#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    vector<Node*> children;

    Node(const T& data = T()) : data(data) {}
};

template <typename T>
void print(Node<T>* tree)
{
    std::cout << tree.data << " ";
    for (Node* child : tree->children)
    {
        print(child);
    }
}

int main() {

    Node<int>* tree = new Node<int>(5);
    tree->children.push_back(6);
    tree->children.push_back(7);

    print(tree);

    return 0;
}