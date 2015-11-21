class MedianFinder {
public:
    MedianFinder() {}
    // Adds a number into the data structure.
    void addNum(int num) {
        if(!front.size() || num <= *front.rbegin()) front.insert(num);
        else rear.insert(num);
        
        if(front.size() > rear.size()+1) {
            multiset<int>::iterator it = front.end();
            it--;
            rear.insert(*it);
            front.erase(it);
        } 
        if(rear.size() > front.size()) {
            front.insert(*rear.begin());
            rear.erase(rear.begin());   
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(front.size() == rear.size()) return (*front.rbegin() + *rear.begin())/2.0;
        else return *front.rbegin();
    }   
private:
    multiset<int> front, rear;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
