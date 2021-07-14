#pragma once


// NewItemDlg dialog

class NewItemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewItemDlg)

public:
	NewItemDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewItemDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeTypeList();
	afx_msg void OnEnChangeEditDescription();
	void clear();
	void show();
	void hide();
	bool checkNewItemError();
	CComboBox selected;
	CEdit descriptionControl;
	CStatic staticSize;
	CComboBox sizeControl;
	CComboBox footSizeControl;
	CString newItemDescription;
	CString newItemCompany;
	double newItemPrice;
	//BOOL newItemIsMale;
	//BOOL newItemIsFemale;
	int newItemQuantity;
	CString newItemClothingSize;
	int newItemFootSize;
	afx_msg void OnBnClickedSaveitem();
	CString newItemColor;
	CString newItemSportType;
	CString newItemClothesType;
	CString newItemShoesType;
	CStatic staticType;
	CComboBox clothesTypeControl;
	CComboBox shoesTypeControl;
	CComboBox sportTypeControl;
	CComboBox colorControl;
	CEdit companyControl;
	CEdit priceControl;
	CButton maleControl;
	CButton femaleControl;
	CEdit quantityControl;
	CComboBox activeOrOutControl;
	afx_msg void OnCbnSelchangeComboActiveOrOut();
	CComboBox activewearControl;
	CString newItemActivewearType;
	CStatic sportTypeOrLeatherControl;
	CComboBox leatherControl;
	CString newItemDriFit;
	CComboBox DriFitControl;
	CStatic staticDriFitControl;
	CStatic staticActiveOrOut;
	CComboBox bodyFitControl;
	CString newItemBodyFit;
	CString newItemIsLeather;
	CStatic staticTextSaveControl;
};
