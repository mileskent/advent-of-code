#include <cstddef>
#include <cstdio>
#include <cstdlib>

class Dial {
private:
    const int MOD_BASE = 100;
    int position = 50;
    size_t landedOnZero = 0;
    size_t passedOverZero = 0;
    void moddecr() {
        position--;
        if (position < 0) position += MOD_BASE;
    }
    void modincr() {
        position++;
        if (position >= MOD_BASE) position = 0;
    }
    void step(bool incr) {
        if (incr) modincr(); else moddecr();
    }
    void move(int n) {
        if (n == 0) return;
        bool incr = n > 0;
        int lim = abs(n);
        for (int i = 0; i < lim; i++) {
            step(incr);
            if (position == 0) passedOverZero++;
        }
        if (position == 0) landedOnZero++;
    }
public:
    void moveRight(int n) {
        if (n >= 0) move(n);
    }
    void moveLeft(int n) {
        if (n >= 0) move(-n);
    }
    inline size_t getPart1Result() { return landedOnZero; }
    inline size_t getPart2Result() { return passedOverZero; }
};
