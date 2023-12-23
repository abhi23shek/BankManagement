#include<string.h>
#include<fstream>
#include<ctype.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<process.h>

using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	int gc;
	char type;
public:

	void giftcard(int n)
	{
	gc=gc-n;
	cout<<"\n\nsucessfully withdrawn";
	}




	account()
	{gc=0;}

	void getdata()

	{

	cout<<"                 CREATE NEW ACCOUNT\n\n\n";
	char ch;
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin>>name;
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);

	cout<<"\nDo you Want Gift cards (y/n)";
	cin>>ch;
	if(ch=='y')
	gc=5000;
	else
	gc=0;

	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";

	cin>>deposit;


	//getch();
	}




	void showdata()

	{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\nBalance in gift card: "<<gc;

	}



	void modify()

	{
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	scanf(name);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The amount : ";
	cin>>deposit;
	}

	void dep(int x)
	{
	deposit+=x;
	}

	void draw(int x)
	{
	deposit-=x;
	}


	void report()

	{
	cout<<acno<<setw(10)<<" "<<name<<setw(12)<<" "<<type<<setw(20)<<deposit<<setw(10)<<gc<<endl;
	}


	int retacno()

	{
	return acno;
	}


	int retdeposit()

	{
	return deposit;
	}

	char rettype()

	{
	return type;
	}

	int retgift()
	{
	return gc;
	}


}ac;



void write()
{


	int flag=0, n=0;
	account ac1;
	ifstream ifile;
	ifile.open("account.dat");
	while(ifile.read((char*)&ac1,sizeof(ac1)))
	{
	n=ifile.tellg();
	}
	n=n/sizeof(ac);
	ifile.close();
	ac.getdata();
	int a=ac.retacno();
	ifile.open("account.dat");
	while(ifile.read((char*)&ac1,sizeof(ac1)))
	{
	if(a==ac1.retacno())
	{
	system("cls");
	cout<<"\n\nAccount Number already exists";
	cout<<"\nPlease Try Again With Different Account Number\n\n";
	write();
	}
	flag++;
	}
	ifile.close();
	if(flag==n)
	{
	ofstream ofile;
	ofile.open("account.dat",ios::app);
	ofile.seekp(0,ios::end);
	ofile.write((char*)&ac,sizeof(ac));
	ofile.close();
	cout<<"\n\n\nAccount Created..";
	}
}




void display(int n)
{

	int flag=0;
	ifstream ifile;
	ifile.open("account.dat");

	cout<<"\nBALANCE DETAILS\n";
    while(ifile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.showdata();
			flag=1;
		}
	}
    ifile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";

getch();
}






void modify(int n)
{


ifstream ifile;
ifile.open("account.dat");

while(ifile.read((char*)&ac,sizeof(ac)))
{

	if(n==ac.retacno())
		{ac.modify();}
	ofstream ofile;
	ofile.open("temp.dat",ios::app);

	ofile.write((char*)&ac,sizeof(ac));


}
remove("account.dat");
rename("temp.dat","account.dat");


ifile.close();

}





void del(int n)

{
ifstream ifile;
ifile.open("account.dat");



while(ifile.read((char*)&ac,sizeof(ac)))
{


	if(n==ac.retacno())
	{cout<<"\nsuccesfully Deleted\n";}
	else
	{
	ofstream ofile;
	ofile.open("temp.dat",ios::app);

	ofile.write((char*)&ac,sizeof(ac));
	}

}
remove("account.dat");
rename("temp.dat","account.dat");


ifile.close();
getch();
}






