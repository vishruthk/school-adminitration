#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
int avj=0;
class school               //class school
{
  public:
	 char name[30],dob[20],bg[6],address[40];
	 char father[30],mother[30],foccu[50],moccu[50],messopt,transopt,slap;
	 long int admno,tele,income,clas,mark[8],total,tutfee;
	 long int messfee,specfee,transfee,fee,caution,age,phone,nut,rollno;
	 float percent;
	 void newadmn();
	 void academics();
	 void mess();
	 void academics1();
	 void fees1();
	 void disdata();
	 void display();
	 int getno();
}ob;

void school::newadmn()            //for inserting new admission
{
	clrscr();
	do
	{
		 cout<<"\n\nEnter the following:\n";
		 cout<<" Student Name            : ";gets(name);
		 cout<<" roll no                 : ";cin>>rollno;
		 cout<<" D.O.B                   : ";gets(dob);
		 cout<<" Father's Name           : ";gets(father);
		 cout<<" Mother's Name           : ";gets(mother);
		 cout<<" Father's occupation     : ";gets(foccu);
		 cout<<" Mother's occupation     : ";gets(moccu);
		 cout<<" Class to  be promoted to: ";cin>>clas;
		 academics1();
		 cout<<" Resedential Address     : ";gets(address);
		 cout<<" Telephone No.           : ";cin>>tele;
		 cout<<" Blood Group             : ";gets(bg);
		 cout<<" Annual Income           : ";cin>>income;
		 cout<<" Whether Availing\n";
		 cout<<" -> Mess (Y/N)           : ";cin>>messopt;
		 fees1();
		 avj++;
		 cout<<"\nDo You Want to add more students(Y/N): ";cin>>slap;
	}while(slap=='Y'||slap=='y');
}

void school::display()                //display function
{
	 cout<<"\n Name                    : "<<name;
	 cout<<"\n Roll no                 : "<<rollno;
	 cout<<"\n D.O.B                   : "<<dob;
	 cout<<"\n Father's Name           : "<<father;
	 cout<<"\n Mother's Name           : "<<mother;
	 cout<<"\n Father's occupation     : "<<foccu;
	 cout<<"\n Mother's occupation     : "<<moccu;
	 cout<<"\n Class to  be promoted to: "<<clas;
	 cout<<"\n Resedential Address     : "<<address;
	 cout<<"\n Telephone No.           : "<<tele;
	 cout<<"\n Blood Group             : "<<bg;
	 cout<<"\n Annual Income           : "<<income;
	 cout<<"\n Availing mess           : "<<messopt;
}

int school::getno()
{
	return rollno;
}

void school::academics1()            //entering marks from class and finding its total and percentage
{
	int nos;
	if(clas<6)
		 nos=8;
	else if(clas<=10)
		 nos=6;
	else if(clas<=12)
		 nos=5;
	else
		 {cout<<"Incorrect!!";}
	cout<<"\t\tEnter the following: \n";
	total=0;
	for(int j=0;j<nos;j++)
	{
		cout<<" Mark_"<<j+1<<": ";
		cin>>ob.mark[j];
		total+=ob.mark[j];
	 }
	 percent=total/nos;
}



void school::fees1()     //class-school,fee1 for calculating fee
{
	clrscr();
	caution=3000;
	if(clas<6)
	{
		 tutfee=2500;
		 messfee=500;
		 specfee=1000;
	}
	else if(clas<11)
	{
		 tutfee=5000;
		 specfee=2000;
	}
	else if(clas>10 && clas<13)
	{
		 tutfee=7000;
		 specfee=2500;
	}
	if(messopt=='y'|| messopt=='Y')
	{
		if(clas<11 && clas>5)
			 {messfee=7000;}
		 else if(clas>10)
			 {messfee=1000;}
	}
	fee=tutfee+specfee+caution+messfee;

	cout<<"\nFees: Rs."<<fee<<" /-";

}

class Faculty               //class faculty for faculty option
{
public :
	long int age,phone,nut;
	char sub[20];
	char facname[20],qual[10],faladdress[30],subject[20],clshand[20];
	void getdata();
	void department();
}f[100];

void Faculty::getdata()
{
	cout<<"Enter Details Of Faculties "<<endl;
	cout<<"Enter Name           :"<<endl;
	gets(facname);
	cout<<"Enter  Qualification :"<<endl;
	gets(qual);
	cout<<"Enter Faculty Address:"<<endl;
	gets(faladdress);
	cout<<"Enter Subject        :"<<endl;
	gets(subject);
	cout<<"Enter class Handling :"<<endl;
	gets(clshand);
	cout<<"Enter Age            :"<<endl;
	cin>>age;
	cout<<"Enter Phone Number   :"<<endl;
	cin>>phone;
}


