class Solution {
public:
    bool find(vector<int>&nums,long long time,int cars){
        for(int i=0,n=nums.size();i<n;i++){
            long long processingCar=sqrt(time/nums[i]);
            cars-=processingCar;
            if(cars<=0) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0;
        long long r=1e18;
        while(l<=r){
            long long mid=(l+r)/2;
            if(find(ranks,mid,cars)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};