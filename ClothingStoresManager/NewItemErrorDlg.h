#pragma once


// NewItemErrorDlg dialog

class NewItemErrorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewItemErrorDlg)

public:
	NewItemErrorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewItemErrorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_ITEM_ERROR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
