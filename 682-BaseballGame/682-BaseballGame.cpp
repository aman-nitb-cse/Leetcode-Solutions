// Last updated: 6/25/2026, 11:37:19 PM
class Solution {
public:
    int calPoints(vector<string>& v) {
        stack <int> st;
        for(string s : v){
            char i = s[0];
            if(i == 'C') st.pop();
            else if(i == '+'){
                int sum = st.top();
                st.pop();
                sum += st.top();
                st.push(sum - st.top());
                st.push(sum);
            }
            else if(i == 'D'){
                st.push(2 * st.top());
            }
            else st.push(stoi(s));
        }
        int sum = 0; 
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};