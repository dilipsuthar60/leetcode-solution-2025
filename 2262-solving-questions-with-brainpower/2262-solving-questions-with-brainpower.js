var mostPoints = function(nums) {
    let n=nums.length;
    let dp=new Array(n+1);
    dp.fill(0);
    for(let i=n-1;i>=0;i--){
        dp[i]=Math.max(dp[i+1],nums[i][0]+dp[Math.min(i+nums[i][1]+1,n)]);
    }
    return dp[0];
};