all: map_generate
	flex includes/scanner/scanner.l
	g++ -o flex_output lex.yy.c -I includes/ includes/queue_ops.cpp
	g++ -o test test.cpp -std=c++11

map_generate: pugixml
	g++ -c includes/map_generator.cpp -std=c++11
	g++ -c includes/queue_ops.cpp

pugixml: 
	g++ -c includes/PugiXML/pugixml.cpp