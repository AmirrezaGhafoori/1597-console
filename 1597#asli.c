#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
/*defining needed functions*/
 long int p,q;//define these two global variables for making random elements;
//fibo serie
int n_fibo (int n)
{
    if (n==1)
        return 1;
    if (n==2)
        return 1;
    return n_fibo(n-1)+n_fibo(n-2);
}

bool is_fibo (int n)//is_fibo function
{
    int i=1;
    while (n_fibo(i)<=n)
    {
        if (n_fibo(i)==n)
            return true;
        i++;
    }
    return false;

}
void print_array (int size,int a[size][size])//this will print the array;
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
            printf("%4d   ",a[i][j]);
        printf("\n\n");
    }
}
bool chek_fibo (int a,int b)//check the two number that they R in fibo or not;
{
    if ((is_fibo(a+b))&&is_fibo(a)&&is_fibo(b))
        return true;
    return false;
}
void make_rand_one (int size,int a[size][size])//makeing random 1 in the array;
{
    int i,p,q;
    while(1)
    {
       p=rand();
       q=rand();
        if (a[p%size][q%size]==0)
        {
            a[p%size][q%size]=1;
            break;
        }
    }
}
void move_up (int size, int a[size][size])//doing up movement;
{
int i,j,k;
for (j=0;j<size;j++)
{


for (i=0;i<size;i++)
    {
        int l=0;
        while(0==a[i][j] && l<size){
        if (a[i][j]==0)
        {

           for (k=i;k+1<size;k++)
               {
               // printf("%d",k);
                int tmp;
                tmp=a[k][j];
                a[k][j]=a[k+1][j];
                a[k+1][j]=tmp;
               }
             //  printf("\n");
             l++;
        }
    }

    }
    i=0;
    }
   //  print_array(size,a);
    for (j=0;j<size;j++)
{
 i=0;
while (i+1<size)
{
    if (chek_fibo(a[i][j],a[i+1][j]))
    {
        a[i][j]=a[i][j]+a[i+1][j];
        a[i+1][j]=0;
        i+=2;
    }
    else
        i++;
}
 //   print_array(size,a);

for (i=0;i<size;i++)
    {
        if (a[i][j]==0)
        {
           for (k=i;k+1<size;k++)
               {
                 //  printf("   %d",k);
                int tmp;
                tmp=a[k][j];
                a[k][j]=a[k+1][j];
                a[k+1][j]=tmp;
               }
             //  printf("\n");
        }

    }
}
}
void move_down (int size, int a[size][size])//doing down movement;
{
    int i,j,k;
    for (j=0;j<size;j++)
    {
        for (i=size-1;i>=0;i--)
        {
            int l=0;
            while (0==a[i][j]&&l<size)
            {
            if (a[i][j]==0)
            {
                for (k=i;k>0;k--)
                {
                    int tmp;
                tmp=a[k][j];
                a[k][j]=a[k-1][j];
                a[k-1][j]=tmp;
                }
                l++;
            }
            }
        }
    }
        i=size-1;
        for (j=0;j<size;j++)
        {
        i=size-1;
        while(i>0)
        {
            if (chek_fibo(a[i][j],a[i-1][j]))
            {
                a[i][j]=a[i][j]+a[i-1][j];
                a[i-1][j]=0;
                i-=2;
            }
            else i--;
        }


         for (i=size-1;i>=0;i--)
        {
            if (a[i][j]==0)
            {
                for (k=i;k>0;k--)
                {
                    int tmp;
                tmp=a[k][j];
                a[k][j]=a[k-1][j];
                a[k-1][j]=tmp;
                }
            }
        }
        }

}
void move_left (int size,int a[size][size])//doing the right movement;
{
    int i=0,j=0,k;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            int l=0;
            while(a[i][j]==0&&l<size)
            {
                if (a[i][j]==0)
                {
                    for (k=j;k+1<size;k++)
                    {
                        int tmp;
                        tmp=a[i][k];
                        a[i][k]=a[i][k+1];
                        a[i][k+1]=tmp;
                    }
                }
                l++;
            }
        }
        j=0;

    }
    for (i=0;i<size;i++)
    {
         j=0;
while (j+1<size)
{
    if (chek_fibo(a[i][j],a[i][j+1]))
    {
        a[i][j]=a[i][j]+a[i][j+1];
        a[i][j+1]=0;
        j+=2;
    }
    else
        j++;
}
 //   print_array(size,a);

for (j=0;j<size;j++)
    {
        if (a[i][j]==0)
        {
           for (k=j;k+1<size;k++)
               {
                 //  printf("   %d",k);
                int tmp;
                tmp=a[i][k];
                a[i][k]=a[i][k+1];
                a[i][k+1]=tmp;
               }
             //  printf("\n");
        }

    }
    }
}
void move_right (int size,int a[size][size])//doing the right movement;
{
    int i,j,k;
    for (i=0;i<size;i++)
    {
        for (j=size-1;j>=0;j--)
        {
            int l=0;
            while (0==a[i][j]&&l<size)
            {
            if (a[i][j]==0)
            {
                for (k=j;k>0;k--)
                {
                    int tmp;
                tmp=a[i][k];
                a[i][k]=a[i][k-1];
                a[i][k-1]=tmp;
                }
                l++;
            }
            }
        }
    }
        j=size-1;
        for (i=0;i<size;i++)
        {
        j=size-1;
        while(j>0)
        {
            if (chek_fibo(a[i][j],a[i][j-1]))
            {
                a[i][j]=a[i][j]+a[i][j-1];
                a[i][j-1]=0;
                j-=2;
            }
            else j--;
        }


         for (j=size-1;j>=0;j--)
        {
            if (a[i][j]==0)
            {
                for (k=j;k>0;k--)
                {
                    int tmp;
                tmp=a[i][k];
                a[i][k]=a[i][k-1];
                a[i][k]=tmp;
                }
            }
        }
        }
}
void copy_array (int size,int b[size][size],int a[size][size])//copying an array to another array;
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            b[i][j]=a[i][j];
        }
    }
}
int main()
{
    int n,i,j,counter_1=0,counter_2=0;
    scanf("%d",&n);
    if ((n>8)||(n<4))
    {
        printf("please intpute a number between 4&8 !");
        return -1;
    }
    int a[n][n];
    int b[n][n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            a[i][j]=0;
    }
    make_rand_one(n,a);
    make_rand_one(n,a);
    print_array(n,a);
    copy_array(n,b,a);
    time_t t=time(NULL);
    srand(t);


    while(1)
    {
    int arrow;
    char ch;
    arrow=ch=getch();
    if (arrow==224)
    {
        arrow=getch();
    }

        if (arrow==72)
        {
        copy_array(n,b,a);
        move_up(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
        }
        if (arrow==80)
        {
        copy_array(n,b,a);
        move_down(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
        }
        if (arrow==77)
        {
        copy_array(n,b,a);
        move_right(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
        }
        if (arrow==75)
        {
        copy_array(n,b,a);
        move_left(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
        }

    if (ch=='q')
    {
        printf("YOU QUIT THE GAME!");
        break;
    }
    if(ch=='j')
    {
        copy_array(n,b,a);
        move_left(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
    }

    if (ch=='i')
    {
        copy_array(n,b,a);
        move_up(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);


    }
    if (ch=='k')
    {
        copy_array(n,b,a);
        move_down(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
    }

    if (ch=='l')
        {
        copy_array(n,b,a);
        move_right(n,a);
        make_rand_one(n,a);
        system("CLS");
        print_array(n,a);
        }
    if (ch=='u')
    {
        system("CLS");
        print_array(n,b);
        copy_array(n,a,b);
    }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (a[i][j]!=0)
                    counter_1++;
                if (a[i][j]==1597)
                    counter_2++;
            }
        }
        if ((counter_1==(n*n))||(counter_2>0))//for the end of the game !
        {
            printf("GAME IS OVER!");
            break;
        }
        else
            counter_1=0;

    }
     return 0;
    }


















