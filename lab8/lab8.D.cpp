#include <iostream>
#include <string>

class Node {
public:
    std::string name;
    int size;
    Node * left, * right;

    Node() {
        size = 1;
        left = right = nullptr;
    }
    Node(std::string _name) : Node() {
        name = _name;
    }
};

class Tree {
public:
    Node * root;

    void insert(std::string name) {
        root = insertNode(root, name);
    }

    std::string kthSmallest(int k) {
        return kSmallestRec(root, k);
    }

private:
    Node* insertNode(Node* node, std::string name) {
        if (!node) return new Node(name);

        if (name < node->name)
            node->left = insertNode(node->left, name);
        else
            node->right = insertNode(node->right, name);

        node->size = 1 + getSize(node->left) + getSize(node->right);

        return node;
    }

    std::string kSmallestRec(Node* node, int k) {
        if (!node) return "";

        int leftSize = getSize(node->left);
        if (k <= leftSize) {
            return kSmallestRec(node->left, k);
        }
        else if (k == leftSize + 1) {
            return node->name;
        }
        else {
            return kSmallestRec(node->right, k - leftSize - 1);
        }
    }

    int getSize(Node* node) {
        return node ? node->size : 0;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    Tree * library = new Tree();

    for (int i = 0; i < N; ++i) {
        std::string query;
        std::cin >> query;

        try {
            int k = stoi(query);
            std::cout << library->kthSmallest(k) << "\n";
        } catch (const std::invalid_argument& ia) {
            library->insert(query);
        }

    }

    delete library;

    return 0;
}