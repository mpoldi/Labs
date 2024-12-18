#include <iostream>
#include <vector>
#include <memory>

class Part {
protected:
    Part() { std::cout << "Part created." << std::endl; }
public:
    virtual void Show() const = 0; // Чисто виртуальная функция
    virtual ~Part() { std::cout << "Part destroyed." << std::endl; }
};

class Assembly : public Part {
protected:
    Assembly() { std::cout << "Assembly created." << std::endl; }
public:
    void Show() const override {
        std::cout << "This is an Assembly." << std::endl;
    }
    ~Assembly() { std::cout << "Assembly destroyed." << std::endl; }
};

template <typename T>
void add(std::vector<std::shared_ptr<Part>>& storage, T* item) {
    storage.push_back(std::shared_ptr<Part>(item));
}

int main() {
    std::vector<std::shared_ptr<Part>> storage;

    add(storage, new Assembly());
    add(storage, new Assembly());

    for (const auto& part : storage) {
        part->Show();
    }

    return 0;
}
