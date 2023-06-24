class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i=0,j=0;
        while(true){
            int a=0,b=0;
            while(i<n1 && v1[i]!='.'){
                a*=10;
                a+=(v1[i]-'0');
                i++;
            }
            while(j<n2 && v2[j]!='.'){
                b*=10;
                b+=(v2[j]-'0');
                j++;
            }
            if(a<b) return -1;
            if(a>b) return 1;
            if(i>=n1 && j>=n2) break;
            i++;
            j++;
            
        }
        return 0;
    }
};