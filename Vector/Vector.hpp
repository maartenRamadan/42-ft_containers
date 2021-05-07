#pragma once

# include <memory>
# include <algorithm>
# include "../Iterator/RandomAccessIterator.hpp"
# include "../Utils/Traits.hpp"
# include "../Utils/ft_utils.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef size_t										size_type;
			typedef ft::randomAccessIterator<T> 				iterator;
			typedef ft::constRandomAccessIterator<T> 			const_iterator;
			typedef ft::reverseRandomAccessIterator<T> 			reverse_iterator;
			typedef ft::constReverseRandomAccessIterator<T> 	const_reverse_iterator;

		private:
			T*		_data;
			size_t	_size;
			size_t	_capacity;
			Alloc	_alloc;

			void		reallocate(size_t n) {
				size_t i;
				T* tmp = new T[n];
				for (i = 0; i < _size && i < n; ++i)
					tmp[i] = _data[i];
				_size = i;
				_capacity = n;
				delete [] _data;
				_data = tmp;
			}

		public:
	// constructors
			explicit vector(const Alloc& alloc = Alloc())
			  : _data(NULL), _size(0), _capacity(0), _alloc(alloc) { }

			explicit vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {
				_data = _alloc.allocate(n);
				for (_size = 0; _size < n; _size++)
					_data[_size] = val;
				_capacity = _size;
			}

			template <class InputIterator>
			vector(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc())
			  : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {
				assign(first, last);
				reallocate(_size);
			}

			vector(const vector& rhs)
			  : _data(NULL), _size(0), _capacity(0), _alloc(rhs._alloc) {
				if (*this != rhs)
					*this = rhs;
			}
		
			~vector() { delete [] _data; }

	// exceptions
		class out_of_range : public std::exception {
			public:
				virtual const char* what() const throw() { return "vector"; }
		};

	// operators:
			vector&			operator=(const vector& rhs) {
				reallocate(rhs._size);
				clear();
				for (_size = 0; _size < rhs._size; _size++)
					_data[_size] = rhs._data[_size];
				_capacity = _size;
				return (*this);
			}

			T&			operator[](size_t n) {
				return _data[n];
			}

			const T&			operator[](size_t n) const {
				return _data[n];
			}

	// iterators:
			iterator					begin() {
				return iterator(_data);
			}
			const_iterator				begin() const {
				return const_iterator(_data);
			}
			iterator					end() {
				return iterator(_data + _size);
			}
			const_iterator				end() const {
				return const_iterator(_data + _size);
			}
			reverse_iterator			rbegin() {
				return reverse_iterator(_data + _size-1);
			}
			const_reverse_iterator		rbegin() const {
				return const_reverse_iterator(_data + _size-1);
			}
			reverse_iterator			rend() {
				return reverse_iterator(_data-1);
			}
			const_reverse_iterator		rend() const {
				return const_reverse_iterator(_data-1);
			}

	// Capacity:
			size_t		size() const { return _size; }
			
			size_t		max_size() { return _alloc.max_size(); }

			void		resize (size_t n, T val = T()) {
				if (n < _size)
					for (; _size > n; _size--)
						_alloc.destroy(_data + _size);
				else if (n > _size)
				{
					reserve(n);
					for (; _size < n; _size++)
						_data[_size] = val;
				}
			}
	
			bool			empty() {
				if (_size == 0)
					return true;
				else
					return false;
			}

			size_t			capacity() {
				return _capacity;
			}
	
			void			reserve(size_t n) {
				if (n > _capacity)
				{
					T* tmp;
					tmp = _alloc.allocate(n);
					if (_size)
					{
						size_t i;
						for (i = 0; i < _size; i++)
							tmp[i] = _data[i];
						for (; i < n; ++i)
							tmp[i] = T();
						_alloc.deallocate(_data, _capacity);
					}
					_data = tmp;
					_capacity = n;
				}
			}

	// Element access:
			T&				at(size_t n) {
				if (n >= _size)
					throw out_of_range();
				else
					return _data[n];
			}

			const T&				at(size_t n) const {
				if (n >= _size)
					throw out_of_range();
				else
					return _data[n];
			}
		
			T&				front() {
				return _data[0];
			}
			const T&		front() const {
				return _data[0];
			}

			T&				back() {
				return _data[_size-1];
			}
			const T&		back() const {
				return _data[_size-1];
			}
			
			T*				data() {
				return _data;
			}
			const T*		data() const {
				return _data;
			}

	// Modifiers:
			void			assign(size_t n, const T& val) {
				reallocate(n);
				clear();
				for (size_t i = 0; i < n; ++i)
					push_back(val);
			}

			template <class InputIterator>
			void			assign(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				reallocate(distance(first, last));
				clear();
				for (; first != last; ++first)
					push_back(*first);
			}

			void			push_back(const T& val) {
				if (_capacity == 0) {
					_data = new T[1];
					_capacity = 1;
				}
				else if (_size == _capacity)
					reallocate(_size * 2);
				_data[_size] = val;
				_size++;
			}
			
			void			pop_back() {
				if (_size)
				{
					_size--;
					_alloc.destroy(_data + _size);
				}
			}
	
			iterator				insert(iterator position, const T& val) {
				size_t i = distance(begin(), position);
				insert(position, 1, val);
				return iterator(_data + i);
			}

			void					insert(iterator position, size_t n, const T& val) {
				size_t i = 0;
				size_t newSize = _size + n;
				ft::vector<T> tmp;

				tmp.assign(position, end());
				i = distance(begin(), position);
				reallocate(newSize);
				for (size_t i2 = i; i2 < newSize-n; i2++)
					_alloc.destroy(_data + i2);
				for (size_t i2 = i; i < i2 + n; i++)
					_data[i] = val;
				for (iterator it = tmp.begin(); it != tmp.end(); it++) {
					_data[i] = *it;
					i++;
				}
				_size = newSize;
			}

			template <class InputIterator>
			void					insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				ft::vector<T> tmp;
				size_t i = 0;
				size_t n = distance(first, last);
				size_t newSize = _size + n;

				tmp.assign(position, end());
				i = distance(begin(), position);
				reallocate(newSize);
				for (size_t i2 = i; i2 < newSize-n; i2++)
					_alloc.destroy(_data + i2);
				for (size_t i2 = i; i < i2 + n; i++) {
					_data[i] = *first;
					first++;
				}
				for (iterator it = tmp.begin(); it != tmp.end(); it++) {
					_data[i] = *it;
					i++;
				}
				_size = newSize;
			}

			iterator			erase(iterator position) {
				iterator ret(position);

				while (position != end()-1) {
					*position = *(position + 1);
					position++;
				}
				--_size;
				return ret;
			}
			
			template <class InputIterator>
			iterator			erase(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				iterator ret(first);

				while (last != end()) {
					*first = *last;
					first++;
					last++;
				}
				_size -= distance(first, last);
				return ret;
			}

			void				swap(vector& x) {
				ft::swapItems(_data, x._data);
				ft::swapItems(_size, x._size);
				ft::swapItems(_capacity, x._capacity);
			}

			void				clear() {
				if (_size)
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_size = 0;
				}
			}

			Alloc			get_allocator() {
				return _alloc;
			}

			private:
				size_t			distance(iterator first, iterator last) {
					size_t n = 0;
					for (iterator it = first; it != last; ++it)
						++n;
					return n;
				}

	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator it_rhs = rhs.begin();

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
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
		ft::swapItems(x._data, y._data);
		ft::swapItems(x._size, y._size);
		ft::swapItems(x._capacity, y._capacity);
	}
}
