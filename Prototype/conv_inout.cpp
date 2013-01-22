#include<iostream>  
#include<stdlib.h>
 #include"replacements.h"  
 
int main() 
{  
int a, b, res ;  
char op ;  
system("clear") ;  
std::cout << "Enter the two numbers : " ;  
std::cin >> a >> b ;  
std::cout << "\nEnter the Operator : " ;  
std::cin >> op ;  
switch(op)  
{  
case '+' : res = a + b ; break ;  
case '-' : res = a - b ; break ;  
case '*' : res = a * b ; break ;  
case '/' : res = a / b ; break ;  
default : std::cout << "Invalid Operator" ;  
}  
std::cout << a << op << b << " = " << res ;  
getch() ;  
}  

