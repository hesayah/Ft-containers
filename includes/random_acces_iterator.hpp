#ifndef __iterator_HPP__
# define __iterator_HPP__

# include "iterator_traits.hpp"

namespace ft {

template<typename itertype>
class iterator : public iterator<random_access_iterator_tag, itertype>
{
    protected :
    itertype* _ptr;
    
    iterator() : _ptr(nullptr) {}
    iterator(itertype* rhs) : _ptr(rhs) {}
    iterator(const iterator &rhs) : _ptr(rhs._ptr) {}
    /* inline iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
    /* inline iterator& operator=(const iterator &rhs) {_ptr = rhs._ptr; return *this;} */
    inline iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
    inline iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
    inline itertype& operator*() const {return *_ptr;}
    inline itertype* operator->() const {return _ptr;}
    inline itertype& operator[](difference_type rhs) const {return _ptr[rhs];}
    
    inline iterator& operator++() {++_ptr; return *this;}
    inline iterator& operator--() {--_ptr; return *this;}
    inline iterator operator++(int) const {iterator tmp(*this); ++_ptr; return tmp;}
    inline iterator operator--(int) const {iterator tmp(*this); --_ptr; return tmp;}
    /* inline iterator operator+(const iterator& rhs) {return iterator(_ptr+rhs.ptr);} */
    inline iterator::difference_type operator-(const iterator& rhs) const {return _ptr-rhs.ptr;}
    inline iterator operator+(iterator::difference_type rhs) const {return iterator(_ptr+rhs);}
    inline iterator operator-(iterator::difference_type rhs) const {return iterator(_ptr-rhs);}
    friend inline iterator operator+(iterator::difference_type lhs, const iterator& rhs) {return iterator(lhs+rhs._ptr);}
    friend inline iterator operator-(iterator::difference_type lhs, const iterator& rhs) {return iterator(lhs-rhs._ptr);}
    
    inline bool operator==(const iterator& rhs) const {return _ptr == rhs._ptr;}
    inline bool operator!=(const iterator& rhs) const {return _ptr != rhs._ptr;}
    inline bool operator>(const iterator& rhs) const {return _ptr > rhs._ptr;}
    inline bool operator<(const iterator& rhs) const {return _ptr < rhs._ptr;}
    inline bool operator>=(const iterator& rhs) const {return _ptr >= rhs._ptr;}
    inline bool operator<=(const iterator& rhs) const {return _ptr <= rhs._ptr;}
};
  
}

#endif