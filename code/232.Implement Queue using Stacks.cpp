class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s2.empty()) {
            s2.pop();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top()), s1.pop();
            }
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int val;
        if(!s2.empty()) {
            val = s2.top();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top()), s1.pop();
            }
            val = s2.top();
        }
        
        return val;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(!s1.empty() || !s2.empty())
            return false;
        else 
            return true;
    }
    
private:
    stack<int> s1;
    stack<int> s2;
};
