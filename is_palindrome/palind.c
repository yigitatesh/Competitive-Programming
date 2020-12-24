#include <stdio.h>

int is_palindrome(char * first) {
    char * raw_first = first;
    char * last;
    last = first;
    int size = 0;
    while (*last != '\0') {
        last++;
        size++;
    }
    last--;

    for (int i=0; i<size/2; i++) {
        if (*first != *last) {
            printf("%s", raw_first);
            printf(" palindrome değildir.\n");
            return 0;
        }
        first++;
        last--;
    }
    printf("%s", raw_first);
    printf(" palindromdur.\n");
    return 1;
}

int main() {
    is_palindrome("ada");
    is_palindrome("abccba");
    is_palindrome("abcbad");

    return 0;
}