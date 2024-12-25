#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include <iomanip>
using namespace std;
struct book   //structure for books
{
    string name = "_", author = "_", description = "_", genre = "_", borrower_name = "_", borrower_contact = "_";
    bool borrowed = false;
    void blank()
    {
        name = "_";
        author = "_";
        description = "_";
        genre = "_";
        borrowed = false;
        borrower_name = "_";
        borrower_contact = "_";
    }
};
inline void clr() {  //clears screen
    system("CLS");
}
void add_book();
void delete_book(int floor, int section, int index);
void modify_book(int floor, int section, int index);
void search_book();
void info(int floor, int section, int index);
void sort(string* s)  //used for sorting of books
{
    bool flag = true;
    for (int i = 0; i < (*s).length() - 1 && flag; i++)
    {
        flag = false;
        for (int j = 0; j < (*s).length() - 1 - i; j++)
            if ((*s)[j] > (*s)[j + 1])
            {
                char t = (*s)[j];
                (*s)[j] = (*s)[j + 1];
                (*s)[j + 1] = t;
                flag = true;
            }
    }
}
void save();
bool load();
#define WID setw(90)
// Terminal color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"      // Red
#define GREEN   "\033[32m"      // Green
#define YELLOW  "\033[33m"      // Yellow
#define BLUE    "\033[34m"      // Blue
#define MAGENTA "\033[35m"      // Orange
// Genre
#define action 'a'
#define adventure 'b'
#define fiction 'c'
#define fantasy 'd'
#define historical 'e'
#define horror 'f'
#define comedy 'g'
#define detective 'h'
#define psychological 'i'
#define lgbtq 'j'
#define guide 'k'
#define romance 'l'
#define scifi 'm'
#define short_story 'n'
#define thriller 'o'
#define religious 'p'
#define art 'q'
#define biography 'r'
#define essay 's'
#define philosophy 't'
#define travel 'u'
#define true_crime 'v'
#define poetry 'w'
#define children 'x'
#define self_help 'y'
#define education 'z'
inline void display_genres() //displays all the genre present
{
    cout <<BLUE<<"(a)\tAction.\t\t(b)\tAdventure.\n(c)\tFiction.\t(d)\tFantasy.\n(e)\tHistorical.\t(f)\tHorror.\n(g)\tComedy.\t\t(h)\tDetective.\n(i)\tPsychological.\t(j)\tLGBTQ+.\n(k)\tGuide / How to.\t(l)\tRomance.\n(m)\tSci-Fi.\t\t(n)\tShort Story.\n(o)\tThriller.\t(p)\tRelogious.\n(q)\tArt.\t\t(r)\tBiography / Autobiography.\n(s)\tEssay.\t\t(t)\tPhilosophy.\n(u)\tTravel.\t\t(v)\tTrue Crime.\n(w)\tPoetry.\t\t(x)\tChildren.\n(y)\tSelf-Help.\t(z)\tAcademics.\n"<<RESET;
}
book books[2][3][20];
bool admin;
int x;
string id = "admin.bese24seecs", password = "Admin@123";
int main()
{
    if (not load())
    {
        ofstream file;
        file.open("Text.txt", ios::app);
        file.close();
        save();
    }
    cout <<setw(90) <<YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n\n";
    cout <<setw(30)<<MAGENTA<<"\t\t\t\t\t   Welcome to Library Management System.\n"<<RESET;
    cout <<setw(90)<< YELLOW<<"\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90) << "\n\t\t\t\t\t\t\t\t*******************************************\n";
login:
    cout <<setw(90) << "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n\n";
    cout<<setw(96)<<GREEN"1.\tAdmin Login.\n";
    cout<<WID<<"2.\tUser Login.\n";
    cout<<setw(91)<<"3.\tInformation.\n";
    cout<<setw(85)<<"0. \tExit.\n"<<RESET; //outputs all the access level to users
    cout <<setw(90) <<YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n\n";
    string input;
    cin >> x;
    clr();
    switch (x)
    {
    case 0:
        return 0;
    case 1: //Admin Access
    cout <<setw(90) << "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n";
        cout <<BLUE<<WID<<"ID ";
    cout <<setw(90) << "YELLOW<<\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n\n";
        cin >> input;
        clr();
        if (input != id)
        {
            cout <<RED<<"Wrong id. Failed to log in. Going Back.\n";
            goto login;
        }
    cout <<setw(90) << YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n";
        cout <<BLUE<<WID<<"Password ";
        cout <<setw(90) << YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n\n";
        cin >> input;
        clr();
        if (input != password)
        {
            cout <<RED<<WID<<"Wrong password. Failed to log in. Going Back.\n";
            goto login;
        }
        admin = true;
    case 2: //User Access
        cout <<MAGENTA<<WID<<"Login successful.\n";
        break;
    case 3: //Information panel
        cout << YELLOW "                                             Library Management System\n\n";
        cout << "                                                            Version: 1.0\n";
        cout << "                                                           Developed by:\n";
        cout << "                                                           - Omer Irfan\n";
        cout << "                                                           - Musa Nadeem\n";
        cout << "                                                           - Safiullah\n\n" << RESET;
        cout << BLUE"                                                Description:\n";
        cout << "                                                    This application helps manage a library by allowing users to:\n";
        cout << "                                                     - Add books to the library collection.\n";
        cout << "                                                     - View the list of available books.\n";
        cout << "                                                     - Borrow and return books.\n";
        cout << "                                                     - Modify or delete existing book records (admin only).\n\n";
        cout << "                                                   Usage Instructions:\n";
        cout << "                                                   - Log in as an Admin or User to access the system.\n";
        cout << "                                                   - Use the provided menu options to perform tasks.\n\n" << RESET;
        cout << GREEN "                                             Contact:\n";
        cout << "                                                   For any issues or feedback, contact your_email@example.com\n\n" << RESET;
        cout << RED "                                               Press any key to go back to the menu...\n" << RESET;
        _getch();
        goto login;
    default:
        cout <<RED<< "Invalid Input. Try again.\n";
        goto login;
    }
menu: //menu for students and user
    cout <<setw(90) << YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n";
    cout <<BLUE<<WID<<"1.\tSearch a book.\n";
    if (admin)
        cout <<BLUE<<WID<<"2.\tAdd a book.\n";
        cout <<BLUE<<WID<<"3.\tView Borrowed books.\n";
        cout <<BLUE<<WID<<"4.\tChange ID.\n";
        cout <<BLUE<<WID<<"5.\tChange Password.\n";
    cout <<BLUE<<"0.\tExit.\n";
    cout <<setw(90) << YELLOW<< "\n\t\t\t\t\t\t\t\t------------------------------------------";
    cout <<setw(90 )<< "\n\t\t\t\t\t\t\t\t*******************************************\n"<<RESET;
get_x:
    cin >> x;
    if (x > 1 and x < 6 and not admin)
    {
        cout <<RED<<"Invalid Input. Try again.\n";
        goto get_x;
    }
    if (x == 0)
        return 0;
    int n = 0;
    string new_password;
    bool upper_case = false, lower_case = false, number = false, symbol = false;
    switch (x)
    {
    case 1: //search for books
        search_book();
        break;
    case 2: //adding new books
        add_book();
        break;
    case 3: //Viewing borrowed books
        clr();
        int found[120];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 20 and books[i][j][k].name != "_"; k++)
                    if (books[i][j][k].borrowed)
                    {
                        found[n] = 1000 * i + 100 * j + k;
                        n++;
                        cout << n << ".\t" << books[i][j][k].name << endl;
                    }
        if (n == 0)
        {
            cout <<RED<<"No borrowed books found.\n";
            break;
        }
get_book:
        cout <<MAGENTA<<"Which book to view?\nEnter 0 to go back.\n";
        cin >> x;
        if (x == 0)
            goto menu;
        if (x<0 || x>n)
        {
            cout <<RED<<"Invalid Input.Try again.\n";
            goto get_book;
        }
        x--;
        clr();
        info(found[x] / 1000, (found[x] % 1000) / 100, found[x] % 100);
        break;
    case 4:
        clr();
        cout <<BLUE<<"ID: \n";
        cin >> id;
        clr();
        break;
    case 5:
        clr();
        cout <<BLUE<<"Password: \n";
        cin >> new_password;
        for(int i = 0; i < new_password.length(); i++)
            if(new_password[i] >= 'a' and new_password[i] <= 'z')
                lower_case = true;
            else if (new_password[i] >= 'A' and new_password[i] <= 'Z')
                upper_case = true;
            else if (new_password[i] >= '0' and new_password[i] <= '9')
                number = true;
            else
                symbol = true;
        if (upper_case and lower_case and number and symbol and new_password.length() > 7)
            password = new_password;
        else //displays the requirement for a strong password
            cout <<MAGENTA<<"The password must be at least 8 characters long including an upper case letter, a lower case letter, a number and a symbol\n";
        clr();
        break;
        default:
        cout <<RED<<"Invalid Input. Try again.\n";
        goto get_x;
        break;
    }
    save();
    goto menu;
}
void add_book()
{
    int av[6], nav = 0;//av = available, nav =number of available books
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            if (books[i][j][19].name == "_")
            {
                av[nav] = 10 * i + j;
                nav++;
            }
    if (nav == 0) //executes if no more space is avaialable
    {
        cout <<RED<<"There is no space available. Remove some books from the library first.\nPress any key to continue.\n"; 
        _getch();
        return;
    }
    clr();
    book temp;
    getchar();
    cout <<BLUE<<"Enter the name of the book: ";
    getline(cin, temp.name);
    clr();
    cout <<BLUE<<"Enter the name of the author: ";
    getline(cin, temp.author);
    clr();
    cout <<BLUE<<"What are it's genres?\n";
    display_genres();
    cout <<MAGENTA<<"Example abc means the book is action, adventure, fantasy genre.\nGenre: ";
    cin >> temp.genre;
    sort(&temp.genre);
    clr();
    cout <<BLUE<<"Enter the description of the book.\nDescription: ";
    getchar();
    getline(cin, temp.description);
    clr();
    cout <<MAGENTA<<"Where do you want to store?\n";
    for (int i = 0; i < nav; i++)
        cout << i + 1 <<GREEN<<".\tFloor " << av[i] / 10 + 1 << " Section " << av[i] % 10 + 1 << endl;
    int store;
get_store:
    cin >> store;
    clr();
    if (store<1 || store>nav)
    {
        cout <<RED<<"Invalid Input. Try again.\n";
        goto get_store;
    }
    store--;
    int book_number = 0;
    while (books[av[store] / 10][av[store] % 10][book_number].name != "_")
        book_number++;
    books[av[store] / 10][av[store] % 10][book_number] = temp;
}
void delete_book(int f, int s, int i) //used when deleting books
{
    while (i < 19)
    {
        books[f][s][i] = books[f][s][i + 1];
        if (books[f][s][i + 1].name == "_")
            break;
        i++;
    }
    books[f][s][i].blank();
}
void modify_book(int f, int s, int i) //modification of books
{
    cout <<BLUE<<WID<<"What do you want to change?\n0.\tGo Back.\n1.\tName.\n2.\tAuthor.\n3.\tGenre.\n4.\tDescription.\n";
    if (books[f][s][i].borrowed)
        cout <<BLUE<<WID<<"5.\tBorrower Name.\n6.\tBorrower Contact.\n";
    int choice;
get_choice:
    cin >> choice;
    clr();
    switch (choice)
    {
    case 0:
        break;
    case 1: //Name
        cout <<GREEN<<"Name: \n";
        getchar();
        getline(cin, books[f][s][i].name);
        break;
    case 2: //Author
        cout << "Author: \n";
        getchar();
        getline(cin, books[f][s][i].author);
        break;
    case 3: //Genre
        cout << "Enter the genres\n";
        display_genres();
        cout << "Example abc means the book is action, adventure, fantasy genre.\nGenre: \n";
        cin >> books[f][s][i].genre;
        sort(&books[f][s][i].genre);
        break;
    case 4: //Description
        cout << "Description: \n";
        getchar();
        getline(cin, books[f][s][i].description);
        break;
    case 5: //Borrowers Name
        if (not books[f][s][i].borrowed)
        {
            cout <<RED<< "Invalid Input. Try again.\n";
            goto get_choice;
        }
        cout <<MAGENTA<<"Borrower's Name: \n";
        getchar();
        getline(cin, books[f][s][i].borrower_name);
        break;
    case 6: //Brrowers Contact
        if (not books[f][s][i].borrowed)
        {
            cout <<RED<< "Invalid Input. Try again.\n";
            goto get_choice;
        }
        cout <<MAGENTA<<"Borrower's Contact: \n";
        getchar();
        getline(cin, books[f][s][i].borrower_contact);
        break;
    default:
        cout <<RED<< "Invalid Input. Try again.\n";
        goto get_choice;
    }
    clr();
}
void search_book() //Searching for books through a mechanism
{
    clr();
    cin.ignore();
    cout <<BLUE<<"How do you want to sarch?\n1.\tBy Title of the book.\n2.\tBy name of the Author.\n3.\tBy Both.\n4.\tShow all.\n";
    string name = "", author = "";
get_search:
    cin >> x;
    getchar();
    if (x < 1 || x>4)
    {
        cout <<RED<<"Invalid Inut. Try again.\n";
        goto get_search;
    } 
    if (x == 1 || x == 3) //Search by title
    {
        cout <<MAGENTA<<"Enter the title of the book you want to search: \n";
        getline(cin, name);
        clr();
    }
    if (x == 2 || x == 3)
    {
        cout <<MAGENTA<<"Enter the name of the author you want to search: \n";
        getline(cin, name);
        clr();
    }
    cout << "Enter the genres you want to search. Eneter all for all genres.\n";
    display_genres();
    cout << "Example abc means the book is action, adventure, fantasy genre.\nGenre: \n";
    string genres;
    cin.ignore();
    cin >> genres;
    sort(&genres);
    clr();
    int found[120];
    for (int i = 0; i < 120; i++)
        found[i] = 0;
    int x = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 20; k++)
                if (books[i][j][k].name == "_")
                    break;
                else if (books[i][j][k].name.find(name) != string::npos and books[i][j][k].author.find(author) != string::npos)
                {
                    for (int a = 0; a < genres.length(); a++)
                        found[x] = i * 1000 + j * 100 + k;
                    x++;
                    cout << x << ".\t" << books[i][j][k].name << " floor " << i + 1 << " section " << j + 1 << endl;
                }
    if (x == 0)
    {
        cout <<RED<<"No books found.\n";
        return;
    }
    int book_number;
