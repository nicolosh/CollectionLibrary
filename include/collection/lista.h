//
// Created by nicol on 15/12/2020.
//

#ifndef COLLECTIONLIBRARY_LISTA_H
#define COLLECTIONLIBRARY_LISTA_H

#include "collection/collectable.h"

namespace collection{
	template <typename T>
    class lista: public collectable<T>
	{
		//NON SO COME RISOLVERE NULL MA FACCIAMO CHE CI RIESCA
		public:
            lista(T **data, int size, const std::string& nameList) : collectable<T>(data, size, nameList){}

            int count() const{
				int conta = 0;
				for(int i = 0; i < this->size_; ++i)
				{
					if(this->data_[i] != nullptr) // mi conta solo i NON 'BUCHI'
						conta++;
				}
				return conta;
			}

			void addElement(const T &element, int pos) override;
			T removeElement(int pos) override;
			void empty() override;
			
			bool isFull() const override{
				if(count() == this->size_)
					return true;
				else
					return false;
			};
			
			
			void resize(int size = 1)
			{
				empty();
				this->size_ += size;
				this->data_ = new T*[this->size_];
			}
    };
}

#endif //COLLECTIONLIBRARY_LISTA_H
