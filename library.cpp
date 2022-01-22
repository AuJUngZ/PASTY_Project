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
          void SearchBook(int );
          void IssueBook();
          void ReturnBook();
          void PassWord();
          void AddBook();
          void Show_Detail(int );
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
        MainMenu_Student();
    }else if(Choice == 2){
        system("cls");
        MainMenu_Admin();
    }else if(Choice == 3){
        exit(0);
    }else{
        cout<<"\n\t\tPlease enter correct option :(";
        getch();
        system("CLS");
        Select_role();
    }
}
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
