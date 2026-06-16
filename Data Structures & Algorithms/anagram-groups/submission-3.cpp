class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& s : strs) {              
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            string key;
            for (int i = 0; i < 26; i++) {
                key += "!" + to_string(count[i]);  
            }
            groups[key].push_back(s);
        }                                          

        vector<vector<string>> res;
        for (auto& [k, group] : groups) {
            res.push_back(group);
        }
        return res;
    }
};