class Solution{
public:

bool isPowerofFour(int num){
//not power of 2
if(num<=0 || num&(num-1)!=0)  return false;
int n = log2(num);
//odd power of 2
if(n&1) return false;

return true;
}
};
