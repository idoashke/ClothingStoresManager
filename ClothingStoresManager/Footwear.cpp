#include "pch.h"
#include "Footwear.h"

/****************** Functions ******************/

int Footwear::getFootSize() const
{
	return this->_footSize;
}

bool Footwear::getIsLeather() const
{
	return this->_isLeather;
}

CString Footwear::getShoesType() const
{
	return this->_shoesType;
}


/****************** Operators ******************/

bool Footwear::operator==(const Footwear& f)
{
	int temp = Item::operator==(f);
	if (temp == 1)
		if (this->_footSize == f._footSize)
			return 1;
		else return 0;
}


/****************** Constructors & Distructor ******************/

Footwear::Footwear(double price, CString company, bool gender, CString description, CString color, int quantity, int footSize, bool isLeather, CString shoesType) :
	Item(price, company, gender, description, color, quantity), _footSize(footSize), _isLeather(isLeather), _shoesType(shoesType) {
	this->_itemType = 0;
}


/****************** Serialization ******************/

void Footwear::Serialize(CArchive& archive)
{
	Item::Serialize(archive);
	if (archive.IsStoring()) {
		archive << _footSize << _isLeather << _shoesType;
	}
	else {
		archive >> _footSize >> _isLeather >> _shoesType;
	}
}