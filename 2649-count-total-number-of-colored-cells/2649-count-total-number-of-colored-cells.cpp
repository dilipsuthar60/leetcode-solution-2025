class Solution {
public:
    long long coloredCells(int n) {
        return 1+4*(1ll*n*(n-1)/2);
    }
};