class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mapi;
        for(int i=0; i<nums.size(); i++){
            if(mapi.find(nums[i])==mapi.end()){
                mapi[nums[i]]=1;
            }
            else{
                mapi[nums[i]]+=1;
            }
        }
        vector<int> res;
        priority_queue<pair<int,int>> pq; 
        for(auto it = mapi.begin(); it != mapi.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)mapi.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};