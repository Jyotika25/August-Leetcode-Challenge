class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> map;
        
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        
        int result = 0;
        int odd_found = false;
        
        for(auto& c : map){
            if(c.second%2==0){
                result = result + c.second;
            }
            else{
                odd_found = true;
                result = result + c.second-1;
            }
        }
        if(odd_found)   result++;
        return result;
    }
};
