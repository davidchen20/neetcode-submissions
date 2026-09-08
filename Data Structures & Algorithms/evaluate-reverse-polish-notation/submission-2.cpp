class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stuff;

        for (int i = 0; i < tokens.size(); i++) {
            if (stuff.empty() || !isOperator(tokens[i])) {
                stuff.push(stoi(tokens[i]));
                continue;
            }

            if (tokens[i] == "+") {
                int operand1 = stuff.top();
                stuff.pop();
                int operand2 = stuff.top();
                stuff.pop();

                stuff.push(operand2 + operand1);
            } else if (tokens[i] == "-") {
                int operand1 = stuff.top();
                stuff.pop();
                int operand2 = stuff.top();
                stuff.pop();

                stuff.push(operand2 - operand1);
            } else if (tokens[i] == "*") {
                int operand1 = stuff.top();
                stuff.pop();
                int operand2 = stuff.top();
                stuff.pop();

                stuff.push(operand2 * operand1);
            } else {
                int operand1 = stuff.top();
                stuff.pop();
                int operand2 = stuff.top();
                stuff.pop();

                stuff.push(operand2 / operand1);
            }
        }

        return stuff.top();
    }

    bool isOperator(string& c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
};
