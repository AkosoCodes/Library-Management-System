#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Header/Book.h"
#include "Header/Reservation.h"
#include "Header/Member.h"
#include "Header/Librarian.h"

using namespace std;

int userID = 0; // Initializing UserID
struct Result{
    bool doesExist;
    string id;
    int quantity;
};

// Starts Program
void libraryManagementSystem();

// Menu Methods
void loginMenu();
void librarianMenu();
void memberMenu();
void accountMenu();
void bookMenu();

// Account Methods
void addAccount();
void removeAccount();
void showAccount();

// Book Methods
void addBook();
void removeBook();
void showInventory();

// Reservation Methods
void makeReservation();
void cancelReservation();
void showReservations();
void printBorrowedBooks(int userID);

// Vectors used to store Objects
vector<Book> books;
vector<Member> members;
vector<Account> userCredentials;
vector<Reservation> reservations;

// File I/O
void loadFiles();
vector<Book> loadBooks();
vector<Member> loadMembers();
vector<Account> loadAccounts();
vector<Reservation> loadReservations();
void rewrite(int ID, bool mode, int amount=1);
void writeFile(const string& line, string fileSource);

// Check Methods
void userInfo(Account User);
void changeQuantity(string ID, int Quantity);
bool inputCheck(int input, int minBound, int maxBound);
Result doesExist(string Title, string Author);
string checkUserID(string Username);

// Other Methods
void pause();
void message(bool mode);
vector<string> split(string s, char delimiter);


// main
int main() {
    libraryManagementSystem();
    return 0;
}


/*  METHOD DEFINITIONS  */

// Starts Program
void libraryManagementSystem(){

    loadFiles();
    message(true);
    loginMenu();
}

