#include "map_generator.h"
#include <iostream>

using namespace std;

const string xml_path("../XML/");

parser::parser() {

}

int parser::xml_reader() {
	char header_it;
	string src("");
	for(header_it= 'a' ; header_it<= 'z' ; header_it++) {
		src+= xml_path;
		src+= header_it;
		src+= ".xml";
		xml_result= xml_header_file.load_file(src.c_str());
		if(xml_result){
			xml_tool= xml_header_file.child("a").child("functions");
			for(child_tool= xml_tool.child("function"); child_tool; child_tool = child_tool.next_sibling("function")){
				cout << "Name " << child_tool.attribute("name").value() << "\n";
			}
		}
	}
}

int parser::create_function_map(string key, string value) {

}

int main()
{
	parser obj;
	obj.xml_reader();
	return 0;
}