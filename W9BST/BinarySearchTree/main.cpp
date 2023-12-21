#include <iostream>

class BST {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;

		Node(int data, Node* left = nullptr, Node* right = nullptr)
			: data(data), left(left), right(right)
		{}
	};

	Node* root;

	void print(Node* root) {

		if (root == nullptr)
		{
			return;
		}

		print(root->left);
		std::cout << root->data << " ";
		print(root->right);
	}

	Node* search(Node* root, int value) {
		if (root == nullptr || root->data == value) {
			return root;
		}

		if (root->data > value) {
			search(root->left, value);
		}
		else {
			search(root->right, value);
		}
	}

	void add(Node* root, int newValue) {
		if (root->data > newValue && root->left != nullptr) {
			add(root->left, newValue);
		}
		else if (root->data > newValue && root->left == nullptr) {
			root->left = new Node(newValue);
		}
		else if (root->data <= newValue && root->right != nullptr) {
			add(root->right, newValue);
		}
		else {
			root->right = new Node(newValue);
		} 
	}

	void clear(Node* root) {
		if (root == nullptr)
		{
			return;
		}

		clear(root->left);
		clear(root->right);

		delete root;
	}

	void removeChild(Node* parent, bool left) {
		Node* child = left ? parent->left : parent->right;
		// first case - no children
		if (child->left == nullptr && child->right == nullptr) {
			left ? parent->left = nullptr : parent->right = nullptr;
			delete child;

			return;
		}

		// second case - one child
		// has left child only
		if (child->left != nullptr && child->right == nullptr) {
			left ? parent->left = child->left : parent->right = child->left;
			delete child;

			return;
		}
		// has right child only
		else if (child->left == nullptr && child->right != nullptr) {
			left ? parent->left = child->right : parent->right = child->right;
			delete child;

			return;
		}

		// third case - two children
		// right child has no left subtree
		if (child->right->left == nullptr) {
			child->data = child->right->data;
			Node* rightNode = child->right;
			child->right = child->right->right;
			delete rightNode;
			return;
		}
		// right child has left subtree
		else {
			Node* minimumRightNodeParent = child->right;
			while (minimumRightNodeParent->left->left != nullptr) {
				minimumRightNodeParent = minimumRightNodeParent->left;
			}
			child->data = minimumRightNodeParent->left->data;
			delete minimumRightNodeParent->left;
			minimumRightNodeParent->left = nullptr;
		}
	}

	bool remove(Node* root, int value) {
		if (root == nullptr) {
			return false;
		}

		if (root->left->data == value || root->right->data == value) {
			removeChild(root, root->left->data == value);
			return true;
		}

		if (root->data > value) {
			return remove(root->left, value);
		}
		else {
			return remove(root->right, value);
		}
	}

public:
	BST() : root(nullptr) {}
	BST(BST& other) = delete;
	BST& operator=(BST& other) = delete;
	~BST() { clear(root); }

	void print() {
		print(root);
	}

	void add(int newValue) {
		if (root == nullptr) {
			root = new Node(newValue);
			return;
		}

		add(root, newValue);
	}

	bool contains(int value) {
		return search(root, value) != nullptr;
	}

	bool remove(int value) {
		if (root->data == value) {
			Node* tempRoot = new Node(0, nullptr, root);
			root = tempRoot;
			removeChild(tempRoot, false);
			root = tempRoot->right;
			delete tempRoot;
		}

		return remove(root, value);
	}
};

int main() {
	BST bst;
	bst.add(7);
	bst.add(4);
	bst.add(3);
	bst.add(2);
	bst.add(10);
	bst.add(9); 
	bst.add(7);
	bst.add(4);
	bst.add(12);
	bst.add(11);
	bst.add(13);

	bst.print();
	std::cout << std::endl;
	
	std::cout << bst.contains(5) << std::endl;
	std::cout << bst.contains(7) << std::endl;
	std::cout << bst.contains(10) << std::endl;

	bst.remove(4);
	bst.remove(10);
	bst.print();

	return 0;
}