#include <iostream>
#include <sstream>

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
        if (currentNode == nullptr) return nullptr;

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

    template<typename T> T* findNext(int value, T * currentNode) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (currentNode->data->value > value) {
            T * minNode = findNext(value, currentNode->left);
            if (minNode != nullptr)
                return minNode;
            return currentNode;
        }
        if (currentNode->right != nullptr)
            return findNext(value, currentNode->right);
        else
            return nullptr;

    }

    template<typename T> T* findPrev(int value, T* currentNode) {
        if (currentNode == nullptr)
            return nullptr;

        if (currentNode->data->value < value) {
            T * maxNode = findPrev(value,currentNode->right);
            if (maxNode != nullptr)
                return maxNode;
            return currentNode;
        }
        if (currentNode->left != nullptr)
            return findPrev(value, currentNode->left);
        else
            return nullptr;
    }
    template <typename T> T* next (int value) {
        T * current = root, successor = nullptr;
        while (current != nullptr) {
            if (current->data->value > value) {
                successor = current;
                current = current->left;
            } else
                current = current->right;
        }
        return successor;
    }
    template <typename T> T* next(T * currentNode) {
        if (currentNode == nullptr) return nullptr;

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

    void insert(int value, Node * currentNode = nullptr) {
        if (root == nullptr) {
            root = new Node(new Data(value));
            return;
        }

        if (currentNode == nullptr)
            currentNode = root;
        while (currentNode != nullptr) {
            if (value >= currentNode->data->value) {
                if (currentNode->right == nullptr) {
                    Node * rightChild = new Node(new Data(value));
                    rightChild->parent = currentNode;
                    currentNode->right = rightChild;
                    break;
                } else
                    currentNode = currentNode->right;
            }else if (value <= currentNode->data->value) {
                if (currentNode->left == nullptr) {
                    Node * leftChild = new Node(new Data(value));
                    leftChild->parent = currentNode;
                    currentNode->left = leftChild;
                    break;
                } else
                    currentNode = currentNode->left;
            }
        }
    }

    void remove(int value) {
        Node * removableNode = search(root, value);
        if (removableNode == nullptr)
            return;
        Node * parentNode = removableNode->parent;

        if (removableNode->left == nullptr && removableNode->right == nullptr) {


            if (parentNode != nullptr) {
                if (parentNode->left == removableNode)
                    parentNode->left = nullptr;
                else if (parentNode->right == removableNode)
                    parentNode->right = nullptr;
            }
            if (removableNode == root)
                root = nullptr;

            delete removableNode;

        } else if (removableNode->left == nullptr || removableNode->right == nullptr) {
            if (removableNode->left == nullptr) {

                if (parentNode != nullptr) {
                    if (parentNode->left == removableNode)
                        parentNode->left = removableNode->right;
                    else if (parentNode->right == removableNode)
                        parentNode->right = removableNode->right;
                }

                removableNode->right->parent = parentNode;

                if (removableNode == root)
                    root = removableNode->right;

                delete removableNode;
            } else if (removableNode->right == nullptr) {
                if (parentNode != nullptr) {

                    if (parentNode->left == removableNode)
                        parentNode->left = removableNode->left;
                    else if (parentNode->right == removableNode)
                        parentNode->right = removableNode->left;
                }

                removableNode->left->parent = parentNode;

                if (removableNode == root)
                    root = removableNode->left;

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

    template <typename T> void preorderTrarersal(T * node, std::stringstream* ss) {
        if (node != nullptr) {
//            std::cout << node->data->value << " ";
            if ((*ss).str().empty()) {
                *ss << node->data->value;
            } else
                *ss << " " << node->data->value;

            preorderTrarersal(node->left, ss);
            preorderTrarersal(node->right, ss);
        }
    }

    template <typename T> void inorderTrarersal(T * node, std::stringstream* ss) {
        if (node != nullptr) {
            inorderTrarersal(node->left, ss);
            if ((*ss).str().empty()) {
                *ss << node->data->value;
            } else
                *ss << " " << node->data->value;
//            std::cout << node->data->value << " ";
            inorderTrarersal(node->right, ss);
        }
    }

    template <typename T> void postorderTrarersal(T * node, std::stringstream* ss) {
        if (node != nullptr) {
            postorderTrarersal(node->left, ss);
            postorderTrarersal(node->right, ss);
//            std::cout << node->data->value << " ";
            if ((*ss).str().empty()) {
                *ss << node->data->value;
            } else
                *ss << " " << node->data->value;
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Tree * tree = new Tree();

    int n;
    bool isTree = true;
    std::cin >> n;
    std::stringstream keys;

    for (int i = 0; i < 3; i++) {
        keys.str(std::string());

        for (int j = 0; j < n; j++) {
            int value;
            std::cin >> value;
            if (i == 0)
                tree->insert(value);

            if (keys.str().empty())
                keys << value;
            else
                keys << " " << value ;
        }

        std::stringstream keys2;
        if (i == 0) {

            tree->preorderTrarersal(tree->root, &keys2);
            if (keys2.str() != keys.str())
                isTree = false;
        }
        else if (i == 1 && isTree) {
            tree->inorderTrarersal(tree->root, &keys2);

            if (keys2.str() != keys.str())
                isTree = false;
        }
        else if (i == 2 && isTree) {
            tree->postorderTrarersal(tree->root, &keys2);

            if (keys2.str() != keys.str())
                isTree = false;
        }

    }

    if (isTree)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    delete tree;

    return 0;
}

