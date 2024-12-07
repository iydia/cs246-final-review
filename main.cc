import <stdexcept>;
import <vector>;
import <string>;
import <iostream>;

using namespace std;

int main() {
    int negi = -1;
    int largei = 100;
    int regi = 2;

    vector<int> v1(10, 1);
    vector<string> v2(5, "hello");

    try {
        cout << v2.at(regi) << " is in bounds" << endl;
        cout << v1.at(negi) << " is in bounds" << endl;
        cout << v1.at(largei) << " is in bounds" << endl;
        cout << "If this sentence prints, no exception was caught. Catch block will not execute" << endl;
    } catch (std::out_of_range &e) {
        cout << "Range error: " << e.what() << endl;
        cout << "If this sentence prints, an exception was found. Catch block has executed" << endl;
    }
}
