#include "Excel.h"

Excel::Excel(){
	Exc.App = CreateOleObject("Excel.Application");
	Exc.App.OlePropertySet("Visible", false);
	Exc.WorkBooks = Exc.App.OlePropertyGet("Workbooks");
}
void __fastcall Excel::Open(String path){
    try{
		Exc.WorkBook = Exc.WorkBooks.OleFunction("Open", OleStr(path));
	}catch(EOleSysError *e){
		BugReport(L"Path Wrong or Not Excel");
        return;
	}
	Exc.WorkBook = Exc.WorkBooks.OleFunction("Open", OleStr(path));
	Exc.WorkSheets = Exc.WorkBook.OlePropertyGet("Worksheets");
	Exc.WorkSheet = Exc.WorkSheets.OlePropertyGet("Item", 1);
}
void __fastcall Excel::Close(){
	Exc.WorkBook.OleFunction("Close", false);
	Exc.App.Exec(Procedure("Quit"));
}
void __fastcall Excel::Close_2(){
	Exc.Range = Exc.WorkSheet.OlePropertyGet("Cells", 1, 1);
    Exc.Range.OleFunction("Copy");
	Exc.WorkBook.OleFunction("Close", false);
	Exc.App.Exec(Procedure("Quit"));
}

bool __fastcall Excel::getWorkSheetbyName(String name){
	try{
		Exc.WorkSheet = Exc.WorkSheets.OlePropertyGet("Item", OleStr(name));
	}catch(EOleSysError *e){
		BugReport(L"Request Worksheet doesn't exit");
        return false;
	}
	return true;
}
void __fastcall Excel::getWorkSheetbyInt(int index){
	Exc.WorkSheet = Exc.WorkSheets.OlePropertyGet("Item", index);
}
int __fastcall Excel::searchValueInColumn(int ColumnIndex, String Value){
	String x;
	Variant temp;
	Exc.Range = Exc.WorkSheet.OlePropertyGet("Columns", ColumnIndex);
	temp = Exc.Range.OleFunction("Find", OleStr(Value)).OlePropertyGet("Item", 1);
	BugReport("Row = " + temp.OlePropertyGet("Row"));
	return temp.OlePropertyGet("Row");
}
String __fastcall Excel::getCellValue(int row, int column){
	String data;
	Variant temp;
	try{
		temp = Exc.WorkSheet.OlePropertyGet("Cells", row, column).OlePropertyGet("Value");
		if(VarType(temp) != varError){
			data = temp;
			//BugReport("data = "+data);
		}
	}catch(EOleSysError *e){
		BugReport(L"The Cell Can't transmit to OleStr");
	}
	return data;
}

void __fastcall Excel::getDataRange(){

	Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr("A100"));
	Exc.Cell1 = Exc.Range.OlePropertyGet("End", xlShiftUp);
	Exc.PresentRangeCellRow = Exc.Cell1.OlePropertyGet("Row");

	Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr("Z1"));
	Exc.Cell2 = Exc.Range.OlePropertyGet("End",xlShiftToLeft);
	Exc.PresentRangeCellColumn = Exc.Cell2.OlePropertyGet("Column");

	Exc.PresentRangeCell = Exc.WorkSheet.OlePropertyGet("Cells",Exc.PresentRangeCellRow,Exc.PresentRangeCellColumn);
}
void __fastcall Excel::getDataRange(int index){
	String temp = "A100";

    temp[1] += index - 1;
	Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr(temp));
	Exc.Cell1 = Exc.Range.OlePropertyGet("End", xlShiftUp);
	Exc.PresentRangeCellRow = Exc.Cell1.OlePropertyGet("Row");

	Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr("Z1"));
	Exc.Cell2 = Exc.Range.OlePropertyGet("End",xlShiftToLeft);
	Exc.PresentRangeCellColumn = Exc.Cell2.OlePropertyGet("Column");

	Exc.PresentRangeCell = Exc.WorkSheet.OlePropertyGet("Cells",Exc.PresentRangeCellRow,Exc.PresentRangeCellColumn);
}
int __fastcall Excel::getAllRange(){
	String temp;                    /*           EXCEL2010         */
	int c1 = 0, c2 = 0, t;          /* 程逆 XFD 程 65536 */

	// 眖程┏100┕т т26逆 т程┏计.
	for(int i = 0; i < 26; i++){
		temp.sprintf(L"%c100",'A'+i);
		Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr(temp));
		Exc.Cell1 = Exc.Range.OlePropertyGet("End", xlShiftUp);
		t = Exc.Cell1.OlePropertyGet("Row");
		c1 = (t>c1) ? t:c1;
	}
	// 眖程 Z逆( 26 )┕オт т100 т程逆计.
	for(int i = 1; i < 100; i++){
		temp.sprintf(_T("Z%d"),i);
		Exc.Range = Exc.WorkSheet.OlePropertyGet("Range",OleStr(temp));
		Exc.Cell2 = Exc.Range.OlePropertyGet("End",xlShiftToLeft);
		t = Exc.Cell2.OlePropertyGet("Column");
		c2 = (t>c2) ? t:c2;
	}
	// 盢魁 PresentRangeCell.
	Exc.PresentRangeCellRow = c1;
	Exc.PresentRangeCellColumn = c2;
	Exc.PresentRangeCell = Exc.WorkSheet.OlePropertyGet("Cells",c1,c2);
	return c1;
}
