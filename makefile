all: UI
	
UI: flex
	@echo -e "\033[1m\033[31m\nGenerating UI JAR File...\033[0m"
	javac MainUI.java
	jar cvfm SynC.jar MANIFEST.MF MainUI.class

flex: queue
	@echo -e "\033[1m\033[31m\nGenerating Flex File...\033[0m"
	flex includes/scanner/scanner.l
	g++ -o flex_output lex.yy.c -I includes/ includes/queue_ops.cpp includes/map_generator.cpp includes/PugiXML/pugixml.cpp -std=c++11

queue: map_generate
	@echo -e "\033[1m\033[31m\nGenerating Queue Operations Object...\033[0m"
	g++ -c includes/queue_ops.cpp -I includes/ includes/map_generator.cpp -std=c++11

map_generate: pugixml
	@echo -e "\033[1m\033[31m\nGenerating Hash Maps Object...\033[0m"
	g++ -c includes/map_generator.cpp -I includes/PugiXML/ includes/PugiXML/pugixml.cpp -std=c++11

pugixml: 
	@echo -e "\033[1m\033[31m\nGenerating XML Parser Object...\033[0m"
	g++ -c includes/PugiXML/pugixml.cpp
