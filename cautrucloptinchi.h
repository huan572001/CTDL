#pragma once
#include<iostream>
using namespace std;
#include"SVDK.h"
#include<string.h>
#include<ctime>
#include "define.h"
struct LopTinChi{
	int maLTC=0;
	char maMH[ma_MH]="";
	char nienKhoa[NienKhoa]="";
	int hocKy=0;
	int nhom=0;
	int minsv=0;
	int maxsv=0;
	bool trangthai=true;
	DSSVDK dsSVDK;
};
struct DSloptinchi{
	LopTinChi *DSltc=new LopTinChi[MAXLTC];
	int soluong;
	int Time[MAXLTC];
};
void NhapDSLopTinChi(DSloptinchi &ds,LopTinChi &ltc)
{
		ds.DSltc[ds.soluong]=ltc;
		time_t now= time('\0');//thoi gian luc moi them
		ds.Time[ds.soluong]=now;	
		ds.soluong++;
}
void xuat1loptinchi(int x,int &y,LopTinChi ltc,int mangdodai_ltc[])
{
	char tam[6];
	chuyen_so_thanh_chuoi(ltc.maLTC,tam);
	outtextxy(x=x+10,y+5,tam);
	outtextxy(x=x+mangdodai_ltc[2],y+5,ltc.maMH);
	outtextxy(x=x+mangdodai_ltc[3],y+5,ltc.nienKhoa);
	chuyen_so_thanh_chuoi(ltc.hocKy,tam);
	outtextxy(x=x+mangdodai_ltc[4],y+5,tam);
	chuyen_so_thanh_chuoi(ltc.nhom,tam);
	outtextxy(x=x+mangdodai_ltc[5],y+5,tam);	
	chuyen_so_thanh_chuoi(soluongSVDK(ltc.dsSVDK.first),tam);
	outtextxy(x=x+mangdodai_ltc[6],y+5,tam);
}
void Xuatds(int x,int y,DSloptinchi ds,int mangdodai_ltc[])
{
	for(int i=0;i<ds.soluong;i++)
	{
		y=y+30;
		xuat1loptinchi(x,y,ds.DSltc[i],mangdodai_ltc);
	}
}
void Xoa(DSloptinchi &ds,int vt)
{
	Xoa_ALL_SVDK(ds.DSltc[vt].dsSVDK.first);
	for(int i=vt;i<ds.soluong;i++)
	{
		ds.DSltc[i]=ds.DSltc[i+1];
	}
	ds.soluong--;
}
void XoaLTC(DSloptinchi &ds,char mMH[])
{
	for(int i=0;i<ds.soluong;i++)
	{
		if(strcmp(mMH,ds.DSltc[i].maMH)==0)
		{
			Xoa(ds,i);
			break;
		}
	}
}
void XoaALLltc(DSloptinchi &ds)
{
	while(ds.soluong>0)
	{
		Xoa_ALL_SVDK(ds.DSltc[ds.soluong].dsSVDK.first);
		ds.soluong--;
	}
	delete[] ds.DSltc;
}
void chinh_Sua(DSloptinchi &ds,LopTinChi &ltc)
{
	for(int i=0;i<ds.soluong;i++)
	{
		if(ltc.maLTC==ds.DSltc[i].maLTC)
		{
			ds.DSltc[i]=ltc;
		}
	}
}
bool KT_nhap_LTC(LopTinChi ltc)
{
	if(ltc.hocKy>0&&ltc.maxsv>0&&ltc.minsv&&ltc.maxsv>ltc.minsv&&ltc.nhom>0&&strlen(ltc.maMH)>0)
	{
		return true;
	}
	return false;
}
bool KT_LTC_chung(DSloptinchi &dsltc,int mltc)
{
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(dsltc.DSltc[i].maLTC==mltc)
		return false;
	}
	return true;
}
void Xuat_mot_ltc_dk(int x,int y,LopTinChi ltc,Node *root,int mangdodai[],char maSV[])
{
		char tam[5];
		outtextxy(x=x+10,y,ltc.maMH);
		Tim_MMH(x=x+mangdodai[2],y,root,ltc.maMH);
		chuyen_so_thanh_chuoi(ltc.nhom,tam);
		outtextxy(x=x+mangdodai[3],y,tam);
		if(soluongSVDK(ltc.dsSVDK.first)==0)
		outtextxy(x=x+mangdodai[4],y,"0");
		else
		{
			chuyen_so_thanh_chuoi(soluongSVDK(ltc.dsSVDK.first),tam);
			outtextxy(x=x+mangdodai[4],y,tam);
		}
		if(ltc.maxsv-soluongSVDK(ltc.dsSVDK.first)==0)
		{
			outtextxy(x=x+mangdodai[5],y,"0");
		}
		else
		{
			chuyen_so_thanh_chuoi(ltc.maxsv-soluongSVDK(ltc.dsSVDK.first),tam);
			outtextxy(x=x+mangdodai[5],y,tam);	
		}
		if(KT_Svdk_chua(ltc.dsSVDK.first,maSV)==true)
		outtextxy(x=x+mangdodai[6]+20,y,"v");
		else
		outtextxy(x=x+mangdodai[6]+20,y,"  ");
}
void Xuat_DS_LTC_DK(int x,int y,DSloptinchi dsltc,Node *root,char nienkhoa[], char hocky[],char maSV[],int trangso)
{
	int mangdodai_svdk[]={0,80,173,273,173,173,173,100};
	int a=1;
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(strcmp(nienkhoa,dsltc.DSltc[i].nienKhoa)==0&&chuyen_chuoi_thanh_so(hocky)==dsltc.DSltc[i].hocKy&&dsltc.DSltc[i].trangthai==true)
		{
			if(a>(trangso-1)*14&&a<=trangso*14)
			{
				Xuat_mot_ltc_dk(x,y,dsltc.DSltc[i],root,mangdodai_svdk,maSV);
				y=y+30;
			}
			x++;
		}
	}
}
int tim_ltc(DSloptinchi &dsltc,int vt,char nienkhoa[],char hocky[])
{
	int i=0;
	for(;i<dsltc.soluong;i++)
	{
		if(strcmp(nienkhoa,dsltc.DSltc[i].nienKhoa)==0&&chuyen_chuoi_thanh_so(hocky)==dsltc.DSltc[i].hocKy)
		{
			if(vt==1)
			{
				return i;
			}
			vt--;
		}
	}
	return i;
}
bool KT_SV_DK_LTC(DSloptinchi dsltc,char maSV[])
{
	for(int i=0;i<dsltc.soluong;i++)
	{
		for(NodeSVDK *k=dsltc.DSltc[i].dsSVDK.first;k!=NULL;k=k->next)
		{
			if(strcmp(k->svdk.maSV,maSV)==0)
			return true;
		}
	}
	return false;
}
bool KT_MH_Da_Duoc_Tao_LTC(DSloptinchi dsltc,char MaMH[])
{
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(strcmp(dsltc.DSltc[i].maMH,MaMH)==0)
		return true;
	}
	return false;
}
void WriteFileLTC(char *FileName,LopTinChi &ltc,int time)  
{
		FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&ltc,sizeof(ltc),1,f);//viet lop tin chi vao trong file
	fwrite(&time,sizeof(time),1,f);//viet time vao file
	int n=soluongSVDK(ltc.dsSVDK.first);//so luong sinh vien dang ky
	fwrite(&n,sizeof(n),1,f);//viet so luong sinh vien dk vao trong file
	for(NodeSVDK *k=ltc.dsSVDK.first;k!=NULL;k=k->next)//duyet ds sinh vien de viet vao file
	{
		fwrite(&k->svdk,sizeof(k->svdk),1,f);//viet tung thang sv vao file
	}
	fclose(f); 
 } 
