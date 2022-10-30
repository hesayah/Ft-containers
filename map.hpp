/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:58 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/30 02:59:12 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "includes/pair.hpp"
# include "includes/reverse_iterator.hpp"
# include "includes/red_black_tree.hpp"

namespace ft {

    							template <class key, class T, class compare = std::less<key> , class alloc = std::allocator<pair<const key,T> > > 
    class 						map
	{
		public :
			typedef 			std::pair<const key, T>										value_type;
			class 				value_compare 
				{
					protected	:
								compare 													_c;
								value_compare(compare c) : _c(c) {}
					public	:
						typedef bool														result_type;
						typedef value_type													first_argument_type;
						typedef value_type													second_argument_type;
						bool																operator() (const value_type& x, const value_type& y) const
																							{
																								return _c(x.first, y.first);
																							}
				};
			typedef 			key															key_type;
			typedef 			T															mapped_type;
			typedef 			compare														key_compare;
			typedef				alloc														allocator_type;
			typedef	typename	allocator_type::reference									reference;
			typedef	typename	allocator_type::const_reference								const_reference;
			typedef	typename	allocator_type::pointer										pointer;
			typedef	typename	allocator_type::const_pointer								const_pointer;
			typedef	typename	iterator_traits<pointer>::difference_type					difference_type;
			typedef	typename	RedBlackTree<value_type, compare, alloc>::iterator			iterator;
			typedef	typename	RedBlackTree<value_type, compare, alloc>::const_iterator	const_iterator;
			typedef				size_t														size_type;
			typedef				RedBlackTree<value_type, compare, alloc>					rbtree;
		protected :
								rbtree														_base;
		private :

		/*	void				_check_storage_limit(size_type new_cap) const
								{
									if (new_cap > this->max_size())
										throw std::length_error("map::reserve");
								}
		*/
			void				_check_range_limit(size_type pos) const
								{
									if (pos >= this->_size)
										throw std::out_of_range("pos out of range !");
								}

		/*						template <typename InputIt>
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
		*/
			public :
/** 
***								constructors
**/
			explicit			map() {}
			/*explicit 			map(size_type count, const_reference value = value_type(), const Allocator& alloc = allocator_type()) :  _alloc(alloc),_size(0) , _base(NULL)
								{
									this->assign(count, value);
								}
								template <typename InputIt>
								map(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = allocator_type()) : _alloc(alloc), _size(0) , _base(NULL)
								{
									assign(first, last);
								}
								map(const map& other) : _alloc(other._alloc), _capacity(0), _size(0) , _base(NULL)
								{
									*this = other;
								}*/
			 					~map(void)
								{
									/*this->clear();
									this->_deallocate();*/
								}
/**
***								Member functions 
**/
 		/*map	& 					operator=(const map& other)
								{

								}							*/	
 		allocator_type 			get_allocator() const
								{
									return (this->_base._alloc);
								}
/**
*** 							Iterators
**/
 		iterator				begin()
								{
									return (this->_base._TNULL);
								}
 		const_iterator			begin() const
								{
									return (this->_base._TNULL);
								}
		iterator				end()
								{
									return (this->_base._TNULL + this->_base._size);
								}
		const_iterator			end() const 
								{
									return (this->_base._TNULL + this->_base._size);
								}
		/*reverse_iterator		rbegin()
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
								}*/
 		bool 					empty() const
								{
									//return (begin() == end());
								}
 		size_type 				size() const 
								{
									return (this->_base._size);
								}
 		size_type 				max_size() const 
								{
									return (_base._alloc.max_size());
								}
/**
*** Element access
**/

		/*reference 				operator[] (size_type n)
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
								}*/
		void					printTree()
								{
									_base.printTree();
								}
/**
*** 							Modifiers
**/
							
		void					insert(const value_type & val)
		{
								_base.insert(val);			
		}

		/*iterator 				insert(iterator position, const value_type& val);
								template <class InputIterator> 
		void 					insert (InputIterator first, InputIterator last);
		void 					erase(iterator position);
		size_type				erase(const key_type& k);
		void					erase(iterator first, iterator last);*/
		void 					clear()
								{
									//this->_base._clear();
								}
		//void 					swap(map	& other)
		//						{
		//						}
		/*iterator 				erase(iterator pos)
								{
									pointer tmp = pos;

									for (;tmp != this->_base + _size - 1; tmp++)
										*tmp = *(tmp + 1);
									resize(this->_size - 1);
									return (pos);
								}
		iterator 				erase(iterator first, iterator last)
								{
									map tmp(begin(), first);
									map tmp_two(last, end());
									difference_type new_size = _size - _distance(first, last);
									resize(new_size);
									size_type i = 0;
									for (; i < tmp.size(); i++)
										*(_base + i) = *(tmp.begin() + i);
									for (size_type j = 0 ; j < tmp_two.size(); j++)
										*(_base + i + j) = *(tmp_two.begin() + j);
									return (first);
								}*/
/**
*** 							Observe
**/
		key_compare 						key_comp() const;
		value_compare 						value_comp() const;
/**
*** 							Operations
**/
    	iterator							find(const key_type& k);
		const_iterator						find (const key_type& k) const;
		size_type							count(const key_type& k) const;
		iterator							lower_bound(const key_type& k);
		const_iterator 						lower_bound (const key_type& k) const;
		iterator							upper_bound(const key_type& k);
		const_iterator 						upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
		pair<iterator,iterator>             equal_range(const key_type& k);
	};

											template<class Key, class T, class Compare, class Alloc>
	bool									operator==(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);

											template< class Key, class T, class Compare, class Alloc >
	bool 									operator!=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);

											template< class Key, class T, class Compare, class Alloc >
	bool									operator<(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);

											template< class Key, class T, class Compare, class Alloc >
	bool									operator<=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);

											template< class Key, class T, class Compare, class Alloc >
	bool									operator>(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);

											template< class Key, class T, class Compare, class Alloc >
	bool 									operator>=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs);
}

#endif