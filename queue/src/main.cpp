#include "queue.hpp"
#include <iostream>
int main()
{
    ft::queue<int> x;

    x.push(5);
    x.push(4);
    x.push(3);
    x.push(2);
    x.push(1);
    x.push(0);
    ft::queue<int> y;

    y.push(0);
    y.push(1);
    y.push(2);
    y.push(3);
    y.push(4);
    y.push(5);
    x.swap(y);
    while ( !x.empty() )
    {
        int top = x.front();
        std::cout << top << " ";
        x.pop();
    }
    

    return 0;
}
