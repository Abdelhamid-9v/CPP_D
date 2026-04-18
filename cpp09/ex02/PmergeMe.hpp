#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class PmergeMe {

    public:

    PmergeMe();
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& assign);
    ~PmergeMe();

    
    static int is_number(std::string& str);
    static int get_jacobsthal(int a);
    static void sort_vec(std::vector<int>& v);
    static void sort_deque(std::deque<int>& dq);
};

#endif