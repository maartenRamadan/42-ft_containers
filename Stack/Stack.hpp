#pragma once

# include "../Vector/Vector.hpp"
# include "../List/List.hpp"
# include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef Container	container_type;
			typedef T			value_type;
			typedef size_t		size_type;

			explicit stack(const container_type& ctnr = container_type()) : _s(ctnr) { }

			~stack() {}

			stack&			operator=(const stack& rhs) {
				_s = rhs._s;
				return *this;
			}
	
		// Capacity:
			size_t		size() { return _s.size(); }

			bool			empty() {
				if (_s.empty())
					return true;
				else
					return false;
			}
	
		// Element access:		
			value_type&				top() {
				return _s.back();
			}

			const value_type&		top() const {
				return _s.back();
			}
			
		// Modifiers:
			void			push(const value_type& val) {
				_s.push_back(val);
			}

			void			pop() {
				_s.pop_back();
			}
			
		// Relational operators
			template <class value_type, class container_type>
			friend bool operator==(const stack<value_type, container_type>& lhs, const stack<T, container_type>& rhs) {
				return (lhs._s == rhs._s);
			}

			template <class value_type, class container_type>
			friend bool operator!=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs) {
				return (lhs._s != rhs._s);
			}

			template <class value_type, class container_type>
			friend bool operator<(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs) {
				return (lhs._s < rhs._s);
			}

			template <class value_type, class container_type>
			friend bool operator<=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs) {
				return (lhs._s <= rhs._s);
			}

			template <class value_type, class container_type>
			friend bool operator>(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs) {
				return (lhs._s > rhs._s);
			}

			template <class value_type, class container_type>
			friend bool operator>=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs) {
				return (lhs._s >= rhs._s);
			}
			
		private:
			container_type		_s;
	};

	// Non-member overloads
	template <class T, class Container>
  	void swap(stack<T, Container>& x, stack<T, Container>& y) {
		  ft::swapItems(x._s, y._s);
	}
}
