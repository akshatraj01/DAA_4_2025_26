#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay,int m,int k,int day){
        int bouquets=0;
        int flowers=0;
        for(int i =0;i<bloomDay.size();++i){
            if(bloomDay[i]<=day){
                flowers++;
            }else{
                flowers=0;
            }
            if(flowers==k){
                bouquets++;
                flowers=0;
            }
            if(bouquets>=m){
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay,int m,int k){
        int n=bloomDay.size();
        if(n<m*k){
            return -1;
        }
        int left =*min_element(bloomDay.begin(),bloomDay.end());
        int right =*max_element(bloomDay.begin(),bloomDay.end());
        
        int result=-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(canMakeBouquets(bloomDay,m,k,mid)){
                result =mid;
                right =mid-1;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
};