// Menu Methods
void loginMenu(){

    // Initializing Values
    bool loop = true;
    int count = 0;
    string tempUsername, tempPassword;

    do{
        // Prints available options and asks for input
        cout << "|-------------------------------------------|" << endl;
        cout << "|                ~LOGIN PAGE~               |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| Username:"; cin >> tempUsername;
        cout << "| Password:"; cin >> tempPassword;
        cout << "|-------------------------------------------|" << endl;


        // Iterates through all users to check for match
        for(int i=0; i<userCredentials.size(); i++){

            Account user = userCredentials[i];

            if(user.getUsername() == tempUsername && user.getPassword() == tempPassword){
                userID = stoi(checkUserID(tempUsername));
                count++;
                loop = false;

                if(user.getType() == 0){
                    librarianMenu();
                }else{
                    memberMenu();
                }
            } else if(i == userCredentials.size()-1 && count == 0){

                cout << "Wrong Credentials used!" << endl;
                pause();
            }

        }

    } while(loop);
}
void librarianMenu() {

    // Initializing Values
    int input = 0;
    bool loop = true;

    do{
        // Prints available options and asks for input
        cout << endl << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "|              ~LIBRARIAN MENU~             |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Manage Books" << endl;
        cout << "| 2 - Manage Accounts" << endl;
        cout << "| 3 - Borrowed Status" << endl;
        cout << "| 4 - Exit" << endl;
        cout << "|-------------------------------------------|" << endl;
        cin >> input;

        cout << endl << endl;

        // Validates input and proceeds with the choice
        if(inputCheck(input, 1, 4)){
            switch(input){
                case 1:
                    bookMenu();
                    loop = true;
                    break;

                case 2:
                    accountMenu();
                    loop = true;
                    break;

                case 3:
                    showReservations();
                    pause();
                    loop = true;
                    break;

                default:
                    message(false);
                    loop = false;

            }
        }

    } while(loop);
}
void memberMenu(){

    // Initializing Values
    int input = 0;
    bool loop = true;

    do{
        // Prints available options and asks for input
        cout << endl << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "|                ~MEMBER MENU~              |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Show Books" << endl;
        cout << "| 2 - Borrow Book" << endl;
        cout << "| 3 - Return Books" << endl;
        cout << "| 4 - Account Info" << endl;
        cout << "| 5 - Go Back" << endl;
        cout << "|-------------------------------------------|" << endl;
        cin >> input;

        cout << endl << endl;

        // Validates input and proceeds with the choice
        if(inputCheck(input, 1, 5)){
            switch(input){
                case 1:
                    showInventory();
                    pause();
                    loop = true;
                    break;

                case 2:
                    makeReservation();
                    loop = true;
                    break;

                case 3:
                    cancelReservation();
                    loop = true;
                    break;

                case 4:
                    userInfo(userCredentials[userID]);
                    break;
                default:
                    message(false);
                    loop = false;

            }
        }

    } while(loop);
}
void accountMenu(){

    // Initializing Values
    int input = 0;
    bool loop = true;

    do{
        // Prints Menu and asks for Input
        cout << endl << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "|               ~ACCOUNT MENU~              |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Add a Member" << endl;
        cout << "| 2 - Remove a Member" << endl;
        cout << "| 3 - List of members" << endl;
        cout << "| 4 - Go Back" << endl;
        cout << "|-------------------------------------------|" << endl;
        cin >> input;
        cout << endl << endl;

        // Validates input and proceeds with the choice
        if(inputCheck(input, 1, 4)){
            switch(input){
                case 1:
                    addAccount();
                    loop = true;
                    break;

                case 2:
                    removeAccount();
                    loop = true;
                    break;

                case 3:
                    showAccount();
                    pause();
                    loop = true;
                    break;

                default:
                    loop = false;

            }
        }

    } while(loop);

}
void bookMenu(){

    // Initializing Values
    int input = 0;
    bool loop = true;

    do{
        // Prints available options and asks for input
        cout << endl << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "|                 ~BOOK MENU~               |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Add a Book" << endl;
        cout << "| 2 - Remove a Book" << endl;
        cout << "| 3 - Check Inventory" << endl;
        cout << "| 4 - Go Back" << endl;
        cout << "|-------------------------------------------|" << endl;
        cin >> input;

        cout << endl << endl;

        // Validates input and proceeds with the choice
        if(inputCheck(input, 1, 4)){
            switch(input){
                case 1:
                    addBook();
                    loop = true;
                    break;

                case 2:
                    removeBook();
                    loop = true;
                    break;

                case 3:
                    showInventory();
                    pause();
                    loop = true;
                    break;

                default:
                    loop = false;
            }
        }

    } while(loop);

}

// Book Methods
void addBook(){

    // Initializing temporary values
    string tempAuthor, tempTitle, tempID;
    int tempQuantity, tID;

    // Asks for input and assigns it to Values
    cout << "|-------------------------------------------|" << endl;
    cout << "|  Please enter the following information:  |" << endl;
    cout << "|-------------------------------------------|" << endl;

    // ID
    tID = books.size() + 1;
    tempID = to_string(tID);

    // Title
    cout << "| Title:";
    cin.ignore();
    getline(cin, tempTitle);

    // Author
    cout << "| Author:";
    getline(cin, tempAuthor);

    // Quantity
    cout << "| Quantity:";
    cin >> tempQuantity;

    // Checks whether the Book already exists
    Result check = doesExist(tempTitle, tempAuthor);

    // If it exists, it will just add the quantity to it, otherwise it will create a new doesExist
    if(check.doesExist){
        changeQuantity(check.id, tempQuantity);
    }else {
        Book newBookObject(tempID, tempTitle, tempAuthor,tempQuantity);
        books.push_back(newBookObject);
        string newBook = "\n"+tempID + "|" + tempTitle + "|" + tempAuthor + "|" + to_string(tempQuantity);
        writeFile(newBook, "bookList.txt");
    }

}
void removeBook(){

    // Initializing temporary values
    int tempID, tempAmount;
    bool loop = true;

    showInventory(); // Shows the list of Books

    // Asks for input and rewrites within file
    do{
        cout << "|-------------------------------------------|" << endl;
        cout << "|  Please enter the following information:  |" << endl;
        cout << "|-------------------------------------------|" << endl;

        // Book ID
        cout << "| Book ID:";
        cin >> tempID;

        // Amount
        cout << "| Amount:";
        cin >> tempAmount;

        // Checks if input is valid
        if(inputCheck(tempID, 0, books.size()) && inputCheck(tempAmount, 0, books[tempID-1].getQuantity())){
            rewrite(tempID-1, false, tempAmount);
            loop = false;
        }else{
            cout << "INVALID INPUT!" << endl;
            pause();
        }
    }while(loop);


}
void showInventory(){

    // Creates a vector using the file
    vector<Book> inventory = loadBooks();
    cout << "ID| \"Title\" by Author | Quantity" << endl;
    cout << "--|-------------------------------------------|" << endl;

    // Iterates through each line and prints it.
    for(auto & i : inventory){
        i.printBookInfo();
    }

    cout << "--|-------------------------------------------|" << endl;
}

