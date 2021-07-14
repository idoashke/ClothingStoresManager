#include "pch.h"
#include "Activewear.h"
//#include "Store.h"
#include "ClothingStoresManagerDlg.h"
#include "NewItemDlg.h"

/****************** Functions ******************/

CString Activewear::getSportType() const
{
	return this->_sportType;
}

bool Activewear::getDriFit() const
{
	return this->_driFit;
}


/****************** Operators ******************/

bool Activewear::operator==(const Activewear& a)
{
	int temp = Clothing::operator==(a);
	if (temp == 1)
		if (this->_sportType == a._sportType && this->_driFit == a._driFit)
			return 1;
		else return 0;
}


/****************** Constructors & Distructor ******************/

Activewear::Activewear(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType, CString sportType, bool driFit) :
	Clothing(price, company, gender, description, color, quantity, size, clothesType), _sportType(sportType), _driFit(driFit)
{
	this->_itemType = 1;
}


/****************** Serialization ******************/

void Activewear::Serialize(CArchive& archive)
{
	Clothing::Serialize(archive);
	if (archive.IsStoring()) {
		archive << _sportType << _driFit;
	}
	else {
		archive >> _sportType >> _driFit;
	}
}