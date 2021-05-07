#pragma once

namespace ft
{
	template <typename T>
	class mapNode
	{
		public:
			T				data;
			mapNode*		left;
			mapNode*		right;
			mapNode*		parent;

			explicit mapNode(const T& data = T())
			  : data(data), left(NULL), right(NULL), parent(NULL) {}

       		mapNode(const mapNode &x)
			   : parent(x.parent), left(x.left), right(x.right), data(x.data) {}

			~mapNode() {}

			mapNode&	operator=(const mapNode& rhs) {
				data = rhs->data;
				left = rhs->left;
				right = rhs->right;
				parent = rhs->parent;
				return *this;
			}

			mapNode*	getNext() {
				mapNode* next = this;

				if (next->right)
				{
					next = next->right;
					while (next->left)
						next = next->left;
				}
				else if (next == next->parent->left)
					next = next->parent;
				else if (next == next->parent->right)
				{
					while (next != next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				return next;
			}

			mapNode*	getPrev() {
				mapNode* prev = this;

				if (prev->left)
				{
					prev = prev->left;
					while (prev->right)
						prev = prev->right;
				}
				else if (prev == prev->parent->right)
					prev = prev->parent;
				else if (prev == prev->parent->left)
				{
					while (prev != prev->parent->right)
						prev = prev->parent;
					prev = prev->parent;
				}
				return prev;
			}
	};
}
