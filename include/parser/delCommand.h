#pragma once

#include "command.h"

class DelCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};