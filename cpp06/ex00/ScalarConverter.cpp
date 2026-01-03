#include "ScalarConverter.hpp"
#include <cerrno>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff");
}

static void printPseudoLiteral(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isPseudoLiteral(literal))
    {
        printPseudoLiteral(literal);
        return;
    }

    char    char_val = 0;
    int     int_val = 0;
    float   float_val = 0.0f;
    double  double_val = 0.0;
    
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char_val = literal[0];
        // std::cout << "====\n";
        int_val = static_cast<int>(char_val);
        float_val = static_cast<float>(char_val);
        double_val = static_cast<double>(char_val);
    }
    else
    {
        char *end;
        errno = 0;
        double parse_val = std::strtod(literal.c_str(), &end);
         std::cout << "====\n";
        if (literal.c_str() == end)
        {
            std::cout <<"......................\n";
            // std::cout <<"--------------------\n["<<literal.c_str()<<"]\n";
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        std::cout <<"--------------------\n["<<*end<<"]\n";
        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        double_val = parse_val;
        float_val = static_cast<float>(double_val);
        int_val = static_cast<int>(double_val);
        char_val = static_cast<char>(double_val);
    }

    std::cout << "char: ";
    if (double_val < 0 || double_val > 127 || std::isnan(double_val))
    {
        std::cout << "impossible";
    } else if (!std::isprint(static_cast<unsigned char>(double_val)))
    {
        std::cout << "Non displayable";
    } else
    {
        std::cout << "'" << static_cast<char>(double_val) << "'";
    }
    std::cout << std::endl;

    std::cout << "int: ";
    if (double_val > 2147483647 || double_val < -2147483648 || std::isnan(double_val))
    {
        std::cout << "impossible";
    } else
    {
        std::cout << int_val;
    }
    std::cout << std::endl;
    std::cout << "float: " <<  std::setprecision(1) << float_val << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << double_val << std::endl;
}