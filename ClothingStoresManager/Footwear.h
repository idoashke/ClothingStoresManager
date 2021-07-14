#pragma once
#include "Item.h"
class Footwear : public Item
{
private:
	CString _shoesType;
	int _footSize;
	bool _isLeather;
public:
	DECLARE_SERIAL(Footwear)

	Footwear() {}
	//Footwear(double price, CString company, bool gender, CString description, int quantity, int productCode, int footSize) :
	//	Item(price, company, gender, description, quantity, productCode), _footSize(footSize) {}
	Footwear(double price, CString company, bool gender, CString description, CString color, int quantity, int footSize, bool isLeather, CString shoesType);
	int getFootSize() const;
	bool getIsLeather() const;
	CString getShoesType() const;
	virtual bool operator ==(const Footwear& f);
	virtual void Serialize(CArchive& archive);
};

