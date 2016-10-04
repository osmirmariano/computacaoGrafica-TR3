//---------------------------------------------------------------------------

#ifndef ReduCoresH
#define ReduCoresH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Jpeg.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	int tom;
	int valor;
	TColor cor;
public:		// User declarations
	//int tonalidade;
	__fastcall TForm3(TComponent* Owner);
	int TForm3::CalcularCor2(RGBTRIPLE* pixel);
	int TForm3::CalcularCor(RGBTRIPLE* pixel);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
