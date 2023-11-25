#include "iostream"
#include "vector"

class Node {
public:
    int value;
    int status; // 0 - пуст, 1 - занят, 2 - удален
    bool checked;

    Node() {
        status = 0;
        checked = false;
    }
    Node(int _value) : Node() {
        value = _value;
    }
};

class Hashtable {
public:


    std::vector<Node*> values;
    int size;
    int currentSize;

    Hashtable() {
        currentSize = 0;
    }

    Hashtable(int _size) : Hashtable() {
        size = _size;
        values = std::vector<Node*>(size);
        for (int i = 0; i < values.size(); i++) {
            values[i] = new Node();
        }
    };

    int getHash(int key) {
        return key % size;
    }




    void insert(int value) {

        int index = getHash(value);


        if (values[index]->status == 0) {
            values[index]->value = value;
            values[index]->status = 1;
            currentSize++;
        } else {
            int tempIndex = index;

            while (values[tempIndex]->status != 0) {
                tempIndex++;

                if (tempIndex >= size)
                    tempIndex %= size;

            }
            if (values[tempIndex]->status != 1) {
                values[tempIndex]->status = 1;
                values[tempIndex]->value = value;
                currentSize++;
            }
        }
    }

    Node* search(int value) {

        int index = getHash(value);

        while (values[index]->status != 0) {
            if (!values[index]->checked && values[index]->value == value)
                return values[index];

            index++;

            if (index >= size)
                index %= size;
        }

        return nullptr;
    }
};



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int count = 0;

    auto xHashTable = new Hashtable(N);
    auto yHashTable = new Hashtable(N);

    int * x = new int[N];
    int * y = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
        std::cin >> y[i];

        if (xHashTable->search(x[i]) || yHashTable->search(y[i]))
            continue;

        xHashTable->insert(x[i]);
        yHashTable->insert(y[i]);
        count++;

        if (count > 3)
            break;
    }

    if (count == 3)
        std::cout << "YES";
    else
        std::cout << "NO";

    delete [] x;
    delete [] y;
    delete xHashTable;
    delete yHashTable;
}