//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReduCores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Graphics::TBitmap * pict = new Graphics::TBitmap();
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	//Mudar a cor do Formul�rio
	Form3->Color = clWhite;
	TColor cor;
}
//---------------------------------------------------------------------------


//Fun��o para carregar a imagem
void __fastcall TForm3::Button2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	Image1->Picture->LoadFromFile("C:\\praia.jpg"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
	//Image1->Picture->Bitmap->Canvas->Pixels[X][Y] = clRed;
}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------

void __fastcall TForm3::Button1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Image1->Picture->LoadFromFile("C:\\praia.jpg"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
	//ShowMessage("Largura: " + IntToStr(Image1->Width) + " Altura: " + IntToStr(Image1->Height));
	Graphics::TBitmap *Bmp = new Graphics::TBitmap;
	Bmp = Image1->Picture->Bitmap; //Apontando para o endere�o da imagem
	int largura = Bmp->Width;
	int altura = Bmp->Height;

	byte r,g,b, cont;

	//ShowMessage("Largura: " + IntToStr(Image1->Width));
	//ShowMessage(" Altura: " + IntToStr(Image1->Height));
	for(int i = 0; i <= IntToStr(Image1->Width); i++) {
		for(int j = 0; j <= IntToStr(Image1->Height); j++)
		{
			cor = Image1->Canvas->Pixels[i][j];
			r = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			g = GetGValue(cor);  //Retorna Intensidade de cor Verde
			b = GetBValue(cor);  //Retorna Intensidade de cor azul
			if(IntToStr(r) == 255 && IntToStr(g) == 0 && IntToStr(b) == 0){
				Image1->Canvas->Pixels[i][j] = RGB(0,0,0);
			}
			cont++;
		}
	}
	ShowMessage("CONTADOR: " + IntToStr(cont));
	Bmp->SaveToFile("C:\praia1.jpg");

	//Image1->Picture->Assign(Bmp);
	//Image1->Picture->LoadFromFile("C:\\C:\Users\osmir\Dropbox\Ci�ncia da Computa��o\5 Per�odo\Computa��o Gr�fica\Trabalho Redu��o N�meros de Cores\Win32\Debug.praia1.jpg"); // Carregando imagem
	//Image1->Stretch = true; //redimensiona
	//Image1->Refresh(); //atualiza
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Button1Click(TObject *Sender)
{
	//Graphics::TBitmap * copia = new Graphics::TBitmap();

}
//---------------------------------------------------------------------------


int TForm3::CalcularCor(RGBTRIPLE* pixel){
 int R = pixel->rgbtRed;
 int G = pixel->rgbtGreen;
 int B = pixel->rgbtBlue;

  return ((R*0.21)+(G*0.72)+(B*0.07));

}

int TForm3::CalcularCor2(RGBTRIPLE* pixel){
	 int R = pixel->rgbtRed;
	 int G = pixel->rgbtGreen;
	 int B = pixel->rgbtBlue;
	 valor = ((R+G+B)/3);
	 ShowMessage("VALOR DA COR: " + valor) ;
}
