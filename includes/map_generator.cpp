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
    along with Syn-C.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "map_generator.h"
#include <stdio.h>

using namespace std;

parser::parser() {
	create_header_map();
}

int parser::xml_reader() {
	char header_it;
	string header_it_str;
	string header, replacement, function_name, value;
	string src;
	for(header_it= 'a' ; header_it<= 'z' ; header_it++) {
		src = "XML/";
		src+= header_it;
		src+= ".xml";
		xml_result= xml_header_file.load_file(src.c_str());
		if(xml_result){
			header_it_str= header_it;
			xml_tool= xml_header_file.child(header_it_str.c_str()).child("functions");
			for(child_tool= xml_tool.child("function"); child_tool; child_tool = child_tool.next_sibling("function")){
				value=""; // Reinitialize value
				function_name = child_tool.attribute("name").value();
				replacement = child_tool.attribute("replacement").value();
				header = child_tool.attribute("header").value();
				value+= replacement + ";" + header + ";"; 
				create_function_map(function_name, value);
			}
		}
	}
}

void parser::create_function_map(string key, string value) {
	function_map[key] = value ;
}

void parser::create_header_map() {
	header_map["assert"]= "true";
	header_map["complex"]= "true";
	header_map["ctype"]= "true";
	header_map["errno"]= "true";
	header_map["fenv"]= "true";
	header_map["float"]= "true";
	header_map["inttypes"]= "true";
	header_map["iso646"]= "true";
	header_map["limits"]= "true";
	header_map["locale"]= "true";
	header_map["math"]= "true";
	header_map["setjmp"]= "true";
	header_map["signal"]= "true";
	header_map["stdarg"]= "true";
	header_map["stdbool"]= "true";
	header_map["stdint"]= "true";
	header_map["stddef"]= "true";
	header_map["stdio"]= "true";
	header_map["stdlib"]= "true";
	header_map["string"]= "true";
	header_map["tgmath"]= "true";
	header_map["wchar"]= "true";
	header_map["wctype"]= "true";
}

/*Search for a key in the map. If type='f', search in function_map, else if type='h', search in header_map*/
string parser::map_find(string key, char type){
	string value("no");
	try{
		if(type== 'f'){
			value= function_map.at(key);
			return value;
		}

		else if(type== 'h'){
			value= header_map.at(key);
			return value;
		}
	}
	
	catch(...){
			return value;
	}
}