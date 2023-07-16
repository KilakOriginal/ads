#include "../Header Files/Ds.hpp"
#include <stdexcept>

/*
 * ====================
 * Stack
 * ====================
 */

template<typename T>
Stack<T>::Stack() 
: is_empty(true), elements(std::vector<T>()) { }

template<typename T>
Stack<T>::Stack(std::initializer_list<T> elements)
: is_empty(true), elements(std::vector<T>()) {

	for (T element : elements) {
		this->push(element);
	}
}

template<typename T>
Stack<T>::~Stack() { }

template<typename T>
void Stack<T>::push(T element) {

	this->elements.push_back(element);
	this->is_empty = false;
}

template<typename T>
T Stack<T>::top() {

	return this->elements[this->elements.size() - 1];
}

template<typename T>
T Stack<T>::pop() {

	T element = this->top();
	this->elements.pop_back();
	this->is_empty = this->elements.empty();
	return element;
}

template<typename T>
int Stack<T>::size() { return this->elements.size(); }

template<typename T>
bool Stack<T>::empty() {

	return this->elements.empty();
}

template<typename T>
std::string Stack<T>::to_string() {

	std::stringstream s;
	std::copy(this->elements.begin(), this->elements.end(), std::ostream_iterator<T>(s, std::string(", ").c_str()));
	std::string output = s.str();
	return std::string("[" + output.substr(0, output.size()-2) + "]");
}

/*
 * ====================
 * Linked List
 * ====================
 */

template<typename T>
LinkedList<T>::LinkedList() 
: head(new Node<T>()), tail(new Node<T>()), current_size(0) { }

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> elements)
: head(new Node<T>()), tail(new Node<T>()), current_size(0) {

	for (T element : elements) {
		this->append(element);
	}
}

template<typename T>
LinkedList<T>::~LinkedList<T>() {

	Node<T>* current_node = this->head;
	for (int i = 0; i < this->current_size; i++) {

		Node<T>* temp = current_node->get_next();
		delete current_node;
		current_node = temp;
	}
}

template<typename T>
void LinkedList<T>::append(T element) {

	Node<T>* new_node = new Node<T>(element);
	Node<T>* current_node = this->head;

	while (current_node->get_next() != nullptr) {
		current_node = current_node->get_next();
	}

	new_node->set_previous(current_node);
	current_node->set_next(new_node);
	this->tail->set_previous(new_node);
	this->current_size++;
}

template<typename T>
T LinkedList<T>::pop_back() {

	if (!this->current_size) { throw std::invalid_argument("pop_back() not defined for empty list."); }

	T value = this->tail->get_previous()->get_data();
	Node<T>* previous_node = this->tail->get_previous()->get_previous() == this->head ? nullptr:this->tail->get_previous()->get_previous();
	delete this->tail->get_previous();
	this->tail->set_previous(previous_node);
	this->current_size--;

	return value;
}

template<typename T>
T LinkedList<T>::pop_front() {

	if (!this->current_size) { throw std::invalid_argument("pop_front() not defined for empty list."); }

	T value = this->head->get_next()->get_data();
	Node<T>* next_node = this->head->get_next()->get_next() == this->tail ? nullptr:this->head->get_next()->get_next();
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
T LinkedList<T>::get(int index) {
	
	if (index >= current_size) { throw std::invalid_argument("Index Out Of Range."); }

	Node<T>* current_node = this->head->get_next();
	for (int i = 0; i < index; i++) {
		current_node = current_node->get_next();
	}

	return current_node->get_data();
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

	s << "[";
	for (int i = 1; i < this->current_size; i++) {
		current_node = current_node->get_next();
		s << current_node->get_data();
		s << ", ";
	}
	s << this->tail->get_previous()->get_data();
	s << "]";

	return s.str();
}

template<typename T>
bool LinkedList<T>::empty() { return this->current_size > 0 ? true:false; }

