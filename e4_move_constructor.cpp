#include <iostream>

class A {
public:
    int x;

    A(int x) : x(x) {
        std::cout << "Constructor" << std::endl;
    }

    A(A &a) : x(a.x) {
        std::cout << "Copy Constructor" << std::endl;
    }

    A &operator=(A &a) {
        x = a.x;
        std::cout << "Copy Assignment operator" << std::endl;
        return *this;
    }

    A(A &&a) : x(a.x) {
        std::cout << "Move Constructor" << std::endl;
    }

    A &operator=(A &&a) {
        x = a.x;
        std::cout << "Move Assignment operator" << std::endl;
        return *this;
    }
};

A GetA() {
    return A(1);
}

A &&MoveA(A &a) {
    return std::move(a);
}

int main() {
    std::cout << "-------------------------1---------" << std::endl;
    A a(1); // Constructor
    std::cout << "-------------------------2---------" << std::endl;
    A b = a; // Copy Constructor
    std::cout << "-------------------------3---------" << std::endl;
    A c(a); // Copy Constructor
    std::cout << "-------------------------4---------" << std::endl;
    b = a; // Copy Assignment operator
    std::cout << "-------------------------5---------" << std::endl;
    A d = A(1); // Constructor
    std::cout << "-------------------------6---------" << std::endl;
    A e = std::move(a); // Move Constructor
    std::cout << "-------------------------7---------" << std::endl;
    A f = GetA(); // Constructor
    std::cout << "-------------------------8---------" << std::endl;
    A &&g = MoveA(f);
    std::cout << "-------------------------9---------" << std::endl;
    d = A(1); // Constructor and Move Assignment operator
}