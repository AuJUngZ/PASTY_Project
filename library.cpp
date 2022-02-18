#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;

int state,day;

string BookName, Auther, Id;
int Quatity;
string toUpperStr(string );
string printBuildDateTime();
void Select_role();
void MainMenu_Student();
void PassWord();
void MainMenu_Admin();
void AddBook();
vector<string> delcomma(string line);
void ShowBook();
void SearchBook();
void IssueBook();
void ShowIssueList();
void ReturnBook();
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
    char Choice[100];
    do{
        system("cls");
        cout<< "\n\t\t\t  A_____A\n\t\t\t ( O w O )\n\t\t\t/  v   v  \\\n" << "\t\t       *~ welcome ~*\n";
        cout<<"\n\t*********** PASTY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Admin\n\n\t\t3.Close Application\n\n";
        cout<<"\t***********************************************";
        cout<<"\n\t\tEnter your choice : ";
        cin >> Choice;
        
        switch (Choice[0]) {
            case '1':{
                system("cls");
                MainMenu_Student();}
                break;
            case '2':{
                PassWord();
                break;
                }
            case '3':{
                system("cls");
                exit(0);}
                break;
            default:
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
        }
    }while(Choice[0] != '3');
}

void MainMenu_Student()
{
    state = 1;
    system("cls");
    char Choice[100];
    cout<<"\t\t\t\t     /)/)  (\\(\\\n\t\t\t\t   ( . .)  (. . )\n\t\t\t\t   (            )\n\n";
    cout<<"\t*************************** Student Menu *****************************\n";
    cout<<"\n\t\t1.Search Book\n\n\t\t2.Issue Books\n\n\t\t3.Return Book\n\n\t\t4.Back to Menu\n";
    cout<<"\n\t********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> Choice;
    
    switch(Choice[0]){
    case '1':{
        system("cls");
        SearchBook();
        break;
    }case '2':{
        system("cls");
        IssueBook();
        break;
    }case '3':{
        system("cls");
        ReturnBook();
        break;
    }case '4':{
        system("cls");
        Select_role();
        break;
    }default:{
        cout<<"Please enter correct option :(";
        getch();
        system("CLS");
        MainMenu_Student();
     }
    }
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}
void MainMenu_Admin(){
    state = 2;
    system("cls");
    char Choice[100];
    do{
        cout<<"\t\t\t\t     /)/)  (\\(\\\n\t\t\t\t   ( . .)  (. . )\n\t\t\t\t   (            )\n\n";
        cout<<"\t*************************** Admin Menu *******************************\n";
        cout<<"\n\t\t1.Add & Delete Book\n\n\t\t2.Issue Book\n\n\t\t3.Search book\n\n\t\t4.View issue list\n\n\t\t5.Back to menu\n";
        cout<<"\n\t**********************************************************************\n";
        cout<<"\t\tEnter your choice : ";
        cin >> Choice;
        switch (Choice[0]) {
            case '1': {
                system("cls");
                char ognChoice[100];
                bool checkc = true;
                do{
                    cout<<"\t\t\t\t       (\\_/)\n\t\t\t\t       (o.o)\n\t\t\t\t       />\"<\\\n\t\t\t\t       \\___/\n\n";
                    cout <<"\t*************************** Add & Delete*****************************\n";
                    cout<<"\n\t\t1.Add to Collection\n\n\t\t2.Delete from Collection\n\n\t\t3.Back to Admin Main Menu\n";
                    cout <<"\n\t*********************************************************************\n";
                    cout<<"\t\tEnter your choice : ";
                    cin >> ognChoice;
                    switch (ognChoice[0]) {
                        case '1':
                            system("cls");
                            AddBook();
                            break;
                        case '2':
                            system("cls");
                            DeleteBook();
                            break;
                        case '3':
                            system("cls");
                            MainMenu_Admin();
                            break;
                        default:
                            cout<<"Please enter correct option :(";
                            getch();
                            system("CLS");
                            checkc = false;
                    }
                }while (checkc == false);}
                break;
            case '2':{
                system("cls");
                IssueBook();}
                break;
            case '3':{
                system("cls");
                SearchBook();}
                break;
            case '4':{
                system("cls");
                ShowIssueList();}
                break;
            case '5':{
                system("cls");
                Select_role();}
                break;
            default:
                cout << "Invalid command";
                getch();
                system("cls");
        }
    }while(Choice[0] != '4');
}

