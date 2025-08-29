class Solution {
public:
    long long flowerGame(int n, int m) {

        return (1ll*(((n+1ll)/2)*(m*1ll/2)))+(1ll*((n*1ll/2)*((m+1ll)/2)));
    }
};