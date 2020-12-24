//
// Created by nicol on 15/12/2020.
//

#include "../include/collection/set.h"

template <typename T>
void collection::set<T>::empty(){
	for(int i = 0; i < this->size_; ++i)
	{
		delete this->data_[i];
	}
	delete[] this->data_;
}



template <typename T>
bool collection::set<T>::checkElement(const T& element) const{
	bool flag = false;
	if(element == nullptr)
		return false;
	for(int i = 0; i < this->size_ && !flag; ++i)
	{
		if(this->data_[i] == &element)
			flag = true;
	}
	return flag;
}

template <typename T>
int collection::set<T>::count() const{
	int conta = 0;
	for(int i = 0; i < this->size_; ++i)
	{
		if(this->data_[i] != nullptr) // mi conta solo i NON 'BUCHI'
			conta++;
	}
	return conta;
}

template <typename T>
bool collection::set<T>::isFull() const{
	if(count() == this->size_)
	{
		resize();
		return true;
	}
	else // presenta buchi ---> nullptr
		return false;
}

template <typename T>
void collection::set<T>::addElement(const T &element, int pos)
{
	if(!checkElement(element))
	{
		if(this->data_[pos] == nullptr)
            this->data_[pos] = &element;
		else
		{
			resize(1);
            this->data_[this->size_-1] = &element; // metto element in ultima posizione
		}
	}
	else
		resize(pos);
}


template <typename T>
T collection::set<T>::removeElement(int pos) {

	//pos non è necessaria--> set è collezione DISORDINATA
	T* elementErased;
	for(int i = 0; i < this->size_; ++i)
	{
		if(this->data_[i] != nullptr) // appena trovo NON buco
		{
			elementErased = this->data_[i];
            this->data_[i] = nullptr;
		}
	}
	return *elementErased;
}







