class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char,int> mp_t;
        for(int i=0;i<s.size();i++){
            mp_t[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp_t.find(s[i]) == mp_t.end()) return false;
            mp_t[s[i]]--;
            if(mp_t[s[i]] == 0) mp_t.erase(s[i]);
        }
        return mp_t.size() == 0 ? true : false;
    }
};