class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        set<char> set;
        int i = 0, j = 0, maxi = 0;
        while (j < s.size()) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j++]);
                if(maxi < set.size()) maxi=set.size();
            } else {
                set.erase(s[i++]);
            }
        }
        return maxi;
    }
};