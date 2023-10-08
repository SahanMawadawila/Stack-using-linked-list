// Node class define
class Node {
public:
	int data;
	Node* left; // pointer to next node
	Node* right; // pointer to previous node
public:
	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};