#pragma once
#include<iostream>
#include<string.h>
#include "funtion.h"
using namespace std;
struct MonHoc{
	char maMH[10]="";
	char tenMH[50]="";
	int STCLT=0,STCTH=0;
};
struct Node{
	MonHoc monhoc;
	Node *pLeft;
	Node *pRight;
};
struct CayNhiPhan{
	Node *root=NULL;
};
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
void ThemNode(Node *&root, MonHoc MH)
{
	
	// n?u cây r?ng
	if (root == NULL)
	{
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
void LNR1(Node *root,int socot,MonHoc &mh)
{
	Node *pre;
	Node *current=root;
	while (current)
    {
		if (!current->pLeft)
    	{
			socot=socot-1;
			if(socot==1)
			{
				mh=current->monhoc;
			}
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
     			socot=socot-1;
				if(socot==1)
				{
					mh=current->monhoc;
				}						
      			pre->pRight = NULL;
      			current = current->pRight;
     		}
    	}
   	}	
}
void LNR(int x,int y,Node *root,int mangdodai_mh[],int trangso)
{
	Node *pre;
	Node *current=root;
	int i=1;
	while (current)
    {
		if (!current->pLeft)
    	{
    		if(i>14*(trangso-1)&&i<=14*trangso)
    		{
    			y=y+30;
   			    XuatMH(x,y,current->monhoc,mangdodai_mh);
			}
			i++;
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
     			if(i>14*(trangso-1)&&i<=14*trangso)
     			{
     				y=y+30;
      				XuatMH(x,y,current->monhoc,mangdodai_mh);
      				pre->pRight = NULL;
				}
				i++;
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
		if(stricmp(key,root->monhoc.maMH)>0)
		{
			XoaNode(root->pRight,key);
		}
		else if(stricmp(key,root->monhoc.maMH)<0)
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
void chinh_su_mon_hoc_co_ten(Node* root,MonHoc mh)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		if(stricmp(mh.maMH,root->monhoc.maMH)>0)
		{
			chinh_su_mon_hoc_co_ten(root->pRight,mh);
		}
		else if(stricmp(mh.maMH,root->monhoc.maMH)<0)
		{
			chinh_su_mon_hoc_co_ten(root->pLeft,mh);
		}
		else
		{
			root->monhoc=mh;
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
bool KT_Nhap_MH(MonHoc mh)
{
	if(strlen(mh.maMH)>2&&strlen(mh.tenMH)>2&&mh.STCLT>0&&mh.STCTH>=0)
	{
		return true;
	}
	return false;
}
