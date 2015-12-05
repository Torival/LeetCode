class MinStack {
public:
    void push(int x) {
        vec.push_back(x);
        set.insert(x);
    }

    void pop() {
        if(vec.size() > 0) {
            set.erase(set.find(*(--vec.end())));
            vec.erase(--vec.end());
        }
    }

    int top() {
        return vec.size()==0 ? 0 : vec[vec.size()-1];
    }

    int getMin() {
        return vec.size()==0 ? 0 : *set.begin();
    }
private:
    vector<int> vec;
    multiset<int> set;
};
