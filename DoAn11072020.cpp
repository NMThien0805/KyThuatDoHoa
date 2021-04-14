#include <iostream>
#include <graphics.h>
#include <math.h>
#define DELAY 1
#include <conio.h>
#include <string>

using namespace std ;

//string ngay_lam = "16 + 17";

int chon = 1;

int color = 15;
int color_clear = 0;
int colorG = 2;
int colorR = 4;
int colorOr = 12;
int colorGra = 8;

int dai = 1300;
int rong = 700;
int size = 5;

int choose_2D = 1;

int Ox_3D = 305;
int Oy_3D = 405;
int x_3D;
int y_3D;
int z_3D;
int canh_3D;
int cao_3D;
int R_3D;
char kitu_truoc = 13; //13 la Enter
int kt_play = 1; // 0 la 2D; 1 la 3D
int nho_3D = 3; //0 la Cube, 1 la Pyramid

int kt_grid = 0;
int phep_chieu = 2; //cabinet = 2; cavarier = 1;

int toa_do_diem_Cube[8][3];
int toa_do_diem_Cylinder[12][3];
int toa_do_diem_Pyramid[5][3];
int arr_cheo_cat_mp[4][2];

int lam_tron(double a){
	double b = int(a) + 0.5;
	if (b < a){
		return int(a) + 1;
	}
	else{
		return a;
	}
}

int chieu_x(int x, int z){
	int KQ = x - lam_tron((z * sqrt(2)) / (2 * phep_chieu));
	return KQ;
}

int chieu_y(int y, int z){
	int KQ = y - lam_tron((z * sqrt(2)) / (2 * phep_chieu));
	return KQ;
}

void putdiem(int a, int b, int color){
	int tam1 = a;      
	int tam2 = b;  
	for (int i= -1;i<=1;i++){                                                            
	   for (int j=-1;j<=1;j++){                                                         
			putpixel(tam1+i, tam2+j, color);
		}
	}
}

void Bresenham(int x1, int y1, int x2, int y2, int color, int xdinh) { 
    int c2, c, Dx, Dy, x, y;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    c = Dx - Dy;
    c2 = 2*c;
    x = x1;
    y = y1;
    int an = 4;
	int hien = 5; 
     
    int x_unit = 1, y_unit = 1;
     
    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;
	
	if (xdinh == 1){
		putdiem(x, y, color);
		if (x1 == x2)   // duong thang dung
    	{
        	while (y != y2)
        	{
            	//delay(DELAY);
            	y += y_unit;
            	putdiem(x, y, color);
        	}
    	}
     
    	else if (y1 == y2)  // duong ngang
    	{
        	while (x != x2)
        	{
            	//delay(DELAY);
            	x += x_unit;
            	putdiem(x, y, color);
        	}
    	}
     
    	else if (x1 != x2 && y1 != y2)  // duong xien
    	{
    	    while(x != x2+1)
    	    {
	            //delay(DELAY);
	            c2 =2*c;
	            if (c2 > -Dy)    
	            {
	                c = c - Dy; 
	                x = x + x_unit;
	            }
	            if (c2 < Dx) 
	            {
                	c = c + Dx; 
            	    y = y + y_unit; 
            	}
           		putdiem(x, y, color);
        	}
    	}
	}
	if (xdinh == 0){
		putdiem(x, y, color);
		if (x1 == x2)   // duong thang dung
    	{
        	while (y != y2)
        	{
            	//delay(DELAY);
            	y += y_unit;
            	if (hien > 0){
            		putdiem(x, y, color);
            		hien = hien - 1;
				}
				else if ((an > 0) && (hien <= 0)){
					an = an - 1;
				}
				else if ((an <= 0) && (hien <= 0)){
					an = 4;
					hien = 6;
				}
        	}
    	}
     
    	else if (y1 == y2)  // duong ngang
    	{
        	while (x != x2)
        	{
            	//delay(DELAY);
            	x += x_unit;
            	if (hien > 0){
            		putdiem(x, y, color);
            		hien = hien - 1;
				}
				else if ((an > 0) && (hien <= 0)){
					an = an - 1;
				}
				else if ((an <= 0) && (hien <= 0)){
					an = 4;
					hien = 5;
				}
        	}
    	}
     
    	else if (x1 != x2 && y1 != y2)  // duong xien
    	{
    	    while(x != x2+1)
    	    {
	            //delay(DELAY);
	            c2 =2*c;
	            if (c2 > -Dy)    
	            {
	                c = c - Dy; 
	                x = x + x_unit;
	            }
	            if (c2 < Dx) 
	            {
                	c = c + Dx; 
            	    y = y + y_unit; 
            	}
           		if (hien > 0){
            		putdiem(x, y, color);
            		hien = hien - 1;
				}
				else if ((an > 0) && (hien <= 0)){
					an = an - 1;
				}
				else if ((an <= 0) && (hien <= 0)){
					an = 4;
					hien = 6;
				}
        	}
    	}
	}
}	

void Clear_Area(int x1, int y1, int x2, int y2){
	setfillstyle(1, BLACK);
	bar(x1, y1, x2, y2);
}

void ve_hcn(int x1, int y1, int x2, int y2, int size_vien, int hcn_color){
	setcolor(hcn_color);
	for (int i = 0; i< size_vien; i++){
		line(x1, y1 + i, x2, y1 + i);
		line(x1, y2 - i, x2, y2 - i);
		line(x1 + i, y1, x1 + i, y2);
		line(x2 - i, y1, x2 - i, y2);
	}
	setcolor(color);
}

void thong_bao(string s, int size_chu, int so_hang){
	string arr[so_hang];
	int j = 0;
	for (int i = 0; i < s.length(); i++){
		if(int(s[i]) == 124){
			j++;
		}
		else{
			arr[j] = arr[j] + s[i];
		}
	}
	int x1 = dai - 450 - 5 + 1;
	int y1 = 5 + 50 + 5 + 50 + 5 - 1;
	int x2 = dai;
	int y2 = 5 + 50 + 5 + 50  + 75 - 5 - 1;
	Clear_Area(x1, y1, x2, y2);
	for (int j = 0; j < so_hang; j++){
		const char* str1 = arr[j].c_str();
		char* str = new char[strlen(str1) + 1];
		strcpy(str, str1);
		
		settextstyle(0, 0, size_chu);
		ve_hcn(x1, y1, x2, y2, 5, color);
		outtextxy(x1 + 450 / 2 - textwidth(str) / 2, y1 + (70 / so_hang) * j + (70 / so_hang) / 2 - textheight(str) / 2, str);
	}
}

int be_hon(int a, int b){
	if (a<=b){
		return a;
	}
	else{
		return b;
	}
}

void ve_table(int x0, int y0, int row, int column, int kcach, int  ngang_o, int doc_o){
	
	int xgoc_duoi_phai = x0 + ngang_o * column;
	int ygoc_duoi_phai = y0 + row * doc_o + kcach;
	ve_hcn(x0, y0 + kcach, xgoc_duoi_phai, ygoc_duoi_phai, 3, color);
	for (int i = 1; i < row; i++){
		line(x0, y0 + kcach + (i * doc_o) - 2, xgoc_duoi_phai, y0 + kcach + (i * doc_o) - 2);
		line(x0, y0 + kcach + (i * doc_o) - 1, xgoc_duoi_phai, y0 + kcach + (i * doc_o) - 1);
		line(x0, y0 + kcach + (i * doc_o), xgoc_duoi_phai, y0 + kcach + (i * doc_o));
	}
	for (int i = 1; i < column; i++){
		line(x0 + i * ngang_o, y0 + kcach, x0 + i * ngang_o, ygoc_duoi_phai);
		line(x0 + i * ngang_o + 1, y0 + kcach, x0 + i * ngang_o + 1, ygoc_duoi_phai);
		line(x0 + i * ngang_o + 2, y0 + kcach, x0 + i * ngang_o + 2, ygoc_duoi_phai);
	}
}

char *chuyen(int so){
	string s;
	int so1 = abs(so);

	while (so1 > 0){
		s = char(so1 % 10 + 48) + s;
		so1 = so1 / 10;
	}
	
	if(so == 0){
		s = "0";
	}
	
	if(so < 0){
		s = "-" + s;
	}
	
	const char* str1 = s.c_str();
	char* str = new char[strlen(str1) + 1];
	strcpy(str, str1);
	//cout << endl << str1;

	return str;
}

void nhap_so(int x, int y, int xdinh_o){
	char key;
	int stop = 0;
	int tam = 0;
	char *s;
	int dau_so_3D = 1;
	delete(s);
	
	thong_bao("ENTER de ket thuc nhap!!!", 2, 1);
	
	while (stop == 0){
		key = getch();
		//cout << int(key) << "|";
		if ((int(key) > 47) && (int(key)<58)){
			tam = (tam * 10) + int(key) - 48;
			if (abs(tam) > 200){
				stop = 1;
				kitu_truoc = 13;
			}
			else{
				kitu_truoc = key;
				int tam1 = tam * dau_so_3D;
				//cout << tam1;
				s = chuyen(tam1);
				Clear_Area(x + 3, y + 5 + 3, x + 3 + 94, y + 5 + 3 + 34);
				settextstyle(0, 0 , 3);
				outtextxy(x + 100/2 - textwidth(s)/2, y + 5 + 40/2 - textheight(s)/2, s);
			}
		}
		else if(int(key) == 13){
			if(kitu_truoc == 13){
				while(int(key) == 13){
					kitu_truoc = key;
					key = getch();
				}
				tam = (tam * 10) + int(key) - 48;
				s = chuyen(tam);
				Clear_Area(x + 3, y + 5 + 3, x + 3 + 94, y + 5 + 3 + 34);
				settextstyle(0, 0 , 3);
				outtextxy(x + 100/2 - textwidth(s)/2, y + 5 + 40/2 - textheight(s)/2, s);
				kitu_truoc = key;
			}
			else{
				stop = 1;
				kitu_truoc = 13;
			}
		}
		else if(int(key) == 8){
			tam = tam / 10;
			kitu_truoc = tam%10;
			s = chuyen(tam);
			Clear_Area(x + 3, y + 5 + 3, x + 3 + 94, y + 5 + 3 + 34);
			settextstyle(0, 0 , 3);
			outtextxy(x + 100/2 - textwidth(s)/2, y + 5 + 40/2 - textheight(s)/2, s);
		}
		else if((int(key) == 9) && (tam == 0)){
			dau_so_3D = dau_so_3D * (-1);
			Clear_Area(x + 3, y + 5 + 3, x + 3 + 94, y + 5 + 3 + 34);
			settextstyle(0, 0 , 3);
			outtextxy(x + 100/2 - textwidth("-")/2, y + 5 + 40/2 - textheight("-")/2, "-");
		}
	}
	tam = tam * dau_so_3D;
	if (xdinh_o == 0){
		x_3D = tam;
	}
	else if (xdinh_o == 1){
		y_3D = tam;
	}
	else if (xdinh_o == 2){
		z_3D = tam;
	}
	else if (xdinh_o == 3){
		if(nho_3D == 0){
			canh_3D = tam;
		}
		else if(nho_3D == 1){

			canh_3D = tam;
		}
		else if(nho_3D == 2){
			R_3D = tam;			
		}
	}
	else if (xdinh_o == 4){
		cao_3D = tam;
	}
	thong_bao("Xong, nhap gia tri khac|Click SHOW de ve!!!", 2, 2);
	//cout << x_3D << "," << y_3D << "," << z_3D << ","<<  canh_3D << "," << cao_3D << endl;	
	//cout << endl<< x + 100/2 - textwidth(s)/2 <<  y + size + 40/2 - textheight(s)/2 << endl;
}

void grid(int kichthuoc, int ngang, int doc, int Grid_color, int kt_play){
	
	setcolor(Grid_color);
		
	if ((kt_play == 2) && (Grid_color != color_clear)){
		//ve Ngang
		for (int i = 1;i<(doc / kichthuoc)-1; i++){
			line(5, i * kichthuoc + 5, ngang - 5, 5 + i * kichthuoc);
		}
		//Ve Doc
		for (int i = 1;i<(ngang / kichthuoc)-1; i++){
			line(i * kichthuoc + 5, 5, 5 + i * kichthuoc, doc - 5);
		}
	}
	
	else if ((kt_play == 3) && (Grid_color != color_clear)){
		//ve mp Oxy
		//ve ngang
		for (int i = Oy_3D; i > 5; i = i - kichthuoc){
			line(Ox_3D, i, ngang - 5, i);
		}
		//ve doc
		for (int i = Ox_3D; i < ngang - 5; i = i + kichthuoc){
			line(i, 5, i, Oy_3D);
		}
		
		//ve mp Oxz
		//ve ngang
		for (int i = Oy_3D; i < (doc - 5); i = i + kichthuoc){
			line(Ox_3D - (i - Oy_3D), i, ngang - 5, i);
		}
		//ve xeo
		int tam;
		for (int i = Ox_3D; i < ngang - 5; i = i + kichthuoc){
			line(i, Oy_3D, i - (doc - 5 - Oy_3D), doc - 5);
			tam = i;
		}
		int tam_x = tam + kichthuoc - (doc - 5 - Oy_3D);
		int tam_y = Oy_3D;
		while (tam_x <= ngang - 5){
			line(tam_x, doc - 5, ngang - 5, tam_y);
			tam_x = tam_x + kichthuoc;
			tam_y = tam_y + kichthuoc;
		}
		
		//ve mp Oyz
		//ve doc
		for (int i = Ox_3D; i > 5; i = i - kichthuoc){
			if (Oy_3D + (Ox_3D - i) <= doc - 5){
				line(i, 5, i, Oy_3D + (Ox_3D - i));
			}
			else{
				line(i, 5, i, doc - 5);
			}
		}
		//ve xeo
		for (int i = Oy_3D - kichthuoc; i >= 5; i = i - kichthuoc){
			if(i + Ox_3D >= doc - 5){
				line(5 + (i + Ox_3D - doc), doc - 5, Ox_3D, i);
			}
			else{
				line(5, i + Ox_3D - 5, Ox_3D, i);
			}
		}
		
		tam_x = 5 + kichthuoc;
		tam_y = 5 + kichthuoc;
		while (tam_x < Ox_3D){
			line(5, tam_y, tam_x, 5);
			tam_x = tam_x + kichthuoc;
			tam_y = tam_y + kichthuoc;
		}
		//lam ro truc toa do
		setcolor(colorGra - 1);
		
		line(Ox_3D + 1, Oy_3D, Ox_3D + 1, 5);
		line(Ox_3D, Oy_3D, Ox_3D, 5);
		line(Ox_3D - 1, Oy_3D, Ox_3D - 1, 5);
		
		line(Ox_3D, Oy_3D + 1, ngang - 5, Oy_3D + 1);
		line(Ox_3D, Oy_3D, ngang - 5, Oy_3D);
		line(Ox_3D, Oy_3D - 1, ngang - 5, Oy_3D - 1);
		
		if(Ox_3D < Oy_3D){
			line(Ox_3D, Oy_3D + 1, 5 + (Ox_3D - (doc -  Oy_3D)) + 1, doc - 5);
			line(Ox_3D, Oy_3D, 5 + (Ox_3D - (doc -  Oy_3D)), doc - 5);
			line(Ox_3D, Oy_3D - 1, 5 + (Ox_3D - (doc -  Oy_3D)) - 1, doc - 5);
		}
		else{
			line(Ox_3D, Oy_3D + 1, 5, doc - ((doc - Oy_3D) - Ox_3D) + 1);
			line(Ox_3D, Oy_3D, 5, doc - ((doc - Oy_3D) - Ox_3D));
			line(Ox_3D, Oy_3D - 1, 5, doc - ((doc - Oy_3D) - Ox_3D) - 1);
		}
	}
	else{
		Clear_Area(5, 5, ngang, doc);
	}

	//Tao khung
	setcolor(color);
	line(5 - 2, 5, ngang - 5 + 2, 5);
	line(5 - 2, 5 - 1, ngang - 5 + 2, 5 - 1);
	line(5 - 2, 5 - 2, ngang - 5 + 2, 5 - 2);
	
	line(5 - 2, doc - 5 + 2, ngang - 5 + 2, doc - 5 + 2);
	line(5 - 2, doc - 5 + 1, ngang - 5 + 2, doc - 5 + 1);
	line(5 - 2, doc - 5, ngang - 5 + 2, doc - 5);
	
	line(5 - 2, 5 - 2, 5 - 2, doc - 5 + 2);
	line(5 - 1, 5 - 2, 5 - 1, doc - 5 + 2);
	line(5 , 5 - 2, 5, doc - 5 + 2);
	
	line(ngang - 5 + 2, 5 - 2, ngang - 5 + 2, doc - 5 + 2);
	line(ngang - 5 + 1, 5 - 2, ngang - 5 +1, doc - 5 + 2);
	line(ngang - 5, 5 - 2, ngang - 5, doc - 5 + 2);
}

