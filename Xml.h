#ifndef XMLH
#define XMLH

#include "JunYeClass.h"
#include <Xml.XMLDoc.hpp>

class Files;
class XML : protected Files
{
private:
	bool __fastcall getCurNodeChild(String NodeName);
	bool __fastcall getLayer1Node(String NodeName);
	String __fastcall checkFirstLetter(String str);
protected:
	_di_IXMLDocument xmlfile;
	_di_IXMLNode xmlnode;
	String filename;
public:
	XML(String FileName);
	TStringList* __fastcall getXMLFiles(String Path);
	void __fastcall setLayer1Node(String NodeName, bool intoLayer);
	void __fastcall setLayer2Node(String Layer1NodeName, String NodeName, bool intoLayer);

	bool __fastcall getNode(String Layer1NodeName);
	bool __fastcall getNode(String Layer1NodeName, String Layer2NodeName);
	bool __fastcall getNode(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	bool __fastcall getNode(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
	bool __fastcall getNodeChild(int index);

	void __fastcall addChildInCurrentNode(String NodeName, bool intolayer);
	void __fastcall addChildInCurrentNode(String NodeName, String Value);
	void __fastcall deleteAllChildInCurrentNode();
	////////////////////////////////////////////////////////////////////////////
    String __fastcall getNodeName();
	String __fastcall getNodeName(String Layer1NodeName);
	String __fastcall getNodeName(String Layer1NodeName, String Layer2NodeName);
	String __fastcall getNodeName(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	String __fastcall getNodeName(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
	int __fastcall getNodeIntValue();
	int __fastcall getNodeIntValue(String Layer1NodeName);
	int __fastcall getNodeIntValue(String Layer1NodeName, String Layer2NodeName);
	int __fastcall getNodeIntValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	int __fastcall getNodeIntValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
	bool __fastcall getNodeBoolValue();
	bool __fastcall getNodeBoolValue(String Layer1NodeName);
	bool __fastcall getNodeBoolValue(String Layer1NodeName, String Layer2NodeName);
	bool __fastcall getNodeBoolValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	bool __fastcall getNodeBoolValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
    String __fastcall getNodeValue();
	String __fastcall getNodeValue(String Layer1NodeName);
	String __fastcall getNodeValue(String Layer1NodeName, String Layer2NodeName);
	String __fastcall getNodeValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	String __fastcall getNodeValue(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
    int  __fastcall getNodeChildCount();
	int  __fastcall getNodeChildCount(String Layer1NodeName);
	int  __fastcall getNodeChildCount(String Layer1NodeName, String Layer2NodeName);
	int  __fastcall getNodeChildCount(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName);
	int  __fastcall getNodeChildCount(String Layer1NodeName, String Layer2NodeName, String Layer3NodeName, String Layer4NodeName);
	String __fastcall getNodeChildName(int index);
	String __fastcall getNodeChildValue(int index);
	String __fastcall getNodeChildValue(String NodeName);
	bool __fastcall getNodeChildBoolValue(int index);

	void __fastcall saveXML();
	void __fastcall test();
	void __fastcall load();
};

#endif
