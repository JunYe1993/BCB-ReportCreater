#ifndef EXCELPARAMETERH
#define EXCELPARAMETERH

//XlPasteType
const int xlPasteAllExceptBorders = 7;				//會貼上框線以外的一切。
const int xlPasteAllMergingConditionalFormats = 14;	//會貼上一切並且合併條件格式。
const int xlPasteAllUsingSourceTheme = 13;			//會使用來源佈景主題貼上一切。
const int xlPasteColumnWidths = 8;					//會貼上複製的欄寬。
const int xlPasteComments = -4144;					//會貼上註解。
const int xlPasteFormats = -4122;					//會貼上來源格式。
const int xlPasteFormulas = -4123;					//貼上公式。
const int xlPasteFormulasAndNumberFormats = 11;		//會貼上公式和數字格式。
const int xlPasteValidation	= 6;	  				//會貼上驗證。
const int xlPasteValues	= -4163;	  				//會貼上值。
const int xlPasteValuesAndNumberFormats = 12;		//會貼上值和數字格式。

//XlPasteSpecialOperation
const int xlPasteSpecialOperationAdd = 2;			//複製的資料將會新增至目標儲存格中的值。
const int xlPasteSpecialOperationDivide = 5;		//複製的資料會劃分為目標儲存格中的值。
const int xlPasteSpecialOperationMultiply = 4;		//複製的資料會將目標儲存格中的值。
const int xlPasteSpecialOperationNone = -4142;		//不會在貼上作業中進行計算。
const int xlPasteSpecialOperationSubtract = 3;		//複製的資料將會減去目標儲存格中的值

//XIDeleteShiftDirection
const int xlDown = -4121;
const int xlShiftToLeft = -4159;
const int xlToRight = -4161;
const int xlShiftUp = -4162;

//XIHAlign
const int xlCenter = -4108;
const int xlCenterAcrossSelection = 7;
const int xlDistributed = -4117;
const int xlFill = 5;
const int xlGeneral = 1;
const int xlJustify = -4130;
const int xlLeft = -4131;
const int xlRight = -4152;

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
	int PresentRangeCellRow;
	int PresentRangeCellColumn;
};

#endif
