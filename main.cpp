#include<iostream>
using namespace std;
const int MAX_Books = 10;
const int MAX_Users = 10;

struct Book {
    int ID{};
    string name{};
    int quantity{};
};

struct User {
    int ID{};
    string name{};
};

User user_name[MAX_Users];
User user_ID[MAX_Users];
Book book_ID[MAX_Books];
Book book_name[MAX_Books];
Book book_quantity[MAX_Books];
int user_count = 0;
int book_count = 0;

int menu() {
    int o = 1;
    while (o--) {
        cout << "Library Menu:\n";
        cout << "1) Add Book\n";
        cout << "2) Search Books by prefix\n";
        cout << "3) Print who borrowed book by name\n";
        cout << "4) Print Library by ID\n";
        cout << "5) Print Library by name\n";
        cout << "6) Add Users\n";
        cout << "7) User borrowing a book\n";
        cout << "8) User returning a book\n";
        cout << "9) Print Users\n";
        cout << "10) Exit\n" << endl;
        cout << "Enter your choice [1 - 10] : \n";
        int choice{};
        cin >> choice;
        if (choice < 1 || choice > 10) {
            cout << "Invalid Choice\n";
            o++;
            continue;
        }
        return choice;
    }
}

void Add_Book() {
    if (book_count == MAX_Books) {
        cout << "Can't add more books. Maximum capacity reached.\n";
        return;
    }
    cout << "Enter book info: ID & name & quantity:";
    cin >> book_ID[book_count].ID >> book_name[book_count].name >> book_quantity[book_count].quantity;
    cout << "Book added successfully\n";
    book_count++;
}

string prefix_Search_Book(int index, string prefix, int &count) {
    if (index == book_count) {
        if (count == 0)
            cout << "No books found.\n";
        return "";
    }

    bool match = true;
    for (int i = 0; i < prefix.size(); i++) {
        if (i >= book_name[index].name.size() || book_name[index].name[i] != prefix[i]) {
            match = false;
            break;
        }
    }
    if (match) {
        cout << "Book ID: " << book_ID[index].ID << ", Name: " << book_name[index].name
                << ", Quantity: " << book_quantity[index].quantity << endl;
        count++;
    }
    return prefix_Search_Book(index + 1, prefix, count);
}

void Search_Book() {
    cout << "Enter book name prefix";
    string prefix{};
    cin >> prefix;
    int size = prefix.size();
    int count = 0;
    prefix_Search_Book(0, prefix, count);
    /*for (int i = 0; i < book_count; i++) {
        bool match = true;
        for (int j = 0; j < prefix.size(); j++) {
            if (i >= book_name[i].name.size() || book_name[i].name[j] != prefix[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "Book ID: " << book_ID[i].ID << ", Name: " << book_name[i].name
                    << ", Quantity: " << book_quantity[i].quantity << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "No books found.\n";*/
}

void Print_who_borrowed_book() {
    cout << "Enter book name";
    string name{};
    cin >> name;
}

void Print_library_by_ID() {
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - i - 1; j++) {
            if (book_ID[j].ID > book_ID[j + 1].ID) {
                int temp_ID = book_ID[j].ID;
                book_ID[j].ID = book_ID[j + 1].ID;
                book_ID[j + 1].ID = temp_ID;

                string temp_name = book_name[j].name;
                book_name[j].name = book_name[j + 1].name;
                book_name[j + 1].name = temp_name;

                int temp_quantity = book_quantity[j].quantity;
                book_quantity[j].quantity = book_quantity[j + 1].quantity;
                book_quantity[j + 1].quantity = temp_quantity;
            }
        }
    }
    for (int i = 0; i < book_count; i++) {
        cout << "Book ID: " << book_ID[i].ID << ", " << "Book name: " << book_name[i].name << ", "
                << "Total quantity: " << book_quantity[i].quantity << endl;
    }
}

void Print_library_by_name() {
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - i - 1; j++) {
            if (book_name[j].name > book_name[j + 1].name) {
                int temp_ID = book_ID[j].ID;
                book_ID[j].ID = book_ID[j + 1].ID;
                book_ID[j + 1].ID = temp_ID;

                string temp_name = book_name[j].name;
                book_name[j].name = book_name[j + 1].name;
                book_name[j + 1].name = temp_name;

                int temp_quantity = book_quantity[j].quantity;
                book_quantity[j].quantity = book_quantity[j + 1].quantity;
                book_quantity[j + 1].quantity = temp_quantity;
            }
        }
    }
    for (int i = 0; i < book_count; i++) {
        cout << "Book name: " << book_name[i].name << ", " << "Book ID: " << book_ID[i].ID << ", "
                << "Total quantity: " << book_quantity[i].quantity << endl;
    }
}

void Add_Users() {
    if (user_count == MAX_Users) {
        cout << "Can't add more users. Maximum capacity reached.\n";
        return;
    }
    cout << "Enter user name and ID: ";
    cin >> user_name[user_count].name >> user_name[user_count].ID;
    cout << "User added successfully\n";
    user_count++;
}

void User_borrowing() {
    string User_Name{};
    string Book_Name{};
    cout << "Enter user name & book name: ";
    cin >> User_Name >> Book_Name;
    bool found_book = false;
    bool found_user = false;
    int user_index{};
    int book_index{};
    for (int i = 0; i < user_count; i++) {
        if (user_name[i].name == User_Name) {
            found_user = true;
            user_index = i;
            break;
        }
    }
    for (int i = 0; i < book_count; i++) {
        if (book_name[i].name == Book_Name) {
            found_book = true;
            book_index = i;
            break;
        }
    }

    if (!found_user || !found_book) {
        cout << "User with this name does not exist.\n";
    } else {
    }
}

void User_returning() {
    int User_ID{};
    cout << "Enter user ID & book name: ";
    cin >> User_ID;
    bool found = false;
    for (int i = 0; i < user_count; i++) {
        if (user_name[i].ID == User_ID) {
            found = true;

            break;
        }
    }
    if (!found) {
        cout << "User with this ID does not exist.\n";
    }
}

void Print_users() {
    for (int i = 0; i < user_count; i++) {
        cout << "User ID: " << user_ID[i].ID << "User name: " << user_name[i].name << endl;
    }
}

void Library_System() {
    while (true) {
        int choice{menu()};
        switch (choice) {
            case 1:
                Add_Book();
                break;
            case 2:
                Search_Book();
                break;
            case 3:
                Print_who_borrowed_book();
                break;
            case 4:
                Print_library_by_ID();
                break;
            case 5:
                Print_library_by_name();
                break;
            case 6:
                Add_Users();
                break;
            case 7:
                User_borrowing();
                break;
            case 8:
                User_returning();
                break;
            case 9:
                Print_users();
                break;
            case 10:
                cout << "Bye bye.\n";
                return;
        }
    }
}

int main() {
    Library_System();
    return 0;
}
