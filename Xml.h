#ifndef XMLH
#define XMLH

#include "JunYeClass.h"
#include <vcl.h>
#include <Xml.XMLDoc.hpp>

class Common;
class XML : public Common
{
private:
protected:
	_di_IXMLDocument xmlfile;
	_di_IXMLNode xmlnode;
	String filename;
public:
	XML(String FileName);
	void __fastcall setLayer1Node(String NodeName, bool intoLayer);
	void __fastcall addChildInCurrentNode(String NodeName, bool intolayer);
	void __fastcall addChildInCurrentNode(String NodeName, String Value);
	void __fastcall saveXML();
	void __fastcall test();
	void __fastcall load();
};

#endif
