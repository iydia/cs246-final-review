import <iostream>;
import <map>;
import <string>;

using namespace std;

template <typename T> void insert(const std::map<string, T> newPairs, std::map<string, T>& currentPairs) {
    for (auto& newPair : newPairs) {
        currentPairs[newPair.first] = newPair.second;
    }
}

template <typename Z> void curve(std::map<Z, int>& preCurved) {
    for(auto& pair : preCurved) {
        pair.second += 2;
    }
}

int main() {
    std::map<string, int> curGrades;

    curGrades["lydia"] = 80; // current grades
    curGrades["anthony"] = 80; // current grades

    std::map<string, int> newGrades;
    newGrades["lydia"] = 85; // at least 87% on the final exam
    newGrades["anthony"] = 95; // gr12 cs

    insert(newGrades, curGrades);
    curve(curGrades);

    for (auto& pair : curGrades) {
        // std::map only has 2 elements in the pair, first and second
        std::cout << "The person " << pair.first << " has %" << pair.second << " in the CS course." << std::endl;
    }

    cout << curGrades.contains("lydia") << endl;
    cout << curGrades.contains("anthony") << endl;
    cout << curGrades.count("lydia") << endl;
    cout << curGrades.count("anthony") << endl;

    curGrades.erase("lydia");
    curGrades.erase("anthony");

    cout << curGrades.contains("lydia") << endl;
    cout << curGrades.contains("anthony") << endl;
    cout << curGrades.count("lydia") << endl;
    cout << curGrades.count("anthony") << endl;

    for (auto& pair : curGrades) {
        // std::map only has 2 elements in the pair, first and second
        std::cout << "The person " << pair.first << " has %" << pair.second << " in the CS course." << std::endl;
    }
}
