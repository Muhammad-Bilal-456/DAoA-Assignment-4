#include <iostream>
#include <fstream>
using namespace std;
void sort(int arr[], int size);
int greedyCoinChange(int coins[], int numCoins, int sum);
int dynamicCoinChange(int coins[], int numCoins, int sum);
int main0() 
{
    ifstream inputFile("coinChange.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening input file.\n";
        return 1;
    }
    string currencyTitle, currencySymbol;
    int numDenominations;
    inputFile >> currencyTitle >> currencySymbol;
    inputFile >> numDenominations;
    int* denominations = new int[numDenominations]; 
    for (int i = 0; i < numDenominations; ++i)
    {
        string denomination;
        int value;
        inputFile >> denomination >> value;
        denominations[i] = value;
    }
    inputFile.close();
    cout << "Currency Title  : " << currencyTitle << endl;
    cout << "Currency Symbol : " << currencySymbol << endl;
    bool isGreedyPossible = true;
    if (isGreedyPossible) 
    {
        int sum;
        cout << "Enter the total sum required: ";
        cin >> sum;
        int greedyResult = greedyCoinChange(denominations, numDenominations, sum);
        if (greedyResult != -1) 
        {
            cout << "Greedy Approach is used!\n" << greedyResult << " coins are required\n";
        }
        else 
        {
            cout << "Greedy algorithm not suitable!\n";
            int dynamicResult = dynamicCoinChange(denominations, numDenominations, sum);
            cout << "Dynamic Programming Approach is used!\n" << dynamicResult << " coins are required\n";
        }
    }
    else 
    {
        cout << "Greedy algorithm not suitable!\n";
        int sum;
        cout << "Enter the total sum required: ";
        cin >> sum;
        int dynamicResult = dynamicCoinChange(denominations, numDenominations, sum);
        cout << "Dynamic Programming Approach is used!\n" << dynamicResult << " coins are required\n";
    }
    delete[] denominations; 
    return 0;
}
void sort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int greedyCoinChange(int coins[], int numCoins, int sum) 
{
    int coinCount = 0;
    sort(coins, numCoins);
    for (int i = 0; i < numCoins; ++i) 
    {
        while (sum >= coins[i]) 
        {
            sum -= coins[i];
            coinCount++;
        }
    }
    return (sum == 0) ? coinCount : -1;
}
int dynamicCoinChange(int coins[], int numCoins, int sum) 
{
    const int MAX_SIZE = 1000;
    int dp[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) 
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= sum; ++i) 
    {
        for (int j = 0; j < numCoins; ++j) 
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) 
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[sum] != INT_MAX) ? dp[sum] : -1;
}