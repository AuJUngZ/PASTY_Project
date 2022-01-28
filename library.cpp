#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;


string BookName, Auther, Id;
int Quatity;
string toUpperStr(string );
string printBuildDateTime();
void Select_role();
void MainMenu_Student();
void MainMenu_Admin();
void AddBook();
vector<string> delcomma(string line);
void ShowBook();
void SearchBook();
void IssueBook();
void ReturnBook();
void PassWord();
void DeleteBook();

///////////////////////////
int main(){
    Select_role();
}
//////////////////////////

string printBuildDateTime () {
    string x = __TIMESTAMP__;
    return x;
}

void Select_role(){
    system("cls");
    int Choice;
    cout<<"\n\t*********** PASTY MANAGEMENT SYSTEM ***********\n";
    cout<<"\n\t\t>>Please Choose Any Option To login \n";
    cout<<"\n\t\t1.Student\n\n\t\t2.Admin\n\n\t\t3.Close Application\n\n";
    cout<<"\t***********************************************";
    cout<<"\n\t\tEnter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        MainMenu_Student();
    }else if(Choice == 2){
        system("cls");
        MainMenu_Admin();
    }else if(Choice == 3){
        exit(0);
    }else{
        cout<<"\n\t\tPlease enter correct option :(";
        cin.get();
        system("CLS");
        Select_role();
    }
}

void MainMenu_Student()
{
    system("cls");
    int Choice;
    cout<<"\t*************************** Student Menu *****************************\n";
    cout<<"\n\t\t1.Search Book\n\n\t\t2.Issue Books\n\n\t\t3.Return Book\n\n\t\t4.Back to Menu\n";
    cout<<"\n\t********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        SearchBook();
    }else if(Choice == 2){
        system("cls");
        IssueBook();
    }else if(Choice == 3){
        system("cls");
        ReturnBook();
    }else if(Choice == 4){
        system("cls");
        Select_role();
    }else{
        cout<<"Please enter correct option :(";
        getch();
        system("CLS");
        MainMenu_Student();
    }
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}
void MainMenu_Admin(){
    system("cls");
    int Choice;
    cout<<"\t*************************** Admin Menu *******************************\n";
    cout<<"\n\t\t1.Add & Delete Book\n\n\t\t2.Issue Book\n\n\t\t3.Search book\n\n\t\t4.Back to Menu\n";
    cout<<"\n\t**********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        int ognChoice;
        bool checkc = true;
        do{
            cout <<"\t*************************** Add & Delete*****************************\n";
            cout<<"\n\t\t1.Add to Collection\n\n\t\t2.Delete from Collection\n\n\t\t3.Back to Admin Main Menu\n";
            cout <<"\n\t*********************************************************************\n";
            cout<<"\t\tEnter your choice : ";
            cin >> ognChoice;
       
            if(ognChoice == 1) AddBook();
            else if(ognChoice == 2){
                system("cls");
                DeleteBook();
            }
            else if(ognChoice == 3){
                system("cls");
                MainMenu_Admin();
            }
            else {
                cout<<"Please enter correct option :(";
                getch();
                system("CLS");
                checkc = false;
            }
        }while (checkc == false);
        
    }else if(Choice == 2){
        system("cls");
        IssueBook();
    }else if(Choice == 3){
        system("cls");
        SearchBook();
    }else if(Choice == 4){
        system("cls");
        Select_role();
    }else{
        cout<<"Please enter correct option :(";
        getch();
        system("CLS");
        MainMenu_Admin();
    }
}

void AddBook(){
    cout << "************************ Adding Book ***************************" << endl;
    cout << "\n";
    int choice;
    string BookName, Author, Id;
    int Quatity;
    fstream myfile;
    myfile.open("BookList.txt", ios::app);
    if(myfile.is_open()){
        cout << "Enter book ID : ";
        cin >> Id;
        cout << "Enter book name : ";
        cin >> BookName;
        cout << "Enter Author : ";
        cin >> Author;
        cout << "Enter quatity of book : ";
        cin >> Quatity;
        myfile << Id << "," << BookName << "," << Author << "," << Quatity << endl;
        myfile.close();
        // {BookId,BookName,Author,Quatity} //
    }
    cout << "\n";
    cout << "***************************************************************" << endl;
    cout << "You want to add more book? : Press 1 --> Yes & Press anykey ->> Back to admin menu." << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    if(choice == 1){
        system("cls");
        AddBook();
    }else{
        cin.get();
        MainMenu_Admin();
    }

}

