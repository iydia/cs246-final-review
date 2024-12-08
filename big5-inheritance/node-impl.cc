module Node;

using namespace std;

// ctor. custom; user gives args
Node::Node(int data, Node *next) : data{data}, next{next} {}

// dtor. recursively calls itself until Node is destroyed
Node::~Node() {
	delete next;
}

// copy ctor. sets our stuff to other's stuff, and creates new nodes as necessary
Node::Node(const Node &other) : data{other.data}, next{other.next ? new Node(*other.next) : nullptr} {}

// move ctor. 
Node::Node(Node &&other) : data{other.data}, next{other.next} {
	other.next = nullptr;
}

// copy asst.
Node& Node::operator=(const Node& other) {
	// check for self-assignment
	if(this==&other) return *this;
	// create temporary object of other
	Node *temp = other.next ? new Node(*other.next) : nullptr;
	// deallocate memory of the location we are copying onto
	// prevents memory leak
	delete next;
	// copy temp onto next
	next = temp;
	// copy other.data onto data
	data = other.data;
	return *this; 
}

// move asst.
Node& Node::operator=(Node&& other) {
	// sanity check once again for all asst
	if(this==&other) return *this;
	// prevents memleaks
	delete next;
	// copy from other this time, since we're not touching the next node
	next = other.next;
	data = other.data;
	// make sure to do this for move always!
	delete other.next;
	return *this;
}
