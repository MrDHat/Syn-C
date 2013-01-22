#include<iostream.h>
#include<conio.h>
void main()
{
int a=0,b=1,c,i,j;
cout << "Enter the number of terms you want to print";
cin >> j;
cout << a << " " << b << " " ;
for(i=3;i<=j;i++)
{
c=a+b;
cout << c << " ";
a=b;
b=c;
}
}