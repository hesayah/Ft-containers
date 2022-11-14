/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:55:53 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/14 18:47:47 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

/**
*** https://www.geeksforgeeks.org/red-black-tree-set-true-introduction-2/
*** https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
*** https://www.programiz.com/dsa/red-black-tree
**/

# include <iostream>
# include <memory>
# include <functional>
# include "rbtree_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft {

		enum Color {BLACK, RED};

		template<class T>
		struct Node
		{
  			T 																	data;
  			Node 																*parent;
  			Node 																*left;
  			Node 																*right;
  			int 																color;
			Node(const T & other) : data(other){}
		};

		template <class T, class compare, class alloc>
		class RedBlackTree 
		{
			public :
				typedef 			T								 			value_type;
				typedef 			compare										key_compare;
				typedef typename 	alloc::template rebind<Node<T> >::other		allocator_type;
				typedef				size_t										size_type;
				typedef				Node<value_type>							Nd;
				typedef 			Nd* 										NodePtr;
				typedef				rbt_iterator<value_type, Nd>				iterator;
				typedef				rbt_iterator<const value_type,const Nd>		const_iterator;
				typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
				typedef 			ft::reverse_iterator<iterator>					reverse_iterator;
				typedef typename	iterator_traits<iterator>::difference_type	difference_type;

    	/*protected :*/
									key_compare									_cmp;
									allocator_type								_alloc;
									size_type									_size;
  									NodePtr										_root;
  									NodePtr 									_TNULL;

		NodePtr						minimum(NodePtr node) const
  									{
										while (node && node->left != _TNULL)
											node = node->left;
										if (node)
											return node;
										else
											return _TNULL;
									}
 		NodePtr	 					maximum(NodePtr node) const
  									{
										while (node && node->right != _TNULL) 
											node = node->right;

										if (node)
											return node;
										else
											return _TNULL;
									}
		NodePtr 					searchTreeHelper(NodePtr node, const value_type& key) const
									{
										if (node == _TNULL || isEqual(key, node->data))
											return node;
										if (_cmp(key ,node->data))
											return searchTreeHelper(node->left, key);
										return searchTreeHelper(node->right, key);
									}
		bool						isEqual(value_type const & x, value_type const & y) const
		{
										return (!_cmp(x, y) && !_cmp(y, x));
		}
		void 						deleteFix(NodePtr x)
									{
										NodePtr s;
										while (x != _root && x->color == 0)
										{
											if (x == x->parent->left)
											{
												s = x->parent->right;
												if (s->color == 1)
												{
													s->color = 0;
													x->parent->color = 1;
													leftRotate(x->parent);
													s = x->parent->right;
												}
												if (s->left->color == 0 && s->right->color == 0)
												{
													s->color = 1;
													x = x->parent;
												} 
												else
												{
													if (s->right->color == 0)
													{
            											s->left->color = 0;
														s->color = 1;
														rightRotate(s);
														s = x->parent->right;
													}
													s->color = x->parent->color;
													x->parent->color = 0;
													s->right->color = 0;
													leftRotate(x->parent);
													x = _root;
												}
											}
											else
											{
												s = x->parent->left;
												if (s->color == 1)
												{
													s->color = 0;
													x->parent->color = 1;
													rightRotate(x->parent);
													s = x->parent->left;
												}
												if (s->right->color == 0 && s->right->color == 0)
												{
													s->color = 1;
													x = x->parent;
												}
												else
												{
													if (s->left->color == 0)
													{
														s->right->color = 0;
														s->color = 1;
														leftRotate(s);
														s = x->parent->left;
													}
													s->color = x->parent->color;
													x->parent->color = 0;
													s->left->color = 0;
													rightRotate(x->parent);
          											x = _root;
        										}
											}
    									}
										x->color = 0;
									}
		void						deleteNodeHelper(NodePtr node, value_type & key)
									{
    									NodePtr z = _TNULL;
    									NodePtr x, y;
    									while (node != _TNULL)
										{
											if (this->isEqual(node->data, key))
												z = node;
											if (_cmp(node->data, key) || this->isEqual(node->data, key))
												node = node->right;
											else
												node = node->left;
										}
										if (z == _TNULL)
											return;
										y = z;
										int y_original_color = y->color;
										if (z->left == _TNULL)
										{
											x = z->right;
											rbTransplant(z, z->right);
										}
										else if (z->right == _TNULL)
										{
											x = z->left;
											rbTransplant(z, z->left);
										}
										else
										{
											y = minimum(z->right);
											y_original_color = y->color;
											x = y->right;
											if (y->parent == z) 
												x->parent = y;
											else
											{
												rbTransplant(y, y->right);
												y->right = z->right;
												y->right->parent = y;
											}
											rbTransplant(z, y);
											y->left = z->left;
											y->left->parent = y;
											y->color = z->color;
										}
										_alloc.destroy(z);
										_alloc.deallocate(z, 1);
										if (y_original_color == false)
											deleteFix(x);
										_size--;
									}
		void 						rbTransplant(NodePtr u, NodePtr v)
									{
										if (u->parent == NULL)
											_root = v;
										else if (u == u->parent->left)
											u->parent->left = v;
										else
											u->parent->right = v;
										v->parent = u->parent;
									}
		void						leftRotate(NodePtr x) 
 									{
										NodePtr y = x->right;
										x->right = y->left;
										if (y->left != _TNULL)
										  y->left->parent = x;
										y->parent = x->parent;
										if (x->parent == NULL)
										  this->_root = y;
										else if (x == x->parent->left)
										  x->parent->left = y;
										else
										  x->parent->right = y;
										y->left = x;
										x->parent = y;
 									}
		void						rightRotate(NodePtr x)
									{
									    NodePtr y = x->left;
									    x->left = y->right;
									    if (y->right != _TNULL)
									      y->right->parent = x;
									    y->parent = x->parent;
									    if (x->parent == NULL)
									      this->_root = y;
									    else if (x == x->parent->right)
									      x->parent->right = y;
									    else
									      x->parent->left = y;
									    y->right = x;
									    x->parent = y;
									}
		void						insertFix(NodePtr k)
									{
								    	NodePtr u;
								    	while (k->parent->color == 1)
										{
								    	  if (k->parent == k->parent->parent->right)
										  {
								    	    	u = k->parent->parent->left;
								    	    	if (u->color == 1)
												{
								    	    	  u->color = 0;
								    	    	  k->parent->color = 0;
								    	    	  k->parent->parent->color = 1;
								    	    	  k = k->parent->parent;
								    	    	}
												else
												{
								    	    	  if (k == k->parent->left)
												  {
								    	    	    k = k->parent;
								    	    	    rightRotate(k);
								    	    	  }
								    	    	  k->parent->color = 0;
								    	    	  k->parent->parent->color = 1;
								    	    	  leftRotate(k->parent->parent);
								    	    	}
								    		} 
											else
											{
								    	    	u = k->parent->parent->right;
								    	    	if (u->color == 1)
												{
								    	    	  u->color = 0;
								    	    	  k->parent->color = 0;
								    	    	  k->parent->parent->color = 1;
								    	    	  k = k->parent->parent;
								    	    	}
												else
												{
								    	    	  if (k == k->parent->right)
												  {
								    	    	    k = k->parent;
								    	    	    leftRotate(k);
								    	    	  }
								    	    	  k->parent->color = 0;
								    	    	  k->parent->parent->color = 1;
								    	    	  rightRotate(k->parent->parent);
								    	    	}
								    	  	}
								    	  	if (k == _root)
								    			break;
								    	}
								    	_root->color = 0;
								 	}
		void						clear(NodePtr _root)
									{
										if (_root != _TNULL) 
										{
										  	clear(_root->left);
									 		clear(_root->right);
									 	 	_alloc.destroy(_root);
											_alloc.deallocate(_root, 1);
										}
									}
		void						clear()
									{
										clear(_root);
										_size = 0;
										_root = _TNULL;
									}
		NodePtr						new_node(const value_type & key)
									{
										NodePtr node = _alloc.allocate(1);
										_alloc.construct(node, key);
									    node->parent = NULL;
									    node->left = _TNULL;
									    node->right = _TNULL;
									    node->color = 1;
										return node;
									}
   public:		
									RedBlackTree(compare c = key_compare(), allocator_type alloca = allocator_type()) : _cmp(c), _alloc(alloca), _size(0) 
									{
									  _TNULL = _alloc.allocate(1);
									  _TNULL->color = 0;
									  _TNULL->left = NULL;
									  _TNULL->right = NULL;
									  _root = _TNULL;
									}
									~RedBlackTree() 
									{
										clear();
										//_alloc.destroy(_TNULL);
										_alloc.deallocate(_TNULL, 1);
										_size = 0;
									}
		iterator					insert(const value_type & key)
									{
									   	NodePtr node = _alloc.allocate(1);
										_alloc.construct(node, key);
									    node->parent = NULL;
									    node->left = _TNULL;
									    node->right = _TNULL;
									    node->color = 1;

									    NodePtr y = NULL;
									    NodePtr x = this->_root;

									    while (x != _TNULL)
										{
									    	y = x;
									    	if (_cmp(node->data, x->data))
									        	x = x->left;
									    	else
									        	x = x->right;
									    }
									    node->parent = y;
									    if (y == NULL)
									      _root = node;
									    else if (_cmp(node->data, y->data))
									      y->left = node;
									    else
									      y->right = node;
										_size++;
									    if (node->parent == NULL)
										{
									    	node->color = 0;
									    	return iterator(node, _root, _TNULL);
									    }
									    else if (node->parent->parent == NULL)
									    	return iterator(node, _root, _TNULL);
									    insertFix(node);
										return iterator(node, _root, _TNULL);
									}
		void						erase(value_type & data)
									{
										deleteNodeHelper(this->_root, data);
									}
		iterator					begin()
									{ 
										return iterator(minimum(this->_root), this->_root, this->_TNULL);
									}
 		const_iterator				begin() const
									{
										return const_iterator(minimum(this->_root), this->_root, this->_TNULL);
									}
		iterator					end()
									{
										return iterator(_TNULL, this->_root, this->_TNULL);
									}
		const_iterator				end() const 
									{
										return const_iterator(_TNULL, this->_root, this->_TNULL);
									}
		iterator					lower_bound(const value_type & pair)
									{
										iterator it = this->begin();
										while (it != this->end())
										{
											if (!_cmp(*it, pair))
												return it;
											it++;
										}
										return (it);
									}
		const_iterator				lower_bound(const value_type & pair) const
									{
										const_iterator it = this->begin();
										while (it != this->end())
										{
											if (!_cmp(*it, pair))
												return it;
											it++;
										}
										return (it);
									}
		iterator					upper_bound(const value_type & pair)
									{
										iterator it = this->begin();
										while (it != this->end())
										{
											if (_cmp(pair, *it))
												return it;
											it++;
										}
										return (it);
									}
		const_iterator				upper_bound(const value_type & pair) const
									{
										const_iterator it = this->begin();
										while (it != this->end())
										{
											if (_cmp(pair, *it))
												return it;
											it++;
										}
										return (it);
									}
  		iterator 					find(const value_type &  k) const
									{
										return (iterator(searchTreeHelper(_root, k), _root, _TNULL));
									}
  		void						swap(RedBlackTree & other)
									{
										allocator_type								alloca;
										size_type									size;
										NodePtr										root;
										NodePtr 									TNULL;
									//	key_compare									cmp;

									//	cmp = this->_cmp;
										alloca = this->_alloc;
										size = this->_size;
										root = this->_root;
										TNULL = _TNULL;

									//	this->_cmp	= other._cmp;
										this->_alloc=other._alloc ;
										this->_size	=other._size ;
										this->_root	=other._root ;
										_TNULL = other._TNULL;

									//	other._cmp = cmp ;
										other._alloc = alloca;
										other._size = size;
										other._root = root;
										other._TNULL = TNULL;
									}

		};
}

#endif