#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

class Base {
public:
    Base() { std::cout << "Base created." << std::endl; }
    virtual void Show() const {
        std::cout << "This is Base." << std::endl;
    }
    virtual ~Base() { std::cout << "Base destroyed." << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived created." << std::endl; }
    void Show() const override {
        std::cout << "This is Derived." << std::endl;
    }
    ~Derived() { std::cout << "Derived destroyed." << std::endl; }
};

void add(std::vector<std::shared_ptr<Base>>& storage, Base* item) {
    storage.push_back(std::shared_ptr<Base>(item));
}

int main() {
    std::vector<std::shared_ptr<Base>> storage;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Инициализация генератора случайных чисел

    for (int i = 0; i < 10; ++i) {
        if (std::rand() % 2 == 0) {
            add(storage, new Base());
        } else {
            add(storage, new Derived());
        }
    }

    for (const auto& obj : storage) {
        obj->Show();
    }

    return 0;
}
