#include <iostream>

class Data {
public:
    int value;
    Data() {}
    Data(int _value) : Data() {
        value = _value;
    }
};

class Node {
public:
    Data * data;

    Node * parent;
    Node * left;
    Node * right;

    Node() {
        data = nullptr;
        parent = left = right = nullptr;
    }
    Node(Data * _data) : Node() {
        data = _data;
    }
};

class Tree {
public:
    Node * root;

    Node* search(Node * currentNode, int value) {
        if (currentNode == nullptr || value == currentNode->data->value)
            return currentNode;
        if (value < currentNode->data->value)
            return search(currentNode->left, value);
        if (value > currentNode->data->value)
            return search(currentNode->right, value);
    }

    Node* prev(Node * currentNode) {

        if (currentNode->left != nullptr) {
            return maximum(currentNode->left);
        }
        Node * parentNode = currentNode->parent;

        while (parentNode != nullptr && currentNode == parentNode->left) {
            currentNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }

    Node* next(Node * currentNode) {
        if (currentNode->right != nullptr) {
            return minimum(currentNode->right);
        }
        Node * parentNode = currentNode->parent;

        while (parentNode != nullptr && currentNode == parentNode->right) {
            currentNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }

    Node* minimum(Node * currentNode) {
        return (currentNode->left == nullptr) ? currentNode : minimum(currentNode->left);
    }

    Node* maximum(Node * currentNode) {
        return (currentNode->right == nullptr) ? currentNode : maximum(currentNode->right);
    }

    Node* insert(Node * currentNode, int value) {
        if (currentNode == nullptr)
            return new Node(new Data(value));
        else if (value > currentNode->data->value)
            currentNode->right = insert(currentNode->left, value);
        else if (value < currentNode->data->value)
            currentNode->left = insert(currentNode->right, value);
        return currentNode;
    }

    void insert(int value, Node * currentNode = nullptr) {
        if (currentNode == nullptr)
            currentNode = root;
        while (currentNode != nullptr) {
            if (value < currentNode->data->value) {
                if (currentNode->left == nullptr) {
                    Node * leftChild = new Node(new Data(value));
                    leftChild->parent = currentNode;
                    currentNode->left = leftChild;
                    break;
                } else
                    currentNode = currentNode->left;
            } else if (value > currentNode->data->value) {
                if (currentNode->right == nullptr) {
                    Node * rightChild = new Node(new Data(value));
                    rightChild->parent = currentNode;
                    currentNode->right = rightChild;
                    break;
                } else
                    currentNode = currentNode->right;
            }
        }
    }

    void remove(Node * removableNode) {
        Node * parentNode = removableNode->parent;

        if (removableNode->left == nullptr && removableNode->right == nullptr) {
            if (parentNode->left == removableNode)
                parentNode->left = nullptr;
            else if (parentNode->right == removableNode)
                parentNode->right = nullptr;

            delete removableNode;
        } else if (removableNode->left == nullptr || removableNode->right == nullptr) {
            if (removableNode->left == nullptr) {
                if (parentNode->left == removableNode)
                    parentNode->left = removableNode->right;
                else if (parentNode->right == removableNode)
                    parentNode->right = removableNode->right;

                removableNode->right->parent = parentNode;

                delete removableNode;
            } else if (removableNode->right == nullptr) {
                if (parentNode->left == removableNode)
                    parentNode->left = removableNode->left;
                else if (parentNode->right == removableNode)
                    parentNode->right = removableNode->left;

                removableNode->left->parent = parentNode;

                delete removableNode;
            }
        } else if (removableNode->left != nullptr && removableNode->right != nullptr) {
            Node * successor = next(removableNode);
            removableNode->data->value = successor->data->value;

            if (successor->parent->left == successor) {
                successor->parent->left = successor->right;
                if (successor->right != nullptr)
                    successor->right->parent = successor->parent;
            } else if (successor->parent->right == successor) {
                successor->parent->right = successor->right;
                if (successor->right != nullptr)
                    successor->right->parent = successor->parent;
            }

            delete successor;
        }
    }

    void inorderTrarersal(Node * node) {
        if (node != nullptr) {
            inorderTrarersal(node->left);
            std::cout << node->data->value << " ";
            inorderTrarersal(node->right);
        }
    }

    void preorderTrarersal(Node * node) {
        if (node != nullptr) {
            std::cout << node->data->value << " ";
            preorderTrarersal(node->left);
            preorderTrarersal(node->right);
        }
    }

    void postorderTrarersal(Node * node) {
        if (node != nullptr) {
            preorderTrarersal(node->left);
            preorderTrarersal(node->right);
            std::cout << node->data->value << " ";
        }
    }

};

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);



    return 0;
}