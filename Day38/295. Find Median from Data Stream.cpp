class MedianFinder {
public:
    priority_queue<int>maxhp;
    priority_queue<int,vector<int>,greater<int>>minhp;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxhp.push(num);
        if(maxhp.size()>0 && minhp.size()>0 && maxhp.top()>minhp.top())
        {
            minhp.push(maxhp.top());
            maxhp.pop();
        }
        if(maxhp.size()>minhp.size()+1)
        {
           minhp.push(maxhp.top());
            maxhp.pop();
        }
        if(minhp.size()>maxhp.size()+1)
        {
           maxhp.push(minhp.top());
            minhp.pop();
        }
        
    }
    
    double findMedian() {
       if(maxhp.size()==minhp.size())
       {
           return (double)(maxhp.top()+minhp.top())*0.5;
       }
        return (maxhp.size()>minhp.size())?maxhp.top():minhp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */