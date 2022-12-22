#include <iostream>
#include <string>

using namespace std;

template<class T>
class Array {
private:
    T *base;
    int capacity = 0;
    int size = 0;
public:
    // 构造函数
    explicit Array(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->base = new T[capacity];
    }

    // 析构函数
    ~Array() {
        if (base != nullptr) {
            delete[] base;
            base = nullptr;
        }
    }

    // 拷贝构造
    Array(const Array &another) {
        // TODO 抽取重复代码
        this->capacity = another.capacity;
        this->size = another.size;
        this->base = new T[another.capacity];
        for (int i = 0; i < this->size; i++) {
            this->base[i] = another.base[i];
        }
    }

    // 赋值运算符重载
    Array &operator=(const Array &another) {
        // TODO 抽取重复代码 和 完善自我赋值
        if (base != nullptr) {
            delete[] base;
            base = nullptr;
        }
        this->capacity = another.capacity;
        this->size = another.size;
        this->base = new T[another.capacity];
        for (int i = 0; i < this->size; i++) {
            this->base[i] = another.base[i];
        }
        return *this;
    }

    void append(const T &val) {
        if (isFull()) {
            cout << "Array is Full!" << endl;
            return;
        }
        this->base[this->size++] = val;
    }

    bool isFull() {
        return this->size == this->capacity;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    int cap() {
        return this->capacity;
    }

    int len() {
        return this->size;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Array is Empty!" << endl;
            return;
        }
        this->size--;
    }

    T &operator[](int index) {
        return this->base[index];
    }
};


template<class T>
void print(Array<T> &array) {
    cout << "cap : " << array.cap() << endl;
    cout << "len : " << array.len() << endl;
    for (int i = 0; i < array.len(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    Array<int> array(3);
    array.append(2);
    array.append(9);
    array.append(5);
    array.pop();
    array.append(12);
    print<>(array);
    Array<int> a1(5);
    a1.append(11);
    a1.append(12);
    a1.append(13);
    a1.append(14);
    print<>(a1);
    a1 = array;
    print<>(a1);
}