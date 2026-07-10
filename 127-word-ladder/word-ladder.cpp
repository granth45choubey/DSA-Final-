class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st;

        for(int i = 0; i < wordList.size(); i++)
        {
            st.insert(wordList[i]);
        }

        if(st.find(endWord) == st.end())
        {
            return 0;
        }

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        st.erase(beginWord);

        while(!q.empty())
        {
            pair<string,int> current = q.front();
            q.pop();

            string word = current.first;
            int steps = current.second;

            if(word == endWord)
            {
                return steps;
            }

            for(int i = 0; i < word.length(); i++)
            {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};