//#include <iostream>
//#include <vector>
//#include <stack>
//
//class Data {
//public:
//    int value;
//    int points;
//    Data() {}
//    Data(int _value) : Data() {
//        value = _value;
//    }
//    Data(int _value, int _points) : Data(_value) {
//        points = _points;
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
//class AVLNode : public BasicNode<AVLNode> {
//public:
//    int height;
//
//    AVLNode() : BasicNode<AVLNode>() {
//    }
//
//    AVLNode(Data * _data) : AVLNode() {
//        data = _data;
//        height = 1;
//    }
//};
//class Tree {
//public:
//    Node * root;
//
//    template <typename T> T* minimum(T * currentNode) {
//        return (currentNode->left == nullptr) ? currentNode : minimum(currentNode->left);
//    }
//
//    template <typename T> void preorderTrarersal(T * node, Data * maxPointsStudent, int& size, long long& sum) {
//        if (node != nullptr) {
//            sum += node->data->points;
//            size++;
//            if (node->data->points > maxPointsStudent->points) {
//                maxPointsStudent->value = node->data->value;
//                maxPointsStudent->points = node->data->points;
//            }
//
//            preorderTrarersal(node->left, maxPointsStudent, size, sum);
//            preorderTrarersal(node->right, maxPointsStudent, size, sum);
//        }
//    }
//
//    template <typename T> void inorderTrarersal(T * node) {
//        if (node != nullptr) {
//            inorderTrarersal(node->left);
//            std::cout << node->data->value << ": " << node->data->points << " ";
//            inorderTrarersal(node->right);
//        }
//    }
//
//    template <typename T> void postorderTrarersal(T * node) {
//        if (node != nullptr) {
//            postorderTrarersal(node->left);
//            postorderTrarersal(node->right);
//            std::cout << node->data->value << ": " << node->data->points << " ";
//
//        }
//
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
//class AVLTree : public Tree {
//public:
//
//    AVLNode * root;
//
//    int heightOfTree(AVLNode * node) {
//        return (node != nullptr) ? node->height : 0;
//    }
//
//    int bfactor(AVLNode * p) {
//        return heightOfTree(p->right) - heightOfTree(p->left);
//    }
//
//    void fixHeight(AVLNode * node) {
//        int leftHeight = heightOfTree(node->left);
//        int rightHeight = heightOfTree(node->right);
//        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
//    }
//
//    AVLNode* rotateLeft(AVLNode * q) {
//        AVLNode * p = q->right;
//
//        q->right = p->left;
//
//        if (q->right != nullptr)
//            q->right->parent = p;
//
//        p->left = q;
//
//        p->parent = q->parent;
//        q->parent = p;
//
//        fixHeight(q);
//        fixHeight(p);
//
//        return p;
//    }
//
//    AVLNode* rotateRight(AVLNode * p) {
//        AVLNode * q = p->left;
//
//        p->left = q->right;
//
//        if (p->left != nullptr)
//            p->left->parent = q;
//
//        q->right = p;
//
//        q->parent = p->parent;
//        p->parent = q;
//
//        fixHeight(p);
//        fixHeight(q);
//
//        return q;
//    }
//
//    AVLNode* balance(AVLNode * p) {
//        fixHeight(p);
//
//        if (bfactor(p) == 2) {
//            if (bfactor(p->right) < 0)
//                p->right = rotateRight(p->right);
//            return rotateLeft(p);
//        }
//
//        if (bfactor(p) == -2) {
//            if (bfactor(p->left) > 0)
//                p->left = rotateLeft(p->left);
//            return rotateRight(p);
//        }
//
//        return p;
//    }
//
//
//    void insert(Data * student, AVLNode* currentNode = nullptr) {
//
//        if (root == nullptr) {
//            root = new AVLNode(student);
//            return;
//        }
//        if (currentNode == nullptr)
//            root = insertNode(student, root);
//        else
//            root = insertNode(student, currentNode);
//    }
//
//    void remove(int value, AVLNode* currentNode = nullptr) {
//        if (currentNode == nullptr)
//            root = removeNode(value, root);
//        else
//            root = removeNode(value, currentNode);
//    }
//
//
//
//private:
//    AVLNode* insertNode(Data * student, AVLNode* currentNode) {
//        if (currentNode == nullptr)
//            return new AVLNode(student);
//        if (student->value < currentNode->data->value) {
//            currentNode->left = insertNode(student, currentNode->left);
//            currentNode->left->parent = currentNode;
//        } else {
//            currentNode->right = insertNode(student,currentNode->right);
//            currentNode->right->parent = currentNode;
//        }
//        return balance(currentNode);
//    }
//
//
//    AVLNode* removeMin(AVLNode* p) {
//        if (p->left == nullptr) {
//            return p->right;
//        }
//        p->left = removeMin(p->left);
//
//        return balance(p);
//    }
//
//    AVLNode* removeNode(int value, AVLNode* p) {
//        if (p == nullptr)
//            return nullptr;
//
//
//        if (value < p->data->value)
//            p->left = removeNode(value, p->left);
//        else if (value > p->data->value)
//            p->right = removeNode(value, p->right);
//        else {
//            AVLNode* q = p->left;
//            AVLNode* r = p->right;
//            if (r == nullptr) {
//                if (q != nullptr)
//                    q->parent = p->parent;
//
//                return q;
//            }
//
//            AVLNode * min = minimum(r);
//            min->right = removeMin(r);
//            min->left = q;
//
//            if (min->parent != nullptr) {
//                min->parent->left = nullptr;
//                min->parent = p->parent;
//            }
//
//            delete p;
//
//            if (q != nullptr)
//                q->parent = min;
//
//            return balance(min);
//        }
//
//        return balance(p);
//    }
//};
//
//class Pair {
//public:
//    int key;
//    int status;
//    AVLTree * group;
//
//    Pair() {
//        status = 0;
//        group = new AVLTree();
//    }
//    Pair(int _key) : Pair() {
//        key = _key;
//    }
//};
//
//class Hashtable {
//public:
//    int size;
//    int currentSize;
//    std::vector<Pair*> values;
//
//
//    Hashtable() {
//        currentSize = 0;
//    }
//    Hashtable(int _size) : Hashtable() {
//        size = _size;
//        values = std::vector<Pair*>(size);
//        for (int i = 0; i < size; i++)
//            values[i] = new Pair();
//
//    }
//
//
//    int insert(int value) {
//        if (currentSize >= size)
//            return -1;
//
//        int index = getHash(value);
//
//        if (values[index]->key == value)
//            return index;
//
//        if (values[index]->status == 0) {
//            values[index]->key = value;
//            values[index]->status = 1;
//            currentSize++;
//
//            return index;
//        } else {
//            int tempIndex = index;
//
//            while (values[tempIndex]->status != 0) {
//                tempIndex++;
//
//                if (tempIndex >= size)
//                    tempIndex %= size;
//
//            }
//            if (values[tempIndex]->status != 1) {
//                values[tempIndex]->status = 1;
//                values[tempIndex]->key = value;
//                currentSize++;
//
//                return tempIndex;
//            }
//            return -1;
//        }
//    }
//
//    int search(int value) {
//        if (currentSize <= 0)
//            return -1;
//
//        int index = getHash(value);
//        int tempIndex = index;
//
//        while (values[tempIndex]->status != 0) {
//            if (values[tempIndex]->status == 1 &&
//                values[tempIndex]->key == value) {
//                return tempIndex;
//            }
//
//            tempIndex++;
//
//            if (tempIndex >= size)
//                tempIndex %= size;
//        }
//
//        return -1;
//
//    }
//
//
//    void remove(int value) {
//        if (currentSize <= 0)
//            return;
//
//        int key = search(value);
//        if (key != -1) {
//            values[key]->status = 2;
//            currentSize--;
//        }
//
//    }
//
//    void addStudent(int group, int isu, int points) {
//        int key = search(group);
//
//        if (key == -1)
//            key = insert(group);
//
//        values[key]->group->insert(new Data(isu,points));
//
//    }
//
//    void removeStudent(int group, int isu) {
//
//
//        int key = search(group);
//        if (key != -1) {
//            values[key]->group->remove(isu, values[key]->group->root);
//        }
//    }
//
//    int getHash(int value) {
////        return size * (std::abs(value) * 0,618 % 1);
//        return abs(value) % size;
//    }
//
//    void getMaxPointsStudent(int group) {
//        int key = search(group);
//        if (key != -1) {
//            long long sum = 0;
//            Data * student = new Data(0, INT_MIN);
//            int sizeOfTree = 0;
//            values[key]->group->preorderTrarersal(values[key]->group->root, student, sizeOfTree, sum);
//
//            std::cout << student->points << "\n";
//
//
//        }else
//            std::cout << 0 << "\n";
//    }
//    void getAvgPoints(int group) {
//        int key = search(group);
//        if (key != -1) {
//            long long sum = 0;
//            Data * student = new Data(0, INT_MIN);
//            int sizeOfTree = 0;
//            values[key]->group->preorderTrarersal(values[key]->group->root, student, sizeOfTree, sum);
//
//            long long avg = sum/sizeOfTree;
//            std::cout << avg << "\n";
//        } else
//            std::cout << 0 << "\n";
//
//    }
//
//};
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    Hashtable * hashtable = new Hashtable(10000);
//
//    int M, Q;
//    std::cin >> M >> Q;
//
//    for (int i = 0; i < Q; i++) {
//        char command;
//        int group, isu;
//        std::cin >> command >> group;
//
//        switch (command) {
//            case 'a':
//                hashtable->getAvgPoints(group);
//                break;
//
//            case '-':
//                std::cin >> isu;
//                hashtable->removeStudent(group, isu);
//                break;
//
//            case '+':
//                int points;
//                std::cin >> isu >> points;
//                hashtable->addStudent(group, isu, points);
//
//                break;
//
//            case 'm':
//                hashtable->getMaxPointsStudent(group);
//                break;
//        }
//    }
//
//    delete hashtable;
//
//    return 0;
//}
