/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/13 03:42:48 by hesayah          ###   ########.fr       */
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
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include "includes/enable_if.hpp"
# include "includes/is_integral.hpp"
# include "includes/equal.hpp"
# include "includes/lexicographical_compare.hpp"
# include "includes/legacy_random_acces_iterator.hpp"
# include "includes/reverse_iterator.hpp"

namespace ft {
	template<typename T, class Allocator = std::allocator<T> >
	class vector 
	{
		public :
			typedef				T											value_type;
			typedef				Allocator									allocator_type;
			typedef				std::size_t									size_type;
			typedef typename	Allocator::difference_type					difference_type;
			typedef typename	Allocator::reference						reference;
			typedef typename	Allocator::const_reference					const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			typedef	typename	vector_iterator<pointer>::pointer			iterator;
			typedef	typename	vector_iterator<const_pointer>::pointer			const_iterator;
			typedef typename	std::reverse_iterator<iterator>				reverse_iterator;
			typedef typename	std::reverse_iterator<const_iterator>		const_reverse_iterator;

			protected :
								allocator_type								_alloc;
								size_type									_capacity;
								size_type									_size;
								pointer										_base;
			private :

			void				_check_storage_limit(size_type new_cap) const
								{
									if (new_cap > this->max_size())
										throw std::length_error("new_cap over max_size() !");
								}

			void				_check_range_limit(size_type pos) const
								{
									if (pos >= this->_size)
										throw std::out_of_range("pos out of range !");
								}

								template <typename InputIt>
			difference_type		_distance(InputIt first, InputIt last)
								{
									InputIt					tmp_it;
									difference_type			n;

									n = 0;
									tmp_it = first;
									for (; tmp_it != last; ++tmp_it)
										n++;
									return (n);
								}
			void				_allocate(size_type new_cap)
								{
									    try {
											this->_base = this->_alloc.allocate(new_cap);
										}
    									catch (const std::bad_alloc& e) {  
											std::cout  << e.what() << std::endl;
    									}
									this->_capacity = new_cap;
								}
			void				_deallocate(void)
								{
									if (this->_capacity && this->_base)
										this->_alloc.deallocate(this->_base, this->_capacity);
									this->_capacity = 0;
									this->_base = NULL;
								}
			void				_clear(void)
								{
									if (this->_size)
									{
										for (size_type i = 0; i < this->_size; i++)
											this->_alloc.destroy(this->_base + i);
										this->_size = 0;
									}
								}
			public :
/** 
***								constructors
**/
			explicit			vector(const Allocator& alloc = allocator_type()) :  _alloc(alloc), _capacity(0), _size(0) , _base(NULL)
								{}
			explicit 			vector(size_type count, const_reference value = value_type(), const Allocator& alloc = allocator_type()) :  _alloc(alloc), _capacity(0), _size(0) , _base(NULL)
								{
									this->assign(count, value);
								}
								template <typename InputIt>
								vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator()) : _alloc(alloc), _capacity(0), _size(0) , _base(NULL)
								{
									assign(first, last);
								}
								vector(const vector& other) : _alloc(other._alloc), _capacity(0), _size(0) , _base(NULL)
								{
									*this = other;
								}
			 					~vector(void)
								{
									this->clear();
									this->_deallocate();
								}
/**
***								Member functions 
**/
 		vector	& 				operator=(const vector& other)
								{
									if (this != &other)
										this->assign(other.begin(), other.end());
									return (*this);
								}								
		void 					assign(size_type count, const T& value)
								{
									this->_check_storage_limit(count);
									this->_clear();
									for(size_type i = 0; i < count; i++)
										push_back(value);
								}
 								template<typename InputIt>
 		void 					assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last)
								{
									this->_clear();
									for (; first != last; ++first) 
           								push_back(*first);
								}
 		allocator_type 			get_allocator() const
								{
									return (this->_alloc);
								}
