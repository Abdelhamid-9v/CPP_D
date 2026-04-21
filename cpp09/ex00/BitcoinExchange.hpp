#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
private:
    std::map<std::string, double> holder;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    bool is_valide(std::string& s);
    int validate_date(std::string& date);
    int validate_value(std::string str_price, double& value);
    void process_input(char *filename);
};

#endif