#pragma once
#include<iostream>
using namespace std;
#include"Monhoc.h"
//#include"SinhVien.h"
//#include"Loptinchi.h"
struct SVDK{
	char maSV[15];
	float diem;
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
void XuatDanhSachSVDK(NodeSVDK *first)
{
	for (NodeSVDK *k = first; k != NULL; k = k->next)
	{
		cout<<"\n\tMa SV: "<<k->svdk.maSV;
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



