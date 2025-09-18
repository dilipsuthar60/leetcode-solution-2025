class TaskManager {
public:
    unordered_map<int,pair<int,int>>mp;
    set<vector<int>,greater<vector<int>>>s;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task: tasks){
            this->add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId, priority};
        s.insert({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto temp=mp[taskId];
        mp.erase(taskId);
        s.erase({temp.second, taskId, temp.first});
        mp[taskId]={temp.first, newPriority};
        s.insert({newPriority, taskId, temp.first});
    }
    
    void rmv(int taskId) {
        auto temp=mp[taskId];
        mp.erase(taskId);
        s.erase({temp.second, taskId, temp.first});
    }
    
    int execTop() {
        if (s.size() == 0)
            return -1;
        auto it = *s.begin();
        s.erase(s.begin());
        return it[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */