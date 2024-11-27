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

void helper(int currentIndex, vector<int> &arr,
            vector<int> &subArray,
            vector<vector<int>> &resultContainer,
            int &sum, int target)
{

    // base condition
    if (currentIndex == arr.size()){
        // there is any subsequence which sum is equal to k
        // store into the resultArray
        if (sum == target){
            resultContainer.push_back(subArray);
            for (auto num : subArray){
                cout << num << " ";
            }
            cout << endl;
            return;
        }
    }

    // take the current element,call for next elements
    sum = sum + arr[currentIndex];
    subArray.push_back(arr[currentIndex]);
    helper(currentIndex + 1, arr, subArray, resultContainer, sum, target);
    // not take the current element, call for next elements,
    // [before gonna to current state, you have to take out the previous state of the array]
    // this concept helps you to learn REACT.STATE!
    // [count,setCount] = useState(0)
    // backtracking concept!
    sum = sum - arr[currentIndex];
    subArray.pop_back();
    helper(currentIndex + 1, arr, subArray, resultContainer, sum, target);
    return;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<vector<int>> resultContainer;
    vector<int> subArray;
    int currentIndex = 0;
    int sum = 0;
    int target = 2; // which is equal to K
    helper(currentIndex, arr, subArray, resultContainer, sum, target);

    cout << "final result" << endl;
    for (auto nums : resultContainer){
        for (auto it : nums){
            cout << it << " ";
        }
        cout << endl;
    }

    cout << "end of code!" << endl;
    return 0;
}