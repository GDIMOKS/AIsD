#include <iostream>

#define QUEUESIZE 1000000

struct Node {
    int value;
    Node * prev;
    Node * next;

    Node() {
        prev = nullptr;
        next = nullptr;
    };
    Node(int value):Node() {
        this->value = value;
    }
};

struct Queue {
    Node * head;
    Node * tail;
    int count = 0;
    int maxSize = QUEUESIZE;

    Queue() {
        head = new Node();
        tail = head;
    }

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

    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                head = new Node(value);
                tail = head;
            } else {
                Node * element = new Node(value);
                element->prev = tail;
                tail->next = element;
                tail = element;
            }

            count++;
        } else {
            std::cout << "Queue overflow!\n";
            exit(1);
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int value = head->value;
            if (head != tail) {
                Node * nextElement = head->next;
                head = nextElement;
                head->prev = nullptr;
            }

            count--;
            return value;
        } else {
            std::cout << "Queue underflow!\n";
            exit(1);
        }
    }

    void print() {
        Node * element = head;
        while(element != nullptr) {
            std::cout << element->value << " ";
            element = element->next;
        }
    }
};





int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Queue * queue = new Queue();
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char sign;

        std::cin >> sign;

        switch (sign) {
            case '+':
                int value;
                std::cin >> value;
                queue->enqueue(value);
                break;

            case '-':
                std::cout << queue->dequeue() << "\n";
                break;

            default:
                return 0;
        }
    }

    delete queue;

    return 0;
}