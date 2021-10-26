#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define n 3
class stack1
{
    int top;
    int *a;

public:
    stack1()
    {
        a = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
            cout << "stack Overflow" << endl;
        else
        {
            top++;
            a[top] = x;
        }
    }
    int pop()
    {
        int y;
        if (top == -1)
            cout << "stack Underflow" << endl;
        else
        {
            y = a[top];
            top--;
        }
        return y;
    }
    int istop()
    {
        if (top == -1)
            cout << "No element in stack";
        return a[top];
    }
    void display()
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
    }
    bool isEmpty()
    {
          return top==-1;
    }
    bool isfull()
    {
          return top==n-1;
    }
};
int main()
{
    stack1 st;
    st.push(12);
    st.push(13);
    st.push(14);
    cout<<st.isfull()<<endl;
    cout << st.istop() << endl;
    st.pop();
    st.pop();
    cout << st.istop() << endl;
    cout << st.isEmpty() << endl;
    
    // st.display();
    return 0;
}
