module AbstractBook;

import <iostream>;
import <string>;

using namespace std;

// AbstractBook Implementation
AbstractBook::AbstractBook() : title{""}, author{""}, pages(0) {}
AbstractBook::AbstractBook(std::string title) : AbstractBook() { // ctor delegation
    this->title = title;
}
AbstractBook::AbstractBook(std::string title, std::string author) : AbstractBook(title) {
    this->author = author;
}
AbstractBook::AbstractBook(std::string title, std::string author, int pages) : AbstractBook(title, author) {
    this->pages = pages;
}
AbstractBook::~AbstractBook() {}
AbstractBook::AbstractBook(const AbstractBook& other) : title{other.title}, author{other.author}, pages{other.pages} {}
// move ctor, using std::move
AbstractBook::AbstractBook(AbstractBook&& other) : title{move(other.title)}, author{move(other.author)}, pages{move(other.pages)} {}
AbstractBook& AbstractBook::operator=(const AbstractBook& other) {
    if (this == &other) return *this;
    title = other.title;
    author = other.author;
    pages = other.pages;
    return *this;
}
AbstractBook& AbstractBook::operator=(AbstractBook&& other) { // recall: move CCTOR MUST MOVE THE FIELD BY USEING STD:;MOVE
    if (this == &other) return *this;
    title = std::move(other.title);
    author = move(other.author);
    pages = move(other.pages);
    return *this;
}

// Book Implementation
Book::Book() : AbstractBook() {} // call abstact book cotr, no additional fields
Book::Book(string title) : AbstractBook(title) {}
Book::Book(string title, string author) : AbstractBook(title, author) {}
Book::Book(string title, string author, int pages) : AbstractBook(title, author, pages) {}
Book::~Book() {}
Book::Book(const Book& other) : AbstractBook(other) { // no additional fields
}
Book::Book(Book&& other) : AbstractBook(other) {}
Book& Book::operator=(const Book& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(other); // invoke AbstractBook copy asst in their protected domain
    return *this;
}
Book& Book::operator=(Book&& other) {
    if (this == &other) return *this; // check for self
    AbstractBook::operator=(move(other)); // AbstractBook move ctor
    return *this;
}

// Text Implementation
Text::Text() : AbstractBook(), subject{""} {}
Text::Text(string title, string subject) : AbstractBook(title), subject{subject} {} // This is not constructor delegation since we are not using our own ctor so we can still keep additional fields in the MIL
Text::Text(string title, string author, string subject) : AbstractBook(title, author), subject{subject} {}
Text::Text(string title, string author, int pages, string subject) : AbstractBook(title, author, pages), subject{subject} {}
Text::~Text() {}
Text::Text(const Text& other) : AbstractBook(other), subject{other.subject} {}
Text::Text(Text&& other) : AbstractBook(move(other)), subject{move(other.subject)} {}
Text& Text::operator=(const Text& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(other); // copy over existing fields, calling AbstractBookcopy asst
    subject = other.subject; // copy over assitional fields
    return *this;
}
Text& Text::operator=(Text&& other) {
    if (this == &other) return *this;
    AbstractBook::operator=(move(other)); // move asst over using AbstractBook class move asst
    subject = move(other.subject); // copy over additional fields of text
    return *this;
}