// Account Methods
void addAccount(){

    // Initializing temporary values
    bool loop = true;
    int tempType, tID;
    string newMember, newLibrarian, newAccount;
    string tempUsername, tempPassword, tempName, tempSurname, tempAddress, tempAge, tempID;

    // ID
    tID  = members.size() + 1;
    tempID = to_string(tID);

    do {
        cout << "|-------------------------------------------|" << endl;
        cout << "|           What type of account?           |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Member" << endl;
        cout << "| 2 - Librarian" << endl;
        cout << "| Account:";
        cin >> tempType;

        // Validates input
        if(inputCheck(tempType,1,2)){

            // Member
            if(tempType==1){

                // Asks for input
                cout << "| Username:"; cin >> tempUsername;
                cout << "| Password:"; cin >> tempPassword;
                cout << "| Name:"; cin >> tempName;
                cout << "| Surname:"; cin >> tempSurname;
                cout << "| Address:"; cin.ignore(); getline(cin, tempAddress);
                cout << "| Age:"; cin >> tempAge;

                // Creates an Object and adds it to Vector
                Member member(tempUsername, tempPassword, tempID, 1, tempName, tempSurname, tempAddress, tempAge);
                members.push_back(member);

                // Formats the inputs in a single string and Writes to File
                newMember = "\n"+ tempID+ "|" + tempUsername + "|" + tempPassword + "|" + tempName + "|" + tempSurname + "|" + tempAddress + "|" + tempAge+ "|" + "M";
                writeFile(newMember, "memberList.txt");

                // Creates an Object and writes it to file
                Account account(tempUsername, tempPassword, tempID, 1);
                newAccount ="\n"+ tempID+ "|" + tempUsername + "|" + tempPassword + "|" + to_string(1);
                writeFile(newAccount, "accountList.txt");

                loop = false; // Exits the loop
            }else {

                // Asks for input
                cout << "| Username:"; cin >> tempUsername;
                cout << "| Password:"; cin >> tempPassword;
                cout << "| Name:"; cin >> tempName;
                cout << "| Surname:"; cin >> tempSurname;

                // Formats the inputs in a single string, and writes it to file
                Librarian librarian(tempUsername, tempPassword, tempID,0, tempName, tempSurname);
                newLibrarian = "\n"+ tempID+ "|" + tempUsername + "|" + tempPassword + "|" + tempName + "|" + tempSurname + "| - | - |" + "L";
                writeFile(newLibrarian, "librarianList.txt");

                // Formats the inputs in a single string, and writes it to file
                Account account(tempUsername, tempPassword, tempID, 1);
                newAccount ="\n"+ tempID+ "|" + tempUsername + "|" + tempPassword + "|" + to_string(0);
                writeFile(newAccount, "accountList.txt");

                loop = false; // Exits the loop
            }
        }
    }while(loop);
}
void removeAccount(){

    // Initializing temporary values
    int tempID;
    bool loop = true;

    showAccount(); // Shows the list of Accounts

    // Asks for input and rewrites within file
    do{
        cout << "|-------------------------------------------|" << endl;
        cout << "|  Please enter the following information:  |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| Account ID:";
        cin >> tempID;

        // Validates the input
        if(inputCheck(tempID, 0, members.size())){
            rewrite(tempID-1, true);
            loop = false;
        }
    }while(loop);


}
void showAccount(){

    // Creates a vector using the file
    vector<Member> database = loadMembers();
    cout << "ID|   Username   |   Full Name   | Age |    Address    | Type" << endl;
    cout << "--|----------------------------------------------------------|" << endl;

    // Iterates through each line and prints it.
    for (auto temp : database) {
        temp.printInfo();
    }

    cout << "--|----------------------------------------------------------|" << endl;
}

