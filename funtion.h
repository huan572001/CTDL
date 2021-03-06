#pragma once
#include <iostream>
using namespace std;
#include "define.h"
#include<string.h> 
//#include "cautrucmonhoc.h"
void chuyen_so_thanh_chuoi(int n,char res[]) {
	char s[4];
	int k = 0;
	while(n){
		s[k++] = n % 10 + 48;
		n /= 10;
	}
	for(int i = k - 1; i >= 0; i--) {
		res[k - 1 - i] = s[i];
	}
	res[k] = '\0';
}
int chuyen_chuoi_thanh_so(char res[]) {
	int n=0;
	for(int i=0;i<strlen(res);i++)
	{
		n=n*10+(res[i]-48);
	}
	return n;
}
int MapID[CUASO_NGANG][CUASO_DOC];
void setmapid()
{
	for (int i=0 ; i<CUASO_NGANG ; i++)
	{
		for (int j=0; j<CUASO_DOC ; j++)
		{
			MapID[i][j]=0;
		}
	}
}
void setidvung(int x1 ,int y1 ,int x2 ,int y2 ,int id)
{
	for (int i=x1 ; i<x2 ; i++)
	{
		for (int j=y1 ; j<y2 ; j++)
		{
			MapID[i][j]=id;
		}
	}
}
///////////////////////////////////////////////////////////////////////// PHAN VE ////////////////////////////////
void taobutton(int x1,int y1,char text[],int vtx, int vty,int mau,int mau_text,int cl_x,int cl_y,int id)// muc luc
{
	setfillstyle(1,mau);
	bar(x1,y1,x1+vtx,y1+vty);
	setbkcolor(mau);
	settextstyle(9,0,1);
	setcolor(mau_text);
	outtextxy(x1+cl_x,y1+cl_y,text);
	setidvung(x1,y1,x1+vtx,y1+vty,id);
}

void taobutton_k(int x1 , int y1 , char text[] , int x2 , int y2,int mau,int mau_text ,int id)//huong dan // thong bao // .... khong bar trong khung 
{
	setfillstyle(1,mau);
	bar(x1,y1,x2+x1,y2+y1);
	settextstyle(9,0,1);
	setbkcolor(mau);
	setcolor(mau_text);
	outtextxy(x1+10,y1+10,text);
	setidvung(x1,y1,x1+x2,y1+y2,id);
}//lay dia chi id

void taobutton_t(int x1 , int y1 , char text[] , int vtx , int vty,int mau,int mau_text,int can_lex,int can_ley)//huong dan // thong bao // .... khong bar vien
{
	setfillstyle(1,mau);
	bar(x1,y1,x1+vtx,y1+vty);
	setbkcolor(mau);
	settextstyle(9,0,1);
	setcolor(mau_text);
	outtextxy(x1+can_lex,y1+can_ley,text);
}//khong lay dc id


void tao_o(int x1,int y1,int x2,int y2)
{
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	rectangle(x1,y1,x2,y2);
}
void taodong(int x1,int y1,int chieu_cao,int mangdodai[],int slcot)
{
	int x2,y2;
	y2=y1+chieu_cao;
	for(int i=1;i<=slcot;i++)
	{
		x2=x1+mangdodai[i];
		tao_o(x1,y1,x2,y2);
		x1=x2;
	}
}

void tao_tieu_de_bang(int x, int y, char td[][50], int slcot, int mang_do_dai[],int clx,int cly) 
{
	for(int i = 1; i <= slcot; i++) {
		settextstyle(9,0,1);
		setbkcolor(MAU_TRANG);
		outtextxy(x + clx,y +cly,td[i]);
		x += mang_do_dai[i];
	}
}



void tao_sott(int x, int y, int chieu_cao,int sldong,int clx,int cly,int trangso) {
	char a[4];
	y=y+30;
	for(int i = 1+14*(trangso-1);i < sldong+14*(trangso-1); i++) 
	{
		chuyen_so_thanh_chuoi(i,a);
		settextstyle(9,0,1);
		setbkcolor(MAU_TRANG);
		outtextxy(x+20,y+cly,a);
		y += chieu_cao;
	}
}

