module AbstractBook;

import <iostream>;
import <string>;

using namespace std;

// AbstractBook Implementation
AbstractBook::AbstractBook();
AbstractBook::AbstractBook(std::string title);
AbstractBook::AbstractBook(std::string title, std::string author);
AbstractBook::AbstractBook(std::string title, std::string author, int pages);
AbstractBook::~AbstractBook();
AbstractBook::AbstractBook(const AbstractBook& other);
AbstractBook::AbstractBook(AbstractBook&& other);
AbstractBook& AbstractBook::operator=(const AbstractBook& other);
AbstractBook& AbstractBook::operator=(AbstractBook&& other);

// Book Implementation
Book::Book();
Book::Book(string title);
Book::Book(string title, string author);
Book::Book(string title, string author, int pages);
Book::~Book();
Book::Book(const Book& other);
Book::Book(Book&& other);
Book& Book::operator=(const Book& other);
Book& Book::operator=(Book&& other);

// Text Implementation
Text::Text();
Text::Text(string title, string subject);
Text::Text(string title, string author, string subject);
Text::Text(string title, string author, int pages, string subject);
Text::~Text();
Text::Text(const Text& other);
Text::Text(Text&& other);
Text& Text::operator=(const Text& other);
Text& Text::operator=(Text&& other);