/////////////////////////////////////////

void ve_table_2D(){
	int y0 = 5 + 50 + 5 + 50 + 75;
	int x0 = dai - 450 + 5;
	int kcach = 5;
	
	ve_table( x0, y0, 2, 3, kcach, 100, 40);
	settextstyle(0, 0, 3);
	outtextxy(x0 + 100/2 - textwidth("X")/2, y0 + 50/2 - textheight("X")/2, "X");
	outtextxy(x0 + 100 + 100/2 - textwidth("Y")/2, y0 + 50/2 - textheight("Y")/2, "Y");
	outtextxy(x0 + 200 + 100/2 - textwidth("R")/2, y0 + 50/2 - textheight("R")/2, "R");
	
	if(choose_2D == 1){
		y0 = y0 + 2 * 40 + kcach;
	
		ve_table( x0, y0, 3, 4, kcach, 100, 40);
		outtextxy(x0 + 100/2 - textwidth("x1")/2, y0 + 50/2 - textheight("x1")/2, "x1");
		outtextxy(x0 + 100 + 100/2 - textwidth("y1")/2, y0 + 50/2 - textheight("y1")/2, "y1");
		outtextxy(x0 + 200 + 100/2 - textwidth("x2")/2, y0 + 50/2 - textheight("x2")/2, "x2");
		outtextxy(x0 + 300 + 100/2 - textwidth("y2")/2, y0 + 50/2 - textheight("y2")/2, "y2");
	
		y0 = y0 + 3 * 40 + kcach;
	
		ve_table( x0, y0, 2, 4, kcach, 100, 40);
		outtextxy(x0 + 100/2 - textwidth("Ax")/2, y0 + 50/2 - textheight("Ax")/2, "Ax");
		outtextxy(x0 + 100 + 100/2 - textwidth("Ay")/2, y0 + 50/2 - textheight("Ay")/2, "Ay");
		outtextxy(x0 + 200 + 100/2 - textwidth("Cx")/2, y0 + 50/2 - textheight("Cx")/2, "Cx");
		outtextxy(x0 + 300 + 100/2 - textwidth("Cy")/2, y0 + 50/2 - textheight("Cy")/2, "Cy");
	}                          
}

float Round(float y){
	return y+0.5;
}

void put4pixel(int xc, int yc, int x, int y, int color){
    putpixel(Round(xc + x), round(yc + y), color);
    putpixel(Round(xc - x), round(yc + y), color);
    putpixel(Round(xc + x), round(yc - y), color);
    putpixel(Round(xc - x), round(yc - y), color);
}

void elip(int xc, int yc, int a, int b, int color){
            int dx = abs(xc - a);
            int dy = abs(yc - b);
            // AH^2 = HB.HC
            int s = (dy * dy) / dx;
            int xtieudiem1 = (xc + dx + s);
            int ytieudiem1 = yc;
            int xtieudiem2 = Round(xc) - (dx + s);
            int ytieudiem2 = yc;
            int MF1 = (int)(sqrt((s * s) + (dy * dy)));
            int MF2 = (int)(sqrt((2 * dx + s) * (2 * dx + s) + (dy * dy)));
            //MF1+ MF2 = 2a
            int Rtruclon = (MF1 + MF2) / 2;
            int Rtieucu = dx + s;
            int Rtrucnho = (int)(sqrt((Rtruclon * Rtruclon) - (Rtieucu * Rtieucu)));
            int x = 0;
            int y = (Rtrucnho);
            a = dx;
            b = Rtrucnho;
            int A, B;
            A = a * a;
            B = b * b;
            double p = B + 1 / A * 4 - A * b;
            int Dx = 0;
            int Dy = 2 * A * y;
            int k = 0;
            put4pixel(xc, yc, x, y, color);

            while (Dx < Dy)
            {
                x++;
                Dx += 2 * B;
                if (p < 0)
                    p += B + Dx;
                else
                {
                    y--;
                    Dy -= 2 * A;
                    p += B + Dx - Dy;
                }
                //if (x % 5 == 0)
                //{
                // put4pixel2(xc, yc, x, y, k);
                put4pixel(xc, yc, x, y, color);
                k++;
                //}
            }
            p = Round(B * (x + 0.5f) * (x + 0.5f) + A * (y - 1) * (y - 1) - A * B);
            while (y > 0)
            {
                y--;
                Dy -= A * 2;
                if (p > 0)
                    p += A - Dy;
                else
                {
                    x++;
                    Dx += B * 2;
                    p += A - Dy + Dx;
                }

                //if (x % 5 == 0) 
                put4pixel(xc, yc, x, y, color);
            }
    setfillstyle(1,color);
	setcolor(color);
	floodfill(xc,yc,color);
    
}

void HCN(int x1, int y1, int x2, int y2, int color){
	Bresenham(x1,y1,x2,y1,color,1);
	Bresenham(x2,y1,x2,y2,color,1);
	Bresenham(x2,y2,x1,y2,color,1);
	Bresenham(x1,y2,x1,y1,color,1);
	setfillstyle(1,color);
	floodfill((x1+x2)/2, (y1+y2)/2, color);
}

void put8pixel(int xc, int yc, int x, int y, int color){
//	x = x * 5;
//	y= y * 5;
	//chia 8 phan doi xung qua x=y=R/can2
    putdiem(x + xc, y + yc, color);
    putdiem(-x + xc, y + yc, color);
    putdiem(x + xc, -y + yc, color);
    putdiem(-x + xc, -y + yc, color);
    putdiem( y + xc, x + yc, color);
    putdiem(-y + xc, x + yc, color);
	putdiem(y + xc, -x + yc, color);
	putdiem(-y + xc, -x + yc, color);
}

void VeCircle(int xc, int yc, int r, int color)
{
	//int dem=1;
	int x = 0; int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color);
    while (x < y)
    {
        if (f < 0){
        	f = f + 2 * x + 3;	
		}
        else
        {
            y--;
            f = f + 2 * x - 2 * y + 5;
        }
        x++;
        //dem++;
        put8pixel(xc, yc, x, y, color);
	}
	setfillstyle(1,color);
	setcolor(color);
	floodfill(xc,yc,color);
	//cout << dem;
}

void put4pixel_B(int xc, int yc, int x, int y, int color, int loai)
{
//	x = x * 5;
//	y= y * 5;
	//chia 4 phan doi xung
	if (loai == 1){
		putdiem(x + xc, y + yc, color);
    	putdiem(-x + xc, y + yc, color);
    	putdiem(x + xc, -y + yc, color);
	    putdiem(-x + xc, -y + yc, color);	
	}
	else{
		putdiem(x + xc, y + yc, color);
    	putdiem(-x + xc, y + yc, color);
	}
}

void ElipMidpoint(int xc, int yc, int a, int b, int color, int xdinh)
{
	//phan 1
	int x = 0;
	int y = b;
	int xd = abs(1 - xdinh);
	int hien = 2;
	int an = 5 * xd;
	// fx/fy = dx/dy = 2*b2*x/2*b2*y
	
	int fx=2*b*b*x;
	int fy=2*a*a*y;
    int p = b*b - a*a*b + a*a/4;
    p = lam_tron(p);
    
    put4pixel_B(xc, yc, x, y, color,1);
    while (fx<fy)
    {
    	fx = fx + 2*b*b;
    	x++;
		//delay(10);
        if (p < 0){
        	p = p + b*b*(2*x + 3);	
		}
        else
        {
            y--;
            fy = fy - 2*a*a;
            p = p + b*b*(2*x + 3) + a*a*(-2*y+2);
        }
        if(hien!=0){
        	put4pixel_B(xc, yc, x, y, color,1);
        	hien--;
		}
		else {
			if (an!=0){
				an--;
				put4pixel_B(xc, yc, x, y, color, 0);
			}
			else{
				put4pixel_B(xc, yc, x, y, color, 1);
				hien = 3;
				an = 5 * xd;
			}
		}
	}
	// phan 2
	p = b*b * (x + 0.5)*(x + 0.5) + a*a*(y - 1)*(y - 1) - a*a*b*b;
	p = lam_tron(p);
	while (y > 0){
		fy = fy - 2*a*a;
		y--;
		if (p >= 0) {
			p = p + a*a*( 3 - 2*y );
		}
		else{
			x++;
			fx = fx + 2*b*b;
			p = p + b*b*(2*x + 2) + a*a*(-2*y+3);
		}
		if(hien!=0){
        	put4pixel_B(xc, yc, x, y, color,1);
        	hien--;
		}
		else {
			if (an!=0){
				an--;
				put4pixel_B(xc, yc, x, y, color, 0);
			}
			else{
				put4pixel_B(xc, yc, x, y, color, 1);
				hien = 3;
				an = 5 * xd;
			}
		}
	}
}


float matran_tinhtien(float matran[3][3], int x, int y)  //tinh tien ve goc toa do 
{ 
			//= new float[3] [3];

    matran[0][0]=1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=1;
	matran[1][2]=0;
	matran[2][0]=400-x;     
	matran[2][1]=300-y;
	matran[2][2]=1;
    return matran[3][3];
}

float matran_tinhtien_x(float matran[3][3])  //tinh tien ve goc toa do 
{ 
			//= new float[3] [3];

    matran[0][0]=1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=1;
	matran[1][2]=0;
	matran[2][0]=5;     
	matran[2][1]=0;
	matran[2][2]=1;
    return matran[3][3];
}

float matran_tinhtien_Trave(float matran[3][3], int x, int y)
{ 
			//= new float[3] [3];

    matran[0][0]=1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=1;
	matran[1][2]=0;
	matran[2][0]=x-400;
	matran[2][1]=y-300;
	matran[2][2]=1;
    return matran[3][3];
}

float matran_tyle(float matran[3][3], int x, int y)
{
	matran[0][0]=x;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=y;
	matran[1][2]=0;
	matran[2][0]=0;
	matran[2][1]=0;
	matran[2][2]=1;
    return matran[3][3];
}

float matran_doixungx(float matran[3][3])
{
	matran[0][0]=1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=-1;
	matran[1][2]=0;
	matran[2][0]=0;
	matran[2][1]=0;
	matran[2][2]=1;
    return matran[3][3];
}

float matran_doixungy(float matran[3][3])
{
	matran[0][0]=-1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=1;
	matran[1][2]=0;
	matran[2][0]=0;
	matran[2][1]=0;
	matran[2][2]=-1;
    return matran[3][3];
}

float matran_doixungO(float matran[3][3],int x,int y)
{
	matran[0][0]=(float)(x-800)/x;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=(float)(y-600)/y;
	matran[1][2]=0;
	matran[2][0]=0;
	matran[2][1]=0;
	matran[2][2]=1;
    return matran[3][3];
}

float Diem_quay(float Diem_quay[1][3], int x, int y)
{
    Diem_quay[0][0]=x - 400;
    Diem_quay[0][1] = y - 300;
  	Diem_quay[0][2] = 1;
 	return Diem_quay[1][3];
}

float matran_quay(float matran[3][3])
{ 
			//= new float[3] [3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && i < 2)
            {
                matran[i][j] = (float)(0.5); //Chú ý    cos
            }
            else if (i == 0 && j == 1)
            {
                matran[i] [j] = (float)sqrt(3) / 2;//Chú ý    sin
            }
            else if (i == 1 && j == 0)
            {
                matran[i] [j] = (float)(-sqrt(3) / 2);//Chú ý   -sin
            }
            else if (i == j && i == 2)
            {
               	matran[i][j] = 1;
            }
            else
            {
                matran[i][j] = 0;
            }
        }
    }
    return matran[3][3];
}
int Nhanmatran_quay(int matran[][3], float diem[][3], float b[][3])
{
            
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matran[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                float s1 = diem[i][k];
                float s2 = b[k][j];
                matran[i][j] += (int)(s1 * s2);
            }
        }
    }
    return matran[1][3];

}
int LayX(int a[1][3] )
{
    int x = a[0] [0];
    return x;
}
int LayY(int a[1][3])
{
    int y = a[0] [1];
    return y;
}
int quay_1diem_X(int x,int y)
{
    float a[1][3];
    float b[3][3];
    int c[1][3];
    Diem_quay(a,x,y);
    matran_quay(b);
    Nhanmatran_quay(c,a,b);
	int s1=	LayX(c)+400;
	int s2= LayY(c)+300;
	return s1;
        		
}
int quay_1diem_Y(int x,int y)
{
    float a[1][3];
    float b[3][3];
    int c[1][3];
    Diem_quay(a,x,y);
    matran_quay(b);
    Nhanmatran_quay(c,a,b);
	int s1=	LayX(c)+400;
	int s2= LayY(c)+300;
	return s2;
        		
}

void khinhkhicau(int i, int kk2){
	float a[1][3];
    float b[3][3];
    int c[1][3]; 
    //toa do hinh tron
	matran_tinhtien_x(b);
	Diem_quay(a,100+i*5,80);
	Nhanmatran_quay(c,a,b);
	int m = LayX(c)+400;
	int n = LayY(c)+300;
	//2 day
	matran_tinhtien_x(b);
	Diem_quay(a,85+i*5,105);
	Nhanmatran_quay(c,a,b);
	int m1 = LayX(c)+400;
	int n1 = LayY(c)+300;
	
	matran_tinhtien_x(b);
	Diem_quay(a,85+i*5,125);
	Nhanmatran_quay(c,a,b);
	int m2 = LayX(c)+400;
	int n2 = LayY(c)+300;
	
	matran_tinhtien_x(b);
	Diem_quay(a,115+i*5,105);
	Nhanmatran_quay(c,a,b);
	int m3 = LayX(c)+400;
	int n3 = LayY(c)+300;
	
	matran_tinhtien_x(b);
	Diem_quay(a,115+i*5,125);
	Nhanmatran_quay(c,a,b);
	int m4 = LayX(c)+400;
	int n4 = LayY(c)+300;
	//HCN
	matran_tinhtien_x(b);
	Diem_quay(a,80+i*5,125);
	Nhanmatran_quay(c,a,b);
	int m5 = LayX(c)+400;
	int n5 = LayY(c)+300;
	
	matran_tinhtien_x(b);
	Diem_quay(a,120+i*5,165);
	Nhanmatran_quay(c,a,b);
	int m6 = LayX(c)+400;
	int n6 = LayY(c)+300;
	//
	Bresenham(m1,n1,m2,n2,7,1);
	Bresenham(m3,n3,m4,n4,7,1);
	HCN(m5,n5,m6,n6,12);
	VeCircle(m,n,30,kk2);
	
	delay(100);
	Bresenham(m1,n1,m2,n2,3,1);
	Bresenham(m3,n3,m4,n4,3,1);
	VeCircle(m,n,35,3);
	HCN(m5,n5,m6,n6,3);
	
	int y0 = 5 + 50 + 5 + 50 + 75;
	int x0 = dai - 450 + 5;
	int kcach = 5;
	settextstyle(0,0,2);
	setcolor(color);
	Clear_Area(x0 + 3, y0 + 40 + 3 + 5, x0 + 100, y0 + 80 - 3 + 5);
	char *p = chuyen(100 + i * 5);
	outtextxy(x0 + 100/2 - textwidth(p)/2, y0 + 40 + 50/2 - textheight(p)/2, p);
	
	y0 = y0 + 2 * 40 + kcach;
	y0 = y0 + 3 * 40 + kcach;

	Clear_Area(x0 + 3, y0 + 40 + 3 + 5, x0 + 100, y0 + 80 - 3 + 5);
	p = chuyen(80 + i * 5);
	outtextxy(x0 + 100/2 - textwidth(p)/2, y0 + 40 + 50/2 - textheight(p)/2, p);
	Clear_Area(x0 + 200 + 3, y0 + 40 + 3 + 5, x0 + 300 - 3, y0 + 80 - 3 + 5);
	p = chuyen(120 + i * 5);
	outtextxy(x0 + 200 + 100/2 - textwidth(p)/2, y0 + 40 + 50/2 - textheight(p)/2, p);
}

void Hinh()
{
	//initwindow(805,600);
	int getmaxx = 795;
	int getmaxy = 600;
	
	//Toa do HCN1
	int xH1 = getmaxx/2 - 85;
	int yH1 = getmaxy - 90;
	int xH2 = getmaxx/2 + 85;
	int yH2 = getmaxy - 55;
	//Toa do HT1
	int xT1 = getmaxx/2 - 40;
	int yT1 = getmaxy - 50;
	//Toa do HT2
	int xT2 = getmaxx/2 + 40;
	int yT2 = getmaxy - 50;
	//Toa do HCN2
	int xH3 = getmaxx/2 - 55;
	int yH3 = yH1 - 25;
	int xH4 = getmaxx/2 + 35;
	int yH4 = yH1;
	// toa do banh xe 1
	int x=xT1;
	int y=yT1;
	int x1=xT1+15;
	int y1=yT1;
	// ve vach duong
	HCN(0,getmaxy-12,getmaxx,getmaxy-22,15);
	HCN(0,425,getmaxx,435,15);
	// toa do banh xe 2
	int q=xT2;
	int w=yT2;
	int q1=xT2+15;
	int w1=yT2;
	//
	float a[1][3];
	float b1[3][3];
    float b[3][3];
    int c[1][3];	
	/////////////////////// ve canh tinh ~ ///////////////////////
	int color = 4;
	//ve mau troi
	HCN(0,0,getmaxx,400,3);
	// ve xe
	HCN(xH1,yH1,xH2,yH2,color);
	color = 4;
	HCN(xH3,yH3,xH4,yH4,color);
	color = 0;
	//Ve HT1
	VeCircle(xT1,yT1,15,3);
	//Ve HT2
	VeCircle(xT2,yT2,15,3);
	//Ve mat troi
	VeCircle(0,0,40,14);
	//Ve cay
	HCN(70,260,90,360,6);
	VeCircle(80,255,45,10);
	HCN(190,260,205,355,6);
	VeCircle(197.5,245,40,10);
	//Ve nha
	HCN(400,250+140,530,60+140,12);
	HCN(420,250+140,510,210+140,8);
	HCN(410,190+140,460,160+140,2);
	HCN(470,190+140,520,160+140,2);
	HCN(410,150+140,460,120+140,2);
	HCN(470,150+140,520,120+140,2);
	HCN(410,110+140,460,80+140,2);
	HCN(470,110+140,520,80+140,2);
	// ve may	
	elip(130,15,175,3,15);
	elip(195,17,235,5,15);
	elip(240,14,270,10,15);
	elip(400,14,460,10,15);
	elip(480,17,520,4,15);
	elip(530,12,579,8,15);
	elip(680,13,720,8,15);
	elip(725,16,755,6,15);
	/////////////////////////////////////////////////////////////
	// .1
    matran_tinhtien(b,x,y);
    Nhanmatran_quay(c,a,b);
    int s1=	LayX(c)+400;
	int s2= LayY(c)+300;
	
	Diem_quay(a,x1,y1);
	Nhanmatran_quay(c,a,b);
	int s3=	LayX(c)+400;
	int s4= LayY(c)+300;
	Diem_quay(a,x,y);

//	int c1[1][3];
	matran_tinhtien(b,q,w);
    Nhanmatran_quay(c,a,b);
    int r1=	LayX(c)+400;
	int r2= LayY(c)+300;
	
	Diem_quay(a,q1,w1);
	Nhanmatran_quay(c,a,b);
	int r3=	LayX(c)+400;
	int r4= LayY(c)+300;
	for(int i=0; i<=150; i++){
		int m=i%6;
		///// xoay banh xe
		// 1
		Diem_quay(a,s3,s4);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int s5=	LayX(c)+400;
		int s6= LayY(c)+300;
		Diem_quay(a,r3,r4);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int r5=	LayX(c)+400;
		int r6= LayY(c)+300;
		//Lay diem doi xung 1
		Diem_quay(a,s5,s6);
		matran_doixungO(b,s5,s6);
		Nhanmatran_quay(c,a,b);
		int s5_dx = LayX(c)+400;
		int s6_dx = LayY(c)+300;
		
		Diem_quay(a,r5,r6);
		matran_doixungO(b,r5,r6);
		Nhanmatran_quay(c,a,b);
		int r5_dx = LayX(c)+400;
		int r6_dx = LayY(c)+300;
		
		// tra ve diem doi xung
		Diem_quay(a,s5_dx,s6_dx);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s7_dx=	LayX(c)+400;
		int s8_dx= LayY(c)+300;
		
		Diem_quay(a,r5_dx,r6_dx);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r7_dx=	LayX(c)+400;
		int r8_dx= LayY(c)+300;
		
		// tra ve 1
		Diem_quay(a,s5,s6);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s7=	LayX(c)+400;
		int s8= LayY(c)+300;
		
		Diem_quay(a,r5,r6);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r7=	LayX(c)+400;
		int r8= LayY(c)+300;
		//2
		Diem_quay(a,s5,s6);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int s51=	LayX(c)+400;
		int s61= LayY(c)+300;
		Diem_quay(a,r5,r6);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int r51=	LayX(c)+400;
		int r61= LayY(c)+300;
		//Lay diem doi xung 2
		Diem_quay(a,s51,s61);
		matran_doixungO(b,s51,s61);
		Nhanmatran_quay(c,a,b);
		int s51_dx = LayX(c)+400;
		int s61_dx = LayY(c)+300;
		
		Diem_quay(a,r51,r61);
		matran_doixungO(b,r51,r61);
		Nhanmatran_quay(c,a,b);
		int r51_dx = LayX(c)+400;
		int r61_dx = LayY(c)+300;
		
		// tra ve diem doi xung
		Diem_quay(a,s51_dx,s61_dx);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s71_dx=	LayX(c)+400;
		int s81_dx= LayY(c)+300;
		
		Diem_quay(a,r51_dx,r61_dx);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r71_dx=	LayX(c)+400;
		int r81_dx= LayY(c)+300;
		// tra ve 2
		Diem_quay(a,s51,s61);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s71=	LayX(c)+400;
		int s81= LayY(c)+300;
		Diem_quay(a,r51,r61);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r71=	LayX(c)+400;
		int r81= LayY(c)+300;
			
		Diem_quay(a,s51,s61);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int s52=	LayX(c)+400;
		int s62= LayY(c)+300;
		Diem_quay(a,r51,r61);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int r52=	LayX(c)+400;
		int r62= LayY(c)+300;
		//Lay diem doi xung 3
		Diem_quay(a,s52,s62);
		matran_doixungO(b,s52,s62);
		Nhanmatran_quay(c,a,b);
		int s52_dx = LayX(c)+400;
		int s62_dx = LayY(c)+300;
		
		Diem_quay(a,r52,r62);
		matran_doixungO(b,r52,r62);
		Nhanmatran_quay(c,a,b);
		int r52_dx = LayX(c)+400;
		int r62_dx = LayY(c)+300;
		
		// tra ve diem doi xung
		Diem_quay(a,s52_dx,s62_dx);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s72_dx=	LayX(c)+400;
		int s82_dx= LayY(c)+300;
		
		Diem_quay(a,r52_dx,r62_dx);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r72_dx=	LayX(c)+400;
		int r82_dx= LayY(c)+300;
		// tra ve 3
		Diem_quay(a,s52,s62);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s72=	LayX(c)+400;
		int s82= LayY(c)+300;
		Diem_quay(a,r52,r62);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r72=	LayX(c)+400;
		int r82= LayY(c)+300;
			
		Diem_quay(a,s52,s62);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int s53=	LayX(c)+400;
		int s63= LayY(c)+300;
		Diem_quay(a,r52,r62);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int r53=	LayX(c)+400;
		int r63= LayY(c)+300;
		//Lay diem doi xung 5
		Diem_quay(a,s53,s63);
		matran_doixungO(b,s53,s63);
		Nhanmatran_quay(c,a,b);
		int s53_dx = LayX(c)+400;
		int s63_dx = LayY(c)+300;
		
		Diem_quay(a,r53,r63);
		matran_doixungO(b,r53,r63);
		Nhanmatran_quay(c,a,b);
		int r53_dx = LayX(c)+400;
		int r63_dx = LayY(c)+300;
		
		// tra ve diem doi xung
		Diem_quay(a,s53_dx,s63_dx);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s73_dx=	LayX(c)+400;
		int s83_dx= LayY(c)+300;
		
		Diem_quay(a,r53_dx,r63_dx);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r73_dx=	LayX(c)+400;
		int r83_dx= LayY(c)+300;
		// tra ve 4
		Diem_quay(a,s53,s63);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s73=	LayX(c)+400;
		int s83= LayY(c)+300;
		Diem_quay(a,r53,r63);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r73=	LayX(c)+400;
		int r83= LayY(c)+300;
			
		Diem_quay(a,s53,s63);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int s54=	LayX(c)+400;
		int s64= LayY(c)+300;
		Diem_quay(a,r53,r63);
		matran_quay(b);
		Nhanmatran_quay(c,a,b);
		int r54=	LayX(c)+400;
		int r64= LayY(c)+300;
		//Lay diem doi xung 5
		Diem_quay(a,s54,s64);
		matran_doixungO(b,s54,s64);
		Nhanmatran_quay(c,a,b);
		int s54_dx = LayX(c)+400;
		int s64_dx = LayY(c)+300;
		
		Diem_quay(a,r54,r64);
		matran_doixungO(b,r54,r64);
		Nhanmatran_quay(c,a,b);
		int r54_dx = LayX(c)+400;
		int r64_dx = LayY(c)+300;
		
		// tra ve diem doi xung
		Diem_quay(a,s54_dx,s64_dx);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s74_dx=	LayX(c)+400;
		int s84_dx= LayY(c)+300;
		
		Diem_quay(a,r54_dx,r64_dx);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r74_dx=	LayX(c)+400;
		int r84_dx= LayY(c)+300;
		// tra ve 5
		Diem_quay(a,s54,s64);
		matran_tinhtien_Trave(b1,x,y);
		Nhanmatran_quay(c,a,b1);
		int s74=	LayX(c)+400;
		int s84= LayY(c)+300;
		Diem_quay(a,r54,r64);
		matran_tinhtien_Trave(b1,q,w);
		Nhanmatran_quay(c,a,b1);
		int r74=	LayX(c)+400;
		int r84= LayY(c)+300;
		
		int y0 = 5 + 50 + 5 + 50 + 75;
		int x0 = dai - 450 + 5;
		int kcach = 5;
	
		y0 = y0 + 2 * 40 + kcach;
//		outtextxy(x0 + 100/2 - textwidth("x1")/2, y0 + 50/2 - textheight("x1")/2, "x1");
//		outtextxy(x0 + 100 + 100/2 - textwidth("y1")/2, y0 + 50/2 - textheight("y1")/2, "y1");
//		outtextxy(x0 + 200 + 100/2 - textwidth("x2")/2, y0 + 50/2 - textheight("x2")/2, "x2");
//		outtextxy(x0 + 300 + 100/2 - textwidth("y2")/2, y0 + 50/2 - textheight("y2")/2, "y2");
		
		if(m==1){
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("442")/2, y0 + 40 + 50/2 - textheight("442")/2, "442");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("549")/2, y0 + 40 + 50/2 - textheight("549")/2, "549");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("429")/2, y0 + 40 + 50/2 - textheight("429")/2, "429");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("526")/2, y0 + 40 + 50/2 - textheight("526")/2, "526");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("522")/2, y0 + 80 + 50/2 - textheight("522")/2, "522");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("629")/2, y0 + 80 + 50/2 - textheight("629")/2, "629");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("509")/2, y0 + 80 + 50/2 - textheight("509")/2, "509");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("606")/2, y0 + 80 + 50/2 - textheight("606")/2, "606");
			
			Bresenham(x,y,s7,s8,4,1);
			Bresenham(q,w,r7,r8,4,1);
			Bresenham(x,y,s7_dx,s8_dx,4,1);
			Bresenham(q,w,r7_dx,r8_dx,4,1);
			delay(50);
			Bresenham(x,y,s7,s8,3,1);
			Bresenham(q,w,r7,r8,3,1);
			Bresenham(x,y,s7_dx,s8_dx,3,1);
			Bresenham(q,w,r7_dx,r8_dx,3,1);
		}
		// 2
		else if(m==2){
			
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("428")/2, y0 + 40 + 50/2 - textheight("428")/2, "428");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("549")/2, y0 + 40 + 50/2 - textheight("549")/2, "549");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("442")/2, y0 + 40 + 50/2 - textheight("442")/2, "442");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("537")/2, y0 + 40 + 50/2 - textheight("537")/2, "537");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("502")/2, y0 + 80 + 50/2 - textheight("502")/2, "502");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("629")/2, y0 + 80 + 50/2 - textheight("629")/2, "629");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("529")/2, y0 + 80 + 50/2 - textheight("529")/2, "529");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("616")/2, y0 + 80 + 50/2 - textheight("616")/2, "616");
			
			Bresenham(x,y,s71,s81,4,1);
			Bresenham(q,w,r71,r81,4,1);
			Bresenham(x,y,s71_dx,s81_dx,4,1);
			Bresenham(q,w,r71_dx,r81_dx,4,1);
			delay(50);
			Bresenham(x,y,s71,s81,3,1);
			Bresenham(q,w,r71,r81,3,1);
			Bresenham(x,y,s71_dx,s81_dx,3,1);
			Bresenham(q,w,r71_dx,r81_dx,3,1);
		}
		// 3
		else if(m==3){
			
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("422")/2, y0 + 40 + 50/2 - textheight("422")/2, "422");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("537")/2, y0 + 40 + 50/2 - textheight("537")/2, "537");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("448")/2, y0 + 40 + 50/2 - textheight("448")/2, "448");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("537")/2, y0 + 40 + 50/2 - textheight("537")/2, "537");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("502")/2, y0 + 80 + 50/2 - textheight("502")/2, "502");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("617")/2, y0 + 80 + 50/2 - textheight("617")/2, "617");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("528")/2, y0 + 80 + 50/2 - textheight("528")/2, "528");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("617")/2, y0 + 80 + 50/2 - textheight("617")/2, "617");
			
			Bresenham(x,y,s72,s82,4,1);
			Bresenham(q,w,r72,r82,4,1);
			Bresenham(x,y,s72_dx,s82_dx,4,1);
			Bresenham(q,w,r72_dx,r82_dx,4,1);
			delay(50);
			Bresenham(x,y,s72,s82,3,1);
			Bresenham(q,w,r72,r82,3,1);
			Bresenham(x,y,s72_dx,s82_dx,3,1);
			Bresenham(q,w,r72_dx,r82_dx,3,1);
		}	
		// 4
		else if(m==4){
			
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("429")/2, y0 + 40 + 50/2 - textheight("429")/2, "429");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("526")/2, y0 + 40 + 50/2 - textheight("526")/2, "526");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("442")/2, y0 + 40 + 50/2 - textheight("442")/2, "442");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("549")/2, y0 + 40 + 50/2 - textheight("549")/2, "549");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("509")/2, y0 + 80 + 50/2 - textheight("509")/2, "509");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("606")/2, y0 + 80 + 50/2 - textheight("606")/2, "606");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("522")/2, y0 + 80 + 50/2 - textheight("522")/2, "522");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("629")/2, y0 + 80 + 50/2 - textheight("629")/2, "629");
			
			Bresenham(x,y,s73,s83,4,1);
			Bresenham(q,w,r73,r83,4,1);
			Bresenham(x,y,s73_dx,s83_dx,4,1);
			Bresenham(q,w,r73_dx,r83_dx,4,1);
			delay(50);
			Bresenham(x,y,s73,s83,3,1);
			Bresenham(q,w,r73,r83,3,1);
			Bresenham(x,y,s73_dx,s83_dx,3,1);
			Bresenham(q,w,r73_dx,r83_dx,3,1);
		}
		// 5
		else if(m==5){
			
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("442")/2, y0 + 40 + 50/2 - textheight("442")/2, "442");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("526")/2, y0 + 40 + 50/2 - textheight("526")/2, "526");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("428")/2, y0 + 40 + 50/2 - textheight("428")/2, "428");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("549")/2, y0 + 40 + 50/2 - textheight("549")/2, "549");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("522")/2, y0 + 80 + 50/2 - textheight("522")/2, "522");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("606")/2, y0 + 80 + 50/2 - textheight("606")/2, "606");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("508")/2, y0 + 80 + 50/2 - textheight("508")/2, "508");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("629")/2, y0 + 80 + 50/2 - textheight("629")/2, "629");
			
			Bresenham(x,y,s74,s84,4,1);
			Bresenham(q,w,r74,r84,4,1);
			Bresenham(x,y,s74_dx,s84_dx,4,1);
			Bresenham(q,w,r74_dx,r84_dx,4,1);
			delay(50);
			Bresenham(x,y,s74,s84,3,1);
			Bresenham(q,w,r74,r84,3,1);
			Bresenham(x,y,s74_dx,s84_dx,3,1);
			Bresenham(q,w,r74_dx,r84_dx,3,1);
		}
		//0
		else if(m==0){
			
			Clear_Area(x0 + 3, y0 + 40 + 5 + 3, x0 + 100, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("448")/2, y0 + 40 + 50/2 - textheight("448")/2, "448");
			Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("537")/2, y0 + 40 + 50/2 - textheight("537")/2, "537");
			Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("422")/2, y0 + 40 + 50/2 - textheight("422")/2, "422");
			Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400, y0 + 80 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("537")/2, y0 + 40 + 50/2 - textheight("537")/2, "537");
			
			Clear_Area(x0 + 3, y0 + 80 + 5 + 3, x0 + 100, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100/2 - textwidth("528")/2, y0 + 80 + 50/2 - textheight("528")/2, "528");
			Clear_Area(x0 + 100 + 3, y0 + 80 + 5 + 3, x0 + 200, y0 + 120 + 5 - 3);
			outtextxy(x0 + 100 + 100/2 - textwidth("617")/2, y0 + 80 + 50/2 - textheight("617")/2, "617");
			Clear_Area(x0 + 200 + 3, y0 + 80 + 5 + 3, x0 + 300, y0 + 120 + 5 - 3);
			outtextxy(x0 + 200 + 100/2 - textwidth("502")/2, y0 + 80 + 50/2 - textheight("502")/2, "502");
			Clear_Area(x0 + 300 + 3, y0 + 80 + 5 + 3, x0 + 400, y0 + 120 + 5 - 3);
			outtextxy(x0 + 300 + 100/2 - textwidth("617")/2, y0 + 80 + 50/2 - textheight("617")/2, "617");
			
			Bresenham(xT1, yT1, xT1+13, yT1,4,1);
			Bresenham(xT2, yT2, xT2+13, yT2,4,1);
			Bresenham(xT1, yT1, xT1-13, yT1,4,1);
			Bresenham(xT2, yT2, xT2-13, yT2,4,1);
			delay(50);
			Bresenham(xT1, yT1, xT1+13, yT1,3,1);
			Bresenham(xT2, yT2, xT2+13, yT2,3,1);
			Bresenham(xT1, yT1, xT1-13, yT1,3,1);
			Bresenham(xT2, yT2, xT2-13, yT2,3,1);
		}
		// ve tinh tien khinh khi cau
		int kk = i%131;
		int kk1 = i/131;
		int kk2 = kk1%16;
		khinhkhicau(kk, kk2+9);
	}	
}

