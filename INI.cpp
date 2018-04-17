#include "JunYeClass.h"

void __fastcall INI::WriteInt(AnsiString category, AnsiString parameter, int value)
{
	TIniFile *IniFile;
	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
	IniFile->WriteInteger(category, parameter, value);
	delete IniFile;
}
void __fastcall INI::WriteStr(AnsiString category, AnsiString parameter, AnsiString value)
{
	TIniFile *IniFile;
	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
	IniFile->WriteString(category, parameter, value);
	delete IniFile;
}
int  __fastcall INI::ReadInt(AnsiString category, AnsiString parameter)
{
	int value;
	TIniFile *IniFile;
	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
	value = IniFile->ReadInteger(category, parameter, 0);
	delete IniFile;
	return value;
}
AnsiString __fastcall INI::ReadStr(AnsiString category, AnsiString parameter)
{
	AnsiString value;
	TIniFile *IniFile;
	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
	value = IniFile->ReadString(category, parameter, value);
	delete IniFile;
	return value;
}
