/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:55:53 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/29 02:10:39 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP

/**
*** https://www.geeksforgeeks.org/red-black-tree-set-true-introduction-2/
*** https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
*** https://www.programiz.com/dsa/red-black-tree
**/

# include <iostream>
# include <memory>
# include "bidir_iterator.hpp"
# include "reverse_iterator.hpp"
# include <memory>
# include <functional>
# include "pair.hpp"
# include "bidir_iterator.hpp"
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
			std::ostream&  operator<<(std::ostream& out){out << data; return (out);}
		};

		template <class T, class compare, class alloc>
		class RedBlackTree 
		{
			public :
				typedef 			T								 			value_type;
				typedef 			compare										key_compare;
				typedef typename 	alloc::template rebind<Node<T> >::other		allocator_type;
				/*typedef	typename	allocator_type::reference				reference;
				typedef	typename	allocator_type::const_reference				const_reference;
				typedef	typename	allocator_type::pointer						pointer;
				typedef	typename	allocator_type::const_pointer				const_pointer;
				typedef	typename	iterator_traits<pointer>::difference_type	difference_type;
				typedef				bidir_iterator<value_type>					iterator;
				typedef				bidir_iterator<const value_type>			const_iterator;*/
				typedef				size_t										size_type;
				typedef 			Node<value_type> 							nd;
				typedef				nd*											NodePtr;

    	protected :
									allocator_type								_alloc;
  									NodePtr										_root;
  									NodePtr 									_TNULL;

				void 				initializeNULLNode(NodePtr node, NodePtr parent)
									{
    									//node->data = 0;
    									node->parent = parent;
    									node->left = NULL;
    									node->right = NULL;
    									node->color = 0;
  									}
  // Preorder
				void				preOrderHelper(NodePtr node)
									{
										if (node != _TNULL) 
										{
											std::cout << node->data << " ";
											preOrderHelper(node->left);
											preOrderHelper(node->right);
										}
									}

  // Inorder
  void inOrderHelper(NodePtr node) {
    if (node != _TNULL) {
      inOrderHelper(node->left);
      std::cout << node->data << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != _TNULL) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
     std::cout << node->data << " ";
    }
  }

  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == _TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return searchTreeHelper(node->left, key);
    }
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
    if (u->parent == nullptr) {
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
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
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
     	std::cout << _root->data << "(" << sColor << ")" << std::endl;
      printHelper(_root->left, indent, false);
      printHelper(_root->right, indent, true);
    }
  }

   public:
  RedBlackTree() {
    _TNULL = _alloc.allocate(1);
    _TNULL->color = 0;
    _TNULL->left = NULL;
    _TNULL->right = NULL;
    _root = _TNULL;
  }
    ~RedBlackTree() {
		//_alloc.destruct(_TNULL, 1);
  }

  void preorder() {
    preOrderHelper(this->_root);
  }

  void inorder() {
    inOrderHelper(this->_root);
  }

  void postorder() {
    postOrderHelper(this->_root);
  }

  NodePtr searchTree(T k) {
    return searchTreeHelper(this->_root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->left != _TNULL) {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->right != _TNULL) {
      node = node->right;
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->right != _TNULL) {
      return minimum(x->right);
    }

    NodePtr y = x->parent;
    while (y != _TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->left != _TNULL) {
      return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != _TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != _TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
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
    if (x->parent == nullptr) {
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
  void insert(T key) {
    NodePtr node = _alloc.allocate(1);
	_alloc.construct(node, key);
    node->parent = NULL;
    node->left = _TNULL;
    node->right = _TNULL;
    node->color = 1;

    NodePtr y = nullptr;
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
    if (y == nullptr) {
      _root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr get_root() {
    return this->_root;
  }

  void deleteNode(T data) {
    deleteNodeHelper(this->_root, data);
  }

  void printTree() {
    if (_root) {
      printHelper(this->_root, "", true);
    }
  }
  friend std::ostream&  operator<<(std::ostream& out, Node<T> & rot){out << rot.data; return (out);}
};

}

#endif