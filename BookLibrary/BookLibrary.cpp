#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

void AddBook(char**& books, int& amountOfBooks) {
    char** tempArr = new char* [amountOfBooks];
    for (int i = 0; i < amountOfBooks; i++) {
        tempArr[i] = new char[strlen(books[i]) + 1];
        strcpy(tempArr[i], books[i]);

        delete[] books[i];
    }

    delete[] books;

    amountOfBooks++;

    books = new char* [amountOfBooks];

    for (int i = 0; i < amountOfBooks - 1; i++) {
        books[i] = tempArr[i];
    }

    books[amountOfBooks - 1] = new char[12];

    cout << "Add new book: ";
    cin.getline(books[amountOfBooks - 1], 12);

    delete[] tempArr;
}

void PrintBooks(char** books, int amountOfBooks) {
    cout << "Books list:\n";
    for (int i = 0; i < amountOfBooks; i++) {
        cout << i + 1 << ". " << books[i] << endl;
    }
}

void RenameBook(char** books, int amountOfBooks) {
    int index;
    cout << "Enter the number of the book to rename (1-" << amountOfBooks << "): ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > amountOfBooks) {
        cout << "Invalid book number.\n";
        return;
    }

    cout << "Enter the new name: ";
    cin.getline(books[index - 1], 12);
}

void DeleteBook(char**& books, int& amountOfBooks) {
    int index;
    cout << "Enter the number of the book to delete (1-" << amountOfBooks << "): ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > amountOfBooks) {
        cout << "Invalid book number.\n";
        return;
    }

    delete[] books[index - 1];

    for (int i = index - 1; i < amountOfBooks - 1; i++) {
        books[i] = books[i + 1];
    }

    amountOfBooks--;
    char** tempArr = new char* [amountOfBooks];
    for (int i = 0; i < amountOfBooks; i++) {
        tempArr[i] = books[i];
    }

    delete[] books;
    books = tempArr;

    cout << "Book deleted successfully.\n";
}

int main() {
    int amountOfBooks = 4;
    char** books = new char* [amountOfBooks];

    for (int i = 0; i < amountOfBooks; i++) {
        books[i] = new char[12];
        cout << "Enter the name of book " << i + 1 << ": ";
        cin.getline(books[i], 12);
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Add a book\n2 - Rename book\n3 - Delete book\n";
        cout << "4 - Show all books\n5 - Exit application\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            AddBook(books, amountOfBooks);
            break;
        case 2:
            RenameBook(books, amountOfBooks);
            break;
        case 3:
            DeleteBook(books, amountOfBooks);
            break;
        case 4:
            PrintBooks(books, amountOfBooks);
            break;
        case 5:
            for (int i = 0; i < amountOfBooks; i++) {
                delete[] books[i];
            }
            delete[] books;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
