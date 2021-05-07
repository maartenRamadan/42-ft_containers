#pragma once

namespace ft
{
	template <typename T>
	class randomAccessIterator
	{
		public:
			typedef std::random_access_iterator_tag	 iterator_category;
			typedef std::ptrdiff_t						difference_type;
			typedef randomAccessIterator				iterator;
			typedef T									value_type;
			typedef size_t								size_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef const T*							const_pointer;
			typedef const T&							const_reference;

		private:
			T*		_ptr;

		public:
			randomAccessIterator() : _ptr(NULL) {}
			randomAccessIterator(T* ptr) : _ptr(ptr) {}
			randomAccessIterator(const iterator& rhs) {
				*this = rhs;
			}
			~randomAccessIterator() {}

			iterator&	operator=(const iterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
				return (*this);
 			}

			T&			operator[](const difference_type& offset) {
				return (_ptr[offset]);
			}

			template<typename T2>
			friend bool operator<(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return (lhs._ptr < rhs._ptr); 
									}

			template<typename T2>
			friend bool operator>(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return (rhs < lhs);};

			template<typename T2>
			friend bool operator<=(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return !(rhs < lhs);
			}

			template<typename T2>
			friend bool operator>=(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return !(lhs < rhs);
			}

			template<typename T2>
			friend bool operator==(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return (lhs._ptr == rhs._ptr);
			}

			template<typename T2>
			friend bool operator!=(const randomAccessIterator<T2>& lhs, const randomAccessIterator<T2>& rhs) {
				return !(lhs == rhs);
			}

			iterator&				operator+=(const difference_type& offset) {
				_ptr += offset;
				return (*this);
			}
			iterator&				operator-=(const difference_type& offset) {
				_ptr -= offset;
				return (*this);
			}

			iterator&			operator++() {
				++_ptr;
				return (*this);
			}

			iterator			operator++(int) {
				iterator tmp = *this;
				++_ptr;
				return (tmp);
			}

			iterator			operator+(int offset) {
				return (iterator(_ptr + offset));
			}

			difference_type 	operator+(const randomAccessIterator<T>& rhs) {
				return (_ptr + rhs._ptr);
			}

			iterator&			operator--() {
				--_ptr;
				return (*this);
			}

			iterator			operator--(int) {
				iterator tmp = *this;
				--_ptr;
				return (tmp);
			}

			iterator			operator-(const difference_type& offset) {
				return (iterator(_ptr - offset));

			}

			difference_type 	operator-(const randomAccessIterator<T>& rhs) {
				return (_ptr - rhs._ptr);
			}

			T& 	operator*() {
				return (*_ptr);
			}
		
			T*	operator->() {
				return (_ptr);
			}

			T*				getPtr() const {
				return (_ptr);
			}
	};
	
	template <typename T>
	class reverseRandomAccessIterator
	{
		public:
			typedef std::random_access_iterator_tag	 iterator_category;
			typedef std::ptrdiff_t					  difference_type;
			typedef reverseRandomAccessIterator			reverse_iterator;
			typedef T									value_type;
			typedef size_t								size_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef const T*							const_pointer;
			typedef const T&							const_reference;

		private:
			T*		_ptr;

		public:
			reverseRandomAccessIterator() : _ptr(NULL) {}
			explicit reverseRandomAccessIterator(T* ptr) : _ptr(ptr) {}
			reverseRandomAccessIterator(const reverse_iterator& rhs) {
				*this = rhs;
			}
			~reverseRandomAccessIterator() {}

			reverse_iterator&	operator=(const reverse_iterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
				return (*this);
 			}

			T&			operator[](const difference_type& offset) { 
				return (_ptr[-offset]);
			};

			template<typename T2>
			friend bool operator<(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return (lhs._ptr < rhs._ptr); 
									}

			template<typename T2>
			friend bool operator>(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return (rhs < lhs);};

			template<typename T2>
			friend bool operator<=(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return !(rhs < lhs);
			}

