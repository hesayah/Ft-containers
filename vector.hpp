/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/29 04:40:28 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://cplusplus.com/reference/vector/vector/
*** https://en.cppreference.com/w/cpp/container/vector
*** https://fr.acervolima.com/programme-pour-creer-une-classe-vectorielle-personnalisee-en-c/
**/

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#	include <memory>
# include "includes/legacy_random_acces_iterator.hpp"

namespace ft {
								template<class T, class Allocator = std::allocator<T>>
	class						vector 
	{
		public :
			typedef				T											value_type;
			typedef		 		Allocator									allocator_type;
			typedef				std::size_t									size_type;
			typedef				std::ptrdiff_t								difference_type;
			typedef				value_type&									reference;
			typedef				const  value_type&							const_reference;
			typedef				vector_iterator<T>							iterator;
			typedef				vector_iterator<const T>					const_iterator;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			typedef typename	std::reverse_iterator<iterator>				reverse_iterator;
			typedef typename	std::reverse_iterator<const_iterator>		const_reverse_iterator;

								vector();
		explicit				vector(const allocator_type&);
		explicit 				vector(size_type count, const T& value, const Allocator&);
								template <class InputIt>
								vector(InputIt first, InputIt last, const allocator_type&);	
								vector(const vector& src);
								~vector(void){};
		protected :
		T						*_vec;
		size_t					_capacity;
		size_t					_size;
		
/**
*** Members function
**/

		vector & 				operator=(const vector & src);
		void 					assign(size_type count, const T& value);
								template<class InputIt>
		void 					assign(InputIt first, InputIt last);
		allocator_type 			get_allocator() const;


/**
*** Iterators
**/

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

/**
*** Capacity
**/

		bool 					empty() const;
		void 					reserve(size_type new_cap);
		size_type 				size() const;
		size_type 				max_size() const;
		size_type 				capacity() const;

/**
*** Element access
**/
		T* 						data();
		reference 				at(size_type pos);
		reference 				operator[](size_type pos);
		reference 				front();
		reference 				back();

/**
*** Modifiers
**/

		void 					clear();
		void 					push_back(const T& value);
		void 					pop_back();
		void 					resize(size_type count, T value = T());
		void 					swap(vector	& other);
		iterator 				insert(const_iterator pos, const T & value);
		iterator 				insert(const_iterator pos, size_type count, const T & value);
								template<class InputIt>
		iterator 				insert(const_iterator pos, InputIt first, InputIt last);
		iterator 				erase(iterator pos);
		iterator 				erase(iterator first, iterator last);

/**
*** Vector operator
**/
		bool					operator==(const vector<T,Allocator> & rhs);
		bool					operator!=(const vector<T,Allocator> & rhs);
		bool					operator<(const vector<T,Allocator> & rhs);
		bool					operator<=(const vector<T,Allocator> & rhs);
		bool					operator>(const vector<T,Allocator> & rhs);
		bool					operator>=(const vector<T,Allocator> & rhs);
	};
}



#endif