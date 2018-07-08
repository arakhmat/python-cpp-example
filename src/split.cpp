#include "split.h"

#include "string.h"
      

std::vector<std::string> string::split(char *s, char *sep, int maxsplit) {
    std::vector<std::string> tokens;
    char *token = s;
    char *end = s;
    int index = maxsplit;
    while(token && index-- != 0) {
        token = strsep(&end, sep);
        tokens.push_back(std::string(token, token + strlen(token)));
        token = end;
    };
    if (token)
        tokens.push_back(std::string(token, token + strlen(token)));
    return tokens;
}