vector<string> delcomma(string line){
		vector<string> result;
		stringstream s_stream(line);

		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}
		return result;
}


void show(){
    fstream myfile;
    myfile.open("BookList.txt");
    string textline;
    vector<string> BookInfo;
    while(getline(myfile,textline)){
        cout << "*******************************************************************************" << endl;
        cout << "\n";
        cout << "Book Id : " << BookInfo.at(0) << "\t";
        cout << "Book Name : " << BookInfo.at(1) << "\t";
        cout << "Author : " << BookInfo.at(2) << "\t";
        cout << "Quatity : " << BookInfo.at(3) << "\t" << endl;
        cout << "\n";
        cout << "*******************************************************************************" << endl;
    }
}

void SearchFormBookId(){
    int choice;
    fstream myfile;
    myfile.open("BookList.txt");
    bool check = false;
    system("cls");
    string BookId;   
    cout << "Enter BookId : ";
    cin >> BookId;
    BookId = toUpperStr(BookId);
    if(myfile.is_open()){
        string text;
        vector<string> BookInFo;
        while (getline(myfile,text))
        {
            BookInFo = delcomma(text);
            if(BookId==toUpperStr(BookInFo.at(0))){
                cout << "***********************************************************************************" << endl;
                cout << "\n";
                cout << "Book Id : " << BookInFo.at(0) << "\t";
                cout << "Book Name : " << BookInFo.at(1) << "\t";
                cout << "Author : " << BookInFo.at(2) << "\t";
                cout << "Quatity : " << BookInFo.at(3) << "\t" << endl;
                cout << "\n";
                cout << "***********************************************************************************" << endl;
                check = true;
            }
        }
        if(check == false){
            cout << "No Books.\n";
            cout << "Press Enter to back to menu.\n";
            getch();
            system("cls");
            SearchBook();
        }
        cout << "1.Search again\n";
        cout << "Press any key to back to menu.";
        cout << "\nEnter your choice : ";
        cin >> choice;
        system("cls");
        if(choice == 1) SearchBook();
        else MainMenu_Student();
        
    }else{
        cout << "File not found.\n";
        cout << "Press Enter to back to menu.\n";
        getch();
        system("cls");
        SearchBook();
    }
    myfile.close();
}

void SearchFormBookName(){
    int choice;
    fstream myfile;
    bool check = false;
    myfile.open("BookList.txt");
    system("cls");
    string BookName;
    cout << "Enter Book Name : ";
    getline(cin,BookName) ;
    BookName = toUpperStr(BookName);
    if(myfile.is_open()){
        string textline;
        vector<string> BookInFo;
        while(getline(myfile,textline)){
            BookInFo = delcomma(textline);
            if(BookName == toUpperStr(BookInFo.at(1))){
                cout << "***********************************************************************************" << endl;
                cout << "\n";
                cout << "Book Id : " << BookInFo.at(0) << "\t";
                cout << "Book Name : " << BookInFo.at(1) << "\t";
                cout << "Author : " << BookInFo.at(2) << "\t";
                cout << "Quatity : " << BookInFo.at(3) << "\t" << endl;
                cout << "\n";
                cout << "***********************************************************************************" << endl;
                check = true;
             }
            }
            if(check == false){
            cout << "No Books.\n";
            cout << "Press Enter to back to menu.\n";
            getch();
            system("cls");
            SearchBook();
        }
        cout << "1.Search again\n";
        cout << "Press any key to back to menu.";
        cout << "\nEnter your choice : ";
        cin >> choice;
        system("cls");
        if(choice == 1) SearchBook();
        else MainMenu_Student();
    }else{
        cout << "File not found.\n";
        cout << "Press Enter to back to menu.\n";
        getch();
        system("cls");
        SearchBook();
    }
    myfile.close();
}

