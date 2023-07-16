#include<vector>
#include<iostream>

template<typename T>
void swap(std::vector<T>& array, int i, int j) {
	if (i != j) {
		array[i] += array[j];
		array[j] = array[i] - array[j];
		array[i] -= array[j];
	}
}

template<typename T>
std::vector<T> insertion_sort(std::vector<T> const& array) {
	if (array.size() < 2) { return std::vector<T>(array); }

	std::vector<T> result(array);
	int position;
	T current;

	for (int i = 1; i < result.size(); i++) {
		current = result[i];
		position = i - 1;

		while (position >= 0 && result[position] > current) {
			result[position + 1] = result[position];
			position--;
		}
		result[position + 1] = current;
	}

	return result;
}

template<typename T>
std::vector<T> selection_sort(std::vector<T> const& array) {
	if (array.size() < 2) { return std::vector<T>(array); }

	std::vector<T> result(array);

	for (int i = 0; i < result.size(); i++) {
		for (int j = i + 1; j < result.size(); j++) {
			if (result[j] < result[i]) {
				result[j] += result[i];
				result[i] = result[j] - result[i];
				result[j] -= result[i];
			}
		}
	}

	return result;
}

namespace qs {
	template<typename T>
	int partition(std::vector<T>& array, int start, int end) {
		T pivot = array[end];
		int i = start - 1;

		for (int j = start; j < end; j++) {
			if (array[j] < pivot) {
				i++;
				swap(array, i, j);
			}
		}
		swap(array, i + 1, end);
		return i + 1;
	}

	template<typename T>
	void sort(std::vector<T>& array, int start, int end) {
		if (start < end) {
			int p = partition(array, start, end);
			sort(array, start, p - 1);
			sort(array, p + 1, end);
		}
	}
}

template<typename T>
std::vector<T> quick_sort(std::vector<T> const& array) {
	if (array.size() < 2) { return array; }
	std::vector<T> result(array);
	qs::sort(result, 0, result.size() - 1);
	return result;
}
