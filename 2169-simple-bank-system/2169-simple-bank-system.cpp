class Bank {
public:
    unordered_map<int,long long>mp;
    int size;
    Bank(vector<long long>& balance) {
        size=balance.size();
        for(int i=0;i<balance.size();i++){
            mp[i+1]=balance[i];
        }
    }
    bool isAccountSafe(int id){
        return id>=1&&id<=size;
    }
    bool transfer(int account1, int account2, long long money) {
        if(isAccountSafe(account1)&&isAccountSafe(account2)&&mp[account1]>=money){
            mp[account1]-=money;
            mp[account2]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(isAccountSafe(account)){
            mp[account]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(isAccountSafe(account)&&mp[account]>=money){
            mp[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */