#pragma once
#include "database.h"
#include "condition_parser.h"

#include <string>
#include <sstream>

string ParseEvent(istream&);

class Command {
public:
	virtual void Execute(std::istringstream& is, Database& db, std::ostream&) = 0;
};

