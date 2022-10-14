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

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main ()
{
	ft::vector<char> vct;
	ft::vector<char>::iterator it = vct.begin();
	ft::vector<char>::const_iterator cit = vct.begin();

	ft::vector<char>::reverse_iterator rit(it);

	ft::vector<char>::const_reverse_iterator crit(rit);
	ft::vector<char>::const_reverse_iterator crit_(it);
	ft::vector<char>::const_reverse_iterator crit_2(cit);
	std::cout << "OK" << std::endl;

}