get_book_number: //Used for getting book number as input
    cout <<BLUE<<"Enter the number of the book to show: \n";
    cin >> book_number;
    if (book_number<1 || book_number>x)
    {
        cout <<RED<<"Invalid Input. Try again.\n";
        goto get_book_number;
    }
    book_number--;
    info(found[book_number]/1000, (found[book_number] % 1000) / 100, found[book_number] % 100);
}
void info(int f, int s, int i) //Displays info of books
{

    string genres[26] = { "Action", "Adventure", "Fiction", "Fantasy", "Historical", "Horror", "Comedy", "Detective", "Psychological", "LGBTQ+", "Guide", "Romance", "Sci-Fi", "Short Story", "Thriller", "Religion", "Art", "Biographies and Autobiographies", "Essay", "Philosophy", "Travel", "True Crime", "Poetry", "children", "Self-Help", "Education" };
start:
    clr();
    cout <<MAGENTA<<"Name: " << books[f][s][i].name << "\nAuthor:" << books[f][s][i].author << "\nGenre: " << genres[int(books[f][s][i].genre[0] - 'a')];
    for (int x = 1; x < books[f][s][i].genre.length(); x++)
        cout << ", " << genres[int(books[f][s][i].genre[x] - 'a')];
    cout << "\nDescription: " << books[f][s][i].description << endl;
    if (books[f][s][i].borrowed)
        cout << "Not available right now.\n";
    cout << "What would you like to do?\n0.\tGo Back.\n";
    if (books[f][s][i].borrowed)
        cout << MAGENTA "1.\tReturn.\n";
    else
        cout << MAGENTA "1.\tBorrow.\n";
    if (admin)
        cout << "2.\tModify.\n3.\tDelete.\n";
    int choice;
    string name, contact;
get_choice:
    cin >> choice;
    switch (choice)
    {
    case 0:
        clr();
        break;
    case 1:
        clr();
        cout <<BLUE<<"Enter you name: \n";
        getchar();
        getline(cin, name);
        if (books[f][s][i].borrowed)
            if (books[f][s][i].borrower_name == name)
            {
                books[f][s][i].borrowed = false;
                cout << "The book has been returned\n";
                break;
            }
        cout << BLUE << "Enter your phone number: \n";
        getline(cin, books[f][s][i].borrower_contact);
        books[f][s][i].borrower_name = name;
        books[f][s][i].borrowed = true;
        cout <<YELLOW<<"The book has been borrowed.\n";
        break;
    case 2:
        if (not admin)
        {
            cout <<RED<<"Invalid Input. Try again.\n";
            goto get_choice;
        }
        clr();
        modify_book(f, s, i);
        goto start;
        break;
    case 3:
        if (not admin)
        {
            cout <<RED<<"Invalid Input. Try again.\n";
            goto get_choice;
        }
        clr();
        delete_book(f, s, i);
        break;
    default:
        cout <<RED<<"Invalid Input. Try again.\n";
        goto get_choice;
    }
}
void save() //Saving of data
{
    ofstream file;
    string line;
    file.open("Text.txt"); 
    if (not file.is_open())
    {
        cout <<RED<<"Failed to save data.\n";
        _getch();
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 20; k++)
                file << books[i][j][k].name << endl << books[i][j][k].author << endl << books[i][j][k].genre << endl << books[i][j][k].description << endl << books[i][j][k].borrowed << endl << books[i][j][k].borrower_name << endl << books[i][j][k].borrower_contact << endl;
    file << id << endl << password;
    file.close();
}
bool load() //Loading of data 
{
    ifstream file;
    file.open("Text.txt");
    if (not file.is_open())
    {
        cout <<RED<<"Failed to load data.\n";
        _getch();
        return false;
    }
    string x; //Stores information of books
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 20; k++)
            {
                getline(file, books[i][j][k].name);
                getline(file, books[i][j][k].author);
                getline(file, books[i][j][k].genre);
                getline(file, books[i][j][k].description);
                getline(file, x);
                books[i][j][k].borrowed = (x == "1");
                getline(file, books[i][j][k].borrower_name);
                getline(file, books[i][j][k].borrower_contact);
            }
    getline(file, id);
    getline(file, password);
    file.close();
    return true;
}
