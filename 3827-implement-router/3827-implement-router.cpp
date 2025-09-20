class Router {
public:
    deque<string>dq;
    unordered_map<string,vector<int>>mp;
    unordered_map<int,vector<int>>destinationMap;
    int limit;
    Router(int memoryLimit) {
        this->limit=memoryLimit;
    }

    string hashKey(int a, int b, int c){
        return to_string(a)+"#"+to_string(b)+"#"+to_string(c);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key=hashKey(source, destination, timestamp);
        if(mp.find(key)!=mp.end()) return false;
        dq.push_back(key);
        mp[key]={source, destination, timestamp};
        destinationMap[destination].push_back(timestamp);
        if(dq.size()>limit){
            forwardPacket();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(!dq.size()) return {};
        string key=dq.front();
        dq.pop_front();
        vector<int>temp=mp[key];
        mp.erase(key);
        destinationMap[temp[1]].erase(destinationMap[temp[1]].begin());
        return temp;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destinationMap.find(destination)==destinationMap.end()) return 0;
        auto &it=destinationMap[destination];
        int i=lower_bound(it.begin(),it.end(), startTime)-it.begin();
        int j=upper_bound(it.begin(),it.end(), endTime)-it.begin();
        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */