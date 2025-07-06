class FindSumPairs {
public:
    unordered_map<int,int>mp;
    vector<int>nums2;
    vector<int>nums1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &element:nums2) mp[element]++;
        this->nums2=nums2;
        this->nums1=nums1;
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(auto &it:nums1){
            if(mp.find(tot-it)!=mp.end()){
                count+=mp[tot-it];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */