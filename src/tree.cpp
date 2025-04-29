#include <iostream>
#include <string>
#include <algorithm>
#include "tasks.h"
using namespace std;


// Задача 3.6. Створити параметризованний клас бінарного дерева. З методами
// - додати елемент у дерево, проходження по дереву в спадному й у
// висхідному порядку. Здійснити пошук по дереву.

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    void add(TreeNode<T>*& node, T value) {
        if (!node) {
            node = new TreeNode<T>(value);
        } else if (value < node->data) {
            add(node->left, value);
        } else {
            add(node->right, value);
        }
    }

    void inOrder(TreeNode<T>* node) const {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void descendingOrder(TreeNode<T>* node) const {
        if (node) {
            descendingOrder(node->right);
            cout << node->data << " ";
            descendingOrder(node->left);
        }
    }

    bool search(TreeNode<T>* node, T value) const {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        else return search(node->right, value);
    }

    void clear(TreeNode<T>* node) {
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

    void printInOrder() const {
        inOrder(root);
        cout << endl;
    }

    void printDescendingOrder() const {
        descendingOrder(root);
        cout << endl;
    }

    bool search(T value) const {
        return search(root, value);
    }
};

void tree_unit() {
  BinaryTree<int> tree;

    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    cout << "Обхід у висхідному порядку: ";
    tree.printInOrder();

    cout << "Обхід у спадному порядку: ";
    tree.printDescendingOrder();

    // Пошук
    int key = 60;
    cout << "Пошук " << key << ": " << (tree.search(key) ? "Знайдено" : "Не знайдено") << endl;

    key = 25;
    cout << "Пошук " << key << ": " << (tree.search(key) ? "Знайдено" : "Не знайдено") << endl;

}
