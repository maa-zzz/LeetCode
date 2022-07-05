class Solution {
private:
    vector<string> possibleSentences;
    
    void breakWord(int index, string &s, set<string>& wordDict, vector<string> &possibleSentence){
        if (index == (int)s.length()) {
            string sentence = "";
            for (string s: possibleSentence) {
                sentence.append(s);
            }
            
            possibleSentences.push_back(sentence);
            
            return;
        }
        
        string possibleWord = "";
        for (int i = index; i < s.length(); i++) {
            possibleWord += s[i];
            
            if (wordDict.find(possibleWord) != wordDict.end()) {
                if (possibleSentence.size() != 0) {
                    possibleSentence.push_back(" ");
                }
                possibleSentence.push_back(possibleWord);
                breakWord(i + 1, s, wordDict, possibleSentence);
                
                possibleSentence.pop_back();
                
                if (possibleSentence.size() != 0) {
                    possibleSentence.pop_back();
                }
            }
        }
    }
        
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordDictionary(wordDict.begin(), wordDict.end());
        vector<string> possibleSentence;
        breakWord(0, s, wordDictionary, possibleSentence);
        
        return possibleSentences;
    }
};