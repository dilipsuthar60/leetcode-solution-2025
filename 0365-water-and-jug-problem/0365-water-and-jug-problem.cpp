class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<int>directions = {x, y, -x, -y};
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        while(q.size()){
            auto temp=q.front();
            q.pop();
            if(temp==target){
                return true;
            }
            for(auto &direction: directions){
                int current = temp + direction;
                if(current >= 0 && current <= x+y && visited.find(current) == visited.end()){
                    visited.insert(current);
                    q.push(current);
                }
            }
        }
        return false;
    }
};