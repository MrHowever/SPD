#include <iostream>
#include "ortools/linear_solver/linear_solver.h"

using namespace operations_research;

int main()
{
    MPSolver solver("simple_mip_program",CBC_MIXED_INTEGER_PROGRAMMING);


    return 0;
}