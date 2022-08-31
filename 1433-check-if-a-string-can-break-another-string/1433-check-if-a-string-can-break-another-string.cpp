class Solution {
public:
    
    bool comp(string big, string notbighehe, int i) {
        
        for(int j=i; j<big.size(); j++){
            if(big[j]<notbighehe[j]){
                return false;
            }
        }
        return true;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.size();
        for(int i=0; i<n; i++){
                if(s1[i]>s2[i]){
                    return comp(s1,s2,i);
                }
                else if(s2[i]>s1[i]){
                    return comp(s2,s1,i);
                }
            
        }
        return true;
    }
};