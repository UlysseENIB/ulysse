/*
* Parser.h
*
*  Created on: 2014
*      Author: kristen
*/
#ifndef PARSER_H_
#define PARSER_H_

#include "Boid.h"
#include "Grid.h"
#include "Global.h"

//
// MAYBE TO DELETE
//
#include <libxml/tree.h>
#include <libxml/parser.h>

class Parser{
public:
	Parser();
	void parseNode(xmlNode * node); // parse one line Column
	void parseTable(xmlNode * node); //parse one table
	void parseDatabase(xmlNode * root); //parse database
	void parse(string fileXML); //one file
private:
	Grid grid;
};


#endif /* PARSER_H_ */