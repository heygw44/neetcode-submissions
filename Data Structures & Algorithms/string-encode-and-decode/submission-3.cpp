class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j-i)); // #앞의 숫자
            i = j + 1;  // 문자열 시작
            j = i + len; // 다음 #
            ans.push_back(s.substr(i, len));
            i = j;
        }
        return ans;
    }
};
