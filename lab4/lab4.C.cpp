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
//    int size;
//
//    BasicNode() {
//        data = nullptr;
//        parent = left = right = nullptr;
//    }
//    BasicNode(Data * _data) : BasicNode() {
//        data = _data;
//        size = 1;
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
//class Tree {
//public:
//    Node * root;
//
//    int size(Node * node) {
//        return (node != nullptr) ? node->size : 0;
//    }
//
//    void updateSize(Node * node) {
//        if (node != nullptr) {
//            node->size = 1 + size(node->left) + size(node->right);
//        }
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
//    Node* insert(Node* node, int value) {
//        if (node == nullptr)
//            return new Node(new Data(value));
//        else if (value < node->data->value)
//            node->left = insert(node->left, value);
//        else if (value > node->data->value)
//            node->right = insert(node->right, value);
//        updateSize(node);
//        return node;
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
//    Node * remove(Node * root, int value) {
//        if (root == nullptr)
//            return root;
//        if (value < root->data->value)
//            root->left = remove(root->left, value);
//        else if (value > root->data->value)
//            root->right = remove(root->right, value);
//        else if (root->left != nullptr && root->right != nullptr) {
//            root->data->value = minimum(root->right)->data->value;
//            root->right = remove(root->right, root->data->value);
//        } else {
//            if (root->left != nullptr)
//                root = root->left;
//            else if (root->right != nullptr)
//                root = root->right;
//            else
//                root = nullptr;
//        }
//        updateSize(root);
//
//        return root;
//    }
//
//    int findKMax(Node * node, int k) {
//        int leftSize = size(node->left);
//        if (leftSize == k) {
//            return node->data->value;
//        } else if (leftSize > k) {
//            return findKMax(node->left, k);
//
//        } else {
//            k -= leftSize + 1;
//            return findKMax(node->right, k);
//        }
//    }
//
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
//
//};
//
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    Tree * tree = new Tree();
//
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        int command;
//        int value;
//        std::cin >> command >> value;
//
//        switch (command) {
//            case -1:
//                tree->root = tree->remove(tree->root, value);
//                break;
//            case 1:
//                tree->root = tree->insert(tree->root,value);
//                break;
//            case 0:
//                std::cout << tree->findKMax(tree->root, tree->size(tree->root) - value) << "\n";
//                break;
//        }
//
///*        tree->preorderTrarersal(tree->root);
//        std::cout << "\n" << tree->size(tree->root) << "\n";*/
//    }
//
//
//    delete tree;
//
//    return 0;
//}
