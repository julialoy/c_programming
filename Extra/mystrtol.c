#include <stdlib.h>
#include <stdio.h>

// Make a function mystrtol which behaves like the strtol function 

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
    printf("indexFirstChar is %d\n", indexFirstChar);
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

int checkBase(int base) {
    // Check for valid base
    if(base == 10 || base == 16) {
        return EXIT_SUCCESS;
    }
    else {
        printf("ERROR: Invalid base. Must be 10 or 16.\n");
        return EXIT_FAILURE;
    }
}

long mystrol(const char * str, const char ** endptr, int base) {
    // Currently pointer correct inside function, incorrect once function ends
    
    // Check for valid base
    if(checkBase(base) == 1) {
        return 0;
    }

    // Check that a string is provided
    if(str[0] == '\0') {
        printf("ERROR: No string provided\n");
        return 0;
    }

    int charIndex = findFirstChar(str);
    const char * charptr = &str[charIndex];
    printf("Charptr is %c\n", *charptr);
    printf("Charptr should be %c\n", str[charIndex]);
    endptr = &charptr;
    printf("Endptr inside function is %c\n", **endptr);
    // Convert the numbers to an integer
    if(charIndex > 0) {
        // Convert the numbers from string to integer
        // return the integer
        long myInt = convertStrToInt(charIndex, str);
        //printf("Your number is: 0x%2X\n", myInt);
        return myInt;
    }
    else if(charIndex == 0) {
        // If the first character of the string cannot be converted
        // to an integer print an error message and return 0
        //endptr = 
        printf("ERROR: This string does not start with a number\n");
        return 0;
    }
    else {
        // Return 0 if function encounters a different case
        return 0;
    }
}

int main(void) {
    const char * str = "5000xyz";
    const char ** endptr = &str;
    int base = 10;
    printf("Here is endptr at init: %c\n", **endptr);
    long mynum = mystrol(str, endptr, base);
    printf("0x%2lX or %ld\n", mynum, mynum);
    printf("Here is endptr after function: %c\n", **endptr);
    return EXIT_SUCCESS;
}
