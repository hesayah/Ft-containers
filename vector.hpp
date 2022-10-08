/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/08 07:43:21 by hesayah          ###   ########.fr       */
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
			typedef	typename	Allocator::reference						reference;
			typedef	typename	Allocator::const_reference					const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			typedef				vector_iterator<value_type>					iterator;
			typedef				vector_iterator<const value_type>				const_iterator;
			typedef typename	std::reverse_iterator<iterator>				reverse_iterator;
			typedef typename	std::reverse_iterator<const_iterator>		const_reverse_iterator;

			protected :		
								allocator_type								_alloc;
								size_t										_capacity;
								size_t										_size;
								pointer										_base;
			private :

			void				_check_storage_limit(size_t new_cap) const
								{
									if (new_cap > this->max_size())
										throw std::length_error("new_cap over max_size() !");
								}

			void				_check_range_limit(size_t pos) const
								{
									if (pos > this->size())
										throw std::out_of_range("pos out of range !");
								}

								template <class InputIt>
			difference_type 	_distance(InputIt first, InputIt last)
								{
									InputIt					tmp_it;
									difference_type			n;

									n = 0;
									tmp_it = first;
									for (; tmp_it != last; ++tmp_it)
										n++;
									return (n);
								}
			void				_allocate(size_t new_cap)
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
									if (!this->empty())
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
								template <class InputIt>
								vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = NULL) : _alloc(alloc), _capacity(0), _size(0) , _base(NULL)
								{
									this->assign(first, last);
								}
								vector(const vector& other)
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
									pointer		ptr;

									if (!count)
										return ;
									this->clear();
									this->_deallocate();
									this->_check_storage_limit(count);
									this->_allocate(count);
									ptr = this->_base;
									this->_size = count;
									this->_capacity = count;
									for(size_type i = 0; i < count; i++)
										this->_alloc.construct(ptr++, value);
								}
 								template<class InputIt>
 		void 					assign(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = NULL)
								{
									difference_type 		dist;
									pointer					ptr;

									this->clear();
									this->_deallocate();
									if (first == last)
										return ;
									dist = this->_distance(first, last);
									this->_size = static_cast<size_type>(dist);
									this->_capacity = static_cast<size_type>(dist);
									this->_check_storage_limit(this->_capacity);
									this->_allocate(this->_capacity);
									ptr = this->_base;
									for(; first != last; ++first)
										this->_alloc.construct(ptr++, *first);
								}
 		allocator_type 			get_allocator() const
								{
									return (this->_alloc);
								}
/**
*** 							Iterators
**/
 		iterator				begin() const
								{
									return (this->_base);
								}
 		/*const_iterator			begin() const 
								{
									return (const_iterator(this->_base));
								}*/
 		iterator				end() const
								{
									return (this->_base + this->_size);
								}
/* 		const_iterator			end() const 
								{
									pointer end;

									end = (&(this->_base[this->_size]));
									return (const_iterator(end));
								}*/
//		reverse_std::		rbegin();
// 		const_reverse_std::	rbegin() const;
// 		reverse_iterator		rend();
// 		const_reverse_iterator	rend() const;
/**
*** 							Capacity
**/
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
 		reference 				at(size_type pos) const
								{
									this->_check_range_limit(pos);
									return ((this->_base[pos]));
								}
 		reference 				operator[](size_type pos) const
								{
									return ((this->_base[pos]));
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
									if (this->size() + 1 > this->capacity())
										this->reserve(this->capacity() * 2);
									this->_size += 1;
									this->_alloc.construct(this->_base + this->_size, value);
									
								}
		void 					pop_back()
								{
									this->_alloc.destroy(this->_base + this->_size - 1);
									this->_size -= 1; 
								}
		void 					resize(size_type count, T value = T())
								{
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
		iterator 				insert(const_iterator pos, const T & value)
								{
									pointer tmp_ptr;

									tmp_ptr = this->_base;
									for (;tmp_ptr != this->_base + pos; tmp_ptr++)
									{
										this->_alloc.destroy(tmp_ptr);
										this->_alloc.construct(tmp_ptr, value);
									}
									return (this->begin());
								}
		iterator 				insert(const_iterator pos, size_type count, const T & value)
								{
									pointer tmp_ptr;

									tmp_ptr = this->_base;
									for (;tmp_ptr != this->_base + pos && count != pos ; tmp_ptr++)
									{
										this->_alloc.destroy(tmp_ptr);
										this->_alloc.construct(tmp_ptr, value);
									}
									return (this->begin());
								}
/*								template<class InputIt>
		iterator 				insert(const_iterator pos, InputIt first, InputIt last)
								{
									
								}
		iterator 				erase(iterator pos)
								{
									
								}
		iterator 				erase(iterator first, iterator last)
								{
									
								}*/
					
	/*					friend		void swap (vector<T,Allocator>& lhs, vector<T,Allocator>& rhs) {lhs.swap(rhs);}
							
						friend		bool operator==(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {lhs == rhs ? true : false;}
								
						friend		bool operator!=(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {return (lhs != rhs);}
								
						friend		bool operator>(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {return (lhs > rhs);}
								
						friend		bool operator<(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {return (lhs < rhs);}
								
						friend		bool operator>=(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {return (lhs >= rhs);}
								
						friend		bool operator<=(const vector<T,Allocator>& lhs,const vector<T,Allocator>& rhs) {return (lhs <= rhs);}*/
	};
								template <class T, class Alloc>
								void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) {lhs.swap(rhs);}
								template<class T, class Alloc>
								bool operator==(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs == rhs);}
								template<class T, class Alloc>
								bool operator!=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs != rhs);}
								template<class T, class Alloc>
								bool operator>(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs > rhs);}
								template<class T, class Alloc>
								bool operator<(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs < rhs);}
								template<class T, class Alloc>
								bool operator>=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs >= rhs);}
								template<class T, class Alloc>
								bool operator<=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) {return (lhs <= rhs);}
}



#endif