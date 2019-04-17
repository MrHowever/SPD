#include <iostream>
#include "Schrage.hh"
#include "FileReader.hh"
#include "Heap.hh"

int main(int argc, char** argv) {

    Schrage schrage(FileReader::readFile(std::string(argv[1])));

    std::pair <Tasks,unsigned int> result = schrage.nlognPtmnOrder();
    std::cout<<"ORDER:\n";

    for(auto& elem : result.first)
        std::cout<<elem.id<<", ";

    std::cout<<"\nCmax = "<<result.second<<std::endl;
/*
    result = schrage.nlognOrder();
    std::cout<<"ORDER:\n";

    for(auto& elem : result.first)
        std::cout<<elem.id<<", ";

    std::cout<<"\nCmax = "<<result.second<<std::endl;
    */
}