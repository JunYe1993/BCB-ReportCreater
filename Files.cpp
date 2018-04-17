#include "JunYeClass.h"

Files::Files(){
	Dir.Count = 0;
	Dir.ModesCount = 0;
}
void __fastcall Files::getFiles(String path, int layer){
	String temp;
	long x;
	BugReport(path);

	while(_wchdir(path.w_str()) == -1)BugReport(L"chdir got wrong");
	if(layer == 1){
		Dir.Modes[Dir.ModesCount] = path;
		Dir.ModesMap[Dir.ModesCount++][0] = 0;
	}

	struct _finddata_t  file;
	x = _findfirst("*.*", &file);
	temp = file.name;

	if((file.attrib & _A_SUBDIR) && (file.name[0]!='.'))
		if(temp.Pos(L"Mode"))
			getFiles(path+"\\"+temp, layer+1);

	while(_findnext(x,&file) == 0){
		temp = file.name;
		if((file.attrib & _A_SUBDIR) && (file.name[0]!='.'))
			if(temp.Pos(L"Mode")){
				getFiles(path+"\\"+temp, layer+1);
			}

		if(layer == 1 && (temp.Pos(L"xls")>0 || temp.Pos(L"gif")>0 || temp.Pos(L"JPG")>0)){
			Dir.Path[Dir.Count] = path;
			Dir.File[Dir.Count++].sprintf(L"%s\\%s", path, temp);
			Dir.ModesMap[Dir.ModesCount-1][0] += 1;
			Dir.ModesMap[Dir.ModesCount-1][Dir.ModesMap[Dir.ModesCount-1][0]] = Dir.Count-1;
		}
	}
	_wchdir(L"..");
	return;
}
int __fastcall Files::getModeCount(){
	return Dir.ModesCount;
}
int __fastcall Files::getFileCount(){
	return Dir.Count;
}
int __fastcall Files::getModeFileCount(int index){
	String temp1 = index;
	String temp2 = Dir.ModesMap[index][0];
	BugReport("ModesMap [" + temp1 + "] = " +temp2);
	return Dir.ModesMap[index][0];
}
String __fastcall Files::getModeName(int index){
	BugReport(Dir.Modes[index]);
	return Dir.Modes[index];
}
String __fastcall Files::getFile(int index){
	BugReport(Dir.Modes[index]);
	return Dir.File[index];
}
String __fastcall Files::getModeFile(int ModeIndex, int FileIndex){
	int index = Dir.ModesMap[ModeIndex][FileIndex+1];
	BugReport("File = " + Dir.File[index]);
	return Dir.File[index];
}
