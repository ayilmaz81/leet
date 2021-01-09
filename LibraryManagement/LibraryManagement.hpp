#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <queue>

using std::queue;
using std::string;
using std::vector;
using std::chrono::time_point;

enum BookStatus
{
    BARROWED,
    RESERVED,
    AVAILABLE
};

struct MemberCard
{
    string barcode;
};
struct Account
{
    MemberCard card;
};

struct ReturnReceipt
{
    int fine;
    time_point<std::chrono::system_clock> returnDate;
};

struct Member : public Account
{
    int reserveCounter;
};

struct Librarian : public Account
{
};

struct Book;

struct BookItem
{
    bool checkedOut;
    time_point<std::chrono::system_clock> dueData;
    Book *book;
    bool available;
};

struct Book
{
    string author;
    string date;
    string title;
    string subject;
    string id;
    string rack;

    vector<BookItem> items;
    queue<Member> reserveQueue;
};

struct Library
{
    vector<Book> books;
    vector<Librarian> librarians;
    vector<Member> members;
};

struct Portal
{
    vector<Book> search();
    BookItem checkOut(string &barcodeImte, MemberCard &card, time_point<std::chrono::system_clock> time);
    ReturnReceipt checkin(string &barcodeItem, MemberCard &card, time_point<std::chrono::system_clock> time);
    bool payFine(ReturnReceipt &receipt);
};

struct MemberPortal : public Portal
{
    BookItem reserve(Book &book, Member &member, time_point<std::chrono::system_clock> time);
};
struct LibrarianPortal : public Portal
{
    vector<BookItem> getBooksByMember(Member &member);
    Book getBookInformation(string &barcode);
    BookItem addBook();
    BookItem removeBook();
};


struct System
{
    void scanDueBooks();
};