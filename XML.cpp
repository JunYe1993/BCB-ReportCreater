#include "JunYeClass.h"

void __fastcall JunYe_XML::test(){
	_di_IXMLDocument xml = NewXMLDocument();
	xml->AddChild("Hi");

	_di_IXMLNode root = xml->GetDocumentElement();
	root->AddChild("GG",root->ChildNodes->Count);
	root->AddChild("GG",root->ChildNodes->Count);
	root->AddChild("GGY",2);
	root->Attributes["path"] = "QQ";
	root->SetAttribute("GG", "HIHI");
	root = root->GetChildNodes()->GetNode(1);
	root->SetAttribute("EE","RR");
	//root->SetNodeValue("HAHAHAHAHAHHA");
	root->SetChildValue("EE","LL");
	xml->SaveToFile("netbar.xml");
	xml->Release();
	load();
}
void __fastcall JunYe_XML::load(){
	_di_IXMLDocument xml = NewXMLDocument();
	xml->LoadFromFile(ExtractFilePath(Application->ExeName)+"netbar.xml");

	_di_IXMLNode root = xml->GetDocumentElement();
	root->AddChild("QQ", 0);
	root = root->GetChildNodes()->GetNode(2);
	root->SetChildValue("EE","LLQQQQQQEEEEEEEEEEEEEEEEEEEEEQQQQQQQQQQQQQ");
	xml->SaveToFile("netbar.xml");
}
