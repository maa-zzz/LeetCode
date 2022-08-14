
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st (wordList.begin(),wordList.end());
//         unordered_set<string> visited;
//         vector<vector<string>> ans;
//         queue<vector<string>> q;
//         q.push({beginWord});
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 auto curr_path = q.front();
//                 q.pop();
//                 string last = curr_path.back();
//                 for(int i = 0 ; i < last.size() ; ++i){
//                     auto temp = last;
//                     for(char ch = 'a' ; ch <= 'z' ; ++ch){
//                         temp[i] = ch;
//                         if(st.find(temp) != st.end()){
//                             auto new_path = curr_path;
//                             new_path.push_back(temp);
//                             visited.insert(temp);
//                             if(temp == endWord)
//                                 ans.push_back(new_path);
//                             else
//                                 q.push(new_path);
//                         }
//                     }
//                 }
//             }
//             for(auto& str : visited)
//                     st.erase(str);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> map;
        unordered_set<string> visited;
        unordered_set<string> set;
        vector<vector<string>> ans;
        
        // build map
        for (auto w : wordList) {
            set.insert(w);
        }
        
        if (set.find(endWord) == set.end())
            return ans;
        
        if (set.find(beginWord) == set.end()) {
            set.insert(beginWord);
            wordList.push_back(beginWord);
        }
        
        for (auto w : wordList) {
            for (int i = 0; i<w.length(); i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j != w[i]) {
                        string cur = w;
                        cur[i] = j;
                        if (set.find(cur) != set.end()) {
                            map[w].push_back(cur);
                        }
                    }
                }
            }
        }
        
        // bfs
        queue<string> q;
        unordered_map<string, int> minDepth;
        unordered_map<string, vector<string>> parent;
        parent[beginWord] = vector<string>({beginWord});
        q.push(beginWord);
        bool find = false;
        int depth = 0;
        while (!q.empty() && !find) {
            int size = q.size();
            depth++;
            for (int i = 0; i<size; i++) {
                string cur = q.front();
                q.pop();
                if (visited.find(cur) != visited.end()) {
                    continue;
                }
                visited.insert(cur);
                for (auto next : map[cur]) {
                    if (minDepth.find(next) == minDepth.end()) {
                        minDepth[next] = depth+1;
                    }
                    if (depth == minDepth[next]-1)
                        parent[next].push_back(cur);
                    q.push(next);
                }
                if (cur == endWord) {
                    find = true;
                    path(ans, parent, beginWord, endWord);
                }
            }
        }
        
        return ans;
    }
    
    void path(vector<vector<string>>& ans,  unordered_map<string, vector<string>>& parent,string beginWord, string endWord) {
        vector<string> cur;
        cur.push_back(endWord);
        backTrack(ans, parent, beginWord, endWord, endWord, cur);
    }
    
    void backTrack(vector<vector<string>>& ans, unordered_map<string, vector<string>>& parent,string beginWord, string endWord, string curWord, vector<string>& cur) {
        if (curWord == beginWord) {
            vector<string> tmp;
            for (int i = cur.size()-1; i>= 0; i--) {
                tmp.push_back(cur[i]);
            }
            ans.push_back(tmp);
        }  else {
            for (int i = 0; i<parent[curWord].size(); i++) {
                string c = parent[curWord][i];
                cur.push_back(c);
                backTrack(ans, parent, beginWord, endWord, c, cur);
                cur.pop_back();
            }
        }      
    }
};