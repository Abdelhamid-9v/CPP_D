#include <iostream>
#include <cctype>


int main(int ac, char **av)
{
    int i = 0;

    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    while (++i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            av[i][j] = (char)toupper(av[i][j]);
            std::cout << av[i][j];
            j++;
        }
    }
    std::cout << std::endl;
    return 0;
}

