#include <iostream>
#include <cmath>
#define ll __int128
    template<ll N, ll i>
    struct Counter
    {
        static const bool flag = Counter<N,i-1>::flag || N%i==0;
    };
    template<ll N>
    struct Counter<N, 2>
    {
        static const bool flag = N%2==0;
    };
    template<ll N>
    struct Prime
    {
        static const bool flag = Counter<N,static_cast<ll>(sqrt(N))>::flag; 
    };
    
    

int main(){
    std::cout<<static_cast<bool>(Prime<99990001>::flag);

    return 0;
}