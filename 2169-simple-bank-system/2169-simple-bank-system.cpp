class Bank {
public:
    vector<long long>accounts;
    Bank(vector<long long>& balance) {
        for(auto &current:balance){
            accounts.push_back(current);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=accounts.size() &&account2<=accounts.size() &&accounts[account1-1]>=money){
            accounts[account1-1]-=money;
            accounts[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<=accounts.size()){
            accounts[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=accounts.size() && accounts[account-1]>=money){
            accounts[account-1]-=money;
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