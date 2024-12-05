export module BST;

import <iostream>;
using namespace std;

export class BST {
    int data;
    BST *left;
    BST *right;
    public:
        BST(); // Constructor
        BST(int data, BST* left, BST* right); // Constructor with fields
        ~BST(); // Destructor
        // Recall: Copy must be (const Node& other)
        // Move must be (Node&& other)
        // Ctor must be Node(...);
        // Asst must be Node& operator=(...);
        BST(const BST& other); // Copy Constructor
        BST(BST&& other); // Move Constructor
        BST& operator=(const BST& other); // Copy Assignment
        BST& operator=(BST&& other); // Move Assignment

        // Getters and Setters
        int getData() const { return data; }
        void setData(int newData) { data = newData; }
        BST* getLeft() const { return left; }
        void setLeft(BST* newLeft) { left = newLeft; }
        BST* getRight() const { return right; }
        void setRight(BST* newRight) { right = newRight; }
};

istream& operator>>(istream& in, const BST& bt); // Input Operator. Makes a tree with like the binary search stuff
ostream& operator<<(ostream& out, const BST& bt); // Output Operator. Prints the tree..?? Hopefully.
