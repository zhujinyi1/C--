#include <iostream>
#include <string>
using namespace std;

typedef struct Chain
{
    int num;
    struct Chain *next;
}*C, Node;

int main()
{
    int a, i = 1;
    C c[4], pnew, p, q, r;
    c[3] = new Node;
    c[1] = new Node;
    c[2] = new Node;
    c[3]->next = NULL;
    c[1]->next = NULL;
    c[2]->next = NULL;
    while (i <= 2)
    {
        p = c[i];
        cin >> a;
        while (a != -1)
        {
            pnew = new Node;
            pnew->num = a;
            pnew->next = p->next;
            p->next = pnew;
            p = p->next;
            cin >> a;
        }
        i++;
    }
    r = c[3];
    p = c[1]->next;
    q = c[2]->next;
    while (p != NULL && q != NULL)
    {
        if (p->num > q->num)
        {
            q = q->next;
        }
        if (p->num < q->num)
        {
            p = p->next;
        }
        if (p->num == q->num)
        {
            pnew = new Node;
            pnew->next = r->next;
            r->next = pnew;
            pnew->num = p->num;
            r = r->next;
            p = p->next;
            q = q->next;
        }
    }
    r = c[3];
    if (r->next == NULL)
    {
        cout << "NULL";
    }
    else
    {
        r = r->next;
        cout <<r->num;
        while (r->next != NULL)
        {
            r = r->next;
            cout << " " << r->num;
        }
    }
    return 0;
}