/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:55:53 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/05 00:45:56 by hesayah          ###   ########.fr       */
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

    	/*protected :*/
									compare 									_cmp;
									allocator_type								_alloc;
									size_type									_size;
  									NodePtr										_root;
  									NodePtr 									_TNULL;

		void						preOrderHelper(NodePtr node)
									{
										if (node != _TNULL) 
										{
											std::cout << node->data << " ";
											preOrderHelper(node->left);
											preOrderHelper(node->right);
										}
									}
		NodePtr						minimum(NodePtr node) const
  									{
    									while (node->left != _TNULL)
      										node = node->left;
    									return node;
									}
 		NodePtr	 					maximum(NodePtr node) const
  									{
										while (node->right != _TNULL)
											node = node->right;
										return node;
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
  // Inorder
  void inOrderHelper(NodePtr node)
  {
    if (node != _TNULL)
	{
      inOrderHelper(node->left);
      std::cout << node->data.first << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != _TNULL) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
     std::cout << node->data.first << " ";
    }
  }

NodePtr searchTreeHelper(NodePtr node, T key) 
  {
    if (node == _TNULL || key == node->data)
      return (node);
    if (key < node->data)
      return searchTreeHelper(node->left, key);
    return searchTreeHelper(node->right, key);
  }

  // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != _root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
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
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
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

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == NULL) {
      _root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void deleteNodeHelper(NodePtr node, T key) {
    NodePtr z = _TNULL;
    NodePtr x, y;
    while (node != _TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == _TNULL) {
     std::cout << "Key not found in the tree" << std::endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == _TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == _TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
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
    if (y_original_color == 0) 
      deleteFix(x);
	_size--;
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == _root) {
        break;
      }
    }
    _root->color = 0;
  }
    void clear(NodePtr _root) {
    if (_root != _TNULL) 
	{
      	clear(_root->left);
     	clear(_root->right);
	  	_alloc.destroy(_root);
		_alloc.deallocate(_root, 1);
    }
	}

  void printHelper(NodePtr _root, std::string indent, bool last) {
    if (_root != _TNULL) {
     std::cout << indent;
      if (last) {
       std::cout << "R----";
        indent += "   ";
      } else {
       std::cout << "L----";
        indent += "|  ";
      }

      std::string sColor = _root->color ? "RED" : "BLACK";
     	std::cout << _root->data.first << "(" << sColor << ")" << std::endl;
      printHelper(_root->left, indent, false);
      printHelper(_root->right, indent, true);
    }
  }

   public:
  RedBlackTree(compare c = compare(), allocator_type alloca = allocator_type()) : _cmp(c), _alloc(alloca), _size(0) 
  {
    _TNULL = _alloc.allocate(1);
    _TNULL->color = 0;
    _TNULL->left = NULL;
    _TNULL->right = NULL;
    _root = _TNULL;
  }
    ~RedBlackTree() {
		if (_size)
			clear(_root);
		//_alloc.destroy(_TNULL);
		_alloc.deallocate(_TNULL, 1);
  }

  void preorder()
  {
    preOrderHelper(this->_root);
  }

  void inorder()
  {
    inOrderHelper(this->_root);
  }

  void postorder()
  {
    postOrderHelper(this->_root);
  }

  iterator searchTree(T k) 
  {
    return (iterator(searchTreeHelper(_root, k), _root, _TNULL));
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != _TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->_root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != _TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
      this->_root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  iterator insert(T key) {
    NodePtr node = _alloc.allocate(1);
	_alloc.construct(node, key);
    node->parent = NULL;
    node->left = _TNULL;
    node->right = _TNULL;
    node->color = 1;

    NodePtr y = NULL;
    NodePtr x = this->_root;

    while (x != _TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == NULL) {
      _root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }
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

/*  NodePtr get_root() {
    return this->_root;
  }*/

  void deleteNode(T data) {
    deleteNodeHelper(this->_root, data);
  }

  void printTree() {
    if (_root) {
      printHelper(this->_root, "", true);
    }
  }
};

}

#endif