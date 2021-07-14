#pragma once


// searchItemDlg dialog

class searchItemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(searchItemDlg)

public:
	searchItemDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~searchItemDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
