
// ClothingStoresManager.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
//#include "Activewear.h"
//#include "Footwear.h"
//#include "Outwear.h"
//#include "Item.h"



// CClothingStoresManagerApp:
// See ClothingStoresManager.cpp for the implementation of this class
//

class CClothingStoresManagerApp : public CWinApp
{
public:
	CClothingStoresManagerApp();

// Overrides
public:
	virtual BOOL InitInstance();


// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CClothingStoresManagerApp theApp;
