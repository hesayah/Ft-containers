/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:58 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/03 08:06:04 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "includes/pair.hpp"
# include "includes/enable_if.hpp"
# include "includes/is_integral.hpp"
# include "includes/equal.hpp"
# include "includes/lexicographical_compare.hpp"
# include "includes/reverse_iterator.hpp"
# include "includes/red_black_tree.hpp"

namespace ft {

    							template <class Key, class T, class compare = std::less<Key> , class Allocator = std::allocator<std::pair<const Key,T> > > 
    class 						map
	{
		public :
			typedef 			std::pair<const Key, T>											value_type;
			class 				value_compare 
				{
					protected	:
								compare 													comp;
								value_compare(compare c) : comp(c) {}
					public	:
						typedef bool														result_type;
						typedef value_type													first_argument_type;
						typedef value_type													second_argument_type;
						bool																operator() (const value_type& x, const value_type& y) const
																							{
																								return (comp(x.first, y.first));
																							}
				};
			typedef 			Key															key_type;
			typedef 			T															mapped_type;
			typedef 			compare														key_compare;
			typedef				Allocator													allocator_type;
			typedef	typename	allocator_type::reference									reference;
			typedef	typename	allocator_type::const_reference								const_reference;
			typedef	typename	allocator_type::pointer										pointer;
			typedef	typename	allocator_type::const_pointer								const_pointer;
			typedef	typename	iterator_traits<pointer>::difference_type					difference_type;
			typedef	typename	RedBlackTree<value_type, compare, Allocator>::iterator			iterator;
			typedef	typename	RedBlackTree<value_type, compare, Allocator>::const_iterator	const_iterator;
			typedef				size_t														size_type;
			typedef				RedBlackTree<value_type, compare, Allocator>				rbtree;
		protected :
								rbtree														_NodeBase;
								allocator_type												_alloc;
								key_compare													_comp;
								size_type													_size;
		private :

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
			public :
/** 
***								constructors
**/
			explicit			map() : _alloc(allocator_type()), _comp(key_compare()), _size(0) {}
			explicit 			map(const compare& comp, const Allocator& alloc = Allocator()) : _alloc(alloc), _comp(comp), _size(0) {}
								template <typename InputIt>
								map(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const compare& comp = compare(), const Allocator& alloc = Allocator()) : _alloc(alloc), _comp(comp), _size(0)
								{
									insert(first, last);
								}
								map(const map& other)
								{
									*this = other;
								}
			 					~map(void)
								{
								}
/**
***								Member functions 
**/
 		map	& 					operator=(const map& other)
								{
									_comp = other._comp;
									_size = other._size;
									_alloc = other._alloc;
									return (*this);
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
									return (this->_NodeBase.begin());
								}
 		const_iterator			begin() const
								{
									return (this->_NodeBase.begin());
								}
		iterator				end()
								{
									return (this->_NodeBase.end());
								}
		const_iterator			end() const 
								{
									return (this->_NodeBase.end());
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
									return (this->_size);
								}
 		size_type 				max_size() const 
								{
									return (_alloc.max_size());
								}
/**
*** Element access
**/

		reference 				operator[] (size_type n)
								{
									return (this->_NodeBase[n]);
								}
		const_reference 		operator[] (size_type n) const
								{
									return (this->_NodeBase[n]);
								}
		reference 				at(size_type n) 
								{
									this->_check_range_limit(n);
									return (this->_NodeBase[n]);
								}
		const_reference 		at (size_type n) const 
								{
									this->_check_range_limit(n);
									return (this->_NodeBase[n]);
								}
		void					printTree()
								{
									_NodeBase.printTree();
								}
/**
*** 							Modifiers
**/
							
		void					insert(const value_type& val)
		{
								_NodeBase.insert(val);
								_size++;
								//return (std::pair<iterator, bool>);
		}

								template <class InputIterator> 
		void 					insert (InputIterator first, InputIterator last)
								{
									for (; first != last; ++first)
										insert(*first);
								}
		/*void 					erase(iterator position);
		size_type				erase(const key_type& k);
		void					erase(iterator first, iterator last);*/
		void 					clear()
								{
									this->_NodeBase._clear();
								}
		//void 					swap(map	& other)
		//						{
		//						}
/**
*** 							Observe
**/
		key_compare 						key_comp() const {return _comp;}
		value_compare 						value_comp() const {return value_compare(_comp);};
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
	bool 		operator==(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return  (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator!=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(lhs == rhs));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator<(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator<=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(rhs < lhs));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator>(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (rhs < lhs);}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator>=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(lhs < rhs));}

				template<class Key, class T, class Compare, class Alloc>
	void		swap(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {lhs.swap(rhs);}
}

#endif