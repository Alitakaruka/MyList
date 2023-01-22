#include "Element.cpp"
#include "Category.cpp"
#include <iostream>

enum IteratorPoint
{
	start,
	end
};
//template<typename T>
//class MLIterarot {
//public:
//	MLIterarot() {}
//	MLIterarot(int size) {
//		capacity = size + 2;
//		elements_ptrs = new Element<T>[capacity];
//	};
//	~MLIterarot() {
//		delete[] elements_ptrs;
//	}
//	T* begin() {
//		return elements_ptrs;
//	}
//	T* end() {
//		return elements_ptrs + size;
//	}
//	T* get_iterator(IteratorPoint point) {
//		if (point == IteratorPoint::start) {
//			return elements_ptrs[0];
//		}
//		return elements_ptrs[size];
//	}
//	void add(Element<T> element) {
//		if (capacity == size) {
//			Element<T> tempArr = copyArray(elements_ptrs);
//			delete elements_ptrs;
//			elements_ptrs = tempArr;
//			elements_ptrs[size + 1] = element;
//			size++;
//		}
//		else {
//			elements_ptrs[size + 1] = element;
//			size++;
//		}
//	}
//	T* getElement(int index = 0) {
//		return elements_ptrs[index];
//	}
//	T& operator *() {
//		return *(elements_ptrs)->value;
//	}
//	bool operator !=(MLIterarot<T>* obj) {
//		return this != obj;
//	}
//	MLIterarot<T>* operator ++() {
//		return this + 1;
//	}
//	void clear() {
//		delete elements_ptrs
//	}
//
//private:
//
//	Element<T>*copyArray(Element<T> arrCopy[]) {
//		Element<T>* newArr = new Element<T>[capacity + 3];
//		for (int i = 0; i != capacity; i++) {
//			newArr[i] = arrCopy[i];
//		}
//		return newArr;
//	}
//	Element<T>* elements_ptrs;
//	int size = 0;
//	int capacity = 0;
//	T value;
//};

template <typename T>
class MList
{
public:
	MList(){}

	~MList()
	{
		delete_all_elements();
	}
	T* begin() {
		return iterators->getElement();
	}
	T* end() {
		return iterators->getElement(m_size-1);
	}

	int size() {
		return m_size;
	}
	bool is_empty() {
		return m_size == 0;
	}

	void assign(std::initializer_list<T> list) {

	}

	void assign(T size, T value) {

	}
	
	void assign(T* begin, T* end) {
		delete_all_elements();
		iterators->clear();
		for (auto i = begin; i < end; i++) {

		}
	}
	#pragma region AddElements
	//работает
	void push_back(T element){
		if (this->m_size == 0) {
			this->m_last = new Element<T>(element);
			this->m_first = this->m_last;
			m_size++;
			return;
		}
		Element<T>* newElement = new Element<T>(element);
		newElement->set_previous(this->m_first);
		this->m_last->set_next(newElement);
		this->m_last = newElement;
		m_size++;
	}
	//работает
	void push_front(T element) {
		if (this->m_size == 0) {
			this->m_last = new Element<T>(element);
			this->m_first = this->m_last;
			m_size++;
			return;
		}
		Element<T>* newElement = new Element<T>(element);
		newElement->set_next(this->m_first);
 		this->m_first->set_previous(newElement);
		this->m_first = newElement;
		m_size++;
	}
	//–аботает
	void emplace(T element, int index = 0){
		if (index > m_size) {
			push_back(element);
			return;
		}
		if (index == 0) {
			push_front(element);
			return;
		}
		Element<T>* newElement = new Element<T>(element);
		Element<T>* nowElement = get_element(index);
		Element<T>* previousElement = nowElement->get_previous();
		previousElement->set_next(newElement);
		newElement->set_previous(previousElement);
		newElement->set_next(nowElement);
		nowElement->set_previous(newElement);
		m_size++;
		
	}
	#pragma endregion

	#pragma region deleteElements
	void pop_back(){
		Element<T> nowElement = this->m_last->get_previous();
		delete this->m_last;
		this->m_last = nowElement;
	}
	void pop_front(){
		Element<T> nowElement = this->m_first->get_previous();
		delete this->m_first;
		this->m_last = nowElement;
	}
	void clear() {
		delete_all_elements();
	}
	#pragma endregion

	#pragma region operators
	//работает
	T* operator [] (int index) {
		auto nowElement = get_element(index);
		return nowElement->get_value();
	}
	bool operator !=(const Element<T>& element) {
		return true;
	}
	#pragma endregion

private:
	
#pragma region deleteElements
	void delete_all_elements() {
		for (int i = 0; i < m_size; i++) {
			Element<T>* nowElement = m_first;
			m_first = nowElement->get_next();
			delete nowElement;
		}
	}
	Element<T>* get_element(int index) {
		if (index > m_size) {
			throw "index more size";
		}
		if (index == 0) {
			return m_first;
		}
		Element<T>* nowElement = m_last;
		if (m_size / 2 < index) {
			for (int i = m_size; i != index; i--) {
				nowElement = nowElement->get_previous();
			}
		}
		else {
			for (int i = 0; i != index; i++) {
				nowElement = nowElement->get_next();
			}
		}
		return nowElement;
	}
#pragma endregion

	int m_size = 0;
	Element<T>* m_last = nullptr;
	Element<T>* m_first = nullptr;

};
