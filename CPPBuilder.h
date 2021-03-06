#ifndef CPPBUILDERH
#define CPPBUILDERH

#include "JunYeClass.h"
#include <Vcl.ValEdit.hpp>
#include <Vcl.CheckLst.hpp>

class INI;
class JunYe_TValueListEditor : protected INI
{
protected :
public :
	void __fastcall deleteAllRow(TValueListEditor* List);
	void __fastcall insertRow(TValueListEditor* List, String Category, String key);
	void __fastcall changeKeyValue(TValueListEditor* List, String Key, String Value);

	void __fastcall setDropList(TValueListEditor* List, int index, TStringList* li);
	TStringList* __fastcall getGender_Eng();
	TStringList* __fastcall getGender_Chi();
};

class JunYe_TCheckListBox : protected INI, Common
{
protected :
public :
	void __fastcall deleteAllRow(TCheckListBox* List);
	bool __fastcall deleteRow(TCheckListBox* List, String Value);
	bool __fastcall addItem(TCheckListBox* List, String Value);
	void __fastcall changeItemValue(TCheckListBox* List, String Item, bool Value);
};

#endif
