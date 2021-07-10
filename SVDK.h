#pragma once
#include<iostream>
using namespace std;
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
void Xoa_ALL_SVDK(NodeSVDK *&first)
{
	NodeSVDK *p;
	while(first!=NULL)
	{
		p=first;
		first=first->next;
		delete p;
	}
}
void XuatDanhSachSVDK(int x,int y,NodeSVDK *first,NodeSinhVien *firstSV,int trangso)
{
		setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int mangdodai_diem[]={0,80,350,245,245,225};
	int tam=x;
	int demSLSV=1;
	char tam1[4];
	for (NodeSVDK *k = first; k != NULL; k = k->next)
	{
		if(demSLSV>(trangso-1)*14&&demSLSV<=trangso*14)
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
		demSLSV++;
		
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
bool KT_Svdk_chua(NodeSVDK *first,char maSV[])
{
	for(NodeSVDK *k=first;k!=NULL;k=k->next)
	{
		if(strcmp(k->svdk.maSV,maSV)==0)
		return true;
	}
	return false;
}

