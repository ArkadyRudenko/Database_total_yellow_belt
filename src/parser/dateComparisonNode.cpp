#include "dateComparisonNode.h"

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& d)
    : date_(d), cmp_(cmp) {};

bool DateComparisonNode::Evaluate(const Date& date, const string& event)  const {
    return ComparisonStringOrEvent(cmp_, date_, date);
}