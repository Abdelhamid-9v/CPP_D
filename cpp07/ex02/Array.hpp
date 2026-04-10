#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T*              arr;
    unsigned int    sz;

public:
   
    Array() : arr(NULL), sz(0) {}

    Array(unsigned int n) : arr(new T[n]()), sz(n) {} //() force value intialization

    Array(const Array& other) : arr(NULL), sz(0)
    {
        *this = other;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            if (arr) {
                delete[] arr;
            }
            sz = other.sz;
            arr = new T[sz]();
            for (unsigned int i = 0; i < sz; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Array() {
        if (arr) {
            delete[] arr;
        }
    }

    class out_of_bounds_exception : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index is out of bounds!";
        }
    };


    T& operator[](unsigned int index)
    {
        if (index >= sz)
            throw out_of_bounds_exception();
        return arr[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= sz)
            throw out_of_bounds_exception();
        return arr[index];
    }

    unsigned int size() const {
        return sz;
    }
};

#endif