/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:58 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/11 19:50:16 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "includes/pair.hpp"
# include "includes/enable_if.hpp"
# include "includes/is_integral.hpp"
# include "includes/equal.hpp"
# include "includes/lexicographical_compare.hpp"
# include "includes/red_black_tree.hpp"

namespace ft {

    							template <class Key, class T, class Compare = std::less<Key> , class Allocator = std::allocator<pair<const Key,T> > > 
    class 						map
	{
		public :
			typedef 			Key															key_type;
			typedef 			T															mapped_type;
			typedef 			pair<const Key, T>											value_type;
			typedef 			Compare														key_compare;
			class 				value_compare 
				{
					friend class map;
					protected	:
								Compare 													comp;
								value_compare(Compare c) : comp(c) {}
					public	:
						typedef bool														result_type;
						typedef value_type													first_argument_type;
						typedef value_type													second_argument_type;
						bool																operator() (const value_type& x, const value_type& y) const
																							{
																								return (comp(x.first, y.first));
																							}
				};
			typedef				Allocator													allocator_type;
			typedef	typename	allocator_type::reference									reference;
			typedef	typename	allocator_type::const_reference								const_reference;
			typedef	typename	allocator_type::pointer										pointer;
			typedef	typename	allocator_type::const_pointer								const_pointer;
			typedef				RedBlackTree<value_type, value_compare, allocator_type>		rbtree;
			typedef	typename	rbtree::iterator											iterator;
			typedef	typename	rbtree::const_iterator										const_iterator;
			typedef	typename	rbtree::reverse_iterator									reverse_iterator;
			typedef typename	rbtree::const_reverse_iterator								const_reverse_iterator;
			typedef	typename	rbtree::size_type											size_type;
			typedef	typename	rbtree::difference_type										difference_type;

		protected :
								rbtree														_NodeBase;
		private :

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
			explicit 			map(const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc) {}
								template <typename InputIt>
								map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc)
								{
									for (; first != last;first++)
										this->insert(*first);
								}
								map(const map& other)
								{

									_NodeBase = other._NodeBase;
								}
			 					~map(void)
								{
								}
/**
***								Member functions 
**/
 		map	& 					operator=(const map& other)
								{
									if (*this == other)
										return *this;
									_NodeBase = other._NodeBase;
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
 		size_type 				size() const 
								{
									return (_NodeBase._size);
								}
 		size_type 				max_size() const 
								{
									return (_NodeBase._alloc.max_size());
								}
/**
*** Element access
**/

		T& 				operator[] (const Key & key) const
								{
									value_type new_pair = ft::make_pair(key, mapped_type());
					iterator f = _NodeBase.searchTree(new_pair);
					if (f == this->end())
						return (_NodeBase.insert(new_pair))->second;
					return f->second;
								}
		T& 				at(const Key & key) const
								{
																		value_type new_pair = ft::make_pair(key, mapped_type());
					iterator f = _NodeBase.searchTree(new_pair);
					if (f == this->end())
						return (_NodeBase.insert(new_pair))->second;
					return f->second;
									/*value_type pr = ft::make_pair(key, mapped_type());
									iterator it = _NodeBase.searchTree(pr);
									if (it == end())
										throw std::out_of_range("pos out of range !");
									return (it->second);*/
								}
		void					printTree()
								{
									_NodeBase.printTree();
								}
/**
*** 							Modifiers
**/
							
		pair<iterator,bool>		insert(const value_type& val)
		{
								iterator it = _NodeBase.searchTree(val);
								//std::cout << &(*it) << " " << &(*end()) << std::endl;
								if (it == this->end())
									return (ft::make_pair(_NodeBase.insert(val), true));
								return (ft::make_pair(it, false));
		}
		iterator 				insert(iterator pos, const value_type& val)
		{
								insert(val);
								return (pos);
		}
								template <class InputIt> 
		void 					insert (InputIt first,InputIt last)
								{
									for (; first != last; ++first)
										_NodeBase.insert(*first);
								}
		void 					erase(iterator position)
								{
									_NodeBase.deleteNode(*position);
								}
		size_type				erase(const key_type& k)
								{
									iterator it = find(k);

									if (it == end())
										return (0);
									_NodeBase.deleteNode(it);
									return (1);
								}
		void					erase(iterator first, iterator last)
								{
									for (;first != last; first++)
										erase(first);
								}
		void 					clear()
								{
									this->_NodeBase.clear(_NodeBase._root);
								}
		void 					swap(map & other)
								{
									_NodeBase.swap(other._NodeBase);
								}
/**
*** 							Observe
**/
		key_compare 						key_comp() const {return (key_compare());}
		value_compare 						value_comp() const {return (value_compare());};
/**
*** 							Operations
**/
    	iterator							find(const key_type& k)
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return _NodeBase.searchTree(searched_pair);

											}
		const_iterator						find (const key_type& k) const
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return _NodeBase.searchTree(searched_pair);
											}
		size_type							count(const key_type& k) const
											{
												(void)k;
												return (1);
											}
		iterator							lower_bound(const key_type& k)
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return (this->_NodeBase.lower_bound(searched_pair));
											}
		const_iterator 						lower_bound(const key_type& k) const
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return (this->_NodeBase.lower_bound(searched_pair));
											}
		iterator							upper_bound(const key_type& k)
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return (this->_NodeBase.upper_bound(searched_pair));
											}
		const_iterator 						upper_bound (const key_type& k) const
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return (this->_NodeBase.upper_bound(searched_pair));
											}
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const
											{
												return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
											}
		pair<iterator,iterator>             equal_range(const key_type& k)
											{
												return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
											}
	};
				template<class Key, class T, class Compare, class Alloc>
	bool 		operator==(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return  (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator!=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(lhs == rhs));}

				template<class Key, class T, class Compare, class Alloc>
	bool 		operator<(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

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