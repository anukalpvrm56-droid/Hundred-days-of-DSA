// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (sorted array)

// Output:
// - Print unique elements only, space-separated

// Example:
// Input:
// 6
// 1 1 2 2 3 3

// Output:
// 1 2 3

// Explanation: Keep first occurrence of each element: 1, 2, 3

#include <stdio.h>

int main() {
    int arr[100]; 
    int n; 
    scanf("%d", &n);
    for ( int i =0 ; i< n ; i++) {
        scanf("%d", &arr[i]);
    }

    int k = 0 ; 

    for ( int i = 0 ; i<n ; i++) {
        if(arr[i] != arr[k]){
            k++;
            arr[k] = arr[i];
            
        }
    }

    for ( int i = 0 ; i<=k; i++) {
        printf("%d ", arr[i]);
    }
    return 0; 
}