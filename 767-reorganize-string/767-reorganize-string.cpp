class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto a: s){
            mp[a]+=1;
        }
        int n=s.size();
        priority_queue<pair<int,char>>pq;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second>0){
                pq.push({it->second, it->first});
            }
        }
        string ans;
        while(pq.size()>1){
            char first = pq.top().second;
            pq.pop();
            char second = pq.top().second;
            pq.pop();
            mp[first]-=1;
            mp[second]-=1;
            ans+=first;
            ans+=second;
            if(mp[first]>0) pq.push({mp[first], first});
            if(mp[second]>0) pq.push({mp[second], second});
        }
        if(!pq.empty()){
            char last = pq.top().second;
            if(mp[last]==1) ans+= last;
            else return "";
        }
        return ans;
    }
};