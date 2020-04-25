#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
fstream file;
class currency
{
	int a,b,c,d,e,f,g,h;
	double sum;
	int m,n,o,p,q,r,s,t;
	public:	
	void getdata()
	{
		cout<<"\nEnter the number of notes : \n\n";
		cout<<"DENOMINAION   NUMBER OF NOTES\n";
		cout<<"      2000  x    "; cin>>a;
		cout<<"        500 x    "; cin>>b;
		cout<<"        200 x    "; cin>>c;
		cout<<"        100 x    "; cin>>d;
		cout<<"         50 x    "; cin>>e;
		cout<<"         20 x    "; cin>>f;
		cout<<"         10 x    "; cin>>g;
		cout<<"      Coins x    "; cin>>h;
	}
	void calculation()
	{
		m=2000*a; n=500*b; o=200*c; p=100*d;
		q=50*e; r=20*f; s=10*g; t=h;
		sum=m+n+o+p+q+r+s+t;
	}
	void putdata()
	{
		cout<<"You Have Entered :\n ";
		cout<<"      2000 x    "; cout<<a; cout<<"  =   "<<m;
		cout<<"\n        500 x    "; cout<<b; cout<<"  =   "<<n;
		cout<<"\n        200 x    "; cout<<c; cout<<"  =   "<<o;
		cout<<"\n        100 x    "; cout<<d; cout<<"  =   "<<p;
		cout<<"\n         50 x    "; cout<<e; cout<<"  =   "<<q;
		cout<<"\n         20 x    "; cout<<f; cout<<"  =   "<<r;
		cout<<"\n         10 x    "; cout<<g; cout<<"  =   "<<s;
		cout<<"\n      Coins x    "; cout<<h; cout<<"  =   "<<t<<endl;
		cout<<"                      --------"<<endl;
		cout<<"               TOTAL  "<<sum<<endl;
		cout<<"                      --------";
	}
	
};
void conti();
int main()
{
	
	currency obj;
	cout<<"\nDo You Want to Load Previous Data Y/N ";
	char ch1; cin>>ch1;
	if(ch1=='Y'||ch1=='y')
	{
		file.open("data.dat",ios::in);
		file.read((char*)&obj,sizeof(obj));
		obj.putdata();
		file.close();
		cout<<"\n Press Enter to continue";
		getch();
		char ch2;
		cout<<"\n Exit Y/N ";
		cin>>ch2;
		if(ch2=='y'||ch2=='Y') return 0;
		else	conti();
	}
	else conti();
	return 0;
}
void conti()
{
	currency cr;
	cr.getdata();
	cout<<"\n	Confirm your Details Y/N ";
	char ch; cin>>ch;
	if(ch=='Y'||ch=='y')
	{
	cr.calculation();
	cr.putdata();
	file.open("data.dat",ios::out);
	file.write((char*)&cr,sizeof(cr));
	file.close();
	cout<<"\n Data Saves to file successfully";
	}
	else {
	system("cls");
	conti();
		}
	getch();
	}
