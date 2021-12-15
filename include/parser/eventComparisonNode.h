#pragma once

#include "node.h"

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison, const string&);
    bool Evaluate(const Date&, const string&) const override;
private:
    const string event_;
    const Comparison cmp_;
};