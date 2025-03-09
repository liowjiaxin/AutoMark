class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.borrowed = 0

    def __str__(self):
        if self.borrowed == 1:
            return f"{self.title} by {self.author} (ISBN: {self.isbn}) - Borrowed"
        else:
            return f"{self.title} by {self.author} (ISBN: {self.isbn}) - Available"


class Library:
    def __init__(self):
        self.books = []

    def add_book(self, title, author, isbn):
        new_book = Book(title, author, isbn)
        self.books.append(new_book)

    def borrow_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                if book.borrowed == 0:
                    book.borrowed = 1
                    return "Success"
                else:
                    return "Already borrowed"
        return "Not Found"

    def return_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                if book.borrowed == 1:
                    book.borrowed = 0
                    return "Success"
                else:
                    return "Not borrowed"
        return "Not Found"

    def list_available_books(self):
        available = []
        for book in self.books:
            if book.borrowed == 0:
                available.append(book)
        return available

    def list_borrowed_books(self):
        borrowed = []
        for book in self.books:
            if book.borrowed == 1:
                borrowed.append(book)
        return borrowed


# Example Usage (for testing):
def test_library():
    library = Library()
    library.add_book(
        "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803"
    )
    library.add_book("Pride and Prejudice", "Jane Austen", "978-0141439518")

    assert library.borrow_book("978-0345391803") == "Success"
    assert library.borrow_book("123-456-789") == "Not Found"
    assert library.borrow_book("978-0345391803") == "Already borrowed"

    assert library.return_book("978-0345391803") == "Success"
    assert library.return_book("123-456-789") == "Not Found"
    assert library.return_book("978-0345391803") == "Not borrowed"

    assert len(library.list_available_books()) == 2
    assert len(library.list_borrowed_books()) == 0

    library.borrow_book("978-0345391803")
    assert len(library.list_available_books()) == 1
    assert len(library.list_borrowed_books()) == 1
    print("Tests Passed!")


if __name__ == "__main__":
    test_library()
