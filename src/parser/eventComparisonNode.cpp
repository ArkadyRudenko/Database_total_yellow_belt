#include "eventComparisonNode.h"

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event)
    : event_(event), cmp_(cmp) {}

bool EventComparisonNode::Evaluate(const Date& data, const string& event) const {
    return ComparisonStringOrEvent(cmp_, event_, event);
}