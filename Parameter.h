#ifndef PARAMETERH
#define PARAMETERH

struct _FileData{
	String Name[500];
	String Mark[500];
    int Count;
};

struct __FileData
{
	String File[3000];
	String Path[3000];
	String Mark[3000];
	int Count;

	String Modes[300];
	int ModesMap[300][50];
	int ModesCount;
};

#endif
