#include <iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> v;
        int n =arr.size();
        
        int maximum=INT_MIN;
        
        for(int i =0;i<k;i++){
            maximum=max(maximum,arr[i]);
        }
        v.push_back(maximum);
        for(int i =k;i<n;i++){
            if(arr[i-k]==maximum){
                maximum=INT_MIN;
                for(int j=i-k+1; j <= i; j++){
                    maximum = max(maximum,arr[j]);
                }
            }
            else{
                maximum=max(maximum,arr[i]);
            }
            v.push_back(maximum);
        }
        return v;
    }
};