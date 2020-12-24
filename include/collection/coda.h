//
// Created by nicol on 15/12/2020.
//

#ifndef COLLECTIONLIBRARY_CODA_H
#define COLLECTIONLIBRARY_CODA_H

#include <collection/collectable.h>

namespace collection{
	template <typename T>
    class coda : public collectable<T> {
		// coda non può avere buchi	nel mezzo (solo inizio/fine o 
		//completamente vuota/piena)
    public:

        coda(T** &data, int size, const std::string& nameCoda) : collectable<T>(data, size, nameCoda){}

        int count() const override;

        void addElement(const T &element, int pos) override;

        T removeElement(int pos) override;

        void empty() override;

        bool isFull() const override;
		
		void resize(int size = 1)
		{
			T* copy[] = new T*[this->size_ + size];
			for(int i = 0; i < this->size_; ++i)
				copy[i] = this->data_[i];

			empty();

            this->size_ += size;
			this->data_ = new T*[this->size_];

            for(int i = 0; i < this->size_; ++i) {
                this->data_[i] = copy[i];
                delete copy[i];
            }
            delete[] copy;
		}
    };
}

#endif //COLLECTIONLIBRARY_CODA_H
