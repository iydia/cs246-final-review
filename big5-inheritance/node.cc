export module Node;

export class Node {
	private:
		int data;
		Node *next;
	public:
		Node(int data, Node *next); // ctor
		~Node(); // dtor
		Node(const Node& other); // copy ctor
		Node(Node&& other); // move ctor
		Node& operator=(const Node& other); // copy asst
		Node& operator=(Node&& other); // move asst
};
