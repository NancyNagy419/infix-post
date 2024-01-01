#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// A Function to return precedence of operators
int prec(char ch) {
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}

// A Function to convert infix expression to postfix expression
string infixToPostfix(string s) {

	stack<char> st; //For stack operations, we are using C++ built in stack
	string ans = "";

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];

		// If the current character is an operand, add it to our answer string.
		if (ch >= '0' && ch <= '9')
			ans += ch;   // Append the current character of string in our answer

		// If the current character of string is an '(', push it to the stack.
		else if (ch == '(')
			st.push('(');

		// If the current character of string is an ')', append the top character of stack in our answer string
		// and pop that top character from the stack until an '(' is encountered.
		else if (ch == ')') {
			while (st.top() != '(')
			{
				ans += st.top();    // Append the top character of stack in our answer
				st.pop();
			}
			st.pop();
		}

		//If an operator is scanned
		else {
			while (!st.empty() && prec(s[i]) <= prec(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(ch);             // Push the current character of string in stack
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	return ans;
}

// calculate postfix

// The main function that returns value 
// of a given postfix expression
int evaluatePostfix(string exp)
{
    // Create a stack of capacity equal to expression size
    stack<int> st;
 
    // Scan all characters one by one
    for (int i = 0; i < exp.size(); ++i) {
         
        // If the scanned character is an operand 
        // (number here), push it to the stack.
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');
 
        // If the scanned character is an operator, 
        // pop two elements from stack apply the operator
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            case '^':
                st.push(pow(val2 , val1));
                break;
            
            }
        }
    }
    return st.top();
}

int main() {
    string input;
    cout<< "Enter the equation: "<<endl;
	while (cin>> input){
        cout <<"post-fix expression = "<< infixToPostfix(input)<<endl;
        string exp= infixToPostfix(input);
        cout << "Answer = " << evaluatePostfix(exp)<<endl;
        cout<< "Enter the new equation: "<<endl;
    }

	return 0;
}