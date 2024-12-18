#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Enter number of pages: ";
        cin >> pages;
    }

    void putdata() override {
        Publication::putdata();
        cout << "Pages: " << pages << endl;
    }
};

class AudioBook : public Publication {
private:
    int recordingTime;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Enter recording time in minutes: ";
        cin >> recordingTime;
    }

    void putdata() override {
        Publication::putdata();
        cout << "Recording time: " << recordingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    book.getdata();
    cout << "Book data:" << endl;
    book.putdata();

    cout << endl;

    AudioBook audioBook;
    audioBook.getdata();
    cout << "Audio book data:" << endl;
    audioBook.putdata();

    return 0;
}
