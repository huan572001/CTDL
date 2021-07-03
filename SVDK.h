#pragma once
#include<iostream>
using namespace std;
#include "Monhoc.h"
#include "cautrucloptinchi.h"
#include "cautrucsinhvien.h"
struct SVDK{
	char maSV[15];
	float diem=0;
};
struct NodeSVDK{
	SVDK svdk;
	NodeSVDK *next;
};
struct DSSVDK{
	NodeSVDK *first=NULL;
};
NodeSVDK *TaoMotSVDK(SVDK SV){
	NodeSVDK *tamp= new NodeSVDK();
	tamp->svdk=SV;
	tamp->next=NULL;
	return tamp;
}

////////////////////////////
void ThemDauSVDK(NodeSVDK*& first, SVDK svdk)
{
	NodeSVDK *p= TaoMotSVDK(svdk);
	// danh s�ch dang r?ng
	if (first == NULL)
	{
		first = p; // node p cung ch�nh l� node d?u danh s�ch
	}
	else
	{
		// Bu?c 1: Cho node p tr? t?i node d?u danh s�ch th�ng qua pHead
		p->next = first; 

		// Bu?c 2: C?p nh?t l?i pHead ch�nh l� node p v?a th�m v�o
		first = p;
	}
}
void XoaSvDK(NodeSVDK *&first,char a[])
{	NodeSVDK *p;
	if (strcmp(first->svdk.maSV,a)==0 ) {
		p=first;
		first = p->next ;
		delete p ;
	}
	else
	for (NodeSVDK *k = first; k != NULL; k = k->next)
	{
		if (strcmp(k->next->svdk.maSV,a)==0)
		{
			p=k->next;
			k->next=p->next;
			delete p;
			break;
		}
	}
}
//void themSVDK(NodeSVDK *&first, SVDK svdk){
////	NodeSinhVien *k = first;
//NodeSVDK *p= TaoMotSVDK(svdk);
//	if(first == NULL)
//	{
//		first=p;
//	}
//	else if(strcmp(p->svdk.maSV,first->svdk.maSV)<0)
//	{
//		ThemDauSVDK(first,p);
//	}
//	else
//	{	for (NodeSVDK *k = first; k != NULL; k = k->next)
//		{
//			if(k->next==NULL)
//			{
//				k->next = p; 
//				break;// d?ng l?i
//			}
//			 if (strcmp(p->svdk.maSV,k->next->svdk.maSV)<0)
//			{
//				NodeSVDK* tam =k->next;
//				k->next=p;
//				p->next=tam;
//				break;// d?ng l?i
//			}
//		}	
//	}
//}
void XuatDanhSachSVDK(int x,int y,NodeSVDK *first,NodeSinhVien *firstSV)
{
	int mangdodai_diem[]={0,80,350,245,245,225};
	int tam=x;
	char tam1[4];
	for (NodeSVDK *k = first; k != NULL; k = k->next)
	{
		outtextxy(x,y,k->svdk.maSV);
		for(NodeSinhVien *h=firstSV;h!=NULL;h=h->next)
		{
			if(strcmp(h->sv.mSV,k->svdk.maSV)==0)
			{
				outtextxy(x=x+mangdodai_diem[2],y,h->sv.ho);
				outtextxy(x=x+mangdodai_diem[3],y,h->sv.ten);
			}
		}
		if(k->svdk.diem==0)
		{
			outtextxy(x=x+mangdodai_diem[4]+100,y,"0");
		}
		else
		{
			chuyen_so_thanh_chuoi(k->svdk.diem,tam1);
			outtextxy(x=x+mangdodai_diem[4]+100,y,tam1);			
		}
		x=tam;
		y=y+30;
	}
}
int soluongSVDK(NodeSVDK *first)
{
	int dem=0;
	for(NodeSVDK *k=first;k!=NULL;k=k->next)
	{
		dem++;
	}
	return dem;
}



