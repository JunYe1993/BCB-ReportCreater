#ifndef EXCELH
#define EXCELH

#include "JunYeClass.h"

class Common;
class Excel : protected Common
{
protected :
	_Excel Exc;
	void __fastcall getDataRange();
	void __fastcall getDataRange(int index);
	int  __fastcall getAllRange();
public :
	Excel();
	void __fastcall Open(String path);
	void __fastcall Close();
	void __fastcall Close_2();// Excel 關閉前複製一格 避免剪貼簿裡資料過多跳出視窗.

	bool __fastcall getWorkSheetbyName(String name);
	void __fastcall getWorkSheetbyInt(int index);
	int  __fastcall searchValueInColumn(int ColumnIndex, String Value);
	String __fastcall getCellValue(int row, int column);

    //virtual void __fastcall getData();
};

#endif