// Reservation Methods
void makeReservation(){

    // Initializing temporary values
    int tempID, amount;
    bool loop = true;

    showInventory(); // Shows inventory

    do {

        cout << "|-------------------------------------------|" << endl;
        cout << "|    Which book would you like to borrow?   |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| Book ID:";
        cin >> tempID;

        // Validates input
        if(inputCheck(tempID, 0, books.size())){

            cout << "| Amount:";
            cin >> amount;

            // Validates input
            if(inputCheck(amount,1,books[tempID-1].getQuantity())){

                // Creates an Object and adds it to Vector
                Reservation temp(reservations.size() + 1, tempID, userCredentials[userID].getUsername(), amount);
                reservations.push_back(temp);

                // Writes it to File
                writeFile(temp.returnReservation(), "reservationList.txt");

                loop = false; // Exits out of Loop
            }

        }else {
            cout<< "INVALID INPUT!" << endl;
            pause();
        }
    } while (loop);

}
void cancelReservation(){

    // Initializing temporary values
    int resID;
    bool loop = true;

    printBorrowedBooks(userID); // Shows the list of reservations

    // Asks for input and rewrites within file
    do{
        cout << "|-------------------------------------------|" << endl;
        cout << "|     Which book do you want to return?     |" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| Reservation ID:";
        cin >> resID;

        // Validates the input
        if(inputCheck(resID, 0, reservations.size())){
            ofstream outFile("reservationList.txt");
            for (int i=0; i < reservations.size(); i++){
                // Rewrites it back to file, and updates the selected value of the ID
                if(i == resID-1){
                    outFile << to_string(resID) + "|" + to_string(reservations[i].bookID) + "|" + reservations[i].name + "|" + to_string(0) + "\n";
                }else {
                    outFile << reservations[i].returnReservation();
                }
            }
            outFile.close();
            loop = false;
        }
    }while(loop);

}
void showReservations(){

    // Creates a vector using the file
    vector<Reservation> reserved = loadReservations();
    cout << "ID|'User' reserved 'Amount' copies of Book '#ID'" << endl;
    cout << "--|---------------------------------------------|" << endl;

    // Iterates through each line and prints it.
    for (auto i : reserved) {
        i.printReservation();
    }

    cout << "--|---------------------------------------------|" << endl;
}
void printBorrowedBooks(int userID){

    cout << "rID| # copies of 'Title' by 'Author'             |" << endl;
    cout << "---|---------------------------------------------|" << endl;

    for(auto res : reservations){
        if(res.name == userCredentials[userID].getUsername()){
            for(auto book : books){
                if(to_string(res.bookID) == book.getID()){
                    string info;

                    if(res.reservationID < 10){
                        info = to_string(res.reservationID) + "  | " + to_string(res.reservationAmount) + " copies of " + "'" + book.getTitle() + "' by "+ book.getAuthor() + "\n";
                    }else {
                        info = to_string(res.reservationID) + " | " + to_string(res.reservationAmount) + " copies of " + "'" + book.getTitle() + "' by "+ book.getAuthor() + "\n";
                    }

                    cout << info;
                }
            }
        }
    }
}

