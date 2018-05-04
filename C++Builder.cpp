#include "JunYeClass.h"

void __fastcall JunYe_TValueListEditor::deleteAllRow(TValueListEditor* List){
	int rowcount = List->RowCount;
	if(rowcount > 1 && List->Keys[1] != ""){
		for(int i = 1; i < rowcount; i++){
			List->DeleteRow(1);
		}
	}
}
void __fastcall JunYe_TValueListEditor::saveAllRow(TValueListEditor* List, String Category){
	int rowcount = List->RowCount;
	if(rowcount > 1 && List->Keys[1] != ""){
		for(int i = 1; i < rowcount; i++){
			WriteStr(Category, List->Name + List->Keys[i], List->Values[List->Keys[i]]);
		}
	}
}
void __fastcall JunYe_TValueListEditor::insertRow(TValueListEditor* List, String Category, String key){
	String value = ReadStr(Category, List->Name + key);
	List->InsertRow(key, value, true);
}

void __fastcall JunYe_TValueListEditor::setDropList(TValueListEditor* List, int index, TStringList* li){
    List->ItemProps[index]->EditStyle = esPickList;
	List->ItemProps[index]->PickList = li;
	List->ItemProps[index]->ReadOnly = true;
}
TStringList* __fastcall JunYe_TValueListEditor::getGender_Eng(){
    TStringList *stringlist = new TStringList;
	stringlist->Add("Male");
	stringlist->Add("Female");
	return stringlist;
}
TStringList* __fastcall JunYe_TValueListEditor::getGender_Chi(){
    TStringList *stringlist = new TStringList;
	stringlist->Add("�k");
	stringlist->Add("�k");
	return stringlist;
}
