#include <stdlib.h>
#include <stdio.h>

// Make a function myatoiHex which behaves like the atoi function except:
// interprets the string as a hexadecimal (base 16) number instead of a decimal
// and does not use atoi or strtol

int exponent(int base, int exponent) {
    //Write function to calculate exponent
    int power = base;
    if(exponent == 1) {
        power = base;
    }
    else if(exponent == 0) {
        power = 1;
    }
    else {
        while(exponent >= 2){
            power *= base;
            exponent--;
        }
    }
    return power;
}

int findFirstChar(const char * str) {
    int indexFirstChar = -1;
    char p = str[0];
    int i = 0;
    while (p != '\0'){
        p = str[i];
        int charToInt = (p - '0');
        if(charToInt < 0 || charToInt > 9) {
            indexFirstChar = i;
            break;
        }
        i++;
        indexFirstChar = i;
    }
    return indexFirstChar;
}

int convertStrToInt(int charIndex, const char * str) {
    int myInt = 0;
    for (int j=0; j < charIndex; j++) {
        char currentItem = str[j];
        int expPower = charIndex - (j + 1);
        myInt += ((currentItem - '0') * (exponent(10, expPower)));
    }
    return myInt;
}

// Write function int myatoi(const char * str) without using atoi or strtol
int myatoi(const char * str){
    if(str[0] == '\0') {
        printf("ERROR: No string provided\n");
        return 0;
    }
    // Currently if string contains more than one zero or zeros in the tens, 
    // hundreds, etc., returns zero in the first case, removes the extra zeros
    // in the second and third cases

    // Once a character that is not 0-9 is found, function assumes nothing following
    // that character will be 0-9 and stops looking 
    // This is the intended function per course instructions
    int charIndex = findFirstChar(str);

    if(charIndex > 0) {
        int myInt = convertStrToInt(charIndex, str);
        //printf("Your number is: 0x%2X\n", myInt);
        return myInt;
    }
    else if(charIndex == 0) {
        printf("ERROR: This string does not start with a number\n");
        return 0;
    }
    else {
        return 0;
    }
}

int main(void) {
    printf("0x%2X\n", myatoi("50000"));
    return EXIT_SUCCESS;
}
