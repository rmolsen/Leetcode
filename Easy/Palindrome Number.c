#include <stdint.h>
#include <stdbool.h>

/*
Given an integer x, return true if x is a 
palindrom, and false otherwise.
*/
bool isPalindrome(int x) {
    // Edge cases
    if(x == 0) {
        return true;
    }
    else if (x < 0) {
        return false;
    }

    // regenerate number backwards and compare
    int digit;

    // use 32 bit integers for larger numbers
    uint32_t remain = (uint32_t)x;
    uint32_t newNum = 0;

    while(remain > 0) {
        digit = remain % 10;
        remain = remain / 10;

        newNum = newNum * 10 + digit;

        if (newNum == x) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    isPalindrome(121);
}