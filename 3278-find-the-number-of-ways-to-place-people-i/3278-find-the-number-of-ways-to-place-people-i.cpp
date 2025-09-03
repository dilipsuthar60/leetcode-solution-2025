class Solution {
public:
    int numberOfPairs(vector<vector<int>>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            int x1=nums[i][0];
            int y1=nums[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=nums[j][0];
                int y2=nums[j][1];
                bool invalid=false;
                if(x1<=x2&&y1>=y2){
                    for(int k=0;k<n;k++){
                        if(i==k||j==k) continue;
                        int x3=nums[k][0];
                        int y3=nums[k][1];
                        if((x1<=x3&&x3<=x2)&&(y2<=y3&&y3<=y1)){
                            invalid=true;
                            break;
                        }
                    }
                    if(!invalid) result++;
                }
            }
        }
        return result;
    }
};