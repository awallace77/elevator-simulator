#ifndef NC_STRAT_H
#define NC_STRAT_H

#include "AllocationStrategy.h"
#include <cstdlib>

// Nearest Car (NC) Strategy
class NCStrategy : public AllocationStrategy {
    public:
	NCStrategy();
	virtual Elevator* allocate(FloorRequest*, std::vector<Elevator*>, int);

};
#endif
