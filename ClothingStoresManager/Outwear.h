#pragma once
#include "Clothing.h"
class Outwear : public Clothing
{
private:
	CString _bodyFit;
public:
	DECLARE_SERIAL(Outwear)

	Outwear() {}
	Outwear(double price, CString company, bool gender, CString description, CString color, int quantity, CString size, CString clothesType, CString bodyFit);
	CString getBodyFit() const;
	virtual bool operator ==(const Outwear& o);
	virtual void Serialize(CArchive& archive);
};

