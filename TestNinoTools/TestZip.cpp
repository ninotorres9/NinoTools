#include "pch.h"
#include "Zip.h"

#include <vector>

TEST(TestZip, TestSameType) {
	std::vector<int> vec_1 = { 1, 2, 3 };
	std::vector<int> vec_2 = { 5, 4, 3 };
	auto result = Nino::zip(vec_1, vec_2);
	std::vector< std::pair<int, int> > answer = {
		{1, 5}, {2, 4}, {3, 3}
	};

	EXPECT_EQ(result, answer);
}
