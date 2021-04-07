#include <iostream>
#include <stack>

using namespace std;

struct Node {

    char data;
    struct Node* next;

};

struct Stack {

    Node* peek;
    int size;

};

void initStack(Stack **s_stack);
void stackPush(Stack *s_stack, char data);
void stackPop(Stack *s_stack);

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int Error_paren = 0; // 괄호의 수가 매치되는지 확인
    bool Error = false; 

    string postfix;
    string str;
    cin >> str;

    Stack* s_stack;
    initStack(&s_stack);

    

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            Error_paren++;
            stackPush(s_stack, str[i]);
        }
        
        else if (str[i] == ')')
        {
            if (s_stack->size == 0)
            {
                Error = true;
                break;
            }

            if (s_stack->peek->data == '(') // 즉, () 라면
            {
                Error_paren--;

                stackPop(s_stack);
                stackPush(s_stack, 'X');

                postfix += '2';
            }

            else if (s_stack->peek->data == 'X' && s_stack->size >= 2)
            {
                if (s_stack->peek->next->data == '(') // 즉, (X) 라면
                {
                    Error_paren--;

                    stackPop(s_stack);
                    stackPop(s_stack);
                    stackPush(s_stack, 'X');

                    postfix += "2*";
                }

                else
                {
                    Error = true;
                    break;
                }
            }

            else
            {
                Error = true;
                break;
            }
        }

        else if (str[i] == ']')
        {
            if (s_stack->size == 0)
            {
                Error = true;
                break;
            }

            if (s_stack->peek->data == '[') // 즉, [] 라면
            {
                Error_paren--;

                stackPop(s_stack);
                stackPush(s_stack, 'X');

                postfix += '3';
            }

            else if (s_stack->peek->data == 'X' && s_stack->size >= 2)
            {
                if (s_stack->peek->next->data == '[') // 즉, [X] 라면
                {
                    Error_paren--;

                    stackPop(s_stack);
                    stackPop(s_stack);
                    stackPush(s_stack, 'X');

                    postfix += "3*";
                }

                else
                {
                    Error = true;
                    break;
                }
            }

            else
            {
                Error = true;
                break;
            }
        }

        if (s_stack->size >= 2) // XX 일 경우,
        {
            if (s_stack->peek->data == 'X' && s_stack->peek->next->data == 'X')
            {
                stackPop(s_stack);
                stackPop(s_stack);
                stackPush(s_stack, 'X');

                postfix += '+';
            }
        }
    }

    if (Error || Error_paren != 0)
        cout << "0";

    else
    {
        // 후위표기식 계산하기
        stack<int> result;
        int op1, op2, temp;

        for (int i = 0; postfix[i] != '\0'; i++)
        {
            temp = postfix[i];

            if (temp >= '0' && temp <= '9')
                result.push(temp - '0');

            else
            {
                op1 = result.top(); result.pop();
                op2 = result.top(); result.pop();

                //cout << "op1 : " << op1 << "    op2 : " << op2 << endl;
                if (temp == '+')
                    result.push(op1+op2);

                else if (temp == '*')
                    result.push(op1*op2);
            }
        }

        cout << result.top();
    }

    return 0;
}

void initStack(Stack **s_stack)
{
    (*s_stack) = (Stack*)malloc(sizeof(Stack));

    (*s_stack)->peek = NULL;
    (*s_stack)->size = 0;
}

void stackPush(Stack *s_stack, char data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    // if s_stack is empty
    if (s_stack->size == 0)
        s_stack->peek = newNode;
    
    // if s_stack is not empty
    else
    {
        newNode->next = s_stack->peek;
        s_stack->peek = newNode;
    }

    s_stack->size++;
}

void stackPop(Stack *s_stack)
{
    Node* freeNode = s_stack->peek;

    if (s_stack->size == 1)
        s_stack->peek = NULL;

    else
        s_stack->peek = s_stack->peek->next;
    
    s_stack->size--;
    free(freeNode);
}