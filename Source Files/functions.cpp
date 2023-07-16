#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include "Ds.cpp"

namespace fn {
	typedef std::vector<std::string> args;
	typedef std::tuple<std::string, short, args> call_tuple;
	typedef Stack<call_tuple> call_stack;

	int fibonacci(uint n) {
		call_stack stack;
		stack.push(call_tuple("fibonacci", 0, args(n)));
		int result = -1;
		while (!stack.empty()) {
			std::string func; short margs; args fargs;  
			std::tie(func, margs, fargs) = stack.pop();

			if (func == "fibonacci") {
				//...
			}
			else if (func == "+") {
				//...
			}
			else if (func == "return") {
				//...
			}
			else { throw std::invalid_argument("Undefined function."); }

			if (result >= 0 and !stack.empty()) {
				//...
			}
		}
		return result;
	}
}
