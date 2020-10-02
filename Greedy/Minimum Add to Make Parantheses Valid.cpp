class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int res = 0;
        
        for (char c : S) {
            if (c == '(')
                st.push(c);
            else {
                if (st.empty())
                    res ++;
                else
                    st.pop();
            }
        }
        
        res += st.size();
        return res;
    }
};
