// ShowStockDlg.cpp : implementation file
//

#include "pch.h"
#include"ClothingStoresManager.h"
#include "ShowStockDlg.h"
#include "afxdialogex.h"
#include "Activewear.h"
#include "Outwear.h"
#include "Footwear.h"
#include "NewItemDlg.h"

// ShowStockDlg dialog


IMPLEMENT_DYNAMIC(ShowStockDlg, CDialogEx)

CTypedPtrArray<CObArray, Item*> store;
Item* currentItem;

ShowStockDlg::ShowStockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOW_STOCK, pParent)
	, findItem(_T(""))
{

}

ShowStockDlg::~ShowStockDlg()
{
}

void ShowStockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STOCK_LIST, stockListControl);
	DDX_Control(pDX, IDC_COMBO_SHOW, showControl);
	DDX_Text(pDX, IDC_EDIT1, findItem);
	DDX_Control(pDX, BTN_REMOVE, staticTextMessage);
	DDX_Control(pDX, BTN_Add, staticText);
	DDX_Control(pDX, IDC_TEXT, text);
}


BEGIN_MESSAGE_MAP(ShowStockDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_STOCK_LIST, &ShowStockDlg::OnLvnItemchangedStockList)
	ON_CBN_SELCHANGE(IDC_COMBO_SHOW, &ShowStockDlg::OnSelchangeComboShow)
	ON_BN_CLICKED(BTN_REMOVE, &ShowStockDlg::OnBnClickedRemove)
	ON_BN_CLICKED(BTN_REFRESH, &ShowStockDlg::OnBnClickedRefresh)
	ON_BN_CLICKED(BTN_Add, &ShowStockDlg::OnBnClickedAdd)
	ON_BN_CLICKED(BTN_SAVE, &ShowStockDlg::OnBnClickedSave)
	ON_BN_CLICKED(BTN_LOAD, &ShowStockDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDCANCEL, &ShowStockDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &ShowStockDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCHBUTTON, &ShowStockDlg::OnBnClickedSearchbutton)
END_MESSAGE_MAP()


// ShowStockDlg message handlers

void ShowStockDlg::loadItems()
{
	//for (int i = 0; i < store.GetSize(); i++)
	store.FreeExtra();
	while (counter < store.GetCount())
	{
		LVITEM lvi;
		CString strItem;
		int itemType = store.GetAt(counter)->getItemType(); // 0 - Footwear , 1 - Activewear , 2 - Outwear
		// Set subitem 0 - Code
		lvi.mask = /*LVIF_IMAGE |*/ LVIF_TEXT;
		strItem.Format(_T("%d"), store.GetAt(counter)->getProductCode());
		lvi.iItem = counter;
		lvi.iSubItem = 0;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.InsertItem(&lvi);
		// Set subitem 1 - Description
		strItem.Format(store.GetAt(counter)->getDescription());
		lvi.iSubItem = 1;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 2 - Type
		switch (itemType)
		{
		case 0:
			strItem.Format(_T("Footwear"));
			break;
		case 1:
			strItem.Format(_T("Activewear"));
			break;
		case 2:
			strItem.Format(_T("Outwear"));
			break;
		default:
			strItem.Format(_T("Unknown"));
		}
		lvi.iSubItem = 2;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 3 - Product
		switch (itemType)
		{
		case 0:
			strItem.Format(store.GetAt(counter)->getShoesType());
			break;
		case 1:
			strItem.Format(store.GetAt(counter)->getClothesType());
			break;
		case 2:
			strItem.Format(store.GetAt(counter)->getClothesType());
			break;
		default:
			strItem.Format(_T("Unknown"));
		}
		lvi.iSubItem = 3;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 4 - Company
		strItem.Format(store.GetAt(counter)->getCompany());
		lvi.iSubItem = 4;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 5 - Color
		strItem.Format(store.GetAt(counter)->getColor());
		lvi.iSubItem = 5;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 6 - Price
		strItem.Format(_T("%f"), store.GetAt(counter)->getPrice());
		lvi.iSubItem = 6;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 7 - Quantity
		strItem.Format(_T("%d"), store.GetAt(counter)->getQuantity());
		lvi.iSubItem = 7;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 8 - Gender // in the end need to do
		bool gender = store.GetAt(counter)->getGender();
		switch (gender)
		{
		case 0:
			strItem.Format(_T("Female"));
			break;
		case 1:
			strItem.Format(_T("Male"));
			break;

		}
		lvi.iSubItem = 8;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 9 - Size
		switch (itemType)
		{
		case 0:
			strItem.Format(_T("%d"), store.GetAt(counter)->getFootSize());
			break;
		case 1:
			strItem.Format(store.GetAt(counter)->getSize());
			break;
		case 2:
			strItem.Format(store.GetAt(counter)->getSize());
			break;
		default:
			strItem.Format(_T("Unknown"));
		}
		lvi.iSubItem = 9;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 10 - sport type / body fit / is leather
		switch (itemType)
		{
		case 0:
			//bool leather = store.GetAt(i)->getIsLeather();
			if (store.GetAt(counter)->getIsLeather() == 0) strItem.Format(_T("Leather"));
			else strItem.Format(_T("Not Leather"));
			break;
		case 1:
			strItem.Format(store.GetAt(counter)->getSportType());
			break;
		case 2:
			strItem.Format(store.GetAt(counter)->getBodyFit());
			break;
		default:
			strItem.Format(_T("Unknown"));
			break;
		}
		lvi.iSubItem = 10;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		stockListControl.SetItem(&lvi);
		// Set subitem 11
		switch (itemType)
		{
		case 0:
			strItem.Format(_T("-"));
			break;
		case 1:
			//bool drifit = store.GetAt(i)->getDriFit();
			if (store.GetAt(counter)->getDriFit() == 0) strItem.Format(_T("Yes"));
			else strItem.Format(_T("No"));
			break;
		case 2:
			strItem.Format(_T("-"));
			break;
		default:
			strItem.Format(_T("Unknown"));
			break;
		}
		lvi.iSubItem = 11;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		lvi.iGroupId = store.GetAt(counter)->getProductCode();
		stockListControl.SetItem(&lvi);

		UpdateData(false);
		counter++;
	}
}


