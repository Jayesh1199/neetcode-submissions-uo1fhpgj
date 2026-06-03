class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(char c : s)
        {
            if( c != ']')
            {
                st.push(c); // push everything except ]
            }
            else{
            // collect letters until [
                string collected = "";
                while(st.top() != '[')
                {
                    collected = st.top() + collected;
                    st.pop();
                }
                st.pop(); // pop [

            // get the number
                string numStr = "";
                while( !st.empty() && isdigit(st.top()))
                {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                 int k = stoi(numStr);

            // repeat and push back
                string repeated = "";
                for(int i = 0; i<k;i++)
                {
                    repeated += collected;
                }
                for(char ch : repeated)
                {
                    st.push(ch);
                }
            }
        }
    

    //collect final result
    string result = "";
    while(!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
    }
    
};