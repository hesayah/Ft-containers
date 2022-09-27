#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

/**
*** https://cplusplus.com/reference/vector/vector/
*** https://en.cppreference.com/w/cpp/container/vector
*** https://fr.acervolima.com/programme-pour-creer-une-classe-vectorielle-personnalisee-en-c/
**/

#include <memory>

namespace ft {
								template <class T, class Alloc = std::allocator<T>>
	class						vector 
	{

		typedef typename		value_type<T>;
		typedef typename		allocator_type	 allocator<value_type>;
		typedef typename		reference	allocator_type::reference	= value_type&;
		typedef typename		const_reference	allocator_type::const_reference = const value_type&;
		typedef typename		pointer	allocator_type::pointer	= value_type*;
		typedef typename		const_pointer	allocator_type::const_pointer = const value_type*;
		typedef typename		iterator;
		typedef typename		const_iterator	= const value_type;	
		typedef typename		reverse_iterator	reverse_iterator<iterator>;
		typedef typename		const_reverse_iterator	reverse_iterator<const_iterator>;	
		typedef typename		difference_type iterator_traits<iterator>::difference_type	= ptrdiff_t;
		typedef typename		size_type	 size_t;

		explicit				vector(const allocator_type& alloc = allocator_type());
		explicit				vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
								template <class InputIterator>         
								vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());	
								vector(const vector& src);
								~vector(void){};
		private :
		T						*arr;
		size_t					capacity;
		size_t					size;
		
/**
*** Members function
**/

		vector & 				operator=(const vector & src);
		void 					assign( size_type count, const T& value );
								template< class InputIt >
		void 					assign( InputIt first, InputIt last );
		allocator_type 			get_allocator() const;


/**
*** Iterators
**/

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

/**
*** Capacity
**/

		bool 					empty() const;
		void 					reserve(size_type new_cap);
		size_type 				size() const;
		size_type 				max_size() const;
		size_type 				capacity() const;

/**
*** Element access
**/
		T* 						data();
		reference 				at(size_type pos);
		reference 				operator[](size_type pos);
		reference 				front();
		reference 				back();

/**
*** Modifiers
**/

		void 					clear();
		void 					push_back(const T& value);
		void 					pop_back();
		void 					resize(size_type count, T value = T());
		void 					swap(vector	& other);
		iterator 				insert(const_iterator pos, const T & value);
		iterator 				insert(const_iterator pos, size_type count, const T & value);
								template<class InputIt>
		iterator 				insert(const_iterator pos, InputIt first, InputIt last);
		iterator 				erase(iterator pos);
		iterator 				erase(iterator first, iterator last);
		


/**
*** Vector operator
**/
								template<class T, class Alloc>
		bool					operator==(const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs);
								template<class T, class Alloc>

		bool					operator!=(const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs);
								template<class T, class Alloc>
		bool					operator<(const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs);
								template<class T, class Alloc>
		bool					operator<=(const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs);
								template<class T, class Alloc>
		bool					operator>(const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
								template< class T, class Alloc >
		bool					operator>=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
	};
}



#endif