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

