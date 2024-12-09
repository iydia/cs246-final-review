import AbstractBook;

import <iostream>;
import <string>;
import <memory>; // compile before string

using namespace std;

int main() {
    Book* b1 = new Text("design patters", "jens", 100, "CS246");
    Text* t1 = dynamic_cast<Text*>(b1);

    return 0;
}