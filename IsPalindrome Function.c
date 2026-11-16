#include <stdbool.h>

bool isPalindrome(int x) {
    // 1. Negative numbers cannot be palindromes (e.g., -121 reversed is 121-)
    //    Numbers ending in 0 (except 0 itself) cannot be palindromes (e.g., 10 reversed is 01)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int original = x;
    long long reversed = 0; // Use long long to completely avoid overflow errors
    
    // 2. Extract digits mathematically from right to left
    while (x > 0) {
        int remainder = x % 10;
        reversed = (reversed * 10) + remainder;
        x /= 10;
    }
    
    // 3. Check if the reversed number matches the original
    return (original == reversed);
}


