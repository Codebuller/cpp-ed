#ifndef IS_SAME_CPP
#define IS_SAME_CPP
template<typename T, typename U>
struct is_same { 
    static const bool value = false;
};
template<typename T>
struct is_same<T,T>{
    static const bool value = true; 
};
#endif
//funny joke: ordering of structs is important: like this it is work
//another order - CE)
