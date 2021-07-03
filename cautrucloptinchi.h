#pragma once
#include<iostream>
using namespace std;
#include"SVDK.h"
#include<string.h>
#define MAXLTC 10000
struct LopTinChi{
	int maLTC=0;
	char maMH[10]="";
	char nienKhoa[10]="";
	int hocKy=0;
	int nhom=0;
	int minsv=0;
	int maxsv=0;
	bool trangthai;
	DSSVDK dsSVDK;
};
struct DSloptinchi{
	LopTinChi *DSltc=new LopTinChi[MAXLTC];
	int soluong;
};
void NhapDSLopTinChi(DSloptinchi &ds,LopTinChi &ltc)
{
		ds.DSltc[ds.soluong]=ltc;
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

//void Nhap_diemLTC(DSloptinchi &dsltc,NodeSinhVien *&firstSV)
//{
//	char MMH[10];
//	char NK[10];
//	int HK;
//	int N;
//	int chay=0;
//	cout<<"\n\tNhap vao nien khoa: ";
//	cin>>NK;
//	cout<<"\n\tNhap vao hoc ky: ";
//	cin>>HK;
//	cout<<"\n\tNhom: ";
//	cin>>N;
//	cout<<"\n\tnhap ma mon hoc: ";
//	cin>>MMH;
//	for(int i=0;i<dsltc.soluong;i++)
//	{
//		if(strcmp(NK,dsltc.DSltc[i].nienKhoa)==0&&HK==dsltc.DSltc[i].hocKy&&N==dsltc.DSltc[i].nhom,strcmp(MMH,dsltc.DSltc[i].maMH)==0)
//		{
//			while(true)
//			{
//				system("cls");
//				int j=0;
//				cout<<"\n\tchon 0 de thoat: ";
//				for(NodeSVDK *k=dsltc.DSltc[i].dsSVDK.first;k!=NULL;k=k->next)
//				{
//					cout<<"\n--------------------STT"<<j+1<<"-----------------------";
//					for (NodeSinhVien *h = firstSV; h != NULL; h = h->next)
//					{
//						if(strcmp(k->svdk.maSV,h->sv.mSV)==0)
//						{
//							cout<<"\n\tMa SV: "<<h->sv.mSV;
//							cout<<"\n\tHo ten: "<<h->sv.ho<<" "<<h->sv.ten;
//							cout<<"\n\tDiem: "<<k->svdk.diem;
//							break;
//						}
//					}
//					j++;
//				}
//				
//				int l=0;
//				do
//				{
//					cout<<"\n\tChon STT sinh vien can them diem: ";
//					cin>>chay;
//				}while(chay>j);
//				for(NodeSVDK *k=dsltc.DSltc[i].dsSVDK.first;l!=chay;k=k->next)
//				{
//					l++;
//					if(l==chay)
//					{
//						cout<<"\n\tNhap diem: ";
//						cin>>k->svdk.diem;
//					}
//				}
//				if(chay==0)
//				{
//					break;
//				}
//			}
//			break;
//		}
//	}
//}
bool KT_nhap_LTC(LopTinChi ltc)
{
	if(ltc.hocKy>0&&ltc.maxsv>0&&ltc.minsv&&ltc.maxsv>ltc.minsv&&ltc.nhom>0&&strlen(ltc.maMH)>2)
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
void Xuat_mot_ltc_dk(int x,int y,LopTinChi ltc,int mangdodai[])
{
		char tam[5];
		chuyen_so_thanh_chuoi(ltc.maLTC,tam);
		outtextxy(x=x+10,y,tam);
		outtextxy(x=x+mangdodai[2],y,ltc.maMH);
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
}
void Xuat_DS_LTC_DK(int x,int y,DSloptinchi dsltc,char nienkhoa[], char hocky[])
{
	int mangdodai_svdk[]={0,80,173,273,173,173,173,100};
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(strcmp(nienkhoa,dsltc.DSltc[i].nienKhoa)==0&&chuyen_chuoi_thanh_so(hocky)==dsltc.DSltc[i].hocKy)
		{
			Xuat_mot_ltc_dk(x,y,dsltc.DSltc[i],mangdodai_svdk);
			y=y+30;
		}
	}
}
void tim_ltc_de_them_svdk(DSloptinchi &dsltc,char mSV[],int vt,char nienkhoa[],char hocky[])
{
	SVDK SV;
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(strcmp(nienkhoa,dsltc.DSltc[i].nienKhoa)==0&&chuyen_chuoi_thanh_so(hocky)==dsltc.DSltc[i].hocKy)
		{
			if(vt==1)
			{
				strcpy(SV.maSV,mSV);
				ThemDauSVDK(dsltc.DSltc[i].dsSVDK.first,SV);
				break;
			}
			vt--;
		}
	}
}
void tim_ltc_de_Xoa_svdk(DSloptinchi &dsltc,char mSV[],int vt,char nienkhoa[],char hocky[])
{
	for(int i=0;i<dsltc.soluong;i++)
	{
		if(strcmp(nienkhoa,dsltc.DSltc[i].nienKhoa)==0&&chuyen_chuoi_thanh_so(hocky)==dsltc.DSltc[i].hocKy)
		{
			cout<<vt<"  ";
			if(vt==1)
			{
				XoaSvDK(dsltc.DSltc[i].dsSVDK.first,mSV);
				break;
			}
			vt--;
		}
	}
}
void WriteFileLTC(char *FileName,LopTinChi &ltc)  
{
		FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&ltc,sizeof(ltc),1,f);//viet lop tin chi vao trong file
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
		WriteFileLTC("Loptinchi.dat",dsltc.DSltc[i]);
	}
}
