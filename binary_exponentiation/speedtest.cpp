#include <iostream>
#include <math.h>

using namespace std;

int exp_iterative(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

int exp_recursive(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int temp = exp_recursive(a, b / 2);
    int result = temp * temp;
    if (b % 2 == 1) {
        result *= a;
    }
    return result;
}

int main() {



    return 0;
}