#include <iostream>
#include "MutantStack.hpp"


// int main()
// {
//     MutantStack<int> arr;

//     arr.push(1);
//     arr.push(2);
//     arr.push(3);
//     arr.push(4);
//     arr.push(5);

//     std::cout <<"arr size--- >  "<< arr.size() << std::endl;
//     return 0;
// }

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--ite;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