float matran_tinhtien_y(float matran[3][3])  //tinh tien ve goc toa do 
{ 
			//= new float[3] [3];

    matran[0][0]=1;
	matran[0][1]=0;
	matran[0][2]=0;
	matran[1][0]=0;
	matran[1][1]=1;
	matran[1][2]=0;
	matran[2][0]=0;     
	matran[2][1]=90;
	matran[2][2]=1;
    return matran[3][3];
}

void bowling_tinhthien(int i){
	float a[1][3];
    float b[3][3];
    int c[1][3];
    //Hinh bowlin
    int getmaxx = 795;
	int getmaxy = 600;
	
    matran_tinhtien_y(b);
	Diem_quay(a,getmaxx/2,450-i*40);
	Nhanmatran_quay(c,a,b);
	int m = LayX(c)+400;
	int n = LayY(c)+300;
	VeCircle(m,n,180-i*10,4);
	delay(100);
	VeCircle(m,n,180-i*10,0);
}

void vechai(int color){
	int l=50;
	int m=90;
	HCN(390,70,400,20,color);
	elip(395,80,415,120,color);
	HCN(390-l,70,400-l,20,color);
	elip(395-l,80,415-l,120,color);
	HCN(390+l,70,400+l,20,color);
	elip(395+l,80,415+l,120,color);
	HCN(390+m,70,400+m,20,color);
	elip(395+m,80,415+m,120,color);
	HCN(390-m,70,400-m,20,color);
	elip(395-m,80,415-m,120,color);
}

void vechai2(int color){
	
	HCN(205,76,165,86,color);
	elip(235,80,195,65,color);
	HCN(205+130,76+30,165+130,86+30,color);
	elip(235+30,80+30,195+30,65+30,color);
	HCN(205-90,76+90,165-90,86+90,color);
	elip(235-90,80+90,195-90,65+90,color);
	HCN(205+500,76+90,165+500,86+90,color);
	elip(235+400,80+90,195+400,65+90,color);
	HCN(205+500,76-40,165+500,86-40,color);
	elip(235+500,80-40,195+500,65-40,color);
}

void Hinh_Bow()
{
	//initwindow(800,600);
	int getmaxx = 795;
	int getmaxy = 600;
	
	Bresenham(150,getmaxy,300,0,7,1);
	Bresenham(500,0,650,getmaxy,7,1);
	Bresenham(300,0,500,0,7,1);
//	Bresenham(150,getmaxy,650,getmaxy,7,1);
	
	Bresenham(0, 0, 0, rong, 7, 1);
	Bresenham(0, rong, dai - 450, rong, 7, 1);
	Bresenham(0, 0, 0, rong, 7, 1);
	Bresenham(dai - 500, 0,dai - 500, rong, 7, 1);
	
	setfillstyle(1,7);
	setcolor(7);
//	floodfill(450,400,7);
	
	Bresenham(130,getmaxy,290,0,7,1);
	Bresenham(0,0,0,getmaxy,7,1);
	Bresenham(0,0,290,0,7,1);
	Bresenham(0,getmaxy,130,getmaxy,7,1);
	setfillstyle(1,13);
	setcolor(7);
	floodfill(10,20,7);
	
	Bresenham(510,0,670,getmaxy,7,1);
	Bresenham(getmaxx,0,getmaxx,getmaxy,7,1);
	Bresenham(getmaxx,0,510,0,7,1);
	Bresenham(getmaxx,getmaxy,670,getmaxy,7,1);
	setfillstyle(1,13);
	setcolor(7);
	floodfill(700,500,7);
	vechai(15);
	for(int i=0; i<11; i++){
		bowling_tinhthien(i);
		if(i==9){
			vechai(0);
		}
		if(i==10){
			vechai2(15);
		}	
		int y0 = 5 + 50 + 5 + 50 + 75;
		int x0 = dai - 450 + 5;
		int kcach = 5;
		settextstyle(0,0,2);
		setcolor(color);
		char *p = chuyen(540 - i * 40);
		Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
		outtextxy(x0 + 100 + 100/2 - textwidth(p)/2, y0 + 40 + 50/2 - textheight(p)/2, p);
		p = chuyen(180 - i * 10);
		Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
		outtextxy(x0 + 200 + 100/2 - textwidth(p)/2, y0 + 40 + 50/2 - textheight(p)/2, p);
	}	
}
///////////////////////////////////////////////

void ve_bong_Cube(){
	int x1, x2, y1, y2;
	
	//chieu len oxy
	x1 = chieu_x(x_3D, 0);
	y1 = chieu_y(y_3D, 0);
	
	x2 = chieu_x(x_3D + canh_3D, 0);
	y2 = chieu_y(y_3D, 0);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(x_3D, 0);
	y2 = chieu_y(y_3D + canh_3D, 0);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	
	x1 = chieu_x(x_3D + canh_3D, 0);
	y1 = chieu_y(y_3D + canh_3D, 0);
	
	x2 = chieu_x(x_3D + canh_3D, 0);
	y2 = chieu_y(y_3D, 0);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(x_3D, 0);
	y2 = chieu_y(y_3D + canh_3D, 0);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	delay(1000);
	
	//chieu len oxz
	x1 = chieu_x(x_3D, z_3D);
	y1 = chieu_y(0, z_3D);
	
	x2 = chieu_x(x_3D + canh_3D, z_3D);
	y2 = chieu_y(0, z_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(x_3D, z_3D - canh_3D);
	y2 = chieu_y(0, z_3D - canh_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorG, 1);
	
	x1 = chieu_x(x_3D + canh_3D, z_3D - canh_3D);
	y1 = chieu_y(0, z_3D - canh_3D);
	
	x2 = chieu_x(x_3D + canh_3D, z_3D);
	y2 = chieu_y(0, z_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(x_3D, z_3D - canh_3D);
	y2 = chieu_y(0, z_3D - canh_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	delay(1000);
	
	//chieu len oyz
	x1 = chieu_x(0, z_3D);
	y1 = chieu_y(y_3D, z_3D);
	
	x2 = chieu_x(0, z_3D);
	y2 = chieu_y(y_3D + canh_3D, z_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(0, z_3D - canh_3D);
	y2 = chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorG, 1);
	
	x1 = chieu_x(0, z_3D - canh_3D);
	y1 = chieu_y(y_3D +canh_3D, z_3D - canh_3D);
	
	x2 = chieu_x(0, z_3D);
	y2 = chieu_y(y_3D + canh_3D, z_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
	x2 = chieu_x(0, z_3D - canh_3D);
	y2 = chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorG, 1);
}

void ve_bong_Cylinder(){
	//chieu len Oxy
	int x1, x2, y1, y2;
	x1 = Ox_3D + size * chieu_x(x_3D - R_3D, 0);
	y1 = Oy_3D - size * chieu_y(y_3D, 0);
	
	x2 = Ox_3D + size * chieu_x(x_3D + R_3D, 0);
	y2 = Oy_3D - size * chieu_y(y_3D, 0);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D - R_3D, 0);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, 0);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	
	x1 = Ox_3D + size * chieu_x(x_3D + R_3D, 0);
	y1 = Oy_3D - size * chieu_y(y_3D + cao_3D, 0);

	x2 = Ox_3D + size * chieu_x(x_3D + R_3D, 0);
	y2 = Oy_3D - size * chieu_y(y_3D, 0);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D - R_3D, 0);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, 0);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	delay(1000);
	
	//chieu len Oxz
	int x_tam = Ox_3D + size * chieu_x(x_3D, z_3D);
	int y_tam = Oy_3D - size * chieu_y(0, z_3D);
	int r = R_3D * size;
	ElipMidpoint(x_tam, y_tam, r, r/2, colorG, 1);
	delay(1000);
	
	//chieu len Oyz
	x1 = Ox_3D + size * chieu_x(0, z_3D);
	y1 = Oy_3D - size * chieu_y(y_3D, z_3D);
	
	x2 = Ox_3D + size * chieu_x(0, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(0, z_3D - R_3D);
	y2 = Oy_3D - size * chieu_y(y_3D, z_3D - R_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	
	x1 = Ox_3D + size * chieu_x(0, z_3D - R_3D);
	y1 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D - R_3D);

	x2 = Ox_3D + size * chieu_x(0, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(0, z_3D - R_3D);
	y2 = Oy_3D - size * chieu_y(y_3D, z_3D - R_3D);
	Bresenham(x1, y1, x2, y2, colorG, 1);
}

void ve_bong_Pyramid(){
	//chieu len Oxy
	int x1, y1, x2, y2;
	x1 = Ox_3D + size * chieu_x(x_3D, 0);
	y1 = Oy_3D - size * chieu_y(y_3D, 0);
	
	x2 = Ox_3D + size * chieu_x(x_3D + lam_tron(canh_3D/2), 0);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, 0);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D + canh_3D, 0);
	y2 = Oy_3D - size * chieu_y(y_3D, 0);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	
	x1 = x2;
	y1 = y2;
	x2 = Ox_3D + size * chieu_x(x_3D + lam_tron(canh_3D/2), 0);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, 0);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	
	//chieu len Oxz
	x1 = Ox_3D + size * chieu_x(x_3D, z_3D);
	y1 = Oy_3D - size * chieu_y(0, z_3D);
	
	x2 = Ox_3D + size * chieu_x(x_3D + canh_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D, z_3D - canh_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D - canh_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D + canh_3D, z_3D - canh_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D - canh_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	
	x1 = x2;
	y1 = y2;
	
	x2 = Ox_3D + size * chieu_x(x_3D + canh_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	x2 = Ox_3D + size * chieu_x(x_3D, z_3D - canh_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D - canh_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	
	x1 = x2;
	y1 = y2;
	
	x2 = Ox_3D + size * chieu_x(x_3D + canh_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(0, z_3D);
	Bresenham(x2, y2, x1, y1, colorG, 1);
	
	//chieu len Oyz
	x1 = Ox_3D + size * chieu_x(0, z_3D);
	y1 = Oy_3D - size * chieu_y(y_3D, z_3D);
	
	x2 = Ox_3D + size * chieu_x(0, z_3D - lam_tron(canh_3D/2));
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D - lam_tron(canh_3D/2));
	Bresenham(x1, y1, x2, y2, colorG, 1);
	x2 = Ox_3D + size * chieu_x(0, z_3D - canh_3D);
	y2 = Oy_3D - size * chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(x1, y1, x2, y2, colorG, 1);
	
	x1 = x2;
	y1 = y2;
	x2 = Ox_3D + size * chieu_x(0, z_3D - lam_tron(canh_3D/2));
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D - lam_tron(canh_3D/2));
	Bresenham(x1, y1, x2, y2, colorG, 1);
}

void in_gtri(int xdinh_hinh, int h, int t){
	cout << "";
	//xdinh = 0 la Cube; xdinh = 1 la Pyramid
	if ((xdinh_hinh == 0) && (h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75+ 50)) && (t < (5 + 50 + 5 + 50 + 75+ 50 + 40 * 4))){
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50, 0);
		}
		else if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40, 1);
		}
		else if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 2, 2);
		}
		else if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 4))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 3, 3);
		}
	}
	if ((xdinh_hinh == 1) && (h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75+ 50)) && (t < (5 + 50 + 5 + 50 + 75+ 50 + 40 * 5))){
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50, 0);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40, 1);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 2, 2);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 4))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 3, 3);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 4)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 5))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 4, 4);
		}
	}
	if ((xdinh_hinh == 2) && (h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75+ 50)) && (t < (5 + 50 + 5 + 50 + 75+ 50 + 40 * 5))){
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50, 0);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40, 1);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 2)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 2, 2);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 3)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 4))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 3, 3);
		}
		if((h > (dai - 450 + 5 + 100)) && (h < (dai - 450 + 5 + 100 + 100)) && (t > (5 + 50 + 5 + 50 + 75 + 50 + 40 * 4)) && (t < (5 + 50 + 5 + 50 + 75 + 50 + 40 * 5))){
			nhap_so(dai - 450 + 5 + 100, 5 + 50 + 5 + 50 + 75 + 50 + 40 * 4, 4);
		}
	}
}

void xuli_ve_3D_Cube(){
	int arr_toa_do_nhan[2][3];
	for (int i = 0;i<3;i++){
		arr_toa_do_nhan[0][i] = 0;
		arr_toa_do_nhan[1][i] = 0;
	}
	int a, b, c;
	a = b = c = 0;
	int arr_tam[8][3];
	for(int i = 1; i<=7; i = i + 2){
		for(int j = 0; j < 8; j++){
			if(((toa_do_diem_Cube[i][0]==toa_do_diem_Cube[j][0]) && (toa_do_diem_Cube[i][1]==toa_do_diem_Cube[j][1])) ||
				((toa_do_diem_Cube[i][0]==toa_do_diem_Cube[j][0]) && (toa_do_diem_Cube[i][2]==toa_do_diem_Cube[j][2])) ||
				((toa_do_diem_Cube[i][2]==toa_do_diem_Cube[j][2]) && (toa_do_diem_Cube[i][1]==toa_do_diem_Cube[j][1]))){
				
					int x1 = chieu_x(toa_do_diem_Cube[i][0], toa_do_diem_Cube[i][2]);
					int y1 = chieu_y(toa_do_diem_Cube[i][1], toa_do_diem_Cube[i][2]);
					int x2 = chieu_x(toa_do_diem_Cube[j][0], toa_do_diem_Cube[j][2]);
					int y2 = chieu_y(toa_do_diem_Cube[j][1], toa_do_diem_Cube[j][2]);
					if(i == 7){
						//cout << x2 << "," << y2 << "," << x1 << "," << y1<<endl;
						//cout << toa_do_diem_Cube[i][0] <<","<< toa_do_diem_Cube[i][1] <<","<< toa_do_diem_Cube[i][2] << endl;
						
						Bresenham(x1 * size + Ox_3D, Oy_3D - y1 * size, x2 * size + Ox_3D, Oy_3D - y2 * size, colorR, 0);
					}
					else if((i == 1) || (i == 3)){
						Bresenham(x2 * size + Ox_3D, Oy_3D - y2 * size, x1 * size + Ox_3D, Oy_3D - y1 * size, colorR, 1);
					}
					else{
						Bresenham(x1 * size + Ox_3D, Oy_3D - y1 * size, x2 * size + Ox_3D, Oy_3D - y2 * size, colorR, 1);
					}
				}
		}
		if((toa_do_diem_Cube[i][0] > 0) && (toa_do_diem_Cube[i][0] != arr_toa_do_nhan[a-1][0]) && (a < 2)){
			arr_toa_do_nhan[a][0] = toa_do_diem_Cube[i][0];
			a++;
		}
		if((toa_do_diem_Cube[i][1] > 0) && (toa_do_diem_Cube[i][1] != arr_toa_do_nhan[b-1][1]) && (b < 2)){
			arr_toa_do_nhan[b][1] = toa_do_diem_Cube[i][1];
			b++;
		}
		if((toa_do_diem_Cube[i][2] > 0) && (toa_do_diem_Cube[i][2] != arr_toa_do_nhan[c-1][2]) && (c < 2)){
			arr_toa_do_nhan[c][2] = toa_do_diem_Cube[i][2];
			c++;
		}
	}
	//lam ro truc toa do
	int ngang = dai - 500;
	int doc = rong - 20;
	setcolor(colorGra - 1);
	
	line(Ox_3D + 1, Oy_3D, Ox_3D + 1, 5);
	line(Ox_3D, Oy_3D, Ox_3D, 5);
	line(Ox_3D - 1, Oy_3D, Ox_3D - 1, 5);
	
	line(Ox_3D, Oy_3D + 1, ngang - 5, Oy_3D + 1);
	line(Ox_3D, Oy_3D, ngang - 5, Oy_3D);
	line(Ox_3D, Oy_3D - 1, ngang - 5, Oy_3D - 1);

	if(Ox_3D < Oy_3D){
		line(Ox_3D, Oy_3D + 1, 5 + (Ox_3D - (doc -  Oy_3D)) + 1, doc - 5);
		line(Ox_3D, Oy_3D, 5 + (Ox_3D - (doc -  Oy_3D)), doc - 5);
		line(Ox_3D, Oy_3D - 1, 5 + (Ox_3D - (doc -  Oy_3D)) - 1, doc - 5);
	}
	else{
		line(Ox_3D, Oy_3D + 1, 5, doc - ((doc - Oy_3D) - Ox_3D) + 1);
		line(Ox_3D, Oy_3D, 5, doc - ((doc - Oy_3D) - Ox_3D));
		line(Ox_3D, Oy_3D - 1, 5, doc - ((doc - Oy_3D) - Ox_3D) - 1);
	}
	if(a == 1){
		int tam;
		tam = arr_toa_do_nhan[0][0];
		arr_toa_do_nhan[0][0] = arr_toa_do_nhan[1][0];
		arr_toa_do_nhan[1][0] = tam;
	}
	if((a == 0) || (b == 0) || (c == 0)){
		//ve_bong_Cube();
	}
	else{
		//ve_bong_Cube();
		int dem = 0;
		for(int i = 1; i >= 0; i--){
			for (int j = 0; j< 2;j++){
				for(int k=0; k<2; k++){
					arr_tam[dem][0] = arr_toa_do_nhan[i][0];
					arr_tam[dem][1] = arr_toa_do_nhan[j][1];
					arr_tam[dem][2] = arr_toa_do_nhan[k][2];
					dem++;
				}
			}
		}
		for(int i=7; i >= 0; i = i - 1){
			//cout << arr_tam[i][0] << "," << arr_tam[i][1] << "," << arr_tam[i][2] << "||"<<endl;
			for(int j = 0; j < i; j++){
				if(((arr_tam[i][0]==arr_tam[j][0]) && (arr_tam[i][1]==arr_tam[j][1])) ||
					((arr_tam[i][0]==arr_tam[j][0]) && (arr_tam[i][2]==arr_tam[j][2])) ||
					((arr_tam[i][2]==arr_tam[j][2]) && (arr_tam[i][1]==arr_tam[j][1]))){
						//cout << arr_tam[j][0] << "," << arr_tam[j][1] << "," << arr_tam[j][2]<<endl;
						int x1 = chieu_x(arr_tam[i][0], arr_tam[i][2]);
						int y1 = chieu_y(arr_tam[i][1], arr_tam[i][2]);
						int x2 = chieu_x(arr_tam[j][0], arr_tam[j][2]);
						int y2 = chieu_y(arr_tam[j][1], arr_tam[j][2]);
//						cout << arr_tam[i][0] << "," << arr_tam[i][1] << "," << arr_tam[i][2]<<endl;
//						cout << arr_tam[j][0] << "," << arr_tam[j][1] << "," << arr_tam[j][2]<<endl;
//						cout << x1 << "," << y1 << "," << x2 << "," << y2<<endl;
						if((arr_tam[i][0] == be_hon(arr_toa_do_nhan[0][0],arr_toa_do_nhan[1][0])) && 
							(arr_tam[i][1] == be_hon(arr_toa_do_nhan[0][1],arr_toa_do_nhan[1][1])) && 
							(arr_tam[i][2] == be_hon(arr_toa_do_nhan[0][2],arr_toa_do_nhan[1][2]))){	
								//cout << arr_tam[i][0] << "," << arr_tam[i][1] << "," << arr_tam[i][2]<< "!!!" << endl;
								Bresenham(x1 * size + Ox_3D, Oy_3D - y1 * size, x2 * size + Ox_3D, Oy_3D - y2 * size, colorOr, 0);
						}
						else{
							Bresenham(x1 * size + Ox_3D, Oy_3D - y1 * size, x2 * size + Ox_3D, Oy_3D - y2 * size, colorOr, 1);
						}
					}
			}
		}
	}
//	for (int i = 0;i<3;i++){
//		cout << arr_toa_do_nhan[0][i] << ", " <<
//		arr_toa_do_nhan[1][i]<< endl;
//	}
}

