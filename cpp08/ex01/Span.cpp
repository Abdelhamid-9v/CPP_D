#include "Span.hpp"

Span::Span(unsigned int N): max_sz(N)
{}
Span::Span() : max_sz(0)
{}

Span::Span(const Span& s): arr(s.arr) , max_sz(s.max_sz)
{
}
Span& Span::operator=(const Span& s){
    if (this != &s)
    {
        arr = s.arr;
        max_sz = s.max_sz;
    }
    return *this;
}

Span::~Span() {}


void Span::addNumber(int n) {
    if(arr.size() >= max_sz)
        throw full_exception();
    arr.push_back(n);
}

int Span::longestSpan()const
{
    if (arr.size() <= 1)
        throw not_enough_elements_except();
    int min_v = *std::min_element(arr.begin(), arr.end());
    int max_v = *std::max_element(arr.begin(), arr.end());
    return max_v - min_v;
}

int Span::shortestSpan()const
{
    if (arr.size() <= 1)
        throw not_enough_elements_except();
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());

    int min_distance = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size(); i++)
    {
        if (sorted[i] - sorted[i-1] < min_distance)
            min_distance = sorted[i] - sorted[i-1];
    }
    return min_distance;
}