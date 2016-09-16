class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty()) {
            int count = q1.size() - 1;
            for(int i = 0; i < count; i++){
                q2.push(q1.front()), q1.pop();
            }
            q1.pop();
        } else {
            int count = q2.size() - 1;
            for(int i = 0; i < count; i++){
                q1.push(q2.front()), q2.pop();
            }
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        int x;
        
        if(!q1.empty()) {
            while(!q1.empty()){
                x = q1.front(), q1.pop();
                q2.push(x);
            }
        } else {
            while(!q2.empty()){
                x = q2.front(), q2.pop();
                q1.push(x);
            }
        }
        
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(!q1.empty() || !q2.empty())
            return false;
        else
            return true;
    }
    queue<int> q1;
    queue<int> q2;
};
