class Solution {
public:
    
    bool checkSubstring(unordered_map<string, int> word_count, string s, int word_len) {
        for(int j=0; j<s.size(); j+=word_len) {
            string w = s.substr(j, word_len);
            if(word_count.find(w) != word_count.end()) {
                if(--word_count[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int word_len = words[0].size();
        int s_len = s.size();
        int words_window = words.size() * word_len;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while((i + words_window) <= s_len) {
            if(checkSubstring(wordCount, s.substr(i, words_window), word_len)) {
                ans.push_back(i);
            }
            ++i;
        }
        return ans;
    }
};