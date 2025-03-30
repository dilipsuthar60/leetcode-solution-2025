class Solution {
public:
    int find(vector<int>&nums, int low,int high){
        int pivotElement=nums[high];
        int pivotIndex=low;
        for(int i=low;i<high;i++){
            if(nums[i]<=pivotElement){
                swap(nums[i],nums[pivotIndex]);
                pivotIndex++;
            }
        }
        swap(nums[high],nums[pivotIndex]);
        return pivotIndex;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        return nums[k-1];
        int n=nums.size();
        int low=0,high=n-1;
        k=n-k;
        while(true){
            int pivot = find(nums,low,high);
            if(pivot==k){
                return nums[pivot];
            }
            if(pivot<=k){
                low=pivot+1;
            }
            else{
                high=pivot-1;
            }
        }
        return -1;
    }
};