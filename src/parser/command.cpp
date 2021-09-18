#include "command.h"

string ParseEvent(istream& is) {
	string event;
	is >> ws;
	getline(is, event);
	return event;
}