void xuli_ve_3D_Cylinder(){
	int x_tam = Ox_3D + size * chieu_x(x_3D, z_3D);
	int y_tam = Oy_3D - size * chieu_y(y_3D, z_3D);
	int r = R_3D * size;
	putdiem(x_tam, y_tam, colorR);
	ElipMidpoint(x_tam , y_tam, r, r/2, colorR, 0);
	
	int x1, x2, y1, y2;
	
	x1 = Ox_3D + size * chieu_x(x_3D + R_3D, z_3D);
	y1 = Oy_3D - size * chieu_y(y_3D, z_3D);
	
	x2 = Ox_3D + size * chieu_x(x_3D + R_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	Bresenham(x2, y2, x1, y1, colorR, 1);
	
	x1 = Ox_3D + size * chieu_x(x_3D - R_3D, z_3D);
	y1 = Oy_3D - size * chieu_y(y_3D, z_3D);
	
	x2 = Ox_3D + size * chieu_x(x_3D - R_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	Bresenham(x1, y1, x2, y2, colorR, 1);
	x2 = Ox_3D + size * chieu_x(x_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D, z_3D);
	Bresenham(x1, y1, x2, y2, colorR, 0);
	
	x_tam = Ox_3D + size * chieu_x(x_3D, z_3D);
	y_tam = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	ElipMidpoint(x_tam, y_tam, r, r/2, colorR, 1);
	
	Bresenham(x_tam, y_tam, x2, y2, colorR, 0);
	x2 = Ox_3D + size * chieu_x(x_3D - R_3D, z_3D);
	y2 = Oy_3D - size * chieu_y(y_3D + cao_3D, z_3D);
	Bresenham(x_tam, y_tam, x2, y2, colorR, 1);
	
	//lam ro truc
	int ngang = dai - 500;
	int doc = rong - 20;
	setcolor(colorGra - 1);
	
	line(Ox_3D + 1, Oy_3D, Ox_3D + 1, 5);
	line(Ox_3D, Oy_3D, Ox_3D, 5);
	line(Ox_3D - 1, Oy_3D, Ox_3D - 1, 5);
	
	line(Ox_3D, Oy_3D + 1, ngang - 5, Oy_3D + 1);
	line(Ox_3D, Oy_3D, ngang - 5, Oy_3D);
	line(Ox_3D, Oy_3D - 1, ngang - 5, Oy_3D - 1);

	if(Ox_3D < Oy_3D){
		line(Ox_3D, Oy_3D + 1, 5 + (Ox_3D - (doc -  Oy_3D)) + 1, doc - 5);
		line(Ox_3D, Oy_3D, 5 + (Ox_3D - (doc -  Oy_3D)), doc - 5);
		line(Ox_3D, Oy_3D - 1, 5 + (Ox_3D - (doc -  Oy_3D)) - 1, doc - 5);
	}
	else{
		line(Ox_3D, Oy_3D + 1, 5, doc - ((doc - Oy_3D) - Ox_3D) + 1);
		line(Ox_3D, Oy_3D, 5, doc - ((doc - Oy_3D) - Ox_3D));
		line(Ox_3D, Oy_3D - 1, 5, doc - ((doc - Oy_3D) - Ox_3D) - 1);
	}
}

void ve_duong_cheo(int x1, int y1, int x2, int y2, int color_First, int xdinh, int chuyen_mau, int thu_tu_dcheo){	
	int c2, c, Dx, Dy, x, y;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    c = Dx - Dy;
    c2 = 2*c;
    x = x1;
    y = y1;
    int an = 4;
	int hien = 5; 
    int colorCheo = color_First;
    int cho_phep = 0;
    int x_unit = 1, y_unit = 1;
    
    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;
	
	if (xdinh == 1){
		putdiem(x, y, colorCheo);
		if (x1 != x2 && y1 != y2)  // duong xien
    	{
    	    while(x != x2+1)
    	    {
	            //delay(DELAY);
	            c2 =2*c;
	            if (c2 > -Dy)
	            {
	                c = c - Dy;
	                x = x + x_unit;
	            }
	            if (c2 < Dx)
	            {
                	c = c + Dx;
            	    y = y + y_unit; 
            	}
            	if ((x == (Ox_3D + chuyen_mau * size)) && (cho_phep == 0)){
            		//cout << Ox_3D + chuyen_mau * size<< ",," << x << endl; 
					if (colorCheo == colorOr){
            			colorCheo = colorR;
					}
					else{
            			colorCheo = colorOr;
					}
					cho_phep = 1;
					arr_cheo_cat_mp[thu_tu_dcheo][0] = x;
					arr_cheo_cat_mp[thu_tu_dcheo][1] = y;
				}
				//cout << Ox_3D + chuyen_mau * size << "," << chuyen_mau << "," << x << endl; 
           		putdiem(x, y, colorCheo);
        	}
    	}
	}
	if (xdinh == 0){
		putdiem(x, y, colorCheo);
		if (x1 != x2 && y1 != y2)  // duong xien
    	{
    	    while(x != x2+1)
    	    {
	            //delay(DELAY);
	            c2 =2*c;
	            if (c2 > -Dy)    
	            {
	                c = c - Dy; 
	                x = x + x_unit;
	            }
	            if (c2 < Dx) 
	            {
                	c = c + Dx; 
            	    y = y + y_unit; 
            	}
            	if ((x == (Ox_3D + chuyen_mau * size)) && (cho_phep == 0)){
            		//cout << Ox_3D + chuyen_mau * size << ",," << x <<endl; 
					if (colorCheo == colorOr){
            			colorCheo = colorR;
					}
					else{
            			colorCheo = colorOr;
					}
					cho_phep = 1;
					arr_cheo_cat_mp[thu_tu_dcheo][0] = x;
					arr_cheo_cat_mp[thu_tu_dcheo][1] = y;
				}
           		if (hien > 0){
            		putdiem(x, y, colorCheo);
            		//cout << Ox_3D + chuyen_mau * size << "," << chuyen_mau << "," << x << endl; 
            		hien = hien - 1;
				}
				else if ((an > 0) && (hien <= 0)){
					an = an - 1;
				}
				else if ((an <= 0) && (hien <= 0)){
					an = 4;
					hien = 6;
				}
        	}
    	}
	}
}

void xuli_ve_3D_Pyramid(){	
	
	int x1, y1, x2, y2;
	x1 = chieu_x(x_3D + (canh_3D/2),z_3D - lam_tron(canh_3D/2));
	y1 = chieu_y(y_3D + cao_3D,z_3D - lam_tron(canh_3D/2));
	
	x2 = chieu_x(x_3D, z_3D);
	y2 = chieu_y(y_3D, z_3D);
	Bresenham(Ox_3D + x1 * size , Oy_3D - y1 * size , Ox_3D + x2 * size - 2, Oy_3D - y2 * size + 2, colorR, 1);
	x2 = chieu_x(x_3D + canh_3D, z_3D - canh_3D);
	y2 = chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1);
	x2 = chieu_x(x_3D + canh_3D, z_3D);
	y2 = chieu_y(y_3D, z_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1);
	
	x1 = x2;
	y1 = y2;
	
	x2 = chieu_x(x_3D, z_3D);
	y2 = chieu_y(y_3D, z_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1);
	x2 = chieu_x(x_3D + canh_3D, z_3D - canh_3D);
	y2 = chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1);
	
	x1 = chieu_x(x_3D, z_3D - canh_3D);
	y1 = chieu_y(y_3D, z_3D - canh_3D);
	
	x2 = chieu_x(x_3D + canh_3D, z_3D - canh_3D);
	y2 = chieu_y(y_3D, z_3D - canh_3D);
	Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorR, 0);
	
	if((phep_chieu == 2) && (cao_3D >= lam_tron(canh_3D / 2))){
		x2 = chieu_x(x_3D, z_3D);
		y2 = chieu_y(y_3D, z_3D);
		Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorR, 0);
		x2 = chieu_x(x_3D + (canh_3D/2),z_3D - lam_tron(canh_3D/2));
		y2 = chieu_y(y_3D + cao_3D,z_3D - lam_tron(canh_3D/2));
		Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 0);
	}
	else if((phep_chieu == 2) && (cao_3D < lam_tron(canh_3D / 2))){
		x2 = chieu_x(x_3D, z_3D);
		y2 = chieu_y(y_3D, z_3D);
		Bresenham(Ox_3D + x1 * size, Oy_3D - y1 * size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorR, 1);
		x2 = chieu_x(x_3D + (canh_3D/2),z_3D - lam_tron(canh_3D/2));
		y2 = chieu_y(y_3D + cao_3D,z_3D - lam_tron(canh_3D/2));
		Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1);
	}
	
	//tim mp cat mat day
	if(y_3D >= 0){
		int toa_do_mday_nhan[2][2];
		int arr_tam[6][3];
		for (int i =0; i<2;i++){
			toa_do_mday_nhan[i][0] = toa_do_mday_nhan[i][1] = 0;
		}
		int a,b;
		a = b = 0;
		for(int i = 0; i<4;i++){
			if((toa_do_diem_Pyramid[i][0] >= 0) && (toa_do_diem_Pyramid[i][0] != toa_do_mday_nhan[a-1][0]) && (a<2)){
				toa_do_mday_nhan[a][0] = toa_do_diem_Pyramid[i][0];
				a++;
			}
			if((toa_do_diem_Pyramid[i][2] >= 0) && (toa_do_diem_Pyramid[i][2] != toa_do_mday_nhan[b-1][1]) && (b<2)){
				toa_do_mday_nhan[b][1] = toa_do_diem_Pyramid[i][2];
				b++;
			}
		}
		if(a == 1){
			int tam;
			tam = toa_do_mday_nhan[0][0];
			toa_do_mday_nhan[0][0] = toa_do_mday_nhan[1][0];
			toa_do_mday_nhan[1][0] = tam;
		}
//		for (int i = 0;i<2;i++){
//			cout << toa_do_mday_nhan[i][0] << ", " << toa_do_mday_nhan[i][1] << endl; 
//		}
		
		if((a == 0) || (b == 0)){
		}
		else{
			//xac dinh toa do cua 4 dinh day mat phang vung hien
			arr_tam[0][0] = toa_do_mday_nhan[0][0];
			arr_tam[0][1] = y_3D;
			arr_tam[0][2] = toa_do_mday_nhan[0][1];
			
			arr_tam[1][0] = toa_do_mday_nhan[0][0];
			arr_tam[1][1] = y_3D;
			arr_tam[1][2] = toa_do_mday_nhan[1][1];
			
			arr_tam[3][0] = toa_do_mday_nhan[1][0];
			arr_tam[3][1] = y_3D;
			arr_tam[3][2] = toa_do_mday_nhan[0][1];
			
			arr_tam[2][0] = toa_do_mday_nhan[1][0];
			arr_tam[2][1] = y_3D;
			arr_tam[2][2] = toa_do_mday_nhan[1][1];
			
			int x1,x2,y1,y2;
			
			x1 = chieu_x(arr_tam[1][0], arr_tam[1][2]);
			y1 = chieu_y(arr_tam[1][1], arr_tam[1][2]);
			
			x2 = chieu_x(arr_tam[0][0], arr_tam[0][2]);
			y2 = chieu_y(arr_tam[0][1], arr_tam[0][2]);
			Bresenham(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 0);
			x2 = chieu_x(arr_tam[2][0], arr_tam[2][2]);
			y2 = chieu_y(arr_tam[2][1], arr_tam[2][2]);
			if(cao_3D > lam_tron(canh_3D / 4)){
				Bresenham(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 0);
			}
			else{
				Bresenham(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 1);
			}
			
			x1 = chieu_x(arr_tam[3][0], arr_tam[3][2]);
			y1 = chieu_y(arr_tam[3][1], arr_tam[3][2]);
			
			x2 = chieu_x(arr_tam[0][0], arr_tam[0][2]);
			y2 = chieu_y(arr_tam[0][1], arr_tam[0][2]);
			Bresenham(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 1);
			x2 = chieu_x(arr_tam[2][0], arr_tam[2][2]);
			y2 = chieu_y(arr_tam[2][1], arr_tam[2][2]);
			Bresenham(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1);
			
			//xac dinh giao diem cua duong cheo
			
			for (int i= 0; i<4;i++){
				arr_cheo_cat_mp[i][3] = 0;
			}
			
			if((a==2) & (b==2)){
				int x1, y1, x2, y2;
				x1 = chieu_x(x_3D + (canh_3D/2),z_3D - lam_tron(canh_3D/2));
				y1 = chieu_y(y_3D + cao_3D,z_3D - lam_tron(canh_3D/2));
				
				x2 = chieu_x(x_3D, z_3D);
				y2 = chieu_y(y_3D, z_3D);
				Bresenham(Ox_3D + x1 * size , Oy_3D - y1 * size , Ox_3D + x2 * size - 2, Oy_3D - y2 * size + 2, colorOr, 1);
				x2 = chieu_x(x_3D + canh_3D, z_3D - canh_3D);
				y2 = chieu_y(y_3D, z_3D - canh_3D);
				Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1);
				x2 = chieu_x(x_3D + canh_3D, z_3D);
				y2 = chieu_y(y_3D, z_3D);
				Bresenham(Ox_3D + x2 * size, Oy_3D - y2 * size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1);
				
				x1 = chieu_x(x_3D, z_3D - canh_3D);
				y1 = chieu_y(y_3D, z_3D - canh_3D);
				x2 = chieu_x(x_3D + (canh_3D/2),z_3D - lam_tron(canh_3D/2));
				y2 = chieu_y(y_3D + cao_3D,z_3D - lam_tron(canh_3D/2));
				if(cao_3D >= lam_tron(canh_3D / 2)){
				Bresenham(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 0);
				}
				else{
					Bresenham(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1);
				}
			}
			else if((b==2) && (a==1)){
				int xe = toa_do_diem_Pyramid[4][0];
				int ye = toa_do_diem_Pyramid[4][1];
				int ze = toa_do_diem_Pyramid[4][2];
				if (xe > 0){
					int x1 = chieu_x(xe, ze);
					int y1 = chieu_y(ye, ze);
					
					int x2 = chieu_x(toa_do_diem_Pyramid[1][0], toa_do_diem_Pyramid[1][2]);
					int y2 = chieu_y(toa_do_diem_Pyramid[1][1], toa_do_diem_Pyramid[1][2]);
					if(cao_3D >= lam_tron(canh_3D / 2)){
						ve_duong_cheo(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 0, chieu_x(0, arr_tam[1][2]), 1);
					}
					else{
						ve_duong_cheo(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 1, chieu_x(0, arr_tam[1][2]), 1);
					}
					x2 = chieu_x(toa_do_diem_Pyramid[0][0], toa_do_diem_Pyramid[0][2]);
					y2 = chieu_y(toa_do_diem_Pyramid[0][1], toa_do_diem_Pyramid[0][2]);
					ve_duong_cheo(Ox_3D + x1 * size, Oy_3D - y1 *size, Ox_3D + x2 * size, Oy_3D - y2 * size, colorOr, 1, chieu_x(0, arr_tam[0][2]), 0);
					x2 = chieu_x(toa_do_diem_Pyramid[2][0], toa_do_diem_Pyramid[2][2]);
					y2 = chieu_y(toa_do_diem_Pyramid[2][1], toa_do_diem_Pyramid[2][2]);
					ve_duong_cheo(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1, chieu_x(arr_tam[2][0], arr_tam[2][2]), 2);
					x2 = chieu_x(toa_do_diem_Pyramid[3][0], toa_do_diem_Pyramid[3][2]);
					y2 = chieu_y(toa_do_diem_Pyramid[3][1], toa_do_diem_Pyramid[3][2]);
					if (cao_3D < canh_3D/2){
						ve_duong_cheo(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorOr, 1, chieu_x(arr_tam[3][0], arr_tam[3][2]), 3);
					}
					else{
						ve_duong_cheo(Ox_3D + x2 * size, Oy_3D - y2 *size, Ox_3D + x1 * size, Oy_3D - y1 * size, colorR, 1, chieu_x(arr_tam[3][0], arr_tam[3][2]), 3);
					}
					
					x1 = arr_cheo_cat_mp[1][0];
					y1 = arr_cheo_cat_mp[1][1];
					
					x2 = Ox_3D + chieu_x(arr_tam[1][0], arr_tam[1][2]) * size;
					y2 = Oy_3D - chieu_y(arr_tam[1][1], arr_tam[1][2]) * size;
					if (cao_3D > lam_tron(canh_3D/4)){
						Bresenham(x1, y1, x2, y2, colorOr, 0);
					}
					x2 = arr_cheo_cat_mp[0][0];
					y2 = arr_cheo_cat_mp[0][1];
					if (cao_3D > lam_tron(canh_3D/2)){
						Bresenham(x1, y1, x2, y2, colorOr, 0);
					}
					x1 = x2;
					y1 = y2;
					
					x2 = Ox_3D + chieu_x(arr_tam[0][0], arr_tam[0][2]) * size;
					y2 = Oy_3D - chieu_y(arr_tam[0][1], arr_tam[0][2]) * size;
					Bresenham(x1, y1, x2, y2, colorOr, 1);
				}
			}
		}
	}
}

