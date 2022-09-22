class Solution {
public:
    string reverseWords(string s) {
        int x = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+x,s.begin()+i);
                x = i+1; 
            }
           
        }
        reverse(s.begin()+x,s.end());       
        return s;
    }
};