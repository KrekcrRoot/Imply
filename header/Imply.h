//
// Created by Code on 13.11.2022.
//

#ifndef IMPLY_IMPLY_H
#define IMPLY_IMPLY_H

#include <string>
#include <vector>

namespace Imply
{
    std::string encrypt(std::string line);
    std::vector<std::string> split(std::string line, const std::string& delimiter);
    std::string decrypt(std::string line);
}

#endif //IMPLY_IMPLY_H
