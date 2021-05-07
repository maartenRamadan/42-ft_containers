#pragma once

# include <utility>
# include "MapNode.hpp"
# include "../Vector/Vector.hpp"
# include "../Utils/ft_utils.hpp"
# include "../Utils/Pair.hpp"
# include "../Utils/Traits.hpp"
# include "../Iterator/BidirectionalIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
			typedef ft::pair<const Key,T> 								pair;
			typedef ft::mapNode<pair> 									node_t;
			typedef ft::bidirectionalIterator<pair, node_t> 			iterator;
			typedef ft::constBidirectionalIterator<pair, node_t> 		const_iterator;
			typedef ft::reverseBidirectionalIterator<pair, node_t> 		reverse_iterator;
			typedef ft::constReverseBidirectionalIterator<pair, node_t> const_reverse_iterator;
			typedef Compare											 key_compare;
			
		private:
			node_t*		_root;
			node_t*		_top;
			node_t*		_bottom;
			Compare		_comp;
			size_t		_size;
			Alloc		_alloc;

		public:

			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					bool operator()(const pair& x, const pair& y) const {
						return comp(x.first, y.first);
					}
			};

			explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) 
			  : _root(NULL), _top(new node_t()), _bottom(new node_t()), _comp(comp), _size(0), _alloc(alloc) {
				_bottom->parent = _top;
				_top->parent = _bottom;
			}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) 
			  : _root(NULL), _top(new node_t()), _bottom(new node_t()), _comp(comp), _size(0), _alloc(alloc) {
				_bottom->parent = _top;
				_top->parent = _bottom;
				insert(first, last);
			}
	
			map(const map& rhs)
			  : _root(NULL), _top(new node_t()), _bottom(new node_t()), _size(0) {
				_bottom->parent = _top;
				_top->parent = _bottom;
				*this = rhs;
			}

			~map() {
				clear();
				delete _bottom;
				delete _top;
			}

			map&			operator=(const map& rhs) {
				_alloc = rhs._alloc;
				_comp = rhs._comp;

				clear();
				insert(rhs.begin(), rhs.end());
				return *this;
			}

	// iterators:
			iterator					begin() {
				return iterator(_bottom->parent);
			}
			const_iterator				begin() const {
				return const_iterator(_bottom->parent);
			}

			iterator					end() {
				return iterator(_top);
			}
			const_iterator				end() const {
				return const_iterator(_top);
			}

			reverse_iterator			rbegin() {
				return reverse_iterator(_top->parent);
			}
			const_reverse_iterator		rbegin() const {
				return const_reverse_iterator(_top->parent);
			}

			reverse_iterator			rend() {
				return reverse_iterator(_bottom);
			}
			const_reverse_iterator		rend() const {
				return const_reverse_iterator(_bottom);
			}
	
	// Capacity:
			bool					empty() {
				if (_size == 0)
					return true;
				else
					return false;
			}

			size_t					size() { return _size; }
			
			size_t					max_size() { return _alloc.max_size(); }

	// Element access:		
			T& operator[] (const Key& k) {
				return ((*((insert(ft::make_pair(k,T()))).first)).second);
			}

	// Modifiers:	
			ft::pair<iterator,bool>		insert(const pair& pr) {
				iterator it = find(pr.first);

				if (it != end())
					return ft::make_pair(iterator(it), false);
				node_t* newNode = new node_t(pr);
				insertNode(newNode);
				++_size;
				if (_size % 3 == 0)
					balance(Key());
				return ft::make_pair(iterator(newNode), true);
			}

			iterator				insert(iterator position, const pair& val) {
				if (position->first == val.first)
					return position;
				else
					return insert(val).first;
			}

			template <class InputIterator>
			void					insert(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				for (; first != last; ++first) {
					insert(*first);
				}
			}

			void					erase(iterator position) {
				erase(position->first);
			}

			size_t					erase(const Key& k) {
				if (find(k) != end())
				{
					balance(k);
					--_size;
					return (1);
				}
				else
					return (0);
			}

			void					erase(iterator first, iterator last) {
				iterator tmp = first;
				for (; first != last; first = tmp) {
					++tmp;
					erase(first);
				}
			}

			void 					swap(map& x) {
				ft::swapItems(_root, x._root);
				ft::swapItems(_bottom, x._bottom);
				ft::swapItems(_top, x._top);
				ft::swapItems(_comp, x._comp);
				ft::swapItems(_size, x._size);
			}

			void					clear() {
				if (!empty())
					erase(begin(), end());
				_bottom->parent = _top;
				_top->parent = _bottom;
				_root = NULL;
			}

		// Observers:
			Compare			key_comp() const {
				return _comp;
			}

			value_compare		value_comp() const {
				return value_compare(_comp);
			}

		// Operations:
			iterator			find(const Key& k) {
				if (!empty()) {
					iterator it = begin();
					for (; it != end(); ++it) {
						if (it->first == k)
							return it;
					}
				}
				return end();
			}

			const_iterator		find(const Key& k) const {
				const_iterator it = begin();
				for (; it != end(); ++it) {
					if (it->first == k)
						return it;
				}
				return end();
			}

			size_t 			count(const Key& k) const {
				if (find(k) != end())
					return (1);
				return (0);
			}

			iterator			lower_bound(const Key& k) {
				iterator it = begin();
				for (; it != end(); ++it) {
					if (!key_comp()(it->first, k))
						return it;
				}
				return end();
			}

			const_iterator		lower_bound(const Key& k) const {
				const_iterator it = begin();
				for (; it != end(); ++it) {
					if (!key_comp()(it->first, k))
						return it;
				}
				return end();
			}

			iterator			upper_bound(const Key& k) {
				iterator it = begin();
				for (; it != end(); ++it) {
					if (key_comp()(k, it->first))
						return it;
				}
				return end();
			}

			const_iterator		upper_bound(const Key& k) const {
				const_iterator it = begin();
				for (; it != end(); ++it) {
					if (key_comp()(k, it->first))
						return it;
				}
				return end();
			}

			ft::pair<iterator,iterator>					equal_range(const Key& k) {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			ft::pair<const_iterator, const_iterator> 	equal_range(const Key& k) const {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

		private:
			void		store(node_t* node, ft::vector<node_t*>& nodes) {
				if (!node || node == _bottom || node == _top)
					return ;
				store(node->right, nodes);
				nodes.push_back(node);
				store(node->left, nodes);
			}

			void		fill(ft::vector<node_t*>& nodes, int start, int end, Key erase) {
				if (start > end)
					return ;
				size_t mid = (start + end) / 2;
				nodes[mid]->left = NULL;
				nodes[mid]->right = NULL;
				if (erase != Key() && (nodes[mid]->data.first == erase))
					delete nodes[mid];
				else
					insertNode(nodes[mid]);
				fill(nodes, start, mid-1, erase);
				fill(nodes, mid+1, end, erase);
			}

			void		balance(Key erase) {
				ft::vector<node_t*> nodes;

				store(_root, nodes);
				_root = NULL;
				fill(nodes, 0, nodes.size()-1, erase);
			}

			void		insertNode(node_t* newNode) {
				if (!_root)
				{
					_root = newNode;
					_root->left = _bottom;
					_root->right = _top;
					_bottom->parent = _top->parent = _root;
				}
				else
				{
					node_t* tmp = _root;
					node_t* parent = NULL;

					while (tmp && tmp != _bottom && tmp != _top)
					{
						parent = tmp;
						if (_comp(newNode->data.first, tmp->data.first))
							tmp = tmp->left;
						else
							tmp = tmp->right;
					}
					newNode->parent = parent;
					if (_comp(newNode->data.first, parent->data.first))
					{
						if (parent->left == _bottom) 
						{
							newNode->left = _bottom;
							_bottom->parent = newNode;
						}
						parent->left = newNode;
					}
					else
					{
						if (parent->right == _top)
						{
							newNode->right = _top;
							_top->parent = newNode;
						}
						parent->right = newNode;
					}
				}
			}
	};
}
