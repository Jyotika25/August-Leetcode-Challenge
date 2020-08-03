class Solution{
public:
bool isPalindrome(string s){
  int n = s.length();
  if(n==0)  return 0;
  int left =0;
   int right = n-1;

while(left<right){

  if(!isalnum(s[left])  left++;
  if(!isalnum(s[right]) right--;
  if(tolower(s[left]) == tolower(s[right]))
 {
    left++;
    right--;
 }
 else
  return false;
}
  return true;
}
};
