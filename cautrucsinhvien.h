#pragma once
#include<iostream>
#include<string.h>
#include "cautrucmonhoc.h"


struct SinhVien{
	char mSV[15]="";
	char ho[50]="";
	char ten[10]="";
	bool phai;//true la nam f la nu
	char sdt[11]="";
	char malop[15]="";
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
	outtextxy(x=x+10,y,sv.malop);
	outtextxy(x=x+mangdodai[2],y,sv.mSV);
	outtextxy(x=x+mangdodai[3],y,sv.ho);
	outtextxy(x+strlen(sv.ho)*20,y,sv.ten);
	outtextxy(x=x+mangdodai[4],y,sv.sdt);
	if(sv.phai==true)
		outtextxy(x=x+mangdodai[5],y,"nam");
	else
		outtextxy(x=x+mangdodai[5],y,"nu");
}
void XuatDanhSach(int x,int y,NodeSinhVien *first,int mangdodai[])
{
	for (NodeSinhVien *k = first; k != NULL; k = k->next)
	{
		if(strcmp(first->sv.malop,k->sv.malop)!=0)
		{
			return;
		}	
		Xuat1SV(x,y,k->sv,mangdodai);
			y=y+30;	
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
void KTho(NodeSinhVien *&first,NodeSinhVien *p)
{
	for (; first != NULL; first = first->next)
	{
		if(strcmp(p->sv.ho,first->sv.ho)<0)
		{
			break;
		}
		else 
		{
			if(strcmp(p->sv.ten,first->next->sv.ten)!=0)
			{
				first = first->next;
				break;
			}
		}
	}
}
void them(NodeSinhVien *&first, NodeSinhVien *p,char key[]){
//	NodeSinhVien *k = first;
	if(first == NULL)//danh sach rong
	{
		first=p;
	}
//	else if(strcmp(p->sv.ten,k->sv.ten)==0)
//	{
//		NodeSinhVien *a;
//		for (; k != NULL; k = k->next)
//		{
//			a=k;
//			if(strcmp(p->sv.ho,k->sv.ho)<0)
//			{
//				break;
//			}
//			else 
//			{
//				if(strcmp(p->sv.ten,k->next->sv.ten)!=0)
//				{
//					k = k->next;
//					break;
//				}
//			}
//		}	
//		
//	}
	else if(stricmp(p->sv.ten,first->sv.ten)<0)//neu ten sv p nho hoen ten sv dau ds thi them dau
	{
		ThemDau(first,p);
	}
	else
	{
		for (NodeSinhVien *k = first; k != NULL; k = k->next)
		{
			if(k->next==NULL)
			{
				k->next = p; //them vao cuoi ds
				break;
			}
			else if (stricmp(p->sv.ten,k->next->sv.ten)<0||stricmp(k->next->sv.malop,key)!=0)
			//ten sv p <ten sv k thi them sao ds o vi tri truoc k||va malop cua sv k bang voi key
			{
				NodeSinhVien* tam =k->next;
				k->next=p;
				p->next=tam;
				break;
			}
		}	
	}
}
void ThemSVvaolop(NodeSinhVien *&first,SinhVien &SV)
{
	if(first==NULL)
	{
//		nhapSV(SV,0);
		NodeSinhVien *p=TaoMotSV(SV);
		them(first,p,SV.malop);
	}
	else		
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		if(stricmp(k->sv.malop,SV.malop)==0||k->next==NULL)
		{
//			nhapSV(SV,0);
			NodeSinhVien *p=TaoMotSV(SV);
			them(k->next,p,SV.malop);
			break;
		}
	}
}
void XoaSv(NodeSinhVien *&first,char a[])
{	NodeSinhVien *p;
	if (strcmp(first->sv.mSV,a)==0 ) {
		p=first;
		first = p->next ;
		delete p ;
	}
	else
	for (NodeSinhVien *k = first; k != NULL; k = k->next)
	{
		if (strcmp(k->next->sv.mSV,a)==0)
		{
			p=k->next;
			k->next=p->next;
			delete p;
			break;
		}
	}
}
void gan(SinhVien &p,NodeSinhVien* q)
{
	for(int i=0;i<50;i++)
	p.ho[i]=q->sv.ho[i];
	for(int i=0;i<15;i++)
	p.malop[i]=q->sv.malop[i];
	for(int i=0;i<15;i++)
	p.mSV[i]=q->sv.mSV[i];
//	p.phai=q->sv.phai;
	for(int i=0;i<11;i++)
	p.sdt[i]=q->sv.sdt[i];
	for(int i=0;i<10;i++)
	p.ten[i]=q->sv.ten[i];
}
void chinh_sua_Sv_coMS(NodeSinhVien *&first,SinhVien SV,char key[])/////chua sua dc
{
	XoaSv(first,key);
	NodeSinhVien *p=TaoMotSV(SV);
	them(first,p,SV.malop);
//	if (strcmp(first->sv.mSV,a)==0 ) {
//		
//		SinhVien SV;
//		gan(SV,first);
//		nhapSV(SV,1);//them vao nhung thu can chinh sua
//		NodeSinhVien* p = TaoMotSV(SV);// tao mt nodesinhvienmoi
//		XoaSv(first,first->sv.mSV);
//		them(first,p);
//	}
//	else
//	for (NodeSinhVien *k = first; k != NULL; k = k->next)
//	{
//		if (strcmp(k->next->sv.mSV,key)==0)
//		{
//				
//			k->next->sv=SV;
////			nhapSV(SV,1);//them vao nhung thu can chinh sua
////			NodeSinhVien* p = TaoMotSV(SV);// tao mt nodesinhvienmoi
////			XoaSv(first,k->next->sv.mSV);
////			ThemSVvaolop(first,SV);
//////			them(first,p);
////			break;	
//		}
//	}
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
	fread(&SV,sizeof(SV),1,f); 
	while (!feof(f))  
	{  
	NodeSinhVien* p = TaoMotSV(SV);
		ThemSVvaolop(first,SV);
		fread(&SV,sizeof(SV),1,f);  
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

void XuatDSlop(int x,int y,NodeSinhVien *first,int mangdodai_lh[])
{
	outtextxy(x=x+10,y+5,first->sv.malop);
	int soluong=0;
	char sl[4];
	NodeSinhVien *tam=first;
	for(NodeSinhVien *k=first;k!=NULL;k=k->next)
	{
		soluong++;
		if(strcmp(k->sv.malop,tam->sv.malop)!=0)
		{
			chuyen_so_thanh_chuoi(soluong,sl);
			outtextxy(x+mangdodai_lh[2],y+5,sl);
			y=y+30;
			outtextxy(x,y+5,k->sv.malop);
			soluong=0;
			tam=k;
		}
		if(k->next==NULL)
		{
			soluong++;
			chuyen_so_thanh_chuoi(soluong,sl);
			outtextxy(x+mangdodai_lh[2],y+5,sl);
		}
	}
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
void timSV(NodeSinhVien *first,int socot,SinhVien &SV)
{
	for(NodeSinhVien *k=first;k!=0;k=k->next)
	{
		if(socot==1)
		{
			SV=k->sv;
			break;				
		}	
		socot--;
	}
}
