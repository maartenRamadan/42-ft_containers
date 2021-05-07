#pragma once

namespace ft
{
	template <typename T, typename Node>
	class bidirectionalIterator
	{
		public:
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef bidirectionalIterator 					iterator;
			typedef T										value_type;
			typedef size_t									size_type;
			typedef Node*									iterator_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T*										pointer;
			typedef T&										reference;

		protected:
			Node*	_node;

		public:
			bidirectionalIterator() : _node(NULL) {}
			explicit bidirectionalIterator(Node* n) : _node(n) {}
			bidirectionalIterator(const iterator& rhs) : _node(rhs._node) {}
			~bidirectionalIterator() {}

			iterator&			operator=(const iterator& rhs) {
				if (this != &rhs)
					_node = rhs._node;
				return *this;
			}

			template<typename T2, typename Node2>
			friend bool operator==(const bidirectionalIterator<T2, Node2>& lhs, const bidirectionalIterator<T2, Node2>& rhs) {
				return (lhs._node == rhs._node);
			}

			template<typename T2, typename Node2>
			friend bool operator!=(const bidirectionalIterator<T2, Node2>& lhs, const bidirectionalIterator<T2, Node2>& rhs) {
				return !(lhs == rhs);
			}

			iterator&			operator++() {
				_node = _node->getNext();
				return *this;
			}

			iterator			operator++(int) {
				iterator tmp = *this;
				++*this;
				return tmp;
			}

			iterator&			operator--() {
				_node = _node->getPrev();
				return *this;
			}

			iterator			operator--(int) {
				iterator tmp = *this;
				--*this;
				return tmp;
			}

			T*	operator->() {
				return &_node->data;
			}

			T&			operator*() {
				return _node->data;
			}

			Node*		getNode() const {
				return _node;
			}
	};
		
	template <typename T, typename Node>
	class reverseBidirectionalIterator
	{
		public:
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef reverseBidirectionalIterator 			reverse_iterator;
			typedef T										value_type;
			typedef size_t									size_type;
			typedef Node*									iterator_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T*										pointer;
			typedef T&										reference;

		protected:
			Node*	_node;

		public:
			reverseBidirectionalIterator() : _node(NULL) {}
			explicit reverseBidirectionalIterator(Node* n) : _node(n) {}
			reverseBidirectionalIterator(const reverse_iterator& rhs) : _node(rhs._node) {}
			virtual ~reverseBidirectionalIterator() {}

			const reverse_iterator&			operator=(const reverse_iterator& rhs) {
				if (this != &rhs)
					_node = rhs._node;
				return *this;
			}

			template<typename T2, typename Node2>
			friend bool operator==(const reverseBidirectionalIterator<T2, Node2>& lhs, const reverseBidirectionalIterator<T2, Node2>& rhs) {
				return (lhs._node == rhs._node);
			}

			template<typename T2, typename Node2>
			friend bool operator!=(const reverseBidirectionalIterator<T2, Node2>& lhs, const reverseBidirectionalIterator<T2, Node2>& rhs) {
				return !(lhs == rhs);
			}

			reverse_iterator&			operator++() {
				_node = _node->getPrev();
				return *this;
			}

			reverse_iterator			operator++(int) {
				reverse_iterator tmp = *this;
				++*this;
				return tmp;
			}

			reverse_iterator&			operator--() {
				_node = _node->getNext();
				return *this;
			}

			reverse_iterator			operator--(int) {
				reverse_iterator tmp = *this;
				--*this;
				return tmp;
			}

			T*			operator->() {
				return &_node->data;
			}

			T&			operator*() {
				return _node->data;
			}
			
			Node*		getNode() const {
				return _node;
			}
	};

	template <typename T, typename Node>
	class constBidirectionalIterator
	{
		public:
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef constBidirectionalIterator 				const_iterator;
			typedef T										value_type;
			typedef size_t									size_type;
			typedef Node*									iterator_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T*										pointer;
			typedef T&										reference;

		private:
			Node*	_node;

		public:
			constBidirectionalIterator() : _node(NULL) {}
			explicit constBidirectionalIterator(Node* n) : _node(n) {}
			constBidirectionalIterator(const bidirectionalIterator<T, Node>& rhs) {
				_node = rhs.getNode();
			}
			constBidirectionalIterator(const const_iterator& rhs) {
				*this = rhs;
			}
			virtual ~constBidirectionalIterator() {}

			const const_iterator&			operator=(const const_iterator& rhs) {
				if (this != &rhs)
					_node = rhs._node;
				return *this;
			}

			template<typename T2, typename Node2>
			friend bool operator==(const constBidirectionalIterator<T2, Node2>& lhs, const constBidirectionalIterator<T2, Node2>& rhs) {
				return (lhs._node == rhs._node);
			}

			template<typename T2, typename Node2>
			friend bool operator!=(const constBidirectionalIterator<T2, Node2>& lhs, const constBidirectionalIterator<T2, Node2>& rhs) {
				return !(lhs == rhs);
			}

			const_iterator&			operator++() {
				_node = _node->getNext();
				return *this;
			}

			const_iterator			operator++(int) {
				const_iterator tmp = *this;
				++*this;
				return tmp;
			}

			const_iterator&			operator--() {
				_node = _node->getPrev();
				return *this;
			}

			const_iterator			operator--(int) {
				const_iterator tmp = *this;
				--*this;
				return tmp;
			}

			const T*	operator->() {
				return &_node->data;
			}

			const T&			operator*() {
				return _node->data;
			}
			
			const Node*		getNode() const {
				return _node;
			}
	};
		
	template <typename T, typename Node>
	class constReverseBidirectionalIterator
	{
		public:
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef constReverseBidirectionalIterator 		const_reverse_iterator;
			typedef T										value_type;
			typedef size_t									size_type;
			typedef Node*									iterator_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T*										pointer;
			typedef T&										reference;

		protected:
			Node*	_node;

		public:
			constReverseBidirectionalIterator() : _node(NULL) {}
			explicit constReverseBidirectionalIterator(Node* n) : _node(n) {}
			constReverseBidirectionalIterator(const reverseBidirectionalIterator<T, Node>& rhs) {
				_node = rhs.getNode();
			}
			constReverseBidirectionalIterator(const const_reverse_iterator& rhs) {
				*this = rhs;
			}

			virtual ~constReverseBidirectionalIterator() {}

			const const_reverse_iterator&			operator=(const const_reverse_iterator& rhs) {
				if (this != &rhs)
					_node = rhs._node;
				return *this;
			}

			template<typename T2, typename Node2>
			friend bool operator==(const constReverseBidirectionalIterator<T2, Node2>& lhs, const constReverseBidirectionalIterator<T2, Node2>& rhs) {
				return (lhs._node == rhs._node);
			}

			template<typename T2, typename Node2>
			friend bool operator!=(const constReverseBidirectionalIterator<T2, Node2>& lhs, const constReverseBidirectionalIterator<T2, Node2>& rhs) {
				return !(lhs == rhs);
			}

			const_reverse_iterator&			operator++() {
				_node = _node->getPrev();
				return *this;
			}

			const_reverse_iterator			operator++(int) {
				const_reverse_iterator tmp = *this;
				++*this;
				return tmp;
			}

			const_reverse_iterator&			operator--() {
				_node = _node->getNext();
				return *this;
			}

			const_reverse_iterator			operator--(int) {
				const_reverse_iterator tmp = *this;
				--*this;
				return tmp;
			}

			T*			operator->() {
				return &_node->data;
			}

			T&			operator*() {
				return _node->data;
			}
	
			const Node*		getNode() const {
				return _node;
			}
	};
}
