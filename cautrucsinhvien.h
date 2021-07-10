#pragma once
#include<iostream>
#include<string.h>
#include "cautrucmonhoc.h"


struct SinhVien{
	char mSV[MaSV]="";
	char ho[Ho]="";
	char ten[Ten]="";
	bool phai;//true la nam f la nu
	char sdt[Sdt]="";
	char malop[Malop]="";
};
struct NodeSinhVien{
	SinhVien sv;
	NodeSinhVien *next=NULL;
};
NodeSinhVien *TaoMotSV(SinhVien SV){
	NodeSinhVien *tamp= new NodeSinhVien();
	tamp->sv=SV;
	tamp->next=NULL;
	return tamp;
}
void Xuat1SV(int x,int y,SinhVien sv,int mangdodai[])
{
	char hoten[Ho+Ten+1];
	outtextxy(x=x+10,y,sv.malop);
	outtextxy(x=x+mangdodai[2],y,sv.mSV);
	strcpy(hoten,sv.ho);
	strcat(hoten," ");
	strcat(hoten,sv.ten);
	outtextxy(x=x+mangdodai[3],y,hoten);
	outtextxy(x=x+mangdodai[4],y,sv.sdt);
	if(sv.phai==true)
		outtextxy(x=x+mangdodai[5],y,"nam");
	else
		outtextxy(x=x+mangdodai[5],y,"nu");
}
void XuatDanhSach(int x,int y,NodeSinhVien *first,int mangdodai[],int trangso,char maLop[])
{
	int i=1;//bien dem so sv
	for (NodeSinhVien *k = first; k != NULL; k = k->next)
	{
		if(strcmp(maLop,k->sv.malop)==0)
		{
			if(i>14*(trangso-1)&&i<=14*trangso)//neu
			{
				Xuat1SV(x,y,k->sv,mangdodai);
				y=y+30;
			}
			i++;
//			if(strcmp(maLop,k->next->sv.malop)!=0)
//			return;
		}			
	}
}
void ThemCuoi(NodeSinhVien*& first, NodeSinhVien *p)
{
	// n?u danh sách r?ng
	if (first == NULL)
	{
		first = p; // node p cung chính là node d?u danh sách
	}
	else
	{
		for (NodeSinhVien *k = first; k != NULL; k = k->next)
		{
			if (k->next == NULL)
			{
				k->next = p; // thêm node p vào cu?i danh sách <=> l?y pNext c?a node n?m ? cu?i danh sách gi? d?a ch? c?a node c?n thêm vào cu?i là node p
				break;// d?ng l?i
			}
		}
	}
}
void ThemDau(NodeSinhVien*& first, NodeSinhVien *p)
{
	// danh sách dang r?ng
	if (first == NULL)
	{
		first = p; // node p cung chính là node d?u danh sách
	}
	else
	{
		// Bu?c 1: Cho node p tr? t?i node d?u danh sách thông qua pHead
		p->next = first; 

		// Bu?c 2: C?p nh?t l?i pHead chính là node p v?a thêm vào
		first = p;
	}
}

void ThemSVvaolop(NodeSinhVien *&first,SinhVien &SV)
{
	NodeSinhVien *truoc=NULL;
	NodeSinhVien *p=TaoMotSV(SV);
	if(first==NULL)
	{
		first=p;
	}
	else		
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		if(stricmp(k->sv.malop,SV.malop)==0)//tim kiem lop de them
		{
			for (; k != NULL; k = k->next)
			{					
				if (stricmp(p->sv.ten,k->sv.ten)<0||stricmp(k->sv.malop,SV.malop)!=0)
				//ten sv p <ten sv k thi them sao ds o vi tri truoc k||va malop cua sv k bang voi key
				{
					if(truoc==NULL)
					{
						ThemDau(first,p);	
						break;
					}
					else
					{
						p->next=k;
						truoc->next=p;
						break;
					}		
				}
				else if(stricmp(p->sv.ten,k->sv.ten)==0)
				{
					 if(stricmp(p->sv.ho,k->sv.ho)<0&&truoc!=NULL)
					{
						p->next=k;
						truoc->next=p;
						break;
					}	
					else if(stricmp(p->sv.ho,k->sv.ho)<0&&truoc==NULL)
					{
						ThemDau(first,p);	
						break;
					}			
				}
				if(k->next==NULL)
				{
					k->next = p; //them vao cuoi ds
					break;
				}
				truoc=k;
			}	
			break;
		}
		else if(k->next==NULL)
		{
			k->next=p;
			break;
		}
		truoc=k;
	}
}

void XoaSv(NodeSinhVien *&first,char a[])
{	
//NodeSinhVien *p;
	if (strcmp(first->sv.mSV,a)==0 ) {
		NodeSinhVien *p=first;
		first = p->next ;
		delete p ;
	}
	else
	for (NodeSinhVien *k = first; k != NULL; k = k->next)
	{
		if (strcmp(k->next->sv.mSV,a)==0)
		{
			NodeSinhVien *p=k->next;
			k->next=p->next;
			delete p;
			break;
		}
	}
}
void XoaALL_SV(NodeSinhVien *&first)
{
	NodeSinhVien *p;
	while(first!=NULL)
	{
		p=first;
		first=first->next;
		delete p;
	}
}
void chinh_sua_Sv_coMS(NodeSinhVien *&first,SinhVien SV,char key[])/////chua sua dc
{
	XoaSv(first,key);
	NodeSinhVien *p=TaoMotSV(SV);
	ThemSVvaolop(first,SV);
}


