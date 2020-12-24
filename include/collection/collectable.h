//
// Created by nicol on 15/12/2020.
//

#ifndef COLLECTIONLIBRARY_COLLECTABLE_H
#define COLLECTIONLIBRARY_COLLECTABLE_H

#include <cassert>
//#include <vector>
#include <string>

namespace collection{
	template <typename T>
    class collectable
	{
	protected:
        T **data_;
		int size_;
		std::string nameCollection;
	public:
	    collectable(int size, const std::string& name) : size_(size), nameCollection(name)
        {
            data_ = new T*[size];
        }
        collectable(T** &data, int size, const std::string& name) : size_(size){
	        nameCollection = name;
			for(int i = 0; i < size; ++i)
			{
				data_[i] = data[i];
			}
		};
        virtual int count() const = 0; // quanti elementi sono presenti

		virtual void empty() = 0; // svuota la struttura

		virtual bool isFull() const = 0;

		virtual void addElement(const T& element, int pos = 0) = 0; //aggiungi elemento alla struttura (array)

		virtual T removeElement(int pos = 0) = 0; //rimuove e restituisce un elemento

        T** getData() const { return data_; }

        int getSize() const { return size_; }

        const std::string& getNameCollection() const { return nameCollection; }

        /*
		~collectable(){
			delete elementoDIdata_[];
			delete[] data_;
		};*/
    };
}


#endif //COLLECTIONLIBRARY_COLLECTABLE_H
