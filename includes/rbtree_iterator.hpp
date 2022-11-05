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
    									return (node);
									}
 			NodePtr 				maximum(NodePtr node) 
  									{
										while (node->right != _TNULL)
											node = node->right;
										return (node);
									}
			NodePtr					successor(NodePtr x)
									{
										if (x ==_TNULL)
											return x;
										if (x->right !=_TNULL) 
										{
											x = minimum(x->right);
											return x;
										}
										NodePtr y = x->parent;
										while (y !=_TNULL && y != NULL && x == y->right) {
											x = y;
											y = y->parent;
										}
										if (y == NULL)
											x =_TNULL;
										else
											x = y;
										return x;
									}
			NodePtr					predecessor(NodePtr x)
									{
										if (x ==_TNULL)
										{
											x = maximum(_root);
											return x;
										}
										if (x->left !=_TNULL) {
											x = maximum(x->left);
											return x;
										}

										NodePtr y = x->parent;
										while (y !=_TNULL && y != NULL && x == y->left) {
											x = y;
											y = y->parent;
										}
										if (y == NULL)
											x =_TNULL;
										else
											x = y;
										return x;
									}
		public	:
									rbt_iterator() : _base(NULL), _root(NULL),_TNULL(NULL) {}
									rbt_iterator(const rbt_iterator<T, Node> & src) : _base(src._base), _root(src._root),_TNULL(src._TNULL) {}
									rbt_iterator(const NodePtr node, const NodePtr root, const  NodePtr nil) : _base(node), _root(root),_TNULL(nil) {}
									~rbt_iterator(){}
		rbt_iterator&				operator=(rbt_iterator const & src)
									{
										if (this != &src)
										{
											this->_base = src._base;
											this->_root = src._root;
											this->_TNULL = src._TNULL;
										}
										return *this;
									}
		operator    				rbt_iterator<value_type const, Node const>() const
        							{
            							return rbt_iterator<value_type const, Node const>(_base, _root,_TNULL);
       								}
		reference 					operator* ()const {return (this->_base->data);}
		pointer 					operator-> () const {return (&(this->_base->data));}
		rbt_iterator 				operator++(int) {rbt_iterator tmp(*this); _base = successor(_base); return (tmp);}
		rbt_iterator 				operator--(int) {rbt_iterator tmp(*this); _base = predecessor(_base); return (tmp);}							
		rbt_iterator	& 			operator--(void) 
									{
										_base = predecessor(_base);
										return (*this);
									}
		rbt_iterator	& 			operator++(void)
									{
										_base = successor(_base);
										return (*this);
									}
	friend	rbt_iterator<T, Node>	operator+(difference_type diff, rbt_iterator<T, Node> x) {return (x += diff);}
	friend	rbt_iterator<T, Node>	operator-(difference_type diff, rbt_iterator<T, Node> x) {return (x -= diff);}
	friend	difference_type			operator+(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base + rhs._base);}
	friend	difference_type			operator-(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base - rhs._base);}
	friend	bool 					operator==(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base == rhs._base);}
	friend	bool 					operator!=(const rbt_iterator<T, Node>& lhs, const rbt_iterator<T, Node>& rhs) {return (lhs._base != rhs._base);}
	};
}

#endif