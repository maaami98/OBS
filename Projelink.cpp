#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <string>
#include <windows.h>
#include <time.h>
using namespace std;
void goruntule(struct ogr *kisi,ogr *kafa);
int alnum()
{
	char a=48;
	int i=0;
	do
	{
		
		a=getch();
		
		if(a==27)return -2;
		if(a==13&&i==0)return -1;
		if(a==13)return i;
		if(a<47 || a>58)continue;
		cout<<a-48;
		i=i*10;
		i+=a-48;
	}while(a!=13);
	//cout<<endl;
	
}
void alharf(char b[])
{
	for(int i=0;;i++)
        {
        	b[i]=cin.get();
			if(b[i]=='\n'){b[i]=0;break;
			}
			//if(b[i]<47 || b[i]>58){i--;continue; }//sadece sayý
			if(b[i]<65 || b[i]>122){i--;continue; }
		}
}

template <typename T>
  std::string intostr ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }
struct ogr{
	string ad,soyadi;
	int no=0 ;
	float d[3][8]={{0}};
	string harf[8];
	float ort[9]={0};
	struct ogr *next;
};

void gotoxy(short x,short y)
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

 void tema() 
 {
 	system("mode con: cols=150 lines=40");
 	 SMALL_RECT rect;
    COORD coord;
    coord.X = 150; // Defining our X and
    coord.Y = 40;  // Y size for buffer.

    rect.Top = 0;
    rect.Left = 0;
    rect.Bottom = coord.Y-1; // height for window
    rect.Right = coord.X-1;  // width for window

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
    SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size
    SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size

	setlocale(LC_ALL,"Turkish");
	system("CLS");
	
	gotoxy(5,2);
	int x,y;
	x=20;
	y=10;
	for(int i=0;i<110+x;i++)cout<<"#";
gotoxy(27,3);
std::cout<<"Mami's  Öðrenci Bilgi Sistemi"<<std::endl;
gotoxy(5,4);
cout.width(110+x);
cout.fill('=');
cout<<" ";
for (int i=3;i<20+y;i++)
{
gotoxy(5,i);
cout<<"#";
gotoxy(114+x,i);
cout<<"#";
}
for(int i=5;i<115+x;i++)
{
gotoxy(i,20+y);
cout<<"+";
}
for(int i=5;i<114+x;i++)
{
gotoxy(i,18+y);
cout<<"=";
}

}
string ders[9]={"Atatürk Ýlke ve Ýnkilaplarý","Elektronik","Sayýsal Analiz","Sayýsal Elektronik","Veri Yapýlarý","Mühendislik Matematiði","Elektronik Mühendisliði Öncüleri","Yabancý Dil III","Genel Ortalama"};
void dosya(string k){
	ofstream dosya1; 
    dosya1.open("ogrenci.txt",ios::app); 
    dosya1 << " "<<k; 
    dosya1.close(); //ile dosya kapanýr 

}

void oku(struct ogr *kafa)
{
	if(kafa->no==-1)kafa=kafa->next;	
	tema();
	gotoxy(14,5);cout<<" NO   ADI              SOYADI         ";
	gotoxy(14,6);cout<<"----  ---------------  -------------  ";
	ogr *g=kafa;
	
	
	int x=0;
	for(int y=7;y<28;y++){
	if(g==NULL)break;
		else if(y==27){y=7;x=x+45;
		}
	gotoxy(15+x,y);cout<<g->no;
	gotoxy(20+x,y);cout<<g->ad;
	gotoxy(37+x,y);cout<<g->soyadi;
	
	g=g->next;
	if(g==NULL){getch();return;}
	
	}
	if(g->next!=NULL)
	{
		getch();
		oku(g);
		return;
	}
	getch();
}
struct ogr *numara(struct ogr *head, int n) {
	ogr *cur = head;
	while(cur) {
		if(cur->no == n) return cur;
		cur = cur->next;
		if(cur==NULL)return NULL;
	}
	
}
struct ogr *isimara(struct ogr *head, string n) {
	ogr *cur = head;
	while(cur) {
		if(cur->ad == n) return cur;
		cur = cur->next;
		if(cur==NULL)return NULL;
	}
	
}
struct ogr *soyadara(struct ogr *head, string n) {
	ogr *cur = head;
	while(cur) {
		if(cur->soyadi == n) return cur;
		cur = cur->next;
		if(cur==NULL)return NULL;
	}
	
}
int in=-12;
void bellekal(struct ogr *kafa)
{
	

	ogr *smd=kafa;
	
	ifstream dosya("ogrenci.txt",ios::in); 
	if(dosya==NULL){cout<<"Dostum Dosya Yok";exit(1);
	}
	while(!dosya.eof())
	{
		cout<<"Dosya Bozuk";
		ogr *yeniogr=new ogr;
		yeniogr->next=NULL;
		dosya>>yeniogr->no;
		in=yeniogr->no;
		//cout<<in;
		dosya>>yeniogr->ad;
		dosya>>yeniogr->soyadi;
		for(int i=0;i<3;i++)
		for(int j=0;j<8;j++)
		//yeniogr->d[i][j]=
		
			dosya>>yeniogr->d[i][j];
		
		
		yeniogr->next=NULL;
		//cout<<"work";
		
		//sonu bulup sona eklicez
		/*cout<<yeniogr->ad;
		
		system("pause");*/
		
		while(smd) {
		if(smd->next == NULL) {
			smd->next = yeniogr;
			
			in++;
			//cout<<in;
			break;
		}
		
		smd = smd->next;
		}	
		
	}
	
	dosya.close();
}
void dosyay(struct ogr *h)
{
	
	ofstream d2("ogrenci2.txt",ios::out);
	ogr *g=h;
	if(g->no==-1)g=g->next;
	while(g!=NULL){
		//gotoxy(25,7);cout<<"Dosyaya Yazýlan: "<<g->ad<<endl;;
		//getch();
	
	d2<<" "<<intostr(g->no)<<" "<<g->ad<<" "<<g->soyadi;
	for(int i=0;i<3;i++)
	for(int j=0;j<8;j++)
	{
		d2<<" "<<intostr(g->d[i][j]);
	}
	
	g=g->next;
	}
	d2.close();
	system("del ogrenci.txt");system("rename ogrenci2.txt ogrenci.txt");
	
	}
float ort(struct ogr *o)
{
	
	float s=0;
	
	for(int i=0;i<8;i++)
	{
	
	if(o->d[2][i]!=-4){
		o->ort[i]=o->d[2][i]*0.6+o->d[0][i]*0.4;
	s+=o->d[2][i]*0.6+o->d[0][i]*0.4;
	
	}
	else {
		o->ort[i]=o->d[1][i]*0.6+o->d[0][i]*0.4;
		s+=o->d[1][i]*0.6+o->d[0][i]*0.4;
	
	}
	}
	s=s/(8*20);
	o->ort[8]=s;
	return s;
}

void but(struct ogr *kafa)
{
	ogr *k=kafa;
	while(k!=NULL)
	{
		for(int i=0;i<8;i++)
		
		{
			ort(k);
			float ort=k->d[1][i]*0.6+k->d[0][i]*0.4;//Vize ve Final Ortalamasý
			if(ort>50 && k->d[1][i]>=35)k->d[2][i]=-4;//Ortalama iyise ve final 35 üstüyse büte girme
			if(k->d[2][i]!=-4)//Büte Girdiysen
			{
				ort=k->d[2][i]*0.6+k->d[0][i]*0.4;
			
			}
			
			
					
			
			
				if(ort>93)k->harf[i]="AA";
					else if(ort>86)k->harf[i]="BA";
						else if(ort>89)k->harf[i]="BB";
							else if(ort>72)k->harf[i]="CB";
								else if(ort>64)k->harf[i]="CC";
									else if(ort>57)k->harf[i]="DC";
										else if(ort>49)k->harf[i]="DD";
											else if(ort>44)k->harf[i]="FD";
												else {
													k->harf[i]="FF";
													k->d[2][i]=0;
												}
											
		}
		k=k->next;
	}
}
int num(struct ogr *o)
{
	ogr *y=o;
	int i=0;
	while(o->next!=NULL)
	{
		//gotoxy(0,0);
		i++;
		o=o->next;
	}
	
	return i;
}
bool sil(struct ogr *del, ogr *kafa)
{
	ogr *g=kafa;
	while(g)
	{
		if(g->next==del){
			g->next=del->next;
			delete del;
			return true;
		}
		g=g->next;
	}
	
	return false;
	
	
}
void goruntule(struct ogr *kisi,ogr *kafa)
{
	tema();
	but(kafa);
	gotoxy(25,7);
	if(kisi==NULL){cout<<"Öðrenci Bulunamadý.";return;}
	gotoxy(7,7);cout<<"Numarasý:"<<kisi->no;
	gotoxy(7,8);cout<<"Adý:"<<kisi->ad;
	gotoxy(7,9);cout<<"Soyadý:"<<kisi->soyadi;
	gotoxy(7,10);cout<<"Ortalamasý:";printf("%.02f",ort(kisi));
	//gotoxy(25,7);
	
	//BAÞLIKLAR
	for(int i=0;i<8;i++)
	{
		gotoxy(25,7+i*2);
		cout<<i<<") "<<ders[i];
	}
	gotoxy(63,5);cout<<"Vize";
	gotoxy(78,5);cout<<"Final";
	gotoxy(94,5);cout<<"Büt";
	gotoxy(110,5);cout<<"Harf Notu";
	gotoxy(80,29);cout<<"Esc=Çýkýþ\tD=Düzenleme\tS=Silme";
	//TABLO OLUÞTURMA
	for(int i=0;i<109;i++)
	{
		for(int f=0;f<9;f++)
		{
			gotoxy(24+i,6+f*2);cout<<"-";
		
		}
	}
	for(int i=0;i<23;i++)
	{gotoxy(23,5+i);cout<<"|";
	gotoxy(60,5+i);cout<<"|";
	gotoxy(75,5+i);cout<<"|";
	gotoxy(90,5+i);cout<<"|";
	gotoxy(100,5+i);cout<<"|";
		}
		
		//NOT GÝRÝÞLERÝ
	for(int i=0;i<8;i++)
	{
		gotoxy(63,7+i*2);cout<<kisi->d[0][i];//Vize
		gotoxy(79,7+i*2);cout<<kisi->d[1][i];gotoxy(95,7+i*2);//Final
		if(kisi->d[2][i]!=0&&kisi->d[2][i]!=-4)cout<<kisi->d[2][i];//Büt
		else if(kisi->d[2][i]!=-4)cout<<kisi->d[2][i];
			else cout<<"-";
		
		gotoxy(117,7+i*2);cout<<kisi->harf[i];//Harf Notu
	}
	//SÝLME 
	char s=getch();
	if(s=='s'||s=='S'){
		tema();gotoxy(26,7);cout<<"Silmek Ýstediðinize emin misin ?";
		gotoxy(28,9);cout<<"EVET=ENTER         HAYIR=ESC";
		if(getch()==13){
			if(sil(kisi,kafa)){
				tema();
				gotoxy(28,9);cout<<"Silindi";
				Sleep(1000)	;
				return;
			}
		}
	}
	else if(s=='d'||s=='D')
	//DÜZENLEME
	{
		gotoxy(80,29);cout<<"Esc=Atla   ";
		gotoxy(60,29);cout<<"Enter=Geç & Onayla   ";
		getch();
		char b[20]={0};
		int a;
		gotoxy(16,7);
		a=alnum();
		if(a!=-1&&a!=-2)
		kisi->no=a;
		gotoxy(11,8);
		for(int i=0;i<12;i++)
		cout<<" ";
		gotoxy(11,8);
		alharf(b);
		if(b[0]!=0)
		kisi->ad=b;b[20]={0};
		gotoxy(14,9);
		for(int i=0;i<9;i++)
		cout<<" ";
		gotoxy(14,9);
		alharf(b);
		if(b[0]!=0)
		kisi->soyadi=b;
		b[20]={0};
		
		for(int i=0;i<2;i++)
		for(int j=0;j<8;j++)
		{
		gotoxy(63+i*16,7+j*2);
		a=alnum();
		if(a!=-1)
		{
			if(a==-2)break;//esc basýlýnca
			kisi->d[i][j]=a;
		}
		
		}
		but(kafa);
		for(int j=0;j<8;j++)//büte özel yazma
		{
			if(kisi->d[2][j]!=-4&&kisi->d[2][j]!=0)
			{
				gotoxy(95,7+j*2);
				a=alnum();
			if(a!=-1)
			{
				if(a==-2)break;//esc basýlýnca
				kisi->d[2][j]=a;
			}
			
			}
		}
		
	}
	else if(s==27)return;
	//but(kafa);
	goruntule(kisi,kafa);
}

