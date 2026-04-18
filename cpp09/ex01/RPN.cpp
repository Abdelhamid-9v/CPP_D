#include "RPN.hpp"

RPN::RPN()
{}
RPN::RPN(const RPN& copy)
{
    (void)copy;
}
RPN& RPN::operator=(const RPN& assign)
{
    (void)assign;
    return *this;
}
RPN::~RPN()
{}

int RPN::calc(char *str)
{
    std::stack<int> holder;
    for (int i = 0; str[i] ; i++)
    {
        if(str[i] == ' ')
            continue;
        else if (std::isdigit(str[i]))
            holder.push(str[i] - '0');
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (holder.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int val2 = holder.top();
            holder.pop();
            int val1 = holder.top();
            holder.pop();
            if(str[i] == '+')
                holder.push(val1 + val2);
            else if (str[i] == '-')
                holder.push(val1 - val2);
            else if (str[i] == '*')
                holder.push(val1 * val2);
            else if (str[i] == '/')
            {
                if (val2 == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return 1;
                }
                holder.push(val1 / val2);
            }
        }else
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    if (holder.size() == 1)
        std::cout << holder.top() << std::endl;
    else
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}