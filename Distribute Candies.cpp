class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
       
        vector<int> result(num_people,0);
        int val=1;
        int index =0;
        
        while(candies > 0){
            result[index] = result[index] + val;
            index++;
            candies = candies - val;
            val++;
            if(index == num_people)  index = 0;
            if(val > candies)   val = candies;
        }
        return result;
    }
};
