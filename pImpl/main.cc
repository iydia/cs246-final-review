import <memory>; // For unique_ptr and make_unique

class A {
public:
    void g() {} // Example method
};

class B {
public:
    void h() {} // Example method
};

// Helper struct for C's internal data
struct Cimpl {
    A a;
    B b;
};

class C {
    std::unique_ptr<Cimpl> pImpl; // Manages dynamic memory for Cimpl. Automatically deletes when pImpl goes out of scope.

public:
    void f() {
        auto temp = std::make_unique<Cimpl>(*pImpl); // Copy current state (pImpl) into temp
        temp->a.g(); // Modify the copy
        temp->b.h(); 
        std::swap(pImpl, temp); // Replace old state with the modified copy
        // Old pImpl is deleted when temp goes out of scope
    }
};

int main() {
    C c;
    c.f(); // Calls f(), demonstrating safe modification of pImpl
}
