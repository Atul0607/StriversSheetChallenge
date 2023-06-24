class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> large;
    priority_queue<int> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || small.top()>num) small.push(num);
        else large.push(num);
        if(small.size() > large.size()+1){
            int val = small.top();
            small.pop();
            large.push(val);
        }
        if(large.size()>small.size()+1){
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        if(large.size() > small.size()) return large.top();
        return (large.top()+small.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */