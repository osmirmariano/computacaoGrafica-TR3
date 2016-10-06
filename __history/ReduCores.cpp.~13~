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
	//Mudar a cor do Formulário
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


//Função para carregar a imagem


//----------------------------------------------------------------------------

void __fastcall TForm3::Button1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Image1->Picture->LoadFromFile("cg.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
	//ShowMessage("Largura: " + IntToStr(Image1->Width) + " Altura: " + IntToStr(Image1->Height));
	Graphics::TBitmap *Bmp = new Graphics::TBitmap;
	Bmp = Image1->Picture->Bitmap; //Apontando para o endereço da imagem
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
	//Image1->Picture->LoadFromFile("C:\\C:\Users\osmir\Dropbox\Ciência da Computação\5 Período\Computação Gráfica\Trabalho Redução Números de Cores\Win32\Debug.praia1.jpg"); // Carregando imagem
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


int CalcularCor(RGBTRIPLE* pixel){
	int R = pixel->rgbtRed;
	int G = pixel->rgbtGreen;
	int B = pixel->rgbtBlue;

  return ((R*0.21)+(G*0.72)+(B*0.07));

}

int CalcularCor2(RGBTRIPLE* pixel){
	 int valor;
	 int R = pixel->rgbtRed;
	 int G = pixel->rgbtGreen;
	 int B = pixel->rgbtBlue;
	 valor = ((R+G+B)/3);
	 ShowMessage("VALOR DA COR: " + valor) ;
}

void __fastcall TForm3::SpeedButton3Click(TObject *Sender)
{

	Graphics::TBitmap *Bmp = new Graphics::TBitmap;
	Bmp = Image1->Picture->Bitmap; //Apontando para o endereço da imagem
	float Luminosidade;
	//Luminosidade = R*0.3 + G*0.59 + B *0.11;
	int R,G,B, L;

	ShowMessage("Largura: " + IntToStr(Image1->Width));
	ShowMessage(" Altura: " + IntToStr(Image1->Height));
	for(int i = 0; i < IntToStr(Image1->Width); i++) {
		for(int j = 0; j < IntToStr(Image1->Height); j++)
		{
			cor = Image1->Canvas->Pixels[i][j];
			R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			B = GetBValue(cor);  //Retorna Intensidade de cor azul
			L=0.299*R + 0.587*G + 0.114*B;

			Image1->Canvas->Pixels[i][j] = RGB(3,5,255);
			//cont++;
		}
	}

	//Image1->Picture->Assign(Bmp);
	//Image1->Picture->LoadFromFile("C:\\C:\Users\osmir\Dropbox\Ciência da Computação\5 Período\Computação Gráfica\Trabalho Redução Números de Cores\Win32\Debug.praia1.jpg"); // Carregando imagem
	//Image1->Stretch = true; //redimensiona
	//Image1->Refresh(); //atualiza

	TrackBar1->Max = 255;
	TrackBar1->Min = 0;

}
//---------------------------------------------------------------------------



