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
int FibonacciNumber(int n){
    if(n <= 1){
        return n;
    }
    int largestElement = FibonacciNumber(n-1);
    int secondLargestElement = FibonacciNumber(n-2);
    int nthFibNumber = largestElement + secondLargestElement;
    return nthFibNumber;
}

// Memoization code
int FibonacciNumberMemo(int n,vector<int> & dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int largestElement = FibonacciNumberMemo(n-1,dp);
    int secondLargestElement = FibonacciNumberMemo(n-2,dp);
    int nthFibNumber = largestElement + secondLargestElement;
    return dp[n] = nthFibNumber;
}

int TabulationFibonacciNumber(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int index = 2; index <= n; index++){
        dp[index] = dp[index-1] + dp[index-2];
    }
    return dp[n];
}

int spaceOptimizationFibNumber(int n){
    int prev1 = 0;
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
    int FibNumber =  FibonacciNumber(n);
    cout << FibNumber << endl;
}

