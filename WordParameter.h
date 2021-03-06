#ifndef WORDPARAMETERH
#define WORDPARAMETERH

//Wd AlertLevel
const int wdAlertsAll = -1;			//All message boxes and alerts are displayed; errors are returned to the macro.
const int wdAlertsMessageBox = -2;  //Only message boxes are displayed; errors are trapped and returned to the macro.
const int wdAlertsNone = 0;			//No alerts or message boxes are displayed. If a macro encounters a message box, the default value is chosen and the macro continues.

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