// File I/O
void loadFiles(){

    //Loads all the Files
    loadMembers();
    loadAccounts();
    loadBooks();
    loadReservations();
}
vector<Book> loadBooks(){

    string line; // Initializing Values
    books.clear(); // Clears the vector

    // Opens the file and checks if it is successful
    ifstream file("bookList.txt");
    if(!file.is_open()){
        cerr << "Error: The File could not be opened." << endl;
        exit(1);
    }

    // While there are lines in the files, read the line and add it to the vector
    while(getline(file, line)){
        vector<string> tempWords = split(line, '|');
        books.emplace_back(tempWords[0], tempWords[1], tempWords[2], stoi(tempWords[3]));
    }

    file.close(); // Closes file

    return books; // Returns the vector

}
vector<Member> loadMembers(){

    string line; // Initializing Value
    members.clear(); // Clears the vector

    // Opens the file and checks if it is successful                                                                                                                                                                                                                                // Opens the file and checks if it is successful
    ifstream file("memberList.txt");
    if(!file.is_open()){
        cerr << "Error: The File could not be opened." << endl;
        exit(1);
    }

    // While there are lines in the files, read the line and add it to the vector
    while(getline(file, line)){
        vector <string> tempLine = split(line,'|');

        Member tempMember(tempLine[1], tempLine[2], tempLine[0], 1, tempLine[3], tempLine[4], tempLine[5], tempLine[6]);
        members.push_back(tempMember);

    }

    file.close(); // Closes file

    return members; // Returns the vector

}
vector<Account> loadAccounts(){

    string line; // Initializing Value
    userCredentials.clear(); // Clears the vector

    // Opens the file and checks if it is successful
    ifstream file("accountList.txt");
    if(!file.is_open()){
        cerr << "Error: The File could not be opened." << endl;
        exit(1);
    }

    // While there are lines in the files, read the line and add it to the vector
    while(getline(file, line)){
        vector<string> tempWords = split(line, '|');
        Account tempAccount(tempWords[1], tempWords[2], tempWords[0], stoi(tempWords[3]));
        userCredentials.push_back(tempAccount);
    }

    file.close(); // Closes file
    return userCredentials; // Returns the vector
}
vector<Reservation> loadReservations(){

    string line; // Initializing Values
    reservations.clear(); // Clears the vector

    // Opens the file and checks if it is successful
    ifstream file("reservationList.txt");
    if(!file.is_open()){
        cerr << "Error: The File could not be opened." << endl;
        exit(1);
    }

    // While there are lines in the files, read the line and add it to the vector
    while(getline(file, line)){
        vector <string> words = split(line,'|');

        Reservation tempReservation(stoi(words[0]), stoi(words[1]),words[2], stoi(words[3]));
        reservations.push_back(tempReservation);

    }

    file.close(); // Closes file
    return reservations; // Returns the vector
}
void rewrite(int ID, bool mode, int amount){

    // FALSE --> BOOKS
    // TRUE --> MEMBERS

    bool check = true; // Initializing Values

    if(check != mode){

        // Opens the file and Iterates through it
        ofstream outFile("bookList.txt");
        for (int i=0; i < books.size(); i++){

            // Rewrites it back to file, and updates the selected value of the ID
            if(i == ID){

                if(books[i].getQuantity() == 0){
                    outFile << books[i].getID() << "|DELETED BOOK|N.A.|0" << "\n";
                }else {
                    outFile << books[i].getID() + "|" + books[i].getTitle() + "|" + books[i].getAuthor() + "|" + to_string((books[i].getQuantity()) - amount) << "\n";
                }

            }else {
                outFile << books[i].returnBookInfo() << "\n";
            }
        }

        outFile.close(); // Closes the file

    }else {

        // Opens the file and Iterates through it
        ofstream outFile("memberList.txt");
        for (int i=0; i < members.size(); i++){

            // Rewrites it back to file, and updates the selected value of the ID
            if(i == ID){
                outFile << ID+1 <<"|-|-|DELETED|MEMBER|-|0|M" << "\n";
            }else {
                outFile << members[i].returnAccountInfo();
            }
        }
    }

}
void writeFile(const string& line, string fileSource){

    // Opens file and appends the string to it
    fstream file;
    file.open(fileSource, fstream::app);
    if(file.is_open()){
        file << line;
        file.close(); // Closes File
    }

}

