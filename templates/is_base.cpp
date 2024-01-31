#ifndef IS_BASE_CPP
#define IS_BASE_CPP
#include "is_same.cpp"
template<typename B, typename D>
    struct is_base{
        struct No {};
        struct Yes {No no[3];};

        static Yes test(B*);
        static No test(...);

        static const bool value = (sizeof(test(static_cast<D*>(0))) == sizeof(Yes));
    };

#endif