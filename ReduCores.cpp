//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReduCores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	//Mudar a cor do Formul�rio
	Form3->Color = clWhite;
	TColor cor;
	ComboBox1->Items->Add("4");
	ComboBox1->Items->Add("8");
	ComboBox1->Items->Add("16");
	SpeedButton2->Enabled = false;
	ComboBox1->Enabled = false;
	TrackBar1->Enabled = false;
}
//---------------------------------------------------------------------------


//Fun��o para carregar a imagem


//----------------------------------------------------------------------------

void __fastcall TForm3::Button1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Image1->Picture->LoadFromFile("cg.bmp"); // Carregando imagem
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
   //	Bmp->SaveToFile("C:\praia1.jpg");

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



void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	Image1->Picture->LoadFromFile("cg.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
	SpeedButton2->Enabled = true;
	ComboBox1->Enabled = true;
	TrackBar1->Enabled = true;
	//Image1->Picture->Bitmap->Canvas->Pixels[X][Y] = clRed;

}
//---------------------------------------------------------------------------



void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{
	AnsiString recebe;
	recebe = ComboBox1->Text;
	if(recebe == "4"){
		ShowMessage("4");
	}
	else if(recebe == "8"){
		ShowMessage("8");
	}
	else if(recebe == "16"){
		ShowMessage("16");
	}
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

	  return (R+G+B/3);
}

void __fastcall TForm3::SpeedButton3Click(TObject *Sender)
{

	Graphics::TBitmap *Bmp = new Graphics::TBitmap;
	Bmp = Image1->Picture->Bitmap; //Apontando para o endere�o da imagem
	int R,G,B, L;

	for(int i = 0; i < IntToStr(Image1->Width); i++) {
		for(int j = 0; j < IntToStr(Image1->Height); j++)
		{
			cor = Image1->Canvas->Pixels[i][j];
			R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			B = GetBValue(cor);  //Retorna Intensidade de cor azul
			if (L < 0) {
				L = 0;
			} else if (L > 255) {
				L = 255;
			}
			L = R*0.3 + G*0.59 + B *0.11;
			Image1->Canvas->Pixels[i][j] = RGB(L,L,L);
		}
	}
	TrackBar1->Position  = TrackBar1->Max/2 ;
}
//---------------------------------------------------------------------------



void __fastcall TForm3::SpeedButton2Click(TObject *Sender)
{
	/*Graphics::TBitmap *Bmp = new Graphics::TBitmap;
	Bmp = Image1->Picture->Bitmap; //Apontando para o endere�o da imagem
	int R,G,B, L;

	for(int i = 0; i < IntToStr(Image1->Width); i++) {
		for(int j = 0; j < IntToStr(Image1->Height); j++)
		{
			//cor = Image1->Canvas->Pixels[i][j];
			if(Image1->Canvas->Pixels[i][j] < 100){
				L = 0*0.3 + 0*0.59 + 0 *0.11;
				Image1->Canvas->Pixels[i][j] = RGB(L,L,L);
			}
			else if (Image1->Canvas->Pixels[i][j] > 100){
            	L = 255*0.3 + 255*0.59 + 255*0.11;
				Image1->Canvas->Pixels[i][j] = RGB(L,L,L);
			}

		}
	}
	*/
	int f =0;

   for (int y = 0; y < Image1->Height; y++) {
			int t = (RGBTRIPLE*)Image1->Picture->Bitmap->ScanLine[y] ;
			//int	t = (RGBTRIPLE*)Image1->ScanLine[y];
			for (int x = 0; x < Image1->Width; x++) {
			f = CalcularCor2(t);

			if(f>127){
				t->rgbtRed = 255;
				t->rgbtGreen = 255;
				t->rgbtBlue = 255;
				t++;
			}

			if(f<128){
				t->rgbtRed = 0;
				t->rgbtGreen = 0;
				t->rgbtBlue = 0;
				t++;
			}

			}
		 }
		 Image1->Picture->Assign(pict);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::TrackBar1Change(TObject *Sender)
{
	Graphics::TBitmap * copia = new Graphics::TBitmap;
	copia->Assign(Image1);
	TrackBar1->Max = 255;
	TrackBar1->Min = 0;
	 copia->Assign(Image1);
	 RGBTRIPLE *r;
	 int tb, tt;
	 tb = TrackBar1->Position;
	   if (tb < tom) {
		  tom = tb;
		  tb = tb-TrackBar1->Max;
	   }else{
		 tom = tb;
	   }

	   for (int y = 0; y < Image1->Height; y++) {
				r = (RGBTRIPLE*)Image1->Picture->Bitmap->ScanLine[y]
				for (int x = 0; x < Image1->Width; x++) {
				tt = CalcularCor(r);
				tt =tt+(tb);
				if (tt>255){
					tt= 255;
				}
				if (tt<0){
					tt=0;
				}
				r->rgbtRed = tt;
				r->rgbtGreen = tt;
				r->rgbtBlue = tt;
				r++;
	   }
	}
	Image1->Picture->Assign(copia);
}
//---------------------------------------------------------------------------

