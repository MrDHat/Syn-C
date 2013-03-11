/*
Parses the XML file, generates the unordered map
*/

#ifndef map_generator_h__
#define map_generator_h__

#include <unordered_map>
#include <string>
#include "PugiXML/pugixml.hpp"

using namespace std;
using namespace pugi;

typedef unordered_map<string,string> string_map;

class parser {
	private:
		
		string_map function_map;	// Data Structure to store the hash map

		//Pugi XML variables
		xml_document xml_header_file;
		xml_parse_result xml_result;
		xml_node xml_tool, child_tool;
		xml_node_iterator xml_iterator;
		xml_attribute xml_attrib;
		xml_attribute_iterator xml_a_iterator;
	
	public:

		parser();
		int create_function_map(string key, string value);
		int xml_reader();

};

#endif