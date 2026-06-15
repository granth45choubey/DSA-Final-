class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        unordered_map<char,int> r;
        unordered_map<char,int> p;

        for(int i=0; i<n; i++){
            r[ransomNote[i]]++;

        }
        for(int j=0; j<m; j++){
            p[magazine[j]]++;
        }
        for(auto i: r){
            if(i.second > p[i.first]) return false;
        }
        return true;
    }
};