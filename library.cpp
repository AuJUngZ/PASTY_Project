#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

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
          void SearchBook();
          void IssueBook();
          void ReturnBook();
          void PassWord();
          void AddBook();
          void DeleteBook();

};


int main(){

}

    /*วิธีสร้าง Function*/
//////////////////////////
/*
void pasty:: ชื่อFunctions(){

}
*/
//////////////////////////

void pasty:: Select_role(){
    int Choice;
    cout<<"\n\t*********** PASTY MANAGEMENT SYSTEM ***********\n";
    cout<<"\n\t\t>>Please Choose Any Option To login \n";
    cout<<"\n\t\t1.Student\n\n\t\t2.Admin\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        MainMenu_Student()
    }else if(Choice == 2){
        system("cls");
        MainMenu_Admin()
    }else if(Choice == 3){
        exit(0);
    }else{
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("CLS");
        Select_role();
    }
}

void pasty:: MainMenu_Admin(){
    int Choice;
    cout<<"Admin Menu\n";
    cout<<"1.Organize Collection\n2.Edit Circulation Status\n3.Search from Catolog\n4.Back to Login page\n";
    cout<<"Enter your choice : ";
    cin >> Choice;
    
    if(Choice == 1){
        system("cls");
        int ognChoice;
        bool checkc = true;
        do{
            cout<<"Organize Collection\n";
            cout<<"1.Add to Collection\n2.Delete from Collection\n3.Back to Admin Main Menu\n";
            cout<<"Enter your choice : ";
            cin >> ognChoice;
       
            if(Choice == 1) AddBook();
            else if(Choice == 2) DeleteBook();
            else if(Choice == 3) MainMenu_Admin();
            else {
                cout<<"Please enter correct option :(";
                getch();
                system("CLS");
                checkc = false;
            }
        }while (checkc = false);
        
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