#pragma once
#include<memory>
#include<stdexcept>


template <class T, class A = std::allocator<T>>
class Vector
{
private:
	size_t m_size;
	size_t maxSize;
	size_t typeSize;
	T* start;
	A alloc;
	void reallocate(const size_t& newSize);

public:
	Vector();
	Vector(const size_t& size);
	Vector(const Vector<T>& vec);
	~Vector();
	void push_back(const T& item);
	void pop_back();
	T& front();
	T& back();
	T* data();
	const T* data() const;
	bool empty() const;
	A get_allocator() const;
	void reserve(const size_t& n);
	void resize(const size_t& n, const T& value = NULL);
	void shrink_to_fit();
	size_t capacity() const;
	size_t size() const;
	void swap(Vector& vec);

	T& operator [] (const size_t& pos) {
		if (pos >= m_size) throw std::out_of_range("Index out of range!");
		return *(start + pos);
	}

	Vector& operator = (const Vector& vec) {
		typeSize = vec.typeSize;
		maxSize = vec.maxSize;
		m_size = vec.m_size;
		start = alloc.allocate(maxSize * typeSize);
		memcpy(start, vec.start, m_size * typeSize);
		return *this;
	}
};

template <class T, class A>
void Vector<T, A>::reallocate(const size_t& newSize) {
	size_t oldSize_Bytes = maxSize * typeSize;
	maxSize = newSize;
	T* oldStart = start;
	T* newStart = alloc.allocate(newSize * typeSize);
	memcpy(newStart, start, m_size * typeSize);
	start = newStart;
	alloc.deallocate(oldStart, oldSize_Bytes);
}

template <class T, class A>
Vector<T, A>::Vector() {
	typeSize = sizeof(T);
	maxSize = 1;
	m_size = 0;
	start = alloc.allocate(maxSize * typeSize);
}

template <class T, class A>
Vector<T, A>::Vector(const size_t& size_) {
	typeSize = sizeof(T);
	maxSize = size_;
	m_size = 0;
	start = alloc.allocate(maxSize * typeSize);
}

template <class T, class A>
Vector<T, A>::Vector(const Vector<T>& vec) {
	*this = vec;
}

template <class T, class A>
Vector<T, A>::~Vector() {
	alloc.deallocate(start, maxSize * typeSize);
}

template <class T, class A>
void Vector<T, A>::push_back(const T& item) {
	if (m_size == maxSize) {
		reallocate(maxSize << 1);
	}
	*(start + m_size) = item;
	m_size++;
}

template <class T, class A>
void Vector<T, A>::pop_back() {
	m_size--;
}

template <class T, class A>
T& Vector<T, A>::front() {
	return *start;
}

template <class T, class A>
T& Vector<T, A>::back() {
	return *(start + m_size - 1);
}

template <class T, class A>
T* Vector<T, A>::data() {
	return start;
}

template <class T, class A>
const T* Vector<T, A>::data() const {
	return start;
}

template <class T, class A>
bool Vector<T, A>::empty() const {
	return m_size > 0 ? true : false;
}

template <class T, class A>
A Vector<T, A>::get_allocator() const {
	return alloc;
}

template <class T, class A>
void Vector<T, A>::reserve(const size_t& n) {
	if (m_size == 0) start = alloc.allocate(n * typeSize);
	else {
		reallocate(n);
	}
}

// TODO
template <class T, class A>
void Vector<T, A>::resize(const size_t& n, const T& value) {
	if (n == m_size) return;
	if (n < m_size) {

	}
}

template <class T, class A>
void Vector<T, A>::shrink_to_fit() {
	reallocate(m_size);
}

template <class T, class A>
size_t Vector<T, A>::capacity() const{
	return maxSize;
}

template <class T, class A>
size_t Vector<T, A>::size() const {
	return m_size;
}

template <class T, class A>
void Vector<T, A>::swap(Vector& vec) {
	Vector<T> temp = *this;
	*this = vec;
	vec = temp;
}