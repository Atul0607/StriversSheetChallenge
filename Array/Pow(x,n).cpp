class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            return 1/(x * myPow(x,abs(n)-1));     
        }
        double sol = myPow(x,n/2);
        double ans= sol * sol;
        if(n%2!=0)
            return x * ans;    
        return ans; 
    }
};