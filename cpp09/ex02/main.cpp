#include <iostream>
#include<vector>
#include <deque>
#include <string>
#include <cctype>
#include <algorithm>



int is_number(const std::string str)
{
    if (str.empty())
        return 0;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}


int get_jacobsthal(int a)
{

    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    int j_prev2 = 0;
    int j_prev1 = 1;
    int jac = 0;
    int i = 2;
    while (i <= a)
    {
        jac = j_prev1 + (2 * j_prev2);
        j_prev2 = j_prev1;
        j_prev1 = jac;
        i++;
    }
    return jac;
}

void sort_vec(std::vector<int>& v)
{
    if(v.size() <= 1)
        return;
    std::vector<std::pair<int, int>> pair;
    bool  p = true;
    if(v.size()%2 != 0)
        p = false;
    for (int i = 0; i < v.size() - 1; i = i + 2)
    {
        if (v[i] > v[i + 1])
            pair.push_back(std::make_pair(v[i], v[i+1]));
        else
            pair.push_back(std::make_pair(v[i+1], v[i]));
    }
    // for (size_t i = 0; i < pair.size(); i++) {
    // std::cout << "Pair: Winner = " << pair[i].first 
    //           << ", Loser = " << pair[i].second << std::endl;
    // }


    std::vector<int> main_v;
    for (size_t i = 0; i < pair.size(); i++)
    {
        main_v.push_back(pair[i].first);
    }
    sort_vec(main_v);

    std::vector<int> pend_v;

    for (size_t i = 0; i < main_v.size(); i++)
    {
        for (size_t j = 0; j < pair.size(); j++)
        {
            if (main_v[i] == pair[j].first)
            {
                pend_v.push_back(pair[j].second);
                break;
            }
        }
    }
    if (!p)
        pend_v.push_back(v[v.size() - 1]);
    
    main_v.insert(main_v.begin(), pend_v[0]);

    int jacob_indx = 3;
    int last_inserted_indx = 1;
    
    int i = main_v.size() - 1;
    while (++i < v.size())
    {
        int curr_jac = get_jacobsthal(jacob_indx);
        if (curr_jac > pend_v.size())
            curr_jac = pend_v.size();
       for (int i = curr_jac - 1; i >= last_inserted_indx ; i--)
        {
            int current_loser = pend_v[i];
            std::vector<int>::iterator win_it;
            if (!p && i == (int)pend_v.size() - 1)
                win_it = main_v.end();
            else
            {
                int winner_value = -1;
                for (int j = 0; j < pair.size(); j++)
                {
                    if (pair[j].second == current_loser)
                    {
                        winner_value = pair[j].first;
                        break;
                    }
                }
                win_it = std::lower_bound(main_v.begin(), main_v.end(), winner_value);
            }
            std::vector<int>::iterator it = std::lower_bound(main_v.begin(), win_it, current_loser);
            main_v.insert(it, current_loser);
        }
        last_inserted_indx = curr_jac;
        jacob_indx++;
    }
    v = main_v;
}


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

        if (!is_number(tmp))
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
        vec_base.push_back(nb);
        deq_base.push_back(nb);
    }
    sort_vec(vec_base);

    for(int i = 0; i < vec_base.size();i++)
    {
        std::cout << vec_base[i] << " ";
    }
    return 0;
}