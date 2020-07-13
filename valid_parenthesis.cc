class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto c : s) {
            if (c == '{' || c == '[' || c == '(')
                st.push(c);
            else if (c == '}') {
                if (st.empty())
                    return false;
                else if (st.top() == '{')
                    st.pop();
                else
                    return false;
            } else if (c == ']') {
                if (st.empty())
                    return false;
                else if (st.top() == '[')
                    st.pop();
                else
                    return false;
            } else if (c == ')') {
                if (st.empty())
                    return false;
                else if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        return (st.empty());
    }
};
