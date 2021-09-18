#pragma once

#include "node.h"

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison, const Date&);
    bool Evaluate(const Date&, const string&) const override;
private:
    const Date date_;
    const Comparison cmp_;
};