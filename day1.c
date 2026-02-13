/*
Problem: Write a C program to inser an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include <stdio.h>

int main() {
    int n ;
    scanf("%d", &n);
    int arr[n];
    

    for ( int i = 0 ; i< n ; i ++ ) {
        scanf("%d", &arr[i]);
    }

    int poss;
    int elem;

    scanf("%d",&poss);
    scanf("%d",&elem);

    n++;

    for( int i = n ; i>=poss; i--) {
        arr[i] = arr[i-1];
        
    }
    
    arr[poss-1] = elem;
    
    for ( int i = 0 ; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0; 

}
