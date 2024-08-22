// book shop maintains the inventory of books that are being sold
// at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the title and author and the system
// searches the list and displays whether it is available or not. If it is
// not, an appropriate message is displayed. If it is, then the system
// displays the book details and requests for the number of copies
// required. If the requested copies book details and requests for the
// number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the
// message “Required copies not in stock” is displayed. Design a system using a class called books with suitable member
// functions and Constructors. Use new operator in constructors to
// allocate memory space required. Implement C++ program for the system.
// 4. Design a C++ Class ‘Complex ‘ with data members for real 

#include<iostream>
#include<vector>
using namespace std;

class Book
{
    string title;
    string author;
    float price;
    string publisher;
    int stock;

public:
    Book(string t, string a, float p, string pub, int s)
    {
        title = t;
        author = a;
        price = p;
        publisher = pub;
        stock = s;
    }

    void display()
    {
        cout << title << "\t" << author << "\t" << price << "\t" << publisher << "\t" << stock << "\t" << endl;
    }

    string getTitle()
    {
        return this->title;
    }

    string getAuthor()
    {
        return this->author;
    }

    float getPrice() 
    {
        return this->price;
    }

    string getPublisher()
    {
        return this->publisher;
    }

    int getStock()
    {
        return this->stock;
    }

    void reduceStock(int quantity) 
    {
        this->stock -= quantity;
    }
};

vector<Book> B;

// Searching title and name of author
void Search()
{
    string title, author;
    int cost, q;
    float totalamount;
    cout << "Enter the title of the book" << endl;
    cin >> title;
    cout << "Enter the name of the author" << endl;
    cin >> author;

    int flag = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i].getTitle() == title && B[i].getAuthor() == author)
        {
            flag = 1;
            cout << "Book found" << endl;
            B[i].display();
            cout << "Enter the number of copies" << endl;
            cin >> q;
            if (B[i].getStock() >= q)
            {
                totalamount = B[i].getPrice() * q;
                cout << "Total amount = " << totalamount << endl;
                B[i].reduceStock(q);                 // Reduce stock after selling
            }
            else
            {
                cout << "Required copies not in stock" << endl;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Book is not here.." << endl;
    }
}

void display()
{
    cout << "Title" <<"\t" <<"Author" <<"\t" << "Price" <<"\t" << "Publisher"<<"\t"<<"Stock"<< endl;
    for (int i = 0; i < B.size(); i++) 
    {
        B[i].display();
    }
}

int main()
{
    int ch = 0;
    int flag = 0;
    string title;
    string author;
    float price;
    string publisher;
    int stock;

    while (ch != 4)
    {
        cout << "\n1. Accept \n2. Display \n3. Search\n4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter the title of the book" << endl;
                cin >> title;
                cout << "Enter the name of the author" << endl;
                cin >> author;
                cout << "Enter the price of the book" << endl;
                cin >> price;
                cout << "Enter the publisher of the book" << endl;
                cin >> publisher;
                cout << "Enter the stock of the book" << endl;
                cin >> stock;
                flag = 0;
                for (int i = 0; i < B.size(); i++)
                {
                    if (B[i].getAuthor() == author && B[i].getTitle() == title) // Fixed the condition
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    B.push_back(Book(title, author, price, publisher, stock));
                }
                break;

            case 2:
                display();
                break;

            case 3:
                Search();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout << "Enter valid choice" << endl;
                break;
        }
    }
    return 0;
}
