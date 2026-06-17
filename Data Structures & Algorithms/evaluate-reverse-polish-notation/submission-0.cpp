class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                int res;
                if (tokens[i] == "+") res = num1 + num2;
                else if (tokens[i] == "-") res = num1 - num2;
                else if (tokens[i] == "*") res = num1 * num2;
                else res = num1 / num2;

                s.push(res);
            } else {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }

    bool isOperator(string& c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
};
