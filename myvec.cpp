#include "vector.hpp"
#include "is_integral.hpp"

void    vector_constructor_test(void)
{
	ft::vector<int> on;
	std::cout << "vector empty construct"<< std::endl;

	ft::vector<int> two;

	on = two;
	std::cout << "vector empty construct"<< std::endl;
}


int main(void)
{
    std::cout << "vector construct test"<< std::endl;
    vector_constructor_test();

    return (0);
}