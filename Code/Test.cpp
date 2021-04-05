#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>

/*
class MagicFoo {
    public:
        std::vector<int> vec;
        MagicFoo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();it != list.end(); ++it)
            vec.push_back(*it);
        }

        void foo(std::initializer_list<int> list){
            for(std::initializer_list<int>::iterator itr = list.begin(); itr != list.end(); ++itr)
                vec = *itr;
        }
};

int main() {
// after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) 
        std::cout << *it << std::endl;
}


template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y){ //C++11 trailing return type
    return x+y;
}

//C++14
template<typename T, typename U>
auto add2(T x, U y){
    return x+y;
}

int main(){

    // C++ 11
    auto w = add<int, double>(1,2.2);

    if(std::is_same<decltype(w), int>::value)
        std::cout << "w= " << w << "is a int" << std::endl;


    //C++ 14
    auto z = add2<double, int>(3.2, 3);
    if(std::is_same<decltype(w), int>::value)
        std::cout << "z= " << z << " is a double" << std::endl;

    return 0;
}



template<typename T>
auto print_type_info(const T& t) -> decltype(t) {
    if constexpr (std::is_integral<T>::value){
        return t+1;
    } else {
        return t+0.01;
    }
}

int main(){
    std::cout<<print_type_info(1)<<std::endl;
    std::cout<<print_type_info(3.13)<<std::endl;

    return 0;
}

*/


class Base{
    public:
        int val_1;
        int val_2;

        Base(){
            val_1 = 1;
        }

        Base(int val):Base(){
            val_2 = val;
        }

        virtual void foo(int);
};

class subclass:public Base{

    public:
        using Base::Base;       //Inheritance constructor

        virtual void foo(int) override;
};

int main() {
    
    subclass s(3);

    std::cout << s.val_1 << std::endl;
    std::cout << s.val_2 << std::endl;
    
    
    return 0;
}