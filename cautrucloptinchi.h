#pragma once
#include<iostream>
using namespace std;
#include"SVDK.h"
#include<string.h>
#define MAXLTC 10000
struct LopTinChi{
	int maLTC;
	char maMH[10]="";
	char nienKhoa[10]="";
	int hocKy;
	int nhom;
	int minsv;
	int maxsv;
	bool trangthai;
	DSSVDK dsSVDK;
};
struct DSloptinchi{
	LopTinChi DSltc[MAXLTC];
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
//	outtextxy(x=x+mangdodai_ltc[6],y+5,tam);
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
//void Nhap_thong_tinDK(DSloptinchi &dsltc,NodeSinhVien *first)
//{
//	SVDK SV;
//	bool a=true;
//	while(a==true)
//	{
//		//nhap ma sinh vien can tim
//		cout<<"\n\tNhap ma sinh vien: ";
//		cin>>SV.maSV;
//		//tim kiem sinh vien trong ds sinh vien
//		for (NodeSinhVien *k = first; k != NULL; k = k->next)
//		{
//			if(strcmp(SV.maSV,k->sv.mSV)==0)
//			{
//				cout<<"\n\tMa lop: "<<k->sv.malop;
//				cout<<"\n\tMa SV: "<<k->sv.mSV;
//				cout<<"\n\tHo ten SV: "<<k->sv.ho<<" "<<k->sv.ten;
//				cout<<"\n\tSDT SV: "<<k->sv.sdt;
//				a=false;
//				break;
//			}
//			a=true;
//		}
//		if(a==true)
//		{
//			cout<<"\n\tMa sinh vien ko ton tai vui long nhap lai: ";
//		}
//	}
//	
//	
//	//nhap vao nien khoa hoc ki de dk lop
//	char nienkhoatam[10];
//	cout<<"\n\tnhap nien khoa: ";
//	cin>>nienkhoatam;
//	cout<<"\n\tnhap hoc ky: ";
//	int hk;
//	cin>>hk;
//	// tim nhung lop thich hop de DK lop
//	for(int i=0;i<dsltc.soluong;i++)
//	{
//		if(strcmp(nienkhoatam,dsltc.DSltc[i].nienKhoa)==0&&hk==dsltc.DSltc[i].hocKy)
//		{
////			timkiem(root,dsltc.DSltc[i].maMH);
//			cout<<"\n\tMa mon hoc: "<<dsltc.DSltc[i].maMH;
//			cout<<"\n\tNhom: "<<dsltc.DSltc[i].nhom;
//			cout<<"\n\tSo sinh vien da dk: "<<soluongSVDK(dsltc.DSltc[i].dsSVDK.first);
//			cout<<"\n\tSo slot con trong: "<<dsltc.DSltc[i].maxsv-soluongSVDK(dsltc.DSltc[i].dsSVDK.first);////DANG BI SAI
////			XuatDanhSachSVDK(dsltc.DSltc[i].dsSVDK.first);
//		}
//	}
//	
//	while(true)
//	{
//		char maMonHoc[10];
//		cout<<"\n\t\tDANG KY MON HOC";
//		cout<<"\n\tNhap 1 de thoat";
//		cout<<"\n\tNhap ma mon hoc ban muon dk: ";
//		cin>>maMonHoc;
//		char tam[10]={"1"};
//		if(strcmp(maMonHoc,tam)==0)
//		{
//			break;
//		}
//		for(int i=0;i<dsltc.soluong;i++)
//		{
//			if(strcmp(nienkhoatam,dsltc.DSltc[i].nienKhoa)==0&&hk==dsltc.DSltc[i].hocKy&&strcmp(maMonHoc,dsltc.DSltc[i].maMH)==0)
//			{
////				NodeSVDK *p= TaoMotSVDK(SV);
//				ThemDauSVDK(dsltc.DSltc[i].dsSVDK.first,SV);
//			}
//		}
//	}
//}

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
