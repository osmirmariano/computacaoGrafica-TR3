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
#include <Vcl.Buttons.hpp>
#include <Vcl.ActnPopup.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.CustomizeDlg.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TLabel *Label3;
	TTrackBar *TrackBar1;
	TImage *Image2;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton6;
	TLabel *Label1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
	int tonalidade;
	int valor;
	TColor cor;
public:		// User declarations

	__fastcall TForm3(TComponent* Owner);
	int TForm3::CalcularCor2(RGBTRIPLE* pixel);
	int TForm3::CalcularCor(RGBTRIPLE* pixel);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
