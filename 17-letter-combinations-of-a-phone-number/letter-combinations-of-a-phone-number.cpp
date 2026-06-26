class Solution {
public:

    void fun(string &digits, int n,int idx,unordered_map<char,string> &f, string &temp,vector<string> &ans){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        string choice = f[digits[idx]];
        for(int j=0; j<choice.size(); j++){
            temp.push_back(choice[j]);
            fun(digits,n,idx+1,f,temp,ans);
            temp.pop_back();
        }
        return;

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int n = digits.size();
        int idx = 0;
        string temp;
        vector<string> ans;
        fun(digits,n,idx,f,temp,ans);
        return ans;
    }
};