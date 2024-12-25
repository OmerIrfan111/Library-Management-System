# Library-Management-System
Library Management System - End Semester Project 
************************************************************Library Management System - User Manual********************************************************
                                                                          Introduction
Welcome to the Library Management System! This system allows users to manage and borrow books from the library. The system is divided into two main roles: 1. Admin:
Admins can manage the library, add, modify, and delete books
2. Users:
Users can search for and borrow books.

***********************************************************************System Requirements*****************************************************************
Operating System: Windows/Linux/MacOS
Compiler: C++ compiler(MinGW)
Libraries: No external libraries are required.
               
*********************************************************************How to Run the Program****************************************************************
                                                                       
                                                                       1. Compile the Code
If using GCC or a terminal-based compiler:
Copy code:
Step 1:
g++ library_management_system.cpp
Step 2:
./a.exe

If using an IDE(Visual Studio):
Simply open the .cpp file and run the project.

                                                                      2. Starting the Program
When the program starts, you will be allowed to log in as either an Admin or User.
 
Admin Mode Features
Once logged in as Admin, you have the following options:
1. Add a New Book
*	Select Add Book from the menu.
*	Enter the Title of the book.
*	Enter the Author of the book.
*	Enter the Genre of the book.
*	Enter the Description of the book.
*	Enter the Location of the book.
*	The book will be added to the library.

2. Modify Book Details
* 	Select Modify Book from the menu.
*	Enter the Title of the book you want to modify.
*	Enter the new Title or Author for the book.
*	The book details will be updated accordingly.

3. Delete a Book
*	Select Delete Book from the menu.
*	Enter the Title of the book to delete.
*	Confirm the deletion. 
*       The book will be permanently removed from the system.

4. View All Books
*	Select View All Books.
*	The program will display a list of all books currently available in the library, including their titles and authors.

 
**********************************************************************User Mode Features*******************************************************************

Once logged in as User, you can perform the following actions:
1. Search for a Book
*	Select Search Book from the menu.
*	You can search by:
	1. Title of the book
	2. Author of the book
	3. Genre of the book

2. Borrow a Book
*	After searching for a book, you can borrow it by selecting Borrow from the search results.
*	The system will check if the book is available.
*	If the book is available, its status will change to Checked Out and the user will successfully borrow it.

3. View Available Books
*	Select View Available Books from the menu.
*	The program will display a list of all books currently available for borrowing.
 
**********************************************************************Exiting the Program******************************************************************

To exit the program, select Exit from the main menu at any time. The program will terminate and you will return to terminal.

