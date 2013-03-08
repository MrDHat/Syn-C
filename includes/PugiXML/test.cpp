#include "pugixml.hpp"
#include <iostream>
int main(){
	pugi::xml_document doc ;
	pugi::xml_parse_result res = doc.load_file("../XML/a.xml") ;
	pugi::xml_node a = doc.child("alloc.h") ;
	std::cout << a ;
	return 0 ;
}