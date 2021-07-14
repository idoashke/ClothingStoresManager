#pragma once
#include "Clothing.h"

class Activewear : public Clothing
{
private:
	CString _sportType;
	bool _driFit;
public:
	DECLARE_SERIAL(Activewear)

	Activewear() : _sportType(_T("")), _driFit(0) {}
	Activewear(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType, CString sportType, bool driFit);
	CString getSportType() const;
	bool getDriFit() const;
	virtual bool operator ==(const Activewear& a);
	virtual void Serialize(CArchive& archive);
};

