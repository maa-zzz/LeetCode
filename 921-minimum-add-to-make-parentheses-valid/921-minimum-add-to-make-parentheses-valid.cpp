class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int x = 0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    x+=1;
                }
                else{
                    st.pop();
                }
            }
        }
        return x+st.size();
    }
};