void alldisplay()
{

	ifstream ifile;
	ifile.open("account.dat");

	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

	cout<<"A/c no.      NAME           Type           Balance     Amount left in gift card \n\n";

	while(ifile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	ifile.close();
	getch();
}


void dep_draw(int n, int o)
{
	int amt;
ifstream ifile;
ifile.open("account.dat");

while(ifile.read((char*)&ac,sizeof(ac)))
{



	if(ac.retacno()==n)
	{
		ac.showdata();
		if(o==1)
		{
			cout<<"\n\nTO DEPOSIT AMOUNT ";
			cout<<"\n\nEnter The amount to be deposited";
			cin>>amt;
			ac.dep(amt);

		}
		if(o==2)
		{
			cout<<"\n\nTO WITHDRAW AMOUNT ";
			cout<<"\n\nEnter The amount to be withdraw";
			cin>>amt;
			int bal=ac.retdeposit()-amt;
			if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		}

		if(o==3)
		{
		cout<<"\n\nTO USE GIFT CARD";
			cout<<"\n\nEnter The amount to be withdrawn from gift card";
			int amt;
			cin>>amt;
			if(ac.retgift()<amt)
					{cout<<"Insufficience balance in the gift card";  }

				else
					ac.giftcard(amt);
		  }




		cout<<"\n\n\t Record Updated";

		}
		ofstream ofile;
		ofile.open("temp.dat",ios::app);
		ofile.write((char*)&ac,sizeof(ac));




getch();

}

remove("account.dat");
rename("temp.dat","account.dat");


}





void intro()
{
	cout<<"\n\n\n                          BANK MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n             MADE BY : Abhishek Kumar";
	cout<<"\n\n             CLASS : 12th D";
	cout<<"\n\n             SCHOOL : Delhi Public School, Dwarka";
	getch();
}


int main()
{

	int num,ch=0,i;
	char p[20],k,m[]="abhishek", n;
	system("cls");

	do
	{
	system("cls");
	cout<<"Enter password:";

	for(i=0;i<8;i++)
	{
	k=getch();
	cout<<"*";
	p[i]=k;
	}
	p[8]='\0';

	if(strcmp(p,m)==0)
	{
	cout<<"\nCORRECT PASSWORD!";

	n='n';
	getch();
	system("cls");
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n                          MAIN MENU";
		cout<<"\n\n1 NEW ACCOUNT";
		cout<<"\n\n2 DEPOSIT AMOUNT";
		cout<<"\n\n3 WITHDRAW AMOUNT";
		cout<<"\n\n4 BALANCE ENQUIRY";
		cout<<"\n\n5 ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n6 CLOSE AN ACCOUNT";
		cout<<"\n\n7 MODIFY AN ACCOUNT";
		cout<<"\n\n8 CLEAR ALL DATA";
		cout<<"\n\n9 EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;

		system("cls");

		switch(ch)
		{
		case 1:
			write();
			break;


		case 2:

			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			dep_draw(num, 1);
			break;


		case 3: cout<<"\n\nEnter the source of withdrawal :";
			cout<<"\n\n1 From account balance";
			cout<<"\n\n2 Use gift card";
			int t;
			cin>>t;
			if(t==1)
		       {cout<<"\n\n\tEnter The account No. : "; cin>>num;
			dep_draw(num, 2);      }
			if(t==2)
			{cout<<"\n\n\tEnter The account No. : "; cin>>num;
			dep_draw(num, 3);  }

			break;



		case 4:
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			display(num);
			break;

		case 5:
			alldisplay();
			break;

		case 6: cout<<"\n\nCLOSE AN ACCOUNT\n\n";
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			del(num);
			break;

		case 7:
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			modify(num);
			break;

		case 8:
			 cout<<"\nAre you sure you want to clear all the data(y/n)";
			 char a;
			 cin>>a;
			 if(a=='y')
			 remove("account.dat");
			 break;

		case 9:

			cout<<"\n\n\tThanks for using bank managemnt system";

			break;

		default :cout<<"invalid input";
		}




    }while(ch!=9);

   }

else
       {cout<<"\n\nYou Entered A wrong Password\n\n";
	cout<<"Would you like to retry(y/n)";
	cin>>n; }

}while(n!='n');

getch();
return 0;
}
