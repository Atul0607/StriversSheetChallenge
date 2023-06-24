class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                st.push(temp);
                temp = "";
                continue;
            }else{
                temp+=s[i];
            }
        }
        st.push(temp);
        string ans = "";
        while(st.size()) {
            if(st.top() == ""){
                st.pop();
            }else{
                ans+=st.top();
                ans+=" ";
                st.pop();
            }
        }
        if(ans[0] == ' '){
            ans = ans.substr(1,ans.size());
        }
        if(ans[ans.size()-1] == ' '){
            ans = ans.substr(0,ans.size()-1);
        }
        return ans;
    }
};