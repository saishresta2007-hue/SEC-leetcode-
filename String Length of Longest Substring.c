#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[128];
    
    for (int i = 0; i < 128; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (lastIndex[(int)s[i]] >= start) {
            start = lastIndex[(int)s[i]] + 1;
        }

        lastIndex[(int)s[i]] = i;

        int len = i - start + 1;
        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}