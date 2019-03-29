//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_JOHNSONORDER_HH
#define SPD3_JOHNSONORDER_HH

#include "OrderingAlgorithm.hh"

class JohnsonOrder : public OrderingAlgorithm {

public:
    Order order(Tasks&);

private:
    Order johnsonsRule2(Tasks);
    Order johnsonsRule3(Tasks);
};


#endif //SPD3_JOHNSONORDER_HH
