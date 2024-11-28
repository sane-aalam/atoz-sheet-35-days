#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int firstPositionSortedArray(vector<int> & arr, int target){
        int startIndex = 0;
        int endIndex = arr.size() - 1;
        int mid = startIndex + (endIndex - startIndex)/2;

        // Why?
        // Reason to came into the left-half
        // we want to get first position element index
        // when we got the target value,then we need to store the index,make sure it would be firstly came element,
        // so, we will continue the search into the left side of sorted array 
        // tc - 0(logN)
        int gotFirstPosition = -1;

        while(startIndex <= endIndex){
            if(arr[mid] == target){
                gotFirstPosition = mid;
                endIndex = mid - 1;
            }else if(arr[mid] < target){
                startIndex = mid + 1;
            }else{
                endIndex = mid - 1;
            }
            // update the midindex
            mid = startIndex + (endIndex - startIndex)/2;
        }
        return gotFirstPosition;
    }
    int lastPositionSortedArray(vector<int> & arr, int target){
        int startIndex = 0;
        int endIndex = arr.size() - 1;
        int mid = startIndex + (endIndex - startIndex)/2;

        // Why?
        // Reason to came into the right-half
        // we want to get last position element index
        // when we got the target value,then we need to store the index,make sure it would be lastly came element,
        // so, we will continue the search into the right side of sorted array 
        // tc - 0(logN)
        int getLastPosition = -1;

        while(startIndex <= endIndex){
            if(arr[mid] == target){
                getLastPosition = mid;
                startIndex = mid + 1;
            }else if(arr[mid] < target){
                startIndex = mid + 1;
            }else{
                endIndex = mid - 1;
            }
            // update the midindex
            mid = startIndex + (endIndex - startIndex)/2;
        }
        return getLastPosition;
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int firstPosition = firstPositionSortedArray(arr,target);
        int lastPosition = lastPositionSortedArray(arr,target);
        cout << "firstIndex -> " << firstPosition << endl;
        cout << "lastIndex -> "<< lastPosition << endl;
        int countFreqElement = lastPosition - firstPosition + 1;

        // What if target is present into the array?
        // Think about this test case
        // target = 4 is not present in the given array so the output is 0.
        // both of function is return -1, which means to present into the sorted array 
        if(firstPosition == -1 && lastPosition == -1){
            return 0;
        }else{
            return countFreqElement;
        }
    }
};

// output:
// firstIndex -> -1
// lastIndex -> -1
// 0

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}