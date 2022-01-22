#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;

<<<<<<< HEAD
class pasty{
    public:
        string BookName, Auther, Id;
        int Quatity;

    pasty()
       {
           BookName = "NO Book Name";
           Auther = "No Author Name";
           Id = "No Book ID";
           Quatity = 0;
       }
          void Select_role();
          void MainMenu_Student();
          void MainMenu_Admin();
          void SearchBook(int );
          void IssueBook();
          void ReturnBook();
          void PassWord();
          void AddBook();
          void Show_Detail(int );
          void DeleteBook();

};


int main(){
    
=======
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
>>>>>>> 27776b1c7a9c9350029a0cc0150f378f7431ea91
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
<<<<<<< HEAD
void pasty:: PassWord(){
     
}
void pasty:: SearchBook(int N){
    int choice,b,count=0;
    char book[100];
    system("cls");
    ifstream search("Booksdata.txt");
    if(!search)
        {
            cout<<"\n\t\tNo Books\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(N==1)
            MainMenu_Student();
            else
            MainMenu_Admin();
        }
    system("cls");
    cout<<"\n\t\tPlease Choose one option :-\n";
    cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
    cout<<"\n\t\tEnter Your Choice : ";
    cin >> choice;
    if (choice == 1)
    {   
        cout<<"\n\t\tEnter Book's ID : ";
        cin.getline(book,100);
        system("cls");
        while (!search.eof())
        {
          if(BookName[i]=='\0'&&Auther[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        Show_Detail(N);
                        
                }
        }     
    }
     else if(choice==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(book,100);
          system("cls");
          while(!search.eof())
          {
              
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            Show_Detail(N);
                            
                            break;
                }
              
            }
          }
            else 
          {
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             SearchBook(N);
          }
          search.close();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
        if(N==1)
            MainMenu_Student();
        else
            MainMenu_Admin();
}
void Show_Detail(int x){
    cout<<"\n\t\tBook Name : "<<BookName<<endl;
    cout<<"\n\t\tBook's Author Name : "<<Auther<<endl;
    cout<<"\n\t\tBook's Quantity : "<<Quantity<<endl;
    
    if(x==2)
    {   
     cout<<"\n\t\tBook's ID : "<<Id<<endl;
    }
}
=======

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

error is_trivially_destructible

void MainMenu_Student(){}
void DeleteBook(){}
void IssueBook(){}
void SearchBook(){}
>>>>>>> 27776b1c7a9c9350029a0cc0150f378f7431ea91
