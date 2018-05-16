#include "JunYeClass.h"

EN301489_Files::EN301489_Files(){
	Dir.Count = 0;
	Dir.ModesCount = 0;
}
void __fastcall EN301489_Files::getFiles(String path, int layer){
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
int __fastcall EN301489_Files::getModeCount(){
	return Dir.ModesCount;
}
int __fastcall EN301489_Files::getFileCount(){
	return Dir.Count;
}
int __fastcall EN301489_Files::getModeFileCount(int index){
	String temp1 = index;
	String temp2 = Dir.ModesMap[index][0];
	BugReport("ModesMap [" + temp1 + "] = " +temp2);
	return Dir.ModesMap[index][0];
}
String __fastcall EN301489_Files::getModeName(int index){
	BugReport(Dir.Modes[index]);
	return Dir.Modes[index];
}
String __fastcall EN301489_Files::getFile(int index){
	BugReport(Dir.Modes[index]);
	return Dir.File[index];
}
String __fastcall EN301489_Files::getModeFile(int ModeIndex, int FileIndex){
	int index = Dir.ModesMap[ModeIndex][FileIndex+1];
	BugReport("File = " + Dir.File[index]);
	return Dir.File[index];
}
void __fastcall EN301489_Files::sortMode(){
	int num1, num2;
	String temp;
	for(int i = 0; i < Dir.ModesCount-1; i++){
		for(int j = 0; j < Dir.ModesCount-i; j++){
			temp = ExtractFileName(Dir.Modes[i]);
			swscanf(temp.w_str(), L"Mode %d", &num1);
			temp = ExtractFileName(Dir.Modes[i+1]);
			swscanf(temp.w_str(), L"Mode %d", &num2);
			if(num1 > num2){
				Dir.Modes[i].swap(Dir.Modes[i+1]);

				num1 = Dir.ModesMap[i][0];
				Dir.ModesMap[i][0] = Dir.ModesMap[i+1][0];
				Dir.ModesMap[i+1][0] = num1;

				num2 = (Dir.ModesMap[i][0] > num1) ? Dir.ModesMap[i][0] : num1;
				for(int k = 1; k < num2+1; k++){
					num1 = Dir.ModesMap[i][k];
					Dir.ModesMap[i][k] = Dir.ModesMap[i+1][k];
					Dir.ModesMap[i+1][k] = num1;
				}
			}
		}
	}
}
