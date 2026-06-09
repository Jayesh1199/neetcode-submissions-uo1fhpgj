class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> v;
        stack<int> s;

        for(int i = size - 1; i >= 0; i--)
        {
            // CASE 1: stack empty
            if(s.size() == 0) {
                v.push_back(0);
            }
            // CASE 2: top index points to greater temp — direct answer
            else if(temperatures[s.top()] > temperatures[i]) {
                v.push_back(s.top() - i);
            }
            // CASE 3: pop while top is <= current, then recheck
            else if(temperatures[s.top()] <= temperatures[i]) {
                while(s.size() > 0 && temperatures[s.top()] <= temperatures[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    v.push_back(0);
                }
                else {
                    v.push_back(s.top() - i);
                }
            }

            s.push(i);   // push INDEX — inside loop, every iteration
        }

        reverse(v.begin(), v.end());
        return v;
    }
};