void Faculty::department()
{
	puts(facname);
}

void school::disdata()
{
	cout<<moccu;
	cout<<name;
	cout<<dob;
	cout<<mother;
	cout<<father;
	cout<<foccu;
	cout<<moccu<<"dddd";
}

void main()
{
	clrscr();
	 fstream file("school1.dat",ios::binary|ios::in|ios::out|ios::app);
	 char option,sname[30],con,con1;
	 int srstd,b;
	 do
	 {
		 clrscr();
		 cout<<"\n<|---------------------------* School Management *----------------------------|>";
		 cout<<"\n\n1. New Admission\n";    //done
		 cout<<"2. Student Details\n";
		 cout<<"3. Academics\n";
		 cout<<"4. Faculty\n";              //done
		 cout<<"5. Fees\n";                 //done
		 cout<<"6. Transportation\n";
		 cout<<"7. Mess\n";
		 cout<<"8. Hostel\n";
		 cout<<"9. exit";
		 cout<<"\n\nEnter Option :";
		 cin>>option;
		 switch(option)
		 {
			case '1':ob.newadmn();                    //case for new admission
				 file.write((char*)&ob,sizeof(school));
				 break;
			case '2':do
				 {
				    clrscr();                        //case for student details
				    cout<<"\n1.Search Student details          ";
				    cout<<"\n2.display all";
				    cin>>srstd;
				    switch(srstd)
				    {
				      case 1:ifstream op("school1.dat",ios::binary|ios::in);
					     cout<<"enter the search no."<<endl;
					     cin>>b;
					     while(!op.eof())
					     {
						  op.read((char*)&ob,sizeof(school));
						  if(b==ob.getno())
						  {
							  ob.display();
						  }
					     }
					     op.close();
					     break;
				      case 2:int i=0;
					     ifstream op1("school1.dat",ios::in,ios::out);
					     while(!op1.eof())
					     {
						op1.read((char*)&ob,sizeof(school));
						ob.display();
						i++;
					     }
					     break;
				      default:cout<<"sorry invalid entry";
				    }
				    cout<<"do you want to continue(y/n)";
				    cin>>con1;
				 }while(con1=='y'|| con1=='Y');
				 break;

			case '4':clrscr();           //case for faculty
				int i=0,d,opt;
				char ans,sub[20],cont;
				do
				{  opt=1;
				   cout<<"1. Add Faculty\n";
				   cout<<"2. View Department";
				   cout<<"\nEnter your Option:";
				   cin>>opt;
				   switch(opt)
				   {
					case 1:do
					       {
						  f[i].getdata();
						  clrscr();
						  cout<<"Do you want to Continue(y/n)";
						  cin>>ans;
						  i++;
						}while(ans=='y'||ans=='Y');
						break;
					case 2 :cout<<"1.Maths department"<<endl;
						cout<<"2.English department"<<endl;
						cout<<"3.Computer department"<<endl;
						cout<<"4.Science department"<<endl;
						cout<<"5.social department"<<endl;
						cout<<endl<<"Enter department"<<endl;
						cin>>d;
						switch(d)
						{
							case 1:strcpy(sub,"maths");
							       for(int j=0;j<i;j++)
								   if(strcmp(sub,f[j].subject)==0)
									 f[j].department();

							       break;
							case 2:strcpy(sub,"english");
							       for(j=0;j<i;j++)
								 if(strcmp(sub,f[j].subject)==0)
									f[j].department();


								break;

							case 3:strcpy(sub,"computer");
							       for(j=0;j<i;j++)
								if(strcmp(sub,f[j].subject)==0)
								 f[j].department();
							       break;
							case 4:for(j=0;j<i;j++)
								{strcpy(sub,"science");
								    if(strcmp(sub,f[j].subject)==0)
									f[j].department();
								}
								break;

							case 5:for(j=0;j<i;j++)
								{strcpy(sub,"social");
								   if(strcmp(sub,f[j].subject)==0)
									f[j].department();}

								}
								break;
							default:cout<<"Invalid Entry";
						}
				cout<<"\nDo you want to go to back Menu(y/n)";
				cin>>cont;
				}while(cont=='y'|| cont=='Y');
			break;
			default:cout<<"SORRY Invalid Option\n";
		 }
		 cout<<"\nDo You want to Continue(Y/N)";
		 cin>>con;
	 }while(con=='y'||con=='Y');
	 getch();
}