void doc_tu_file_vao_LTC(char *FileName,DSloptinchi &dsltc)
{
		FILE *f;   
	LopTinChi ltc;   
	int n=0;//n la so luong svdk
	SVDK svdk;
	f=fopen(FileName,"rb");
	while (fread(&ltc,sizeof(ltc),1,f))  
	{  
	//doc tu file de lay lop tin chi
		dsltc.DSltc[dsltc.soluong]=ltc;//gan lop tin chi vao dsltc[i]
		dsltc.DSltc[dsltc.soluong].dsSVDK.first=NULL;
		fread(&dsltc.Time[dsltc.soluong],sizeof(dsltc.Time[dsltc.soluong]),1,f);
		fread(&n,sizeof(n),1,f);//doc tu file de lay so luong svdk
		for(int i=0;i<n;i++)
		{
			fread(&svdk,sizeof(svdk),1,f);//doc svdk trong file
			ThemDauSVDK(dsltc.DSltc[dsltc.soluong].dsSVDK.first,svdk);
		}
		if(!feof(f))//neu da o cuoi file thi ko tang so luong ltc 
		dsltc.soluong++;//tang so luong lop tin chi len 1
	}  	  
	fclose(f); 
	
}
void vietLTCvaofile(DSloptinchi &dsltc)
{
	for(int i=0;i<dsltc.soluong;i++)//duyet danh sach lop tin chi de viet vao file
	{
		WriteFileLTC("Loptinchi.dat",dsltc.DSltc[i],dsltc.Time[i]);
	}
}
void KT_Huy_Lop(DSloptinchi &dsltc)
{
	time_t now= time('\0');
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(now-dsltc.Time[i]>60*60*48&&soluongSVDK(dsltc.DSltc[i].dsSVDK.first)<dsltc.DSltc[i].minsv)
		{
			dsltc.DSltc[i].trangthai=false;
		}
	}
}
void Tu_Dong_Huy_LTC(DSloptinchi &dsltc)
{
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(dsltc.DSltc[i].trangthai==false&&soluongSVDK(dsltc.DSltc[i].dsSVDK.first)==0)
		{
			Xoa(dsltc,i);
			i--;
		}
	}
//	remove("Loptinchi.dat");
//	vietLTCvaofile(dsltc);
}
