// NewItemDlg.cpp : implementation file
//

#include "pch.h"
#include "ClothingStoresManager.h"
#include "NewItemDlg.h"
#include "NewItemErrorDlg.h"
#include "afxdialogex.h"
#include "Item.h"
#include "Footwear.h"
#include "Activewear.h"
#include "Outwear.h"
#include "ShowStockDlg.h"


//#define IDC_TYPE_LIST "CHOOSE ITEM TYPE.."
// NewItemDlg dialog


IMPLEMENT_DYNAMIC(NewItemDlg, CDialogEx)

NewItemDlg::NewItemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEW_ITEM, pParent), newItemDescription(_T(""))
	, newItemCompany(_T(""))
	, newItemPrice(NULL)
	, newItemQuantity(NULL)
	, newItemClothingSize(_T(""))
	, newItemFootSize(NULL)
	, newItemColor(_T(""))
	, newItemSportType(_T(""))
	, newItemClothesType(_T(""))
	, newItemShoesType(_T(""))

	, newItemActivewearType(_T(""))

	, newItemDriFit(_T(""))
	, newItemBodyFit(_T(""))
	, newItemIsLeather(_T(""))
{
}


NewItemDlg::~NewItemDlg()
{
}

void NewItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TYPE_LIST, selected);
	DDX_Control(pDX, IDC_EDIT_DESCRIPTION, descriptionControl);
	DDX_Control(pDX, IDC_STATIC_SIZE, staticSize);
	DDX_Control(pDX, IDC_COMBO_SIZE, sizeControl);
	DDX_Control(pDX, IDC_COMBO_FOOTSIZE, footSizeControl);
	DDX_Text(pDX, IDC_EDIT_DESCRIPTION, newItemDescription);
	DDX_Text(pDX, IDC_EDIT_COMPANY, newItemCompany);
	DDX_Text(pDX, IDC_EDIT_PRICE, newItemPrice);
	//DDX_Radio(pDX, IDC_MALE, newItemIsMale);
	//DDX_Radio(pDX, IDC_FEMALE, newItemIsFemale);
	DDX_Text(pDX, IDC_EDIT_QUANTITY, newItemQuantity);
	DDX_CBString(pDX, IDC_COMBO_SIZE, newItemClothingSize);
	DDX_CBIndex(pDX, IDC_COMBO_FOOTSIZE, newItemFootSize);
	DDX_CBString(pDX, IDC_COMBO_COLOR, newItemColor);
	DDX_CBString(pDX, IDC_SPORT_TYPE, newItemSportType);
	DDX_CBString(pDX, IDC_CLOTHES_TYPE, newItemClothesType);
	DDX_CBString(pDX, IDC_SHOES_TYPE, newItemShoesType);
	DDX_Control(pDX, IDC_CLOTHES_OR_SHOES_TYPE, staticType);
	DDX_Control(pDX, IDC_CLOTHES_TYPE, clothesTypeControl);
	DDX_Control(pDX, IDC_SHOES_TYPE, shoesTypeControl);
	DDX_Control(pDX, IDC_SPORT_TYPE, sportTypeControl);
	DDX_Control(pDX, IDC_COMBO_COLOR, colorControl);
	DDX_Control(pDX, IDC_EDIT_COMPANY, companyControl);
	DDX_Control(pDX, IDC_EDIT_PRICE, priceControl);
	DDX_Control(pDX, IDC_MALE, maleControl);
	DDX_Control(pDX, IDC_FEMALE, femaleControl);
	DDX_Control(pDX, IDC_EDIT_QUANTITY, quantityControl);
	DDX_Control(pDX, IDC_COMBO_ACTIVE_OR_OUT, activeOrOutControl);
	DDX_Control(pDX, IDC_ACTIVEWEAR_TYPE, activewearControl);
	DDX_CBString(pDX, IDC_ACTIVEWEAR_TYPE, newItemActivewearType);
	DDX_Control(pDX, IDC_STATIC_SPORTTYPE, sportTypeOrLeatherControl);
	DDX_Control(pDX, IDC_LEATHER, leatherControl);
	DDX_CBString(pDX, IDC_COMBO_DRIFIT, newItemDriFit);
	DDX_Control(pDX, IDC_COMBO_DRIFIT, DriFitControl);
	DDX_Control(pDX, IDC_STATIC_DRIFIT, staticDriFitControl);
	DDX_Control(pDX, IDC_STATIC_ACTIVEOROUT, staticActiveOrOut);
	DDX_Control(pDX, IDC_BODYFIT, bodyFitControl);
	DDX_CBString(pDX, IDC_BODYFIT, newItemBodyFit);
	DDX_CBString(pDX, IDC_LEATHER, newItemIsLeather);
	DDX_Control(pDX, IDC_STATIC_ITEMSAVED, staticTextSaveControl);
}


