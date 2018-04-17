#ifndef JUNYECLASSH
#define JUNYECLASSH

#include <vcl.h>
#include <vector>
#include <direct.h>
#include <io.h>
#include "inifiles.hpp"
#include "Parameter.h"
using namespace std;

class Common
{
protected :
public :
	void __fastcall SortDouble(vector<double> &nums, int left, int right);
	void __fastcall Timer(unsigned long x);
	void __fastcall CreateReportpath();
	void __fastcall initBugReport();
	void __fastcall initDataReport(AnsiString filename);
	void __fastcall BugReport(AnsiString msg);
	void __fastcall DataReport(AnsiString filename, AnsiString msg);
};

class Files : public Common
{
private :
	_FileData Dir;
	void __fastcall extractpath();
public :
    Files();
	void __fastcall getFiles(String path, int layer);

	int __fastcall getModeCount();
	int __fastcall getFileCount();
    int __fastcall getModeFileCount(int index);
	String __fastcall getModeName(int index);
	String __fastcall getFile(int index);
	String __fastcall getModeFile(int ModeIndex, int FileIndex);
};

class INI : public Common
{
protected:
public:
	void __fastcall WriteInt(AnsiString category, AnsiString parameter, int value);
	void __fastcall WriteStr(AnsiString category, AnsiString parameter, AnsiString value);
	int  __fastcall ReadInt(AnsiString category, AnsiString parameter);
	AnsiString  __fastcall ReadStr(AnsiString category, AnsiString parameter);
};

class Excel : public Common
{
private :
	_Excel Exc;
public :
	Excel();
	void __fastcall Open(String path);
	void __fastcall Close();

	bool __fastcall getWorkSheetbyName(String name);
	void __fastcall getWorkSheetbyInt(int index);
    int __fastcall searchValueInColumn(int ColumnIndex, String Value);
	String __fastcall getCellValue(int row, int column);
};

class JunYe_Word : public Common
{
private :
	_Word Wd;
	void __fastcall getMarks();
	String __fastcall getBookmark(int index);
public :
	JunYe_Word();
	void __fastcall Open(String path);
	void __fastcall OpenData(String path); // for another word which data come from
	bool __fastcall Save(String name);
    bool __fastcall SaveandClose(String name);
	void __fastcall CloseData();
	void __fastcall Close();


	// Destination Word
	int  __fastcall getTableCount();
	int  __fastcall getTableRowCount(int index);
	void __fastcall getTable(int index);
	void __fastcall deleteTableRow(int TableIndex, int RowIndex);
	void __fastcall getTableCell(int TableIndex, int RowIndex, int ColumnIndex);
	void __fastcall getTableCellTable(int TableIndex, int RowIndex, int ColumnIndex);
	void __fastcall addTableRow(int index);
	void __fastcall getTableRow(int index, int RowIndex);

	int  __fastcall getInlineShapeCount();
	void __fastcall getInlineShape(int index);
	void __fastcall setInlineShapeHeight(int index, int height);
	void __fastcall setInlineShapeWidth(int index, int width);

	int  __fastcall getBookmarkCount();
	void __fastcall gotoBookmark(String mark);
	void __fastcall setfontName(String name);
	void __fastcall setfontBold();
	void __fastcall setfontSize(int size);
	void __fastcall setfontColor(const int index);
	void __fastcall setText(String text);
	void __fastcall setPic(String file);

    void __fastcall deleteRange();
	void __fastcall copy();
	void __fastcall paste();
	void __fastcall gotoNext();
	void __fastcall insertPageBreak();
	// Data Word
	bool __fastcall getDataTable(int index);
	int  __fastcall test();
};

#endif