#ifndef STRINGPARAMETERH
#define STRINGPARAMETERH

const String __SavePath = "Save\\";
const String __NameCardPath = "NameCard\\";
const String __PicturePath = "Pic\\";
const String __PicturePasdsadh = "QSDDAD\\";

struct TempFile
{
	String key[100];
	String Stringvalue[100];
	bool boolvalue[100];
	int intvalue[100];
	int intarrayvalue[100][100];

	int count;
};

#endif
