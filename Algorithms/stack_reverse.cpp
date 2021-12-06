#include <stack>
#include <iostream>

void transfer_elements(std::stack<int> &s1, std::stack<int> &s2, int size)
{
    for (int i = 0; i < size; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void stack_reverse(std::stack<int> &s)
{
    if (s.empty())
        return;
    std::stack<int> temp;
    int val, n = s.size();
    for (int i = 0; i != n; i++)
    {
        val = s.top();
        s.pop();
        transfer_elements(s, temp, n - i - 1);
        s.push(val);
        transfer_elements(temp, s, n - i - 1);
    }
}

int main()
{
    std::stack<int> s1;
    s1.push(5);
    s1.push(3);
    s1.push(4);
    s1.push(1);
    s1.push(2);
    stack_reverse(s1);
    while (!s1.empty())
    {
        std::cout << s1.top() << std::endl;
        s1.pop();
    }
}