#include <iostream>
#include <cstring> // Use cstring instead of string.h
#include <cstdlib> // Use cstdlib instead of stdlib.h

using namespace std;

class book {
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book() {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }

    ~book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
        delete price;
        delete stock;
    }

    void feeddata();
    void editdata();
    void showdata();
    int search(const char[], const char[]);
    void buybook();
};

void book::feeddata() {
    cin.ignore();
    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;
}

void book::editdata() {
    cin.ignore();
    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;
}

void book::showdata() {
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock Position: " << *stock;
}

int book::search(const char tbuy[20], const char abuy[20]) {
    return (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0);
}

void book::buybook() {
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;
    if (count <= *stock) {
        *stock -= count;
        cout << "\nBooks Bought Successfully";
        cout << "\nAmount: Rs. " << (*price) * count;
    } else {
        cout << "\nRequired Copies not in Stock";
    }
}

int main() {
    book *B[20];
    int i = 0, t, choice;
    char titlebuy[20], authorbuy[20];
    while (1) {
        cout << "\n\n\t\tMENU"
             << "\n1. Entry of New Book"
             << "\n2. Buy Book"
             << "\n3. Search For Book"
             << "\n4. Edit Details Of Book"
             << "\n5. Exit"
             << "\n\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            B[i] = new book;
            B[i]->feeddata();
            i++;
            break;

        case 2:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    B[t]->buybook();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 3:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->showdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 4:
            cin.ignore();
            cout << "\nEnter Title Of Book: ";
            cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";
            cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->editdata();
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;

        case 5:
            for (int j = 0; j < i; j++) {
                delete B[j];
            }
            exit(0);

        default:
            cout << "\nInvalid Choice Entered";
        }
    }
    return 0;
}