/**
*** 							Iterators
**/
 		iterator				begin()
								{
									return (this->_base);
								}
 		const_iterator			begin() const
								{
									return (this->_base);
								}
		iterator				end()
								{
									return (this->_base + this->_size);
								}
		const_iterator			end() const 
								{
									return (this->_base + this->_size);
								}
 		bool 					empty() const 
								{
									return (begin() == end());
								}
 		void 					reserve(size_type new_cap)
								{
									this->_check_storage_limit(new_cap);
									if (new_cap > this->_capacity && new_cap <= this->max_size())
									{
										iterator				tmp_it;
										pointer					tmp_ptr;
										pointer					new_ptr;
										size_type				tmp_size;

										new_ptr = this->_alloc.allocate(new_cap);
										tmp_it = this->begin();
										tmp_ptr = new_ptr;
										for(;tmp_it != this->end(); ++tmp_it)
											this->_alloc.construct(tmp_ptr++, *tmp_it);
										tmp_size = this->_size;
										this->_clear();
										this->_deallocate();
										this->_size =tmp_size;
										this->_capacity = new_cap;
										this->_base = new_ptr;
									}
								}
 		size_type 				size() const 
								{
									return (this->_size);
								}
 		size_type 				max_size() const 
								{
									return (this->_alloc.max_size());
								}
 		size_type 				capacity() const
								{
									return (this->_capacity);
								}
/**
*** Element access
**/

		reference 				operator[] (size_type n)
								{
									return (this->_base[n]);
								}
		const_reference 		operator[] (size_type n) const
								{
									return (this->_base[n]);
								}
		reference 				at(size_type n) 
								{
									this->_check_range_limit(n);
									return (this->_base[n]);
								}
		const_reference 		at (size_type n) const 
								{
									this->_check_range_limit(n);
									return (this->_base[n]);
								}
 		reference 				front()
								{
									return (*this->begin());
								}
		const_reference 		front() const
								{
									return (*this->begin());
								}
 		reference 				back()
								{
									return (*(this->end() - 1));
								}
 		const_reference 		back() const
								{
									return (*(this->end() - 1));
								}
/**
*** 							Modifiers
**/
		void 					clear()
								{
									this->_clear();
								}
		void 					push_back(const T& value)
								{
									if ((this->_size + 1) > this->_capacity)
										this->reserve((this->_capacity * 2) + 1);
									this->_alloc.construct(this->_base + this->_size, value);
									++this->_size;
								}
		void 					pop_back()
								{
									if (!this->_size)
										return ;
									this->_alloc.destroy(this->_base + this->_size - 1);
									--this->_size; 
								}
		void 					resize(size_type count, T value = value_type())
								{
									_check_storage_limit(count);
									if (count > this->_size)
										for (; this->_size < count;)
											this->push_back(value);
									else
										for (; this->_size > count;)
											this->pop_back();
								}
		void 					swap(vector	& other)
								{
									vector	tmp_vector;

									tmp_vector = other;
									other = *this;
									*this = tmp_vector;
								}
		iterator 				insert(iterator pos, const T & value)
								{									
									(void)pos;
						//			(void)count;
									(void)value;
									/*difference_type n = _distance(this->begin(), pos);
									reserve(_size + 1);
									for (difference_type i = this->_size; i > n; i--)
									{
										this->_alloc.construct(_base + i, *(this->_base + i - 1));
										this->_alloc.destroy(this->_base + i - 1);
									}
									_alloc.construct(this->_base + n, value);
									_size++;*/
									return (this->_base);

								}
		void					insert(iterator pos, size_type count, const T & value)
								{
									(void)pos;
									(void)count;
									(void)value;
								}
								template<class InputIt>
		void					insert(iterator pos, InputIt first,  typename enable_if<!is_integral<InputIt>::value, InputIt>::type last)
								{
									(void)pos;
									(void)first;
									(void)last;
								}
	/*	iterator 				erase(iterator pos)
								{
									return (this->begin());
								}
		iterator 				erase(iterator first, iterator last)
								{
									return (this->begin());
								}*/

	};
	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		if (lhs.size() == rhs.size()) {

			return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		return (false);
	}

	template <class T, class  Allocator>
	bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		return (!(lhs == rhs));
	}

	template <class T, class  Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		if (lhs != rhs) {
			return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		return (false);
	}

	template <class T, class  Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(rhs < lhs));
	}

	template <class T, class  Allocator>
	bool operator>  (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		if (lhs == rhs)
			return (false);
		return (rhs < lhs);
	}

	template <class T, class  Allocator>
	bool operator>= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {

		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	}

	template <class T, class  Allocator>
	void swap(vector<T, Allocator>& x, vector<T, Allocator>& y) {

		x.swap(y);
	}
}



#endif