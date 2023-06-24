class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i=2;i<=n;i++){
            string s = "";
            int cnt = 0;
            int sz = str.size();
            for(int j=0;j<sz;j++){
                if(j<sz-1){
                    if(str[j] == str[j+1]){
                        cnt++;
                    }else{
                        cnt++;
                        s+=to_string(cnt);
                        int c = str[j]-'0';
                        s+=to_string(c);
                        cnt=0;
                    }
                }else{
                    cnt++;
                    s+=to_string(cnt);
                    int c = str[j]-'0';
                    s+=to_string(c);        
                }
            }
            str = s;
        }
        return str;
    }
};