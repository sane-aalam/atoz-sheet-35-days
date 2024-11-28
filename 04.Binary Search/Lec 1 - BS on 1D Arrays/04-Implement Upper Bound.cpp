
// Problem statement -->
// Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

// Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
// Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

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

// Algorithm used here ): 
// floor of element -> smallest element index into sorted array, if element is not present 
// ceil of element -> largest element index into sorted array, if element is not present 

class Solution {
  private:
    int getFloor(vector<int> & arr, int x){

        // floor of element -> smallest element index into sorted array, if element is not present 
        // ceil of element -> largest element index into sorted array, if element is not present 
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;
        int floorIndex = -1;

        while(start <= end){
            mid = start + (end-start)/2;
            if(arr[mid] == x){
                return mid;
            }else if(arr[mid] < x){
                floorIndex = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return floorIndex;
    }
    int getCeil(vector<int> & arr, int x){
         // floor of element -> smallest element index into sorted array, if element is not present 
        // ceil of element -> largest element index into sorted array, if element is not present 
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;
        int ceilValue = -1;

        while(start <= end){
            mid = start + (end-start)/2;
            if(arr[mid] == x){
                return mid;
            }else if(arr[mid] < x){
                start = mid + 1;
            }else{
                ceilValue = mid;
                end = mid - 1;
            }
        }
        return ceilValue;
    }
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int floorValue = getFloor(arr,x);
        int ceilValue = getCeil(arr,x);
        return {floorValue,ceilValue};
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        for(auto it : ans){
            cout << it << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}