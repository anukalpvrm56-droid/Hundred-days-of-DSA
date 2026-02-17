// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1
#include <stdio.h> 
#include <limits.h> 
int main() {
    int arr[100]; 

    int n ; 
    scanf( "%d ", &n) ; 

    for ( int i = 0 ; i< n ; i++ ) {
        scanf("%d", &arr[i]) ; 

    }

    int max = INT_MIN ; 
    for ( int i = 0 ; i< n ; i++) {
        if (arr[i]  >  max ) {
            max = arr[i] ; 
        } 
    } 
    printf("%d", max) ; 

    int min = INT_MAX ; 
    for ( int i = 0 ; i< n ; i++ ) {
        if ( arr[i] < min ) {
            min = arr[i] ; 
        }
    }
    printf("\n%d", min) ; 
    return 0 ; 
}