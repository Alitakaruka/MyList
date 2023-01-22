#pragma once
#include "Category.cpp"

template <typename T>
class Element
{
public:
	Element(T value);
	Element(T value,  Element<T>* next,  Element<T>* previous);
	~Element();
	Element<T>* get_next() {
		return this->m_next;
	}
	Element<T>* get_previous() {
		return this->m_previous;
	}
	T* get_value() {
		return &this->value;
	}
	void set_previous(Element<T>* element);
	void set_next(Element<T>* element);

private:
	T value;
	Element<T>* m_next = nullptr;
	Element<T>* m_previous = nullptr;
};

template<typename T>
Element<T>::Element(T value)
{
		this->value = value;
}
template<typename T>
Element<T>::Element(T value,  Element<T>* next,  Element<T>* previous) {
	this->m_next = next;
	this->m_previous = previous;
	this->value = value;
}

template<typename T>
Element<T>::~Element()
{
}

template<typename T>
void Element<T>::set_previous(Element<T>* element)
{
	this->m_previous = element;
}

template<typename T>
void Element<T>::set_next(Element<T>* element)
{
	this->m_next = element;
}
