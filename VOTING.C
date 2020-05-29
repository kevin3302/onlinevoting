//ONLINE VOTING SYSTEM
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int c1=0,c2=0,c3=0,c4=0,c5=0,total=0,otp,alpha,pos=7147;
typedef struct vote
{
  char aadhar[14];
  char name[20],phno[11];
  int age;
  int count;
  char place[20];
  struct vote *rc,*lc;
}vote;
vote *root=NULL;
vote * search(vote * address,char string[])
{
 if (address==NULL)
   return NULL ;
 else if(strcmp(string,address->aadhar)>0)
	 {
	  return search(address->rc,string) ;
	 }
  else if(strcmp(string,address->aadhar)==0)
	{
	 return address ;
	}
 else if(strcmp(string,address->aadhar)<0)
	{
	 return search(address->lc,string) ;
	}
}
void admin()
{
 int i;
 char cp[6],x[6],l[6];
 printf("    \n\nenter 4 digit password  :");
 for (i=0;i<4;i++)
 {
   cp[i]=getch();
   printf("*");
 }

 if(atoi(cp)==pos)
   { printf("\n     enter 1  to change possword else enter 2  : ");
		scanf("%d",&i);

	 if(i==1)
	  {

		printf("    \n\nenter 4 digit new  password  :");
		  for (i=0;i<4;i++)
		  {
			x[i]=getch();
			printf("*");
		  }
		printf("\n\n         reenter passward  : ");
		  for (i=0;i<4;i++)
		 {
		   l[i]=getch();
		   printf("*");
		  }
		if(atoi(x)==atoi(l))
		 { pos=atoi(x);
		   printf("     password saved\n");
		 }
		else
		printf("        incorrect   password");
	  }
	 clrscr();
	 printf("\n       \n      candidate 1 got     %d votes",c1);
	 printf("\n       \n      candidate 2 got     %d votes",c2);
	 printf("\n       \n      candidate 3 got     %d votes",c3);
	 printf("\n       \n      candidate 4 got     %d votes",c4);
	 printf("\n       \n      nota        got     %d votes",c5);

	 printf("\n\t\t     total votes : %d\n\n\n",total);
   }
   else
   printf("\ninvalid password\n");

}
void enroll()
{ int k;
  vote *nn,*temp,*p;
  nn=(vote*)malloc(sizeof(vote));

	 che:
	  k=0 ;
	  printf("\nenter aadhar number : ");
	  scanf("%s",&nn->aadhar);
	  if(strlen(nn->aadhar)!=12)
	   {printf("\n        invalid aadhar number \n");
		 printf("enter 1 to reenter aadhar no else enter 2 : ");
		 scanf("%d",&k);}
	   if(k==1)
		goto che;
	   if(k==2)
		return;
	  cha:k=0;
	  printf("\nenter phone number  : ");
	  scanf("%s",&nn->phno);
	  if(strlen(nn->phno)!=10)
		{printf("\n        invalid number \n");
		 printf("enter 1 to reenter phone no else enter 2 : ");
		 scanf("%d",&k);}
	   if(k==1)
		goto cha;
	   if(k==2)
		return;

	 printf("\nenter name          : ");
	 scanf("%s",&nn->name);
	 printf("\nenter age           : ");
	 scanf("%d",&nn->age);
	 printf("\nenter place         : ");
	 scanf("%s",&nn->place);
	 do
	 { printf("\n     enter otp sent to your phone number %c%c******%c%c :  ",nn->phno[0],nn->phno[1],nn->phno[8],nn->phno[9]);
	   scanf("%d",&otp);
	   if(otp==1234)
		 printf("\n           data saved\n");
		else
		{ printf("\n incorrect otp\n");
		  printf("\n enter 1 to exit  \nenter 2 to rresend otp  : ");
		  scanf("%d",&otp);
		  if(otp==1)
		   return;
		}
	  }while(otp!=1234);
	 nn->count=0;
	 nn->lc=NULL;
	 nn->rc=NULL;
	  if(root==NULL)
		root=nn;
	  else
	   {  temp=root;
		 while(temp)
		  {
		   p=temp;
		   if(strcmp(nn->aadhar,temp->aadhar)==1)
				{
				 temp=temp->rc;
				}
		   else
				{
				 temp=temp->lc;
				}
		  }
		   if(strcmp(nn->aadhar,p->aadhar)==1)
			 {
			  p->rc=nn;
			 }
		   else
			 {
			  p->lc=nn;
			 }
	   }

  }
void voting()
{ char no[14];
  int choice;
  vote *temp;
  printf("enter aadhar number : ");
  scanf("%s",&no);
  temp=search(root,no);
   if(temp==NULL)
   printf("\n\n          user not found  \n");
   else
	  { do
		{ printf("\n     enter otp sent to your phone number %c%c******%c%c :  ",temp->phno[0],temp->phno[1],temp->phno[8],temp->phno[9]);
		  scanf("%d",&otp);
		  if(otp==1234)
		   printf("\n           you can give vote\n");
			else
		   { printf("\n incorrect otp\n");
			printf("\n enter 1 to exit  \nenter 2 to resend otp : ");
		   scanf("%d",&otp);
		   if(otp==1)
			return;
		   }
		}while(otp!=1234);
		printf(" name          =  %s \n",temp->name);
		printf(" phone number  =  %s \n",temp->phno);
		printf(" age           =  %d  \n",temp->age);
		printf(" place         =  %s   \n",temp->place);
		printf("voter enrolled\n");
		if(temp->count==1)
		{ printf("\n       you have voted succesfully\n");
		  return;
		}
		total++;
		printf("\n       name      symbol  \n");
		printf("   1.    candidate 1     apple  \n");
		printf("   2.    candidate 2     ball  \n");
		printf("   3.    candidate 3     cat  \n");
		printf("   4.    candidate 4     dog  \n");
		printf("   5.    nota            none  \n");
		do
		 { printf("\n   enter choice  : ");
		  scanf("%d",&choice);
		  printf("\n\n\n   are you sure that your choice is %d\n\n",choice);
		  printf("  enter 0 to conform  else enter any number other than 0 to revote  : ");
		  scanf("%d",&alpha);
		 }while(alpha!=0);
		if(choice==1)
		c1++;
		if(choice==2)
		c2++;
		if(choice==3)
		c3++;
		if(choice==4)
		c4++;
		if(choice==5)
		c5++;
		printf("\n           your  vote saved successfully       ");
		temp->count=1;

	  }



}
void main()
{  int op;
   clrscr();
   do
   {   printf(  "\n\n\n enter any key to proceed\n\n");
	   getch();
	   clrscr();
	  printf(" \nenter   1.Election Admin\n        2.Voter Enrolling\n        3.Voting\n        4.Exit\n");
	  scanf("%d",&op);
	  clrscr();
	  switch(op)
	  {
	   case 1 : admin();break;
	   case 2 : enroll();break;
	   case 3 : voting();break;
	   case 4 :break;
	   default : printf("invalid input");
	  }
   }while(op!=4);
}