void XuatDSlop(int x,int y,NodeSinhVien *first,int mangdodai_lh[],int trangso)
{
	int soluong=0;
	int i=1;
	char sl[4];
	NodeSinhVien *tam=first;//giu ma lop dau ds
	if(i>14*(trangso-1)&&i<=14*trangso)
	outtextxy(x=x+10,y+5,first->sv.malop);//in ra lop dau tien
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)//duyet ds de dam sl sinh vien va in ra cac lop
	{
		//dem so luong SV cua lop
		if(strcmp(k->sv.malop,tam->sv.malop)!=0)//gap mot lop khac lop da in
		{
			if(i>14*(trangso-1)&&i<=14*trangso)
			{
				chuyen_so_thanh_chuoi(soluong,sl);
				outtextxy(x+mangdodai_lh[2],y+5,sl);
				y=y+30;
				outtextxy(x,y+5,k->sv.malop);
				soluong=0;//cap nhat lai so luong SV =0 de bat dau dem SV lop tiep theo
				tam=k;//giu lai ma lop vua in
			}
			i++;			
		}
		if(k->next==NULL)//cuoi ds in so luong sinh vien cua lop cuoi cung
		{
			if(i>14*(trangso-1)&&i<=14*trangso)
			{
				soluong++;
				chuyen_so_thanh_chuoi(soluong,sl);
				outtextxy(x+mangdodai_lh[2],y+5,sl);
			}			
		}
		soluong++;
	}
}
int SL_SV_Lop(NodeSinhVien *first,char malop[])
{
	int dem=0;
		for(NodeSinhVien *k=first;k!=NULL;k=k->next)
		{
			if(strcmp(k->sv.malop,malop)==0)
			dem++;
		}
	return dem;
}
void timLopSV(NodeSinhVien *first,int socot,char malop[])
{
	NodeSinhVien *tam=first;
	if(socot==1)
	{
		strcpy(malop,first->sv.malop);
		return;
	}
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		if(strcmp(k->sv.malop,tam->sv.malop)!=0)
		{
			socot--;
		}
		if(socot==1)
		{
			strcpy(malop,k->sv.malop);
		return;
		}
	}
}
void timSV(NodeSinhVien *first,int socot,SinhVien &SV,char maLop[])
{
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		if(strcmp(k->sv.malop,maLop)==0)
		{
			if(socot==1)
			{
				SV=k->sv;
				break;				
			}	
			socot--;
		}

	}
}
bool Kiem_tra_nhapSV(SinhVien SV)
{
	if(strlen(SV.mSV)==10&&strlen(SV.sdt)>=9&&strlen(SV.sdt)<=11&&strlen(SV.ho)>=2&&strlen(SV.ten)>0)
	{
		return true;
	}
	return false;
}
bool Kiem_tra_MaSV(NodeSinhVien *first,char masv[])
{
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		if(strcmp(k->sv.mSV,masv)==0)
		{
			return false;
		}
	}
	return true;
}
int Dem_Lop(NodeSinhVien *first,int trangso)
{
    int soluong=0;
	int i=1;
	char sl[4];
	NodeSinhVien *tam=first;//giu ma lop dau ds
	if(i>14*(trangso-1)&&i<=14*trangso)
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)//duyet ds de dam sl sinh vien va in ra cac lop
	{
		//dem so luong SV cua lop
		if(strcmp(k->sv.malop,tam->sv.malop)!=0)//gap mot lop khac lop da in
		{
			if(i>14*(trangso-1)&&i<=14*trangso)
			{
				soluong=0;//cap nhat lai so luong SV =0 de bat dau dem SV lop tiep theo
				tam=k;//giu lai ma lop vua in
			}
			i++;			
		}
		if(k->next==NULL)//cuoi ds in so luong sinh vien cua lop cuoi cung
		{
			if(i>14*(trangso-1)&&i<=14*trangso)
			{
				soluong++;
			}			
		}
		soluong++;
	}
	return soluong;
}
void WriteFileSV(char *FileName,SinhVien SV)  
{  
	FILE *f;      	
	f=fopen(FileName,"ab");  
	fwrite(&SV,sizeof(SV),1,f); 
	fclose(f);   
}  
void doc_tu_file_vao_dslkd(char *FileName,NodeSinhVien *&first)
{
		FILE *f;   
		SinhVien SV;   
	f=fopen(FileName,"rb");
//	fread(&SV,sizeof(SV),1,f); 
	while (fread(&SV,sizeof(SV),1,f))  
	{  
		NodeSinhVien* p = TaoMotSV(SV);
		ThemSVvaolop(first,SV);		
	}  	  
	fclose(f); 
}
void vietSVvaofile(NodeSinhVien *&first)
{
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		WriteFileSV("Sinhvien.dat",k->sv);
	}
}
