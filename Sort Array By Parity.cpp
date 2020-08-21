//tc : O(n) two pass
//sc : O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> new_arr;
        
        for(auto it : A){
            if(it%2==0)
                new_arr.push_back(it);
        }
        for(auto it : A){
            if(it%2)
                new_arr.push_back(it);
        }
        return new_arr;
    }
};

//tc: O(n)
//sc: O(n)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> new_arr(A.size(),0);
        int evenindex=0;
        int oddindex =A.size()-1;
        
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0)
                new_arr[evenindex++] = A[i];
            else
                new_arr[oddindex--] = A[i];
        }
       return new_arr;
        
    }
};


//tc: O(n)
//sc:O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int i=0;
        int j=A.size()-1;
        
      while(i<j){
          if(A[i]%2==0)
              i++;
          else{   
              swap(A[i],A[j]);
              j--;
              }
      }
        return A;
        
    }
};
