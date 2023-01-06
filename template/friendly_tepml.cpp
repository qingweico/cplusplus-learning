#include <iostream>

using namespace std;

template<class T>
class Result;

template<class T>
void print(Result<T> &r) {
    cout << "{data : " << r.data << ", success : " << boolalpha << r.success << "}" << endl;
}

template<class T>
class Result {

    // 类内实现模板友元函数
    friend void print(Result<T> &r) {
        cout << "{data : " << r.data << ", success : " << boolalpha << r.success << "}" << endl;
    }

    // 类外实现模板友元函数
    friend void print<>(Result<T> &r);

private:
    T data;
    bool success{};

    Result(T data, bool success) {
        this->data = data;
        this->success = success;
    }

public:

    Result() = default;

    Result ok(T t) {

        return Result(t, true);
    }

};


int main() {
    Result<string> r{};
    r = r.ok("hhhh");
    print(r);
}
