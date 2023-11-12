//#include <iostream>
//
//class Data {
//public:
//    int value;
//    Data() {}
//    Data(int _value) : Data() {
//        value = _value;
//    }
//};
//
//template <typename T>
//class BasicNode {
//public:
//    Data * data;
//
//    T * parent;
//    T * left;
//    T * right;
//
//    BasicNode() {
//        data = nullptr;
//        parent = left = right = nullptr;
//    }
//    BasicNode(Data * _data) : BasicNode() {
//        data = _data;
//    }
//};
//
//class Node : public BasicNode<Node> {
//public:
//    Node() : BasicNode<Node>() {
//    }
//    Node(Data * _data) : BasicNode<Node>(_data) {
//    }
//};
//
//
//class Tree {
//public:
//    Node * root;
//
//    template <typename T> T* search(T * currentNode, int value) {
//        if (currentNode == nullptr || value == currentNode->data->value)
//            return currentNode;
//        if (value < currentNode->data->value)
//            return search(currentNode->left, value);
//        if (value > currentNode->data->value)
//            return search(currentNode->right, value);
//    }
//
//    template <typename T> T* prev(T * currentNode) {
//        if (currentNode == nullptr) return nullptr;
//
//        if (currentNode->left != nullptr) {
//            return maximum(currentNode->left);
//        }
//        T * parentNode = currentNode->parent;
//
//        while (parentNode != nullptr && currentNode == parentNode->left) {
//            currentNode = parentNode;
//            parentNode = parentNode->parent;
//        }
//        return parentNode;
//    }
//
//    template<typename T> T* findNext(int value, T * currentNode) {
//        if (currentNode == nullptr) {
//            return nullptr;
//        }
//
//        if (currentNode->data->value > value) {
//            T * minNode = findNext(value, currentNode->left);
//            if (minNode != nullptr)
//                return minNode;
//            return currentNode;
//        }
//        if (currentNode->right != nullptr)
//            return findNext(value, currentNode->right);
//        else
//            return nullptr;
//
//    }
//
//    template<typename T> T* findPrev(int value, T* currentNode) {
//        if (currentNode == nullptr)
//            return nullptr;
//
//        if (currentNode->data->value < value) {
//            T * maxNode = findPrev(value,currentNode->right);
//            if (maxNode != nullptr)
//                return maxNode;
//            return currentNode;
//        }
//        if (currentNode->left != nullptr)
//            return findPrev(value, currentNode->left);
//        else
//            return nullptr;
//    }
//
//    template <typename T> T* next(T * currentNode) {
//        if (currentNode == nullptr) return nullptr;
//
//        if (currentNode->right != nullptr) {
//            return minimum(currentNode->right);
//        }
//        T * parentNode = currentNode->parent;
//
//        while (parentNode != nullptr && currentNode == parentNode->right) {
//            currentNode = parentNode;
//            parentNode = parentNode->parent;
//        }
//        return parentNode;
//    }
//
//    template <typename T> T* minimum(T * currentNode) {
//        return (currentNode->left == nullptr) ? currentNode : minimum(currentNode->left);
//    }
//
//    template <typename T> T* maximum(T * currentNode) {
//        return (currentNode->right == nullptr) ? currentNode : maximum(currentNode->right);
//    }
//
//    void insert(int value, Node * currentNode = nullptr) {
//        if (root == nullptr) {
//            root = new Node(new Data(value));
//            return;
//        }
//
//        if (currentNode == nullptr)
//            currentNode = root;
//        while (currentNode != nullptr) {
//            if (value < currentNode->data->value) {
//                if (currentNode->left == nullptr) {
//                    Node * leftChild = new Node(new Data(value));
//                    leftChild->parent = currentNode;
//                    currentNode->left = leftChild;
//                    break;
//                } else
//                    currentNode = currentNode->left;
//            } else if (value > currentNode->data->value) {
//                if (currentNode->right == nullptr) {
//                    Node * rightChild = new Node(new Data(value));
//                    rightChild->parent = currentNode;
//                    currentNode->right = rightChild;
//                    break;
//                } else
//                    currentNode = currentNode->right;
//            } else
//                break;
//        }
//    }
//
//    void remove(int value) {
//        Node * removableNode = search(root, value);
//        if (removableNode == nullptr)
//            return;
//        Node * parentNode = removableNode->parent;
//
//        if (removableNode->left == nullptr && removableNode->right == nullptr) {
//
//
//            if (parentNode != nullptr) {
//                if (parentNode->left == removableNode)
//                    parentNode->left = nullptr;
//                else if (parentNode->right == removableNode)
//                    parentNode->right = nullptr;
//            }
//            if (removableNode == root)
//                root = nullptr;
//
//            delete removableNode;
//
//        } else if (removableNode->left == nullptr || removableNode->right == nullptr) {
//            if (removableNode->left == nullptr) {
//
//                if (parentNode != nullptr) {
//                    if (parentNode->left == removableNode)
//                        parentNode->left = removableNode->right;
//                    else if (parentNode->right == removableNode)
//                        parentNode->right = removableNode->right;
//                }
//
//                removableNode->right->parent = parentNode;
//
//                if (removableNode == root)
//                    root = removableNode->right;
//
//                delete removableNode;
//            } else if (removableNode->right == nullptr) {
//                if (parentNode != nullptr) {
//
//                    if (parentNode->left == removableNode)
//                        parentNode->left = removableNode->left;
//                    else if (parentNode->right == removableNode)
//                        parentNode->right = removableNode->left;
//                }
//
//                removableNode->left->parent = parentNode;
//
//                if (removableNode == root)
//                    root = removableNode->left;
//
//                delete removableNode;
//            }
//        } else if (removableNode->left != nullptr && removableNode->right != nullptr) {
//            Node * successor = next(removableNode);
//            removableNode->data->value = successor->data->value;
//
//            if (successor->parent->left == successor) {
//                successor->parent->left = successor->right;
//                if (successor->right != nullptr)
//                    successor->right->parent = successor->parent;
//            } else if (successor->parent->right == successor) {
//                successor->parent->right = successor->right;
//                if (successor->right != nullptr)
//                    successor->right->parent = successor->parent;
//            }
//
//            delete successor;
//        }
//    }
//
//    template <typename T> void preorderTrarersal(T * node) {
//        if (node != nullptr) {
//            std::cout << node->data->value << " ";
//            preorderTrarersal(node->left);
//            preorderTrarersal(node->right);
//        }
//    }
//
//    template <typename T> void inorderTrarersal(T * node) {
//        if (node != nullptr) {
//            inorderTrarersal(node->left);
//            std::cout << node->data->value << " ";
//            inorderTrarersal(node->right);
//        }
//    }
//
//    template <typename T> void postorderTrarersal(T * node) {
//        if (node != nullptr) {
//            postorderTrarersal(node->left);
//            postorderTrarersal(node->right);
//            std::cout << node->data->value << " ";
//        }
//    }
//
//    template <typename T> int heightOfTree(T * node) {
//        if (node == nullptr)
//            return 0;
//
//        int left, right;
//        if (node->left != nullptr)
//            left = heightOfTree(node->left);
//        else
//            left = 0;
//
//        if (node->right != nullptr)
//            right = heightOfTree(node->right);
//        else
//            right = 0;
//
//        return (left > right) ? left+1 : right+1;
//    }
//};
//
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    Tree * tree = new Tree();
//
//    std::string command;
//
//    while(std::cin >> command) {
//        int value;
//        std::cin >> value;
//
//        if (command == "insert") {
//            tree->insert(value);
//        } else if (command == "delete") {
//            tree->remove(value);
//        } else if (command == "exists") {
//            Node* human = tree->search(tree->root, value);
//            if (human == nullptr)
//                std::cout << "false\n";
//            else
//                std::cout << "true\n";
//        } else if (command == "next") {
//
//            Node * nextNode = tree->findNext(value, tree->root);
//            if (nextNode == nullptr)
//                std::cout << "none\n";
//            else
//                std::cout << nextNode->data->value << "\n";
//        } else if (command == "prev") {
//
//            Node * prevNode = tree->findPrev(value, tree->root);
//            if (prevNode == nullptr)
//                std::cout << "none\n";
//            else
//                std::cout << prevNode->data->value << "\n";
//        }
//
//    }
//
//
//    delete tree;
//
//    return 0;
//}