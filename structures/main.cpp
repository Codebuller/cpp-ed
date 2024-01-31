#include<iostream>
#include "span/Span.h"
int main(){
    std::array<int, 100> arr;

    for(int i = 0;i<100;++i)
        arr[i] = i; 

    Span<int> span = Span<int>(arr);
    std::cout<<span[99];

}