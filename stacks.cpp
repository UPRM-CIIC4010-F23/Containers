#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    OPERATOR,
    OPERAND,
};

set<string> VALID_OPS{"+", "-", "*", "/"};

TokenType tokenType(string s) {
    if ((VALID_OPS.count(s) != 0)) {
        return OPERATOR;
    } else {
        return OPERAND;
    }
}

double apply(string op, double v1, double v2) {
    if (op == "+")
        return (v1 + v2);
    if (op == "-")
        return (v1 - v2);
    if (op == "*")
        return (v1 * v2);
    if (op == "/")
        return (v1 / v2);
    return 0.0; // Just to avoid no-return warning
}

vector<string> tokenize(string expression) {
    vector<string> result;
    int tokenStart = 0;
    int i = 0;
    while (i < expression.size()) {
        if (expression.substr(i, 1) == " ") {
            result.push_back(expression.substr(tokenStart, i - tokenStart));
            tokenStart = i + 1;
        }
        i++;
    }
    return result;
}

double evalPostfix(vector<string> tokens) {

    stack<double> mystack;
    for (auto t :  tokens) {
        switch(tokenType(t)) {
            case OPERAND:
                mystack.push(atof(t.c_str()));
                break;
            case OPERATOR: {
                double op2 = mystack.top();
                mystack.pop();
                double op1 = mystack.top();
                mystack.pop();
                mystack.push(apply(t,op1,op2));
                break;
            }
            default:
                cerr << "Fatal Error: Illegal  Operator  in Expression" << endl;
                exit(1);
        }
    }
    return mystack.top();

}

int main() {

    vector<string> e1{"-5.0", "3.0", "-"};
    cout << "5.0 3.0 +  -> " << evalPostfix(e1) << endl;

    vector<string> e2{"5.0", "3.0", "+", "2.0", "*", "2.0", "*"};
    cout << "5.0 3.0 + 2.0 * 2.0 * -> " << evalPostfix(e2) << endl;

    string expression = "5.0 3.0 + 2.0 * 2.0 * 2 / ";
    vector<string> tokens = tokenize(expression);
    cout << "5.0 3.0 + 2 * 2 /-> " << evalPostfix(tokens) << endl;
}