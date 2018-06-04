#include "JunYeClass.h"

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