BEGIN_MESSAGE_MAP(NewItemDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_TYPE_LIST, &NewItemDlg::OnCbnSelchangeTypeList)
	ON_EN_CHANGE(IDC_EDIT_DESCRIPTION, &NewItemDlg::OnEnChangeEditDescription)
	ON_BN_CLICKED(IDSAVEITEM, &NewItemDlg::OnBnClickedSaveitem)
	ON_CBN_SELCHANGE(IDC_COMBO_ACTIVE_OR_OUT, &NewItemDlg::OnCbnSelchangeComboActiveOrOut)
END_MESSAGE_MAP()
	
// NewItemDlg message handlers

void NewItemDlg::clear()
{
	sizeControl.SetCurSel(-1);
	footSizeControl.SetCurSel(-1);
	clothesTypeControl.SetCurSel(-1);
	shoesTypeControl.SetCurSel(-1);
	sportTypeControl.SetCurSel(-1);
	colorControl.SetCurSel(-1);
	leatherControl.SetCurSel(-1);
	DriFitControl.SetCurSel(-1);
	newItemDescription = _T("");
	newItemCompany = _T("");
	newItemPrice = NULL;
	newItemQuantity = NULL;
	maleControl.SetCheck(0);
	femaleControl.SetCheck(0);
	sportTypeControl.SetCurSel(-1);
	bodyFitControl.SetCurSel(-1);
	staticTextSaveControl.ShowWindow(false);
	UpdateData(false);
}

void NewItemDlg::show()
{
	descriptionControl.ShowWindow(true);
	colorControl.ShowWindow(true);
	companyControl.ShowWindow(true);
	priceControl.ShowWindow(true);
	maleControl.ShowWindow(true);
	femaleControl.ShowWindow(true);
	quantityControl.ShowWindow(true);
	sizeControl.ShowWindow(true);
}

void NewItemDlg::hide()
{
	descriptionControl.ShowWindow(false);
	colorControl.ShowWindow(false);
	companyControl.ShowWindow(false);
	priceControl.ShowWindow(false);
	maleControl.ShowWindow(false);
	femaleControl.ShowWindow(false);
	quantityControl.ShowWindow(false);
	sizeControl.ShowWindow(false);
}

bool NewItemDlg::checkNewItemError()
{
	UpdateData(true);
	if (newItemDescription == _T("") || newItemCompany == _T("") || colorControl.GetCurSel() == -1 || newItemPrice == NULL ||
		newItemQuantity == NULL || (maleControl.GetCheck() == 0 && femaleControl.GetCheck() == 0))
		return false; // Dlg.DoModal - open error dlg
	if (selected.GetCurSel() == 0)
	{
		if (newItemClothingSize == _T("")) return false;
		if (activeOrOutControl.GetCurSel() == 0)
		{
			if (activewearControl.GetCurSel() == -1 || sportTypeControl.GetCurSel() == -1 || DriFitControl.GetCurSel() == -1) return false;
		}
		else if (activeOrOutControl.GetCurSel() == 1)
		{
			if (clothesTypeControl.GetCurSel() == -1 || bodyFitControl.GetCurSel() == -1) return false();
		}
	}
	else if (newItemFootSize == NULL) return false();

	return true;
}


