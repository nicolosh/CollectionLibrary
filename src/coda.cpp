//
// Created by nicol on 15/12/2020.
//


#include "../include/collection/coda.h"

template <typename T>
void collection::coda<T>::empty(){
	for(int i = 0; i < this->size_; ++i)
	{
		delete this->data_[i];
	}
	delete[] this->data_;
}

template <typename T>
bool collection::coda<T>::isFull() const
{
	if(this->data_[this->size_-1] != nullptr)
		return true;
	
	return false;
}

template <typename T>
int collection::coda<T>::count() const{
	
	if(isFull())
		return this->size_;
	
	int conta = 0;
	while(conta < this->size_ && this->data_[conta] != nullptr) //appena trovo buco da quello in poi tutti vuoti
	{
		conta++;
	}
	return conta;
}

template <typename T>
void collection::coda<T>::addElement(const T &element, int pos)
{	

	assert(pos == 0);
	// aggiungo all'inizio

	if(!isFull()) {
        T* copy[] = new T*[this->size_];

        copy[pos] = &element;
        for (int i = 1; i < this->size_; ++i) {
            copy[i] = this->data_[i - 1];
        }
        for (int j = 0; j < this->size_; ++j) {
            this->data_[j] = copy[j];
            delete copy[j];
        }
		delete[] copy;
	}
	else // alloco memoria aggiuntiva 
		resize(pos);
}

template <typename T>
T collection::coda<T>::removeElement(int pos) {
	
	T* elementErased;
	
	if(isFull())
	{
		elementErased = this->data_[pos];
        this->data_[pos] = nullptr;
	}
	else
	{	
		for(int i = 0; i < this->size_; ++i)
		{
			if(this->data_[i+1] == nullptr) // trovo il buco
			{
				elementErased = this->data_[i];
                this->data_[i] = nullptr;
			}
		}
	}
	
	return *elementErased;
}

