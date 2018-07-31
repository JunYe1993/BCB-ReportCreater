#ifndef EXCELH
#define EXCELH

#include "Comobj.hpp"
#include "JunYeClass.h"
#include "ExcelParameter.h"

class Common;
class Excel : protected Common
{
protected :
	_Excel Exc;
	void __fastcall getDataRange();
	void __fastcall getDataRange(int index);
    void __fastcall getDataRange(int row1, int col1, int row2, int col2);
	int  __fastcall getAllDataRange();
public :
	Excel();

	void __fastcall Open(String path);
	void __fastcall Save(String path);
	void __fastcall Close();
	void __fastcall Close_2();// Excel 關閉前複製一格 避免剪貼簿裡資料過多跳出視窗.

	bool __fastcall addWorkSheet();
	bool __fastcall getWorkSheet(int index);
	bool __fastcall getWorkSheet(String name);
	bool __fastcall getWorkSheetCopy(String name);
	bool __fastcall setWorkSheetVisible(String name, bool visible);
	bool __fastcall changeWorkSheetName(String name);
	bool __fastcall deleteWorkSheet();
	bool __fastcall getWorksheetOLEObject(int index);
	bool __fastcall getWorksheetOLEObject(String name);


	String __fastcall getRangeValue(int row, int column);
	String __fastcall getRangeValue(String name);
    bool __fastcall getRange(int row, int col);
	bool __fastcall getRange(String name);
	bool __fastcall getAboveRange(String name, int index);
	bool __fastcall getRangeCopy(String name);
	bool __fastcall setRangeValue(String value);
	bool __fastcall setRangeValue(String name, String value);
	bool __fastcall setAboveRangeValue(String name, int index, String value);
	bool __fastcall setRangeColor(int ColorIndex);



	int  __fastcall searchValueInColumn(int ColumnIndex, String Value);
	bool __fastcall insertRow(String Range);
	bool __fastcall insertCopy(String Range, int RowNum);

	bool __fastcall getAllDataCopy();
	bool __fastcall getAllDataCopy(int row1, int col1, int row2, int col2);
	bool __fastcall paste();
	bool __fastcall pasteColumnWidth();

    //virtual void __fastcall getData();
};

#endif
