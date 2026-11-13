class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (string s : strs) {
            int count[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                count[s[i]-'a']++;
            }
        
        string key = "";

        for (int i = 0; i < 26; i++) {
            key+=to_string(count[i])+"#";
        }
        
        mp[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(group);
        }
        return res;
    }
};
