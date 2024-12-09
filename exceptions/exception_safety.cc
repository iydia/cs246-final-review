#include <vector>
#include <memory>
#include <string>

using namespace std;

void f(int& treasure) {
    treasure *= 2;
    g();
}


void f(int& counter) {
    ++counter;
}


void f(std::vector<int>& data) {
    std::vector<int> tempData = data;
    g(tempData);  // provide basic guarantee
    data.swap(tempData);
}


class A{...}, class B{...};
class C {
    A a;
    B b;
public:
    void f() {
	a.g();  // provide strong guarantee
	b.h();  // provide strong guarantee
    }
};


std::string f(std::vector<std::string>& v) {
    std::string* s = new std::string{""};
    try {
        g(s);  // provide basic guarantee
		v.push_back(s);
		return s;
    } catch (...) {
		delete s;
        throw;
    }
}
        