void taobang(int x1,int y1,int chieu_cao,int mangdodai[],int slcot,int sldong,char td[][50],int clx,int cly,int id,int trangso)
{
	for (int i=0;i<sldong;i++)
	{
		taodong(x1,y1+chieu_cao*i,chieu_cao,mangdodai,slcot);
		setidvung(x1,y1+chieu_cao*i,x1+1200,y1+chieu_cao*(i+1),id+i);
	}
	tao_tieu_de_bang(x1,y1,td,slcot,mangdodai,clx,cly);
	tao_sott(x1,y1,chieu_cao,sldong,clx,cly,trangso);
}
void taotextinput(int x, int y ,int x1 ,int y1, char text[], int id)
{
	setcolor(MAU_DEN);
	setfillstyle(1,MAU_TRANG);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	outtextxy(x1, y1, text);
	setidvung(x,y,x1,y1,id);
}
///////////////////////////////////////////////////////////////////// PHAN TEXT ///////////////////////////////////////////////////////////

char *Chuan_Hoa(char *a)// chuan hoa nhap vao, chuyen thanh dang Anh Em Oi  
{


    strlen(a);
	int start=0;
	char *res='\0';
	while(start< strlen(a) && a[start]==' ') start++;
	if(start== strlen(a)) return res;
	if(a[start]>='a'&&a[start<='z']) a[start]+='A'-'a';
	res+=a[start];
	for(int i=start+1;i< strlen(a);i++)
	{
		if(a[i-1]!=' '&&a[i]!=' ')
		{
			if(a[i]>='A'&&a[i]<='Z') a[i]+='a'-'A';
			res+=a[i];
		}
		else if(a[i-1]==' '&&a[i]!=' ') {
			if(a[i]>='a'&&a[i]<='z') a[i]+='A'-'a';
			res+=a[i];
		}
	}
	int i,j;
	int n=strlen(a);
		for(i=0;i<n;i++)
		{
		if((a[i]==' ')&&(a[i+1]==' '))
		{
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--; 
		}
	}
		
	return res;
}
////////////////////////////////BAT KI TU TU BAN PHIM//////////////////////////////////////////
void Nhap(int x, int y,int &luu_id, char s[]) {
	int x1=x;
	int y1=y;
    int l=strlen(s) ;
    s[l+1]='\0';
    s[l]='|'; 
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
    while(1){
		outtextxy(x,y,s);
		int id=luu_id;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(id!=luu_id)
		{
			luu_id=id;
			s[l]='\0';
			l--;
			return;
		}
		else
		{
			x=x1;
			y=y1;
		}
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||'0'<=c&&c<='9'||c==' ')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
				if(l>0)
				{
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 
			 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			Chuan_Hoa(s); 			 
			outtextxy(x,y,s);
		 
		}	
	 } 
	
} 
void Nhapso(int x, int y ,int &luu_id, char s[],int chieudai)
{
		int x1=x;
	int y1=y;
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int l=strlen(s) ;
	s[l+1]='\0';
    s[l]='|'; 
	int id=luu_id;
    while(1){
       	
		outtextxy(x,y,s);
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(id!=luu_id)
		{
			luu_id=id;
			s[l]='\0';
//			l--;
			return;
		}
		else
		{
			x=x1;
			y=y1;
		}
     	if(kbhit()){
	     	char c= getch();
	     	if('0'<=c&&c<='9')
	     	{
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
				if(l>0)
				{
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				return; 
			}
			if(strlen(s)>=chieudai)
			{
				delay(50);
				s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
			} 	 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			Chuan_Hoa(s); 			 
			outtextxy(x,y,s);		 
		}	
	 } 	
}
void NhapInHoa(int x, int y,int &luu_id, char s[]) {
		int x1=x;
	int y1=y;
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int l=strlen(s) ;
	 s[l+1]='\0';
    s[l]='|'; 
     while(1){
       	
		outtextxy(x,y,s);
		int id=luu_id;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(id!=luu_id)
		{
			luu_id=id;
			s[l]='\0';
			l--;
			return;
		}
		else
		{
			x=x1;
			y=y1;
		}
     	if(kbhit()){
	     	char c= getch();
	     	if('a'<=c&&c<='z'||'A'<=c&&c<='Z'||'0'<=c&&c<='9')
	     	{
	     		if('a'<=c&&c<='z')
	     		{
	     			c=c-32;
				 }
		     	s[l]=c;
				 l++;
				 s[l+1]='\0';
				 outtextxy(x,y,s);
			}
			else if(c==8){
				if(l>0)
				{
					s[l-1]='|';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
			} 
			else if(c==13) {
				s[l]='\0';// xoa dau cach o cuoi chuoi  
				break; 
			} 

			 	
		 }
		 else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);			 
			outtextxy(x,y,s);
		 
		}	
	 } 
	
} 
int tong(int a[],int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		tong=tong+a[i];
	}
	return tong;
}
void taobarde(int x ,int y ,int x1 ,int y1)//de bang
{
	setfillstyle(1,MAU_TRANG);
	bar(x,y,x1,y1);
} 
