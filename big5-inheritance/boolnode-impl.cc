module Boolnode;

import <utility>; // needed for std::move(other) and std::move(other.etc) in move ctor and move asst.

// ctor initializes new values bool on, and calls Node ctor for the rest
Boolnode::Boolnode(bool on, int data, Node* next) : Node(data, next), on{on} {}

// dtor doesn't do anything special
Boolnode::~Boolnode() {}

// copy ctor copies on = other.on, and then calls Node's copy ctor to do Node{other]}
Boolnode::Boolnode(const Boolnode& other) : Node{other}, on{other.on} {}

// move ctor is as expected but one has to use the std::move(other) function
Boolnode::Boolnode(Boolnode&& other) : Node{std::move(other)}, on{std::move(other.on)} {}

// copy asst 
Boolnode& Boolnode::operator=(const Boolnode& other) {
    if (this == &other) return *this; // check for self-asst
    Node::operator=(other); // call's Node's copy asst with other
    on = other.on; // copy primitive data over
    return *this;
}

// move asst
Boolnode& Boolnode::operator=(Boolnode&& other) {
    if (this == &other) return *this; // check for self-asst
    Node::operator=(std::move(other)); // call Node's move asst, using std::move(other) for the parameters
    on = std::move(other.on); // copy primitive data over using std::move(other.on)
    return *this;
}
