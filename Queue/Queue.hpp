#pragma once

#include "../List/List.hpp"
# include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class queue
	{
		public:
			typedef Container	container_type;
			typedef T			value_type;
			typedef size_t		size_type;

			explicit queue(const container_type& container = container_type()) : _q(container) {}

			~queue() {}

			queue& operator=(const queue& rhs) {
				this->_q = rhs._q;
				return *this;
			}
	
		// Capacity:

			size_t size() { return _q.size(); }

			bool empty() {
				if (this->_q.empty())
					return true;
				else
					return false;
			}
	
		// Element access:
			T& front() {
				return this->_q.front();
			}

			const T& front() const {
				return this->_q.front();
			}

			T& back() {
				return this->_q.back();
			}

			const T& back() const {
				return this->_q.back();
			}
			
		// Modifiers:
			void push(const value_type& val) {
				this->_q.push_back(val);
			}

			void pop() {
				this->_q.pop_front();
			}

		// Relational operators
			template <class value_type, class container_type>
			friend bool operator==(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q == rhs._q);
			}

			template <class value_type, class container_type>
			friend bool operator!=(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q != rhs._q);
			}

			template <class value_type, class container_type>
			friend bool operator<(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q < rhs._q);
			}

			template <class value_type, class container_type>
			friend bool operator<=(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q <= rhs._q);
			}

			template <class value_type, class container_type>
			friend bool operator>(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q > rhs._q);
			}

			template <class value_type, class container_type>
			friend bool operator>=(const queue<value_type, container_type>& lhs, const queue<value_type, container_type>& rhs) {
				return (lhs._q >= rhs._q);
			}
	
		private:
			container_type		_q;
	};
	
	// Non-member overloads
	template <class T, class Container>
  	void swap(queue<T, Container>& x, queue<T, Container>& y) {
		  ft::swapItems(x._q, y._q);
	}
}
