#pragma once

#include "command.h"

class LastCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};
