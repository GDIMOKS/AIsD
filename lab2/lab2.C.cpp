//#include <iostream>
//
//struct Node {
//    int value;
//    Node * prev;
//    Node * next;
//
//    Node() {
//        prev = nullptr;
//        next = nullptr;
//    };
//    Node(int value):Node() {
//        this->value = value;
//    }
//};
//
//struct Backpack {
//    Node * head;
//    Node * tail;
//    int count = 0;
//    int maxSize;
//
//    Backpack() {
//        head = new Node();
//        tail = head;
//    }
//    Backpack(int size) : Backpack() {
//        this->maxSize = size;
//    }
//
//    bool isFull() {
//        if (count >= maxSize)
//            return true;
//        return false;
//    }
//
//    bool isEmpty() {
//        if (count == 0)
//            return true;
//        return false;
//    }
//
//    void enqueue(int value) {
//        if (!isFull()) {
//            if (isEmpty()) {
//                head = new Node(value);
//                tail = head;
//            } else {
//                Node * element = new Node(value);
//                element->prev = tail;
//                tail->next = element;
//                tail = element;
//            }
//
//            count++;
//        } else {
////            std::cout << "Queue overflow!\n";
////            exit(1);
//            int headValue = dequeueHead();
//            count--;
//            if (!isEmpty()) {
//                int max1 = headValue;
//                int max2 = dequeueTail();
//                count--;
//
//                if (max1 < max2) {
//                    int temp;
//                    temp = max1;
//                    max1 = max2;
//                    max2 = temp;
//                }
//                if (max1 < value) {
//                    max2 = max1;
//                    max1 = value;
//                } else {
//                    if (max2 < value)
//                        max2 = value;
//                }
//                enqueue(max2);
//                enqueue(max1);
//                count += 2;
//            } else {
//                if (headValue > value)
//                    enqueue(headValue);
//                else
//                    enqueue(value);
//                count++;
//            }
//        }
//    }
//
//    int dequeueTail() {
//        if (!isEmpty()) {
//            int value = tail->value;
//            if (head != tail) {
//                Node * prevElement = tail->prev;
//                tail = prevElement;
//                tail->next = nullptr;
//            }
//            count--;
//            return value;
//        } else {
//            std::cout << "Queue underflow!\n";
//            exit(1);
//        }
//    }
//
//    int dequeueHead() {
//        if (!isEmpty()) {
//            int value = head->value;
//            if (head != tail) {
//                Node * nextElement = head->next;
//                head = nextElement;
//                head->prev = nullptr;
//            }
//
//            count--;
//            return value;
//        } else {
//            std::cout << "Queue underflow!\n";
//            exit(1);
//        }
//    }
//
//    void print() {
//        Node * element = head;
//        while(element != nullptr) {
//            std::cout << element->value << " ";
//            element = element->next;
//        }
//    }
//};
//
//
//
//
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int n, m;
//    std::cin >> n >> m;
//    Backpack * bag = new Backpack(m);
//
//    for (int i = 0; i < n; i++) {
//        int treasure;
//
//        std::cin >> treasure;
//        bag->enqueue(treasure);
//    }
//
//    bag->print();
//
//    delete bag;
//
//    return 0;
//}
