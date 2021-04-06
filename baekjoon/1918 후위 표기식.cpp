#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

typedef enum {
    Operand = 0,
    Inlparen = 4,
    Lparen = 1,
    Rparen = 5,
    Plus = 2,
    Minus = 2,
    Times = 3,
    Divide = 3
} Priority;

Priority getToken(char x);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    Priority token; // 우선순위 판단을 위한 token 변수 선언
    char x;

    string postFix; // 변환된 후위표기식을 저장하는 변수
    string inFix;
    cin >> inFix;

    stack<char> stack;

    for (int i = 0; inFix[i] != '\0'; i++)
    {
        x = inFix[i];
        token = getToken(inFix[i]);

        // 스택에 들어있지 않은 '('는 가장 높은 우선순위 부여
        if (token == Lparen)
            token = Inlparen;

        // 피연산자는 바로 후위표기식에 넣어도 됨!
        if (token == Operand)
            postFix += x;

        // 스택이 비어있을 경우, push해준다.
        else if (stack.empty())
            stack.push(x);
        
        // 스택이 비어있지 않을 경우,
        else
        {
            // ')' 일 경우
            if (token == Rparen)
            {
                while (stack.top() != '(')
                {
                    postFix += stack.top();
                    stack.pop();
                }
                stack.pop(); // 왼쪽 괄호 Pop하기
            }

            // 우선순위가 높으면 push 해라
            else if (getToken(stack.top()) < token)
                stack.push(x);

            // 우선순위가 낮으면 같거나 높은 우선순위들을 Pop 해줌
            else
            {
                while (!stack.empty())
                {
                    if (getToken(stack.top()) < token)
                        break;
                    
                    postFix += stack.top();
                    stack.pop();
                }
                stack.push(x);
            }
        }
    }

    cout << postFix;
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }

    return 0;
}

Priority getToken(char x)
{
    switch(x){
        case '(': return Lparen;
        case ')': return Rparen;
        case '+': return Plus;
        case '-': return Minus;
        case '*': return Times;
        case '/': return Divide;
        default: return Operand;
    }
}