void AddBook(){
    system("cls");
    cout << "\t\t\t                                .-.\n\t\t\t   (___________________________()6 `-,\n\t\t\t   (   ______________________   /''\"`\n\t\t\t   //\\\\                      //\\\\\n\t\t\t   \"\" \"\"                     \"\" \"\"\n\n";
    cout << "\t************************ Adding Book ***************************" << endl;
    cout << "\n";
    int choice;
    string BookName, Author, Id;
    int Quatity;
    fstream myfile;
    myfile.open("BookList.txt", ios::app);
    if(myfile.is_open()){
        cout << "\tEnter book ID : ";
        cin >> Id;
        cout << "\tEnter book name : ";
        cin >> BookName;
        cout << "\tEnter Author : ";
        cin >> Author;
        cout << "\tEnter quatity of book : ";
        cin >> Quatity;
        myfile << Id << "," << BookName << "," << Author << "," << Quatity << endl;
        myfile.close();
        // {BookId,BookName,Author,Quatity} //
    }
    cout << "\n";
    cout << "\t***************************************************************" << endl;
    cout << "\tYou want to add more book? : Press 1 --> Yes & Press anykey ->> Back to admin menu." << endl;
    cout << "\tEnter your choice : ";
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
    system("cls");
    char choice[100];
    fstream myfile;
    myfile.open("BookList.txt");
    string textline;
    vector<string> BookInfo;
    while(getline(myfile,textline)){
        BookInfo = delcomma(textline);
        cout << "*******************************************************************************" << endl;
        cout << "\n";
        cout << "Book Id : " << BookInfo.at(0) << "\t";
        cout << "Book Name : " << BookInfo.at(1) << "\t";
        cout << "Author : " << BookInfo.at(2) << "\t";
        cout << "Quatity : " << BookInfo.at(3) << "\t" << endl;
        cout << "\n";
        cout << "*******************************************************************************" << endl;
    }
    myfile.close();
    do{
            cout << "\tBack to menu.";
            cout << "\n\tEnter your choice : ";
            cin >> choice;
            switch(choice[0]){
                default:
                    if(state == 1){
                    MainMenu_Student();
                }else if(state == 2){
                    MainMenu_Admin();
                }
        }
    }while(true);
}

void SearchFormBookId(){
    char choice[100];
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
        myfile.close();
        if(check == false){
            cout << "No Books.\n";
            cout << "Press Enter to back to menu.\n";
            getch();
            system("cls");
            SearchBook();
        }
        do{
            cout << "\n\t1.Search again\n";
            cout << "\t2.Back to menu.";
            cout << "\n\tEnter your choice : ";
            cin >> choice;
            switch(choice[0]){
            case '1': 
                SearchBook();
                break;
            case '2':
                if(state == 1){
                    MainMenu_Student();
                }else if(state == 2){
                    MainMenu_Admin();
                }
            }
        }while(choice[0] != '2');
        
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
    char choice[100];
    fstream myfile;
    bool check = false;
    myfile.open("BookList.txt");
    system("cls");
    string BookName;
    cout << "Enter Book Name : ";
    cin.ignore();
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
        myfile.close();
        if(check == false){
            cout << "No Books.\n";
            cout << "Press Enter to back to menu.\n";
            getch();
            system("cls");
            SearchBook();
        }
        do{
            cout << "\n\t1.Search again\n";
            cout << "\t2.Back to menu.";
            cout << "\n\tEnter your choice : ";
            cin >> choice;
            switch(choice[0]){
            case '1': 
                SearchBook();
                break;
            case '2':
                if(state == 1){
                    MainMenu_Student();
                }else if(state == 2){
                    MainMenu_Admin();
                }
            }
        }while(choice[0] != '2');
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
    char choice[100];
    do{
        system("cls");
        cout<<"\t\t\t\t       (\\_/)\n\t\t\t\t       (o.o)\n\t\t\t\t       />\"<\\\n\t\t\t\t       \\___/\n\n";
        cout<<"\t*************************** Search Menu *******************************\n";
        cout << "\n\t\t1.Search from Books ID. \n\n\t\t2.Search from BookName.\n\n\t\t3.All book in library.\n\n\t\t4.Back to Menu\n";
        cout<<"\n\t***********************************************************************\n";
        cout << "\t\tEnter choice : ";
        cin >> choice;
            switch(choice[0]){
                case '1':
                    SearchFormBookId();
                    break;
                case '2':
                    SearchFormBookName();
                    break;
                case '3':
                    show();
                    break;
                case '4':
                    if(state == 1){
                        MainMenu_Student();
                    }else if(state == 2){
                        MainMenu_Admin();
                    }
            }
    }while(choice[0] != '3');
}
//Search

