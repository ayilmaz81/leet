#pragma once
#include <vector>
#include <string>

using namespace std;
struct Category {
    string name;
    vector<Category> subCategories;
};

enum Rating {
    ONE,
    TWO,
    THREE
};
enum OrderStatus {
    TAKEN,
    PREPARED,
    CANCELLED,
    SHIPPED,
    DELIVERED
};
struct Account {

};
struct Address {
    string name;
    string street;
};
struct User :public Account {
    string name;
    vector<Address> addresses;
};

struct Guest {

};

struct Review {
    string comment;
    string title;
    User reviewer;
    Rating rating;
};


struct Product {
    Category category;
    string name;

    vector<Review> reviews;
};


struct Catalog {
    vector<Product> searchByCategory(Category cat);
    vector<Product> searchByName(string name);


    vector<Product> products;

};


struct CartItem :public Product {
    int count;
};
struct OrderItem :public Product {
    OrderStatus status;
};
struct Order {
    User user;
    vector<OrderItem> items;
    Address shippingAdress;
    void cancelOrderItem(OrderItem& item);
};

struct Payment {
    virtual void withdraw(int amount);
};

struct BankTransferPayment :public Payment {
    string holderName;
    string sortcode;
    string number;

    virtual void withdraw(int amount);
};
struct CreditCardPayment :public Payment {
    string holderName;
    string number;
    virtual void withdraw(int amount);
};

struct ShoppingCart {
    vector<CartItem> items;
    int price;

    void addProduct(Product product, int count);
    void removeProduct(Product product, int count);
    Order placeOrder(Address address, Payment payment);
};

struct System {
    vector<Order> orders;
    //Changes order status
    void scanOrders();
};

struct Admin :public Account {

};

struct AdminPortal {
    Admin login();
    void logout();

    void addCategory(Category& cat);
    void removeCategory(Category& cat);
    void removeUser(User user);
};

struct Shopping {
    vector<User> users;
    Catalog catalog;
    void login(User user);
    void logout();
};