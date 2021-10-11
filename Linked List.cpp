#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node // structure is an user defined data type and
// contains element of different data types and it is private by default
{
    int data;
    struct Node *next;
} *first = NULL;
// Creation of Linked list
void createLL(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < 5; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
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

// Counting Nodes and sum of nodes recursively
int countnodes(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return countnodes(p->next) + 1;
}
int sumofnodes(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return sumofnodes(p->next) + p->data;
}
// finding maximum in linked list recursively
int maxnode(struct Node *p)
{
    if (p == 0)
        return INT_MIN;
    int y = maxnode(p->next);
    return y > p->data ? y : p->data;
}
// Searching in a linked list recursively
int Search(int key, struct Node *p)
{
    if (p == NULL)
        return 0;
    if (key == p->data)
        return 1;
    return Search(key, p->next);
}
// Improved Linear Search by moving it to head
void ImprovedlinearSearch(int key, struct Node *p)
{
    struct Node *q = NULL;
    while (p->data != key)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next = first;
    first = p;
}

// Inserting  in a sorted  linked list
void insertinsorted(struct Node *p,int key)
{      struct Node *t=new Node;
       struct Node *q=NULL;
       t->data=key;
       t->next=NULL;
        if(first==NULL)
          first=t;
       else
       {
       while (p and p->data<key)
       {
           q=p;
           p=p->next;
       }
       if(p==first)
       {
           t->next=first;
           first=t;
       }
       else{
           t->next=p;
           q->next=t;
       }
       }
}

// Deletion in Linked List
void delete1(struct Node*p,int pos)
{   struct Node *q=NULL;
    if(pos==1)
    {  q=first;
       first=first->next;
       delete q; 

    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }
}
// check if a Linked List is sorted or not
bool isSorted(struct Node *p)
{
    struct Node *q = NULL;
    q = p;
    p = p->next;
    while (p and q->data <= p->data)
    {
        q = p;
        p = p->next;
    }
    if(p)
       return false;
    else
        return true;
} 

// Checking for duplicates in Linked List
void isDuplicate(struct Node *p)
{
    struct Node *q = NULL;
    q = p;
    p = p->next;
    while (p != NULL)
    {
        if (p->data == q->data)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
// Insertion in a Linked List---------> Two cases, before 1st Node and anywhere else
void insert(struct Node *p, int key, int pos)
{
    int i = 0;
    struct Node *t = new Node;
    struct Node *q = new Node;
    if (pos == 0)
    {
        t->data = key;
        t->next = first;
        first = t;
    }
    else
    {
        while (i < pos - 1 and p)
        {
            p = p->next;
            i++;
        }
        if (p)
        {
            q->data = key;
            q->next = p->next;
            p->next = q;
        }
        else
            cout << "Element not found" << endl;
    }
}
//  Simple Display of Linked list

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    //int a[] = {4, 6, 8, 12, 17};
    //createLL(a, 5);
    //RecursiveDisplay(first);
    //Display(first);
    //cout<<countnodes(first)<<endl;
    //cout<<sumofnodes(first)<<endl;
    //cout<<maxnode(first)<<endl;
    //ImprovedlinearSearch(12,first);
    //Display(first);
    //insertinsorted(first,3);
    //insertinsorted(first,27);
    //insertinsorted(first,100);
    //delete1(first,1);
    //insertlast(first,34);
    insert(first, 5, 0);
    insert(first, 5, 1);
    insert(first, 10, 2);
    insert(first, 20, 3);
    insert(first, 20, 4);
    insert(first, 20, 5);
    insert(first, 20, 6);
    //cout<<isSorted(first);
    isDuplicate(first);
    Display(first);
    return 0;
}
