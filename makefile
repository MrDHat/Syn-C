all: map_generate
	g++ -o test test.cpp -std=c++11

map_generate: pugixml
	g++ -c includes/map_generator.cpp -std=c++11

pugixml: 
	g++ -c includes/PugiXML/pugixml.cpp