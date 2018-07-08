#include "join.h"

#include <sstream>

std::string string::join(std::vector<std::string> words, char *sep) {
    if (words.size() == 0)
        return "";
    std::stringstream ss;
    ss << words[0];
    for (int i = 1; i < words.size(); i++)
        ss << sep << words[i];
    return ss.str();
}