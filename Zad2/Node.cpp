//
// Created by mrhowever on 24.03.19.
//

#include "Node.hh"

std::ostream& operator<<(std::ostream& Strm, Node& node)
{
    return Strm << "T: " << node.task << " M: " << node.machine << " TP: " << node.timePassed << " ";
}
