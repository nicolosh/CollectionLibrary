//
// Created by nicol on 15/12/2020.
//


#include "../include/collection/lista.h"

template <typename T>
void collection::lista<T>::empty()
{
	for(int i = 0; i < this->size_; ++i)
		delete this->data_[i];
	delete[] this->data_;
}

template <typename T>
void collection::lista<T>::addElement(const T &element, int pos)
{
	assert(pos >= 0 && pos < this->size_);
	
	T* copy[] = new T*[this->size_ + 1];
	for (int i = 0; i < this->size_ + 1; ++i) {
		if(i < pos)
			copy[i] = this->data_[i];
		else if(i == pos)
			copy[i] = &element;
		else
			copy[i] = this->data_[i - 1];
	}
	
	resize(1); // metto data_ alla stessa lunghezza di copy
	
	for(int j = 0; j < this->size_ + 1; ++j)
	{
		this->data_[j] = copy[j];
		delete copy[j];
	}
	
	delete[] copy;
}

template <typename T>
T collection::lista<T>::removeElement(int pos) {
	
	assert(pos >= 0 && pos < this->size_);

	T* elementErased;
	if(isFull())
	{
		T* erased[] = new T*[this->size_ - 1];
		for(int i = 0; i < this->size_ - 1; ++i)
		{
			if(i < pos)
				erased[i] = this->data_[i];
			else
			{
				if(i == pos) // salvo element da restituire
					elementErased = this->data_[pos];
					
				erased[i] = this->data_[i + 1];
			}
		}
			
		resize(-1);
		
		for(int j = 0; j < this->size_ - 1; ++j) {
            this->data_[j] = erased[j];
            delete erased[j];
        }

		delete[] erased;
	}
	
	return *elementErased;
}
