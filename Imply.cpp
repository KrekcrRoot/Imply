//
// Created by Code on 13.11.2022.
//

#include "header/Imply.h"
#include <fstream>
#include <regex>

std::string Imply::encrypt(std::string line)
{
    int key = (int) line[0];
    std::string result = std::to_string(key) + "@";

    for(auto letter : line)
    {
        int code = (int) letter - key;
        int separator = abs(code + 33);

        if(separator <= 33) separator += 33;
        if(separator >= 48 && separator <= 57) separator += 10;

        result += std::to_string(code);
        result += (char) separator;
    }

    return result;
}

std::vector<std::string> Imply::split(std::string line, const std::string &delimiter)
{
    std::vector <std::string> vec{};
    std::string token{};
    size_t pos;

    while((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        vec.push_back(token);
    }

    vec.push_back(line);
    return vec;
}

std::string Imply::decrypt(std::string line)
{
    int key = std::stoi(split(line, "@")[0]);
    line.erase(0, line.find('@') + 1);

    std::smatch smatched;
    std::regex reg {"-?\\d+"};
    bool founded{};
    std::string result{};

    while((founded = std::regex_search(line, smatched, reg)))
    {
        int letterCode = (std::stoi(smatched.str()) + key);
        result += (char) letterCode;
        line = smatched.suffix().str();
    }

    return result;
}
