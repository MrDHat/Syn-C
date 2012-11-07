#include<iostream.h>
#include<conio.h>
void main( )
{
int num, i, flag=0;
cout<< "Enter a number " ;
cin>>num ;
i=2;
while ( i <= num - 1 )
{
if ( num % i == 0 )
{
cout<<"Not a prime number";
flag=1;
break ;
}
i++ ;
}
if(flag ==0)
cout<<"It is a prime number";
}
