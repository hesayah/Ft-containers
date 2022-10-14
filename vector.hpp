/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/14 23:56:57 by hesayah          ###   ########.fr       */
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
# include <limits>
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
			typedef				T													value_type;
			typedef				Allocator											allocator_type;
			typedef				std::size_t											size_type;
			typedef typename	Allocator::difference_type							difference_type;
			typedef typename	Allocator::reference								reference;
			typedef typename	Allocator::const_reference							const_reference;
			typedef typename	Allocator::pointer									pointer;
			typedef typename	Allocator::const_pointer							const_pointer;
			typedef	typename	vector_iterator<pointer>::pointer					iterator;
			typedef	typename	vector_iterator<const_pointer>::pointer				const_iterator;
			typedef	 			reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef 			reverse_iterator<iterator>							reverse_iterator;
		

			protected :
								allocator_type										_alloc;
								size_type											_capacity;
								size_type											_size;
								pointer												_base;
			private :

			void				_check_storage_limit(size_type new_cap) const
								{
									if (new_cap > this->max_size())
										throw std::length_error("vector::reserve");
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
											std::cout <<  e.what();
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
								vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0) , _base(NULL)
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
		reverse_iterator		rbegin()
								{
									return (reverse_iterator(end()));
								}
		const_reverse_iterator	rbegin() const 
								{
									return (const_reverse_iterator(end()));
								}
		reverse_iterator		rend()
								{
									return (reverse_iterator(begin()));
								}
 		const_reverse_iterator	rend() const
								{
									return (const_reverse_iterator(begin()));
								}
 		bool 					empty() const 
								{
									return (begin() == end());
								}
 		void 					reserve(size_type new_cap)
								{
									this->_check_storage_limit(new_cap);
									if (new_cap > this->_capacity)
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
										this->_size = tmp_size;
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
									if (!_capacity)
										reserve(1);
									if ((this->_size + 1) > this->_capacity)
										this->reserve(this->_capacity * 2);
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
									allocator_type	alloc;
									size_type		capacity;
									size_type		size;
									pointer			ptr;

									alloc = this->_alloc;
									this->_alloc = other._alloc;
									other._alloc = alloc;

									capacity = this->_capacity;
									this->_capacity = other._capacity;
									other._capacity = capacity;

									size = this->_size;
									this->_size = other._size;
									other._size = size;

									ptr = this->_base;
									this->_base = other._base;
									other._base = ptr;
								}
				iterator		insert(iterator pos, const value_type& value)
								{
									difference_type n_pos = _distance(this->begin(), pos);
									if (!_capacity)
										reserve(1);
									if ((this->_size + 1) > this->_capacity)
										this->reserve(this->_capacity * 2);
									for (difference_type i = _size; i > n_pos; i--)
									{
										_alloc.construct(_base+ i, *(_base+ i - 1));
										_alloc.destroy(_base+ i - 1);
									}
									_alloc.construct(_base+ n_pos, value);
									_size++;
									return (_base + n_pos);
								}
				void 			insert(iterator pos, size_type count, const value_type& value)
								{
									difference_type n_pos = _distance(this->begin(), pos);

									if (_size + count > _capacity)
										reserve(_size * 2 > _size + count ? _size * 2 : _size + count);
									for (size_type i = 0; i < count; i++)
										this->insert(_base + n_pos + i, value);
								}
								template <class InputIterator>
				void			insert(iterator pos, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
								{
									vector 			tmp(first, last);
									difference_type n_pos = _distance(this->begin(), pos);

									if (_size + tmp.size() > _capacity)
										reserve(_size * 2 > _size + tmp.size() ? _size * 2 : _size + tmp.size());
									reserve(_size + tmp.size());
									iterator beg = tmp.begin();
									for (size_type i = 0; i < tmp.size(); i++)
										this->insert(_base + n_pos + i, *(beg + i));
								}
		iterator 				erase(iterator pos)
								{
									pointer tmp = pos;

									for (;tmp != this->_base + _size - 1; tmp++)
										*tmp = *(tmp + 1);
									resize(this->_size - 1);
									return (pos);
								}
		iterator 				erase(iterator first, iterator last)
								{
									vector tmp(begin(), first);
									vector tmp_two(last, end());
									difference_type new_size = _size - _distance(first, last);
									resize(new_size);
									size_type i = 0;
									for (; i < tmp.size(); i++)
										*(_base + i) = *(tmp.begin() + i);
									for (size_type j = 0 ; j < tmp_two.size(); j++)
										*(_base + i + j) = *(tmp_two.begin() + j);
									return (first);
								}

	};
				template <class T, class Allocator>
	bool 		operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return  (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

				template <class T, class  Allocator>
	bool 		operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return (!(lhs == rhs));}

				template <class T, class  Allocator>
	bool 		operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

				template <class T, class  Allocator>
	bool 		operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return (!(rhs < lhs));}

				template <class T, class  Allocator>
	bool 		operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return (rhs < lhs);}

				template <class T, class  Allocator>
	bool 		operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs) {return (!(lhs < rhs));}

				template <class T, class  Allocator>
	void		swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs) {lhs.swap(rhs);}
}

#endif