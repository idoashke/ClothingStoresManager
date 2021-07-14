// searchItemDlg.cpp : implementation file
//

#include "pch.h"
#include "ClothingStoresManager.h"
#include "searchItemDlg.h"
#include "afxdialogex.h"


// searchItemDlg dialog

IMPLEMENT_DYNAMIC(searchItemDlg, CDialogEx)

searchItemDlg::searchItemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH_ITEM, pParent)
{

}

searchItemDlg::~searchItemDlg()
{
}

void searchItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(searchItemDlg, CDialogEx)
END_MESSAGE_MAP()


// searchItemDlg message handlers
