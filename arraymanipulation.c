#include <stdio.h>
#include <stdlib.h>
int SIZE1,SIZE2;
int *a;
int *b;
void populate()
{
    int i;
    printf("how many elements to store in array?\n");
    scanf("%d",&SIZE1);
    a=malloc(sizeof(int)* SIZE1);
    printf("insert elements now\n");
    for(i=0;i<SIZE1;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Elements stored success\n");
}
void display()
{
    if(a!=NULL)
    {
   int i;
   printf("present content of array:\n");
    for(i=0;i<SIZE1;i++)
    {
       printf(" %d",a[i]);
    }
printf("\n");
    }
    else printf("EMPTY ARRAY !! press menu no: 1 to create array first\n");
}

void insert()
{
    int i,p,n;
    printf("Enter position(1 to %d) to insert a element to array\n",SIZE1);scanf("%d",&p);
    printf("Enter the new element to be inserted in position(%d)\n",p);scanf("%d",&n);
    SIZE1+=1;
    for(i=SIZE1-1;i>=p-1 ;i--)
    {
         a[i+1]=a[i];
    }

    a[p-1]=n;

}
void del()
{
    if(a!=NULL)
    {
int i,p;
printf("Enter position(1 to %d) to delete\n",SIZE1);scanf("%d",&p);
 if(p>SIZE1)
    {
        printf("Incorrect option enter position from(1 to %d)\n",SIZE1);del();
    }
else
{

for(i=0;i<SIZE1;i++)
{

    if(i>=p-1)
    {
        a[i]=a[i+1];
    }


}
if(p>SIZE1){}else{printf("....element position(%d) deleted from array success \n ",p);}
SIZE1=SIZE1-1;

}
    }
    else printf("Deletion action failed( no action to handel empty array)::\n");
}
void merge()
{
    if(a!=NULL){
    int j, i,temp;
    printf("for neww array:\nEnter index:");
    scanf("%d",&SIZE2);
    b=malloc(sizeof(int)* SIZE2 );
    printf("insert elements now\n");
    for(i=0;i<SIZE2;i++)
    {
       scanf("%d",&b[i]);
    }
    printf("Elements stored success\n");
    temp=SIZE1;
    SIZE1=SIZE1+SIZE2;
    for(i=0;i<SIZE1;i++)
{
     if(i==temp){
            for(j=0;j<SIZE2;j++)
           {
            a[i]=b[j];
            i=i+1;
           }
                }
}
    } else printf("merge failed \"no previous array to merge\"\n");
}

void update()
{

    int i,n,p;
    if(a!=NULL)
{
    printf("Enter the position(1 to %d) to update element\n",SIZE1);scanf("%d",&p);
    printf("Enter the new element to update on position(%d) ",p);scanf("%d",&n);
    for(i=0;i<SIZE1;i++)
    {
        if(i==p-1)
        {
            a[i]=n;
        }
    }
}
else printf("array not created create array first press 1 to create\n");
}
int main()
{
   int x;
    p:
   printf("-----------------MENU------------------------\n");
   printf("\tpress 1 create a new  array\n");
   printf("\tpress 2 to insert elements to array\n");
   printf("\tpress 3 to Delete element of array\n");
   printf("\tpress 4 to display  elements of array\n");
   printf("\tpress 5 to merge two arrays\n");
   printf("\tpress 6 to update a element on array\n");
   printf("\tpress 7 to exit a element on array\n");


   v:

    printf("ENTER MENU NO:\n(press 0 to get menu if you dont see it): ");
   scanf("%d",&x);


   switch(x)
{
   case(1):
   {
       populate();
       display();
       goto v;
     
   }
   case(2):
   {
         insert();
         display();
         goto v;
      

   }
   case(3):
   {
        del();
        display();
        goto v; 
   }
   case(4):
    {
       display();goto v;
   
    }
   case(5):
    {
       merge();
       display(); goto v;
  
    }
   case(6):
    {
        update();
        display(); goto v;
   
    }
   case (7):
    {
       break;
    }
   case (0):
    {
        goto p;
       
    }
   default:
    {
        printf("invalid input (Enter number from(1 to 7)\n");
        goto p;
      
    }
}

    return 0;
}
