//
// Created by nicol on 15/12/2020.
//


#include "../include/collection/stack.h"

template <typename T>
void collection::stack<T>::empty(){
	for(int i = 0; i < this->size_; ++i)
	{
		delete this->data_[i];
	}
	delete[] this->data_;
}

template <typename T>
bool collection::stack<T>::isFull() const
{
	if(this->data_[this->size_-1] != nullptr)
		return true;
	
	return false;
}


template <typename T>
int collection::stack<T>::count() const{
	
	if(isFull())
		return this->size_;
	
	int i = 0;
	while(i < this->size_ && this->data_[i] != nullptr) //appena trovo buco da quello in poi tutti vuoti
	{
		i++;
	}
	return i;
}


template <typename T>
void collection::stack<T>::addElement(const T &element, int pos)
{
    //aggiungo all'inizio
	if(!isFull())
	{
        this->data_[pos] = &element; // pos è 0
		for(int i = count(); i > 1; --i)
		{
            this->data_[i] = this->data_[i-1];
		}
	}
	else
		resize(pos);
}


template <typename T>
T collection::stack<T>::removeElement(int pos){
	
	assert(pos == 0);
	
	T* elementErased;
	elementErased = this->data_[pos];
	for(int i = 0; i < this->size_-1;++i)
	{
        this->data_[i] = this->data_[i+1];
	}
    this->data_[this->size_-1] = nullptr;
	
	return *elementErased;
}







