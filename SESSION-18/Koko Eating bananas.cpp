class Solution {
public:
    long long cc(int mid, vector<int>& piles){
        long long c=0;
        for(int i =0;i<piles.size();i++){
            c += (piles[i] + mid - 1) / mid;
        }
        return c;
    }

    int minEatingSpeed(vector<int>& piles,int h){
        int n = piles.size();
        int first =1;
        int last =*max_element(piles.begin(),piles.end());
        int ans =last;
        while(first<=last){
            int mid = first+(last-first)/2;
            long long hours =cc(mid,piles);
                if(hours<=h){
                ans =mid;
                last =mid-1;
            }else{
                first =mid+1;
            }
        }
        return ans;
    }
};