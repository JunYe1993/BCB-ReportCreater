#ifndef STRINGPARAMETERH
#define STRINGPARAMETERH

const String __tempFileName = "ForProgram_Temp";
const String __saveFileName = "ForProgram_Save";
const String __saveNameCard = "ForProgram_NameCardSave";
const String __prefixNameCard = "ForProgram_NameCard_";

const String __SavePath = "Save\\";
const String __NameCardPath = "NameCard\\";

struct TempFile
{
	String key[100];
	String Stringvalue[100];
	bool boolvalue[100];
	int intvalue[100];
    int count;
};


#endif
