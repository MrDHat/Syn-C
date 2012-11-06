#include<iostream.h> 
#include<conio.h>  

void main() 
{ 
 int a, b, res ; 
 char op ; 
 clrscr() ; 
 cout << "Enter the two numbers : " ; 
 cin >> a >> b ; 
 cout << "\nEnter the Operator : " ; 
 cin >> op ; 
 switch(op) 
 { 
  case '+' : res = a + b ; break ; 
  case '-' : res = a - b ; break ; 
  case '*' : res = a * b ; break ; 
  case '/' : res = a / b ; break ; 
  default : cout << "Invalid Operator" ; 
 } 
 cout << a << op << b << " = " << res ; 
 getch() ; 
} 
