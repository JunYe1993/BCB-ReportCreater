#include "XML.h"

XML::XML(String FileName){
	struct _wffblk file;
	if(FileName.Pos(".xml")<1)
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
TStringList* __fastcall XML::getXMLFiles(String Path){
	TStringList *strlist = getFiles(Path, "xml");
    resetCurPath();
	return strlist;
}
void __fastcall XML::setLayer1Node(String NodeName, bool intoLayer){
	NodeName = checkFirstLetter(NodeName);
	xmlnode = xmlfile->GetDocumentElement();
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
		if(intoLayer){
			xmlnode = xmlnode->AddChild(NodeName);
		}else{
			xmlnode->AddChild(NodeName);
		}
	}else{
		xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
	}
}
void __fastcall XML::setLayer2Node(String Layer1NodeName, String NodeName, bool intoLayer){
	xmlnode = xmlfile->GetDocumentElement();
	if(xmlnode->GetChildNodes()->FindNode(Layer1NodeName) == NULL){
		BugReport("Function Error : XML::setLayer2Node");
		BugReport("The Layer1Node ("+Layer1NodeName+") is not exist!!");
	}else{
		xmlnode = xmlnode->GetChildNodes()->FindNode(Layer1NodeName);
		if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
			if(intoLayer){
				xmlnode = xmlnode->AddChild(NodeName);
			}else{
				xmlnode->AddChild(NodeName);
			}
		}else{
			xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
		}
	}
}
bool __fastcall XML::getNode(String Layer1NodeName){
	Layer1NodeName = checkFirstLetter(Layer1NodeName);
	if(!getLayer1Node(Layer1NodeName)){
		BugReport("Function Error : XML::getNode");
		BugReport("The Layer1Node ("+Layer1NodeName+") is not exist!!");
		return false;
	}
	return true;
}
bool __fastcall XML::getNode(String Layer1NodeName, String Layer2NodeName){
	Layer2NodeName = checkFirstLetter(Layer2NodeName);
	if(getNode(Layer1NodeName)){
		if(!getCurNodeChild(Layer2NodeName)){
			BugReport("Function Error : XML::getNode");
			BugReport("The Layer2NodeName ("+Layer2NodeName+") is not exist!!");
			return false;
		}
	}
	return true;
}
bool __fastcall XML::getNode(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	Layer3NodeName = checkFirstLetter(Layer3NodeName);
	if(getNode(Layer1NodeName, Layer2NodeName)){
		if(!getCurNodeChild(Layer3NodeName)){
			BugReport("Function Error : XML::getNode");
			BugReport("The Layer3NodeName ("+Layer3NodeName+") is not exist!!");
			return false;
		}
	}
	return true;
}
bool __fastcall XML::getNode(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
	Layer4NodeName = checkFirstLetter(Layer4NodeName);
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		if(!getCurNodeChild(Layer4NodeName)){
			BugReport("Function Error : XML::getNode");
			BugReport("The Layer4NodeName ("+Layer4NodeName+") is not exist!!");
			return false;
		}
	}
	return true;
}
bool __fastcall XML::getNode(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName, String Layer5NodeName){
	Layer5NodeName = checkFirstLetter(Layer5NodeName);
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		if(!getCurNodeChild(Layer5NodeName)){
			BugReport("Function Error : XML::getNode");
			BugReport("The Layer5NodeName ("+Layer5NodeName+") is not exist!!");
			return false;
		}
	}
	return true;
}
bool __fastcall XML::getNodeChild(int index){
	if(getNodeChildCount() > 0){
		xmlnode = xmlnode->GetChildNodes()->Get(index);
		return true;
	}else{
		BugReport("Function Error : XML::getNodeChild");
		BugReport("The child index ("+IntToStr(index)+") is not exist!!");
		return false;
	}
}
void __fastcall XML::addChildInCurrentNode(String NodeName, bool intolayer){
	NodeName = checkFirstLetter(NodeName);
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
		if(intolayer)
			xmlnode = xmlnode->AddChild(NodeName);
		else
			xmlnode->AddChild(NodeName);
	}else{
		if(intolayer)
			xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
	}
}
void __fastcall XML::addChildInCurrentNode(String NodeName, String Value){
	NodeName = checkFirstLetter(NodeName);
	if(xmlnode->GetChildNodes()->FindNode(NodeName) == NULL){
		xmlnode->AddChild(NodeName, xmlnode->GetChildNodes()->Count);
		//xmlnode->AddChild(NodeName);
	}
	xmlnode->SetChildValue(NodeName, Value);
}
void __fastcall XML::deleteAllChildInCurrentNode(){
	int num = xmlnode->GetChildNodes()->Count;
	for(int i = 0; i < num; i++)
		xmlnode->GetChildNodes()->Delete(0);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
String __fastcall XML::getNodeName(){
	if(xmlnode == NULL)
		return NULL;
	else
		return checkFirstLetter(xmlnode->GetNodeName());
}
String __fastcall XML::getNodeName(String Layer1NodeName){
	if(getNode(Layer1NodeName)){
		return checkFirstLetter(xmlnode->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeName");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeName(String Layer1NodeName, String Layer2NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName)){
		return checkFirstLetter(xmlnode->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeName");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeName(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		return checkFirstLetter(xmlnode->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeName");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeName(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		return checkFirstLetter(xmlnode->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeName");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeName(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName, String Layer5NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName, Layer5NodeName)){
		return checkFirstLetter(xmlnode->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeName");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
int __fastcall XML::getNodeIntValue(){
	int value;
	if(TryStrToInt(Trim(xmlnode->GetText()), value))
		return value;
	BugReport("Function Error : XML::getNodeIntValue");
	BugReport("Can not translate to Int");
	BugReport("----------------------------------------------------------");
	return 2147483647;
}
int __fastcall XML::getNodeIntValue(String Layer1NodeName){
	int value;
	if(getNode(Layer1NodeName)){
		if(TryStrToInt(Trim(xmlnode->GetText()), value))
			return value;
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("Can not translate to Int");
		BugReport("----------------------------------------------------------");
	}else{
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("----------------------------------------------------------");
	}
	return 2147483647;
}
int __fastcall XML::getNodeIntValue(String Layer1NodeName, String Layer2NodeName){
	int value;
	if(getNode(Layer1NodeName, Layer2NodeName)){
		if(TryStrToInt(Trim(xmlnode->GetText()), value))
			return value;
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("Can not translate to Int");
		BugReport("----------------------------------------------------------");
	}else{
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("----------------------------------------------------------");
	}
	return 2147483647;
}
int __fastcall XML::getNodeIntValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	int value;
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		if(TryStrToInt(Trim(xmlnode->GetText()), value))
			return value;
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("Can not translate to Int");
		BugReport("----------------------------------------------------------");
	}else{
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("----------------------------------------------------------");
	}
	return 2147483647;
}
int __fastcall XML::getNodeIntValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
    int value;
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		if(TryStrToInt(Trim(xmlnode->GetText()), value))
			return value;
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("Can not translate to Int");
		BugReport("----------------------------------------------------------");
	}else{
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("----------------------------------------------------------");
	}
	return 2147483647;
}
int __fastcall XML::getNodeIntValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName, String Layer5NodeName){
	int value;
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName, Layer5NodeName)){
		if(TryStrToInt(Trim(xmlnode->GetText()), value))
			return value;
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("Can not translate to Int");
		BugReport("----------------------------------------------------------");
	}else{
		BugReport("Function Error : XML::getNodeIntValue");
		BugReport("----------------------------------------------------------");
	}
	return 2147483647;
}
bool __fastcall XML::getNodeBoolValue(){
	if(xmlnode->GetText() != "0")
		return true;
	return false;
}
bool __fastcall XML::getNodeBoolValue(String Layer1NodeName){
	if(getNode(Layer1NodeName)){
		if(xmlnode->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeBoolValue");
		BugReport("----------------------------------------------------------");
	}
	return false;

}
bool __fastcall XML::getNodeBoolValue(String Layer1NodeName, String Layer2NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName)){
		if(xmlnode->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeBoolValue");
		BugReport("----------------------------------------------------------");
	}
	return false;
}
bool __fastcall XML::getNodeBoolValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		if(xmlnode->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeBoolValue");
		BugReport("----------------------------------------------------------");
	}
	return false;
}
bool __fastcall XML::getNodeBoolValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		if(xmlnode->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeBoolValue");
		BugReport("----------------------------------------------------------");
	}
	return false;
}
bool __fastcall XML::getNodeBoolValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName, String Layer5NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName, Layer5NodeName)){
		if(xmlnode->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeBoolValue");
		BugReport("----------------------------------------------------------");
	}
	return false;
}
String __fastcall XML::getNodeValue(){
	if(xmlnode == NULL)
		return NULL;
	else
		return xmlnode->GetText();
}
String __fastcall XML::getNodeValue(String Layer1NodeName){
	if(getNode(Layer1NodeName)){
		return xmlnode->GetText();
	}else{
		BugReport("Function Error : XML::getNodeValue");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeValue(String Layer1NodeName, String Layer2NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName)){
		return xmlnode->GetText();
	}else{
		BugReport("Function Error : XML::getNodeValue");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		return xmlnode->GetText();
	}else{
		BugReport("Function Error : XML::getNodeValue");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		return xmlnode->GetText();
	}else{
		BugReport("Function Error : XML::getNodeValue");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
String __fastcall XML::getNodeValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName, String Layer5NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName, Layer5NodeName)){
		return xmlnode->GetText();
	}else{
		BugReport("Function Error : XML::getNodeValue");
		BugReport("----------------------------------------------------------");
	}
	return NULL;
}
int __fastcall XML::getNodeChildCount(){
	if(xmlnode == NULL){
        BugReport("Function Error : XML::getNodeChildCount");
		BugReport("----------------------------------------------------------");
		return -1;
	}
	else
		return xmlnode->GetChildNodes()->Count;
}
int __fastcall XML::getNodeChildCount(String Layer1NodeName){
	if(getNode(Layer1NodeName)){
		return xmlnode->GetChildNodes()->Count;
	}else{
		BugReport("Function Error : XML::getNodeChildCount");
		BugReport("----------------------------------------------------------");
		return -1;
	}
}
int __fastcall XML::getNodeChildCount(String Layer1NodeName, String Layer2NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName)){
		return xmlnode->GetChildNodes()->Count;
	}else{
		BugReport("Function Error : XML::getNodeChildCount");
		BugReport("----------------------------------------------------------");
		return -1;
	}
}
int __fastcall XML::getNodeChildCount(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName)){
		return xmlnode->GetChildNodes()->Count;
	}else{
		BugReport("Function Error : XML::getNodeChildCount");
		BugReport("----------------------------------------------------------");
		return -1;
	}
}
int __fastcall XML::getNodeChildCount(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName){
	if(getNode(Layer1NodeName, Layer2NodeName, Layer3NodeName, Layer4NodeName)){
		return xmlnode->GetChildNodes()->Count;
	}else{
		BugReport("Function Error : XML::getNodeChildCount");
		BugReport("----------------------------------------------------------");
		return -1;
	}
}
String __fastcall XML::getNodeChildName(int index){
    if(getNodeChildCount() > 0){
		return checkFirstLetter(xmlnode->GetChildNodes()->Get(index)->GetNodeName());
	}else{
		BugReport("Function Error : XML::getNodeChildName");
		BugReport("The child index ("+IntToStr(index)+") is not exist!!");
		return NULL;
	}
}
String __fastcall XML::getNodeChildValue(int index){
	if(getNodeChildCount() > 0){
		return xmlnode->GetChildNodes()->Get(index)->GetText();
	}else{
		BugReport("Function Error : XML::getNodeChildName");
		BugReport("The child index ("+IntToStr(index)+") is not exist!!");
		return NULL;
	}
}
String __fastcall XML::getNodeChildValue(String NodeName){
	if(getNodeChildCount() > 0){
		return xmlnode->GetChildNodes()->FindNode(NodeName)->GetText();
	}else{
		BugReport("Function Error : XML::getNodeChildName");
		BugReport("The child name ("+NodeName+") is not exist!!");
		return NULL;
	}
}
bool __fastcall XML::getNodeChildBoolValue(int index){
	if(getNodeChildCount() > 0){
		if(xmlnode->GetChildNodes()->Get(index)->GetText() != "0")
			return true;
	}else{
		BugReport("Function Error : XML::getNodeChildName");
		BugReport("The child index ("+IntToStr(index)+") is not exist!!");
	}
	return false;
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
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////   private   ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool __fastcall XML::getCurNodeChild(String NodeName){
    if(xmlnode->GetChildNodes()->FindNode(NodeName) != NULL){
		xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
		return true;
	}
    return false;
}
bool __fastcall XML::getLayer1Node(String NodeName){
	xmlnode = xmlfile->GetDocumentElement();
	if(xmlnode->GetChildNodes()->FindNode(NodeName) != NULL){
		xmlnode = xmlnode->GetChildNodes()->FindNode(NodeName);
        return true;
	}
    return false;
}
String __fastcall XML::checkFirstLetter(String str){
	int value;
	String msg = str.SubString(1,1);


	if(str.Pos(" ") || str.Pos("-") || str.Pos("@")){
		TReplaceFlags rf = TReplaceFlags()<<rfReplaceAll;
		str = StringReplace(str, L" ", L"_", rf);
		str = StringReplace(str, L"-", L"_", rf);
		str = StringReplace(str, L"(", L"_", rf);
		str = StringReplace(str, L")", L"_", rf);
		str = StringReplace(str, L"'", L"_", rf);
		str = StringReplace(str, L"/", L"_", rf);
		str = StringReplace(str, L"@", L"_", rf);
	}
	if(TryStrToInt(msg, value)){
		return "_"+str;
	}

	msg = str.SubString(2,1);
	if(TryStrToInt(msg, value) && str[1] == '_'){
		return str.SubString(2, str.Length()-1);
	}

	return str;
}

