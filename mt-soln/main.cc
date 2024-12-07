import <string>;
import <iostream>;

using namespace std;

struct BAstring {
    string str;
};

BAstring operator+(const BAstring& left, const BAstring& right) {
    BAstring l{left.str};
    BAstring r{right.str};
    int indexL = 0;
    for (size_t i = 0; i < l.str.length(); ++i) {
        for (size_t j = 0; j < r.str.length(); ++j) {
            if (l.str.substr(i, l.str.length()) == r.str.substr(0, j)) {
                indexL = i;
            }
        }
    }
    return {l.str.substr(0, indexL) + r.str};
}

BAstring add(const BAstring& left, const BAstring& right) {
    int llength = left.str.length();
    int rlength = right.str.length();
    int minlen = llength; // determine minlen for for loop valid
    if (rlength < llength) minlen = rlength;
    int numOverlap = 0;
    for (int i = 0; i < minlen; ++i) {
        for (int j = llength; j > 0; --j) {
            if (right.str.substr(0, i+1) == left.str.substr(j-1, llength)) {
                numOverlap = i+1;
            }
        }
    }
    string result = left.str + right.str.substr(numOverlap, rlength);
    BAstring r{result};
    return r;
}

int main() {
    // my midterm soln (fixed (they forgave me for syntax errors lol))
    BAstring l1{"Star Lord"};
    BAstring r1{"Lord of the Rings"};
    cout << (l1 + r1).str << endl;
    BAstring l2{"ABCBCD"}, r2{"BCDEF"};
    cout << (l2 + r2).str << endl;
    BAstring l3{"Lord Help"}, r3{"Lord Help"};
    cout << (l3 + r3).str << endl;

    // my new soln (redid the midterm)
    cout << add(l1, r1).str << endl;
    cout << add(l2, r2).str << endl;
    cout << add(l3, r3).str << endl;
}