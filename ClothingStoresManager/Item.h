#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>

using namespace std;

extern int counter;


class Item : public CObject
{
protected:
	int _itemType = -1;
private:
	double _price;
	CString _company;
	CString _description;
	int _quantity;
	bool _gender;
	int _productCode;
	CString _color;
	//static int counter;
	//static int _productCode;

public:
	DECLARE_SERIAL(Item)

	Item() : _price(NULL), _company(_T("")), _gender(NULL), _description(_T("")), _color(_T("")), _quantity(NULL), _productCode(counter) { counter++; }
	Item(double price, CString company, bool gender, CString description, CString color, int quantity, int productCode = counter);
	double getPrice() const;
	CString getCompany() const;
	CString getDescription() const;
	int getQuantity() const;
	bool getGender() const;
	int getProductCode() const;
	CString getColor() const;
	int getItemType() const;

	//Footwear
	virtual int getFootSize() const { return NULL; }
	virtual bool getIsLeather() const { return NULL; }
	virtual CString getShoesType() const { return NULL; }
	//Clothing
	virtual CString getSize() const { return NULL; }
	virtual CString getClothesType() const { return NULL; }
	//Actiewear
	virtual CString getSportType() const { return NULL; }
	virtual bool getDriFit() const { return NULL; }
	//Outwear
	virtual CString getBodyFit() const { return NULL; }


	virtual void Serialize(CArchive& archive);
	virtual bool operator ==(const Item& i);

};