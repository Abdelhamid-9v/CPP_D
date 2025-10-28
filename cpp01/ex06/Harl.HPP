#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    int get_levelindex(std::string level);

public:
    void filter(std::string level);
};

#endif