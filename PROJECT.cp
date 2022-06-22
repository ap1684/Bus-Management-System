#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
class transport
{
int nostud,distance,fare,earning,busno,total;
char drivername[30],route[20];

public:

int getbusno()
{
 return busno;
}
char* getroute()
{
return route;
}
void ask()
{
cout<<"\nEnter the bus number = ";
cin>>busno;
cout<<"\nDriver name = ";
gets(drivername);
cout<<"\nEnter the route of new bus = ";
gets(route);
cout<<"\nEnter the total capacity of the bus =";
cin>>total;
cout<<"\nEnter the number of students travel = ";
cin>>nostud;
cout<<"\nEnter the distance of route = ";
cin>>distance;
}
void charge()
{
if(distance<=10)
fare=100;
else if(distance<=20&&distance>10)
fare=200;
else if(distance<=30&&distance>20)
fare=300;
else if(distance<=40&&distance>30)
fare=400;
else if(distance<=50&&distance>40)
fare=500;
else if(distance>50)
fare=600;
}
void output()
{
cout<<"\n\t\tTHE ENTIRE DETAIL OF DESIRED BUS IS =>";
cout<<"\n\nBus number = "<<busno;
delay(100);
cout<<"\nDriver name = "<<drivername;
delay(100);
cout<<"\nRoute = "<<route;
delay(100);
cout<<"\nThe capacity of bus ="<<total;
delay(100);
cout<<"\nNumber of students in the bus = "<<nostud;
delay(100);
cout<<"\nDistance of the route = "<<distance;
charge();
earning=nostud*fare;
delay(100);
cout<<"\nEarning of bus = "<<earning;
}
};
void save()
{
ofstream file("transport.dat",ios::app|ios::binary);
transport t;
t.ask();
file.write((char*)&t,sizeof(t));
clrscr();
delay(1000);
t.output();
file.close();
}

void search(int busno)
{
int f=0;
transport t;
ifstream file("transport.dat",ios::in|ios::binary);
while(!file.eof())
{
file.read((char*)&t,sizeof(t));
if(t.getbusno()==busno)
{
f=1;
clrscr();
delay(1000);
t.output();
break;
}
if(f==0)
clrscr();
cout<<"\nSORRY.....!";
cout<<"\n\nBus number not found!!";
}
}

void searchto(char route[])
{
int f=0;
transport t;
ifstream file("transport.dat",ios::in|ios::binary);
while(!file.eof())
{
file.read((char*)&t,sizeof(t));
if(strcmpi(t.getroute(),route)==0)
{
f=1;
clrscr();
delay(1000);
t.output();
break;
}
if(f==0)
clrscr();
cout<<"\nSORRY.....!";
cout<<"\n\nRoute of bus not found!!";
}
}
void udf()
{
clrscr();
cout<<"\n________________________________________________________________________________";
cout<<"\n:::::::::::::::::::::::::::::::: PROJECT ::::::::::::::::::::::::::::::::::::::";
cout<<"\n\n::::::::::::::::::::::::::::::::::: ON :::::::::::::::::::::::::::::::::::::::::";
cout<<"\n:::::::::::::::::::::::: TRANSPORT MANAGEMENT SYSTEM :::::::::::::::::::::::::::";
cout<<"________________________________________________________________________________";
cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
cout<<"\NOTE-To proceed the program please select one of the option->";
cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
cout<<"\n\t     *||* FOR SELECTING ANY OPTION PRESS(1,2,3 OR 4) *||*";
cout<<"\n\n\n\n\t\t\tFor watching the options"<<endl<<"\n\n\t\t\t     Please enter!!!";
getch();
clrscr();
cout<<"\n\t\t\t\tMAIN MENU";
cout<<"\n\t\t\t\t---------";
cout<<"\n\t     SELECT ONE OF THE OPTION TO CONTINUE THE PROGRAM =>";
cout<<"\n\n\n1)-Do you want to add record of new bus=>";
cout<<"\n\n2)-Do want to search details  of bus (by bus number)=>";
cout<<"\n\n3)-Do want to search details of bus (by route)=>";
cout<<"\n\n4)-Do want to exit from the program=>";
}

void main()
{
clrscr();
int ch=1;
do
{
udf();
cout<<"\n\n";
cin>>ch;
if(ch==1)
{
save();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t"<<"   "<<"!!Press Enter To Continue!!";
getch();
}
else if(ch==2)
{
int busno;
clrscr();
cout<<"\n\t\tTHE LIST OF AVAILABLE BUS NUMBERS IS FOLLOWING =>";
cout<<"\n\n\t\t(NOTE-to select any bus number enter{1,2 to 10})";
cout<<"\n\n->BUS NUMBER-1\n->BUS NUMBER-2\n->BUS NUMBER-3\n->BUS NUMBER-4\n->BUS NUMBER-5\n->BUS NUMBER-6\n->BUS NUMBER-7\n->BUS NUMBER-8\n->BUS NUMBER-9\n->BUS NUMBER-10";
cout<<"\n\n\nEnter the bus number = ";
cin>>busno;
search(busno);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t"<<"   "<<"!!Press Enter To Continue!!";
getch();
}

else if(ch==3)
{
char route[20];
clrscr();
cout<<"\n\t        THE LIST OF ROUTES AVAILABLE IS FOLLOWING =>";
cout<<"\n\n\t(NOTE-To search the record write the name of route as written)";
cout<<"\n\n->rajendra nagar\n->civil lines\n->madhi nath\n->chaupla\n->chauki chauraha\n->green park\n->tulip tower\n->mahanagar\n->subhash nagar\n->rampur garden";
cout<<"\n\n\nEnter the route = ";
gets(route);
searchto(route);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t"<<"   "<<"!!Press Enter To Continue!!";
getch();
}
}while(ch!=4);
getch();
}



















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































