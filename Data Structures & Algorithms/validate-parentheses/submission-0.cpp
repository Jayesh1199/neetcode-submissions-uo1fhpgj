class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        for(char c : s){
            if(c == '(' || c =='[' || c == '{' ){
                st.push(c);
        }
        else{
            if(st.empty())
                return false;
            if(st.top() != m[c])
                return false;
            st.pop();
        }
    }
    return st.empty();
    }
};
