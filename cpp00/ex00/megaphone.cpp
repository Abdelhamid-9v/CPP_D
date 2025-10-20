#include <iostream>

int main(int ac, char **av)
{
    int i = 1;

    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    while (i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            av[i][j] = (char)toupper(av[i][j]);
            std::cout << av[i][j];
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}

//DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.