void ReturnBook(){
    string key, name, con;
    int choice,t;
    system("cls");
    cout<<"\t\t\t\t       (\\_/)\n\t\t\t\t       (o.o)\n\t\t\t\t       />\"<\\\n\t\t\t\t       \\___/\n\n";
    cout<<"\t*************************** Return Menu *******************************\n";
    cout << "\n\t\t1.Return From Id\n\n\t\t2.Return Form Name\n\n\t\t3.Back to menu\n";
    cout<<"\n\t***********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> choice;
    switch (choice) {
        case 1:
            system("cls");
            cout << "Please Enter the Id of record you want to return: ";  
            cin >> key;
            cout << "Please Enter your name : ";
            cin.ignore();
            getline(cin,name);
            t = 0;
            break;
        case 2:
            system("cls");
            cout << "Please Enter the name of record you want to return: ";
            cin.ignore();
            getline(cin,key);
            cout << "Please Enter your name : ";
            cin.ignore();
            getline(cin,name);
            t = 1;
            break;
        case 3:
            if(state == 1){
                MainMenu_Student();
            }else if(state == 2){
                MainMenu_Admin();
            }
        default:
            cout << "Invalid command";
            getch();
            system("CLS");
            ReturnBook();
    }
    ifstream myfile("BookList.txt");
    ofstream newfile("NewBookList.txt");
    ofstream ReturnList("ReturnList.txt",ios::app);
    if(myfile.is_open()){
        string z;
        vector<string> v;

        while(getline(myfile,z)){
            v = delcomma(z);
            if(toUpperStr(key) == toUpperStr(v.at(t))){
                newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << stoi(v.at(3))+1 << endl;
                ReturnList << name << "," << v.at(0) << "," << v.at(1) << "," << printBuildDateTime() <<endl;
            }else{
                newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << v.at(3) << endl;
            }
        }
        myfile.close();
        newfile.close();
        ReturnList.close();
        remove("BookList.txt");
        rename("NewBookList.txt", "BookList.txt");
        system("cls");
        cout << "successfully return :D\n" << endl;
        do{
            cout << "Do you have another book to return?(Yes : y || No : n) : ";
            cin  >> con;
            if( con == "y"){
                ReturnBook();
                break;
            }
            else if (con == "n"){
                if(state == 1){
                    MainMenu_Student();
                }else if(state == 2){
                    MainMenu_Admin();
                }
            }
            else{
                cout << "Invalid command";
                getch();
                system("cls");
            }
        } while(true);
    }
}


