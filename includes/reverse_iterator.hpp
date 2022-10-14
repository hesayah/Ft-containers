/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:55:48 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/14 15:39:55 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__


# include "iterator_traits.hpp"

namespace ft {
template <typename It>
class reverse_iterator
    : public std::iterator<
          typename iterator_traits<It>::iterator_category, typename iterator_traits<It>::value_type,
          typename iterator_traits<It>::difference_type, typename iterator_traits<It>::pointer,
          typename iterator_traits<It>::reference>
{
    // clang-format off
public:
    typedef It                                            iterator_type;
    typedef typename iterator_traits<It>::value_type      value_type;
    typedef typename iterator_traits<It>::difference_type difference_type;
    typedef typename iterator_traits<It>::reference       reference;
    typedef typename iterator_traits<It>::pointer         pointer;
    // clang-format on

public:
    reverse_iterator()
        : current()
    {
    }

    reverse_iterator(const reverse_iterator& it)
        : current(it.current)
    {
    }

    explicit reverse_iterator(iterator_type it)
        : current(it)
    {
    }

    template <typename Iter>
    reverse_iterator(const reverse_iterator<Iter>& it)
        : current(it.base())
    {
    }

    ~reverse_iterator()
    {
    }

    reverse_iterator& operator=(const reverse_iterator& other)
    {
        current = other.current;
        return *this;
    }

public:
    iterator_type base() const
    {
        return current;
    }

    reference operator*() const
    {
        It tmp = current;
        return *--tmp;
    }

    pointer operator->() const
    {
        return &(operator*());
    }

    reverse_iterator& operator++()
    {
        --current;
        return *this;
    }

    reverse_iterator operator++(int)
    {
        return reverse_iterator(current--);
    }

    reverse_iterator& operator--()
    {
        ++current;
        return *this;
    }

    reverse_iterator operator--(int)
    {
        return reverse_iterator(current++);
    }

    reverse_iterator operator+(difference_type n) const
    {
        return reverse_iterator(current - n);
    }

    reverse_iterator& operator+=(difference_type n)
    {
        current -= n;
        return *this;
    }

    reverse_iterator operator-(difference_type n) const
    {
        return reverse_iterator(current + n);
    }

    reverse_iterator& operator-=(difference_type n)
    {
        current += n;
        return *this;
    }

    reference operator[](difference_type n) const
    {
        return *(*this + n);
    }

protected:
    It current;
};

template <typename ItL, typename ItR>
inline bool operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() == rhs.base();
}

template <typename It>
inline bool operator==(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() == rhs.base();
}

template <typename ItL, typename ItR>
inline bool operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() != rhs.base();
}

template <typename It>
inline bool operator!=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() != rhs.base();
}

template <typename ItL, typename ItR>
inline bool operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() < rhs.base();
}

template <typename It>
inline bool operator>(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() < rhs.base();
}

template <typename ItL, typename ItR>
inline bool operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() > rhs.base();
}

template <typename It>
inline bool operator<(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() > rhs.base();
}

template <typename ItL, typename ItR>
inline bool operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() <= rhs.base();
}

template <typename It>
inline bool operator>=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() <= rhs.base();
}

template <typename ItL, typename ItR>
inline bool operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
{
    return lhs.base() >= rhs.base();
}

template <typename It>
inline bool operator<=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
{
    return lhs.base() >= rhs.base();
}

template <typename ItL, typename ItR>
inline typename reverse_iterator<ItL>::difference_type operator-(const reverse_iterator<ItL>& lhs,
                                                                 const reverse_iterator<ItR>& rhs)
{
    return rhs.base() - lhs.base();
}

template <typename It>
inline typename reverse_iterator<It>::difference_type operator-(const reverse_iterator<It>& lhs,
                                                                const reverse_iterator<It>& rhs)
{
    return rhs.base() - lhs.base();
}

template <typename It>
inline reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n,
                                      const reverse_iterator<It>& it)
{
    return reverse_iterator<It>(it.base() - n);
}

}

#endif