void NewItemDlg::OnCbnSelchangeTypeList()
{
	clear();
	activeOrOutControl.SetCurSel(-1);
	if (selected.GetCurSel() == 0) // if curr selection is clothing (index 0)
	{
		//descriptionControl.EnableWindow(false);
		//descriptionControl.ShowWindow(false);
		hide();
		staticSize.SetWindowTextW(_T("Size:"));
		staticType.SetWindowTextW(_T("Clothes type:"));
		sportTypeOrLeatherControl.SetWindowTextW(_T("type:"));
		staticActiveOrOut.ShowWindow(true);
		activeOrOutControl.ShowWindow(true);
		//clothesTypeControl.ShowWindow(true);
		shoesTypeControl.ShowWindow(false);
		//sizeControl.ShowWindow(true);
		footSizeControl.ShowWindow(false);
		leatherControl.ShowWindow(false);
		//selected.AddString(_T("ido"));	
	}
	else
	{
		//activeOrOutControl.SetCurSel(-1);
		show();
		staticSize.SetWindowTextW(_T("Foot size:"));
		staticType.SetWindowTextW(_T("Shoes type:"));
		sportTypeOrLeatherControl.SetWindowTextW(_T("Leather:"));
		staticActiveOrOut.ShowWindow(false);
		activeOrOutControl.ShowWindow(false);
		clothesTypeControl.ShowWindow(false);
		activewearControl.ShowWindow(false);
		shoesTypeControl.ShowWindow(true);
		sizeControl.ShowWindow(false);
		footSizeControl.ShowWindow(true);
		sportTypeControl.ShowWindow(false);
		leatherControl.ShowWindow(true);
		DriFitControl.ShowWindow(false);
		staticDriFitControl.ShowWindow(false);
		bodyFitControl.ShowWindow(false);
		//selected.DeleteString(2);

	}
}

void NewItemDlg::OnCbnSelchangeComboActiveOrOut()
{
	//activeOrOutControl.SetCurSel(-1);
	clear();
	show();
	if (activeOrOutControl.GetCurSel() == 0)
	{
		clothesTypeControl.ShowWindow(false);
		activewearControl.ShowWindow(true);
		sportTypeControl.ShowWindow(true);
		DriFitControl.ShowWindow(true);
		staticDriFitControl.ShowWindow(true);
		bodyFitControl.ShowWindow(false);
		sportTypeOrLeatherControl.SetWindowTextW(_T("Sport type:"));
		//sportTypeControl.EnableWindow(1);
	}
	else
	{
		clothesTypeControl.ShowWindow(true);
		activewearControl.ShowWindow(false);
		DriFitControl.ShowWindow(false);
		staticDriFitControl.ShowWindow(false);
		bodyFitControl.ShowWindow(true);
		sportTypeControl.ShowWindow(false);
		//sportTypeControl.SetCurSel(-1);
		sportTypeOrLeatherControl.SetWindowTextW(_T("Body fit:"));
		//sportTypeControl.EnableWindow(0);
	}
}


void NewItemDlg::OnEnChangeEditDescription() // Ignore
{

}


void NewItemDlg::OnBnClickedSaveitem()
{
	if (checkNewItemError() == false)
	{
		NewItemErrorDlg Dlg;
		Dlg.DoModal();
	}
	else
	{
		bool gender;
		if (maleControl.GetCheck() == 1) gender = true; // male
		else gender = false; // female
		if (selected.GetCurSel() == 0) // if its clothing
		{
			if (activeOrOutControl.GetCurSel() == 0) // if its activewear
			{
				bool isDriFit;
				if (DriFitControl.GetCurSel() == 0) isDriFit = true; // yes - its drifit
				else isDriFit = false; // yes - its not drifit
				currentItem = new Activewear(newItemPrice, newItemCompany, gender, newItemDescription, newItemColor, newItemQuantity, newItemClothingSize,
					newItemActivewearType, newItemSportType, isDriFit);
				store.Add(currentItem);

			}
			else if (activeOrOutControl.GetCurSel() == 1) // if its outwear
			{
				currentItem = new Outwear(newItemPrice, newItemCompany, gender, newItemDescription, newItemColor, newItemQuantity, newItemClothingSize,
					newItemClothesType, newItemBodyFit);
				store.Add(currentItem);
			}
		}
		else // if its footwear
		{
			bool isLeather;
			if (leatherControl.GetCurSel() == 0) isLeather = true; // yes
			else isLeather = false; // no
			currentItem = new Footwear(newItemPrice, newItemCompany, gender, newItemDescription, newItemColor, newItemQuantity, newItemFootSize,
				isLeather, newItemShoesType);
			store.Add(currentItem);
			
		}
		//store.Add(currentItem);
		staticTextSaveControl.ShowWindow(true);
		//Sleep(10000);
	}
 }




