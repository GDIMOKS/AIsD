#include <iostream>
#include <vector>

class Data {
public:
    int key;
    int value;

    Data(int _value) {
        value = _value;
    }
    Data(int _key, int _value) : Data(_value){
        key = _key;
    }
};

class Node {
public:
    Data * data;
    Node * next;

    Node() {
        data = nullptr;
        next = nullptr;
    }

    Node(Data * _data) : Node() {
        data = _data;
    }
};

class Hashtable {
public:
    int size;
    int currentSize;
    std::vector<Node *> data;


    Hashtable() {
        currentSize = 0;
    }
    Hashtable(int _size) : Hashtable() {
        size = _size;
        data.resize(size);
    }

    void insert(int key, int value) {
        int index = getHash(key);
        Node * node = new Node(new Data(key, value));
        node->next = data[index];
        data[index] = node;
        currentSize++;
    }

    int search(int key) {
        if (currentSize <= 0)
            return -1;

        int index = getHash(key);

        Node * currentNode = data[index];
        while (currentNode != nullptr) {
            if (currentNode->data->key == key)
                return currentNode->data->value;
            currentNode = currentNode->next;
        }

        return -1;

    }

    int getHash(int value) {
        return abs(value) % size;
    }

};


int countPairs(std::vector<int>& values) {

    int n = values.size();
    int count = 0;

    Hashtable hashTable(2 * n + 1);

    for (int i = 0; i < n; ++i) {
        int difference = values[i] - i + n;

        int value = hashTable.search(difference);
        if (value == -1)
            value++;

        count += value;


        hashTable.insert(difference, value + 1);
    }

    return count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> values = std::vector<int>(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    std::cout << countPairs(values);


    return 0;
}