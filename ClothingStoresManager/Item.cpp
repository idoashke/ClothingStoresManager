#include "pch.h"
#include "Item.h"
#include "Clothing.h"
#include "Footwear.h"
#include "Activewear.h"
#include "Outwear.h"


IMPLEMENT_SERIAL(Item, CObject, 1)
IMPLEMENT_SERIAL(Clothing, Item, 1)
IMPLEMENT_SERIAL(Footwear, Item, 1) // we can put all this on the specific cpp of the object
IMPLEMENT_SERIAL(Outwear, Item, 1)
IMPLEMENT_SERIAL(Activewear, Item, 1)

int counter = 0;

/****************** Functions ******************/

double Item::getPrice() const
{
	return this->_price;
}

CString Item::getCompany() const
{
	return this->_company;
}
CString Item::getDescription() const
{
	return this->_description;
}

int Item::getQuantity() const
{
	return this->_quantity;
}

bool Item::getGender() const
{
	return this->_gender;
}
int Item::getProductCode() const
{
	return this->_productCode;
}

CString Item::getColor() const
{
	return this->_color;
}

int Item::getItemType() const
{
	return this->_itemType;
}






void Item::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	if (archive.IsStoring()) {
		archive << _price << _company << _gender << _description << _color << _quantity << _productCode << _itemType;
	}
	else {
		archive >> _price >> _company >> _gender >> _description >> _color >> _quantity >> _productCode >> _itemType;
	}
}


/****************** Operators ******************/

bool Item::operator==(const Item& i)
{
	if (this->_description == i._description && this->_company == i._company && this->_price == i._price &&
		this->_gender == i._gender && this->_color == i._color) // without productCode and quantity
		return 1;
	else return 0;
}


/****************** Constructors ******************/

//Item::Item() /*: _price(NULL), _company(_T("")), _gender(NULL), _description(_T("")), _color(_T("")), _quantity(NULL), _productCode(counter)*/
//{
//	this->_price = NULL;
//	this->_company = _T("");
//	this->_gender = NULL;
//	this->_description = _T("");
//	this->_color = _T("");
//	this->_quantity = NULL;
//	this->_productCode = counter++;
//	//counter++;
//}


Item::Item(double price, CString company, bool gender, CString description, CString color, int quantity, int productCode)
	:_price(price), _company(company), _gender(gender), _description(description), _color(color), _quantity(quantity), _productCode(productCode)
{
	counter++; this->_itemType = -1;
}


/****************** Distructor ******************/
