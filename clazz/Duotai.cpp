// 多态
#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speaking() {
        cout << "Animal" << endl;
    }

    // 纯虚函数 类似Java中的抽象方法 拥有纯虚函数的类为抽象类 不能实例化
    // 子类必须重写该方法 否则子类也是抽象类
    virtual void behavior() = 0;

};

class Dog : public Animal {
public:
    void speaking() override {
        cout << "Dog" << endl;
    }

    void behavior() override{
        cout << "吃骨头" << endl;
    }
};

class Cat : public Animal {
public:
    void speaking() override {
        cout << "Cat" << endl;
    }

    void behavior() override{
        cout << "抓老鼠" << endl;
    }

};

void speaking(Animal &animal) {
    animal.speaking();
}

int main() {
    Cat cat;
    speaking(cat);
    Dog dog;
    speaking(dog);

    Animal *animal = new Cat();
    animal->speaking();
    animal->behavior();
    animal = new Dog();
    animal->speaking();
    animal->behavior();

}
