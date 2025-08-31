class Solution {
public:
    vector<int>ans;
    int bestDiff=1e9;
    void check(vector<int>nums){
        sort(nums.begin(),nums.end());
        int diff=nums.back()-nums.front();
        if(diff<bestDiff){
            bestDiff = diff;
            ans=nums;
        }
    }
    void find(int n, int k, vector<int>&current){
        if(k==1){
            current.push_back(n);
            check(current);
            current.pop_back();
            return ;
        }
        for(int i=1;i<=n;i++){
            if(n%i==0){
                current.push_back(i);
                find(n/i,k-1, current);
                current.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int>current;
        find(n, k, current);
        return ans;
    }
};