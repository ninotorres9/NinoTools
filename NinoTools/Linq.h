#pragma once

#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

namespace Nino {

	template<typename ContainerType>
	class Sequence {
	public:
		Sequence(const ContainerType& container) : container_(container) { ; }
		~Sequence() { ; }
	public:
		template<typename FunctionType>
		auto where(FunctionType condition) {
			std::vector<ContainerType::value_type> result(std::begin(container_), std::end(container_));
			result.erase(
				std::remove_if(result.begin(), result.end(), 
					std::not1(std::function<bool(ContainerType::value_type)>(condition))),
				result.end()
			);
			return Sequence<ContainerType>(result);
		}
		template<typename FunctionType>
		auto select(FunctionType function) {
			std::vector<ContainerType::value_type> result(std::begin(container_), std::end(container_));
			for (size_t i = 0; i != result.size(); ++i) {
				result[i] = function(result[i]);
			}
			return Sequence<ContainerType>(result);
		}
		template<typename FunctionType>
		auto ordBy(FunctionType function) {
			std::vector<ContainerType::value_type> result(std::begin(container_), std::end(container_));
			std::sort(std::begin(result), std::end(result),
				[function](int lhs, int rhs) {return function(lhs) < function(rhs); });
			return Sequence<ContainerType>(result);
		}
		auto sum() {
			return std::accumulate(
				std::begin(container_) + 1,
				std::end(container_),
				*std::begin(container_));
		}
	public:
		auto toVector() {
			std::vector<ContainerType::value_type> result;
			for (auto iter = std::begin(container_); iter != std::end(container_); ++iter) {
				result.push_back(*iter);
			}
			return result;
		}
	private:
		ContainerType container_;
	};

	template<typename ContainerType>
	auto from(const ContainerType& container) {
		return Sequence<ContainerType> (container);
	}
}
