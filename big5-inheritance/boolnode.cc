export module Boolnode;

import Node;

export class Boolnode : public Node {
    bool on;
    public:
        Boolnode(bool on, int data, Node* next);
        ~Boolnode();
        Boolnode(const Boolnode& other);
        Boolnode(Boolnode&& other);
        Boolnode& operator=(const Boolnode& other);
        Boolnode& operator=(Boolnode&& other);
};
