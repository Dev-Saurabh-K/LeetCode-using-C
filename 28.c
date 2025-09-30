#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);
    int k = 0;   

    if (n == 0) return 0;

    for (int i = 0; i <= m - n; i++) {
        k = i; 
        int j = 0;
        
        
        while (j < n && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == n) {
            return k; 
        }
    }
    return -1; 
}

int main() {
    char haystack[] = "leetcode";
    char needle[] = "code";

    int index = strStr(haystack, needle);

    if (index != -1)
        printf("First occurrence at index: %d\n", index);
    else
        printf("Substring not found.\n");

    return 0;
}
