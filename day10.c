// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h> 
#include <string.h> 
int main() {
    char str[100]; 
    scanf("%s", &str); 
    int i = 0 ; 
    int j = strlen(str) -1; 
    while ( j> i ){
        if ( str[i] == str[j]) {
            i++; 
            j--; 
        }
        else{
            printf("%s", "no") ;
            return 0; 
        } 
    }
    printf("%s", "yes") ; 
}