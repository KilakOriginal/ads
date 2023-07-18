#include <tuple>
#include "Ds.cpp"

namespace fn {
	typedef std::tuple<std::string, short, std::vector<std::string>> call_tuple;
	typedef Stack<call_tuple> call_stack;

	std::size_t fibonacci(int sequence_number) {
		std::size_t n = 0;
		std::size_t m = 1;

		for (int i = 1; i < sequence_number; i++) {
			m = n+m;
			n = m-n;
		}
		return n;
	}
}
