#ifndef ADD_VALUE_REFERENCES_CPP
#define ADD_VALUE_REFERENCES_CPP
#include"helpfull_types.cpp"
template<typename T>
    struct type_identity{
        using type = T;
    };


template<typename T>
    auto try_add_lvalue_reference(int) -> type_identity<T&>;
template<typename T>
    auto try_add_lvalue_reference(...) -> type_identity<T>;
template<typename T>
    auto try_add_rvalue_reference(int) -> type_identity<T&&>;
template<typename T>
    auto try_add_rvalue_reference(...) -> type_identity<T>;   
    

template<typename T>
    struct is_lvalue_references :false_type{};       
template<typename T>
    struct is_lvalue_references<T&> :true_type{};

template<typename T>
    struct is_rvalue_references : false_type{};       
template<typename T>
    struct is_rvalue_references<T&&> :true_type{};

template<class T>
struct add_lvalue_reference: decltype(try_add_lvalue_reference<T>(0)) {};
 
template<class T>
struct add_rvalue_reference: decltype(try_add_rvalue_reference<T>(0)) {};

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template<typename T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

struct base{
    base() = delete;
};

#endif