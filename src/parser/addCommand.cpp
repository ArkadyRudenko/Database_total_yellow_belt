#include "addCommand.h"

void AddCommand::Execute(std::istringstream& is, Database& db, std::ostream& out) {
	const auto date = ParseDate(is);
	if (date.year != -1) {
		const auto event = ParseEvent(is);
		db.Add(date, event);
	}
}