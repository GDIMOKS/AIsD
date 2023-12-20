#include <iostream>

#define STACKSIZE 1000000

struct Node {
    int value;
    Node * prev;

    Node() {
        this->prev = nullptr;
    };
    Node(int value):Node() {
        this->value = value;
    }
};

struct Stack {
    Node * head;
    int count = 0;
    int maxSize = STACKSIZE;

    bool isFull() {
        if (count == maxSize)
            return true;
        return false;
    }

    bool isEmpty() {
        if (count == 0)
            return true;
        return false;
    }

    void push(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                head = new Node(value);
            } else {
                Node * element = new Node(value);
                element->prev = head;
                head = element;
            }

            count++;
        } else {
            std::cout << "Stack overflow!\n";
            exit(1);
        }
    }

    int pop() {
        if (!isEmpty()) {
            int value = head->value;
            Node * prevElement = head->prev;
            head = prevElement;
            count--;
            return value;
        } else {
            std::cout << "Stack underflow!\n";
            exit(1);
        }
    }

    void print() {
        Node * element = head;
        while(element != nullptr) {
            std::cout << element->value << " ";
            element = element->prev;
        }
    }
};





int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Stack * stack = new Stack();
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char sign;

        std::cin >> sign;

        switch (sign) {
            case '+':
                int value;
                std::cin >> value;
                stack->push(value);
                break;

            case '-':
                std::cout << stack->pop() << "\n";
                break;

            default:
                return 0;
        }
    }

    delete stack;

    return 0;
}
