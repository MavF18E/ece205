#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

string cleanInfix(const string& infix);
string infixToPostfix(const string& infix);
Node* constructTree(const string& postfix);
int evaluate(Node* root);
bool isOperator(char c);


int main() {
    cout << "Enter an infix expression: " << endl;
    string exp;
    getline(cin, exp);
    exp = cleanInfix(exp);
    // string exp = "(8+1)*3-8/4";
    string postfix = infixToPostfix(exp);
    cout << "The postfix expression is: " << postfix << endl;
    Node* r = constructTree(postfix);
    cout << "The value of the expression is: " << evaluate(r) << endl;
    return 0;
}


string cleanInfix(const string& infix) {
    // This function removes spaces from the infix expression
    string cleaned;
    for (char c : infix) {
        if (c != ' ') {
            cleaned += c;
        }
    }
    return cleaned;
}

bool isOperator(char c) {
    // This function checks if a character is an operator
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(const string& infix) {
    // This function converts an infix expression to postfix notation
    stack <char> operators;
    queue <char> output;
    for (char c : infix) {

        if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(') {
                if ((c == '*' || c == '/') && (operators.top() == '+' || operators.top() == '-')) {
                    break;
                }
                output.push(operators.top());
                operators.pop();
            }
            operators.push(c);
        }
        else if (c >= '0' && c <= '9') {
            output.push(c);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push(operators.top());
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        }
    }
    while (!operators.empty()) {
        output.push(operators.top());
        operators.pop();
    }
    string result;
    while (!output.empty()) {
        result += output.front();
        output.pop();
    }
    return result;
}

Node* constructTree(const string& postfix) {
    // This function constructs an expression tree from a postfix expression
    stack<Node*> st;
    Node* t, * t1, * t2;

    for (int i = 0; i < postfix.length(); i++) {
        if (!isOperator(postfix[i])) {
            t = new Node(postfix[i]);
            st.push(t);
        }
        else {
            t = new Node(postfix[i]);

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();
    
    return t;
}

int evaluate(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (!isOperator(root->data)) {
        return root->data - '0';
    }
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}