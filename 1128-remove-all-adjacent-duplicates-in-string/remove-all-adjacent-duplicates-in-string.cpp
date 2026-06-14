class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack <char> st;
        string ans ="";

        for(int i=0; i<n; i++){
            if( !st.empty() && s[i] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while( !st.empty()){
            char c = st.top();
            st.pop();
            ans = ans + c;
            
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};