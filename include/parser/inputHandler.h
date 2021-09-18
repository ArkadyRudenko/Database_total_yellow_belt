#pragma once
#include "command.h"

class InputHandler {
public:
	bool handleInput(const string& command,
		std::istringstream& is, Database& db, std::ostream&);

private:
	Command* del;
	Command* find;
	Command* add;
	Command* last;
	Command* print;
};