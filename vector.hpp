#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include "includes/iterator.hpp"
#include <memory>

namespace ft {

template<typename T, typename Alloc = std::allocator<T> > 
class vector {

    private:

    //size capasiti inter

public:
  typedef T                                       value_type;            
  typedef Alloc                                   allocator_type;        
  typedef allocator_type::size_type               size_type;             
  typedef allocator_type::difference_type         difference_type;       
  //typedef unspecified                             reference;             
  //typedef unspecified                             const_reference;       
  //typedef allocator_type::pointer                 pointer;               
  //typedef allocator_type::const_pointer           const_pointer;         
  //typedef buffer_iterator< T >                    iterator;              
  //typedef buffer_iterator< T >                    const_iterator;        
  //typedef std::reverse_iterator< iterator >       reverse_iterator;      
  //typedef std::reverse_iterator< const_iterator > const_reverse_iterator;

  vector();
  ~vector();


  iterator begin();
  const_iterator begin() const;
  const_iterator cbegin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cend() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator crbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;
  const_reverse_iterator crend() const;
  size_type size() const;
  size_type max_size() const;
  void resize(size_type);
  bool empty() const;
  size_type capacity() const;
  void reserve(size_type);
  reference operator[](size_type);
  const_reference operator[](size_type) const;
  reference at(size_type);
  const_reference at(size_type) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  void assign(size_type, const T &);
  void push_back(const T &);
  void pop_back();
  iterator insert(iterator, const T &);
  void insert(iterator, size_type, const T &);
  template<typename InputIterator> 
    void insert(iterator, InputIterator, InputIterator);
  iterator erase(iterator);
  iterator erase(iterator, iterator);
  void swap(vector< T > &);
  void clear();
  allocator_type get_allocator() const;
  const buffer & get_buffer() const;
};

}



#endif