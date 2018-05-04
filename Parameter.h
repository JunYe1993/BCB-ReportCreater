#ifndef OleParameterH
#define OleParameterH

//#include <OleServer.hpp>
#include "Comobj.hpp"

const int wdAuto = 0;			//�۰ʮM��A�q�`�w�]���¦�C
const int wdBlack = 1;			//�¦�C
const int wdBlue = 2;			//�Ŧ�C
const int wdBrightGreen = 4;	//�G���C
const int wdByAuthor = -1;		//�Ѥ��@�̩w�q����m�C
const int wdDarkBlue = 9;		//�`�Ŧ�C
const int wdDarkRed = 13;		//�`����C
const int wdDarkYellow = 14;	//�`����C
const int wdGray25 = 16;		//�Ǧ⪺���� 25�C
const int wdGray50 = 15;		//�Ǧ⪺���� 50�C
const int wdGreen = 11;			//���C
const int wdPink = 5;			//������C
const int wdRed = 6;			//����C
const int wdTeal = 10;			//�ź��C
const int wdTurquoise = 3;		//�L���Ŧ�C
const int wdViolet = 12;		//��ù����C
const int wdWhite = 8;			//�զ�C
const int wdYellow = 7;			//����C

const String __tempFileName = "ForProgram_Temp";
const String __saveFileName = "ForProgram_Save";

struct _FileData
{
	String File[3000];
	String Path[3000];
	String Mark[3000];
	int Count;

	String Modes[300];
	int ModesMap[300][50];
	int ModesCount;
};

struct _Excel
{
	Variant App;
	Variant WorkBooks;
	Variant WorkBook;
	Variant WorkSheets;
	Variant WorkSheet;
	Variant Range;
	Variant Cell1;
	Variant Cell2;
	Variant PresentRangeCell;
};

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