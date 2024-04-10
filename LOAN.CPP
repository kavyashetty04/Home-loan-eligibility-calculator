#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>

class input
{
 protected :
 long int income;
 int age,tenure,bank;
 char gender,opt;
 long int other_EMI;
 int calculate_tenure()
 {
  if(age>60 || age<21)
  {
   cout<<"\n Sorry! You are not eligible for loan!"<<endl;
   delay(5000);
   exit(0);
  }
  else if(60-age>=30)
  {
    return 30;
  }
  else
  {
   return 60 - age;
  }
 }
 public:
 float rate;
 void display_info()
 {
  cout<<endl;
  cout<<"                  ====================================="<<endl;
  cout<<"                    HOME LOAN ELIGIBILITY CALCULATOR.  "<<endl;
  cout<<"                  ====================================="<<endl<<endl;

  cout<<"Rules : "<<endl<<endl;;
  cout<<"1. The age of the candidate should be between 21 and 60 years."<<endl;
  cout<<"2. The salary must be at least Rs.20,000 monthly"<<endl;
  cout<<"3. The candidate must have at least one year of work experience."<<endl<<endl;
  cout<<"-------------------------------------------------------------------------------"<<endl;
 }
 void choose_bank();
 int getdata()
 {
  cout<<"\n Enter your gross monthly income : ";
  cin>>income;
  if (income < 20000)
  {
   cout<<"\n Sorry! Your income must be atleast Rs.20000 monthly !"<<endl;;
   delay(5000);
   exit(0);
  }
  cout<<"\n Enter your age (you must be between 21 and 60) : ";
  cin>>age;
  cout<<"\n Your maximum tenure(years) : "<<calculate_tenure()<<endl;
  cout<<"\n Enter tenure (years) : ";
  cin>>tenure;
  if(tenure>= 60 - age || tenure>=30)
  {
   cout<<"\n you have exceeded the maximum tenure! \n Please enter within limit : ";
   cin>>tenure;
  }
  cout<<"\n Enter your gender (f - female , m - male) : ";
  cin>>gender;
  cout<<"\n Do you have any other EMI's ?(yes => y  ,  no=>n) : ";
  cin>>opt;
  if(opt == 'y')
  {
   cout<<"\n enter the amount  : ";
   cin>>other_EMI;
  }
  else
  {
   other_EMI = 0;
  }

 }
};

class calculate_loan : public input
{
 public :
 long int loan_amount;
 long int EMI,final_EMI;

 void EMI_perlack()
 {
  rate = (rate/100)/12;
   tenure = tenure*12;
  EMI =  100000*rate*pow((1 + rate),tenure)/(pow((1 + rate),tenure) - 1);
 }

 void loan_eligibility()
 {
   loan_amount = (((0.5*income)-other_EMI)/EMI)*100000;
  cout<<" YOUR LOAN ELIGIBILITY : Rs."<<loan_amount<<endl<<endl;
  cout<<"--------------------------------------------"<<endl<<endl;
 }
 void calc_EMI()
{

  final_EMI =  loan_amount*rate*pow((1 + rate),tenure)/(pow((1 + rate),tenure) - 1);
  cout<<" YOUR EMI : Rs."<<final_EMI<<endl;
 }
};

void input :: choose_bank()
{
 cout<<"\n Choose bank from which you want to take loan : "<<endl<<endl;
 cout<<" -------------------------------------- "<<endl;
 cout<<"|   HDFC                        => 1   |"<<endl;
 cout<<"|--------------------------------------|"<<endl;
 cout<<"|   State Bank of India(SBI)    => 2   |"<<endl;
 cout<<"|--------------------------------------|"<<endl;
 cout<<"|   Axis Bank                   => 3   |"<<endl;
 cout<<"|--------------------------------------|"<<endl;
 cout<<"|   ICICI Bank                  => 4   |"<<endl;
 cout<<"|--------------------------------------|"<<endl;
 cout<<"|   enter your rate of interest => 5   |"<<endl;
 cout<<" -------------------------------------- "<<endl;
 cin>>bank;
 switch(bank)
 {
  case 1 :
  if(gender == 'f'|| gender == 'F')
  {
   rate = 8.95;
  }
  else
  {
   rate = 9.00;
  }
  break;

  case 2 :
  if(gender == 'f'|| gender == 'F')
  {
   rate = 6.95;
  }
  else
  {
   rate = 7.00;
  }

  break;

  case 3 :
  rate = 6.90;
  break;

  case 4 :
  rate = 6.80;
  break;

  case 5 :
  cout<<"enter rate of interest : ";
  cin>>rate;
  break;

  default :
  cout<<"Invalid input! choose (1-4) : ";
 }

 cout<<"\nYour rate of interest : "<<rate<<"% per annum"<<endl<<endl;
 cout<<"Calculating you Home Loan Eligibility ...."<<endl<<endl;
 delay(1000);
}
int main()
{
 calculate_loan l;
 clrscr();
 l.display_info();
 l.getdata();
 l.choose_bank();
 l.EMI_perlack();
 cout<<"--------------------------------------------"<<endl;
 l.loan_eligibility();
 l.calc_EMI();
 cout<<"--------------------------------------------"<<endl;
 cout<<endl<<endl;
 cout<<"============================================"<<endl;
 cout<<"                THANK YOU !                 "<<endl;
 cout<<"============================================"<<endl;
 getch();
 return 0;
}