#include <array>
#include <chrono>
#include <iostream>

constexpr std::size_t N = 149'795;

constexpr std::array<int, N> makeArray() {
	std::array<int, N> arr;
	for (std::size_t i = 0; i < N; ++i) {
		arr[i] = 2;
	}
	return arr;
}

constexpr uint64_t blaze(const std::array<int, N>& d) {
	uint64_t acc = 0;
	for (const size_t i : d) {
		acc += i;
	}
	return acc;
}

constexpr uint64_t result = blaze(makeArray());

int main()
{
	const auto t1 = std::chrono::steady_clock::now();
	std::cout << result << "\n";
	const auto t2 = std::chrono::steady_clock::now();
	std::cout << "Elapsed microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << "\n";

	return 0;
}
