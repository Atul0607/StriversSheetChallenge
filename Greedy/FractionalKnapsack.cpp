class Solution
{
    public:
    static bool mycmp(Item& a, Item& b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0.0;
        sort(arr,arr+n,mycmp);
        for(int i=0;i<n;i++){
            if(arr[i].weight <= W){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }else{
                ans+=(double)W/arr[i].weight*arr[i].value;
                break;
            }
        }
        return ans;
    }
};