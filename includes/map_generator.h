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
		string_map header_map;		// Data Structure to store the ANSI Header Files.

		//Pugi XML variables
		xml_document xml_header_file;
		xml_parse_result xml_result;
		xml_node xml_tool, child_tool;
		xml_node_iterator xml_iterator;
		xml_attribute xml_attrib;
		xml_attribute_iterator xml_a_iterator;
	
	public:

		parser();
		void create_function_map(string key, string value);
		void create_header_map();
		int xml_reader();
		string map_find(string key, char type);
};

#endif