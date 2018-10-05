#ifndef WORDH
#define WORDH

#include "Comobj.hpp"
#include "JunYeClass.h"
#include "WordParameter.h"

class Common;
class JunYe_Word : public Common
{
private :
	_Word Wd;
	void __fastcall getMarks();

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

	String __fastcall getBookmark(int index);
    bool __fastcall getBookmark(String mark);
	int  __fastcall getBookmarkCount();
	bool __fastcall gotoBookmark(String mark);
	void __fastcall setfontName(String name);
	void __fastcall setfontBold();
	void __fastcall setfontSize(int size);
	void __fastcall setfontColor(const int index);
	void __fastcall setText(String text);
	void __fastcall setPic(String file);

    void __fastcall deleteRange();
	void __fastcall copy();
	void __fastcall paste();
	bool __fastcall paste_2();
	void __fastcall gotoNext();
	void __fastcall insertPageBreak();
	// Data Word
	bool __fastcall getDataTable(int index);
	int  __fastcall test();
};

#endif
