#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    void add(Node<T>*& node, T value) {
        if (!node) {
            node = new Node<T>(value);
        } else if (value < node->data) {
            add(node->left, value);
        } else {
            add(node->right, value);
        }
    }

    void clear(Node<T>* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear(root);
    }

    void add(T value) {
        add(root, value);
    }

    Node<T>* getRoot() const {
        return root;
    }
};

template <typename T>
class TreeIterator {
private:
    stack<Node<T>*> nodeStack;

    void pushLeft(Node<T>* node) {
        while (node) {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    TreeIterator(Node<T>* root) {
        pushLeft(root);
    }

    bool hasNext() const {
        return !nodeStack.empty();
    }

    T next() {
        Node<T>* current = nodeStack.top();
        nodeStack.pop();

        if (current->right) {
            pushLeft(current->right);
        }

        return current->data;
    }
};

int iter_unit() {
    BinaryTree<int> tree;

    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    TreeIterator<int> it(tree.getRoot());

    
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}
