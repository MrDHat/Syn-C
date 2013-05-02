all: UI
	
UI: flex
	javac MainUI.java

flex: queue
	flex includes/scanner/scanner.l
	g++ -o flex_output lex.yy.c -I includes/ includes/queue_ops.cpp includes/map_generator.cpp includes/PugiXML/pugixml.cpp -std=c++11

queue: map_generate
	g++ -c includes/queue_ops.cpp -I includes/ includes/map_generator.cpp -std=c++11

map_generate: pugixml
	g++ -c includes/map_generator.cpp -I includes/PugiXML/ includes/PugiXML/pugixml.cpp -std=c++11

pugixml: 
	g++ -c includes/PugiXML/pugixml.cpp
