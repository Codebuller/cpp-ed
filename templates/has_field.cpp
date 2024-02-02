// #include "is_same.cpp"
// #include "helpfull_types.cpp"
// #include "add_value_references.cpp"
// #include <iostream>
// #include "declvar.cpp"
// template<typename T>
//     struct has_field{
//         template<typename U>
//         static  true_type test(U::value){};
//         static false_type test(...);
//         static const bool value = is_same<test(T),std::true_type>::value; 
//     }
//     struct test1
//     {
//         int value = 5;
//     };
//     struct A{
//         A() = delete;
//         int foo() {return 1;}
//     };
    
// int main(){
//     std::cout<< typeid(declvar<A>().foo()).name();
// } 