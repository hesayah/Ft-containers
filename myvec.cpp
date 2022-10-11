#include "vector.hpp"
#include "includes/is_integral.hpp"
#include <string>
#include <iostream>
#include <list>

template<typename T>
std::ostream& operator<<(std::ostream& s, const ft::vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
 

int main ()
{
  ft::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
