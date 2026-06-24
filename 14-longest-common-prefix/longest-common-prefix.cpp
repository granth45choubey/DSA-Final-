class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();

        string first = strs[0];
        string last = strs[n-1];
        string ans = "";

        int len = min(first.size(),last.size());
        for(int i =0;i<len;i++){
            if(first[i] == last[i]) ans = ans + first[i];
            else break;
        }
        return ans;
    }
};