#ifndef CPPBUILDERH
#define CPPBUILDERH

#include "JunYeClass.h"

class INI;
class JunYe_TValueListEditor : protected INI
{
protected :
public :
	void __fastcall deleteAllRow(TValueListEditor* List);
	void __fastcall saveAllRow(TValueListEditor* List, String category);
	void __fastcall saveAllRow_CommonVersion(TValueListEditor* List, String category, String parameter);
	void __fastcall insertRow(TValueListEditor* List, String Category, String key);
	void __fastcall insertRow_CommonVersion(TValueListEditor* List, String Category, String parameter,String key);

    void __fastcall setDropList(TValueListEditor* List, int index, TStringList* li);
	TStringList* __fastcall getGender_Eng();
	TStringList* __fastcall getGender_Chi();
};

class JunYe_TCheckListBox : protected INI
{
protected :
public :
	void __fastcall deleteAllRow(TCheckListBox* List);
	bool __fastcall deleteRow(TCheckListBox* List, String Value);
	bool __fastcall addItem(TCheckListBox* List, String Value);
	void __fastcall changeItemValue(TCheckListBox* List, String Item, bool Value);

	void __fastcall saveAllRow(TCheckListBox* clb, String category);
	void __fastcall loadAllRow(TCheckListBox* clb, String category);
};

#endif
