#include <bits/stdc++.h>
using namespace std;

// Note: If multiple occurrences are there, please return the smallest index.
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int startIndex = 0;
        int endIndex = arr.size() - 1;
        // integer overflow error control
        int mid = startIndex + (endIndex - startIndex)/2;
        int result = -1;
        while(startIndex <= endIndex){
            if(arr[mid] == k){
                result = mid;
                endIndex = mid - 1;
            }else if(arr[mid] < k){
                startIndex = mid + 1;
            }else{
                endIndex = mid - 1;
            }
            // update the midindex
            mid = startIndex + (endIndex - startIndex)/2;
        }
        return result;
    }
};