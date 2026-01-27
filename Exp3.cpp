#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<char>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    int maxlen=0;

    for(int i=0;i<n;i++){
        if(arr[i]=='P')
            sum+=1;
        else
            sum-=1;
        if(mp.find(sum)!=mp.end()){
            maxlen=max(maxlen,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    cout<<maxlen<<endl;
    return 0;
}