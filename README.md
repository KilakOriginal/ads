# ads
## About this project
A collection of usefull data structures, algorithms and various related functions
## Data Structures
### Stack
A `Stack` is a LIFO data structure similar to a vector, that doesn't allow indexing.

#### Methods:
* `Stack()` initialises an empty stack.
* `Stack(args)` initialises a stack with the argument list provided.
* `~Stack()` deletes the stack.
* `push(data)` pushes an element onto the stack.
* `top()` returns the value of the stack's topmost element.
* `pop()` removes the topmost element from the stack and returns its value.
* `size()` returns the size of the stack.
* `to_string()` returns a string `[element_1, ..., element_n]`.
* `empty()` returns `true` if the stack is empty, `false` otherwise.

### Linked List
A `LinkedList` in this instance, is a double linked list.

#### Methods:
* `LinkedList()` initialises an empty linked list.
* `LinkedList(args)` initialises a linked list with the argument list provided.
* `~LinkedList()` deletes the linked list and all of its nodes.
* `append(data)` appends an element to the list.
* `pop_back()` removes the list's last element and returns its value.
* `pop_front()` removes the list's first element and returns its value.
* `size()` returns the size of the list.
* `first()` returns the data contained within the first node of the list.
* `last()` returns the data contained within the last node of the list.
* `empty()` returns `true` if the list is empty, `false` otherwise.
* `[i]` access the i-th value in the list.
* `begin()` returns the `LinkedList<T>::Iterator` for the first element of the the list.
* `end()` returns the `LinkedList<T>::Iterator` past the last element of the the list.

## Algorithms
### Insertion Sort
`std::vector<T> insertion_sort(std::vector<T> const& array)` returns a sorted copy of the input vector.

### Slection Sort
`std::vector<T> selection_sort(std::vector<T> const& array)` returns a sorted copy of the input vector.

### Quick Sort
`quick_sort(std::vector<T> const& array)` returns a sorted copy of the input vector.

## Miscellaneous Functions
### Fibonacci
`fibonacci(std::size_t n)` calculates and returns the n-th fibonacci number.
