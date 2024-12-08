import <memory>; // for unique_ptr and make_unique

class A {
    public:
        void g() {}
};

class B {
    public:
        void h() {}
};

// Helper structure that holds some data
struct Cimpl { 
    A a; // Object of type A, assumed to have some functionality
    B b; // Object of type B, assumed to have some functionality
};

// Class C encapsulates data and uses a smart pointer to manage it
class C {
    // `pImpl` is a unique_ptr to a `Cimpl` object.
    // - It manages a dynamically allocated object of type `Cimpl`.
    // - Ensures the `Cimpl` object is automatically cleaned up (deleted)
    //   when `pImpl` is no longer needed.
    std::unique_ptr<Cimpl> pImpl{std::make_unique<Cimpl>()}; 

public:
    // Function `f` modifies the current state of `Cimpl` safely
    void f() {
        // Step 1: Create a **copy** of the current state (`pImpl`).
        // - `*pImpl` dereferences the unique_ptr to get the `Cimpl` object it owns.
        // - `std::make_unique` creates a new unique_ptr containing a copy of the `Cimpl` object.
        auto temp = std::make_unique<Cimpl>(*pImpl); 

        // Step 2: Operate on the copy (`temp`).
        // - These operations modify the `a` and `b` members of the `Cimpl` copy.
        temp->a.g(); // Call the `g()` function on the `a` member.
        temp->b.h(); // Call the `h()` function on the `b` member.

        // Step 3: Replace the original `pImpl` with the modified copy.
        // - `std::swap` exchanges the contents of `pImpl` and `temp`:
        //   - `pImpl` now owns the updated `Cimpl`.
        //   - `temp` owns the old `Cimpl`.
        std::swap(pImpl, temp);

        // Step 4: Clean up the old state.
        // - When `temp` goes out of scope, the unique_ptr automatically deletes
        //   the old `Cimpl` it manages. This avoids memory leaks.
    }
};