void SearchBook(){
    fstream myfile("BookList.txt");
    int choice;
    cout<<"\t*************************** Search Menu *******************************\n";
    cout << "\n\t\t1.Search from Books ID \n\n\t\t2.Search from BookName\n\n\t\t";
    cout<<"\n\t***********************************************************************\n";
    cout << "\t\tEnter choice : ";
    cin >> choice;
    
        if(choice == 1){
            SearchFormBookId();
        } else if(choice == 2) {
            SearchFormBookName();
        } else {
            cout<<"Please enter correct option :(";
                getch();
                system("CLS");
                SearchBook();
        }
}
//Search
void ReturnBook(){}
void DeleteBook(){
    bool check = false;
    int choice;
    system("cls");
    string txtline,key;
    ifstream myfile;
    myfile.open("BookList.txt");
    ofstream newfile;
    newfile.open("newBookList.txt");
    vector<string> info;
    cout << "1.Delete From Id\n2.Delete Form Name\nEnter your choice : ";
    cin >> choice;
    if(choice == 1){
        cout << "Please Enter the Id of record you want to delete: ";  
        cin >> key;
    }
    else if (choice == 2) {
        cout << "Please Enter the name of record you want to delete: ";
        getline(cin,key);
    }
    if(myfile.is_open()){
        int t;
        while(getline(myfile,txtline)){
            if(choice == 1){
                 t = 0;
            }else if(choice == 2){
                 t = 1;
            }
            info = delcomma(txtline);
            if(key != info.at(t) ){
                newfile << txtline << endl;
            }else if(key == info.at(t) ){
                check = true;
            }
        }
        if(check == true){
            myfile.close();
            newfile.close();
            remove("BookList.txt");
            rename("newBookList.txt", "BookList.txt");
            system("cls");
            cout<<"\t***************************** Status *******************************\n";
            cout << "\n\tThe record with the name " << key << " has been deleted if it exsisted" << endl;
            cout<<"\n\n\t*************************** Delete Menu ****************************\n\n";
            cout << "\t\t1.Delete more book \n\t\tPress any key to back to menu.";
            cout << "\n\t\tEnter choice : ";
            cin >> choice;
            if(choice == 1) DeleteBook();
            else MainMenu_Admin();
        }else{
            myfile.close();
            newfile.close();
            remove("BookList.txt");
            rename("newBookList.txt", "BookList.txt");
            system("cls");
            cout<<"\t***************************** Status *******************************\n\n";
            cout << "\t\tNo book match with  " << key << endl;
            cout<<"\n\t*************************** Delete Menu ****************************\n\n";
            cout << "\t\t1.Delete more book \n\t\tPress any key to back to menu.";
            cout << "\n\t\tEnter choice : ";
            cin >> choice;
            if(choice == 1) DeleteBook();
            else MainMenu_Admin();
        }
    }
}
void IssueBook(){
    ifstream myfile("BookList.txt");
    ofstream newfile("NewBookList.txt");
    ofstream issuefile("IssueList.txt",ios::app);
    string key, name, con;
    int choice,t;
    system("cls");
    cout << "1.Issue From Id\n2.Issue Form Name\nEnter your choice : ";
    
    cin >> choice;
    if(choice == 1){
        cout << "Please Enter the Id of record you want to issue: ";  
        cin >> key;
        cout << "Please Enter your name : ";
        cin.ignore();
        getline(cin,name);
        t = 0;
    }
    else if (choice == 2) {
        cout << "Please Enter the name of record you want to issue: ";
        getline(cin,key);
        cout << "Please Enter your name : ";
        cin.ignore();
        getline(cin,name);
        t = 1;
    }
    if(myfile.is_open()){
        string z;
        vector<string> v;

        while(getline(myfile,z)){
            v = delcomma(z);
            if(toUpperStr(key) == toUpperStr(v.at(t))){
                newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << stoi(v.at(3))-1 << endl;
                issuefile << name << "," << v.at(0) << "," << v.at(1) << "," << printBuildDateTime() <<endl;
            }else{
                newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << v.at(3) << endl;
            }
        }
        myfile.close();
        newfile.close();
        issuefile.close();
        remove("BookList.txt");
        rename("NewBookList.txt", "BookList.txt");
        system("cls");
        cout << "successfully issue... have fun :D\n" << endl;
        cout << "Will you continue to issue?(Yes : y || No : n) : ";
        cin  >> con;
        do{
            if( con == "y"){
                IssueBook();
            }
            else if (con == "n"){
                Select_role();
            }
            else{
                cout << "Invalid command";
            }
        } while(true);
    }
}

