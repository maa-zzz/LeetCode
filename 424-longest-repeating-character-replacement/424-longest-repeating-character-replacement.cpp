class Solution {
public:
    
    int maxFreq(unordered_map<char, int>& freq){
        int counter = 0;
        for(const auto& p : freq)
            counter = max(counter, p.second);
        return counter;
    }
    
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freq; // stores freq of each char
        int l = 0;
        int r = 0;
		char rightChar;
		char leftChar;
        int maxLength = 1;
        
        // loop till right pointer reaches end of string
        while(r != s.size()){
            rightChar = s[r];
            leftChar = s[l];
            
            freq[rightChar]++; // increment freq for right char            
            r++; // move right pointer
            int currLength = r - l; // compute max of current window
            
            // check if cannot do any replacements
            if(currLength - maxFreq(freq) > k){ 
                freq[leftChar]--; // decrement freq for left char
                l++; // move left pointer
                currLength--; // adjust current max
            }
            
            maxLength = max(maxLength, currLength);
        }    
              
        return maxLength;
    }
};