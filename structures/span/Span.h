#ifndef SPAN_H
#define SPAN_H

#include <array>
#include <cmath>
#include <stdexcept>

template<unsigned long N>
struct Conditional {
    static const bool isLower = N < 100 ? true : false;
};

template<typename T>
class Span {
public:
    template<std::size_t N, typename std::enable_if_t<(N <= 100), int> = 0>
    Span(std::array<T, N >  &arr){
        cap = 100;
        sz = N;
        int* new_arr = new int[100];
        for(int i = 0;i<N;++i)
            new_arr[i] = arr[i];
        
        _pointers_sub_arr[0] = &new_arr[0];

        _coll_sub_arr[0] = 100;
    
    };

    template <std::size_t N, typename std::enable_if_t<(N > 100), int> = 0 >
    Span(std::array<T,N> & arr){
        sz = N;
        cap = N;
        _coll_sub_arr[0] = N;
        _pointers_sub_arr[0] = &arr[0];
    };

    Span(auto start, auto end);
    void push_back(const T& element);
    T& operator[](int num);
    ~Span();

private:
    unsigned int sz;
    unsigned int cap = 0;
    int* _coll_sub_arr = new int[20];
    int** _pointers_sub_arr = new int*[20];
};

#include "Span.cpp"

#endif // SPAN_H