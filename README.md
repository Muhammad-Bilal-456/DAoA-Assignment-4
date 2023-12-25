# DAoA-Assignment-4
## Part-A  Coin-Change Problem 
# Problem Description:
The Coin-Change problem involves finding the minimum number of coins required to make up a given sum of money using a given set of coin denominations. The denominations are specified as an array, and the goal is to minimize the number of coins needed to make up the desired sum. If it's not possible to make the exact sum with the given denominations, the algorithm should return -1.
# Solutions:
# 1. Greedy Approach:
The greedy approach for the Coin-Change problem involves selecting the largest possible denomination at each step until the desired sum is achieved. The steps are as follows:
    • Sort the array of denominations in descending order.
    • Iterate through the sorted denominations, and at each step, select the largest denomination that does not exceed the remaining sum.
    • Subtract the selected denomination from the remaining sum and increment the coin count.
    • Repeat until the remaining sum becomes zero.
# Asymptotic Upper Bound Analysis:
        ◦ Time Complexity: The time complexity of the greedy approach is dominated by the sorting step, which is O(N log N), where N is the number of denominations. The subsequent loop has a linear time complexity, so the overall time complexity is O(N log N).
        ◦ Space Complexity: The space complexity is O(1) as the algorithm only uses a constant amount of additional space for variables.
# 2. Dynamic Programming Approach:
The dynamic programming approach for the Coin-Change problem involves building a dynamic programming table to store the minimum number of coins required to make up each possible sum from 0 to the target sum. The steps are as follows:
    • Create a dynamic programming array (dp) with a size of MAX_SIZE to store the minimum number of coins for each sum.
    • Initialize the array with a large value (representing infinity) except for dp[0], which is set to 0.
    • Iterate through each sum from 1 to the target sum and for each coin denomination.
    • Update the dp array if using the current coin reduces the number of coins needed for the current sum.
    • The final result is stored in dp[sum], and if it's still set to the initial large value, return -1 as the target sum is not achievable.
# Asymptotic Upper Bound Analysis:
        ◦ Time Complexity: The time complexity is O(N * sum), where N is the number of denominations and sum is the target sum. This is because, for each sum, the algorithm iterates through all denominations, resulting in a nested loop. The space complexity is also O(sum) due to the dynamic programming table.
        ◦ Space Complexity: The space complexity is O(sum) due to the dynamic programming table, which stores the minimum number of coins needed for each sum.
In general, the greedy approach is faster but may not always provide an optimal solution. The dynamic programming approach guarantees an optimal solution but may require more time and space, especially for large target sums. The choice between the two approaches depends on the specific requirements and constraints of the problem at hand.
**
**************************
