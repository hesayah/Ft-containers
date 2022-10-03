/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/03 07:49:22 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://cplusplus.com/reference/vector/vector/
*** https://en.cppreference.com/w/cpp/container/vector
*** https://fr.acervolima.com/programme-pour-creer-une-classe-vectorielle-personnalisee-en-c/
**/

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <memory>
# include <iterator>
# include "includes/legacy_random_acces_iterator.hpp"
# include "includes/reverse_iterator.hpp"

namespace ft {
								template<class T, class Allocator = std::allocator<T> >
	class						vector 
	{
		public :
			typedef				T											value_type;
			typedef		 		Allocator									allocator_type;
			typedef				std::size_t									size_type;
			typedef				std::ptrdiff_t								difference_type;
			typedef				value_type&									reference;
			typedef				const  value_type&							const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			typedef				vector_iterator<T>							iterator;
			typedef				vector_iterator<const T>					const_iterator;
			typedef typename	std::reverse_iterator<iterator>				reverse_iterator;
			typedef typename	std::reverse_iterator<const_iterator>		const_reverse_iterator;

			protected :		
								allocator_type								_alloc;
								size_t										_capacity;
								size_t										_size;
								pointer										_base;

			public :

/**
***								Member functions 
**/
								
								/** 
								***  constructors
								**/
			explicit			vector(const Allocator& alloc = allocator_type()) : _capacity(0), _size(0),  _alloc(alloc)
								{
									_base = NULL;
									//alloc = allocator_type();_
									//_alloc = alloc;
								}
			explicit 			vector(size_type count, const_reference value = value_type(), const Allocator& alloc = allocator_type()) :  _alloc(alloc), _capacity(count), _size(count), _base(_alloc.allocate(count))
								{
									pointer		ptr;
									ptr = this->_base;
									for(size_t i = 0; i < count; i++)
										this->_alloc.construct(ptr++, value);
								}
/*								template <class InputIt>
								vector(InputIt first, InputIt last,const Allocator& alloc = Allocator()) : _alloc(alloc)
								{
									difference_type dist;
									dist = static_cast<size_type>(std::distance(first, last));
									this->_capacity = dist;
									this->_size = dist;
									this->_alloc.allocate(dist);
									std::uninitialized_copy(first, last, this->_base);
								}	*/
								vector(const vector& other)
								{
									*this = other;
								}
			 					~vector(void)
								{
									_alloc.deallocate(this->_base, this->_capacity);
								}
 		vector	& 				operator=(const vector& other)
								{
									this->_base = other._base;
									this->_alloc = other._alloc;
									this->_capacity = other._capacity;
									this->_size = other._size;
									return (*this);
								}
 /*		void 					assign(size_type count, const T& value)
								{

								}
 								template<class InputIt>
 		void 					assign(InputIt first, InputIt last)
								{

								}
 		allocator_type 			get_allocator() const
								{
									return (_alloc);
								}*/


// /**
// *** Iterators
// **/

 		iterator				begin(){return (this->_base);};
 		const_iterator			begin()const {return (this->_base);};
 		iterator				end(){return (this->_base[this->_size]);};
 		const_iterator			end() const {return (this->_base[this->_size]);};
//		reverse_std::		rbegin();
// 		const_reverse_std::	rbegin() const;
// 		reverse_iterator		rend();
// 		const_reverse_iterator	rend() const;

// /**
// *** Capacity
// **/

// 		bool 					empty() const {return (this->_size == 0);};
// 		void 					reserve(size_type new_cap) {pointer tmp; this->_alloc.allocate(5); };
// 		size_type 				size() const {return (this->_size);};
// 		size_type 				max_size() const {return (std::numeric_limits<difference_type>::max());};
// 		size_type 				capacity() const {return (this->_capacity);};

// /**
// *** Element access
// **/
// 		T* 						data();
// 		reference 				at(size_type pos);
// 		reference 				operator[](size_type pos);
// 		reference 				front();
// 		reference 				back();

// /**
// *** Modifiers
// **/

// 		void 					clear();
// 		void 					push_back(const T& value);
// 		void 					pop_back();
// 		void 					resize(size_type count, T value = T());
// 		void 					swap(vector	& other);
// 		iterator 				insert(const_iterator pos, const T & value);
// 		iterator 				insert(const_iterator pos, size_type count, const T & value);
// 								template<class InputIt>
// 		iterator 				insert(const_iterator pos, InputIt first, InputIt last);
// 		iterator 				erase(iterator pos);
// 		iterator 				erase(iterator first, iterator last);


	};
	
// /**
// *** Vector operator
// **/
// 		bool					operator==(const vector<T,Allocator>& other);
// 		bool					operator!=(const vector<T,Allocator>& other);
// 		bool					operator<(const vector<T,Allocator>& other);
// 		bool					operator<=(const vector<T,Allocator>& other);
// 		bool					operator>(const vector<T,Allocator>& other);
// 		bool					operator>=(const vector<T,Allocator>& other);
}



#endif