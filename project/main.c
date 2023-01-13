#include <stdio.h>
#include <stdlib.h>
int grandTotal=0,samosaPlates=0,dosaPlates=0,totalcups=0;

int menu()
{
    int choice;
    printf("   Menu \n");
    printf("1.Samosa\n");
    printf("2.Tea\n");
    printf("3.Dosa\n");
    printf("0.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
return choice;
}

void order(int choice,int rate)
{
int plates;

if(choice==2)
  printf("Enter Number of Cups: ");
else
  printf("Enter Number of Plates: ");
  scanf("%d",&plates);

billing(rate,plates);
if(choice==1)
        samosaPlates=samosaPlates+plates;


if(choice==2)

        dosaPlates=dosaPlates+plates;

   if(choice==3)

      totalcups=totalcups+plates;

}

void billing(int rate,int plates)
{
    int subTotal;
    subTotal=rate*plates;
    //printf("Sub total : %d\n",subTotal);
    grandTotal=grandTotal+subTotal;
}

void printBill()
{
int cash=0,lp=1;
printBillTable();
printf("Grand total %d\n",grandTotal);
while(lp)
{
printf("Enter your Cash : ");
scanf("%d",&cash);
grandTotal=grandTotal-cash;
if(grandTotal==0)
{
printf("Thank You\n");
lp=0;
}
if(grandTotal<0)
{
 printf("Return : %d\n",grandTotal*-1);
 notes(grandTotal*-1);
 printf("Thank You\n");
 lp=0;
}
if(grandTotal>0)
{
 printf("Please Enter %d Rupees more\n",grandTotal);
 notes(grandTotal*1);
}

}

}

void notes(int cash)
{

    int grandTotal;
   grandTotal=cash/500; //220/100=2
   cash=cash%500;  //
   if(grandTotal!=0)
    printf("500 Notes x %d\n",grandTotal);
    grandTotal=cash/200; //220/100=2
   cash=cash%200;  //
    if(grandTotal!=0)
    printf("200 Notes x %d\n",grandTotal);
   grandTotal=cash/100; //1
   cash=cash%100;//25
    if(grandTotal!=0)
    printf("100 Notes x %d\n",grandTotal);
   grandTotal=cash/50; //1
   cash=cash%50;//5
    if(grandTotal!=0)
    printf("50 Notes x %d\n",grandTotal);
   grandTotal=cash/20; //0
  cash=cash%20;//5
   if(grandTotal!=0)
    printf("20 Notes x %d\n",grandTotal);
   grandTotal=cash/10; //1
   cash=cash%10;//0
    if(grandTotal!=0)
    printf("10 Notes x %d\n",grandTotal);
   grandTotal=cash/5; //0
   cash=cash%5;//0
    if(grandTotal!=0)
    printf("5 Notes x %d\n",grandTotal);
}

void printBillTable()
{
                   int count=1;
                   printf(" : : Your Bill : : \n");
                   printf("--------------------------------------------\n");
                   printf("| Sr No. |  Item  | Qty  | Rate  | Sub Total |\n");
                   printf("--------------------------------------------\n");
                   if(samosaPlates!=0)
                   printf("   %d     | Samosa  | %d    |  20    |    %d    \n",count++,samosaPlates,samosaPlates*20);
                   if(dosaPlates!=0)
                   printf("   %d     |  Dosa   | %d    |  30    |    %d    \n",count++,dosaPlates,dosaPlates*30);
                   if(totalcups!=0)
                   printf("   %d     |   Tea   | %d    |  10    |    %d    \n",count++,totalcups,totalcups*10);
                   printf("--------------------------------------------\n");

}


int main()
{
    int ch,lp=1;
    printf("WELCOME TO HOTEL\n");

    while(lp)
    {
     ch= menu();
    switch(ch)
    {
    case 1:
        order(ch,20);
        break;
    case 2:
        order(ch,10);
        break;
    case 3:
        order(ch,30);
        break;
    case 0:
        lp=0;
        printBill();

        break;
    default:
        printf("Wrong input! Try again and choose correct option\n");
        break;
    }
    }
    return 0;
}
