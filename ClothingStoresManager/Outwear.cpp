#include "pch.h"
#include "Outwear.h"

/****************** Functions ******************/

CString Outwear::getBodyFit() const
{
	return this->_bodyFit;
}


/****************** Operators ******************/

bool Outwear::operator==(const Outwear& o)
{
	int temp = Clothing::operator==(o);
	if (temp == 1)
		if (this->_bodyFit == o._bodyFit)
			return 1;
		else return 0;
}


/****************** Constructors & Distructor ******************/

Outwear::Outwear(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType, CString bodyFit) :
	Clothing(price, company, gender, description, color, quantity, size, clothesType), _bodyFit(bodyFit) {
	this->_itemType = 2;
}



/****************** Serialization ******************/

void Outwear::Serialize(CArchive& archive)
{
	Clothing::Serialize(archive);
	if (archive.IsStoring()) {
		archive << _bodyFit;
	}
	else {
		archive >> _bodyFit;
	}
}