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
            vector<int> & subArray, vector<vector<int>> &resultContainer)
{

    // base condition
    if (currentIndex == arr.size())
    {
        resultContainer.push_back(subArray);
        for(auto num : subArray){
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // take the current element,call for next elements
    subArray.push_back(arr[currentIndex]);
    helper(currentIndex + 1, arr, subArray, resultContainer);
    // not take the current element, call for next elements,
    // [before gonna to current state, you have to take out the previous state of the array]
    // this concept helps you to learn REACT.STATE!
    // [count,setCount] = useState(0)
    subArray.pop_back();
    helper(currentIndex + 1, arr, subArray, resultContainer);
    return;
}

int main()
{
    vector<int> arr = {2,1,3};
    vector<vector<int>> resultContainer;
    vector<int> subArray;
    int currentIndex = 0;
    helper(currentIndex, arr, subArray, resultContainer);
    
    cout << "final result" << endl;
    for(auto nums : resultContainer){
        for(auto it : nums){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}