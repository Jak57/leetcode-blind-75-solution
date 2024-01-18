// https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed
// Two heaps

class MedianFinder {
    priority_queue<int> mxHeap;
    priority_queue< int, vector<int>, greater<int> > mnHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxHeap.push(num);
        int mxSize, mnSize, top;
        
        mxSize = mxHeap.size();
        mnSize = mnHeap.size();
        
        if (mnSize > 0 && mxHeap.top() > mnHeap.top()) {
            int t1, t2;
            t1 = mxHeap.top();
            mxHeap.pop();
            
            t2 = mnHeap.top();
            mnHeap.pop();
            
            mxHeap.push(t2);
            mnHeap.push(t1);
        }
        
        if (mxSize-mnSize == 2) {
            top = mxHeap.top();
            mxHeap.pop();
            mnHeap.push(top);
            
        } else if (mnSize-mxSize == 2) {
            top = mnHeap.top();
            mnHeap.pop();
            mxHeap.push(top);
        }
    }
    
    double findMedian() {
        if (mxHeap.size() == mnHeap.size()) {
            return (mxHeap.top() + mnHeap.top())/2.0;
        } else {
            int tmp = INT_MAX;
            if (mnHeap.size() > 0)
                tmp = mnHeap.top();
            return float(min(mxHeap.top(), tmp));
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
