/*
* Parser.h
*
*  Created on: 2014
*      Author: kristen
*/
#pragma once

#include "Boid.h"
#include "DataBaseResources.h"
#include "Grid.h"
#include "Global.h"
#include "textureLoader.h"


//
// MAYBE TO DELETE
//
#include <libxml/tree.h>
#include <libxml/parser.h>

struct ContentStruct
{
	xmlChar* name;
	xmlChar* value;
};

class Parser{
public:
	Parser();
	Grid grid;
	DataBaseResource dataBaseResource;

	//parse the file fileXML
	void parse(string fileXML);

private:
	ContentStruct* parseNode(xmlNode * node); // parse one line Column
	void parseTable(xmlNode * node, xmlChar* typeTable); //parse one table
	void parseDatabase(xmlNode * root); //parse database


};