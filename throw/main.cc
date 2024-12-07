import <iostream>;
import <stdexcept>;

using namespace std;

void fib(int n) {
    if (n == 0 || n == 1) {
        throw n;
    }
    // Note: fib has no return value, so the only way to grab the value is to try catch them recursively
    try {
        fib(n - 1);
    } catch (int a) {
        try {
            fib(n - 2);
        } catch (int b) {
            throw a + b;
        }
    }
}

int main() {
    int a = 2;
    int b = 5;

    try {
        fib(a);
    } catch (int e) {
        cout << e << endl;
    }

    try {
        fib(b);
    } catch (int e) {
        cout << e << endl;
    }

    try {
        fib(6);
    } catch (int e) {
        cout << e << endl;
    }

    try {
        fib(7);
    } catch (int e) {
        cout << e << endl;
    }
}

// import <iostream>; import <stdexcept>; using namespace std; void fib(int n) { if (n == 0 || n == 1) { throw n; } try { fib(n - 1); } catch (int a) { try { fib(n - 2); } catch (int b) { throw a + b; } } } int main() { int a = 2; int b = 5; try { fib(a); } catch (int e) { cout << e << endl; } try { fib(b); } catch (int e) { cout << e << endl; } try { fib(6); } catch (int e) { cout << e << endl; } try { fib(7); } catch (int e) { cout << e << endl; } }