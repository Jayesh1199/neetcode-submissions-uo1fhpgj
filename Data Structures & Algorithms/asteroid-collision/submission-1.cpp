class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;

        for(int ast : asteroids){
            // collision happens only when top-> meets <- ast
            while(!st.empty() && st.top() > 0 && ast< 0){

                if(abs(ast) > st.top()){
                    st.pop();          // top asteroid explodes
                                      //  Current Survives, keep looping
                }
                else if(abs(ast) == st.top()){
                    st.pop();         // both explode
                    ast = 0;          // mark current as dead
                    break;            // stop the loop
                }
                else{
                    ast = 0;         // current explodes
                    break;          // stop the loop
                }

            }
            if(ast !=0 ){            // only push if still alive
                st.push(ast);
            }
        }
        //convert stack to vector for the result
        vector<int> result(st.size());
        for(int i = st.size()-1; i>= 0 ; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};