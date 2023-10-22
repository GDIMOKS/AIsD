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
//    Node(int _value):Node() {
//        value = _value;
//    }
//
//};
//
//struct Stack {
//    Node * head;
//
//    bool isEmpty() {
//        if (head == nullptr)
//            return true;
//        return false;
//    }
//
//    void push(int value) {
//        if (isEmpty()) {
//            head = new Node(value);
//        } else {
//            Node * element = new Node(value);
//            element->prev = head;
//            head = element;
//        }
//    }
//
//    int pop() {
//        if (!isEmpty()) {
//            int value = head->value;
//            Node * prevElement = head->prev;
//            head = prevElement;
//
//            return value;
//        } else {
//            std::cout << "Stack underflow!\n";
//            exit(1);
//        }
//    }
//
//    void print() {
//        Node * element = head;
//        while(element != nullptr) {
//            std::cout << element->value << " ";
//            element = element->prev;
//        }
//    }
//};
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    Stack * stack = new Stack();
//
//    int n;
//    std::cin >> n;
//
//    int * a = new int[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> a[i];
//    }
//
//    long long square = 0;
//    for (int i = 0; i < n; i++) {
//        while (!stack->isEmpty() && a[i] < a[stack->head->value]) {
//            int j = stack->pop();
//
//            long long width;
//            if (stack->isEmpty())
//                width = i;
//            else
//                width = ((i - stack->head->value) - 1);
//
//            square = std::max(square, a[j] * width);
//        }
//        stack->push(i);
//    }
//
//    while (!stack->isEmpty()) {
//        int i = stack->pop();
//        long long width;
//
//        if (stack->isEmpty()) {
//            width = n;
//        } else {
//            width = (n - (stack->head->value) - 1);
//        }
//        square = std::max(square, a[i] * width);
//    }
//
//    std::cout << square << "\n";
//
//    delete stack;
//
//    return 0;
//}

