#ifndef DS_hpp
#define DS_hpp

#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <initializer_list>
#include <cstring>
#include <stdexcept>

template<typename T>
class Stack {

private:
	// Fields
	bool is_empty;
	int max_size;
	int current_size;
	T* elements;
public:
	// Constructors and Destructors
	Stack() noexcept; // Initialise empty stack
	Stack(std::initializer_list<T>); // Initialise stack and push variable number of arguments
	~Stack(); // Free-up memory
	
	// Operations
	void push(T); // Add element to top of stack

	// Getter function
	T top(); // Get first element on stack
	T pop(); // Get first element on stack and remove it
	int size(); // Get the stack's current size
	std::string to_string(); // String representation of the stack
	int debug_get_max_size() { return this->max_size; }

	// Test functions
	bool empty(); // Returns true if stack is empty
};

template<typename T>
class LinkedList {

// Internal classes
public:
	// Nodes for storing data
	template<typename D>
	class Node {

	private:
		// Fields
		D data;
		Node<D>* next;
		Node<D>* previous;
	public:
		// Constructors / Destructors
		Node() noexcept
		: next(nullptr), previous(nullptr) { }
		Node(D data) noexcept
		: data(data), next(nullptr), previous(nullptr) { }
		Node(Node<D>* node) noexcept
		: data(node->data), next(nullptr), previous(nullptr) { }
		~Node() { }

		// Getter functions
		Node<D>* get_next() { return this->next; }
		Node<D>* get_previous() { return this->previous; }
		D& get_data() { return this->data; }
		
		// Setter functions
		void set_next(Node<D>* next) { this->next = next; }
		void set_previous(Node<D>* previous) { this->previous = previous; }
		void set_data(D data) { this->data = data; }

	};

	// Iterator class for convenience
	class Iterator {

	private:
		Node<T>* current_node;
	public:
		Iterator() noexcept
		: current_node(head->get_next()) { }
		Iterator(Node<T>* node) noexcept
		: current_node(node) { }

		// Prefix ++
		Iterator& operator++() { 

			if (this->current_node) { this->current_node = this->current_node->get_next(); }
			return *this;
		}
		// Postfix ++
		Iterator operator++(int) {

			Iterator iterator = *this;
			++*this;
			return iterator;
		}
		// Prefix --
		Iterator& operator--() { 

			if (this->current_node) { this->current_node = this->current_node->previous; }
			return *this;
		}
		// Postfix --
		Iterator operator--(int) {

			Iterator iterator = *this;
			--*this;
			return iterator;
		}
		Iterator& operator=(Node<T>* node) { 
			
			this->current_node = node;
			return *this;
		}
		bool operator!=(const Iterator& iterator) { 
			
			return this->current_node != iterator.current_node;
		}
		bool operator==(const Iterator& iterator) { 
			
			return this->current_node == iterator.current_node;
		}
		T operator*() { return this->current_node->get_data(); }
		Node<T>* operator->() { return this->current_node; }
	};
	private:
		// Fields
		Node<T>* head;
		Node<T>* tail;
		int current_size;

	public:
		// Constructors / Destructors
		LinkedList() noexcept;
		LinkedList(std::initializer_list<T>);
		~LinkedList();

		// Operations
		void append(T);
		T pop_back();
		T pop_front();

		// Getter functions
		int size();
		T first();
		T last();
		std::string to_string();

		// Test functions
		bool empty();

		// Operators and Utility
		T& operator[](int);
		//LinkedList operator+=(const LinkedList&);

		Iterator begin() { return Iterator(this->head->get_next()); }
		Iterator end() { return Iterator(nullptr); }
};

#endif
