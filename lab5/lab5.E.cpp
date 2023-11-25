/*
#include <iostream>
#include <vector>
#include <cmath>

class Data {
public:
    int value;
    int status; // 0 - пуст, 1 - занят, 2 - удален

    Data() {
        status = 0;
    }
    Data(int _value) : Data() {
        value = _value;
    }
};

class Hashtable {
public:
    int size;
    int currentSize;
    std::vector<Data> values;


    Hashtable() {
        currentSize = 0;
    }
    Hashtable(int _size) : Hashtable() {

        int rank = std::ceil(log2(_size));
        size = pow(2,rank);
        values.resize(size);
    }


    void insert(int value) {
        if (currentSize >= size)
            return;

        int index1 = getHash(value);
        int index2 = getHash2(value);
        int index = index1;
        if (values[index1].value == value ||
            values[index2].value == value)
            return;


        for (int i = 0; i < size; i++) {
            if (values[index].status == 0) {
                values[index].status = 1;
                values[index].value = value;
                currentSize++;
                return;
            }
            index = (index1 + i*index2) % size;
        }

    }

    int search(int value) {
        if (currentSize <= 0)
            return -1;

        int index1 = getHash(value);
        int index2 = getHash2(value);
        int index = index1;

        for (int i = 0; i < size; i++) {
            if (values[index].status != 0) {
                if (values[index].value == value)
                    return index;
            } else {
                return -1;
            }
            index = (index1 + i*index2) % size;
        }
        return -1;

    }


    void remove(int value) {
        if (currentSize <= 0)
            return;

        int key = search(value);
        if (key != -1) {
            values[key].status = 2;
            currentSize--;
        }

    }

    int getHash(int value) {
        return abs(value) % size;
//        return size * (std::abs(value) * 0,618 % 1);
    }
    int getHash2(int value) {
        return abs(value) % (size-1) + 1;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            if (values[i].status == 1)
                std::cout << i << ": " <<  values[i].value << " ";
        }
    }
};



int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Hashtable * hashtable = new Hashtable(n);

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        hashtable->insert(value);
    }
    bool isEqual = true;
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        if (hashtable->search(value) == -1) {
            isEqual = false;
//            break;
        }
    }

    if (isEqual)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

//    hashtable->insert(1);
//    hashtable->insert(1);
//    hashtable->insert(1);
//    hashtable->remove(3);
//
//    std::cout << hashtable->search(2, 0) << "\n";
//    std::cout << hashtable->search(3, 0) << "\n";
//    std::cout << hashtable->search(1, 0) << "\n";


//    hashtable->print();


    delete hashtable;

    return 0;
}
*/

/*#include <iostream>
#include <vector>

class Data {
public:
    int value;
    int status; // 0 - пуст, 1 - занят, 2 - удален

    Data() {
        status = 0;
    }
    Data(int _value) : Data() {
        value = _value;
    }
};

class Hashtable {
public:
    int size;
    int currentSize;
    std::vector<Data> values;


    Hashtable() {
        currentSize = 0;
    }
    Hashtable(int _size) : Hashtable() {
        size = _size;
        values.resize(_size);
    }


    void insert(int value) {
        if (currentSize >= size)
            return;

        int index = getHash(value);

        if (values[index].value == value)
            return;

        if (values[index].status == 0) {
            values[index].value = value;
            values[index].status = 1;
            currentSize++;
        } else {
            int tempIndex = index;

            while (values[tempIndex].status != 0) {
                tempIndex++;

                if (tempIndex >= size)
                    tempIndex %= size;

            }
            if (values[tempIndex].status != 1) {
                values[tempIndex].status = 1;
                values[tempIndex].value = value;
                currentSize++;
            }
        }
    }

    int search(int value) {
        if (currentSize <= 0)
            return -1;

        int index = getHash(value);
        int tempIndex = index;

        while (values[tempIndex].status != 0) {
            if (values[tempIndex].status == 1 &&
                values[tempIndex].value == value) {
                return tempIndex;
            }

            tempIndex++;

            if (tempIndex >= size)
                tempIndex %= size;
        }

        return -1;

    }


    void remove(int value) {
        if (currentSize <= 0)
            return;

        int key = search(value);
        if (key != -1) {
            values[key].status = 2;
            currentSize--;
        }

    }

    int getHash(int value) {
//        return size * (std::abs(value) * 0,618 % 1);
        return abs(value) % size;
    }
    int getIndex(int index, int step) {
        return (index + step) % size;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            if (values[i].status == 1)
                std::cout << i << ": " <<  values[i].value << " ";
        }
    }
};



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Hashtable * hashtable = new Hashtable(1000000);

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        hashtable->insert(value);
    }
    bool isEqual = true;
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        if (hashtable->search(value) == -1) {
            isEqual = false;
            break;
        }
    }

    if (isEqual)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

//    hashtable->insert(1);
//    hashtable->insert(1);
//    hashtable->insert(1);
//    hashtable->remove(3);
//
//    std::cout << hashtable->search(2, 0) << "\n";
//    std::cout << hashtable->search(3, 0) << "\n";
//    std::cout << hashtable->search(1, 0) << "\n";


//    hashtable->print();


    delete hashtable;

    return 0;
}*/
