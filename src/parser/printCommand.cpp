#include "printCommand.h"

void PrintCommand::Execute(std::istringstream& is, Database& db, std::ostream& out) {
	db.Print(out);
}