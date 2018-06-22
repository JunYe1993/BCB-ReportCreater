#ifndef WORDPARAMETERH
#define WORDPARAMETERH

//Wd Colors
const int wdAuto = 0;			//自動套色，通常預設為黑色。
const int wdBlack = 1;			//黑色。
const int wdBlue = 2;			//藍色。
const int wdBrightGreen = 4;	//亮綠色。
const int wdByAuthor = -1;		//由文件作者定義的色彩。
const int wdDarkBlue = 9;		//深藍色。
const int wdDarkRed = 13;		//深紅色。
const int wdDarkYellow = 14;	//深黃色。
const int wdGray25 = 16;		//灰色的網底 25。
const int wdGray50 = 15;		//灰色的網底 50。
const int wdGreen = 11;			//綠色。
const int wdPink = 5;			//粉紅色。
const int wdRed = 6;			//紅色。
const int wdTeal = 10;			//藍綠色。
const int wdTurquoise = 3;		//淺粉藍色。
const int wdViolet = 12;		//紫羅蘭色。
const int wdWhite = 8;			//白色。
const int wdYellow = 7;			//黃色。

struct _Word
{
	Variant App;
	Variant Documents;
	Variant ActiveDoc;
	Variant DataDoc;
	Variant Range;
	Variant CurTable;

	int BookmarkCount;
	String Bookmark[3000];
};

#endif
