#include "vector.hpp"
#include "includes/is_integral.hpp"
#include <string>
#include <iostream>

void    vector_constructor_test(void)
{
	ft::vector<int> on;
	std::cout << "vector empty construct"<< std::endl;

	ft::vector<int> two;

	on = two;
	std::cout << "vector empty construct"<< std::endl;
	
}

int main() 
{
	std::cout << "vector construct test"<< std::endl;
    vector_constructor_test();
    ft::vector<int> words1(10, 50);

  for (ft::vector<int>::iterator it = words1.begin(); it != words1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';    // words2 == words1
    //ft::vector<std::string> words2(words1.begin(), words1.end());
 
    // words3 == words1
    //ft::vector<std::string> words3(words1);
 
    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
   // ft::vector<std::string> words4(5, "Mo");


	return (0);
}