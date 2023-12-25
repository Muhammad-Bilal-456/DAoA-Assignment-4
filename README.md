# DAoA-Assignment-4
# Part-A  Coin-Change Problem 
## Problem Description:
The Coin-Change problem involves finding the minimum number of coins required to make up a given sum of money using a given set of coin denominations. The denominations are specified as an array, and the goal is to minimize the number of coins needed to make up the desired sum. If it's not possible to make the exact sum with the given denominations, the algorithm should return -1.
## Solutions:
## 1. Greedy Approach:
The greedy approach for the Coin-Change problem involves selecting the largest possible denomination at each step until the desired sum is achieved. The steps are as follows:
    • Sort the array of denominations in descending order.
    • Iterate through the sorted denominations, and at each step, select the largest denomination that does not exceed the remaining sum.
    • Subtract the selected denomination from the remaining sum and increment the coin count.
    • Repeat until the remaining sum becomes zero.
### Asymptotic Upper Bound Analysis:
        ◦ Time Complexity: The time complexity of the greedy approach is dominated by the sorting step, which is O(N log N), where N is the number of denominations. The subsequent loop has a linear time complexity, so the overall time complexity is O(N log N).
        ◦ Space Complexity: The space complexity is O(1) as the algorithm only uses a constant amount of additional space for variables.
## 2. Dynamic Programming Approach:
The dynamic programming approach for the Coin-Change problem involves building a dynamic programming table to store the minimum number of coins required to make up each possible sum from 0 to the target sum. The steps are as follows:
    • Create a dynamic programming array (dp) with a size of MAX_SIZE to store the minimum number of coins for each sum.
    • Initialize the array with a large value (representing infinity) except for dp[0], which is set to 0.
    • Iterate through each sum from 1 to the target sum and for each coin denomination.
    • Update the dp array if using the current coin reduces the number of coins needed for the current sum.
    • The final result is stored in dp[sum], and if it's still set to the initial large value, return -1 as the target sum is not achievable.
### Asymptotic Upper Bound Analysis:
        ◦ Time Complexity: The time complexity is O(N * sum), where N is the number of denominations and sum is the target sum. This is because, for each sum, the algorithm iterates through all denominations, resulting in a nested loop. The space complexity is also O(sum) due to the dynamic programming table.
        ◦ Space Complexity: The space complexity is O(sum) due to the dynamic programming table, which stores the minimum number of coins needed for each sum.
In general, the greedy approach is faster but may not always provide an optimal solution. The dynamic programming approach guarantees an optimal solution but may require more time and space, especially for large target sums. The choice between the two approaches depends on the specific requirements and constraints of the problem at hand.
# Part-B   Longest-Common Subsequence (LCS) Problem 
## Problem Description:
The Longest Common Subsequence (LCS) problem involves finding the longest subsequence common to two given sequences. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. For the LCS problem, the elements of the subsequence are not required to occupy consecutive positions within the original sequences.
Given two sequences, S1 and S2, the objective is to find a common subsequence, Z. Z must be a subsequence of both S1 and S2, and the indices of the elements chosen from the original sequences must be in ascending order.
## Solutions: 
## 1.Simple Recursion
The simple recursive solution involves exploring all possible subsequences and finding the length of the LCS. The base case is when either of the sequences is empty. If the last elements of both sequences match, the length of the LCS is incremented, and the recursion continues with the rest of the sequences.
### Asymptotic Analysis:
        ◦ The time complexity is exponential, O(2^(m+n)), where m and n are the lengths of the input sequences S1 and S2.
        ◦ The recurrence relation is T(m, n) = T(m-1, n) + T(m, n-1) + O(1).
## 2.Dynamic Programming
The dynamic programming solution involves creating a table (2D array) to store the length of the LCS for different subproblems. The table is filled iteratively, and the final value in the bottom-right corner represents the length of the LCS.
### Asymptotic Analysis:
        ◦ The time complexity is O(m * n), where m and n are the lengths of the input sequences S1 and S2.
        ◦ The space complexity is also O(m * n) due to the dynamic programming table.
        ◦ The recurrence relation is T(m, n) = O(1), as each entry in the table is computed once.
### Conclusion:
The dynamic programming solution is often preferred for practical applications where efficiency is crucial.


**
**************************
