#include "Span.h"
    template<typename T>
    Span<T>::Span(auto start, auto end){
        _pointers_sub_arr[0]= new T[100];
        _coll_sub_arr[0]=100;
        sz = 0;
        cap = 100;
        
        for(int i = 0;start!=end ;++i){
            push_back(*start);
            ++start;
        }
        
    }
    template<typename T>
    void Span<T>::push_back(const T& element){
        unsigned int current_num = std::floor(std::log2(sz/_coll_sub_arr[0])+1);
        
    
        if(sz<cap){
            if(current_num==0)
            _pointers_sub_arr[0][sz]=element;
            else
            _pointers_sub_arr[current_num][sz-_coll_sub_arr[current_num-1]]=element;
            
        }
        else{
         
            cap*=2;
            _pointers_sub_arr[current_num] = new T[_coll_sub_arr[current_num-1]];
            _coll_sub_arr[current_num] = cap;
            _pointers_sub_arr[current_num][0] = element;
        }
        ++sz;
    }

    template<typename T>
    Span<T>::~Span(){
        delete [] _coll_sub_arr;
        for(int i = 0;i < 20; ++i)
            delete [] _pointers_sub_arr[i];
        delete [] _pointers_sub_arr;
    }
    template<typename T>
    T& Span<T>::operator[](int num){
        if(num>sz || num<0)
            throw new std::string("Out of bounds");
        for(int i = 0;i<20;++i){
            if(num>=_coll_sub_arr[i])
                continue;
            return i==0 ? _pointers_sub_arr[0][num] : _pointers_sub_arr[i][num - _coll_sub_arr[i-1]];
        }
    }
    
