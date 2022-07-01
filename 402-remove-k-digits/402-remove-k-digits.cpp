class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>num.size()){
            return "0";
        }
        if(k==0){
            return num;
        }
        string ans = "";
        stack<char>st;
        st.push(num[0]);
        for(int i=1; i<num.size(); i++){
            while(!st.empty() and st.top()>num[i] and k>0){
                st.pop();
                k-=1;
            }
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0'){
                st.pop();
            }
        }
        while(k and !st.empty()){
            st.pop();
            k-=1;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};