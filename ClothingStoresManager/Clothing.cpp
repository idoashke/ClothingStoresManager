#include "pch.h"
#include "Clothing.h"


/****************** Functions ******************/

CString Clothing::getSize() const
{
	return this->_size;
}

CString Clothing::getClothesType() const
{
	return this->_clothesType;
}


/****************** Operators ******************/

bool Clothing::operator==(const Clothing& c)
{
	int temp = Item::operator==(c);
	if (temp == 1)
		if (this->_size == c._size && this->_clothesType == c._clothesType)
			return 1;
		else return 0;
}


/****************** Constructors & Distructor ******************/

Clothing::Clothing(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType) :
	Item(price, company, gender, description, color, quantity), _size(size), _clothesType(clothesType) {}


/****************** Serialization ******************/

void Clothing::Serialize(CArchive& archive)
{
	Item::Serialize(archive);
	if (archive.IsStoring()) {
		archive  << _size << _clothesType;
	}
	else {
		archive >> _size >> _clothesType;
	}
}