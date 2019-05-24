#include <iostream>
#include "Schrage.hh"
#include "FileReader.hh"
#include "Heap.hh"
#include "Carlier.hh"

int main(int argc, char** argv) {

    for(int i = 1; i < argc; i++) {
        Tasks input = FileReader::readFile(std::string(argv[i]));
        Carlier carlier;
        unsigned int UB = 9999;
        carlier.order(UB, input);

        printf("%s Cmax = %d\n", argv[i], carlier.Cmax(carlier.bestPermutation));

        std::cout << "ORDER:\n";

        for (auto &elem : carlier.bestPermutation)
            std::cout << elem.id << ", ";

        std::cout<<std::endl<<std::endl;
    }
}