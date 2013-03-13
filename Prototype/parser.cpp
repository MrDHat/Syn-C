/*
   	This file is part of Syn-C.

    Syn-C is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Syn-C is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Weka Grain.  If not, see <http://www.gnu.org/licenses/>.
*/

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
				strcpy(replace, "system(\"clear\")") ;
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
	
	string input_file(argv[1]) ;
	string output_file(argv[1]) ;
	string log_file(argv[1]) ; ;
	
	input_file.append(argv[2]) ;
	
	output_file.append("conv_") ;
	output_file.append(argv[2]) ;
	
	log_file.append("log.txt") ;
	
	queue<char *> inputLine ;				//Queue in which the words are stored
	
	in.open(input_file.c_str() ,ios::in) ;
	out.open(output_file.c_str(), ios::out) ;				//File Name to be REVISED!
	logout.open(log_file.c_str() ,ios::out);
	
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
	logout.close() ;
	return 0;
	
}