class Solution {
public:
    int find(vector<int>&nums1,vector<int>&nums2,int value){
        int counter1=0, counter2=0;
        for(int i=0;i<nums1.size();i++){
            if((nums1[i]!=value)&&(nums2[i]!=value)) 
                return INT_MAX;
            if(nums1[i]!=value) counter1++;
            if(nums2[i]!=value) counter2++;
        }
        return min(counter1,counter2);
    }
    int minDominoRotations(vector<int>& nums1, vector<int>& nums2) {
        int operation1=find(nums1,nums2,nums1.front());
        int operation2=find(nums1,nums2,nums2.front());
        return (min(operation1,operation2)==INT_MAX)?-1:min(operation1,operation2);
    }
};