#pragma once
#include "Item.h"
class Clothing : public Item
{
private:
	CString _size;
	CString _clothesType;
public:
	DECLARE_SERIAL(Clothing)

	Clothing() {}
	Clothing(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType);
	virtual bool operator ==(const Clothing& c);
	CString getSize() const;
	CString getClothesType() const;
	virtual void Serialize(CArchive& archive);
};