void ve_3D(int xdinh_hinh){
	//cout << x_3D << ", " << y_3D << ", " << z_3D << ", " << canh_3D << endl;
	int x = x_3D;
	int y = y_3D;
	int z = z_3D;
	int canh = canh_3D;

	int ox = Ox_3D;
	int oy = Oy_3D;
	
	putdiem(ox, oy, colorG);
	if (xdinh_hinh == 0){
		toa_do_diem_Cube[0][0] = x;
		toa_do_diem_Cube[0][1] = y;
		toa_do_diem_Cube[0][2] = z;
		
		toa_do_diem_Cube[7][0] = x;
		toa_do_diem_Cube[7][1] = y;
		toa_do_diem_Cube[7][2] = z - canh;

		toa_do_diem_Cube[3][0] = x + canh;
		toa_do_diem_Cube[3][1] = y;
		toa_do_diem_Cube[3][2] = z;

		toa_do_diem_Cube[1][0] = x;
		toa_do_diem_Cube[1][1] = y + canh;
		toa_do_diem_Cube[1][2] = z;
		
		x = x + canh;
		z = z - canh;
		toa_do_diem_Cube[4][0] = x;
		toa_do_diem_Cube[4][1] = y;
		toa_do_diem_Cube[4][2] = z;

		toa_do_diem_Cube[5][0] = x;
		toa_do_diem_Cube[5][1] = y + canh;
		toa_do_diem_Cube[5][2] = z;
		
		x = x - canh;
		y = y + canh;
		toa_do_diem_Cube[6][0] = x;
		toa_do_diem_Cube[6][1] = y;
		toa_do_diem_Cube[6][2] = z;
		
		x = x + canh;
		z = z + canh;
		toa_do_diem_Cube[2][0] = x;
		toa_do_diem_Cube[2][1] = y;
		toa_do_diem_Cube[2][2] = z;

//		for(int i =0;i<8;i++){
//			cout << toa_do_diem_Cube[i][0] << "," << toa_do_diem_Cube[i][1]<< "," <<toa_do_diem_Cube[i][2] << endl;
//		}
		xuli_ve_3D_Cube();
	}
	else if(xdinh_hinh == 2){
		toa_do_diem_Cylinder[0][0] = x;
		toa_do_diem_Cylinder[0][1] = y;
		toa_do_diem_Cylinder[0][2] = z;
		
		toa_do_diem_Cylinder[1][0] = x - R_3D;
		toa_do_diem_Cylinder[1][1] = y;
		toa_do_diem_Cylinder[1][2] = z;
		
		toa_do_diem_Cylinder[2][0] = x;
		toa_do_diem_Cylinder[2][1] = y;
		toa_do_diem_Cylinder[2][2] = z - R_3D;
		
		toa_do_diem_Cylinder[3][0] = x + R_3D;
		toa_do_diem_Cylinder[3][1] = y;
		toa_do_diem_Cylinder[3][2] = z;
		
		toa_do_diem_Cylinder[4][0] = x;
		toa_do_diem_Cylinder[4][1] = y;
		toa_do_diem_Cylinder[4][2] = z + R_3D;
		
		toa_do_diem_Cylinder[5][0] = x;
		toa_do_diem_Cylinder[5][1] = y + cao_3D;
		toa_do_diem_Cylinder[5][2] = z;
		
		toa_do_diem_Cylinder[6][0] = x - R_3D;
		toa_do_diem_Cylinder[6][1] = y + cao_3D;
		toa_do_diem_Cylinder[6][2] = z;
		
		toa_do_diem_Cylinder[7][0] = x;
		toa_do_diem_Cylinder[7][1] = y + cao_3D;
		toa_do_diem_Cylinder[7][2] = z - R_3D;
		
		toa_do_diem_Cylinder[8][0] = x + R_3D;
		toa_do_diem_Cylinder[8][1] = y + cao_3D;
		toa_do_diem_Cylinder[8][2] = z;
		
		toa_do_diem_Cylinder[9][0] = x;
		toa_do_diem_Cylinder[9][1] = y - cao_3D;
		toa_do_diem_Cylinder[9][2] = z + R_3D;
		
		xuli_ve_3D_Cylinder();
	}
	else if(xdinh_hinh == 1){
		toa_do_diem_Pyramid[0][0] = x;
		toa_do_diem_Pyramid[0][1] = y;
		toa_do_diem_Pyramid[0][2] = z;
		int cao = cao_3D;
		
		toa_do_diem_Pyramid[1][0] = x;
		toa_do_diem_Pyramid[1][1] = y;
		toa_do_diem_Pyramid[1][2] = z - canh;
		
		toa_do_diem_Pyramid[2][0] = x + canh;
		toa_do_diem_Pyramid[2][1] = y;
		toa_do_diem_Pyramid[2][2] = z - canh;
		
		toa_do_diem_Pyramid[3][0] = x + canh;
		toa_do_diem_Pyramid[3][1] = y;
		toa_do_diem_Pyramid[3][2] = z;
		
		toa_do_diem_Pyramid[4][0] = x + lam_tron(canh/2);
		toa_do_diem_Pyramid[4][1] = y + cao;
		toa_do_diem_Pyramid[4][2] = z - lam_tron(canh/2);
		
		xuli_ve_3D_Pyramid();
	}
}

void ve_table_3D(int kt){
	int y0 = 5 + 50 + 5 + 50 + 75 + 50;
	int x0 = dai - 450 + 5;
	int kcach = 5;
	
	thong_bao("Nhap toa do|Click SHOW de ve!!!", 2, 2);
	//ve Cube
	if (kt == 0){
		Clear_Area(x0 ,y0, dai, rong);
		settextstyle(0, 0, 3);
		
		ve_table(x0, y0, 4, 2, kcach, 100, 40);
		outtextxy(x0 + 100/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 100/2 - textwidth("y")/2, y0 + 5 + 40 + 40/2 - textheight("y")/2, "y");
		outtextxy(x0 + 100/2 - textwidth("z")/2, y0 + 5 + 40 + 40 +  40/2 - textheight("z")/2, "z");
		settextstyle(0, 0, 2);
		outtextxy(x0 + 100/2 - textwidth("Canh")/2, y0 + 5 + 40 + 40 + 40 + 40/2 - textheight("Canh")/2, "Canh");
	}
	//ve Cylinder
	if (kt == 2){
		Clear_Area(x0, y0, dai, rong);
		settextstyle(0, 0, 3);
		
		ve_table(x0, y0, 5, 2, kcach, 100, 40);
		outtextxy(x0 + 100/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 100/2 - textwidth("y")/2, y0 + 5 + 40 + 40/2 - textheight("y")/2, "y");
		outtextxy(x0 + 100/2 - textwidth("z")/2, y0 + 5 + 40 + 40 +  40/2 - textheight("z")/2, "z");
		settextstyle(0, 0, 2);
		outtextxy(x0 + 100/2 - textwidth("Rday")/2, y0 + 5 + 40 + 40 + 40 + 40/2 - textheight("Rday")/2, "Rday");
		outtextxy(x0 + 100/2 - textwidth("cao")/2, y0 + 5 + 40 + 40 + 40 + 40 + 40/2 - textheight("Cao")/2, "Cao");
	}
	//ve Pyramid
	if (kt == 1){
		Clear_Area(x0, y0, dai, rong);
		settextstyle(0, 0, 3);
		
		ve_table(x0, y0, 5, 2, kcach, 100, 40);
		outtextxy(x0 + 100/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 100/2 - textwidth("y")/2, y0 + 5 + 40 + 40/2 - textheight("y")/2, "y");
		outtextxy(x0 + 100/2 - textwidth("z")/2, y0 + 5 + 40 + 40 +  40/2 - textheight("z")/2, "z");
		settextstyle(0, 0, 2);
		outtextxy(x0 + 100/2 - textwidth("Cday")/2, y0 + 5 + 40 + 40 + 40 + 40/2 - textheight("Cday")/2, "Cday");
		outtextxy(x0 + 100/2 - textwidth("cao")/2, y0 + 5 + 40 + 40 + 40 + 40 + 40/2 - textheight("Cao")/2, "Cao");
	}
}

