class Solution {
public:
    vector<vector<int> > generate(int numRows) {

        vector<vector<int> > ans;

        int i, j;

        for (i = 0; i < numRows; i++) {

            vector<int> row(i + 1, 1);

            // 🔁 CHANGEABLE: can use while loop instead of for
            for (j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};