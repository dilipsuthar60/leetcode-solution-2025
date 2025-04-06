class Router {
public:
    int limit;
    set<vector<int>>s;
    deque<vector<int>>dq;
    unordered_map<int,vector<int>>mp;
    unordered_map<int,int>remove;
    Router(int memoryLimit) {
      limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>nums={source, destination,timestamp};
        if(s.find(nums)!=s.end()) return false;
        dq.push_back(nums);
        mp[destination].push_back(timestamp);
        s.insert(nums);
        if(dq.size()>limit){
            auto nums=dq.front();
            dq.pop_front();
            remove[nums[1]]++;
            s.erase(nums);
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        auto nums=dq.front();
        remove[nums[1]]++;
        dq.pop_front();
        s.erase(nums);
        return nums;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(mp.find(destination)==mp.end()){
            return 0;
        }
        auto &nums=mp[destination];
        int l=lower_bound(nums.begin(),nums.end(), startTime)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(), endTime)-nums.begin();
        return max(0,r-max(l,remove[destination]));
    }
};
