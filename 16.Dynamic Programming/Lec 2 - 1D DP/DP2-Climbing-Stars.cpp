#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// Problem Statement:  Introduction To Dynamic Programming
// In this article, we will be going to understand the concept of dynamic programming.
// Dynamic Programming can be described as storing answers to various sub-problems to be used later whenever required to solve the main problem.
// The two common dynamic programming approaches are:
// Memoization: Known as the “top-down” dynamic programming, usually the problem is solved in the direction of the main problem to the base cases.
// Tabulation: Known as the “bottom-up" dynamic programming, usually the problem is solved in the direction of solving the base cases to the main problem
// Note: The base case does not always mean smaller input. It depends upon the implementation of the algorithm.

// Recursion [Try all possible ways]
// Try to express everything in term of indexes
// Do all the stuff that index
// According to problem statement(max,min,sumup,shortest,largest)

// Recursion code
int ClimbingStars(int n){
    if(n <= 1){
        return 1;
    }
    int OneJump = ClimbingStars(n-1);
    int TwoJump = ClimbingStars(n-2);
    int nthFibNumber = OneJump + TwoJump;
    // short-cut
    // return ClimbingStars(n-1) + ClimbingStars(n-2);
    return nthFibNumber;
}

// Memoization code
int ClimbingStarsMemo(int n,vector<int> & dp){
    if(n <= 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int OneJump = ClimbingStarsMemo(n-1,dp);
    int TwoJump = ClimbingStarsMemo(n-2,dp);
    int nthFibNumber = OneJump + TwoJump;
    return dp[n] = nthFibNumber;
}

int TabulationClimbingStars(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    for(int index = 2; index <= n; index++){
        dp[index] = dp[index-1] + dp[index-2];
    }
    return dp[n];
}

int spaceOptimizationFibNumber(int n){
    int prev1 = 1;
    int prev2 = 1;
    int curr = 0;

    for(int i = 2; i<=n; i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev1;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    // just try to understand working of not!
    int FibNumber =  ClimbingStars(n);
    cout << FibNumber << endl;
}

