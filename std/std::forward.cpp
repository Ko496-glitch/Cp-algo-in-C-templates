#include <type_traits>
#include "std::forward.hpp"

struct util {

    template<typename T>
    using remove_reference_t = std::remove_reference_t<T>;

    template<typename T>
    static constexpr T&& my_forward(remove_reference_t<T>& x) noexcept {
        return static_cast<T&&>(x);
    }

    template<typename T>
    static constexpr T&& my_forward(remove_reference_t<T>&& x) noexcept {
        static_assert(!std::is_lvalue_reference_v<T>);
        return static_cast<T&&>(x);
    }

    template<typename T>
    static constexpr remove_reference_t<T>&& my_move(T&& x) noexcept {
        return static_cast<remove_reference_t<T>&&>(x);
    }
};

void g(int&)  { std::cout << "lvalue\n"; }
void g(int&&) { std::cout << "rvalue\n"; }

template<typename T>
void f(T&& x) {
    g(util::my_forward<T>(x));
}

int main() {
    int a = 10;

    std::cout << "forward lvalue -> ";
    f(a);       

    std::cout << "forward rvalue -> ";
    f(10);      

    std::cout << "move lvalue -> ";
    g(util::my_move(a));  

    std::cout << "move rvalue -> ";
    g(util::my_move(20)); 

    return 0;
}

