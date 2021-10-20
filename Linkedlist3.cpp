//Finding middle node using two pointer technique and stack method, and finding intersection point of 2 Linked List using stack

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

// Creation of Linked list
void create1(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int b[], int n, struct Node *p)
{
    struct Node *last = NULL;
    second = new Node;
    second->data = b[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        struct Node *t = new Node;
        t->data = b[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = p;
}

// Display linked list (Recursively)
void RecursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        RecursiveDisplay(p->next);
    }
}

// finding middle node of a linked list using 2 pointer technique
int middle(struct Node *p)
{
    struct Node *q = first;
    while (q != NULL)
    {
        q = q->next;
        q = q != NULL ? q->next : q;
        p = q != NULL ? p->next : p;
    }
    return p->data;
}

// finding middle node of a linked list using stack
int stacktechnique(struct Node *p)
{
    stack<Node *> s;
    while (p)
    {
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int k = int(floor(length / 2.0));
    while (k)
    {
        s.pop();
        k--;
    }
    return s.top()->data;
}

// intersection point of 2 linked list

int intersection(struct Node *p, struct Node *q)
{
    Node *k;
    stack<Node *> s1;
    stack<Node *> s2;
    while (p)
    {
        s1.push(p);
        p = p->next;
    }
    while (q)
    {
        s2.push(q);
        q = q->next;
    }
    while (s1.top() == s2.top())
    {
        k = s1.top();
        s1.pop();
        s2.pop();
    }
    return k->data;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {13, 14, 15, 16, 17, 18};
    // creating 1st Linked list
    create1(a, 5);
    // Linking 3rd Node with second Linked list
    Node *temp = first;
    int i = 2;
    while (i > 0)
    {
        temp = temp->next;
        i--;
    }
    create2(b, 6, temp);
    // RecursiveDisplay(second);
    // cout<<middle(first);
    // cout<<stacktechnique(first);
    // cout<<intersection(first,second);
    return 0;
}
