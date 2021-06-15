#pragma once
#include<iostream>
#include<string.h>
#include "funtion.h"
using namespace std;
struct MonHoc{
	char maMH[10]="";
	char tenMH[50]="";
	int STCLT,STCTH;
};
struct Node{
	MonHoc monhoc;
	Node *pLeft;
	Node *pRight;
};
struct CayNhiPhan{
	Node *root=NULL;
};
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
void NhapMH(MonHoc &MH,int key)
{
	if(key==0)
	{
	cout<<"\n\tNhap ma mon hoc: ";
	cin>>MH.maMH;
	cout<<"\n\tnhap ten mon hoc: ";
	cin>>MH.tenMH;
	}
	cout<<"\n\tnhap so tin chi ly thuyet: ";
	cin>>MH.STCLT;
	cout<<"\n\tNhap so tin chi thuc hanh: ";
	cin>>MH.STCTH;
}
void XuatMH(int x,int &y,MonHoc MH,int mangdodai_mh[])
{
	outtextxy(x=x+10,y+5,MH.maMH);
	outtextxy(x=x+mangdodai_mh[2],y+5,MH.tenMH);
	char stclt[3];
	chuyen_so_thanh_chuoi(MH.STCLT,stclt);
	outtextxy(x=x+mangdodai_mh[3],y+5,stclt);
	chuyen_so_thanh_chuoi(MH.STCTH,stclt);
	outtextxy(x=x+mangdodai_mh[4],y+5,stclt);	
}
void XuatMH2(MonHoc MH)
{
	cout<<"\n\tma mon hoc: ";
	cout<<MH.maMH;
	cout<<"\n\tten mon hoc: ";
	cout<<MH.tenMH;
	cout<<"\n\tso tin chi ly thuyet: ";
	cout<<MH.STCLT;
	cout<<"\n\tso tin chi thuc hanh: ";
	cout<<MH.STCTH;
}
void LNR2(Node *root)
{
	// cây còn ph?n t?
	
	if (root != NULL)
	{
		LNR2(root->pLeft);
		XuatMH2(root->monhoc);
		LNR2(root->pRight);
	}
	
}
void ThemNode(Node *&root, MonHoc MH)
{
	
	// n?u cây r?ng
	if (root == NULL)
	{
		cout<<"\n\n\t\tVO ROI NE";
		Node* p = new Node;
		p->monhoc = MH;
		p->pLeft = NULL;
		p->pRight = NULL;
		root = p; // phan tu p chinh la node go cau cay
	}
	else
	{
		if (stricmp(MH.maMH,root->monhoc.maMH) >0)
		{
			ThemNode(root->pRight, MH);
		}
		else if (stricmp(MH.maMH,root->monhoc.maMH) <0)
		{
			ThemNode(root->pLeft, MH);
		}
	}
}
//void LNR(int x,int y,Node *root,int mangdodai_mh[])
//{
//	if (root != NULL)
//	{
//		LNR(x,y,root->pLeft,mangdodai_mh);
//		XuatMH(x,y,root->monhoc,mangdodai_mh);
//		LNR(x,y,root->pRight,mangdodai_mh);
//	}	
//}
void LNR(int x,int y,Node *root,int mangdodai_mh[])
{
	Node *pre;
	Node *current=root;
	while (current)
    {
		if (!current->pLeft)
    	{
    		y=y+30;
   		    XuatMH(x,y,current->monhoc,mangdodai_mh);
    	    current = current->pRight;
    	}
    	else
    	{
     		pre = current->pLeft;
     		while (pre->pRight&&pre->pRight != current)
     		{
      			pre = pre->pRight;
     		}
     		if (!pre->pRight)
     		{
      			pre->pRight = current;
      			current = current->pLeft;
     		}
     		else
     		{
     			y=y+30;
      			XuatMH(x,y,current->monhoc,mangdodai_mh);
      			pre->pRight = NULL;
      			current = current->pRight;
     		}
    	}
   	}
}

// CÁCH 1: TÌM NODE TRÁI NH?T C?A CÂY CON PH?I
void Tim_Node_The_Mang(Node*& X, Node*& Y)
{
	if (Y->pLeft != NULL)
	{
		Tim_Node_The_Mang(X, Y->pLeft);
	}
	else // <=> if(Y->pLeft == NULL)
	{
		X->monhoc = Y->monhoc;
		X = Y;
		Y = Y->pRight;
	}
}
void XoaNode(Node *&root,char *key)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		if(stricmp(key,root->monhoc.tenMH)>0)
		{
			XoaNode(root->pRight,key);
		}
		else if(stricmp(key,root->monhoc.tenMH)<0)
		{
			XoaNode(root->pLeft,key);
		}
		else
		{

			Node*X =root;
			if(root->pLeft==NULL)
			{
				root=root->pRight;
			}
			else if(root->pRight==NULL)
			{
				root=root->pLeft;
			}
			else
			{
				Tim_Node_The_Mang(X,root->pRight);
			}
			delete X;
		}
	}
}
void chinh_su_mon_hoc_co_ten(Node* root,char* key,MonHoc &mh)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		if(stricmp(key,root->monhoc.maMH)>0)
		{
			chinh_su_mon_hoc_co_ten(root->pRight,key,mh);
		}
		else if(stricmp(key,root->monhoc.maMH)<0)
		{
			chinh_su_mon_hoc_co_ten(root->pLeft,key,mh);
		}
		else
		{
			mh=root->monhoc;
		}
	}
}
void WriteFileMH(char *FileName,MonHoc mh)  
{  
	FILE *f;      	
//	MonHoc mh;
//	NhapMH(mh,0);
	f=fopen(FileName,"ab");  
//	ThemNode(root,mh);
	fwrite(&mh,sizeof(mh),1,f); 
	fclose(f);   
}  
void doc_tu_file_vao_cay(char *FileName,Node *&root)
{
		FILE *f;   
		MonHoc monhoc;   	
	f=fopen(FileName,"rb");
	fread(&monhoc,sizeof(monhoc),1,f);  
	 	ThemNode(root,monhoc);
	while (!feof(f))  
	{  
		 ThemNode(root,monhoc);
		fread(&monhoc,sizeof(monhoc),1,f);  
	}  	  
	fclose(f); 
}
void vietMHvaofile(Node *&root)
{
	if (root != NULL)
	{
		vietMHvaofile(root->pLeft);
		WriteFileMH("monhoc.dat",root->monhoc);
		vietMHvaofile(root->pRight);
	}		
}
void KiemTraMMH(Node *root,char a[],int &kt)
{
	if (root != NULL)
	{
		KiemTraMMH(root->pLeft,a,kt);
		if(stricmp(root->monhoc.maMH,a)==0)
		{
			kt=1;
		}
		KiemTraMMH(root->pRight,a,kt);
	}
}
