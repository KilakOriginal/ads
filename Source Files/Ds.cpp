#include "../Header Files/Ds.hpp"

/*
 * ====================
 * Stack
 * ====================
 */

template<typename T>
Stack<T>::Stack() noexcept
: max_size(1), current_size(0), elements(new T[1]) { }

template<typename T>
Stack<T>::Stack(std::initializer_list<T> elements)
: max_size(pow(2, ceil(log2(elements.size())))), elements(new T[this->max_size]) {

	this->current_size = elements.size();
	for (int i = 0; i < this->current_size; i++) {
		this->elements[i] = elements[i];
	}
}

template<typename T>
Stack<T>::~Stack() {
	delete[] this->elements;
}

template<typename T>
void Stack<T>::push(T element) {

	if (this->current_size >= this->max_size) {
		T* new_array = new T[this->max_size*2];
		memcpy(new_array, this->elements, this->max_size*2*sizeof(T));
		delete[] this->elements;
		this->elements = new_array;
		this->max_size *= 2;
	}

	this->elements[current_size] = element;
	this->current_size ++;
}

template<typename T>
T Stack<T>::top() {

	return this->elements[current_size-1];
}

template<typename T>
T Stack<T>::pop() {

	T return_value = this->elements[this->current_size-1];
	if (this->current_size <= this->max_size * 0.25) {
		T* new_array = new T[this->max_size/2];
		memcpy(new_array, this->elements, this->max_size*2*sizeof(T));
		delete[] this->elements;
		this->elements = new_array;
		this->max_size/=2;
	}

	this->current_size--;

	return return_value;
}

template<typename T>
int Stack<T>::size() { return this->current_size; }

template<typename T>
bool Stack<T>::empty() {

	return this->current_size == 0 ? true:false;
}

template<typename T>
std::string Stack<T>::to_string() {

	std::stringstream s;
	for (int i = 0; i < this->current_size; i++) {
		s << this->elements[i];
		s << ", ";
	}
	std::string output = s.str();
	return std::string("[" + output.substr(0, output.size()-2) + "]");
}

/*
 * ====================
 * Linked List
 * ====================
 */

template<typename T>
LinkedList<T>::LinkedList() noexcept
: head(new Node<T>()), tail(new Node<T>()), current_size(0) {
	this->head->set_next(this->tail);
	this->tail->set_previous(this->head);
}

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> elements)
: head(new Node<T>()), tail(new Node<T>()), current_size(0) {

	this->head->set_next(this->tail);
	this->tail->set_previous(this->head);

	for (T element : elements) {
		this->append(element);
	}
}

template<typename T>
LinkedList<T>::~LinkedList<T>() {

	Node<T>* current_node = this->head;
	for (int i = -1; i < this->current_size; i++) {

		Node<T>* temp = current_node->get_next();
		delete current_node;
		current_node = temp;
	} delete this->tail;
}

template<typename T>
void LinkedList<T>::append(T element) {

	Node<T>* new_node = new Node<T>(element);
	Node<T>* current_node = this->tail->get_previous();

	new_node->set_previous(current_node);
	current_node->set_next(new_node);
	this->tail->set_previous(new_node);
	this->current_size++;
}

template<typename T>
T LinkedList<T>::pop_back() {

	if (!this->current_size) { throw std::invalid_argument("pop_back() not defined for empty list."); }

	T value = this->tail->get_previous()->get_data();
	Node<T>* previous_node = this->tail->get_previous()->get_previous();
	delete this->tail->get_previous();
	this->tail->set_previous(previous_node);
	this->current_size--;

	return value;
}

template<typename T>
T LinkedList<T>::pop_front() {

	if (!this->current_size) { throw std::invalid_argument("pop_front() not defined for empty list."); }

	T value = this->head->get_next()->get_data();
	Node<T>* next_node = this->head->get_next()->get_next();
	delete this->head->get_next();
	this->head->set_next(next_node);
	this->current_size--;

	return value;
}

template<typename T>
int LinkedList<T>::size() {
	return this->current_size;
}

template<typename T>
T LinkedList<T>::first() { 

	if (!current_size) { throw std::invalid_argument("No elements in list."); }

	return this->head->get_next()->get_data(); 
}

template<typename T>
T LinkedList<T>::last() {

	if (!current_size) { throw std::invalid_argument("No elements in list."); }

	return this->tail->get_previous()->get_data();
}

template<typename T>
std::string LinkedList<T>::to_string() {

	std::ostringstream s;
	Node<T>* current_node = this->head;

	for (int i = 0; i < this->current_size; i++) {
		current_node = current_node->get_next();
		s << current_node->get_data();
		s << ", ";
	}
	
	std::string output = s.str();

	return std::string("[" + output.substr(0, output.size()-2) + "]");
}

template<typename T>
bool LinkedList<T>::empty() { return this->current_size > 0 ? true:false; }

template<typename T>
T& LinkedList<T>::operator[](int index) {

	if (index >= current_size) { throw std::invalid_argument("Index Out Of Range."); }

	Node<T>* current_node = this->head->get_next();
	for (int i = 0; i < index; i++) {
		current_node = current_node->get_next();
	}

	return current_node->get_data();
}

/*template<typename T>
LinkedList<T> LinkedList<T>::operator+=(const LinkedList& other) {

	Node<T>* current_node = other.head->get_next();
	Node<T>* end = this->tail->get_previous();

	for (int i = 0; i < other.current_size; i++) {
		Node<T>* new_node = new Node<T>(current_node);
		new_node->set_previous(end);
		end->set_next(new_node);
		current_node = current_node->get_next();
		end = end->get_next();
	}

	this->current_size += other.current_size;
}*/
