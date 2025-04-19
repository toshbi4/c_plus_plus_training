#include <iostream>
#include <memory>

using namespace std;

class A {
public:
    A () {
        std::cout << "Init A" << std::endl;
    }

    ~A () {
        std::cout << "Deinit A" << std::endl;
    }

    void call() {
        call_count++;
        std::cout << "Call numder: " << call_count << std::endl;
    }

private:
    static int call_count;
};

int A::call_count = 0;

int main() {

// Unique ptr
    std::cout << ">> 1. Create unique ptr: u_ptr1" << std::endl;
    unique_ptr<A> u_ptr1 = make_unique<A>();
    u_ptr1->call();

    /* This will cause compile-time error. */
    // unique_ptr<A> u_ptr2 = u_ptr1;

    /* This will make u_ptr1 == nullptr and 
        u_ptr2 == u_ptr1 */
    std::cout << ">> 2. Move unique ptr." << std::endl;
    std::cout << "u_ptr1 before move: " << u_ptr1.get() << std::endl;
    unique_ptr<A> u_ptr2 = std::move(u_ptr1);
    std::cout << "u_ptr1 after move: " << u_ptr1.get() << std::endl;
    std::cout << "u_ptr2 after move: " << u_ptr2.get() << std::endl;
    u_ptr2->call();

// Shared ptr

}

