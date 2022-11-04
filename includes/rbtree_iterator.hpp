/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:26:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/30 02:13:25 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BIDIR_ITERATOR__
# define __BIDIR_ITERATOR__

# include "iterator_traits.hpp"

namespace ft {
									template <typename T, typename Node>
	class							rbt_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public	:
			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::difference_type						difference_type;
			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::value_type							value_type;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::pointer								pointer;
   			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::reference							reference;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::iterator_category					iterator_category;
			typedef					Node*																					NodePtr;
    	protected	:
      								NodePtr												_base;
									NodePtr												_root;
									NodePtr												_TNULL;

			NodePtr 				minimum(NodePtr node) 
  									{
    									while (node->left != _TNULL)
      										node = node->left;
    									return node;
									}
 			NodePtr 				maximum(NodePtr node) 
  									{
										while (node->right != _TNULL)
											node = node->right;
										return node;
									}
			NodePtr					successor(NodePtr x)
									{
										if (x->right != _TNULL) 
											return minimum(x->right);
										NodePtr y = x->parent;
										while (y != _TNULL && x == y->right) 
										{
											x = y;
											y = y->parent;
										}
										return y;
									}
			NodePtr					predecessor(NodePtr x)
									{
										if (x->left != _TNULL) 
											return maximum(x->left);
										NodePtr y = x->parent;
										while (y != _TNULL && x == y->left)
										{
											x = y;
											y = y->parent;
										}
   										return y;
									}
		public	:
									rbt_iterator() : _base(NULL), _root(NULL), _TNULL(NULL) {}
									rbt_iterator(const NodePtr & base, const NodePtr & TNULL, const NodePtr & root) : _base(base),  _root(root), _TNULL(TNULL){}
									rbt_iterator(const rbt_iterator<const T, Node> & other) : _base(other._base), _root(other._root), _TNULL(other._TNULL) {}
									~rbt_iterator() {}
  			operator 				rbt_iterator<const value_type, Node>() const {return rbt_iterator<const value_type, Node>(_base, _root, _TNULL);}
			rbt_iterator<T, Node> &	operator=(const rbt_iterator & other) 
									{
										_base = other._base;
										_TNULL = other._TNULL;
										_root = other._root;
										return (*this);
									}
			reference 				operator*()  {return (&(this->_base)->data);}
			pointer 				operator->() const {return (&(this->_base)->data);}
			reference				operator[](difference_type diff) const {return (*(this->_base + diff));}
			rbt_iterator 			operator++(int) {return (*(this)++);}
			rbt_iterator 			operator--(int) {return (*(this)--);}								
			rbt_iterator	& 		operator--(void) 
									{
										predecessor(_base);
										return (*this);
									}
			rbt_iterator	& 		operator++(void)
									{
										successor(_base);
										return (*this);
									}
			rbt_iterator			operator+(difference_type diff) const {return (_base + diff);}
			rbt_iterator 			operator-(difference_type diff) const {return (_base - diff);}
			rbt_iterator	& 		operator+=(difference_type diff) 
									{
										this->_base = _base + diff;
										return (*this);
									}
			rbt_iterator	& 		operator-=(difference_type diff)
									{
										this->_base = _base - diff;
										return (*this);
									}
	friend	rbt_iterator<T, Node>	operator+(difference_type diff, rbt_iterator<T, Node> x) {return (x += diff);}
	friend	rbt_iterator<T, Node>	operator-(difference_type diff, rbt_iterator<T, Node> x) {return (x -= diff);}
	friend	difference_type			operator+(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base + rhs._base);}
	friend	difference_type			operator-(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base - rhs._base);}
	friend	bool					operator==(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base == rhs._base);}
	friend	bool					operator!=(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base != rhs._base);}
	friend	bool					operator<(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base < rhs._base);}
	friend	bool					operator<=(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base <= rhs._base);}
	friend	bool					operator>(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base > rhs._base);}
	friend	bool					operator>=(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base >= rhs._base);}
	};
}

#endif