#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    virtual void getData() {
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    virtual void putData() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

class Sales {
protected:
    float salesData[3];

public:
    void getData() {
        std::cout << "Enter sales data for the last 3 months:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "Month " << i + 1 << ": ";
            std::cin >> salesData[i];
        }
    }

    void putData() {
        std::cout << "Sales data for the last 3 months:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "Month " << i + 1 << ": " << salesData[i] << std::endl;
        }
    }
};

class Book : public Publication, public Sales {
protected:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
        Sales::getData();
    }

    void putData() {
        Publication::putData();
        std::cout << "Page count: " << pageCount << std::endl;
        Sales::putData();
    }
};

class Type : public Publication, public Sales {
protected:
    int recordingTime;

public:
    void getData() {
        Publication::getData();
        std::cout << "Enter recording time (minutes): ";
        std::cin >> recordingTime;
        Sales::getData();
    }

    void putData() {
        Publication::putData();
        std::cout << "Recording time: " << recordingTime << " minutes" << std::endl;
        Sales::putData();
    }
};

int main() {
    Book book;
    Type type;

    std::cout << "Enter data for a book:" << std::endl;
    book.getData();
    std::cout << "\nBook details:" << std::endl;
    book.putData();

    std::cout << "\nEnter data for an audio book:" << std::endl;
    type.getData();
    std::cout << "\nAudio book details:" << std::endl;
    type.putData();

    return 0;
}
