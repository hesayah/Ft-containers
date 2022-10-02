#include "stack.hpp"
#include <iostream>
 
void reportStackSize(const ft::stack<int>& s)
{
    std::cout << s.size() << " elements on stack\n";
}
 
void reportStackTop(const ft::stack<int>& s)
{
    // Leaves element on stack
    std::cout << "Top element: " << s.top() << '\n';
}
 
int main()
{
    ft::stack<int> s;
    s.push(2);
    s.push(6);
    s.push(51);
 
    reportStackSize(s);
    reportStackTop(s);
 
    reportStackSize(s);
    s.pop();
 
    reportStackSize(s);
    reportStackTop(s);
}