#include "node.h"

//template<typename T>
//bool ComparisonStringOrEvent(Comparison cmp_,const T& lhs,const T& rhs) {
//        if (cmp_ == Comparison::Equal) {
//		    return lhs == rhs;
//	    }
//        else if(cmp_ == Comparison::NotEqual){
//		    return lhs != rhs;
//	    }
//        else if(cmp_ == Comparison::NotEqual){
//		    return lhs != rhs;
//	    }
//        else if(cmp_ == Comparison::LessOrEqual){
//		    return lhs >= rhs;
//	    }
//        else if(cmp_ == Comparison::Less){
//		    return lhs > rhs;
//	    }
//        else if(cmp_ == Comparison::GreaterOrEqual){
//		    return lhs <= rhs;
//	    }
//        else if(cmp_ == Comparison::Greater){
//		    return lhs < rhs;
//	    }
//        else {
//            throw logic_error("Unknown comparison token");
//        }
//}