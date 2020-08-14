class CombinationIterator {
    
    string s;
    queue<string> q;
    
    void getCombination(int start,int len,string text){
        if(len == 0){
            q.push(text);
            return;
        }
        for(int i=start;i<=s.length()-len;++i){
            getCombination(i+1,len-1,text+s[i]);
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
    s = characters;
    string text ="";
    getCombination(0,combinationLength,text);
    }
    
    string next() {
        string str = q.front();
        q.pop();
        return str;
    }
    
    bool hasNext() {
        return !q.empty();
        
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
