/*
* Parser.h
*
*  Created on: 2014
*      Author: kristen
*/
#include "Parser.h"

/**
*	Just create a grid of size CUBE_SIZE
*
*/
Parser::Parser(){
	grid.createGrid(CUBE_SIZE);
	dataBaseResource = DataBaseResource();
}

ContentStruct* Parser::parseNode(xmlNode * node){
	xmlAttr * it = NULL;
	for (it = node->properties; it; it = it->next) {
		//	cout << it->name << "  " << it->children->content << "   " << node->children->content << endl;
		if (xmlStrEqual(it->name, xmlCharStrdup("name"))) {
			ContentStruct* content = new ContentStruct;
			content->name = it->children->content;
			content->value = node->children->content;
			return content;
		}
	}
	return NULL;
}

void Parser::parseTable(xmlNode * node, xmlChar* typeTable){
	xmlNode * it = NULL;
	// begining of the parser : 
	// each table identite define one boid
	// we need to add each boid to grid created by the constructor Parser()
	if (xmlStrEqual(typeTable, xmlCharStrdup("identite"))){
		int id_element = -1;
		char* name = NULL;
		char* url = NULL;
		char* description = NULL;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id-element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("name"))){
							name = (char*)content->value;
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("url"))){
							url = (char*)content->value;
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("descrption"))){
							description = (char*)content->value;
						}
					}
				}
			}
		}
		Boid* boid = new Boid(id_element, name, url, description);
		grid.addToGrid(boid);
	}
	// for each table localisation
	// we need to find the good boid by his id
	// and we set some values
	else if (xmlStrEqual(typeTable, xmlCharStrdup("localisation"))){
		int id_element = -1;
		char* lieu = NULL;
		//float* _gps[2] = { NULL };
		char* epoque = NULL;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("lieu"))){
							lieu = (char*)content->value;
						}
						/*else if (xmlStrEqual(content->name, xmlCharStrdup("gps"))){
							gps = (char*)content->value;
							}*/
						else if (xmlStrEqual(content->name, xmlCharStrdup("epoque"))){
							epoque = (char*)content->value;
						}
					}
				}
			}
		}
		Boid* boid = grid.findBoidById(id_element);
		boid->setLieu(lieu);
		//boid->setGPS(gps);
		boid->setEpoque(epoque);
	}
	// for each table localisation
	// we need to find the good boid by his id
	// and we set keywords
	// besides we need to stock the boid in the list of keywords created by DataBaseResource()
	else if (xmlStrEqual(typeTable, xmlCharStrdup("mot-cle"))){
		int id_element = -1;
		char* keyword = NULL;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("mot_cle"))){
							keyword = (char*)content->value;
						}
					}
				}
			}
		}
		Boid* boid = grid.findBoidById(id_element);
		boid->addKeyword(keyword);
		dataBaseResource.addBoidInListKeyword(keyword, boid);
	}
}

void Parser::parseDatabase(xmlNode * root){
	xmlNode * itNode = NULL;
	xmlAttr * itAttr = NULL;
	for (itNode = root->children; itNode; itNode = itNode->next) {
		if (itNode->type == XML_ELEMENT_NODE) {
			if (xmlStrEqual(itNode->name, xmlCharStrdup("table"))) {
				for (itAttr = itNode->properties; itAttr; itAttr = itAttr->next) {
					if (xmlStrEqual(itAttr->name, xmlCharStrdup("name"))) {
						// one node with the attribut <table> define one boid
						parseTable(itNode, itAttr->children->content);
					}
				}
			}
		}
	}
}

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
