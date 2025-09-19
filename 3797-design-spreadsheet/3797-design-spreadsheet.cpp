class Spreadsheet {
public:
    unordered_map<string,int>mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    int findValue(string &s){
        if(s[0]>='1'&&s[0]<='9'){
            return stoi(s);
        }
        return mp[s];
    }
    int getValue(string formula) {
        int positionOfPlus=formula.find('+');
        string leftPart=formula.substr(1, positionOfPlus-1);
        string rightPart=formula.substr(positionOfPlus+1);
        return findValue(leftPart)+findValue(rightPart);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */