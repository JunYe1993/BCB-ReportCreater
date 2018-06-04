#include "XML.h"

XML::XML(String FileName){
	struct _wffblk file;
	filename = FileName + ".xml";
	xmlfile = NewXMLDocument();
	if(_wfindfirst(filename.w_str(), &file, 0) == -1){
		xmlfile->AddChild("root");
		xmlnode = xmlfile->GetDocumentElement();
		xmlnode->SetAttribute("Name", ExtractFileName(FileName));
	}else{
		xmlfile->LoadFromFile(filename);
        xmlnode = xmlfile->GetDocumentElement();
	}
}
void __fastcall XML::setLayer1Node(String NodeName, bool intolayer){
    xmlnode = xmlfile->GetDocumentElement();
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
		if(intolayer){
			xmlnode = xmlnode->AddChild(NodeName);
		}else{
			xmlnode->AddChild(NodeName);
		}
	}else{
		xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
	}
}
void __fastcall XML::addChildInCurrentNode(String NodeName, bool intolayer){
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
		xmlnode->AddChild(NodeName);
    }
}
void __fastcall XML::addChildInCurrentNode(String NodeName, String Value){
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
        xmlnode->AddChild(NodeName);
		xmlnode->SetChildValue(NodeName, Value);
	}
}
void __fastcall XML::saveXML(){
	xmlfile->SaveToFile(filename);
	xmlfile->Release();
	xmlnode->Release();
}
void __fastcall XML::test(){
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
void __fastcall XML::load(){
	_di_IXMLDocument xml = NewXMLDocument();
	xml->LoadFromFile(ExtractFilePath(Application->ExeName)+"netbar.xml");

	_di_IXMLNode root = xml->GetDocumentElement();
	root->AddChild("QQ", 0);
	root = root->GetChildNodes()->GetNode(2);
	root->SetChildValue("EE","LLQQQQQQEEEEEEEEEEEEEEEEEEEEEQQQQQQQQQQQQQ");
	xml->SaveToFile("netbar.xml");
}
