class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string ans = "";
        unordered_map<char,int>freqMap;
        for(auto &ch:s) freqMap[ch]++;

        priority_queue<pair<int,char>>pq;

        for(auto &[key,value]:freqMap) pq.push({value,key});

        while(pq.size()>1){
            auto [freq1,char1]=pq.top();
            pq.pop();
            auto [freq2,char2]=pq.top();
            pq.pop();
            ans+=char1;
            ans+=char2;
            freq1--;
            freq2--;
            if(freq1){
                pq.push({freq1,char1});
            }
            if(freq2){
                pq.push({freq2,char2});
            }
        }
        if(pq.size()){
            auto [freq1,char1]=pq.top();
            pq.pop();
            if(freq1>1) return "";
            ans+=char1;
        }
        return ans;
    }
};