#include <iostream>
#include "Schrage.hh"
#include "FileReader.hh"
#include "Heap.hh"
#include "Carlier.hh"

int main(int argc, char** argv) {

    Tasks input = FileReader::readFile(std::string(argv[1]));
    Carlier carlier(input);
    unsigned int UB = 9999;
    carlier.order(UB);

    printf("bestCmax = %d, Cmax = %d",carlier.Cmax(carlier.bestPermutation),
                carlier.Cmax(carlier.tasks));

    std::cout<<"ORDER:\n";

    for(auto& elem : carlier.tasks)
        std::cout<<elem.id<<", ";
}