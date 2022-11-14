/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:58 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/14 18:19:40 by hesayah          ###   ########.fr       */
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
    class 									map
	{			
		public :			
			typedef 						Key															key_type;
			typedef 						T															mapped_type;
			typedef 						pair<const Key, T>											value_type;
			typedef 						Compare														key_compare;
			class 							value_compare 
				{			
					friend class			map;
					friend class			Redblacktree;
					protected	:
											Compare 													comp;
											value_compare(Compare c) : comp(c) {}
					public	:			
						typedef 			bool														result_type;
						typedef 			value_type													first_argument_type;
						typedef 			value_type													second_argument_type;
						bool																			operator() (const value_type& x, const value_type& y) const
																										{
																											return (comp(x.first, y.first));
																										}
				};
			typedef							Allocator													allocator_type;
			typedef	typename				allocator_type::reference									reference;
			typedef	typename				allocator_type::const_reference								const_reference;
			typedef	typename				allocator_type::pointer										pointer;
			typedef	typename				allocator_type::const_pointer								const_pointer;
			typedef							RedBlackTree<value_type, value_compare, allocator_type>		rbtree;
			typedef	typename				rbtree::iterator											iterator;
			typedef	typename				rbtree::const_iterator										const_iterator;
			typedef	typename				rbtree::reverse_iterator									reverse_iterator;
			typedef typename				rbtree::const_reverse_iterator								const_reverse_iterator;
			typedef	typename				rbtree::size_type											size_type;
			typedef	typename				rbtree::difference_type										difference_type;

		protected :			
											rbtree														_NodeBase;
											key_compare													_kc;

			public :	
/** 	
***								construc	tors
**/			
			explicit 						map(const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc) {}
											template <typename InputIt>
											map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc)
											{
													this->insert(first, last);
											}
											map(const map& other) : _NodeBase(other._NodeBase._cmp, Allocator())
											{
												insert(other.begin(), other.end());
											}
			 								~map()
											{
											}
/**			
***											Member functions 
**/			
 		map	& 								operator=(const map& x)
											{
												if (!this->empty())
													this->clear();
												this->_kc = x.key_comp();
												const_iterator pos = x.begin();
												while (pos != x.end())
													this->insert(*pos++);
												return *this;
											}							
 		allocator_type 						get_allocator() const
											{
												return (_NodeBase._alloc);
											}
/**			
*** 										Iterators
**/			
 		iterator							begin()
											{
												return (this->_NodeBase.begin());
											}
 		const_iterator						begin() const
											{
												return (this->_NodeBase.begin());
											}
		iterator							end()
											{
												return (this->_NodeBase.end());
											}
		const_iterator						end() const 
											{
												return (this->_NodeBase.end());
											}
		reverse_iterator					rbegin()
											{
												return (reverse_iterator(end()));
											}
		const_reverse_iterator				rbegin() const 
											{
												return (const_reverse_iterator(end()));
											}
		reverse_iterator					rend()
											{
												return (reverse_iterator(begin()));
											}
 		const_reverse_iterator				rend() const
											{
												return (const_reverse_iterator(begin()));
											}
 		bool 								empty() const
											{
												return (begin() == end());
											}
 		size_type 							size() const 
											{
												return (_NodeBase._size);
											}
 		size_type 							max_size() const 
											{
												return (_NodeBase._alloc.max_size());
											}
/**		
*** Element access			
**/			
		T& 									operator[] (const Key & key) 
											{
												value_type pr = ft::make_pair(key, mapped_type());
												iterator it = _NodeBase.find(pr);
												if (it == end())
													return ((_NodeBase.insert(pr))->second);
												return (it->second);
											}
		T& 									at(const Key & key) const
											{
												value_type pr = ft::make_pair(key, mapped_type());
												iterator it = _NodeBase.find(pr);
												if (it == end())
													throw std::out_of_range("pos out of range !");
												return (it->second);
											}
		void								printTree()
											{
												_NodeBase.printTree();
											}
/**			
*** 										Modifiers
**/
		pair<iterator,bool>					insert(const value_type& val)
		{			
											iterator it = _NodeBase.find(val);
											if (it == this->end())
												return (ft::make_pair(_NodeBase.insert(val), true));
											return (ft::make_pair(it, false));
		}			
		iterator 							insert(iterator pos, const value_type& val)
		{			
											(void)pos;
											return (insert(val)).first;
		}			
											template <class InputIt>
		void 								insert (InputIt first,InputIt last)
											{
												for (; first != last;)
													insert(*first++);
											}
		void 								erase(iterator position)
											{
												_NodeBase.erase(*position);
											}
		size_type							erase(const key_type& k)
											{
												iterator it = find(k);

												if (it == end())
													return (0);
												erase(it);
												return (1);
											}
		void								erase(iterator first, iterator last)
											{
												for (;first != last;)
													erase(first++);
											}
		void 								clear()
											{
												this->_NodeBase.clear();
											}
		void 								swap(map & other)
											{
												_NodeBase.swap(other._NodeBase);
											}
/**
*** 							Observe
**/
		key_compare 						key_comp() const {return (_kc);}
		value_compare 						value_comp() const {return (_NodeBase._cmp);};
/**
*** 							Operations
**/
    	iterator							find(const key_type& k)
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return _NodeBase.find(searched_pair);

											}
		const_iterator						find (const key_type& k) const
											{
												value_type searched_pair = ft::make_pair(k, mapped_type());
												return _NodeBase.find(searched_pair);
											}
		size_type							count(const key_type& k) const
											{
												if (this->find(k) == this->end())
													return (0);
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
		bool 								operator==(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return  (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}
							
											template<class Key, class T, class Compare, class Alloc>
		bool 								operator!=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(lhs == rhs));}
							
											template<class Key, class T, class Compare, class Alloc>
		bool 								operator<(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
							
											template<class Key, class T, class Compare, class Alloc>
		bool 								operator<=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(rhs < lhs));}
							
											template<class Key, class T, class Compare, class Alloc>
		bool 								operator>(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (rhs < lhs);}
							
											template<class Key, class T, class Compare, class Alloc>
		bool 								operator>=(const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs) {return (!(lhs < rhs));}
							
											template<class Key, class T, class Compare, class Alloc>
		void								swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs) {lhs.swap(rhs);}
}

#endif