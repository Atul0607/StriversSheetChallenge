class Solution 
{
    public:
    
    static bool cmp(Job& a, Job& b){
        return a.dead < b.dead;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            if(arr[i].dead > pq.size()){
                pq.push(arr[i].profit);
            }else{
                if(pq.top()<arr[i].profit){
                    pq.pop();
                    pq.push(arr[i].profit);
                }
            }
        }
        vector<int> ans(2);
        ans[0] = pq.size();
        ans[1] = 0;
        while(!pq.empty()){
            ans[1]+=pq.top();
            pq.pop();
        }
        return ans;
    } 
};