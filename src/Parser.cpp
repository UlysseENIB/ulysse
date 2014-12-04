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
	xmlAttr * it = new xmlAttr();
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
	xmlNode * it = new xmlNode();
	// begining of the parser : 
	// each table identite define one boid
	// we need to add each boid to grid created by the constructor Parser()
	if (xmlStrEqual(typeTable, xmlCharStrdup("identite"))){
		int id_element = -1;
		int id_parent = -1;
		char* name = NULL;
		char* picture = NULL;
		char* url = NULL;
		char* description = NULL;
		GLuint texId = NULL;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("id_parent"))){
							if (xmlStrEqual(content->name, xmlCharStrdup("NULL"))){
								id_parent = -1;
							}
							else{
								id_parent = atoi((char*)content->value);
							}
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("name"))){
							name = (char*)content->value;
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("picture"))){
							picture = (char*)content->value;
							TextureLoader* textureLoader = new TextureLoader();
							texId = textureLoader->init(picture);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("url"))){
							url = (char*)content->value;
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("development"))){
							description = (char*)content->value;
						}
					}
				}
			}
		}
		Boid* boid = new Boid(id_element, name, url, description, true, texId);
		grid.addToGrid(boid);
	}
	// for each table localisation
	// we need to find the good boid by his id
	// and we set some values
	else if (xmlStrEqual(typeTable, xmlCharStrdup("localisation"))){
		int id_element = -1;
		char* lieu = NULL;
		float* gps[2] = { NULL };
		float latitude;
		float longitude;
		char* epoque = NULL;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("locality"))){
							lieu = (char*)content->value;
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("latitude"))){
							latitude = atof((const char*)content->value);
							}
						else if (xmlStrEqual(content->name, xmlCharStrdup("longitude"))){
							longitude = atof((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("epoque"))){
							epoque = (char*)content->value;
						}
					}
				}
			}
		}
		Boid* boid = grid.findBoidById(id_element);
		boid->setLieu(lieu);
		boid->setGPS(latitude, longitude);
		boid->setEpoque(epoque);
	}
	// for each table localisation
	// we need to find the good boid by his id
	// and we set keywords
	// besides we need to stock the boid in the list of keywords created by DataBaseResource()
	else if (xmlStrEqual(typeTable, xmlCharStrdup("mots_cles"))){
		int id_element = -1;
		//char* keyword = NULL;
		std::vector<float> keywordVector;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("vecteur_mots_cles"))){
							//keywordVector = atoi((const char*)content->value;
							istringstream iss((char*)content->value);
							string word;
							while (iss >> word) {
								keywordVector.push_back(atof(word.c_str()));
							}
						}
					}
				}
			}
		}
		Boid* boid = grid.findBoidById(id_element);
		boid->setKeywordVector(keywordVector);
		//dataBaseResource.addBoidInListKeyword(keyword, boid);
	}
	else if (xmlStrEqual(typeTable, xmlCharStrdup("parent-enfants"))){
		int id_element = -1;
		int id_element_parent = -1;
		int id_element_enfant = -1;
		for (it = node->children; it; it = it->next) {
			if (it->type == XML_ELEMENT_NODE) {
				if (xmlStrEqual(it->name, xmlCharStrdup("column"))) {
					ContentStruct* content = parseNode(it);
					if (content != NULL){
						if (xmlStrEqual(content->name, xmlCharStrdup("id_element"))){
							id_element = atoi((const char*)content->value);
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("id_element_parent"))){
							//id_element_parent = atoi((const char*)content->value);
							if (xmlStrEqual(content->name, xmlCharStrdup("NULL"))){
								id_element_parent = -1;
							}
							else{
								id_element_parent = atoi((char*)content->value);
							}
						}
						else if (xmlStrEqual(content->name, xmlCharStrdup("id_element_enfant"))){
							//id_element_enfant = atoi((const char*)content->value);
							if (xmlStrEqual(content->name, xmlCharStrdup("NULL"))){
								id_element_enfant = -1;
							}
							else{
								id_element_enfant = atoi((char*)content->value);
							}
						}
					}
				}
			}
		}
		Boid* boid = grid.findBoidById(id_element);
		boid->setIdParent(id_element_parent);
		boid->addIdEnfant(id_element_enfant);
		dataBaseResource.addBoidInListIdEnfant(id_element_enfant, boid);
	}
}

void Parser::parseDatabase(xmlNode * root){
	xmlNode * itNode = new xmlNode();
	xmlAttr * itAttr = new xmlAttr();
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
		//printf("error: could not parse file %s\n", fileXML);
	}

	//Get root element to start parsing
	xmlNode * root = xmlDocGetRootElement(doc);

	xmlNode * itNode = new xmlNode();
	xmlAttr * itAttr = new xmlAttr();
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
