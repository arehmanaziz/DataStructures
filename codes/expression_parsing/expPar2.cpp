#include <iostream>
#include <string.h>
#include <stack>
#include <cmath>
#include <map>
using namespace std;


class Stack { 
    private:
        char stackData[100];       
        int topOfStack;             

    public:
        Stack() { topOfStack = -1; }
        
        void push(char ch) {

            if (full()) {
                throw invalid_argument("STACK OVERFLOW");
            }

            stackData[++topOfStack] = ch;
        }

        char pop() {
            if (empty()) {
                throw invalid_argument("STACK UNDERFLOW");          
            }
            char data = stackData[topOfStack];
            stackData[topOfStack--] = 0;
            return data;
        }

        bool empty() {
            return (topOfStack==-1 ? 1 : 0);
        }

        bool full() {
            return (topOfStack==99 ? 1 : 0);
        }

        char top() {
            return stackData[0];
        }

};


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


int main() {

    // 1. -----------------------INPUT--------------------------------

    // char infix[100] = "A+B*C/(E-F)*(A^(B-C/D))";
    cout << "Enter an expression \n";
    char exp[100];
    cin >> exp;

    char infix[100];
    strcpy(infix, exp);
    int len = strlen(infix);

    map<char, double> values;

    for (int z=0; z<len; z++) {
        char c = infix[z];
        double a;
        if (isOperator(c)==0 && values.count(c)==0) {
            cout << "Enter value of " << c << ": ";
            cin >> a;
            values[c] = a;
        }
    }

    cout << endl << "Infix: " << infix << endl << endl;
    char postfix[100] = "";
    Stack s;

    // 2. ------------------INFIX TO POSTFIX-------------------
    int j = 0;

    for (int i=0; i<len; i++) {

        char current = infix[i];
        int op = isOperator(current);

        if (op==-1) {
            while (s.top()!='(') {
                postfix[j++] = s.pop();
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
                    postfix[j++] = s.pop();
                    if (s.empty()) break;
                }

                s.push(current);
            }

        }
    }

    {while (!s.empty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
    cout << "Postfix: " << postfix << endl << endl;}


    // 3. -------------------SOLVING POSTFIX----------------------

    Stack solution;
    double ans;
    int length = strlen(postfix);
    for (int k=0; k<length; k++) {
        char current = postfix[k];

        if (isOperator(current)==0) {
            solution.push(current);
        }

        else {
            double b = values[solution.pop()];
            double a = values[solution.pop()];

            ans = operation(a, b, current);
            // cout << a << current << b << " = " << ans << endl;
            values[char(ans)] = ans;
            solution.push(char(ans));
        }
    }
    ans = solution.pop();
    cout << "Solution: "<< ans << endl; 
    // solution.pop();
}