#pragma once

#include "Item.h"

// ShowStockDlg dialog

extern CTypedPtrArray<CObArray, Item*> store;
extern Item* currentItem;

class ShowStockDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowStockDlg)

	int counter;

public:
	ShowStockDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ShowStockDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW_STOCK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedStockList(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl stockListControl;
	afx_msg void OnSelchangeComboShow();
	virtual BOOL OnInitDialog();
	CComboBox showControl;
	CString findItem;
	afx_msg void OnBnClickedRemove();
	void loadItems();
	CButton staticTextMessage;
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	CButton staticText;
	CStatic text;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSearchbutton();
};
