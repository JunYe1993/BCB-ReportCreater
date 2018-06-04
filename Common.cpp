#include "JunYeClass.h"

void __fastcall Common::SortDouble(vector<double> &nums, int left, int right)
{
	if(left < right){
		double pivot = nums.at((right+left)/2);
		int l = left-1, r = right+1;
		while(l < r){
			while(nums[++l] < pivot);
			while(nums[--r] > pivot);
			if(l < r)
				swap(nums[l], nums[r]);
		}
		SortDouble(nums, left, l-1);
		SortDouble(nums, r+1, right);
	}
}
void __fastcall Common::Timer(unsigned long x){
	long Time;
	Time = GetTickCount();
	while((GetTickCount() - Time) < x){
		if((GetTickCount() - Time) <= 0)
			Time = GetTickCount();
	}
}
void __fastcall Common::CreateReportpath(){
	_wmkdir(L"Report");
}
void __fastcall Common::CreateReportpath(String str){
	_wmkdir(str.w_str());
}
void __fastcall Common::initBugReport(){
	String OutputPath = ExtractFilePath(Application->ExeName) + "Debug.txt";
	FILE *fp = _wfopen(OutputPath.w_str(), L"w+");
	if(!fp)fclose(fp);
}
void __fastcall Common::initDataReport(AnsiString filename){
	String OutputPath = ExtractFilePath(Application->ExeName)+ filename +".txt";
	FILE *fp = _wfopen(OutputPath.w_str(), L"w+");
	if(!fp)fclose(fp);
}
void __fastcall Common::BugReport(AnsiString msg)
{
	AnsiString Path = ExtractFilePath(Application->ExeName);
	Path.cat_sprintf("DeBug.txt");
	FILE *fp = fopen(Path.c_str(), "a+");
	if(!fp)return;
	fprintf(fp, "%s\n", msg);
	fclose(fp);
}
void __fastcall Common::DataReport(AnsiString filename, AnsiString msg)
{
	AnsiString Path = ExtractFilePath(Application->ExeName);
	Path.cat_sprintf("%s.txt", filename.c_str());
	FILE *fp = fopen(Path.c_str(), "a+");
	if(!fp)return;
	fprintf(fp, "%s\n", msg);
	fclose(fp);

}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Files::Files(){
	Dir.Count = 0;
}
TStringList* __fastcall Files::getFiles(String Path, String Ext){
	TStringList *strlist = new TStringList;
	String temp;
	long x;

	//BugReport(Path);
	if(_wchdir(Path.w_str()) == -1){
		BugReport(L"chdir "+Path+" got wrong");
		return NULL;
	}

	struct _finddata_t  file;
	x = _findfirst("*.*", &file);
	temp = file.name;
	if(temp.Pos(Ext))
		strlist->Add(temp);
	while(_findnext(x,&file) == 0){
		temp = file.name;
		if(temp.Pos(Ext))
			strlist->Add(temp);
	}
	_wchdir(L"..");
	return strlist;
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

