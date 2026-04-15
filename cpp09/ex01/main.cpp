#include <cctype>
#include <iostream>
#include <stack>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        return 1;
    }
    std::stack<int> holder;
    for (int i = 0; av[1][i] ; i++)
    {
        if(av[1][i] == ' ')
            continue;
        else if (std::isdigit(av[1][i]))
            holder.push(av[1][i] - '0');
        else if(av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' || av[1][i] == '/')
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
            if(av[1][i] == '+')
                holder.push(val1 + val2);
            else if (av[1][i] == '-')
                holder.push(val1 - val2);
            else if (av[1][i] == '*')
                holder.push(val1 * val2);
            else if (av[1][i] == '/')
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