#include "vector.hpp"
#include "includes/is_integral.hpp"
#include <string>
#include <iostream>

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
 
int main() 
{
    // C++11 initializer list syntax:
    ft::vector<std::string> words1(5, "Mo");
    std::cout << "words1: " << words1 << '\n';
 
    // words2 == words1
  	ft::vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
 
    // words3 == words1
    ft::vector<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';

    ft::vector<std::string> words5 = words3;
	std::cout << "words3:  cap" << words5.capacity() << '\n';
}