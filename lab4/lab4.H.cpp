//#include <iostream>
//
//class Data {
//public:
//    std::string value;
//    bool indexes[3]{};
//    int count;
//    Data() {}
//    Data(std::string _value, int index) : Data() {
//        value = _value;
//        count = 1;
//        indexes[index] = true;
//    }
//
//    int getMark() {
//        switch (count) {
//            case 1:
//                return 3;
//            case 2:
//                return 1;
//            case 3:
//                return 0;
//        }
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
//    template <typename T> T* search(T * currentNode, std::string value) {
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
//    Node* insert(Node* node, std::string value, int index) {
//        if (node == nullptr)
//            return new Node(new Data(value, index));
//
//        else if (value < node->data->value)
//            node->left = insert(node->left, value, index);
//        else if (value > node->data->value)
//            node->right = insert(node->right, value, index);
//        else if (value == node->data->value) {
//            node->data->count++;
//            node->data->indexes[index] = true;
//        }
//        return node;
//
//    }
//
//    template <typename T> void preorderTrarersal(T * node, int * persons) {
//        if (node != nullptr) {
//
//            for (int i = 0; i < 3; i++) {
//                if (node->data->indexes[i]) {
//                    persons[i] += node->data->getMark();
//                }
//            }
//            preorderTrarersal(node->left, persons);
//            preorderTrarersal(node->right, persons);
//        }
//    }
//
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
//    int n;
//
//    std::cin >> n;
//    Tree * tree = new Tree();
//
//    for (int j = 0; j < 3; j++) {
//        for (int i = 0; i < n; i++) {
//            std::string file;
//            std::cin >> file;
//            tree->root = tree->insert(tree->root,file, j);
//        }
//    }
//    int persons[3] = {0};
//
//    tree->preorderTrarersal(tree->root, persons);
//
//    for (int i = 0; i < 3; i++) {
//        std::cout << persons[i] << " ";
//    }
//
//    std::cout << "\n";
//    delete tree;
//
//    return 0;
//}
