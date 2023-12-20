#include <iostream>

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

class AVLNode : public BasicNode<AVLNode> {
public:
    int height;

    AVLNode() : BasicNode<AVLNode>() {
    }

    AVLNode(Data * _data) : AVLNode() {
        data = _data;
        height = 1;
    }
};

class Tree {
public:
    Node * root;

    template <typename T> T* search(T * currentNode, int value) {
        if (currentNode == nullptr || value == currentNode->data->value)
            return currentNode;
        if (value < currentNode->data->value)
            return search(currentNode->left, value);
        if (value > currentNode->data->value)
            return search(currentNode->right, value);
    }

    template <typename T> T* prev(T * currentNode) {

        if (currentNode->left != nullptr) {
            return maximum(currentNode->left);
        }
        T * parentNode = currentNode->parent;

        while (parentNode != nullptr && currentNode == parentNode->left) {
            currentNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }

    template <typename T> T* next(T * currentNode) {
        if (currentNode->right != nullptr) {
            return minimum(currentNode->right);
        }
        T * parentNode = currentNode->parent;

        while (parentNode != nullptr && currentNode == parentNode->right) {
            currentNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }

    template <typename T> T* minimum(T * currentNode) {
        return (currentNode->left == nullptr) ? currentNode : minimum(currentNode->left);
    }

    template <typename T> T* maximum(T * currentNode) {
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
        if (root == nullptr) {
            root = new Node(new Data(value));
            return;
        }

        if (currentNode == nullptr)
            currentNode = root;
        while (currentNode != nullptr) {
            if (value <= currentNode->data->value) {
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

    void remove(int value) {
        Node * removableNode = search(root, value);
        if (removableNode == nullptr)
            return;
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

    template <typename T> void preorderTrarersal(T * node) {
        if (node != nullptr) {
            std::cout << node->data->value << " ";
            preorderTrarersal(node->left);
            preorderTrarersal(node->right);
        }
    }

    template <typename T> void inorderTrarersal(T * node) {
        if (node != nullptr) {
            inorderTrarersal(node->left);
            std::cout << node->data->value << " ";
            inorderTrarersal(node->right);
        }
    }

    template <typename T> void postorderTrarersal(T * node) {
        if (node != nullptr) {
            postorderTrarersal(node->left);
            postorderTrarersal(node->right);
            std::cout << node->data->value << " ";
        }
    }

    template <typename T> int heightOfTree(T * node) {
        if (node == nullptr)
            return 0;

        int left, right;
        if (node->left != nullptr)
            left = heightOfTree(node->left);
        else
            left = 0;

        if (node->right != nullptr)
            right = heightOfTree(node->right);
        else
            right = 0;

        return (left > right) ? left+1 : right+1;
    }
};

class AVLTree : public Tree {
public:

    AVLNode * root;

    int heightOfTree(AVLNode * node) {
        return (node != nullptr) ? node->height : 0;
    }

    int bfactor(AVLNode * p) {
        return heightOfTree(p->right) - heightOfTree(p->left);
    }

    void fixHeight(AVLNode * node) {
        int leftHeight = heightOfTree(node->left);
        int rightHeight = heightOfTree(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
    }

    AVLNode* rotateLeft(AVLNode * q) {
        AVLNode * p = q->right;

        q->right = p->left;

        if (q->right != nullptr)
            q->right->parent = p;

        p->left = q;

        p->parent = q->parent;
        q->parent = p;

        fixHeight(q);
        fixHeight(p);

        return p;
    }

    AVLNode* rotateRight(AVLNode * p) {
        AVLNode * q = p->left;

        p->left = q->right;

        if (p->left != nullptr)
            p->left->parent = q;

        q->right = p;

        q->parent = p->parent;
        p->parent = q;

        fixHeight(p);
        fixHeight(q);

        return q;
    }

    AVLNode* balance(AVLNode * p) {
        fixHeight(p);

        if (bfactor(p) == 2) {
            if (bfactor(p->right) < 0)
                p->right = rotateRight(p->right);
            return rotateLeft(p);
        }

        if (bfactor(p) == -2) {
            if (bfactor(p->left) > 0)
                p->left = rotateLeft(p->left);
            return rotateRight(p);
        }

        return p;
    }


    void insert(int value, AVLNode* currentNode = nullptr) {
        if (root == nullptr) {
            root = new AVLNode(new Data(value));
            return;
        }
        if (currentNode == nullptr)
            root = insertNode(value, root);
        else
            root = insertNode(value, currentNode);
    }

    void remove(int value, AVLNode* currentNode = nullptr) {
        if (currentNode == nullptr)
            root = removeNode(value, root);
        else
            root = removeNode(value, currentNode);
    }



private:
    AVLNode* insertNode(int value, AVLNode* currentNode) {
        if (currentNode == nullptr)
            return new AVLNode(new Data(value));
        if (value < currentNode->data->value) {
            currentNode->left = insertNode(value, currentNode->left);
            currentNode->left->parent = currentNode;
        } else {
            currentNode->right = insertNode(value,currentNode->right);
            currentNode->right->parent = currentNode;
        }
        return balance(currentNode);
    }


    AVLNode* removeMin(AVLNode* p) {
        if (p->left == nullptr) {
            return p->right;
        }
        p->left = removeMin(p->left);

        return balance(p);
    }

    AVLNode* removeNode(int value, AVLNode* p) {
        if (p == nullptr)
            return nullptr;


        if (value < p->data->value)
            p->left = removeNode(value, p->left);
        else if (value > p->data->value)
            p->right = removeNode(value, p->right);
        else {
            AVLNode* q = p->left;
            AVLNode* r = p->right;
            if (r == nullptr) {
                if (q != nullptr)
                    q->parent = p->parent;

                return q;
            }

            AVLNode * min = minimum(r);
            min->right = removeMin(r);
            min->left = q;

            if (min->parent != nullptr) {
                min->parent->left = nullptr;
                min->parent = p->parent;
            }

            delete p;

            if (q != nullptr)
                q->parent = min;

            return balance(min);
        }

        return balance(p);
    }
};

AVLNode* sortedArrayToAvlTree(int * values, int begin, int end) {
    if (begin > end)
    {
        return nullptr;
    }

    int middle = begin + (end - begin)/2;
    AVLNode * node = new AVLNode(new Data(values[middle]));

    node->left = sortedArrayToAvlTree(values, begin, middle-1);
    node->right = sortedArrayToAvlTree(values, middle+1, end);

    return node;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    AVLTree * avlTree = new AVLTree();

    int n;
    std::cin >> n;
    int * values = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    avlTree->root = sortedArrayToAvlTree(values, 0, n-1);
    avlTree->preorderTrarersal(avlTree->root);

    delete avlTree;

    return 0;
}