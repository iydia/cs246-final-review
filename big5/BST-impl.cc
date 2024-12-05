module BST;

using namespace std;

// Ctor
BST::BST() : data{0}, left{nullptr}, right{nullptr} {}

// Ctor with specified arguments
BST::BST(int data, BST* left, BST* right) : data{data}, left{left}, right{right} {}

// Dtor
BST::~BST() {
    delete left;
    delete right;
}

// Copy Ctor
// Copies a BST into a newly created BST
BST::BST(const BST& other) : data{other.data}, left{other.left ? new BST(*other.left) : nullptr}, right{other.right ? new BST(*other.right) : nullptr} {}
// Copies data over, a primitive int type. 
// Checks if the left branch is not null. if not, then set the left branch to a BST of the other.left (assuming copy ctor)
// Same for right branch

// Move Ctor
// Moves the rvalue stuff of a BST into a newly created BST
BST::BST(BST&& other) : data{other.data}, left{other.left}, right{other.right} { // Set my fields to other.fields using the MIL
    // set the other.fields to Nullptr or empty, to remove access of Move from my things
    // to prevent other's things from touching my things...
    other.left = nullptr;
    other.right = nullptr;
}

// Copy Assignment Operator
// Copies a BST into the space of an existing BST
BST& BST::operator=(const BST& other) {
    if (this == &other) return *this; // Check for self-assignment
    // Create a temporary variable to copy other's next into this.
    // uses copy ctor to create a new variable
    BST* tempL = other.left ? new BST(*other.left) : nullptr;
    // uses copy ctor to create a new variable
    BST* tempR = other.right ? new BST(*other.right) : nullptr;
    // Delete current stuff to prevent memleaks
    delete left;
    delete right;
    // Copy next stuff into left and right
    left = tempL;
    right = tempR;
    // Copy trivial data fields over. no need to use temp
    data = other.data; 
    // return
    return *this;
} // tempL and tempR go out of scope I hope

// Move Assignment Operator
BST& BST::operator=(BST&& other) {
    if (this == &other) return *this; // Check for self-Assignment
    // No need to create temp, just immediately swap the rvalue into this
    // Delete current stuff to prevent memleaks
    delete left;
    delete right;
    // assign other's stuff to us
    left = other.left;
    right = other.right;
    data = other.data;
    // prevents other's stuff from deleting our stuff when their dtor is run
    other.left = nullptr;
    other.right = nullptr;
    // return this
    return *this;
}

void addToBST(BST& bt, int newData) {
    if (newData >= bt.getData()) {
        if (!bt.getRight()) {
            bt.setRight(new BST(newData, nullptr, nullptr));  // Create a new node
        } else {
            addToBST(*bt.getRight(), newData);  // Recur on the right subtree
        }
    } else {
        if (!bt.getLeft()) {
            bt.setLeft(new BST(newData, nullptr, nullptr));  // Create a new node
        } else {
            addToBST(*bt.getLeft(), newData);  // Recur on the left subtree
        }
    }
}

istream& operator>>(istream& in, const BST& bt) {
    int readInt;
    while (in >> readInt) {
        addToBST(bt, readInt);
    }
    return in;
}

void printInorder(ostream& out, const BST* node) {
    if (!node) return;              // Base case: do nothing for null nodes
    printInorder(out, node->left);  // Print left subtree
    out << node->getData() << " ";       // Print current node's data
    printInorder(out, node->right); // Print right subtree
}

ostream& operator<<(ostream& out, const BST& bt) {
    printInorder(out, &bt);
    return out;
}
