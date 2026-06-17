class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) return false;
                switch (c) {
                    case ')':
                        if (st.top() != '(') return false;
                        st.pop();
                        break;
                    case '}':
                        if (st.top() != '{') return false;
                        st.pop();
                        break;
                    case ']':
                        if (st.top() != '[') return false;
                        st.pop();
                        break;
                    default:
                        break;
                }
            }
        }

        return st.empty();

    }
};
