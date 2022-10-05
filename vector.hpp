/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:09:54 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/04 10:06:37 by hesayah          ###   ########.fr       */
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
			typedef				vector_iterator<value_type>					iterator;
			typedef				vector_iterator<const value_type>			const_iterator;
//			typedef typename	std::reverse_iterator<iterator>				reverse_iterator;
//			typedef typename	std::reverse_iterator<const_iterator>		const_reverse_iterator;

			protected :		
								allocator_type								_alloc;
								size_t										_capacity;
								size_t										_size;
								pointer										_base;

			public :
/** 
***								constructors
**/
			explicit			vector(const Allocator& alloc = allocator_type()) : _capacity(0), _size(0),  _alloc(alloc) , _base(NULL)
								{}
			explicit 			vector(size_type count, const_reference value = value_type(), const Allocator& alloc = allocator_type()) :  _alloc(alloc), _capacity(count), _size(count), _base(_alloc.allocate(count))
								{
									pointer		ptr;
									ptr = this->_base;
									for(size_t i = 0; i < count; i++)
										this->_alloc.construct(ptr++, value);
								}
								template <class InputIt>
								vector(InputIt first, InputIt last,const Allocator& alloc = Allocator()) : _alloc(alloc)
								{
									size_type 		dist;
									iterator		tmp_it;
									
									dist = 0;
									tmp_it = first;
									for (; tmp_it != last; ++tmp_it)
										dist++;
									this->_capacity = dist;
									this->_size = this->_capacity;
									this->_base = this->_alloc.allocate(this->_capacity);
									std::uninitialized_copy(first, last, this->_base);
								}
								vector(const vector& other)
								{
									*this = other;
								}
			 					~vector(void)
								{
									this->clear();
									this->_alloc.deallocate(this->_base, this->_capacity);
								}
/**
***								Member functions 
**/
 		vector	& 				operator=(const vector& other)
								{
									this->_alloc = other._alloc;
									this->_base = this->_alloc.allocate(other._capacity);
									this->_capacity = other._capacity;
									this->_size = other._size;
									std::uninitialized_copy(other.begin(), other.end(), this->_base);
									return (*this);
								}								
		void 					assign(size_type count, const T& value)
								{
									pointer		ptr;

									this->clear();
									this->_size = count;
									ptr = this->_base;
									for(size_type i = 0; i < count; i++)
										this->_alloc.construct(ptr++, value);
								}
 								template<class InputIt>
 		void 					assign(InputIt first, InputIt last)
								{
									size_type 		dist;
									iterator		tmp_it;

									this->clear();
									dist = 0;
									tmp_it = first;
									for (; tmp_it != last; ++tmp_it)
										dist++;
									this->_size = dist;
									std::uninitialized_copy(first, last, this->_base);
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
									return (iterator(this->_base));
								}
 		const_iterator			begin() const 
								{
									return (const_iterator(this->_base));
								}
 		iterator				end()
								{
									pointer end;
									end = (&(this->_base[this->_size]));
									return (iterator(end));
								}
 		const_iterator			end() const 
								{
									pointer end;
									end = (&(this->_base[this->_size]));
									return (const_iterator(end));
								}
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
									if (new_cap > this->_capacity && new_cap < this->max_size())
									{
										vector		tmp(*this);

										this->clear();
										this->_alloc.desallocate(this->_base, this->_capacity);
										this->_capacity = new_cap;
										this->_alloc.allocate(this->_capacity);
										std::uninitialized_copy(tmp.begin(), tmp.end(), this->_base);
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
 		value_type* 			data()
								{
									return (this->begin());
								}
		const value_type* 		data() const
								{
									return (this->begin());
								}
 		reference 				at(size_type pos)
								{
									if (pos > this->size())
										throw std::out_of_range("pos out of range !");
									return (&(this->_bas + pos));
								}
 		reference 				operator[](size_type pos)
								{
									return (&(this->_bas + pos));
								}
 		reference 				front()
								{
									return (&(this->_base));
								}
 		reference 				back()
								{
									return (&(this->_base + this->_size));
								}
/**
*** 							Modifiers
**/
		void 					clear()
								{
									pointer tmp_ptr;

									tmp_ptr = this->_base;
									for (size_type i = 0; i < this->_size; i++)
										this->_alloc.destroy(tmp_ptr++);
									this->_size = 0;
								}
		void 					push_back(const T& value)
								{
									if (this->size() + 1 > this->capacity())
										this->reserve(this->capacity() * 2);
									this->_size += 1;
									this->_alloc.construct(++this->end(), value);
									
								}
		void 					pop_back()
								{
									this->_alloc.destroy(this->end());
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
									
								}
		iterator 				insert(const_iterator pos, size_type count, const T & value)
								{
									
								}
								template<class InputIt>
		iterator 				insert(const_iterator pos, InputIt first, InputIt last)
								{
									
								}
		iterator 				erase(iterator pos)
								{
									
								}
		iterator 				erase(iterator first, iterator last)
								{
									
								}

								template<class T, class Alloc>
		friend					bool operator==(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs) 
								{
									return (lhs._base == rhs._base && lhs._alloc == rhs._alloc && lhs._capacity == rhs._capacity && lhs._size == rhs._size);
								}
								template<class T, class Alloc>
		friend							bool operator!=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs)
								{
									return (lhs._base != rhs._base && lhs._alloc != rhs._alloc && lhs._capacity != rhs._capacity && lhs._size != rhs._size);
								}
								template<class T, class Alloc>
		friend							bool operator>(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs)
								{
									return (lhs._base > rhs._base && lhs._alloc > rhs._alloc && lhs._capacity > rhs._capacity && lhs._size > rhs._size);
								}
								template<class T, class Alloc>
		friend							bool operator<(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs)
								{
									return (lhs._base < rhs._base && lhs._alloc < rhs._alloc && lhs._capacity < rhs._capacity && lhs._size < rhs._size);
								}
								template<class T, class Alloc>
		friend							bool operator>=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs)
								{
									return (lhs._base >= rhs._base && lhs._alloc >= rhs._alloc && lhs._capacity >= rhs._capacity && lhs._size >= rhs._size);
								}
								template<class T, class Alloc>
		friend							bool operator<=(const vector<T,Alloc>& lhs,const vector<T,Alloc>& rhs)
								{
									return (lhs._base <= rhs._base && lhs._alloc <= rhs._alloc && lhs._capacity <= rhs._capacity && lhs._size <= rhs._size);
								}
	};
}



#endif