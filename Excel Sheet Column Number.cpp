class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int j =0;
        
        for(int i = s.size()-1;i>=0;i--){
            sum +=(s[i]-'A'+1) * pow(26,j);
            j++;
        }
        return sum;
    }
};
