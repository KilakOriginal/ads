#include <iostream>
#include <vector>
#include "sorting.cpp"
#include "Ds.cpp"

int main(int argc, char** argv) {
	/*
	std::vector<int> myVector{12, 32, 5, 435, 45, 1, 34};
	std::vector<int> mySortedVector = quick_sort(myVector);

	printf("Original vector:\t");
	for (int i = 0; i < myVector.size(); i++) {
		printf("%d ", myVector[i]);
	}
	printf("\r\n");

	printf("Sorted vector:\t\t");
	for (int i = 0; i < mySortedVector.size(); i++) {
		printf("%d ", mySortedVector[i]);
	}
	printf("\r\n");
	*/

	Stack<int> stack;
	stack.push(23);
	std::cout << stack.to_string() << " " << stack.debug_get_max_size() << std::endl;
	stack.push(19);
	std::cout << stack.to_string() << " " << stack.debug_get_max_size() << std::endl;
	stack.pop();
	std::cout << stack.to_string() << " " << stack.debug_get_max_size() << std::endl;
	stack.push(78);
	std::cout << stack.to_string() << " " << stack.debug_get_max_size() << std::endl;

	/*
	LinkedList<int> list;
	list.append(56);
	list.append(2);
	list.append(12);

	std::cout << list.to_string() << std::endl;

	list.pop_back();
	list.append(80);

	std::cout << list.to_string() << std::endl;
	*/

	return 0;
}

