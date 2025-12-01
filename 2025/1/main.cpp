#include "dial.cpp"
#include <string>
#include <cstdio>
#include <fstream>

void spin(Dial& d) {
    const std::string filename = "input.txt";
    std::ifstream infile(filename);
    if (!infile.is_open()) return;
    char c;
    size_t n;
    while (infile >> c >> n) {
        if (c == 'L') {
            d.moveLeft(n);
        } else {
            d.moveRight(n);
        }
    }
    infile.close();
}

int main(void) {
    Dial d;
    spin(d);

    printf("PART ONE:\n");
    {
        size_t result = d.getPart1Result();
        printf("Password: %u\n", result);
    }
    printf("PART TWO:\n");
    {
        size_t result = d.getPart2Result();
        printf("Password: %u\n", result);
    }
    return 0;
}