// Check Methods
void userInfo(Account User){

    // Initializing Values
    int input = 0;
    bool loop = true;


    do{
        // Prints available options and asks for input
        cout << endl << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "            <= Welcome " + User.getUsername() + "! =>" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| 1 - Show Reservations" << endl;
        cout << "| 2 - Personal Info" << endl;
        cout << "| 3 - Go Back" << endl;
        cout << "|-------------------------------------------|" << endl;
        cin >> input;

        // Validates input and proceeds with the choice
        if(inputCheck(input, 1, 3)){
            switch(input){
                case 1:
                    printBorrowedBooks(userID);
                    pause();
                    loop = true;
                    break;

                case 2:
                    User.printInfo();
                    pause();
                    loop = true;
                    break;

                default:
                    loop = false;
            }
        }

    } while(loop);
    //Prints User Info

}
void changeQuantity(string ID, int Quantity){

    // Opens the File
    ofstream outFile("bookList.txt");

    // Finds the selected book and changes the quantity
    for (int i=0; i < books.size(); i++){

        Book tempBook = books[i];

        if(i == stoi(ID)-1){

            outFile << tempBook.getID() + "|" + tempBook.getTitle() + "|" + tempBook.getAuthor() + "|" + to_string(tempBook.getQuantity() + Quantity)<< "\n";
        }else {
            outFile << tempBook.returnBookInfo() << "\n";
        }
    }

    outFile.close(); // Closes file
}
bool inputCheck(int input, int minBound, int maxBound){

    // Validates user input and returns the status
    if(input <minBound || input > maxBound){
        cout << endl << "**************************" << endl;
        cout << "Please enter a valid input" << endl;
        cout << "**************************" << endl << endl;
        return false;
    }
    return true;
}
Result doesExist(string Title, string Author){

    // Initializing Values
    int count = 0;
    Result tempArray;

    // Checks whether the book exists
    for (auto tempBook : books) {
        if(Title == tempBook.getTitle() && Author == tempBook.getAuthor()){
            count++;
            tempArray.doesExist = true;
            tempArray.id = tempBook.getID(); // ID
            tempArray.quantity = tempBook.getQuantity(); // Quantity
        }
    }

    if(count == 0){
        tempArray.doesExist = false;
        tempArray.id = "1"; // ID
        tempArray.quantity = 0; // Quantity
    }

    return tempArray;

}
string checkUserID(string Username){

    // Iterates through all users to find the ID and returns it
    for (auto & user : userCredentials) {
        if(Username == user.getUsername()){
            return user.getID();
        }
    }
}

// Other Methods
void pause(){

    // Pauses the program by asking user for input
    cout << "Press Enter to continue..."<< endl;
    cin.ignore();
    cin.get();

}
void message(bool mode){

    bool check = true; // Initializes Value

    // Prints out the message
    if(check == mode){
        cout << "|-------------------------------------------|" << endl;
        cout << "| Welcome to the Library Management System! |" << endl;
        cout << "|-------------------------------------------|" << endl;

    } else {
        cout << "|-------------------------------------------|" << endl;
        cout << "|                 Good Bye!                 |" << endl;
        cout << "|-------------------------------------------|" << endl;
    }

}
vector<string> split(string s, char delimiter){

    // Initializes Values
    string token;
    vector<string> words;
    stringstream ss(s);

    // Iterates through the string, and splits it with the delimiter
    while(getline(ss , token , delimiter)){
        words.push_back(token);
    }

    return words; // returns vector
};
