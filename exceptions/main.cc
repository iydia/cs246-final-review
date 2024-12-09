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

    int i = 10;
    int j = 9;
    int k = -1;

    vector<int> v(10, 8);

    try {
        cout << v.at(j) << " gyatt" << endl;
        cout << v.at(k) << " rizz" << endl;
        cout << v.at(i) << " sigma" << endl;
    } catch (std::out_of_range &e) {
        cerr << "heheheha " << e.what() << endl;
        cout << "gyah" << endl;
    }
}
