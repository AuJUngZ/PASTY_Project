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

void MainMenu_Admin(){
    system("cls");
    int Choice;
    cout<<"\t*************************** Admin Menu *****************************\n";
    cout<<"\t\t1.Add & Delete Book\n\t\t2.Issue Book\n\t\t3.Search book\n\t\t4.Back to Menu\n";
    cout<<"\t********************************************************************\n";
    cout<<"\t\tEnter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        int ognChoice;
        bool checkc = true;
        do{
            cout <<"\t*************************** Add & Delete*****************************\n";
            cout<<"\t\t1.Add to Collection\n\t\t2.Delete from Collection\n\t\t3.Back to Admin Main Menu\n";
            cout <<"\t*********************************************************************\n";
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
        BookInfo = delcomma(textline);
        cout << "***************************************************************" << endl;
        cout << "\n";
        cout << "Book Id : " << BookInfo.at(0) << "\t";
        cout << "Book Name : " << BookInfo.at(1) << "\t";
        cout << "Author : " << BookInfo.at(2) << "\t";
        cout << "Quatity : " << BookInfo.at(3) << "\t" << endl;
        cout << "\n";
        cout << "***************************************************************" << endl;
    }
}

void MainMenu_Student(){}
void DeleteBook(){}
void IssueBook(){}
void SearchBook(){}