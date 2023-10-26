//#include <iostream>
//
//struct Node {
//    int data;
//    Node * parent;
//    Node * leftChild;
//    Node * rightChild;
//    Node * next;
//    Node * prev;
//
//    Node() {
//        parent = leftChild = rightChild = next = prev = nullptr;
//    }
//    Node(int _data) : Node() {
//        data = _data;
//    }
//    Node(Node* _prev, int _data) : Node(_data) {
//        prev = _prev;
//    }
//
//};
//
//struct HeapCool {
//    Node * root;
//    Node * last;
//
//    HeapCool() {
//        root =
//        last = nullptr;
//    }
//
//    void print() {
//        Node * node = root;
//        while (node != nullptr) {
//            std::cout << node->data << " ";
//            node = node->next;
//        }
//        std::cout << "\n";
//    }
//
//    void siftUp(Node * currentNode) {
//        Node * node = currentNode;
//        while(node->parent != nullptr) {
//            if (node->data >= node->parent->data)
//                break;
//            std::swap(node->data, node->parent->data);
//            node = node->parent;
//        }
//    }
//
//    void siftDown(Node * currentNode) {
//        Node * node = currentNode;
//
//        if (currentNode->leftChild != nullptr && node->data > currentNode->leftChild->data) {
//            node = currentNode->leftChild;
//        }
//        if (currentNode->rightChild != nullptr && node->data > currentNode->rightChild->data) {
//            node = currentNode->rightChild;
//        }
//
//        if (node != currentNode) {
//            std::swap(node->data, currentNode->data);
//            siftDown(node);
//        }
//    }
//
//    int extractMin() {
//        if (root == nullptr) {
//            return 1000000001;
//        }
//        int min = root->data;
//        if (root == last) {
//            last = root = nullptr;
//            return  min;
//        }
//        root->data = last->data;
//        if (last->parent->rightChild != nullptr)
//            last->parent->rightChild = nullptr;
//        else
//            last->parent->leftChild = nullptr;
//
//
//        last = last->prev;
//
//        last->next = nullptr;
//        if (last == nullptr)
//            root = last;
//
//        siftDown(root);
//
//        return min;
//    }
//
//    void insert(int value) {
//        if (root == nullptr) {
//            root = new Node(value);
//            last = root;
//            return;
//        }
//
//        Node * node = root;
//        last->next = new Node(last, value);
//        last = last->next;
//
//        while (node->leftChild != nullptr && node->rightChild != nullptr) {
//            node = node->next;
//        }
//
//        if (node->leftChild == nullptr)
//            node->leftChild = last;
//        else
//            node->rightChild = last;
//
//        last->parent = node;
//        siftUp(last);
//
//    }
//
//    void merge(HeapCool *heap1, HeapCool *heap2) {
//        Node * node = heap1->root;
////        Queue * queue = new Queue();
//        while (node != nullptr) {
//            insert(node->data);
////            queue->enqueue(node->data);
//            node = node->next;
//        }
//        node = heap2->root;
//        while (node != nullptr) {
////            queue->enqueue(node->data);
//            insert(node->data);
//            node = node->next;
//        }
////        node = root;
////        while (node->leftChild != nullptr && node->rightChild != nullptr) {
////            node = node->next;
////        }
////        queue->print();
//    }
//
//    void decreaseKey(int xIndex, int yValue) {
//        Node * node = root;
//        for (int i = 0; i < xIndex; i++) {
//            node = node->next;
//        }
//        node->data = yValue;
//        siftUp(node);
//    }
//};
//
//void addHeaps(HeapCool *&heaps, int &maxSize, int size) {
//    HeapCool * tempHeaps;
//    maxSize *= 5;
//    tempHeaps = new HeapCool[maxSize];
//    for (int i = 0; i < size; i ++) {
//        tempHeaps[i] = heaps[i];
//    }
//    if (maxSize != 0)
//        delete [] heaps;
//    heaps = tempHeaps;
//}
//
//int main() {
////    std::ios::sync_with_stdio(false);
////    std::cin.tie(nullptr);
//
//
//    std::string command;
//    int maxSize = 64;
//    HeapCool * heaps = new HeapCool[maxSize];
//    int count = 0;
//
//    while(std::cin >> command){
//        int x,y,k,m;
//
//        switch (command[0]) {
//            case 'c':
//                if (count >= maxSize)
//                    addHeaps(heaps, maxSize, count);
//
//                heaps[count] = HeapCool();
//                count++;
//                break;
//            case 'i':
//                std::cin >> k >> x;
//                heaps[k].insert(x);
////                heaps[k].print();
//                break;
//            case 'e':
//                std::cin >> k;
//                int result;
//                result = heaps[k].extractMin();
//                if (result == 1000000001)
//                    std::cout << "*\n";
//                else
//                    std::cout << result << "\n";
//
////                heaps[k].print();
//
//                break;
//            case 'm':
//                std::cin >> k >> m;
//                addHeaps(heaps, maxSize, count);
//                heaps[count] = HeapCool();
//                heaps[count].merge(&heaps[k], &heaps[m]);
////                heaps[count].print();
//                count++;
//
//                break;
//            case 'd':
//                std::cin >> k >> x >> y;
//                heaps[k].decreaseKey(x-1,y);
////                heaps[k].print();
//                break;
//        }
//
//    }
//
//    delete [] heaps;
//
//
//    return 0;
//}
//
