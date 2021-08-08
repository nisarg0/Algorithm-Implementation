// Maximum size square Sub-Matrix with sum less than or equals to K
// Link -> geeksforgeeks.org/maximum-size-square-sub-matrix-with-sum-less-than-or-equals-to-k/

// Step 1: Find Prefix matrix sum[i][j] = arr[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
// Step 2: Iterate over all i and j (N^2)
// Step 3: Do binary search over all possible square sizes. min(i,j);
// Step 4: Check if square sum is less than equals to k

