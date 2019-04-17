//
// Created by mrhowever on 16.04.19.
//

#include "FileReader.hh"
#include <fstream>

Tasks FileReader::readFile(std::string filename)
{
    std::ifstream input(filename);
    Tasks data;
    unsigned int rows = -1, cols = -1;
    input >> rows;
    input >> cols;

    for(unsigned int i = 0; i < rows; i++) {
            unsigned int r1,p1,q1;
            input >> r1;
            input >> p1;
            input >> q1;
            data.push_back(Task(r1,p1,q1,i));
        }

    return data;
}