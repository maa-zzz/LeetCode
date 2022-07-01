class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(auto c: tasks){
            counts[c]++;
        }
        priority_queue<int> pq;
        for(pair<char, int> count: counts){
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n+1;
        while(!pq.empty()){
            int time = 0;
            vector<int> temp;
            for(int i=0; i<cycle; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    time+=1;
                }
            }
            for(auto x:temp){
                if(--x){
                    pq.push(x);
                }
            }
            alltime+=!pq.empty() ? cycle :time;
        }
        return alltime;
    }
};