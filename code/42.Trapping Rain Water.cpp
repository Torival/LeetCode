class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0;
        int high = 0;
        for(int i=0; i<height.size(); i++) {
            if(height[i]) {
                if(!st.empty()) {
                    high = 0;
                    while(!st.empty() && height[st.top()] < height[i]) {
                       sum +=  (height[st.top()]-high)*(i - st.top()-1);
                       high = height[st.top()];
                       st.pop();
                    }
                    
                    if(!st.empty()) 
                        sum += (height[i]-high)*(i - st.top()-1);
                }
                st.push(i);
            }
        }
        return sum;
    }
};

