#pragma once

#include <vector>

namespace Nino {
	template<typename C1, typename C2>
	auto zip(const C1& c1, const C2& c2) {
		std::vector<std::pair<C1::value_type, C2::value_type> > result;
		auto i1 = std::begin(c1);
		auto i2 = std::begin(c2);
		for (; i1 != std::end(c1) && i2 != std::end(c2); ++i1, ++i2) {
			result.push_back({ *i1, *i2 });
		}
		return result;
	}
}
