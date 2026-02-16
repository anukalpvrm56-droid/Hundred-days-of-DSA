// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9


# include <stdio.h> 

int main() {
    int arr[100][100]; 
    int m, n; 
    scanf("%d %d", &m, &n );

    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
            scanf("%d", &arr[i][j]); 
        }
        printf("\n"); 
    }
    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
            printf("%d", arr[i][j]); 
        }
        printf("\n"); 
    }
    int sum = 0 ; 
    for ( int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j<n; j++) {
             if ( i == j ) {
                sum += arr[i][j]; 
             }
        }
        
    }
    printf("sum = %d", sum ) ; 
    
}