#include <iostream>
#include <vector>

using namespace std;

// Node struct that allows for n number of children
struct Node {
	int value;
	int childCount;
	vector<Node*> children;
	Node(int value, int childCount):value(value), childCount(childCount){};
};

// Recursive function to get children of a node.
void getChildren(Node *parent) {
	// Get input for each child
	for(int i = 0; i < parent->childCount; i++) {
		// Read in values and create a new node with those values
		int value;
		int count;
		cin >> value;
		cin >> count;
		Node *child = new Node(value, count);
		
		// Recursively get children for current node
		getChildren(child);
		
		// Add node and all its children to vector of parent
		parent->children.push_back(child);
	}
}

// Recursive function to print post-order traversal of a tree
void printPostOrder(Node *parent) {
	// Recursively print out values of each child (and children's children, etc..)
	for(int i = 0; i < parent->childCount; i++) {
		printPostOrder(parent->children[i]);
	}
	// Print out current node's value
	cout << parent->value << " " << parent->childCount << endl;
}

int main(int argc, char *argv[]) {
	// Read in node value & child count from input
	int value;
	int count;
	cin >> value;
	cin >> count;
	
	// Create a new "head" node with input data
	Node *head = new Node(value, count);
	
	// Call recursive function to read in data for child nodes
	getChildren(head);
	
	// Call recursive function to print a post-order traversal of the tree
	printPostOrder(head);
}
