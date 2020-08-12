//give the ith index row

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1,1);
        
        for(int i=1;i<rowIndex;i++)
            for(int j=i;j>0;--j)
                output[j] = output[j] + output[j-1];
        return output;
    }
};
