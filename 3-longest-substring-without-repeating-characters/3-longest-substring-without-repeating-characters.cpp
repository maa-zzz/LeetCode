class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        if (s.length() ==0)
             return 0;        
        string dp ="" ; 
        int longest= 1 , found ;  
        dp += s[0] ;  
        for (int i=1 ; i< s.length() ; i++){
            found = dp.find(s[i]);  
            if ( found == -1)
                dp += s[i];
     
            else {
              dp =  dp.substr(found + 1, dp.length());
              dp +=s[i]; 
			  }
            if(dp.length()>longest){
                longest = dp.length();
            }
        }
            return longest;
        
    }
};