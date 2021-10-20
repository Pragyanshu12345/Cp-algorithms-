// Covered Loop, Merging,concatenation of singly Linked list and Circular Linked List

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
// length of circular linked list
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != first);
    return len;
}

// checking for LOOP in Linked List
bool isloop(struct Node *p)
{
    struct Node *q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p && q and p != q);
    return p == q ? true : false;
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
    last->next = first;
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
        cout << p->data << " ";
        p = p->next;
    }
}

// code to display circular linked list
void circulardisplay(struct Node *p)
{
    do
    {
        cout << p->data << " " << p->next << " " << p << endl;
        p = p->next;
    } while (p != first);
}

// insertion in a circular linked list
void circularinsert(struct Node *p, int key, int pos)
{
    if (pos == 0)
    {
        struct Node *t = new Node;
        t->data = key;
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            while (p->next != first)
                p = p->next;
            p->next = t;
            t->next = first;
            first = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        struct Node *t = new Node;
        t->data = key;
        t->next = p->next;
        p->next = t;
    }
}

// Deletion in circular linked list
void deletecircular(struct Node *p, int key, int pos)
{
    struct Node *q = NULL;
    if (pos == 1)
    {
        while (p->next != first)
            p = p->next;
        if (first == p)
        {
            delete first;
            first = NULL;
        }
        else
        {
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        delete q;
    }
}
int main()
{ // struct Node *t1,*t2;
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int b[] = {80, 90, 100, 110, 120};
    //create1(a, 7);
    //deletecircular(first,10,1);
    //circulardisplay(first);
    // cout<<Length(first);
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    // Display(first);
    //circularinsert(first, 34, 0);
    //circularinsert(first, 44, 1);
    //circularinsert(first, 54, 2);
    //circularinsert(first, 64, 3);
    //circularinsert(first, 74, 4);
    //circulardisplay(first);
    // cout<<isloop(first);
    // create2(b, 5);
    // merge(first, second);
    // concantenate(first);
    // reverserecursion(first,NULL);
    return 0;
}
