class WordDictionary {
    vector<WordDictionary*> children;
    bool isEndofWord;
    
public:
    WordDictionary(): isEndofWord(false){
        children = vector<WordDictionary*>(26,nullptr);
    }
    
    /** Initialize your data structure here. */
    
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary * curr = this;
        for(char c:word){
            if(curr->children[c-'a'] == nullptr)
                curr->children[c-'a'] = new WordDictionary();
            curr = curr->children[c-'a'];
        }
        curr->isEndofWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *curr = this;
        for(int i=0;i<word.length();++i){
            char c = word[i];
            if(c=='.'){
                for(auto ch : curr->children)
                    if(ch && ch->search(word.substr(i+1)))  return true;
                return false;
            }
             if(curr->children[c-'a'] == nullptr)   return false;
            curr = curr->children[c-'a'];
        }
        return curr && curr->isEndofWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
