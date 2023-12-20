#include <iostream>
#include <queue>

class Data {
public:
    int value;
    Data() {}
    Data(int _value) : Data() {
        value = _value;
    }
};

template <typename T>
class BasicNode {
public:
    Data * data;

    T * parent;
    T * left;
    T * right;

    BasicNode() {
        data = nullptr;
        parent = left = right = nullptr;
    }
    BasicNode(Data * _data) : BasicNode() {
        data = _data;
    }
};

class Node : public BasicNode<Node> {
public:
    Node() : BasicNode<Node>() {
    }
    Node(Data * _data) : BasicNode<Node>(_data) {
    }
};

class Tree {
public:
    Node * root;

    void insert(int value, Node * currentNode = nullptr) {
        if (root == nullptr) {
            root = new Node(new Data(value));
            return;
        }

        if (currentNode == nullptr)
            currentNode = root;
        while (currentNode != nullptr) {
            if (value > currentNode->data->value) {
                if (currentNode->right == nullptr) {
                    Node *rightChild = new Node(new Data(value));
                    rightChild->parent = currentNode;
                    currentNode->right = rightChild;
                    break;
                } else
                    currentNode = currentNode->right;
            } else if (value < currentNode->data->value) {
                if (currentNode->left == nullptr) {
                    Node *leftChild = new Node(new Data(value));
                    leftChild->parent = currentNode;
                    currentNode->left = leftChild;
                    break;
                } else
                    currentNode = currentNode->left;
            } else
                break;
        }
    }


    void findRightDec(Node * root, std::vector<int>& rightNodes) {
        if (root == nullptr)
            return;

        std::queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 1; i <= n; i++) {
                Node* temp = q.front();
                q.pop();
                if (i == n)
                    rightNodes.push_back(temp->data->value);

                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Tree * tree = new Tree();

    int n;
    std::vector<int> rightNodes;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;

        tree->insert(value, tree->root);
    }
    tree->findRightDec(tree->root, rightNodes);

    for (int i = 0; i < rightNodes.size(); i++) {
        std::cout << rightNodes[i] << " ";

    }


    delete tree;

    return 0;
}

