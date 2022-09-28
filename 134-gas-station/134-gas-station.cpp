class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1;
        if(accumulate(gas.begin(), gas.end(),0)<accumulate(cost.begin(),cost.end(),0)){
           return ans;
       }
        else{
            ans = 0;//definetly works
        }
 //you know there is a solution
                                      // after you reach end of the array with positive price
        int total = 0;                          //no need to iterate again as that index is the answer
        for(int i=0; i<gas.size(); i++){                    //think, its easy
            total +=(gas[i]-cost[i]);
            if(total<0){
                total = 0;
                ans=i+1;
            }
        }
        return ans;
    }
};