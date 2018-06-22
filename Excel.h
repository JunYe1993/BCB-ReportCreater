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
	int  __fastcall getAllRange();
public :
	Excel();
	void __fastcall Open(String path);
	void __fastcall Close();
	void __fastcall Close_2();// Excel �����e�ƻs�@�� �קK�ŶKï�̸�ƹL�h���X����.

	bool __fastcall getWorkSheetbyName(String name);
	void __fastcall getWorkSheetbyInt(int index);
	int  __fastcall searchValueInColumn(int ColumnIndex, String Value);
	String __fastcall getCellValue(int row, int column);

    //virtual void __fastcall getData();
};

#endif