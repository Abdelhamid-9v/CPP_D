#include "PmergeMe.hpp"






int main (int ac , char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1; 
    }

    std::vector<int> vec_base;
    std::deque<int> deq_base;
    
    for (int i = 1; i < ac ; i++)
    {
        std::string tmp = av[i];

        if (!PmergeMe::is_number(tmp))
        {
            std::cerr << "Error" << std::endl;
            return 1; 
        }
        long nb = std::atol(tmp.c_str());
        if (nb > 2147483647 || nb < 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        if (std::find(vec_base.begin(), vec_base.end(), nb) != vec_base.end())
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec_base.push_back(nb);
        deq_base.push_back(nb);
    }
    std::cout << "Before: ";
    for(size_t i = 0; i < vec_base.size();i++)
        std::cout << vec_base[i] << " ";
    std::cout << std::endl;

    clock_t start_vec = clock();
    PmergeMe::sort_vec(vec_base);
    clock_t end_vec = clock();
    
    std::cout << "After: ";
    for(size_t i = 0; i < vec_base.size();i++)
        std::cout << vec_base[i] << " ";
    std::cout << std::endl;


    double time_vec = static_cast<double>(end_vec - start_vec);


    /////////////////////////////////////////////////////////////////////////
    
    
    clock_t start_deq = clock();
    PmergeMe::sort_deque(deq_base);
    clock_t end_deq = clock();

    
    double time_deq = static_cast<double>(end_deq - start_deq);
    
    std::cout << "Time to process a range of " << vec_base.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq_base.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
    return 0;
}