/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:44:52 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/14 07:06:32 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "vector.hpp"

namespace ft {

	template<class T, class Container = vector<T> > 
	class stack 
	{
		public :

			typedef				Container 						container_type;
			typedef	typename	Container::value_type			value_type;
			typedef	typename	Container::size_type			size_type;
			typedef typename	Container::reference			reference;
			typedef typename	Container::const_reference 		const_reference;

		protected :
								container_type					_c;
		public :

			explicit 			stack(const Container& cont = Container()) : _c(cont) {}
								~stack(){}
			reference 			top() {return (_c.back());}
			const_reference		top() const {return (_c.back());}
			bool 				empty() const {return (_c.empty());}
			size_type			size() const {return (_c.size());}
			void 				pop() {_c.pop_back();}
			void 				push(const value_type& value) {_c.push_back(value);}

			friend	bool		operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c == rhs._c);}
			friend	bool		operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c != rhs._c);}
			friend	bool		operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c < rhs._c);}
			friend	bool		operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c <= rhs._c);}
			friend	bool		operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c > rhs._c);}
			friend	bool		operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._c >= rhs._c);}
	};
}

#endif