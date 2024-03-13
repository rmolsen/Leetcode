#include <stdbool.h>

int romanToInt(char* s) {
    int counter = 0;
    int total = 0;

    // Find value
        int nextCharValue;
        int charValue = 0;

    while(true) {
        char x = *(s + counter);
        
        switch(x) {
            case 'M': nextCharValue = 1000;
                        break;
            case 'D': nextCharValue = 500;
                        break;
            case 'C': nextCharValue = 100;
                        break;
            case 'L': nextCharValue = 50;
                        break;
            case 'X': nextCharValue = 10;
                        break;
            case 'V': nextCharValue = 5;
                        break;
            case 'I': nextCharValue = 1;
                        break;
            default: nextCharValue = 0;
                        break;
        }

        // Handle no previous edge case
        if (charValue == 0 && nextCharValue != 0) {
            charValue = nextCharValue;
            counter++;
            continue;
        }

        // Last char
        if (nextCharValue == 0) {
            total = total + charValue;
            return total;
        }
        // Subtract edge case
        else if (charValue < nextCharValue) {
            total = total + nextCharValue - charValue;
            charValue = 0;
        }
        // Standard case
        else {
            total = total + charValue;
            charValue = nextCharValue;
        }

        counter++;
    }
}

int main() {
    // Expect 1994
    char input[7] = {'M','C','M','X','C','I','V'};
    int num = romanToInt(input);
}