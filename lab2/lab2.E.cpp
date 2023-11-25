#include <iostream>

struct Data {
    int value;
    int index;

    Data() {};
    Data(int _value) {
        value = _value;
    }
    Data(int _value, int _index) : Data(_value) {
        index = _index;
    }
};

struct Node {
    Data * data;
    Node * prev;
    Node * next;

    Node() {
        prev = nullptr;
        next = nullptr;
    };
    Node(int _value, int _index):Node() {
        data = new Data(_value, _index);
    }
    Node(Data * _data):Node() {
        data = _data;
    }
};

struct Stack {
    Node * head;

    bool isEmpty() {
        if (head == nullptr)
            return true;
        return false;
    }

    void push(int value) {
        if (isEmpty()) {
            head = new Node(new Data(value));
        } else {
            Node * element = new Node(new Data(value));
            element->prev = head;
            head = element;
        }
    }
    void push(Data * data) {
        if (isEmpty()) {
            head = new Node(data);
        } else {
            Node * element = new Node(data);
            element->prev = head;
            head = element;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int value = head->data->value;
            Node * prevElement = head->prev;
            head = prevElement;

            return value;
        } else {
            std::cout << "Stack underflow!\n";
            exit(1);
        }
    }

    void print() {
        Node * element = head;
        while(element != nullptr) {
            std::cout << element->data->value << " ";
            element = element->prev;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int * calendar = new int[n];
    Stack * result = new Stack();
    Stack * diffDays = new Stack();

    for (int i = 0; i < n; i++) {
        int diffLevel;
        std::cin >> diffLevel;
        calendar[i] = diffLevel;
    }

    for (int i = n-1; i >= 0; i--) {

        while (!diffDays->isEmpty()) {
            if (calendar[i] >= diffDays->head->data->value) {
                diffDays->pop();
            } else {
                break;
            }
        }
        if (diffDays->isEmpty()) {
            result->push(-1);
        } else {
            result->push(diffDays->head->data->index - i);
        }

        diffDays->push(new Data(calendar[i], i));

    }

    result->print();

    delete diffDays;
    delete result;
    delete [] calendar;

    return 0;
}