void edit(struct ogr *kafa)
{
	tema();
	int a;
	string n;
	gotoxy(25,5);cout<<"Neye Göre aramak Ýstersiniz ? ";
	gotoxy(25,8);cout<<"1) Numara  2)Ýsim 3)Soyisim";
	switch(getch())
	{
		case '1':{tema();gotoxy(25,5);cout<<"Numarasýný Giriniz :";cin>>a;goruntule(numara(kafa,a),kafa);
			break;
		}
		case '2':{tema();gotoxy(25,5);cout<<"Ýsmini Giriniz :";cin>>n;goruntule(isimara(kafa,n),kafa);
			break;
		}
		case '3':{tema();gotoxy(25,5);cout<<"Soyismini Giriniz :";cin>>n;goruntule(soyadara(kafa,n),kafa);
			break;
		}
	}
		
}
void sinif(struct ogr *o,int a);
void sirala(ogr *o, int a,int f)
{
			ogr *ilk, *orta, *son;
			
			if(f==1)
			{
			
				ilk=o;
			
				while(son->next!=NULL)
				{
				orta=ilk->next;
				son=orta->next;
				
				if(orta->ort[a] < son->ort[a])
				{
					
					ilk->next=son;
					orta->next=son->next;
					son->next=orta;
					ilk=o;
				}
				else
				ilk=orta;
				}
			}
			if(f==2)
			{
				ilk=o;
			
				while(son->next!=NULL)
				{
				orta=ilk->next;
				son=orta->next;
				
				if(orta->ort[a] > son->ort[a])
				{
					
					ilk->next=son;
					orta->next=son->next;
					son->next=orta;
					ilk=o;
				}
				else
				ilk=orta;
				}
			}
			if(f==3)
			{
				ilk=o;
			
				while(son->next!=NULL)
				{
				orta=ilk->next;
				son=orta->next;
				
				if(orta->no > son->no)
				{
					
					ilk->next=son;
					orta->next=son->next;
					son->next=orta;
					ilk=o;
				}
				else
				ilk=orta;
				}
			}

sinif(o,a);
}
void sinif(struct ogr *o,int a)
{
	
	tema();
	ogr *k=o;
	//k=k->next;
	int y=0,x=0;
	gotoxy(25,5);cout<<ders[a];
	gotoxy(17,6);cout<<" NO   ADI              SOYADI         NOTU  ";
	gotoxy(17,7);cout<<"----  ---------------  -------------  -------";
	
	while(k->next!=NULL)
	{
		k=k->next;
		gotoxy(18+x,y+8);cout<<k->no;
		gotoxy(24+x,8+y);cout<<k->ad;
		gotoxy(40+x,8+y);cout<<k->soyadi;
		gotoxy(58+x,8+y);printf("%0.02f",k->ort[a]);
		y++;
		if(y==18){x+=50;y=0;
		}
	}
	//cout<<a;
	gotoxy(20,29);cout<<"1=Büyükten Küçüðe Sýrala\t2=Küçükten Büyüðe Sýrala\t3=Numaraya Göre sýrala";
	//k=k->next;
	char f=getch();
	f=f-48;
	if(f==1)sirala(o,a,f);
	if(f==2)sirala(o,a,f);
	if(f==3)sirala(o,a,f);		
	
}
void oekle(struct ogr *kafa)
{
	
	ogr *yeniogr=new ogr;
	yeniogr->no=in;
	gotoxy(31,6);
	cout<<"Adi:";
	cin>>yeniogr->ad;;
	gotoxy(31,7);
	cout<<"Soyadý:";
	cin>>yeniogr->soyadi;
	gotoxy(31,8);
	cout<<"Numarasý:"<<yeniogr->no;
	ogr *smd=kafa;
	yeniogr->next=NULL;
	//random not
	for(int i=0;i<3;i++)
	for(int j=0;j<8;j++)
	yeniogr->d[i][j]=rand()%100;
		//getch();
		//sonu bulup sona eklicez
		while(smd) {
		if(smd->next == NULL) {
			smd->next = yeniogr;
			in++;
			goruntule(yeniogr,kafa);
			
			return ;
		}
		
		smd = smd->next;
		}	
	cout<<"HATA";
	getch();
	
	

	
	
}
int notg(struct ogr *g,int d,int k)
{
	tema();
	ogr *bas=g;
//	cout<<endl<<"D:"<<d<<endl;
	if(g->no==-1)g=g->next;
	for(int i=0;i<127;i++)
	{
		for(int f=0;f<11;f++)
		{
			gotoxy(7+i,6+f*2);cout<<"-";
		
		}
	}
	for(int i=0;i<23;i++)
	{gotoxy(13,5+i);cout<<"|";//no sonu
	gotoxy(60,5+i);cout<<"|";// ad soyad sonu
	gotoxy(75,5+i);cout<<"|";
	gotoxy(90,5+i);cout<<"|";
	gotoxy(100,5+i);cout<<"|";
		}
	gotoxy(10,5);cout<<"NO";
	gotoxy(20,5);cout<<"Ýsim";
	gotoxy(37,5);cout<<"Soyisim";
	gotoxy(65,5);cout<<"Vize";
	gotoxy(81,5);cout<<"Final";
	gotoxy(95,5);cout<<"Büt";
	gotoxy(115,5);cout<<"Harf Notu";
	if(k==0)
	{gotoxy(30,29);cout<<"Esc=Çýkýþ\tK=Not Giriþ\tSonraki Sayfa=Herhangi bir tus";
	}
	else
	{gotoxy(60,29);cout<<"Çýkýþ=Herhangi bir nota -1 girin";
	}
	
	int u;
	
	///Yazdýrma Baþý
	for(int y=0;y<28;y++){
	if(g==NULL)break;
		else if(y==11){char nk=getch();
	if(nk=='k'||nk=='K'){
		k=1;
		notg(bas,d,k);
		return 0;
	}
	if(nk==27)return 1;
	notg(g,d,k);return 0;
		
		
		}
	gotoxy(10,7+y*2);cout<<g->no;
	gotoxy(20,7+y*2);cout<<g->ad;
	gotoxy(37,7+y*2);cout<<g->soyadi;
	gotoxy(65,7+y*2);if(k==0)cout<<g->d[0][d];
	else
	{
		cin>>u;
		if(u==-1)return 0;
		g->d[0][d]=u;
	}
	gotoxy(81,7+y*2);if(k==0)cout<<g->d[1][d];
	else
	{
		cin>>u;
		if(u==-1)return 0;
		g->d[1][d]=u;
	}
	but(g);
	if(g->d[2][d]!=-4){gotoxy(95,7+y*2);
	{
		if(k==0)
	cout<<g->d[2][d];	else{
		cin>>u;
		if(u==-1)return 0;
		g->d[2][d]=u;
	}
	}
	
	
	}
	but(g);
	gotoxy(115,7+y*2);cout<<g->harf[d];
	
	
	g=g->next;
	
	
	}
	if(g==NULL){getch();return 0;
	
	}
}
int main()
{
		srand (time(NULL));
		setlocale(LC_ALL,"Turkish");
		struct ogr *o=new ogr;
		o->no=-1;
		o->next=NULL;
		
		bellekal(o);
		
		but(o);
		
		//dosyay(o);
		char a=1;
		while(1){
		
		tema();
		gotoxy(30,5);cout<<"1) Öðrenci Ekle ";
		gotoxy(30,6);cout<<"2) Öðrenci Listele ";
		gotoxy(30,7);cout<<"3) Öðrenci Düzenleme ";
		gotoxy(30,8);cout<<"4) Sýnýf Düzeyi ";
		gotoxy(30,9);cout<<"5) Not Giriþi ";
		gotoxy(30,11);cout<<"6) Çýkýþ ";
		gotoxy(37,19);cout<<"Mevcut Öðrenci Sayýsý :"<<num(o);
		//cout<<endl<<o->next->d[1][0];
		a=getch();
		tema();
		switch(a)
			{
				case '1':{oekle(o);//dosyay(o);
					break;
				}
				case '2':{oku(o);
					break;
				}
				case '3':{
					edit(o);
					break;
				}
				case '4':{
					ort(o);
					tema();
					for(int i=0;i<9;i++)
					{
						gotoxy(25,7+i);cout<<i<<") "<<ders[i];
					}
					int a=0;
					
					while(a<47 || a>58)a=getch();
					sinif(o,a-48);
					break;
				}
				case '5':{gotoxy(25,5);cout<<"Ders Seçiniz";
					for(int i=0;i<8;i++)
					{
						gotoxy(25,7+i);cout<<i<<") "<<ders[i];
					}
					int a=0;
					
					while(a<47 || a>58)a=getch();
					while(!notg(o,a-48,0));
					break;
				}
				case '6':{dosyay(o);exit(1);
					break;
				}
			}
		
		
		dosyay(o);
		
		}
		//oku(o);
		
		//cout<<o.d[2].bnot;
	
}
