#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

int main() {
    char *content;
    // file reading
    FILE *f = fopen("/Users/btwael/Downloads/longtextfile.txt", "r+");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    content = (char *) malloc(fsize + 1);
    fread(content, fsize, 1, f);
    fclose(f);

    std::string string(content);

    std::vector<std::string> lines;
    unsigned long last = 0;
    for(unsigned long i = 0; i < string.size(); i++) {
        int c = string.at(i);
        if(c == '\n') {
            lines.push_back(string.substr(last, last - i));
            last = i;
        }
    }

    // free content
    free(content);
    return 0;
}
