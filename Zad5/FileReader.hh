//
// Created by mrhowever on 16.04.19.
//

#ifndef ZAD5_FILEREADER_HH
#define ZAD5_FILEREADER_HH
#include <vector>
#include <string>
#include "Task.hh"

typedef std::vector<Task> Tasks;

class FileReader {
public:
    static Tasks readFile(std::string);
};


#endif //ZAD5_FILEREADER_HH
