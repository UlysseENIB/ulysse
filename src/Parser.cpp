/*
* Parser.h
*
*  Created on: 2014
*      Author: kristen
*/
#include "Parser.h"

Parser::Parser(){
	//
	//TO DO
	//
	//grid.createGrid(CUBE_SIZE);
}

void Parser::parseNode(xmlNode * node){
	xmlAttr * it = NULL;
	for (it = node->properties; it; it = it->next) {
		cout << it->name << "  " << it->children->content << "   " << node->children->content << endl;
		//
		// HERE ADD CONDITION TO GET VALUE TO CREATE BOIDS AND TO ADD THEM AT THE GRID.
		//
		//if (xmlStrEqual(it->name, xmlCharStrdup("name")) && xmlStrEqual(it->children->content, xmlCharStrdup("Ulysse"))) {
		//	//DO SOMETHING
		//}
	}
}

void Parser::parseTable(xmlNode * node){
	xmlNode * it = NULL;
	for (it = node->children; it; it = it->next) {
		if (it->type == XML_ELEMENT_NODE) {
			if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
				parseNode(it);
			}
		}
	}
}

void Parser::parseDatabase(xmlNode * root){
	xmlNode * it = NULL;
	for (it = root->children; it; it = it->next) {
		if (it->type == XML_ELEMENT_NODE) {
			if (xmlStrEqual(it->name, xmlCharStrdup("table"))) {
				parseTable(it);
			}
		}
	}
}

//XML Parser
void Parser::parse(string fileXML){

	xmlDocPtr doc;

	//Open xml file
	doc = xmlReadFile(fileXML.c_str(), NULL, 0);

	if (doc == NULL) {
		printf("error: could not parse file %s\n", fileXML);
	}

	//Get root element to start parsing
	xmlNode * root = xmlDocGetRootElement(doc);

	xmlNode * itNode = NULL;
	xmlAttr * itAttr = NULL;
	for (itNode = root->children; itNode; itNode = itNode->next) {
		if (itNode->type == XML_ELEMENT_NODE) {
			// go to the part database
			if (xmlStrEqual(itNode->name, xmlCharStrdup("database"))) {
				for (itAttr = itNode->properties; itAttr; itAttr = itAttr->next) {
					// check database is Ulysse
					if (xmlStrEqual(itAttr->name, xmlCharStrdup("name")) && xmlStrEqual(itAttr->children->content, xmlCharStrdup("Ulysse"))) {
						parseDatabase(itNode);
					}
				}
			}
		}
	}

	//Close xml ressource
	xmlFreeDoc(doc);
	xmlCleanupParser();

	cout << "End Parse" << endl;
}
