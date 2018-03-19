#include "pch.h"
#include "Linq.h"

using namespace Nino;

TEST(TestLinq, TestSequence) {
	std::vector<int> container = { 1, 2, 3, 4, 5 };
	Sequence< std::vector<int> > sequence(container);

	 EXPECT_EQ(sequence.toVector(), container);
}

TEST(TestLinq, TestFrom) {
	std::vector<int> container = { 1, 2, 3, 4, 5 };
	auto sequence = from(container);

	EXPECT_EQ(sequence.toVector(), container);
}

TEST(TestLinq, TestWhere) {
	std::vector<int> container = { 1, 2, 3, 4, 5 };
	auto sequence = from(container)
		.where([](int x) {return x % 2 == 0; });

	std::vector<int> correct = { 2, 4 };
	EXPECT_EQ(sequence.toVector(), correct);
}

TEST(TestLinq, TestSelect) {
	std::vector<int> container = { 1, 2, 3, 4, 5, 6 };
	auto sequence = from(container)
		.where([](int x) {return x % 2 == 0; })
		.select([](int x) {return x * x; });

	std::vector<int> correct = { 4, 16, 36 };
	EXPECT_EQ(sequence.toVector(), correct);
}

TEST(TestLinq, TestSum) {
	std::vector<int> container = { 1, 2, 3, 4, 5, 6 };
	int result = from(container)
		.where([](int x) {return x % 2 == 0; })
		.select([](int x) {return x * x; })
		.sum();

	EXPECT_EQ(result, 56);
}

TEST(TestLinq, TestOrderby) {
	std::vector<int> container = { 1, 9, 25, 49, 81 };
	auto sequence = from(container)
		.ordBy([](int x) {return x % 10; });

	std::vector<int> correct = { 1, 81, 25, 9, 49 };
	EXPECT_EQ(sequence.toVector(), correct);
}
