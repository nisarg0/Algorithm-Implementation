// Maximum size square Sub-Matrix with sum less than or equals to K
// Link -> geeksforgeeks.org/maximum-size-square-sub-matrix-with-sum-less-than-or-equals-to-k/

// Step 1: Find Prefix matrix sum[i][j] = arr[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
// Step 2: Iterate over all i and j (N^2)
// Step 3: Do binary search over all possible square sizes. min(i,j);
// Step 4: Check if square sum is less than equals to k


// Dungeon Game  Reach n,m from 1,1 and healtmust be always +ve while moving.
// Find starting health
// https://leetcode.com/problems/dungeon-game/

// Crux --> start from n-1,m-1 boz we need to know what will be elements next to know what to choose
