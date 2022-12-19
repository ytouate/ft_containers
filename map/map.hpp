/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:07:54 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/19 12:06:07 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MAP_HPP)
#define MAP_HPP

#include "../inc.hpp"

namespace ft
{
    template <class key, class T, class Compare = std::less<key>,
              class Allocator = std::allocator<ft::pair<const key, T> > >
    class map
    {
    public:
        typedef key                                        key_type;
        typedef T                                          mapped_type;
        typedef ft::pair<const key, T>                     value_type;
        typedef Compare                                    key_compare;
        typedef Allocator                                  allocator_type;
        typedef typename Allocator::reference              reference;
        typedef typename Allocator::const_reference        const_reference;
        typedef typename Allocator::pointer                pointer;
        typedef typename Allocator::const_pointer          const_pointer;
        typedef size_t                                     size_type;
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        // construct / copy / destror
        explicit map(const key_compare &comp = key_compare(), const Allocator &alloc = Allocator()) : _tree()
        {
            this->_size = 0;
            this->_comp = comp;
            this->_alloc = alloc;
        }
        template <class inputIterator>
        map(inputIterator first, inputIterator last,
            const key_compare &comp = key_compare(), const Allocator & = Allocator());
        const map<key, T, key_compare, Allocator>& operator =(const map<key, T, Compare, Allocator>&rhs);
    private:
        size_type                       _size;
        Compare                         _comp;
        Allocator                       _alloc;
        ft::redBlackTree<value_type>    _tree;
    };
};
#endif // MAP
