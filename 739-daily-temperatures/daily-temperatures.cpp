class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<int> st;
        

        for(int i=n-1; i>=0; i--){
            int curr = i;

            while(!st.empty() && temperatures[st.top()] <= temperatures[curr]){
                st.pop();
                
            
            }
            if(!st.empty()){
                answer[i] = st.top() - curr;
            }
            st.push(curr);
        }
        return answer;
    }
};