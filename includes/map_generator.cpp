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


#include "map_generator.h"
#include <iostream>

using namespace std;

const string xml_path("../XML/");

parser::parser() {

}

int parser::xml_reader() {
	char header_it;
	string header, replacement, function_name, value;
	string src("");
	for(header_it= 'a' ; header_it<= 'z' ; header_it++) {
		src+= xml_path;
		src+= header_it;
		src+= ".xml";
		xml_result= xml_header_file.load_file(src.c_str());
		if(xml_result){
			xml_tool= xml_header_file.child("a").child("functions");
			for(child_tool= xml_tool.child("function"); child_tool; child_tool = child_tool.next_sibling("function")){
				
				function_name = child_tool.attribute("name").value();
				replacement = child_tool.attribute("replacement").value();
				header = child_tool.attribute("header").value();
				value+= replacement + ";" + header; 
				/*cout << "Name " << function_name << "\n";
				cout << "rep " << replacement << "\n";
				cout << "header " << header << "\n";
				cout << "Value " << value << "\n";*/
				create_function_map(function_name, value);
				value=""; // Reinitialize value
			}
		}
	}

}

int parser::create_function_map(string key, string value) {
	function_map[key] = value ;
}