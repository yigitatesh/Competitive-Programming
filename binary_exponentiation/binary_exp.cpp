#include <iostream>

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

int exp_with_modula(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

int main() {
    int a, b, m;
    m = 1000000007;
    
    while (true) {
        cout << "a, b: ";
        cin >> a >> b;
        if (a == 0) {
            break;
        }
        cout << "result 1: " << exp_recursive(a, b) << endl;
        cout << "result 2: " << exp_iterative(a, b) << endl;
        cout << "result 3: " << exp_with_modula(a, b, m) << endl;
    }

    return 0;
}