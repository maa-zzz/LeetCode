class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;
        int minsum = INT_MAX;
        vector<string> ans;
        for(int i=0; i<list1.size(); i++){
            map.emplace(list1[i], i);            
        }
        for(int i=0; i<list2.size(); i++){
            auto it = map.find(list2[i]);
            if(it!=map.end()){
                int sum = i+it->second;
                if(minsum>sum){
                    vector<string> temp;
                    temp.push_back(it->first);
                    ans = temp;
                    minsum = sum;
                }
                else if(minsum==sum){
                    ans.push_back(it->first);
                }
            }
        }
        return ans;
    }
};