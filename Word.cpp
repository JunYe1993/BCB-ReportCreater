#include "JunYeClass.h"

// private
void __fastcall JunYe_Word::getMarks(){
	Wd.Range = Wd.ActiveDoc.OlePropertyGet("BookMarks");
	Wd.BookmarkCount = Wd.Range.OlePropertyGet("Count");
	for(int i = 1; i <= Wd.BookmarkCount; i++){
		Wd.Bookmark[i-1] = Wd.Range.OleFunction("Item",i).OlePropertyGet("Name");
		//BugReport(Wd.Bookmark[i-1]);
	}
}
String __fastcall JunYe_Word::getBookmark(int index){
	return Wd.Bookmark[index];
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// public
JunYe_Word::JunYe_Word(){
	Wd.App = CreateOleObject("Word.Application");
	Wd.Documents = Wd.App.OlePropertyGet("Documents");
}
void __fastcall JunYe_Word::Open(String path){
	Wd.ActiveDoc = Wd.Documents.OleFunction("Open",StringToOleStr(path));
	getMarks();
}
void __fastcall JunYe_Word::OpenData(String path){
	Wd.DataDoc = Wd.Documents.OleFunction("Open",StringToOleStr(path));
}
bool __fastcall JunYe_Word::Save(String name){
    bool flag = true;
    String p = ExtractFilePath(Application->ExeName);
	p.cat_sprintf(L"\\Report\\%s.docx", name);
	try{
		Wd.ActiveDoc.OleFunction("SaveAs", OleStr(p));
	}catch(EOleSysError *e){
		BugReport(p);
		BugReport(L"Save Fail!!");
		flag = false;
	}
	Wd.ActiveDoc.OleFunction("Close", false);
	return flag;
}
bool __fastcall JunYe_Word::SaveandClose(String name){
	bool flag = true;
    String p = ExtractFilePath(Application->ExeName);
	p.cat_sprintf(L"\\Report\\%s.docx", name);
	try{
		Wd.ActiveDoc.OleFunction("SaveAs", OleStr(p));

	}catch(EOleSysError *e){
		BugReport(p);
		BugReport(L"Save Fail!!");
        flag = false;
	}
	Wd.ActiveDoc.OleFunction("Close", false);
	Wd.App.Exec(Procedure("Quit"));
	return flag;
}
void __fastcall JunYe_Word::CloseData(){
	Wd.DataDoc.OleFunction("Close", false);
}
void __fastcall JunYe_Word::Close(){
	Wd.App.Exec(Procedure("Quit"));
}
////////////////////////////////////////////////////////////////////////////////
int __fastcall JunYe_Word::getTableCount(){
    String x = Wd.ActiveDoc.OlePropertyGet("Tables").OlePropertyGet("Count");
	return Wd.ActiveDoc.OlePropertyGet("Tables").OlePropertyGet("Count");
}
int __fastcall JunYe_Word::getTableRowCount(int index){
    String n = index;
	String x = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",index).OlePropertyGet("Rows").OlePropertyGet("Count");
	return Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",index).OlePropertyGet("Rows").OlePropertyGet("Count");
}
void __fastcall JunYe_Word::getTable(int index){
	Wd.Range = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",index).OlePropertyGet("Range");
}
void __fastcall JunYe_Word::deleteTableRow(int TableIndex, int RowIndex){
	Wd.Range = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",TableIndex).OlePropertyGet("Range");
	Wd.Range.OlePropertyGet("Rows").OleFunction("Item",RowIndex).OleFunction("Delete");
}
void __fastcall JunYe_Word::getTableCell(int TableIndex, int RowIndex, int ColumnIndex){
	Variant temp = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",TableIndex);
	Wd.Range = temp.OleFunction("Cell", RowIndex, ColumnIndex).OlePropertyGet("Range");
}
void __fastcall JunYe_Word::getTableCellTable(int TableIndex, int RowIndex, int ColumnIndex){
	//String test;
	//Variant temp = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",TableIndex);
	//temp = temp.OleFunction("Cell", RowIndex, ColumnIndex).OlePropertyGet("Tables");
	//test = temp.OlePropertyGet("Count");
	//BugReport("test : " + test);
	//Wd.Range = temp.OleFunction("Item",1);
	//Wd.Range.OleFunction("Cell", 1, 1).OlePropertyGet("Range").OlePropertySet("Text", OleStr("HAHA"));
}
void __fastcall JunYe_Word::addTableRow(int index){
	Variant temp = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",index);
	Wd.Range = temp.OlePropertyGet("Rows").OleFunction("Add");
}
void __fastcall JunYe_Word::getTableRow(int index, int RowIndex){
	Variant temp = Wd.ActiveDoc.OlePropertyGet("Tables").OleFunction("Item",index);
	Wd.Range = temp.OlePropertyGet("Rows").OleFunction("Item", RowIndex).OlePropertyGet("Range");
}

/////////////////////////////////   SHAPE   ////////////////////////////////////
int __fastcall JunYe_Word::getInlineShapeCount(){
	String x = Wd.ActiveDoc.OlePropertyGet("InlineShapes").OlePropertyGet("Count");
	return Wd.ActiveDoc.OlePropertyGet("InlineShapes").OlePropertyGet("Count");
}
void __fastcall JunYe_Word::getInlineShape(int index){
	Wd.Range = Wd.ActiveDoc.OlePropertyGet("InlineShapes").OleFunction("Item", index);
}
void __fastcall JunYe_Word::setInlineShapeHeight(int index, int height){
	getInlineShape(index);
	Wd.Range.OlePropertySet("Height", height);
}
void __fastcall JunYe_Word::setInlineShapeWidth(int index, int width){
	getInlineShape(index);
	Wd.Range.OlePropertySet("Width", width);
}

//////////////////////////////   BookMark   ////////////////////////////////////
int __fastcall JunYe_Word::getBookmarkCount(){
	return Wd.BookmarkCount;
}
void __fastcall JunYe_Word::gotoBookmark(String mark){
	try{
		Wd.Range = Wd.ActiveDoc.OlePropertyGet("Bookmarks").OleFunction("Item", OleStr(mark)).OlePropertyGet("Range");
	}catch(EOleSysError *e){
		BugReport("BookMark = " + mark);
		BugReport(L"Ranging Fail�ABookMark Doesn't exit or Tty Again Later");
	}
}

void __fastcall JunYe_Word::setfontName(String fontname){
	Wd.Range.OlePropertyGet("Font").OlePropertySet("Name", OleStr(fontname));
}
void __fastcall JunYe_Word::setfontBold(){
	Wd.Range.OlePropertyGet("Font").OlePropertySet("Bold", true);
}
void __fastcall JunYe_Word::setfontSize(int size){
	Wd.Range.OlePropertyGet("Font").OlePropertySet("Size", size);
}
void __fastcall JunYe_Word::setfontColor(const int index){
	//String X =
    Wd.Range.OlePropertyGet("Font").OlePropertySet("ColorIndex", index);
}
void __fastcall JunYe_Word::setText(String text){
	Wd.Range.OlePropertySet("Text", OleStr(text));
}
void __fastcall JunYe_Word::setPic(String file){
	Wd.Range.OlePropertyGet("InlineShapes").OleFunction("AddPicture", OleStr(file));
}

////////////////////////////////   Function   //////////////////////////////////
void __fastcall JunYe_Word::deleteRange(){
	Wd.Range.OleFunction("Delete");
}
void __fastcall JunYe_Word::copy(){
	Wd.Range.OleFunction("Copy");
}
void __fastcall JunYe_Word::paste(){
	Wd.Range.OleFunction("PasteAppendTable");
}
void __fastcall JunYe_Word::gotoNext(){
	Wd.Range = Wd.Range.OleFunction("Next");
}
void __fastcall JunYe_Word::insertPageBreak(){
	//Wd.Range.OleFunction("Collapse", 0);
	Wd.Range.OleFunction("InsertBreak", 7);
}
////////////////////////////////////////////////////////////////////////////////
bool __fastcall JunYe_Word::getDataTable(int index){
	Variant Range;
	bool flag = true;
	try{
		Range = Wd.DataDoc.OlePropertyGet("Tables").OleFunction("Item",index).OlePropertyGet("Range");
	}catch(EOleSysError *e){
		BugReport(L"Ranging Fail�AThis Word doesn't have No."+IntToStr(index)+" Table.");
        	flag = false;
	}
	if(flag){
		Range.OlePropertyGet("Rows").OleFunction("Item",1).OleFunction("Delete");
		Range.OleFunction("Copy");
	}
    return flag;
}
int __fastcall JunYe_Word::test(){
	getInlineShape(3);
	BugReport("Height : " + Wd.Range.OlePropertyGet("Width"));
	return 0;
}