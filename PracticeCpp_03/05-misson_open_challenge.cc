/*
    Copyright 2018 Moreal
*/

#include <iostream>
#include <string>
#include <memory>

enum PRODUCT_TYPES { BOOK = 1,  MUSICCD = 2, CONVERSATIONBOOK = 3 };
enum COMMANDS { ADD_PRODUCT = 1, VIEW_ALL_PRODUCTS = 2, EXIT = 3 };

inline void getline(std::istream& cin, std::string& s) {
    char c = cin.get();
    std::getline(cin, s);
    if (c != '\n') s = c + s;
}

class Product {
    int uid, price;
    std::string description, maker;
 public:
    Product() {
        static int id = 0;
        uid = id++;
        std::cout << "Description >> ";
        getline(std::cin, description);
        std::cout << "Maker >> ";
        getline(std::cin, maker);
        std::cout << "Price >> ";
        std::cin >> price;
    }

    virtual void show();

    int getId() const { return uid; }
    int getPrice() const { return price; }
    std::string getDescription() const { return description; }
    std::string getMaker() const { return maker; }
};

class Book : Product {
    int isbn;
    std::string author, title;

 public:
    Book() {
        std::cout << "ISBN >> ";
        std::cin >> isbn;
        std::cout << "Author >> ";
        getline(std::cin, author);
        std::cout << "Title >> ";
        getline(std::cin, title);
    }

    virtual void show();
};

class ConversationBook : Book {
    std::string language;

 public:
    ConversationBook() {
        std::cout << "Language >> ";
        getline(std::cin, language);
    }
    void show() override;
};

class CompactDisc : Product {
    std::string title, singer;

 public:
    CompactDisc() {
        std::cout << "Album title >> ";
        getline(std::cin, title);
        std::cout << "Singer >> ";
        getline(std::cin, singer);
    }

    void show() override;
};

class ProductManager {
    int top = -1;
    Product* products[100];
 public:
    bool addProduct(Product*);
    bool canAddProduct() { return top < 99; }
    bool show();
};

void Product::show() {
    std::cout
        << "---- Product ID : " << uid << '\n'
        << "Description : " << description << '\n'
        << "Maker : " << maker << '\n'
        << "Price : " << price << '\n';
}

void Book::show() {
    Product::show();
    std::cout
        << "Book Title : " << title << '\n'
        << "Author : " << author << '\n'
        << "ISBN : " << isbn << '\n';
}

void ConversationBook::show() {
    Book::show();
    std::cout << "Language : " << language << '\n';
}

void CompactDisc::show() {
    Product::show();
    std::cout
        << "Album Title : " << title << '\n'
        << "Singer : " << singer << '\n';
}

bool ProductManager::addProduct(Product* product) {
    if (top == 99)
        return false;

    products[++top] = product;

    return true;
}

bool ProductManager::show() {
    if (top == -1)
        return false;

    for (int i(0); i <= top; ++i) {
        products[i]->show();
    }

    return true;
}

void handleUI(ProductManager& manager) {
    int cmd;
    std::cout << "Add Product(1) / View All Products(2) / Exit(3) ? ";
    std::cin >> cmd;

    switch (cmd) {
    case ADD_PRODUCT:
        std::cout << "Book(1) / MusicCD(2) / ConversationBook(3) ? ";
        std::cin >> cmd;

        switch (cmd) {
        case BOOK:
            manager.addProduct(reinterpret_cast<Product*>(new Book));
            break;

        case MUSICCD:
            manager.addProduct(reinterpret_cast<Product*>(new CompactDisc));
            break;

        case CONVERSATIONBOOK:
            manager.addProduct(
                reinterpret_cast<Product*>(new ConversationBook));
            break;

        default:
            std::cout << "Wrong Input..\n";
            exit(0);
        }

        break;

    case VIEW_ALL_PRODUCTS:
        manager.show();
        break;

    case EXIT:
        exit(0);
        break;

    default:
        std::cout << "Wrong Input..\n";
        exit(0);
    }
}

int main() {
    ProductManager manager;

    while (manager.canAddProduct()) {
        handleUI(manager);
    }
}
