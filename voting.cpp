#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class election
{
       int age;
       char n[10];
       static int A,B,C,N;
   public:
       char id[20];
      void checkAge()
      {
      	char a[3];
   label:cout<<"Enter your age: ";
         cin>>a;
         age=atoi(a);
         if(age<=0||age>150)
         {
         cout<<endl<<"     ---plz enter correct input---"<<endl<<endl;
         goto label;
         }
         if(age>=18)
         {
         cout<<endl<<"    ***you are eligible***"<<endl<<endl;
         }
         else
         {
         cout<<endl<<"    **you are not eligible**"<<endl<<endl;
         goto label;
         }
      }
      void proof()
      {
          cin.ignore();
   label3:cout<<"Re enter your voter id: "<<endl;
          cin>>id;
          
      }
      void myvote()
      {  
         int a;
         cout<<"The election candidate sections are:"<<endl;
         cout<<"1.CSEA"<<endl<<"2.CSEB"<<endl<<"3.CSEC"<<endl<<"4.NOTA"<<endl;
         cout<<endl;
  label1:cout<<"VOTE FOR YOUR FAVOURITE SECTION : ";
         cin>>n;
         a=atoi(n);
         if(a==1)
         {
         cout<<endl<<"   **you have voted for CSEA**"<<endl;
         A=A+1;
         }
         else if(a==2)
         {
         cout<<endl<<"   **you have voted for CSEB**"<<endl;
         B=B+1;
         }
         else if(a==3)
         {
         cout<<endl<<"   **you have voted for CSEC**"<<endl;
         C=C+1;
         }
         else if(a==4)
         {
         cout<<endl<<"  **I didn't like these sections**"<<endl;
         N=N+1;
         }
         else
         {
         cout<<endl<<"    ---plz enter correct input---"<<endl<<endl;
         goto label1;
         }   
      } 
      void result()
      {
          cout<<"The result is: "<<endl;
          cout<<"CSEA got "<<A<<" votes"<<endl;
          cout<<"CSEB got "<<B<<" votes"<<endl;
          cout<<"CSEC got "<<C<<" votes"<<endl;
          cout<<N<<" votes are not used to any section"<<endl;
          cout<<endl<<"    ***WINNER IS****"<<endl;
          (A>B&&A>C&&A>N)?cout<<setw(19)<<right<<"CSEA"<<endl:(B>A&&B>C&&B>N)?cout<<setw(19)<<"CSEB"<<endl:(C>A&&C>B&&C>N)?cout<<setw(19)<<"CSEC"<<endl:cout<<endl<<"            Not decided "<<endl;
      }
};
int election::A;
int election::B;
int election::C;
int election::N;
int main()
{
    election e[100];
    
    cout<<endl<<"*WELCOME TO CSE ELECTION POLL*"<<endl<<endl;
    int i=0;
    static int m=0;
    char b;
      do
      {
             e[i].checkAge();
             char d[20];
             int j;
             cout<<"Enter your voter id"<<endl;
             cin>>d;
             e[i].proof();
              if(strcmp(e[i].id,d)!=0)
              {
               cout<<"    ---plz enter correct id---"<<endl;
               e[i].proof();
               }
               for(j=0;j<i;j++)
               {
                   if(strcmp(e[j].id,d)==0)
                   {
                    cout<<endl<<"     **voter already voted**"<<endl<<endl;
                    goto label;
                   }
                }
               e[i].myvote();
               m=m+1;
        label: cout<<endl<<m<<" members are voted any other voters to vote now:"<<endl;
       label2: cout<<endl<<"if yes enter Y or if no enter N : ";
               cin>>b;
               if(b!='n'&& b!='N'&& b!='Y' && b!='y')
               {
               cout<<endl<<"    plz enter correct input!!!!"<<endl;
               goto label2;
               }
               cout<<endl<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;
               if(b=='n'||b=='N')
                   break;
                i++;
      }while(b=='Y'||b=='y');
      e[m].result();
      return 0;
}
