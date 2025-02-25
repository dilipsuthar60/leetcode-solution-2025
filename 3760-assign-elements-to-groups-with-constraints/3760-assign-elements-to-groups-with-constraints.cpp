class Solution {
public:
    const int N=1e5+10;
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int>hash(N,-1);
        for(int i=0;i<elements.size();i++){
            if(hash[elements[i]]!=-1) continue;
            for(int j=elements[i];j<N;j+=elements[i]){
                if(hash[j]==-1){
                    hash[j]=i;
                }
            }
        }
        vector<int>ans;
        for(auto &it:groups){
            ans.push_back(hash[it]);
        }
        return ans;
    }
};