			template<typename T2>
			friend bool operator>=(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return !(lhs < rhs);
			}

			template<typename T2>
			friend bool operator==(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return (lhs._ptr == rhs._ptr);
			}

			template<typename T2>
			friend bool operator!=(const reverseRandomAccessIterator<T2>& lhs, const reverseRandomAccessIterator<T2>& rhs) {
				return !(lhs == rhs);
			}

			reverse_iterator&		operator+=(const difference_type& offset) {
				_ptr -= offset;
				return (*this);
			}
			reverse_iterator&		operator-=(const difference_type& offset) {
				_ptr += offset;
				return (*this);
			}

			reverse_iterator&		operator++() {
				--_ptr;
				return (*this);
			}
			reverse_iterator		operator++(int) {
				reverse_iterator tmp = *this;
				++*this;
				return (tmp);
			}
			reverse_iterator		operator+(int offset) {
				return (reverse_iterator(_ptr - offset));
			}
			difference_type 		operator+(const reverseRandomAccessIterator<T>& rhs) {
				return (_ptr - rhs._ptr);
			}
			reverse_iterator&		operator--() {
				++_ptr;
				return (*this);
			}
			reverse_iterator		operator--(int) {
				reverse_iterator tmp = *this;
				--*this;
				return (tmp);
			}
			reverse_iterator		operator-(const difference_type& offset) {
				return (reverse_iterator(_ptr + offset));

			}
			difference_type 		operator-(const reverseRandomAccessIterator<T>& rhs) {
				return (_ptr + rhs._ptr);
			}

			T& 	operator*() {
				return (*_ptr);
			}
		
			T*	operator->() {
				return (_ptr);
			}

			T*				getPtr() const {
				return (_ptr);
			}
	};

	template <typename T>
	class constRandomAccessIterator
	{
		public:
			typedef std::random_access_iterator_tag	 iterator_category;
			typedef std::ptrdiff_t					  difference_type;
			typedef constRandomAccessIterator			const_iterator;
			typedef T									value_type;
			typedef size_t								size_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef const T*							const_pointer;
			typedef const T&							const_reference;

		private:
			T*		_ptr;

		public:
			constRandomAccessIterator() : _ptr(NULL) {}
			explicit constRandomAccessIterator(T* ptr) : _ptr(ptr) {}
			constRandomAccessIterator(const randomAccessIterator<T>& rhs) {
				_ptr = rhs.getPtr();
			}
			constRandomAccessIterator(const const_iterator& rhs) {
				*this = rhs;
			}
			virtual ~constRandomAccessIterator() {}

			const const_iterator&	operator=(const const_iterator& rhs) {
				if (this != &rhs)
					_ptr = rhs._ptr;
				return *this;
 			}

			T&			operator[](const difference_type& offset) { 
				return (_ptr[offset]);
			}

			template<typename T2>
			friend bool operator<(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return (lhs._ptr < rhs._ptr); 
									}

			template<typename T2>
			friend bool operator>(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return (rhs < lhs);};

			template<typename T2>
			friend bool operator<=(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return !(rhs < lhs);
			}

			template<typename T2>
			friend bool operator>=(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return !(lhs < rhs);
			}

			template<typename T2>
			friend bool operator==(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return (lhs._ptr == rhs._ptr);
			}

			template<typename T2>
			friend bool operator!=(const constRandomAccessIterator<T2>& lhs, const constRandomAccessIterator<T2>& rhs) {
				return !(lhs == rhs);
			}

