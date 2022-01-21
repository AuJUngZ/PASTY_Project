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
    //edit
}

etesttestesteste