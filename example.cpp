#include<iostream>
#include "./templates/is_base.cpp"
#include "./templates/is_same.cpp"

struct B {};
struct D:public B{};


int main(){
std::cout<<(is_base<B,B>::value && !(is_same<B,B>::value));

    return 0;  
}