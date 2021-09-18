#pragma once

#include "command.h"

class PrintCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};