#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream data("data.csv");
    std::string line;
    if (data.is_open())
    {
        std::getline(data, line);
        while (std::getline(data, line)) {
            size_t a = line.find(',');
            std::string date;
            std::string str_price;
            
            if (a != std::string::npos) {
                date = line.substr(0, a);
                str_price = line.substr(a + 1);
                
                if (date.length() != 10)
                    continue;
                    
                double price = std::strtod(str_price.c_str(), NULL);
                holder[date] = price;
            }
        }
    } else {
        std::cout << "Error: could not open file.\n";
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
    if (this != &o) {
        this->holder = o.holder;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::validate_date(std::string& date) {
    if(date.length() != 10)
        return 0;
    if(date[4] != '-' || date[7] != '-')
        return 0;
    for (int i=0; i < 10 ;i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return 0;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return 0;
    } else if (month == 2) {
        if (year % 400 == 0 && day > 29)
            return 0;
        else if (year % 100 == 0 && year % 400 != 0 && day > 28)
            return 0;
        else if (year % 4 == 0 && year % 100 != 0 && day > 29)
            return 0;
        else if (year % 4 != 0 && day > 28)
            return 0;
    }
    return 1;
}

bool BitcoinExchange::is_valide(std::string& s)
{
    size_t i = 0;
    bool dot = false;
    bool nbr_start = false;
    char last;
    while (i < s.length() && s[i] == ' ')
        i++;

    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        i++;

    while (i < s.length())
    {
        if (std::isdigit(s[i]))
            nbr_start = true;
        else if (s[i] == '.')
        {
            if (dot)
                return 0;
            dot = true;
        } 
        else
            return false;
        last  = s[i];
        i++;
    }
    if (last == '.')
        return false;
    // std::cout <<"aaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
    return nbr_start;
}

int BitcoinExchange::validate_value(std::string str_price, double& value)
{
    
    if (!is_valide(str_price))
    {
        std::cout << "Error: not a valide number.\n";
        return 0;
    }
    value = std::strtod(str_price.c_str(), NULL);
    if (value < 0) {
        std::cout << "Error: not a positive number.\n";
        return 0;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number.\n";
        return 0;
    }
    return 1;
}

void BitcoinExchange::process_input(char *filename) {
    std::ifstream input(filename);
    std::string line;
    
    if(input.is_open()) {
        std::getline(input, line);
        size_t b = line.find('|');
        if(b != std::string::npos)
        {
            std::string date = line.substr(0,b - 1);
            std::string value = line.substr(b + 2);
            // std::cout <<"["<< date <<"]" << std::endl;
            // std::cout <<"["<< value << "]" <<std::endl;
            if (date != "date" || value != "value")
            {
                std::cout << "Error: bad input => " << line << std::endl;
                // return;
            }

        }else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            // return;
        }


        while (std::getline(input, line)) {
            size_t a = line.find('|');
            std::string date;
            std::string str_price;

            if (a != std::string::npos) {
                date = line.substr(0, a - 1);
                str_price = line.substr(a + 1);
                // std::cout <<"["<< date <<"]" << std::endl;
                // std::cout <<"["<< str_price << "]" <<std::endl;

                if (validate_date(date)) {
                    double val;
                    if(validate_value(str_price, val)) 
                    {
                        std::map<std::string, double>::iterator it = holder.lower_bound(date);
                        
                        if (it == holder.begin() && it->first != date) {
                            std::cout << "Error: bad input => " << date << std::endl;
                            continue;
                        }
                        if (it->first != date)
                            --it;
                            
                        double result = val * it->second;
                        std::cout << date << " => " << val << " = " << result << std::endl;
                    }
                } else {
                    std::cout << "Error: bad input => " << date << std::endl;
                }
            } else {
                std::cout << "Error: bad input => " << line << std::endl;
            }
        }
    } else {
        std::cout << "Error: could not open file.\n";
    }
}