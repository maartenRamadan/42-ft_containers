#pragma once

#include <memory>
#include <limits>

#include "../Utils/ft_utils.hpp"
#include "../Utils/Traits.hpp"
#include "../Iterator/BidirectionalIterator.hpp"
#include "ListNode.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef Node<T> 											node_t;
			typedef bidirectionalIterator<T, node_t> 					iterator;
			typedef constBidirectionalIterator<T, node_t> 				const_iterator;
			typedef reverseBidirectionalIterator<T, node_t> 			reverse_iterator;
			typedef constReverseBidirectionalIterator<T, node_t> 		const_reverse_iterator;
			typedef Node<T>*											node_pointer;
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef T&													reference;
			typedef const T&											const_reference;
			typedef T*													pointer;
			typedef const T*											const_pointer;
			typedef std::ptrdiff_t										difference_type;
			typedef size_t												size_type;
			typedef Node<T>			 									Node;

		private:
			node_t*		_head;
			node_t*		_tail;
			size_t		_size;
			Alloc		_alloc;

		public:
			explicit list(const Alloc& alloc = Alloc())
					: _head(new node_t()), _tail(new node_t()), _size(0), _alloc(alloc) {
				_head->next = _tail;
				_tail->prev = _head;
			}

			explicit list(size_t n, const T& val = T(), const Alloc& alloc = Alloc())
					: _head(new node_t()), _tail(new node_t()),  _size(0), _alloc(alloc) {
				_head->next = _tail;
				_tail->prev = _head;
				assign(n, val);
			}
			
			template <class InputIterator>
			list(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc())
					: _head(new node_t()), _tail(new node_t()),  _size(0), _alloc(alloc) {
				_head->next = _tail;
				_tail->prev = _head;
				assign(first, last);
			}

			list(const list& rhs)
					: _head(new node_t()), _tail(new node_t()),  _size(0), _alloc(rhs._alloc) {
				_head->next = _tail;
				_tail->prev = _head;
				*this = rhs;
			}

			~list() { 
				clear();
				delete _tail;
				delete _head;
			 }

			list&			operator=(const list& rhs) {
				_alloc = rhs._alloc;
				assign(rhs.begin(), rhs.end());
				return *this;
			}

	// iterators:
			iterator				begin() {
				return iterator(_head->next);
			}
			const_iterator				begin() const {
				return const_iterator(_head->next);
			}

			iterator				end() {
				return iterator(_tail);
			}
			const_iterator				end() const {
				return const_iterator(_tail);
			}

			reverse_iterator		rbegin() {
				return reverse_iterator(_tail->prev);
			}
			const_reverse_iterator		rbegin() const {
				return const_reverse_iterator(_tail->prev);
			}

			reverse_iterator		rend() {
				return reverse_iterator(_head);
			}
			const_reverse_iterator		rend() const {
				return const_reverse_iterator(_head);
			}
	
	// Capacity:
			size_t		size() const { 
				return _size;
			}
			
			size_t		max_size() { 
				return std::numeric_limits<size_t>::max() / sizeof(node_t);
			}

			bool			empty() {
				if (_size == 0)
					return true;
				else
					return false;
			}

	// Element access:		
			T&				front() {
				return _head->next->data;
			}

			T&				front() const {
				return _head->next->data;
			}

			T&				back() {
				return _tail->prev->data;
			}

			T&				back() const {
				return _tail->prev->data;
			}
			
	// Modifiers:
			void				push_front(const T& val) {
				node_t* newNode = new node_t(val, _head->next, _head);
				_head->next->prev = newNode;
				_head->next = newNode;
				++_size;
			}

			void				pop_front() {
				node_t* tmp = _head->next;
				_head->next = _head->next->next;
				_head->next->prev = _head;
				--_size;
				delete tmp;
			}

			void				resize(size_t n, T val = T()) {
				if (n < _size)
					for (; _size > n; pop_back());
				else
					for (; _size < n; push_back(val));
			}
			
			template <class InputIterator>
			void				assign(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				clear();
				for (; first != last; ++first)
					push_back(*first);
			}

			void				assign(size_t n, const T& val) {
				clear();
				for (; n > 0; --n)
					push_back(val);				
			}

			void			push_back(const T& val) {
				node_t* newNode = new node_t(val, _tail, _tail->prev);

				_tail->prev->next = newNode;
				_tail->prev = newNode;
				++_size;
			}
			
			void			pop_back() {
				node_t* tmp = _tail->prev;
				_tail->prev = _tail->prev->prev;
				_tail->prev->next = _tail;
				--_size;
				delete tmp;
			}
	
			iterator				insert(iterator position, const T& val) {
				node_t* tmp = _head->next;

				for (iterator it = begin(); it != position; ++it)
					tmp = tmp->next;
				
				node_t* newNode = new node_t(val, tmp, tmp->prev);
				
				tmp->prev->next = newNode;
				tmp->prev = newNode;
				++_size;
				return position;
			}

			void					insert(iterator position, size_t n, const T& val) {
				for (; n > 0; --n)
					insert(position, val);
			}

			template <class InputIterator>
			void					insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				for (; first != last; ++first) {
					insert(position, *first);
				}
			}

			iterator				erase(iterator position) {
				iterator ret(position);
				ret++;
				node_t* tmp = position.getNode();

				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				--_size;
				return ret;
			}
			
			iterator				erase(iterator first, iterator last) {
				for (iterator tmp = first; first != last; first = tmp) {
					tmp++;
					first = erase(first);
				}
				return first;
			}

			void				swap(list& x) {
				ft::swapItems(_head, x._head);
				ft::swapItems(_tail, x._tail);
				ft::swapItems(_size, x._size);
			}

			void			clear() {
				if (_size)
				{
					node_t* tmp = _head->next->next;

					for (; _size > 0; _size--) {
						delete tmp->prev;
						tmp = tmp->next;
					}
				}
				_head->next = _tail;
				_tail->prev = _head;
			}

		// Operations:
			void			splice(iterator position, list& x) {
				splice(position, x, x.begin(), x.end());
			}

			void			splice(iterator position, list& x, iterator i) {
				node_t* tmp = _head->next;
				
				for (iterator it = begin(); it != position; ++it)
					tmp = tmp->next;
				
				node_t* tmpX = x._head->next;
				
				for (iterator itX = x.begin(); itX != i; ++itX)
					tmpX = tmpX->next;

				tmpX->next->prev = tmpX->prev;
				tmpX->prev->next = tmpX->next;
				--x._size;

				tmp->prev->next = tmpX;
				tmpX->prev = tmp->prev;
				tmp->prev = tmpX;
				tmpX->next = tmp;
				++_size;
			}

			void			splice(iterator position, list& x, iterator first, iterator last) {
				for (; first != last; splice(position, x, first++)) {}
			}

			void			remove(const T& val) {
				iterator it = begin();
				for (iterator tmp = it; it != end(); it = tmp) {
					tmp++;
					if (*it == val)
						erase(it);
				}
			}

			template <class Predicate>
  			void			remove_if(Predicate pred) {
				iterator it = begin();
				for (iterator tmp = it; it != end(); it = tmp) {
					tmp++;
					if (pred(*it))
						erase(it);
				}
			}

			void			unique() {
				iterator it = begin();
				++it;

				while (it != end()) 
				{
					if (*it == it.getNode()->prev->data)
						it = erase(it);
					else
						++it;
				}
			}

			template <class BinaryPredicate>
			void			unique(BinaryPredicate binary_pred) {
				if (_size > 1)
				{
					iterator it = begin();
					++it;
					for (; it != end(); ++it) {
						if (binary_pred(*it, it.getNode()->prev->data))
							erase(it);
					}
				}
			}

			void			merge(list& x) {
				iterator it = begin();
				iterator itX;
		
				while (x._size && it != end())
				{
					itX = x.begin();
					if (*itX < *it)
						splice(it, x, itX);
					else
						++it;
				}
				if (x._size)
					splice(end(), x);
			}

			template <class Compare>
  			void			merge(list& x, Compare comp) {
				iterator it = begin();
				iterator itX;
		
				while (x._size && it != end())
				{
					itX = x.begin();
					if (comp(*itX, *it))
						splice(it, x, itX);
					else
						++it;
				}
				if (x._size)
					splice(end(), x);
			}

			void			sort() {
				node_t* tmp = _head->next;
				for (; tmp != _tail; tmp = tmp->next) {
					node_t* tmp2 = tmp->next;
					for (; tmp2 != _tail; tmp2 = tmp2->next)
						if (tmp->data > tmp2->data)
							ft::swapItems(tmp->data, tmp2->data);
				}
			}

			template <class Compare>
  			void			sort(Compare comp) {
				node_t* tmp = _head->next;
				for (; tmp != _tail; tmp = tmp->next) {
					node_t* tmp2 = tmp->next;
					for (; tmp2 != _tail; tmp2 = tmp2->next)
						if (!comp(tmp->data, tmp2->data))
							ft::swapItems(tmp->data, tmp2->data);
				}
			}

			void			reverse() {
				node_t* list = _head->next;
				for (; list != _tail; list = list->prev)
					ft::swapItems(list->prev, list->next);
				ft::swapItems(_head->prev, _head->next);
				ft::swapItems(_tail->prev, _tail->next);
				ft::swapItems(_head, _tail);
			}
			
			Alloc			get_allocator() {
				return _alloc;
			}
	};

	template <class T, class Alloc>
	bool operator==(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		typename ft::list<T>::const_iterator it_lhs = lhs.begin();
		typename ft::list<T>::const_iterator it_rhs = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it_lhs != lhs.end()) {
			if (*it_lhs != *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

	template <class T, class Alloc>
	bool operator<=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(list<T, Alloc>& x, list<T, Alloc>& y) {
		ft::swapItems(x._head, y._head);
		ft::swapItems(x._tail, y._tail);
		ft::swapItems(x._size, y._size);
	}
}
