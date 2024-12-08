module AbstractBook;

import <iostream>;
import <string>;

using namespace std;

// AbstractBook Implementation
AbstractBook::AbstractBook() : title{""}, author{""}, pages(0) {}
AbstractBook::AbstractBook(std::string title) : AbstractBook() { // ctor delegation
    title{title};
}
AbstractBook::AbstractBook(std::string title, std::string author) : AbstractBook(title) {
    author{author};
}
AbstractBook::AbstractBook(std::string title, std::string author, int pages) : AbstractBook(title, author) {
    pages{pages};
}
AbstractBook::~AbstractBook() {}
AbstractBook::AbstractBook(const AbstractBook& other) : title{other.title}, author{other.author}, pages{other.pages} {}
AbstractBook::AbstractBook(AbstractBook&& other) : title{other.title}, author{other.author}, pages{other.pages} {}
AbstractBook& AbstractBook::operator=(const AbstractBook& other) {
    if (this == &other) return *this;
    title = other.title;
    author = other.author;
    pages = other.pages;
    other.title = "";
    other.author = "";
    other.pages = 0;
    return *this;
}
AbstractBook& AbstractBook::operator=(AbstractBook&& other) {
    if (this == &other) return *this;
    title = other.title;
    author = other.author;
    pages = other.pages;
    other.title = "";
    other.author = "";
    other.pages = 0;
    return *this;
}

// Book Implementation
Book::Book() : AbstractBook::AbstractBook() {} // call abstact book cotr, no additional fields
Book::Book(string title) : AbstractBook::AbstractBook(title) {}
Book::Book(string title, string author) : AbstractBook::AbstractBook(title, author) {}
Book::Book(string title, string author, int pages) : AbstractBook::AbstractBook(title, author, pages) {}
Book::~Book() {}
Book::Book(const Book& other) : AbstractBook::AbstractBook(other) { // no additional fields
}
Book::Book(Book&& other) : AbstractBook::AbstractBook(other) {}
Book& Book::operator=(const Book& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(other); // invoke AbstractBook copy asst
    return *this;
}
Book& Book::operator=(Book&& other) {
    if (this == &other) return *this; // check for self
    AbstractBook::operator=(other); // AbstractBook move ctor
    return *this;
}

// Text Implementation
Text::Text() : title{""}, author{""}, pages{0}, subject{""} {}
Text::Text(string title, string subject) : AbstractBook::AbstractBook(title), subject{subject} {} // This is not constructor delegation since we are not using our own ctor so we can still keep additional fields in the MIL
Text::Text(string title, string author, string subject) : AbstractBook::AbstractBook(title, author), subject{subject} {}
Text::Text(string title, string author, int pages, string subject) : AbstractBook::AbstractBook(title, author, pages), subject{subject} {}
Text::~Text() {}
Text::Text(const Text& other) : AbstractBook::AbstractBook(other), subject{other.subject} {}
Text::Text(Text&& other) : AbstractBook::AbstractBook(other), subject{other.subject} {}
Text& Text::operator=(const Text& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(other); // copy over existing fields, calling AbstractBookcopy asst
    subject = other.subject; // copy over assitional fields
    return *this;
}
Text& Text::operator=(Text&& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(other); // move asst over using AbstractBook class move asst
    subject = other.subject; // copy over additional fields of text
    return *this;
}