void ShowStockDlg::OnLvnItemchangedStockList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void ShowStockDlg::OnSelchangeComboShow()
{
}


BOOL ShowStockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Code");
	stockListControl.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 260;
	lvColumn.pszText = _T("Description");
	stockListControl.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Type"); // Footwear or Activerwear or Outwear
	stockListControl.InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Product"); // Shirt or T-shirt or Jeans and etc
	stockListControl.InsertColumn(4, &lvColumn);// activeweartype (tights...) ( / outweartype (jackets...) / shoestype (boots...)

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Company");
	stockListControl.InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Color");
	stockListControl.InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Price");
	stockListControl.InsertColumn(7, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Quantity");
	stockListControl.InsertColumn(8, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Gender");
	stockListControl.InsertColumn(9, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Size");
	stockListControl.InsertColumn(10, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Type/Fit/Leather"); // sport type / body fit / is leather
	stockListControl.InsertColumn(11, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = _T("Dri-Fit"); // is drifit - only activerwear item
	stockListControl.InsertColumn(12, &lvColumn);

	//loadItems();
		//COleDateTime::GetCurrentTime().Format(_T("Created: %I:%M:%S %p, %m/%d/%Y"))); //if i want to know date of create
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void ShowStockDlg::OnBnClickedRemove()
{
	int temp = stockListControl.GetSelectionMark();
	CString t = stockListControl.GetItemText(temp, 0);
	int code = StrToInt(t);
	for (int i = 0; i < store.GetCount(); i++)
	{
		if (store.ElementAt(i)->getProductCode() == code)
		{

			stockListControl.DeleteItem(temp);
			store.RemoveAt(i);
			text.SetWindowTextW(_T("Item removed successfully"));
			counter--;
			exit;
		}
	}
}


void ShowStockDlg::OnBnClickedRefresh()
{
	loadItems();
	showControl.SetCurSel(-1);
	text.SetWindowTextW(_T("List refreshed successfully"));
}


void ShowStockDlg::OnBnClickedAdd()
{
	NewItemDlg Dlg;
	Dlg.DoModal();
	loadItems();
	text.SetWindowTextW(_T("Items added successfully"));
}


void ShowStockDlg::OnBnClickedSave()
{
	const TCHAR czFilter[] = _T("Store files (*.store)|*.store|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("store"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		store.Serialize(ar);
		ar.Close();
		file.Close();
	}
	text.SetWindowTextW(_T("Store saved successfully"));
	//CDialogEx::OnOK();
}


void ShowStockDlg::OnBnClickedLoad()
{
	const TCHAR czFilter[] = _T("Store files (*.store)|*.store|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("store"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		store.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	text.SetWindowTextW(_T("Store loaded successfully"));
	counter = 0;
	loadItems();
}


void ShowStockDlg::OnBnClickedCancel()
{
	stockListControl.DeleteAllItems();
	store.RemoveAll();
	CDialogEx::OnCancel();
}


void ShowStockDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void ShowStockDlg::OnBnClickedSearchbutton()
{
	if (showControl.GetCurSel() != -1)
	{
		UpdateData(true);
		stockListControl.DeleteAllItems();
		int d = store.GetCount();
		loadItems();
		switch (showControl.GetCurSel()) // findItem
		{
		case 0: // type
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 2) != findItem)
					stockListControl.DeleteItem(i);
			}
			break;
		case 1: // product
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 3) != findItem)
					stockListControl.DeleteItem(i);
			}
			break;
		case 2: // product code
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 3) != findItem)//sxsXsx
					stockListControl.DeleteItem(i);
			}
			break;
		case 3: // description
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 1) != findItem)
					stockListControl.DeleteItem(i);
			}
			break;
		case 4: // company
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 4) != findItem)
					stockListControl.DeleteItem(i);
			}
			break;
		case 5: // color
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 5) != findItem)
					stockListControl.DeleteItem(i);
			}
			break;
		case 6: // gender
			for (int i = 0; i < store.GetCount(); i++)
			{
				if (stockListControl.GetItemText(i, 1) != findItem) // bool
					stockListControl.DeleteItem(i);
			}
			break;
		}
		UpdateData(false);
	}
}
