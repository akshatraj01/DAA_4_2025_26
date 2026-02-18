#include <iostream>
#include <vector>
using namespace std;

int lwr(const vector<int>& arr,int target){
    int lft=0,ryt=arr.size();
    
    while(lft<ryt){
        int mid=lft+(ryt-lft)/2;
        
        if(arr[mid]<target){
            lft=mid+1;
        }else{
            ryt=mid;
        }
    }
        return lft;
}

int upr(const vector<int>& arr,int target){
    int lft=0,ryt=arr.size();
    while (lft<ryt){
        int mid=lft+(ryt-lft)/2;
        
        if(arr[mid]<=target){
            lft=mid+1;
        }else{
            ryt = mid;
        }
    }
    return lft;
}

int main(){
    vector<int>arr={1,2,2,3,4,4,5,6};
    
    int target=4;
    int lower=lwr(arr,target);
    int upper=upr(arr,target);
    return 0;
}
