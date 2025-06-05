
#ifndef _FONT_H_
	#define _FONT_H_

	#include <string.h>

 	#define FONT_HEADER_SIZE  				7 					// header size of fonts
    #define PutPixel(x, y, clr)				ILI9488_Draw_Pixel(x, y, clr)
	// Letter type (English - Persian)
	typedef enum {
		E_LETTER,
	  P_LETTER
	} Lt_Mode;

	/////////////////////////
	extern unsigned char 							rot;
	extern unsigned char 							Reverse;
	extern unsigned char							Horizontal;

	extern unsigned int							    FgColor;
	extern unsigned int							    BkColor;
	extern unsigned char							FontFixed;
	extern unsigned char							NonTransparence;
	
	extern unsigned char 							FontWidth;
	extern unsigned char 							FontHeight;
	extern unsigned char 							FontXScale;
	extern unsigned char 							FontYScale;
	extern unsigned char 							FontSpace;
	
	extern unsigned int 							cursorX;
	extern unsigned int 							cursorY;

	extern Lt_Mode										peLETTER;

	/////////////////////////////////////////////////////////	
	#define GetLetter() 							peLETTER

	#define GetCursorX() 							cursorX
	#define GetCursorY() 							cursorY
	#define SetCursorX(x) 						cursorX = x
	#define SetCursorY(y) 						cursorY = y
	#define SetCursor(x,y) 						{cursorX = x; cursorY = y;}
	
	#define LcdRot(n)									rot = n
	#define LcdReverse(n)							Reverse = n
	#define LcdHorizontal(n)					Horizontal = n
	
	#define LcdFontFixed(n)						FontFixed = n
	#define LcdNonTransparence(n)			NonTransparence = n
	
	#define SetFgColor(c)							FgColor = c
	#define SetBkColor(c)							BkColor = c
	#define GetFgColor()							FgColor
	#define GetBkColor()							BkColor
	
	#define LcdFontXScale(n)					FontXScale = n
	#define LcdFontYScale(n)					FontYScale = n
	
	#define LcdFontSpaceX(n)					FontSpaceX  = n
	#define LcdFontSpaceY(n)					FontSpaceY  = n


	#define LcdFontWidth() 	 					FontWidth
	#define LcdFontHeight()						FontHeight
	
	// complex function
	#define DrawStringAt(l,c,s,fk,bk)			{SetLine(l,c); SetFgColor(fk); SetBkColor(bk); Puts(s);}
	
	//******************* Function Prototypes
	void LcdFont(const unsigned char *pointer);

	void SetLetter(Lt_Mode L);
	void SetLine(unsigned char line,unsigned char column);

	void PutChar(unsigned char c);
	void Puts(char *Text);

#endif	//_FONT_H_
