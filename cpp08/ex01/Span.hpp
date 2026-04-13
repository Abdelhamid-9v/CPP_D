#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class  Span
{
private:
    std::vector<int> arr;
    unsigned int max_sz;
public:

    Span();
    Span(unsigned int N);
    Span(const Span& s);
    Span& operator=(const Span& s);
    ~ Span();


    void addNumber(int n);

    class full_exception : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: Span is already full!";
        }
    };

    int longestSpan()const;
    int  shortestSpan()const;
    class not_enough_elements_except : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: Not enough elements to calculate span!";
        }
    };

    template <typename T>
    void addNumbers(T begin, T end)
    {
        unsigned int dist = std::distance(begin, end);

        if (arr.size() + dist > max_sz)
            throw full_exception();

        arr.insert(arr.end(), begin, end);
    }
};



#endif