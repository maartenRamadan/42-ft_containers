#pragma once

#include <type_traits>
#include <algorithm>

namespace ft
{
	struct output_iterator_tag{};
	struct input_iterator_tag{};
	struct forward_iterator_tag : public input_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};

	template<bool B, class T = void>
	struct enable_if { typedef T type; };
	
	template<class T>
	struct enable_if<false, T> {};

	template<typename T, typename C = typename T::iterator_category>
	struct is_input_iterator {
		typedef char yes[1];
		typedef char no[2];

		static yes& test(std::input_iterator_tag);
		static no& test(...);

		static const bool value = (sizeof(test(C())) == sizeof(yes));
	};
}
