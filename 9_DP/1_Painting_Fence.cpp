#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{
    if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));

    int ans = (solveUsingRecursion(n-2,k) + solveUsingRecursion(n-1,k))*(k-1);
    return ans;
}   

int solveUsingMem(int n,int k, vector<int>&dp)
{
     if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));
    if(dp[n] != -1) return dp[n];

    dp[n] = (solveUsingMem(n-2,k,dp) + solveUsingMem(n-1,k,dp))*(k-1);
    return dp[n];
}
int solveUsingTab(int n, int k)
{
     vector<int>dp(n+1,-1);
     dp[1] = k;
     dp[2] = (k*k);

     for(int i = 3;i<=n;i++)
     {
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);

     }
     return dp[n];
}

int solveUsingSpace(int n , int k)
{
    int prev1 = k;
    int prev2 = (k*k);

    for(int i = 3;i<=n;i++)
    {
        int curr = (prev2 + prev1)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n = 4;
    int k = 3;
    // int ans = solveUsingRecursion(n,k);

    // vector<int>dp(n+1,-1);
    // int ans = solveUsingMem(n,k,dp);

    // int ans = solveUsingTab(n,k);

    int ans = solveUsingSpace( n, k);
    cout<<"Ans is: "<<ans<<endl;

    return 0;
}