void DeleteBook(){
    bool check = false,check_state = true;
    int choice;
    system("cls");
    string txtline,key;
    ifstream myfile;
    myfile.open("BookList.txt");
    ofstream newfile;
    newfile.open("newBookList.txt");
    vector<string> info;
    do{
    cout << "\t\t\t                                .-.\n\t\t\t   (___________________________()6 `-,\n\t\t\t   (   ______________________   /''\"`\n\t\t\t   //\\\\                      //\\\\\n\t\t\t   \"\" \"\"                     \"\" \"\"\n\n";
    cout<<"\t*************************** Delete Book *****************************\n";
    cout<<"\n\t\t1.Delete From Id\n\n\t\t2.Delete Form Name\n\n\t\t3.Back to menu\n";
    cout<<"\n\t********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> choice;
    switch(choice){
        case 1:
            system("cls");
            cout << "Please Enter the Id of record you want to delete: ";  
            cin >> key;
            check_state = false;
            break;
        case 2:
            system("cls");
            cout << "Please Enter the name of record you want to delete: ";
            getline(cin,key);
            check_state = false;
            break;
        case 3:
            system("cls");
            if(state == 1){
                MainMenu_Student();
            }else if(state == 2){
                MainMenu_Admin();
            }
        }
    }while(check_state);
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
            cout << "\t\t1.Delete more book \n\t\tPress any other key to back to menu.";
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
            cout << "\t\t1.Delete more book \n\t\tPress any other key to back to menu.";
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
    cout<<"\t\t\t\t       (\\_/)\n\t\t\t\t       (o.o)\n\t\t\t\t       />\"<\\\n\t\t\t\t       \\___/\n\n";
    cout<<"\t*************************** Issue Menu *******************************\n";
    cout << "\n\t\t1.Issue From Id\n\n\t\t2.Issue Form Name\n\n\t\t3.Back to menu\n";
    cout<<"\n\t***********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> choice;
    if(choice == 1){
        system("cls");
        cout << "Please Enter the Id of record you want to issue: ";  
        cin >> key;
        cout << "Please enter How many days will you borrow: ";
        cin >> day;
        cout << "Please Enter your name : ";
        cin.ignore();
        getline(cin,name);
        t = 0;
    }
    else if (choice == 2) {
        system("cls");
        cout << "Please Enter the name of record you want to issue: ";
        cin.ignore();
        getline(cin,key);
        cout << "Please enter How many days will you borrow: ";
        cin >> day;
        cout << "Please Enter your name : ";
        getline(cin,name);
        t = 1;
    } else if (choice == 3) {
        myfile.close();
        newfile.close();
        issuefile.close();
        if(state == 1){
           MainMenu_Student();
        }else if(state == 2){
            MainMenu_Admin();
        }
    } else{
        myfile.close();
        newfile.close();
        issuefile.close();
        cout << "\t\tWrong answer...\n\t\tAuto back to menu Press Enter";
        getch();
        if(state == 1){
           MainMenu_Student();
        }else if(state == 2){
            MainMenu_Admin();
        }
    }
    
    if(myfile.is_open()){
        string z;
        vector<string> v;
        while(getline(myfile,z)){
            v = delcomma(z);
            if(stoi(v.at(3)) != 0){
                if(toUpperStr(key) == toUpperStr(v.at(t))){
                    newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << stoi(v.at(3))-1 << endl;
                    issuefile << name << "," << v.at(0) << "," << v.at(1) << "," << printBuildDateTime() <<","<<day<<endl;
                }else{
                    newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << v.at(3) << endl;
                }
            }else{
                newfile << v.at(0) << "," << v.at(1) << "," << v.at(2) << "," << v.at(3) << endl;
                myfile.close();
                newfile.close();
                issuefile.close();
                remove("BookList.txt");
                rename("NewBookList.txt", "BookList.txt");
                cout << "This book is not enough for issue.\n";
                cout << "Will you continue to issue?(Yes : y || No : n) : ";
                cin  >> con;
                do{
                    if( con == "y"){
                            IssueBook();
                    }
                    else if (con == "n"){
                            if(state == 1){
                                MainMenu_Student();
                            }else if(state == 2){
                                MainMenu_Admin();
                            }
                    }
                    else{
                            cout << "Invalid command";
                    }
                } while(true);
            }
        }
    }
        myfile.close();
        newfile.close();
        issuefile.close();
        remove("BookList.txt");
        rename("NewBookList.txt", "BookList.txt");
        system("cls");
        cout << "successfully issue... have fun :D\n" << endl;
        cout << "You must return the book after "<< day <<" days today.";
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

void ShowIssueList(){
    system("cls");
    char choice[100];
    ifstream myfile;
    myfile.open("IssueList.txt");
    string textline;
    vector<string> IssueListInfo;
    while(getline(myfile,textline)){
        IssueListInfo = delcomma(textline);
        cout << "*******************************************************************************" << endl;
        cout << "\n";
        cout << "Borrower: " << IssueListInfo.at(0) << "\t";
        cout << "Book ID: " << IssueListInfo.at(1) << "\t";
        cout << "Book ID Name: " << IssueListInfo.at(2) << "\t" << "\n\n";
        cout << "Borrowed time : " << IssueListInfo.at(3) << "\t" <<"\n\n";
        cout << "Time to return : "<< IssueListInfo.at(4) <<" day After Borrowed time.\n";
        cout << "\n";
        cout << "*******************************************************************************" << endl;
    }
    myfile.close();
    do{
            cout << "\tBack to menu.";
            cout << "\n\tEnter your choice : ";
            cin >> choice;
            switch(choice[0]){
                default:
                    if(state == 1){
                    MainMenu_Student();
                }else if(state == 2){
                    MainMenu_Admin();
                }
        }
    }while(true);

}
void PassWord(){
    int i=0;
    char ch,st[21],ch1[21]={"KarnlnwZa007"};
    cout << "\n\t\tEnter Password : ";
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            cout<<"*";
            st[i]=ch;
            i++;
        }
    }
    ifstream inf("Password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        MainMenu_Admin();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        Select_role();
    }
}