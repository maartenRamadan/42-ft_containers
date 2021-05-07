#pragma once

namespace ft
{
	template <typename T>
	class Node
	{
		public:
			T		data;
			Node*	next;
			Node*	prev;

			explicit Node(const T& d = T(), Node* nxt = NULL, Node* prev = NULL)
				: data(d), next(nxt), prev(prev) {}

			~Node() {}

			Node*	getNext() {
				Node* node = this;
				node = node->next;
				return node;
			}

			Node*	getPrev() {
				Node* node = this;
				node = node->prev;
				return node;
			}
	};
}
