/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:10:58 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/15 00:43:08 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SET_HPP__
# define __SET_HPP__

# include "includes/pair.hpp"
# include "includes/enable_if.hpp"
# include "includes/is_integral.hpp"
# include "includes/equal.hpp"
# include "includes/lexicographical_compare.hpp"
# include "includes/red_black_tree.hpp"

namespace ft {
											template<class T, class Compare = std::less<T>,	class Allocator = std::allocator<T> >
    class 									set
	{			
		public :			
			typedef 						T															key_type;
			typedef 						T															value_type;
			typedef 						Compare														key_compare;
			typedef							Compare														value_compare;
			typedef							Allocator													allocator_type;
			typedef	typename				allocator_type::reference									reference;
			typedef	typename				allocator_type::const_reference								const_reference;
			typedef	typename				allocator_type::pointer										pointer;
			typedef	typename				allocator_type::const_pointer								const_pointer;
			typedef							RedBlackTree<const T, key_compare, allocator_type>				rbtree;
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
			explicit 						set(const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc) {}
											template <typename InputIt>
											set(InputIt first, InputIt last, const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) : _NodeBase(comp, alloc)
											{
													this->insert(first, last);
											}
											set(const set& other) : _NodeBase(other._NodeBase.cmp(), Allocator())
											{
												insert(other.begin(), other.end());
											}
			 								~set()
											{
											}
/**			
***											Member functions 
**/			
 		set	& 								operator=(const set& other)
											{
												if (!this->empty())
													this->clear();
												this->_kc = other.key_comp();
												this->insert(other.begin(), other.end());
												return (*this);
											}							
 		allocator_type 						get_allocator() const
											{
												return (_NodeBase.get_alloc());
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
												return (_NodeBase.size());
											}
 		size_type 							max_size() const 
											{
												return (_NodeBase.get_alloc().max_size());
											}
/**		
*** Element access			
**/			
		T& 									operator[] (const T & key) 
											{
												value_type pr = ft::make_pair(key, value_type());
												iterator it = _NodeBase.find(pr);
												if (it == end())
													return ((_NodeBase.insert(pr))->second);
												return (it->second);
											}
		T& 									at(const T & key) const
											{
												value_type pr = ft::make_pair(key, value_type());
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
		void 								swap(set & other)
											{
												_NodeBase.swap(other._NodeBase);
											}
/**
*** 							Observe
**/
		key_compare 						key_comp() const {return (_kc);}
		value_compare 						value_comp() const {return (_NodeBase.cmp());};
/**
*** 							Operations
**/
    	iterator							find(const key_type& k)
											{
												return (_NodeBase.find(k));

											}
		const_iterator						find (const key_type& k) const
											{
												return (_NodeBase.find(k));
											}
		size_type							count(const key_type& k) const
											{
												if (this->find(k) == this->end())
													return (0);
												return (1);
											}
		iterator							lower_bound(const key_type& k)
											{
												return (this->_NodeBase.lower_bound(k));
											}
		const_iterator 						lower_bound(const key_type& k) const
											{
												return (this->_NodeBase.lower_bound(k));
											}
		iterator							upper_bound(const key_type& k)
											{
												return (this->_NodeBase.upper_bound(k));
											}
		const_iterator 						upper_bound (const key_type& k) const
											{
												return (this->_NodeBase.upper_bound(k));
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
											template<class T, class Compare, class Alloc>
		bool 								operator==(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return  (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}
							
											template<class T, class Compare, class Alloc>
		bool 								operator!=(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return (!(lhs == rhs));}
							
											template<class T, class Compare, class Alloc>
		bool 								operator<(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
							
											template<class T, class Compare, class Alloc>
		bool 								operator<=(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return (!(rhs < lhs));}
							
											template<class T, class Compare, class Alloc>
		bool 								operator>(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return (rhs < lhs);}
							
											template<class T, class Compare, class Alloc>
		bool 								operator>=(const set<T,Compare,Alloc>& lhs,const set<T,Compare,Alloc>& rhs) {return (!(lhs < rhs));}
							
											template<class T, class Compare, class Alloc>
		void								swap(set<T,Compare,Alloc>& lhs, set<T,Compare,Alloc>& rhs) {lhs.swap(rhs);}
}

#endif