class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> list;
        int end = A.size();
        
        while(end!=1){
            int index = find(A,end);
            flip(A,index);
            flip(A,end-1);
            list.push_back(index+1);
            list .push_back(end);
            end--;
        }
        return list;
    }
    
    int find(vector<int>& A , int index){
        for(int i=0;i<A.size();i++){
            if(A[i] == index)
                return i;
        }
        return -1;
    }
    
    void flip(vector<int>& A , int index){
        int start = 0;
        while(start < index){
            int temp = A[start];
            A[start++] = A[index];
            A[index--] = temp;
        }
    }
};
