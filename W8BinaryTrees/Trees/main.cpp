#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {}
};

enum PrintOrder {
    InOrder,
    PreOrder,
    PostOrder
};

template <typename T>
void print(Node<T>* root, PrintOrder order = PrintOrder::InOrder)
{
    if (root == nullptr)
    {
        return;
    }

    switch (order)
    {
    case InOrder:
        print(root->left, order);
        std::cout << root->data << " ";
        print(root->right, order);
        break;
    case PreOrder:
        std::cout << root->data << " ";
        print(root->left, order);
        print(root->right, order);
        break;
    case PostOrder:
        print(root->left, order);
        print(root->right, order);
        std::cout << root->data << " ";
        break;
    default:
        break;
    }

}

template <typename T>
void clear(Node<T>* root) {
    if (root == nullptr)
    {
        return;
    }

    clear(root->left);
    clear(root->right);

    delete root;
}

// incorrect because it only checks locally
//template <typename T>
//bool isBST(Node<T>* root) {
//    if (root == nullptr)
//    {
//        return true;
//    }
//
//    if (
//        (root->left != nullptr && root->data > root->left->data) &&
//        (root->right != nullptr && root->data < root->right->data))
//    {
//        return isBST(root->left) && isBST(root->right);
//    }
//
//    return false;
//}
// okay, but slow
//template <typename T>
//bool isBST(Node<T>* root) {
//    if (root == nullptr)
//    {
//        return true;
//    }
//
//    if (
//        (root->left != nullptr && root->data < max(root->left)) ||
//        (root->right != nullptr && root->data > min(root->right)))
//    {
//        return false;
//    }
//
//    return isBST(root->left) && isBST(root->right);
//}

template <typename T>
bool isBST(Node<T>* root) {
    return isBST(root, min(root->left), max(root->right));
}

template <typename T>
bool isBST(Node<T>* root, T min, T max) {
    if (root == nullptr)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    return isBST(root->left, min, root->data) && 
           isBST(root->right, root->data, max);
}

template <typename T>
T min(Node<T>* root) {
    if (root == nullptr)
    {
        throw "Empty tree";
    }

    T minValue = root->data;
    if (root->left != nullptr) {
        T minLeftValue = min(root->left);
        if (minValue > minLeftValue) {
            minValue = minLeftValue;
        }
    }

    if (root->right != nullptr) {
        T minRightValue = min(root->right);
        if (minValue > minRightValue) {
            minValue = minRightValue;
        }
    }
    
    return minValue;
}

template <typename T>
T max(Node<T>* root) {
    if (root == nullptr)
    {
        throw "Empty tree";
    }

    T maxValue = root->data;
    if (root->left != nullptr) {
        T maxLeftValue = max(root->left);
        if (maxValue < maxLeftValue) {
            maxValue = maxLeftValue;
        }
    }

    if (root->right != nullptr) {
        T maxRightValue = max(root->right);
        if (maxValue < maxRightValue) {
            maxValue = maxRightValue;
        }
    }

    return maxValue;
}

//template <typename T>
//int sum(Node<T>* root) {
//    int result = root->data;
//    
//    for (Node<T>* child : root->children)
//        result += sum(child);
//
//    return result;
//}
//
//template <typename T>
//bool equal(Node<T>* root1, Node<T>* root2) {
//    if (root1->data != root2->data || 
//        root1->children.size() != root2->children.size())
//    {
//        return false;
//    }
//
//    for (int i = 0; i < root1->children.size(); ++i)
//        if (!equal(root1->children[i], root2->children[i]))
//            return false;
//
//    return true;
//}
//
//template <typename T>
//Node<T>* copy(Node<T>* root) {
//    Node<T>* newRoot = new Node<T>(root->data);
//    for (Node<T>* child : root->children)
//        newRoot->children.push_back(copy(child));
//
//    return newRoot;
//}

int main() {
    Node<int>* root = new Node<int>(6,
        new Node<int>(3,
            new Node<int>(1),
            new Node<int>(4,
                nullptr,
                new Node<int>(67)
            )
        ),
        new Node<int>(9,
            new Node<int>(7),
            nullptr
        )
    );
    print(root, PrintOrder::PostOrder);
    std::cout << std::endl;
    std::cout << min(root) << std::endl;
    std::cout << std::endl;
    std::cout << isBST(root) << std::endl;
    //Node<int>* root3 = copy(root);
    //root->children[1]->children.push_back(new Node<int>(9));
    //std::cout << "equal root1 root3: " << equal(root, root3) << std::endl;
    //print(root);
    //std::cout << std::endl;
    //print(root3);
    //std::cout << std::endl;

    ////print(root);
    //std::cout << std::endl;
    //std::cout << "sum: " << sum(root) << std::endl;
    //
    //Node<int>* root2 = copy(root);
    //print(root2);

    clear(root);

    return 0;
}