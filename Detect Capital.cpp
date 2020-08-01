class Solution{
public:
bool detectCapital(string word){

int count =0;

for(int i=0;i<word.length();i++){
  if(isupper(word[i]))
  count++;
}
return count == 0 || count == word.length() || count == 1 && isupper(word[0]);
}
};
