#pragma once

#include "command.h"

class FindCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};