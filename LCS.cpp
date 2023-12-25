#include <iostream>
#include <string>
using namespace std;
int lcsSimpleRecursion(string S1, string S2, int i, int j);
int lcsDynamicProgramming(string S1, string S2);
int main()
{
    string S1 = "ABCBDAB";
    string S2 = "BDCAB";
    int l1 = S1.length(), l2 = S2.length();
    int result = lcsSimpleRecursion(S1, S2, l1, l2);
    cout << "\nLCS Using Simple Recursion!\n";
    cout << "Length of LCS for String " << S1 << " and String " << S2 << " is: " << result << endl;
    result = lcsDynamicProgramming(S1, S2);
    cout << "________________________________________\n";
    cout << "LCS Using Dynamic Programming!\n";
    cout << "Length of LCS for String " << S1 << " and String " << S2 << " is: " << result << endl;
    return 0;
}
int lcsSimpleRecursion(string S1, string S2, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (S1[i - 1] == S2[j - 1])
    {
        return 1 + lcsSimpleRecursion(S1, S2, i - 1, j - 1);
    }
    else
    {
        int case1 = lcsSimpleRecursion(S1, S2, i - 1, j);
        int case2 = lcsSimpleRecursion(S1, S2, i, j - 1);
        return max(case1, case2);
    }
}
int lcsDynamicProgramming(string S1, string S2)
{
    int m = S1.length(), n = S2.length();
    int** dp = new int* [m + 1];
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int result = dp[m][n];
    for (int i = 0; i <= m; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}
