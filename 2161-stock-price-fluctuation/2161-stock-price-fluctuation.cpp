class StockPrice {
public:
    map<long long,long long >mp;
    multiset<long long>s;
    
    StockPrice() 
    {
        mp.clear();
        s.clear();
    }
    void update(int timestamp, int price) 
    {
        if(mp.find(timestamp)!=mp.end())
        {
           long long  val=mp[timestamp];
             s.erase(s.find(val));
        }
        mp[timestamp]=price;
        s.insert(price);
    }
    
    int current() 
    {
        auto it=*mp.rbegin();
        return it.second;
    }
    
    int maximum() 
    {
        return *s.rbegin();
    }
    
    int minimum() {
      
        return *s.begin();
    }
};