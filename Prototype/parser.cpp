#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstring>
#include<queue>

using namespace std ;

ifstream in ;
ofstream out, logout ;						//File Pointers

int line = 0 ;

class parser
{
private: 
	
	
public:
	
	parser()
	{
		  
	}
	
	void parseLineFromQueue(queue<char *> &inputLine)					//Replace words in queue
	{
		line++ ;
		char *word, replace[50], buf[50] ;
		while(!inputLine.empty())
		{
			word = inputLine.front() ;
			if(!strcmp(word, "#include<iostream.h>")){
				strcpy(replace, "#include<iostream>") ;
				out << replace << " " ;
				logout << line << ": Replace " << word << " with " << replace << "\n" ;
			}
			else if(!strcmp(word, "#include<conio.h>")){
				strcpy(replace, "#include<stdlib.h>\n") ;
				out << replace << " " ;
				logout << line << ": Replace " << word << " with " << replace << "\n" ;
				strcpy(replace, "#include\"replacements.h\"");
				out << replace << " " ;
				line++ ;
				logout<<"Include replacements.h which includes definition for getch()\n";
			}
			else if(!strcmp(word, "clrscr()")){
				strcpy(replace, "system(\"cls\")") ;
				out << replace << " " ;
				logout << line << ": Replace " << word << " with " << replace << "\n" ;
			}
			else if(!strcmp(word, "cout")){
				strcpy(replace, "std::cout") ;
				out << replace << " " ;
				logout << line << ": Replace " << word << " with " << replace << "\n" ;
			}
			else if(!strcmp(word, "cin")){
				strcpy(replace, "std::cin") ;
				out << replace << " " ;
				logout << line << ": Replace " << word << " with " << replace << "\n" ;
			}
			else if(!strcmp(word, "void")){
				strcpy(buf, "int") ;
				inputLine.pop() ;
				continue ;
			}
			else if(!strcmp(word, "main()") && !strcmp(buf, "int")){
				out << "int main()" ;
				logout<< line << ": Replace void main() with int main()\n";
			}
			else
				out << word << " " ;
			inputLine.pop() ;
		}
	}
	
};

int main(int argc, char **argv)
{	
	string sline ;						//Line read from file
	char *line, *word ;
	
	queue<char *> inputLine ;				//Queue in which the words are stored
	
	in.open("inout.cpp",ios::in) ;
	out.open("output.cpp",ios::out) ;				//File Name to be REVISED!
	logout.open("log.txt",ios::out);
	
	parser obj ;						//Class Object
	
	while(!in.eof())
	{
		getline(in, sline) ;
		line = new char [sline.size() + 1] ;
		strcpy(line, sline.c_str()) ;
		word = strtok(line, " ") ;
		while(word != NULL)
		{
			inputLine.push(word) ;
			word = strtok(NULL, " ") ;
		}
		obj.parseLineFromQueue(inputLine) ;
		out << "\n" ;
	}
	
	in.close() ;
	out.close() ;
	return 0;
	
}