void show_kqua_3D(int nho_3D){
	
	int x0 = dai - 450 + 5 + 100 * 2;
	int y0 = 5 + 50 + 5 + 50 + 75 + 50;
		
	if(nho_3D == 0){		
		settextstyle(0, 0, 3);
		ve_table(x0 + 5, y0, 9, 3, 5, 70, 40);
		outtextxy(x0 + 5 + 70/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth("z")/2, y0 + 5 + 40/2 - textheight("z")/2, "z");
		outtextxy(x0 + 5 + 70 + 70/2 - textwidth("y")/2, y0 + 5 + 40/2 - textheight("y")/2, "y");
		for (int i = 0; i<8; i++){
			settextstyle(0, 0, 2);
			Clear_Area(x0 + 5 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			char *p = chuyen(toa_do_diem_Cube[i][0]);
			outtextxy(x0 + 5 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			p = chuyen(toa_do_diem_Cube[i][1]);
			outtextxy(x0 + 5 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 - 3);
			p = chuyen(toa_do_diem_Cube[i][2]);
			outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
		}
		delay(2000);
		Clear_Area(5-2, 5-2, dai - 500, rong - 20);
		grid(size, dai - 500, rong - 20, colorGra , 3);
		kt_grid = 0;
		ve_bong_Cube();
	}
	else if(nho_3D == 2){
		settextstyle(0, 0, 3);
		ve_table(x0 + 5, y0, 11, 3, 5, 70, 40);	
		outtextxy(x0 + 5 + 70/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 5 + 70 + 70/2 - textwidth("y")/2, y0 + 5 + 40/2 - textheight("y")/2, "y");
		outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth("z")/2, y0 + 5 + 40/2 - textheight("z")/2, "z");
		for (int i = 0; i<10; i++){
			settextstyle(0, 0, 2);
			Clear_Area(x0 + 5 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			char *p = chuyen(toa_do_diem_Cylinder[i][0]);
			outtextxy(x0 + 5 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			p = chuyen(toa_do_diem_Cylinder[i][1]);
			outtextxy(x0 + 5 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 - 3);
			p = chuyen(toa_do_diem_Cylinder[i][2]);
			outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
		}
		delay(2000);
		Clear_Area(5-2, 5-2, dai - 500, rong - 20);
		grid(size, dai - 500, rong - 20, colorGra, 3);
		kt_grid = 0;
		ve_bong_Cylinder();
	}
	else if(nho_3D == 1){
		settextstyle(0, 0, 3);
		ve_table(x0 + 5, y0, 6, 3, 5, 70, 40);	
		outtextxy(x0 + 5 + 70/2 - textwidth("x")/2, y0 + 5 + 40/2 - textheight("x")/2, "x");
		outtextxy(x0 + 5 + 70 + 70/2 - textwidth("y")/2, y0 + 5 + 40/2 - textheight("y")/2, "y");
		outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth("z")/2, y0 + 5 + 40/2 - textheight("z")/2, "z");
		for (int i = 0; i<5; i++){
			settextstyle(0, 0, 2);
			Clear_Area(x0 + 5 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			char *p = chuyen(toa_do_diem_Pyramid[i][0]);
			outtextxy(x0 + 5 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 -3);
			p = chuyen(toa_do_diem_Pyramid[i][1]);
			outtextxy(x0 + 5 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
			Clear_Area(x0 + 5 + 70 + 70 + 3, y0 + 5 + 40 * (i + 1) + 3, x0 + 5 + 70 + 70 + 70 - 3, y0 + 5 + 40 * (i + 1) + 40 - 3);
			p = chuyen(toa_do_diem_Pyramid[i][2]);
			outtextxy(x0 + 5 + 70 + 70 + 70/2 - textwidth(p)/2, y0 + 5 + 40 * (i + 1) + 40/2 - textheight(p)/2, p);
		}
		delay(2000);
		Clear_Area(5-2, 5-2, dai - 500, rong - 20);
		grid(size, dai - 500, rong - 20, colorGra, 3);
		kt_grid = 0;
		ve_bong_Pyramid();
	}
}

void show_3D(int kt, int h, int t){
	int button_Cube_x1 = dai - 450 + 225 - 200 - 5 - 5;
	int button_Cube_y1 = 5 + 50 + 5 + 50 + 75;
	int button_Cube_x2 = dai - 450 + 225 - 5 - 5;
	int button_Cube_y2 = 5 + 50 + 5 + 50 + 75 + 50;

	int button_Cylinder_x1 = dai - 200 - 5 - 5;
	int button_Cylinder_y1 = 5 + 50 + 5 + 50 + 75;
	int button_Cylinder_x2 = dai - 5 - 5;
	int button_Cylinder_y2 = 5 + 50 + 5 + 50 + 75 + 50;
	
	int button_Pyramid_x1 = dai - 200 - 5 - 5;
	int button_Pyramid_y1 = 5 + 50 + 5 + 50 + 75;
	int button_Pyramid_x2 = dai - 5 - 5;
	int button_Pyramid_y2 = 5 + 50 + 5 + 50 + 75 + 50;
	
	if (kt == 1){
		if ((h > button_Cube_x1) && (h < button_Cube_x2) && (t > button_Cube_y1) && (t < button_Cube_y2)){
			ve_hcn(button_Cube_x1 - 9, button_Cube_y1, button_Cube_x1 - 4, button_Cube_y2, 3, colorG);
			if(chon == 1){
				ve_hcn(button_Pyramid_x1 - 9, button_Pyramid_y1, button_Pyramid_x1 - 4, button_Pyramid_y2, 3, colorR);
			}
			else if(chon == 2){
				ve_hcn(button_Cylinder_x1 - 9, button_Cylinder_y1, button_Cylinder_x1 - 4, button_Cylinder_y2, 3, colorR);
			}
			ve_table_3D(0);
			nho_3D = 0;
			Clear_Area(5, 5, dai - 500, rong - 20);
			grid(size, dai - 500, rong - 20, colorGra * abs(kt_grid - 1), kt_play);
			x_3D = y_3D = z_3D = canh_3D = cao_3D = 0;
		}
		else if ((chon == 2) && (h > button_Cylinder_x1) && (h < button_Cylinder_x2) && (t > button_Cylinder_y1) && (t < button_Cylinder_y2)){
			ve_hcn(button_Cube_x1 - 9, button_Cube_y1, button_Cube_x1 - 4, button_Cube_y2, 3, colorR);
			ve_hcn(button_Cylinder_x1 - 9, button_Cylinder_y1, button_Cylinder_x1 - 4, button_Cylinder_y2, 3, colorG);
			ve_table_3D(2);
			nho_3D = 2;
			Clear_Area(5, 5, dai - 500, rong - 20);
			grid(size, dai - 500, rong - 20, colorGra * abs(kt_grid - 1), kt_play);
			x_3D = y_3D = z_3D =R_3D = cao_3D = 0;
		}
		else if ((chon == 1) && (h > button_Pyramid_x1) && (h < button_Pyramid_x2) && (t > button_Pyramid_y1) && (t < button_Pyramid_y2)){
			ve_hcn(button_Cube_x1 - 9, button_Cube_y1, button_Cube_x1 - 4, button_Cube_y2, 3, colorR);
			ve_hcn(button_Pyramid_x1 - 9, button_Pyramid_y1, button_Pyramid_x1 - 4, button_Pyramid_y2, 3, colorG);
			ve_table_3D(1);
			nho_3D = 1;
			Clear_Area(5, 5, dai - 500, rong - 20);
			grid(size, dai - 500, rong - 20, colorGra * abs(kt_grid - 1), kt_play);
			x_3D = y_3D = z_3D =canh_3D = cao_3D = 0;
		}
		else{
			in_gtri(nho_3D, h, t);
		}
	}
	if ( kt == 0){
		settextstyle(0, 0, 3);
	
		ve_hcn(button_Cube_x1, button_Cube_y1, button_Cube_x2, button_Cube_y2, 3, color);
		ve_hcn(button_Cube_x1 - 9, button_Cube_y1, button_Cube_x1 - 4, button_Cube_y2, 3, colorR);
		outtextxy((button_Cube_x2-button_Cube_x1)/2-textwidth("Cube")/2+button_Cube_x1,(button_Cube_y2-button_Cube_y1)/2-textheight("Cube")/2+button_Cube_y1, "Cube");

		if (chon == 2){
			ve_hcn(button_Cylinder_x1, button_Cylinder_y1, button_Cylinder_x2, button_Cylinder_y2, 3, color);
			ve_hcn(button_Cylinder_x1 - 9, button_Cylinder_y1, button_Cylinder_x1 - 4, button_Cylinder_y2, 3, colorR);
			outtextxy((button_Cylinder_x2-button_Cylinder_x1)/2-textwidth("Cylinder")/2+button_Cylinder_x1,(button_Cylinder_y2-button_Cylinder_y1)/2-textheight("Cylinder")/2+button_Cylinder_y1, "Cylinder");
		}
		else if(chon == 1){
			ve_hcn(button_Pyramid_x1, button_Pyramid_y1, button_Pyramid_x2, button_Pyramid_y2, 3, color);
			ve_hcn(button_Pyramid_x1 - 9, button_Pyramid_y1, button_Pyramid_x1 - 4, button_Pyramid_y2, 3, colorR);
			outtextxy((button_Pyramid_x2-button_Pyramid_x1)/2-textwidth("Pyramid")/2+button_Pyramid_x1,(button_Pyramid_y2-button_Pyramid_y1)/2-textheight("Pyramid")/2+button_Pyramid_y1, "Pyramid");
		}
	}
}

void ve_button_led(){
	int button_2D_x1 = dai - 450 + 150 - 100 - 5 - 5;
	int button_2D_y1 = 5;
	int button_2D_x2 = dai - 450 + 150 - 5 - 5;
	int button_2D_y2 = 5 + 50;

	int button_3D_x1 = dai - 450 + 300 - 100 - 5 - 5;
	int button_3D_y1 = 5;
	int button_3D_x2 = dai - 450 + 300 - 5 - 5;
	int button_3D_y2 = 5 + 50;

	int button_Grid_x1 = dai - 450 + 150 - 100 - 5 - 5;
	int button_Grid_y1 = 5 + 50 + 5;
	int button_Grid_x2 = dai - 450 + 150 - 5 - 5;
	int button_Grid_y2 = 5 + 50 + 5 + 50;

	int button_Exit_x1 = dai - 450 + 300 - 100 - 5 - 5;
	int button_Exit_y1 = 5 + 50 + 5;
	int button_Exit_x2 = dai - 450 + 300 - 5 - 5;
	int button_Exit_y2 = 5 + 50 + 5 + 50;
	
	int button_Play_x1 = dai - 450 + 300 - 5;
	int button_Play_y1 = 5;
	int button_Play_x2 = dai - 5 - 5;
	int button_Play_y2 = 5 + 50 + 5 + 50;
	
	//cout << button_3D_x1 << "|" << button_3D_y1 << "|" << button_3D_x2 << "|" << button_3D_y2;
	settextstyle(0, 0, 4);
	
	ve_hcn(button_2D_x1, button_2D_y1, button_2D_x2, button_2D_y2, 3, color);
	ve_hcn(button_2D_x1 - 9, button_2D_y1, button_2D_x1 - 4, button_2D_y2, 3, colorR);
	outtextxy((button_2D_x2-button_2D_x1)/2-textwidth("2D")/2+button_2D_x1,(button_2D_y2-button_2D_y1)/2-textheight("2D")/2+button_2D_y1, "2D");

	ve_hcn(button_3D_x1, button_3D_y1, button_3D_x2, button_3D_y2, 3, color);
	ve_hcn(button_3D_x1 - 9, button_3D_y1, button_3D_x1 - 4, button_3D_y2, 3, colorR);
	outtextxy((button_3D_x2-button_3D_x1)/2-textwidth("3D")/2+button_3D_x1,(button_3D_y2-button_3D_y1)/2-textheight("3D")/2+button_3D_y1, "3D");
	
	settextstyle(0,0,2);
	ve_hcn(button_Exit_x1, button_Exit_y1, button_Exit_x2, button_Exit_y2, 3, color);
	outtextxy((button_Exit_x2-button_Exit_x1)/2-textwidth("Exit")/2+button_Exit_x1,(button_Exit_y2-button_Exit_y1)/2-textheight("Exit")/2+button_Exit_y1, "Exit");

	int h,t;

	while (1){
		delay(DELAY);
		//nhan dup chuot trai nhan toa do diem
		if (ismouseclick(WM_LBUTTONDBLCLK)){
            getmouseclick(WM_LBUTTONDBLCLK, h, t);
			
			if ((h > button_2D_x1) && (h < button_2D_x2) && (t > button_2D_y1) && (t < button_2D_y2)){
				thong_bao("Click PLAY de bat dau!!!", 2, 1);
				Clear_Area(dai - 450 + 5, 5 + 50 + 5 + 50 + 75, dai - 5, rong);
				Clear_Area(5 - 2, 5 - 2, dai - 500, rong - 20);
				ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, colorG);
//				ve_table_2D();
				kt_play = 2;

				ve_hcn(button_2D_x1 - 9, button_2D_y1, button_2D_x1 - 4, button_2D_y2, 3, colorG);
				ve_hcn(button_3D_x1 - 9, button_3D_y1, button_3D_x1 - 4, button_3D_y2, 3, colorR);

				settextstyle(0, 0 , 3);
				
				ve_hcn(button_Play_x1, button_Play_y1, button_Play_x2, button_Play_y2, 3, color);
				setcolor(color_clear);
				outtextxy((button_Play_x2-button_Play_x1)/2-textwidth("SHOW")/2+button_Play_x1,(button_Play_y2-button_Play_y1)/2-textheight("SHOW")/2+button_Play_y1, "SHOW");
				setcolor(color);
				outtextxy((button_Play_x2-button_Play_x1)/2-textwidth("PLAY")/2+button_Play_x1,(button_Play_y2-button_Play_y1)/2-textheight("PLAY")/2+button_Play_y1, "PLAY");

				settextstyle(0, 0, 2);
				setcolor(color_clear);
				//ve_hcn(button_Grid_x1, button_Grid_y1, button_Grid_x2, button_Grid_y2, 3, color_clear);
				//ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, colorR);
				outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Grid")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Grid")/2+button_Grid_y1, "Grid");
				
				setcolor(color);
				settextstyle(0, 0, 1);
				ve_hcn(button_Grid_x1, button_Grid_y1, button_Grid_x2, button_Grid_y2, 3, color);
				ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, colorG);
				if (choose_2D == 1){
					outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Hinh 1")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Hinh 1")/2+button_Grid_y1, "Hinh 1");
				}
				else if (choose_2D == 2){
					outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Hinh 2")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Hinh 2")/2+button_Grid_y1, "Hinh 2");	
				}
			}
			else if ((h > button_3D_x1) && (h < button_3D_x2) && (t > button_3D_y1) && (t < button_3D_y2)){
				thong_bao("Chon loai hinh muon ve", 2, 1);
				Clear_Area(dai - 450 + 5, 5 + 50 + 5 + 50 + 75, dai - 5, rong);
				Clear_Area(5 - 2, 5 - 2, dai - 500, rong - 20);
				x_3D = y_3D = z_3D = R_3D = canh_3D = cao_3D = 0;
				ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, colorR);
				//grid(size, dai - 500, rong - 20, colorGra, 3);
				kt_grid = 1;
				ve_hcn(button_3D_x1 - 9, button_3D_y1, button_3D_x1 - 4, button_3D_y2, 3, colorG);
				ve_hcn(button_2D_x1 - 9, button_2D_y1, button_2D_x1 - 4, button_2D_y2, 3, colorR);
			
				settextstyle(0, 0, 3);
			
				ve_hcn(button_Play_x1, button_Play_y1, button_Play_x2, button_Play_y2, 3, color);
				setcolor(color_clear);
				outtextxy((button_Play_x2-button_Play_x1)/2-textwidth("PLAY")/2+button_Play_x1,(button_Play_y2-button_Play_y1)/2-textheight("PLAY")/2+button_Play_y1, "PLAY");
				setcolor(color);
				outtextxy((button_Play_x2-button_Play_x1)/2-textwidth("SHOW")/2+button_Play_x1,(button_Play_y2-button_Play_y1)/2-textheight("SHOW")/2+button_Play_y1, "SHOW");
				
				settextstyle(0, 0, 2);
				ve_hcn(button_Grid_x1, button_Grid_y1, button_Grid_x2, button_Grid_y2, 3, color);
				//ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, colorR);
				outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Grid")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Grid")/2+button_Grid_y1, "Grid");

				
				show_3D(0, h, t);
				kt_play = 3;				
			}
			else if ((h > button_Grid_x1) && (h < button_Grid_x2) && (t > button_Grid_y1) && (t < button_Grid_y2)){
				if (kt_play == 3){
					grid(size, dai - 500, rong - 20, colorGra * kt_grid, kt_play);
					ve_hcn(button_Grid_x1 - 9, button_Grid_y1, button_Grid_x1 - 4, button_Grid_y2, 3, 4 - 2 * kt_grid);
					kt_grid = abs(kt_grid - 1);
				}
				else if(kt_play == 2){
					settextstyle(0,0,1);
					if (choose_2D == 1){
						outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Hinh 2")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Hinh 2")/2+button_Grid_y1, "Hinh 2");
						choose_2D = 2;
					}
					else if (choose_2D == 2){
						outtextxy((button_Grid_x2-button_Grid_x1)/2-textwidth("Hinh 1")/2+button_Grid_x1,(button_Grid_y2-button_Grid_y1)/2-textheight("Hinh 1")/2+button_Grid_y1, "Hinh 1");
						choose_2D = 1;
					}
				}
			}
			else if ((h > button_Exit_x1) && (h < button_Exit_x2) && (t > button_Exit_y1) && (t < button_Exit_y2)){
				closegraph();
			}
			else if((h > button_Play_x1) && (h < button_Play_x2) && (t > button_Play_y1) && (t < button_Play_y2)){
				//ve_hcn(10, 10, 50, 50, 3, color);
				if (kt_play == 3){
					//cout << nho_3D;
					if ((nho_3D != 2) && (canh_3D <= 0)){
						thong_bao("Canh sai gia tri!!!", 2, 1);
					}
					else if ((R_3D <= 0) && (nho_3D == 2)){
						thong_bao("Ban kinh sai gia tri!!!", 2, 1);
					}
					else if ((cao_3D <= 0) && (nho_3D == 2)){
						thong_bao("Chieu cao sai gia tri!!!", 2, 1);
					}
					else if ((cao_3D <= 0) && (nho_3D == 1)){
						thong_bao("Chieu cao sai gia tri!!!", 2, 1);
					}
					else if (chieu_x(x_3D + canh_3D, z_3D - canh_3D) * size + Ox_3D > dai - 505){
						thong_bao("Tran man hinh|voi x va canh hien tai", 2, 2);
					}
					else {
						//cout << x_3D << ", " << y_3D << ", " << z_3D << ", " << canh_3D << ", " <<cao_3D << endl;
						Clear_Area(5-2, 5-2, dai - 500, rong - 20);
						grid(size, dai - 500, rong - 20, colorGra * abs(kt_grid - 1), 3);
						ve_3D(nho_3D);
						show_kqua_3D(nho_3D);
					}
				}
				else if((kt_play == 2) && (choose_2D == 1)){
					Clear_Area(dai - 450 + 5, 5 + 50 + 5 + 50 + 75, dai - 5, rong);
					Clear_Area(5 - 2, 5 - 2, dai - 500, rong - 20);
					ve_table_2D();
					int y0 = 5 + 50 + 5 + 50 + 75;
					int x0 = dai - 450 + 5;
					int kcach = 5;
					settextstyle(0,0,2);
					Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
					outtextxy(x0 + 100 + 100/2 - textwidth("80")/2, y0 + 40 + 50/2 - textheight("80")/2, "80");
					Clear_Area(x0 + 200 + 3, y0 + 40 + 5 + 3, x0 + 300, y0 + 80 + 5 - 3);
					outtextxy(x0 + 200 + 100/2 - textwidth("30")/2, y0 + 40 + 50/2 - textheight("30")/2, "30");
					
					y0 = y0 + 2 * 40 + kcach;
					y0 = y0 + 3 * 40 + kcach;
					
					Clear_Area(x0 + 100 + 3, y0 + 40 + 5 + 3, x0 + 200, y0 + 80 + 5 - 3);
					outtextxy(x0 + 100 + 100/2 - textwidth("125")/2, y0 + 40 + 50/2 - textheight("125")/2, "125");
					Clear_Area(x0 + 300 + 3, y0 + 40 + 5 + 3, x0 + 400 - 3, y0 + 80 + 5 - 3);
					outtextxy(x0 + 300 + 100/2 - textwidth("165")/2, y0 + 40 + 50/2 - textheight("165")/2, "165");  
					Hinh(); 
				}
				else if((kt_play == 2) && (choose_2D == 2)){
					Clear_Area(dai - 450 + 5, 5 + 50 + 5 + 50 + 75, dai - 5, rong);
					Clear_Area(5 - 2, 5 - 2, dai - 500, rong - 20);
					ve_table_2D();
					int y0 = 5 + 50 + 5 + 50 + 75;
					int x0 = dai - 450 + 5;
					int kcach = 5;
					settextstyle(0,0,2);
					Clear_Area(x0 + 3, y0 + 40 + 3 + 5, x0 + 100, y0 + 80 - 3 + 5);
					outtextxy(x0 + 100/2 - textwidth("395")/2, y0 + 40 + 50/2 - textheight("395")/2, "395");
					Hinh_Bow();
				}
			}
			else{
				if (kt_play == 3){
					show_3D(1, h, t);
				}
			}
		}
	}                                                                                    
}

void Window(){
	initwindow(dai, rong);
	for (int i = 0;i<5;i++){                                 
		line(dai - 500 + i, 0, dai - 500 + i, rong);
		line(dai - 450 - i, 0, dai - 450 - i, rong);
	}
	ve_button_led();
}

int main(){
	Window();
	
	return 0;
}
