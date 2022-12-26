#include <iostream>
#include <string.h>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

char postfix[100], infix[100];
map<char, double> values;

int isOperator(char op) {
    if (op=='(') return 1;

    else if (op==')') return -1;

    else if (op=='+' || op=='-') return 2;

    else if (op=='/' || op=='*') return 3;

    else if (op=='^') return 4;

    else return 0;
}


double operation(double a, double b, char op) {
    if (op=='+') return a+b;

    else if (op=='-') return a-b;

    else if (op=='*') return a*b;

    else if (op=='/') return a/b;

    else return pow(a, b);
}


void inputExpression(char *infix) {
    // A+B*C/(E-F)*(A^(B-C/D))
    cout << "Enter an expression \n";
    char exp[100]; 
    cin >> exp;
    strcpy(infix, exp);

    
    int len = strlen(exp);


    for (int z=0; z<len; z++) {
        char c = exp[z];
        double a;
        if (isOperator(c)==0 && values.count(c)==0) {
            cout << "Enter value of " << c << ": ";
            cin >> a;
            values[c] = a;
        }
    }
}

void infixToPostfix(char *infix, char *postfix) {

    // char* postfix;
    stack<char> s;
    int len = strlen(infix);
    int j = 0;

    for (int i=0; i<len; i++) {

        char current = infix[i];
        int op = isOperator(current);

        if (op==-1) {
            while (s.top()!='(') {
                postfix[j++] = s.top();
                s.pop();
            }
            s.pop();
            continue;
        }

        if (op==0) {
            postfix[j++] = current;
        }

        else {

            if ((s.empty()) || op==1)   s.push(current);

            else {
                while (op <= isOperator(s.top())) {
                    postfix[j++] = s.top();
                    s.pop();
                    if (s.empty()) break;
                }

                s.push(current);
            }

        }
    }

    {while (!s.empty()) {
        postfix[j++] = s.top();
        s.pop();
    }

    postfix[j] = '\0';}

}

double evaluatePostfix(char *postfix) {

    stack<char> solution;
    double ans;
    int length = strlen(postfix);
    for (int k=0; k<length; k++) {
        char current = postfix[k];

        if (isOperator(current)==0) {
            solution.push(current);
        }

        else {
            double b = values[solution.top()];
            solution.pop();
            double a = values[solution.top()];
            solution.pop();

            ans = operation(a, b, current);
            values[char(ans)] = ans;
            solution.push(char(ans));
        }
    }
    solution.pop();

    return ans;

}
