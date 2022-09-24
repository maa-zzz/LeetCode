class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        map<int,int> mp1,mp2;int sum1=0,sum2=0;vector<int> ans;
        for(int i=0;i<aliceSizes.size();i++){
            mp1[aliceSizes[i]]++;
            sum1+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            mp2[bobSizes[i]]++;
            sum2+=bobSizes[i];
        }
        if(sum1>sum2){
            for(int i=0;i<bobSizes.size();i++){
                if(mp1[(sum1+sum2)/2-(sum2-bobSizes[i])]>=1)
                {ans.push_back((sum1+sum2)/2-(sum2-bobSizes[i])); ans.push_back(bobSizes[i]); return ans;}
            }
        }
        else {
            for(int i=0;i<aliceSizes.size();i++){
                if(mp2[(sum1+sum2)/2-(sum1-aliceSizes[i])]>=1)
                {ans.push_back(aliceSizes[i]);ans.push_back((sum1+sum2)/2-(sum1-aliceSizes[i]));  return ans;}
            }
        }
            return ans;
    }
};