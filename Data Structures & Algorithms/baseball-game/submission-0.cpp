class Solution {
public:
    int calPoints(vector<string>& operations) {
      stack<int> st;

      for(string op : operations){
            if(op == "C"){
                st.pop();
            }
            else if(op == "D"){
                int prev = st.top();
                st.push(prev*2);
            }
            else if( op == "+"){
                int top = st.top(); st.pop();
                int below = st.top(); st.pop();
                st.push(below);
                st.push(top);
                st.push(top+ below);
            }
            else {
                st.push(stoi(op));
            }
       }  
       int sum = 0;
       while(!st.empty()){
        sum += st.top();
        st.pop();
       }
       return sum;

    }
};