#pragma once
template <class T>
class StackC
{
	T* mem;
	int MaxSize;
	int ind;
public:
	StackC(int _MaxSize = 10);
	~StackC();
	bool IsEmpty();
	bool IsFull();
	void push(T val);
	T pop();
};
template <class T>
StackC<T>::StackC(int _MaxSize) :MaxSize(_MaxSize) {
	mem = new T[MaxSize];
	ind = -1;
}
template <class T>
StackC<T>::~StackC() {
	delete[] mem;
}
template <class T>
bool StackC<T>::IsEmpty() {
	return ind < 0;
}
template <class T>
bool StackC<T>::IsFull() {
	return ind >= MaxSize - 1;
}
template <class T>
void StackC<T>::push(T val) {
	if (IsFull()) throw - 1;
	ind = ind + 1;
	mem[ind] = val;
}
template <class T>
T StackC<T>::pop() {
	if (IsEmpty()) throw - 2;
	T val = mem[ind];
	ind--;
	return val;
}