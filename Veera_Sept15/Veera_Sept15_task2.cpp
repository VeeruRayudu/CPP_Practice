#include<iostream>
#include<string>
#include<iomanip>

enum Genre {FICTION, NON_FICTION, SCIENCE, HISTORY, TECHNOLOGY};

std::string genreToString(Genre g){
    switch(g){
        case FICTION: return "Fiction";
        case NON_FICTION: return "Non-Fiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case TECHNOLOGY: return "Technology";
    }
}

class Book{
    private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;
    bool isReferenceOnly;
    std::string title;
    Genre genre;

    public:

    Book(): bookID(0), rating(0.0), price(0.0), availabilityStatus('A'), isReferenceOnly(false), title("Untitled"), genre(FICTION){}
    
    Book(int bID, float _rating, double _price, char availStatus, bool isRefOnly, std::string _title, Genre g): bookID(bID), rating(_rating), price(_price), availabilityStatus(availStatus), isReferenceOnly(isRefOnly), title(_title), genre(g) {}

    ~Book(){
        std::cout<<"Book Object with ID "<<bookID<<" destroyed.\n";
    }

    int getBookID()const {
        return bookID;
    }
    float getRating()const{
        return rating;
    }
    double getPrice()const {
        return price;
    }
    char getAvailabilityStatus() const {
        return availabilityStatus;
    }
    bool getIsReferenceOnly() const {
        return isReferenceOnly;
    }
    std::string getTitle() const{
        return title;
    }
    Genre getGenre() const{
        return genre;
    }

    void setBookID(int bID){ bookID = bID; }
    void setRating(float _rating) { 
        if (_rating >= 0.0 && _rating <= 5.0) rating = _rating; 
        else std::cout << "Invalid rating! Must be 0.0–5.0.\n";
    }
    void setPrice(double _price) {
        if (_price > 0) price = _price; 
        else std::cout << "Invalid price! Must be positive.\n";
    }
    void setAvailabilityStatus(char availStat) { availabilityStatus=availStat;}
    void setIsReferenceOnly(bool isRefOnly) {isReferenceOnly=isRefOnly;}
    void setTitle(std::string _title) {
        if (!_title.empty()) title = _title;
        else std::cout << "Title cannot be empty!\n";
    }
    void setGenre(Genre g){genre=g;}

    void updateAvailability(bool isBorrowed){
        availabilityStatus = isBorrowed? 'B' : 'A';
    }

    void displayInfo(){
        std::cout<< "\nBook ID: " << bookID;
        std::cout<< "\nTitle: " << title;
        std::cout<< "\nPrice: " << price;
        std::cout<< "\nRating: " << rating;
        std::cout<< "\nStatus: " << (availabilityStatus == 'A' ? "Available" : "Borrowed");
        std::cout<< "\nReference Only: " << (isReferenceOnly ? "Yes" : "No");
        std::cout<< "\nGenre: " << genreToString(genre) << "\n";
    }
};

void markAsReference(Book &book){
    book.setIsReferenceOnly(true);
    if(book.getIsReferenceOnly()){
        std::cout<<"Book "<<book.getTitle()<<" marked as reference only"<<std::endl;
    }
}

bool isAffordable(Book &book, double budget){
    return book.getPrice()<=budget;
}

void printFormattedBookList(const Book books[], const int size){
    std::cout << "\n--------------------------------------------------------------\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Title"
              << std::setw(10) << "Price"
              << std::setw(8) << "Rating"
              << std::setw(10) << "Status"
              << std::setw(12) << "Reference"
              << std::setw(12) << "Genre"
              << "\n--------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(5) << books[i].getBookID()
             << std::setw(20) << books[i].getTitle()
             << std::setw(10) << books[i].getPrice()
             << std::setw(8) << books[i].getRating()
             << std::setw(10) << (books[i].getAvailabilityStatus() == 'A' ? "Available" : "Borrowed")
             << std::setw(12) << (books[i].getIsReferenceOnly() ? "Yes" : "No")
             << std::setw(12) << genreToString(books[i].getGenre())
             << "\n";
    }
}

int main() {
    const int SIZE = 3;
    Book books[SIZE] = {
        Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY),
        Book(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE),
        Book() 
    };

    int choice;
    do {
        std::cout << "\n===== Library Menu =====\n";
        std::cout << "1. Add/Update Book Details\n";
        std::cout << "2. Mark Book as Reference Only\n";
        std::cout << "3. Check if Book is Affordable\n";
        std::cout << "4. Update Availability\n";
        std::cout << "5. Display Book Details\n";
        std::cout << "6. Display All Books\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int idx;
            std::cout << "Enter index (0–2): ";
            std::cin >> idx;
            if (idx >= 0 && idx < SIZE) {
                int id; float rating; double price; char status; bool ref; std::string title; int g;
                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << "Enter Rating (0.0–5.0): "; std::cin >> rating;
                std::cout << "Enter Price (>0): "; std::cin >> price;
                std::cout << "Enter Status (A/B): "; std::cin >> status;
                std::cout << "Is Reference Only (0/1): "; std::cin >> ref;
                std::cin.ignore();
                std::cout << "Enter Title: "; getline(std::cin, title);
                std::cout << "Select Genre (0=FICTION,1=NONFICTION,2=SCIENCE,3=HISTORY,4=TECHNOLOGY): ";
                std::cin >> g;

                books[idx] = Book(id, rating, price, status, ref, title, static_cast<Genre>(g));
            }
        }
        else if (choice == 2) {
            int idx; std::cout << "Enter index: "; std::cin >> idx;
            if (idx >= 0 && idx < SIZE) markAsReference(books[idx]);
        }
        else if (choice == 3) {
            int idx; double budget;
            std::cout << "Enter index and budget: ";
            std::cin >> idx >> budget;
            if (idx >= 0 && idx < SIZE)
                std::cout << (isAffordable(books[idx], budget) ? "Affordable\n" : "Not Affordable\n");
        }
        else if (choice == 4) {
            int idx; bool borrowed;
            std::cout << "Enter index and borrowed? (1=Yes,0=No): ";
            std::cin >> idx >> borrowed;
            if (idx >= 0 && idx < SIZE) books[idx].updateAvailability(borrowed);
        }
        else if (choice == 5) {
            int idx; std::cout << "Enter index: "; std::cin >> idx;
            if (idx >= 0 && idx < SIZE) books[idx].displayInfo();
        }
        else if (choice == 6) {
            printFormattedBookList(books, SIZE);
        }

    } while (choice != 7);

    return 0;
}