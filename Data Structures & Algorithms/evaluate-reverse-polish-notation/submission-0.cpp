class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        
        for(string token : tokens){

            if(token == "+" || token == "-" || token == "*" || token == "/"){

                int b = st.top(); st.pop(); // most recent number
                int a = st.top(); st.pop(); // second most recent number
                                        // eg stack= [1,2], b=2 , a=1 -> 1+2 not 2+1

                if(token == "+") {st.push(a+b); } // add and push back the result back
                else if (token == "-") {st.push(a-b);}
                else if (token == "*") {st.push(a*b);}
                else if (token == "/") {st.push(a/b);}
            }
            else{
                st.push(stoi(token)); // its a number -> convert string to int and push
            }
        }
        return st.top(); // only one element left = final answer.
    }
};
