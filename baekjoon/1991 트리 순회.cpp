#include <iostream>

typedef struct _Node {

    char data;
    struct _Node *llink;
    struct _Node *rlink;

} Node;


void insertNode(Node* head, char parent, char ldata, char rdata);
void parentNode(Node* head, Node** temp, char parent);
void inorderTraversal(Node* ptr);
void preorderTraversal(Node* ptr);
void postorderTraversal(Node* ptr);

using namespace std;

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    Node* head = new Node;
    head->data = 'A';
    head->llink = NULL;
    head->rlink = NULL;
    

    char parent, ldata, rdata;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> parent >> ldata >> rdata;

        // leaf 노드가 아닐 경우
        if (ldata != '.' || rdata != '.')
            insertNode(head, parent, ldata, rdata);
    }

    preorderTraversal(head);
    cout << '\n';

    inorderTraversal(head);
    cout << '\n';

    postorderTraversal(head);

    return 0;
}

void insertNode(Node* head, char parent, char ldata, char rdata)
{
    Node *searchNode = NULL;
    parentNode(head, &searchNode, parent);
    
    if (ldata != '.')
    {
        Node *newLNode = new Node;

        newLNode->data = ldata;
        newLNode->llink = NULL;
        newLNode->rlink = NULL;

        searchNode->llink = newLNode;
    }
    
    if (rdata != '.')
    {
        Node *newRNode = new Node;

        newRNode->data = rdata;
        newRNode->llink = NULL;
        newRNode->rlink = NULL;

        searchNode->rlink = newRNode;
    }
}

void parentNode(Node* searchNode, Node** temp, char parent)
{
    if (searchNode != NULL && *temp == NULL)
    {
        if (searchNode->data == parent) *temp = searchNode;

        parentNode(searchNode->llink, temp, parent);
        parentNode(searchNode->rlink, temp, parent);
    }
}

void inorderTraversal(Node* ptr)
{
    if (ptr != NULL)
    {
        inorderTraversal(ptr->llink);
        cout << ptr->data;
        inorderTraversal(ptr->rlink);
    }
}

void preorderTraversal(Node* ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data;
        preorderTraversal(ptr->llink);
        preorderTraversal(ptr->rlink);
    }
}

void postorderTraversal(Node* ptr)
{
    if (ptr != NULL)
    {
        postorderTraversal(ptr->llink);
        postorderTraversal(ptr->rlink);
        cout << ptr->data;
    }
}