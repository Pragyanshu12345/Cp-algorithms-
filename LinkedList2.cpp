#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
// reversing a linked list using Sliding pointers
void reverseLinkedlist(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
// reversing a linked list using recursion

void reverserecursion(struct Node *p, struct Node *q)
{
    if (p)
    {
        reverserecursion(p->next, p);
        p->next = q;
    }
    else
        first = q;
}
void concantenate(struct Node *p)
{
    while (p->next)
        p = p->next;
    p->next = second;
    second = NULL;
}
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}
void create1(int a[], int n)
{
    struct Node *last = NULL;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        struct Node *t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int b[], int n)
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
}
void Display(struct Node *p)
{
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int a[]={10,20,30,40,50,60,70}; 
    int b[]={80,90,100,110,120};
    //create1(a, 6);
    //create2(b, 5);
    //merge(first, second);
    //concantenate(first);
    //reverserecursion(first,NULL);
    //Display(first);
    return 0;
}
