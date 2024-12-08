// FULL implementation of Book, Text, Comic with big 5 and inheritance
export module AbstractBook;

import <iostream>;
import <string>;

using namespace std;

/*
Partial Assignment: kind of like object slicing except it's invoked when copy asst/move asst is called. The compiler will call the superclass (book)
coppy assignmtne,t thus only partially or mixedly copying the fields over. 
*/ 

/*
Note: Partial Assignment only occurs for copy assignment operators and move assignment operators, and not copy constructors or move constructors
THis is because the compiler is smart enough to call the subclass ctor when making a new object, that is trivial.
But when copying into an existing object, it for some reason will call the superclass class
*/

export class AbstractBook {
    std::string title;
    std::string author;
    int pages;
    public:
        // various ctors
        AbstractBook();
        explicit AbstractBook(std::string title);
        AbstractBook(std::string title, std::string author);
        AbstractBook(std::string title, std::string author, int pages);
        // virtual dtor for abstract class
        virtual ~AbstractBook() = 0;
        // copy and move ctor not affected by partial/mixed asst
        AbstractBook(const AbstractBook& other);
        AbstractBook(AbstractBook&& other);
    protected:
        // copy asst in # for preventing partial/mixed assignment
        AbstractBook& operator=(const AbstractBook& other);
        AbstractBook& operator=(AbstractBook&& other);
};

// Book, comic, and text all inherit from AbstractBook

class Book : public AbstractBook {
    public:
        // various ctors
        Book();
        explicit Book(string title);
        Book(string title, string author);
        Book(string title, string author, int pages);
        // dtor not virtual? idk
        ~Book();
        // copy move ctor for Book
        Book(const Book& other);
        Book(Book&& other);
        // copy move asst for Book (in public)
        Book& operator=(const Book& other);
        Book& operator=(Book&& other);
};

class Text : public AbstractBook {
    string subject;
        // various ctors
        Text();
        Text(string title, string subject);
        Text(string title, string author, string subject);
        Text(string title, string author, int pages, string subject);
        // dtor not virtual? idk
        ~Text();
        // copy move ctor for Book
        Text(const Text& other);
        Text(Text&& other);
        // copy move asst for Book (in public)
        Text& operator=(const Text& other);
        Text& operator=(Text&& other);
};