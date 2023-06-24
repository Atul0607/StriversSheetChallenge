class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        int i=0;
        if(len == 0){
            return "";
        }
        if(len == 1){
            return strs[0];
        }
        sort(strs.begin(),strs.end());
        int end = min(strs[0].size(),strs[len-1].size());
        string s = "";
        while(i<end && strs[0][i] == strs[len-1][i]){
            s+=strs[0][i];
            i++;
        }
        return s;
    }
};