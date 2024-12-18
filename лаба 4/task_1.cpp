#include <iostream>
#include <stdexcept>

class Error {
public:
    virtual void Print() const = 0; // Чисто виртуальная функция
    virtual ~Error() {} // Виртуальный деструктор
};

class MemoryAccessError : public Error {
public:
    void Print() const override {
        std::cout << "Memory access error!" << std::endl;
    }
};

class MathError : public Error {
public:
    void Print() const override {
        std::cout << "A mathematical error!" << std::endl;
    }
};

class DivisionByZeroError : public MathError {
public:
    void Print() const override {
        std::cout << "Error: division by zero!" << std::endl;
    }
};

class OverflowError : public MathError {
public:
    void Print() const override {
        std::cout << "Error: overflow!" << std::endl;
    }
};

// Новый класс для обработки ошибок выполнения
class RuntimeError : public std::runtime_error {
public:
    RuntimeError(const std::string& message) : std::runtime_error(message) {}
};

template <class T>
class CCollectionOfPointers {
private:
    T** m_arr;
    int m_cnt;
public:
    CCollectionOfPointers(int Count) : m_cnt(Count) {
        m_arr = new T * [m_cnt];
        for (int i = 0; i < m_cnt; i++) {
            m_arr[i] = nullptr; // Инициализация указателей
        }
    }

    ~CCollectionOfPointers() {
        for (int i = 0; i < m_cnt; i++) {
            delete m_arr[i]; // Освобождение памяти для объектов
        }
        delete[] m_arr; // Освобождение памяти для массива указателей
    }

    T* operator[](int n) const {
        if (n < 0 || n >= m_cnt) throw std::out_of_range("The index is out of range!");
        return m_arr[n];
    }

    T*& operator[](int n) {
        if (n < 0 || n >= m_cnt) throw std::out_of_range("The index is out of range!");
        return m_arr[n];
    }
};

int main() {
    try {
        CCollectionOfPointers<Error> errorList(5);

        errorList[0] = new MemoryAccessError();
        errorList[1] = new DivisionByZeroError();
        errorList[2] = new OverflowError();

        // Пример выбрасывания исключения runtime_error
        throw RuntimeError("An execution error has occurred!");

        // Выводим сообщения об ошибках
        for (int i = 0; i < 3; i++) {
            if (errorList[i] != nullptr) {
                errorList[i]->Print();
            }
        }

    }
    catch (const RuntimeError& e) {
        std::cerr << "RuntimeError exception: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "A common mistake: " << e.what() << std::endl;
    }

    return 0;
}
