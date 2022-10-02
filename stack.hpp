/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:44:52 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/02 09:39:42 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

#include <vector>

namespace ft {

	template<class T, class Container = std::vector<T>> 
	class stack {

		protected :

			std::vector<T>		_c;

		public :

			explicit 		stack(const Container& cont = Container());
							~stack();
			reference 		top() {return *(_c.back() - 1)};
			const_reference	top() const {return *(_c.cend() -1)};
			bool 			empty() const {return (_c.empty())};
			size_t			size() return (_c.size());
			void 			pop() {_c.pop_back()};
			void 			push(const value_type& value) {_c.push_back(value)};


	};

template< class T, class Container >
bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template< class T, class Container >
bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template< class T, class Container >
bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template< class T, class Container >
bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template< class T, class Container >
bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template< class T, class Container >
bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
}

#endif