class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.borrowed = False

    def __str__(self):
        return f"{self.title} by {self.author} (ISBN: {self.isbn}) - {'Borrowed' if self.borrowed else 'Available'}"


class Library:
    def __init__(self):
        self.books = []

    def add_book(self, title, author, isbn):
        self.books.append(Book(title, author, isbn))

    def borrow_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                if not book.borrowed:
                    book.borrowed = True
                    return True
                else:
                    return False  # Book already borrowed
        return None  # Book not found

    def return_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                if book.borrowed:
                    book.borrowed = False
                    return True
                else:
                    return False  # Book not borrowed
        return None  # Book not found

    def list_available_books(self):
        return [book for book in self.books if not book.borrowed]

    def list_borrowed_books(self):
        return [book for book in self.books if book.borrowed]


# Example Usage (for testing):
def test_library():
    library = Library()
    library.add_book(
        "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803"
    )
    library.add_book("Pride and Prejudice", "Jane Austen", "978-0141439518")

    assert library.borrow_book("978-0345391803") == True
    assert library.borrow_book("123-456-789") == None
    assert library.borrow_book("978-0345391803") == False

    assert library.return_book("978-0345391803") == True
    assert library.return_book("123-456-789") == None
    assert library.return_book("978-0345391803") == False

    assert len(library.list_available_books()) == 2
    assert len(library.list_borrowed_books()) == 0

    library.borrow_book("978-0345391803")
    assert len(library.list_available_books()) == 1
    assert len(library.list_borrowed_books()) == 1
    print("Tests Passed!")


if __name__ == "__main__":
    test_library()
