#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

string getInputs() {
    ifstream file("input.txt");
    if (!file.is_open()) exit(1);
    string buffer;
    getline(file, buffer);
    file.close();
    replace(buffer.begin(), buffer.end(), '-', ' ');
    replace(buffer.begin(), buffer.end(), ',', ' ');
    return buffer;
}

int digits(long x) {
    int result = 0;
    if (x == 0) return 1;
    while (x > 0) {
        x /= 10;
        result++;
    }
    return result;
}

bool isFalseID(long x) {
    int d = digits(x);
    int a = 1;
    for (int i = 0; i < d / 2; i++) a *= 10;
    int f = x / a;
    int s = x - a * f;
    return f == s;
}

void FalseIDDebug(long start, long end) {
    printf("<%ld, %ld>: ", start, end);
    for (long i = start; i <= end; ++i) {
        if(isFalseID(i)) printf("%ld ", i);
    }
    printf("\n");
}

long long FalseIDSum(long start, long end) {
    long long sum = 0;
    for (long i = start; i <= end; ++i) {
        if(isFalseID(i)) sum += i;
    }
    return sum;
}

vector<long> parseToLongVector(const string& int_string) {
    std::vector<long> long_vector;
    std::stringstream ss(int_string);
    long number;
    while (ss >> number) {
        long_vector.push_back(number);
    }
    return long_vector;
}

void test() {
   FalseIDDebug(11, 22);
   FalseIDDebug(95, 115);
   FalseIDDebug(998, 1012);
   FalseIDDebug(1188511880, 1188511890);
   FalseIDDebug(222220,222224);
   FalseIDDebug(1698522,1698528);
   FalseIDDebug(446443,446449);
   FalseIDDebug(38593856,38593862);
}

int main (void) {
    // test();
    string s = getInputs();
    vector<long> v = parseToLongVector(s);
    long long sum = 0;
    for (int i = 0; i < v.size() - 1; i += 2) {
        sum += FalseIDSum(v[i], v[i + 1]);
    }
    printf("Part 1: %lld\n", sum);
    return 0;
}