			const_iterator&				operator+=(const difference_type& offset) {
				_ptr += offset;
				return (*this);
			}
			const_iterator&				operator-=(const difference_type& offset) {
				_ptr -= offset;
				return (*this);
			}
			const_iterator&			operator++() {
				++_ptr;
				return (*this);
			}
			const_iterator			operator++(int) {
				const_iterator tmp = *this;
				++_ptr;
				return (tmp);
			}
			const_iterator			operator+(int offset) {
				return (const_iterator(_ptr + offset));
			}
			difference_type 	operator+(const constRandomAccessIterator<T>& rhs) {
				return (_ptr + rhs._ptr);
			}
			const_iterator&			operator--() {
				--_ptr;
				return (*this);
			}
			const_iterator			operator--(int) {
				const_iterator tmp = *this;
				--_ptr;
				return (tmp);
			}
			const_iterator			operator-(const difference_type& offset) {
				return (const_iterator(_ptr - offset));

			}
			difference_type 		operator-(const constRandomAccessIterator<T>& rhs) {
				return (_ptr - rhs._ptr);
			}

			T& 	operator*() {
				return (*_ptr);
			}
		
			T*	operator->() {
				return (_ptr);
			}
	};

	template <typename T>
	class constReverseRandomAccessIterator
	{
		public:
			typedef std::random_access_iterator_tag	 iterator_category;
			typedef std::ptrdiff_t					  difference_type;
			typedef constReverseRandomAccessIterator	const_reverse_iterator;
			typedef T									value_type;
			typedef size_t								size_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef const T*							const_pointer;
			typedef const T&							const_reference;

		private:
			T*		_ptr;

		public:
			constReverseRandomAccessIterator() : _ptr(NULL) {}
			explicit constReverseRandomAccessIterator(T* ptr) : _ptr(ptr) {}
			constReverseRandomAccessIterator(const const_reverse_iterator& rhs) {
				*this = rhs;
			}
			constReverseRandomAccessIterator(const reverseRandomAccessIterator<T>& rhs) {
				_ptr = rhs.getPtr();
			}

			~constReverseRandomAccessIterator() {}
			const_reverse_iterator&	operator=(const const_reverse_iterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
				return (*this);
			}

			T&			operator[](const difference_type& offset) { 
				return (_ptr[-offset]);
			}

			template<typename T2>
			friend bool operator<(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) { 
				return (lhs._ptr < rhs._ptr); 
			}

			template<typename T2>
			friend bool operator>(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) { 
				return (rhs < lhs);
			}

			template<typename T2>
			friend bool operator<=(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) { 
				return !(rhs < lhs); 
			}

			template<typename T2>
			friend bool operator>=(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) { 
				return !(lhs < rhs); 
			}

			template<typename T2>
			friend bool operator==(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) { 
				return (lhs._ptr == rhs._ptr); 
			}

			template<typename T2>
			friend bool operator!=(const constReverseRandomAccessIterator<T2>& lhs, const constReverseRandomAccessIterator<T2>& rhs) {
				return !(lhs == rhs);
			}

			const_reverse_iterator&		operator+=(const difference_type& offset) {
				_ptr -= offset;
				return (*this);
			}
			const_reverse_iterator&		operator-=(const difference_type& offset) {
				_ptr += offset;
				return (*this);
			}
			const_reverse_iterator&		operator++() {
				--_ptr;
				return (*this);
			}
			const_reverse_iterator		operator++(int) {
				const_reverse_iterator tmp = *this;
				++*this;
				return (tmp);
			}
			const_reverse_iterator		operator+(int offset) {
				return (const_reverse_iterator(_ptr - offset));
			}
			difference_type 			operator+(const constReverseRandomAccessIterator<T>& rhs) {
				return (_ptr - rhs._ptr);
			}
			const_reverse_iterator&		operator--() {
				++_ptr;
				return (*this);
			}
			const_reverse_iterator		operator--(int) {
				const_reverse_iterator tmp = *this;
				--*this;
				return (tmp);
			}
			const_reverse_iterator		operator-(const difference_type& offset) {
				return (const_reverse_iterator(_ptr + offset));

			}
			difference_type 			operator-(const constReverseRandomAccessIterator<T>& rhs) {
				return (_ptr + rhs._ptr);
			}

			T& 	operator*() {
				return (*_ptr);
			}
		
			T*	operator->() {
				return (_ptr);
			}
	};
}
