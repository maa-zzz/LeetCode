class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string ref[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> st;
        for(auto a: words){
            string ans = "";
            for(int i=0; i<a.size(); i++){
                ans+=ref[a[i]-'a'];
            }
            st.insert(ans);
        }
        return st.size();
    }
        
};