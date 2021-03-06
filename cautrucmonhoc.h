#pragma once
#include<iostream>
#include<string.h>
#include "funtion.h"
#include "define.h"
using namespace std;
struct MonHoc{
	char maMH[ma_MH]="";
	char tenMH[Ten_MH]="";
	int STCLT=0,STCTH=0;
};
struct Node{
	MonHoc monhoc;
	Node *pLeft;
	Node *pRight;
};
//struct CayNhiPhan{
//	Node *root=NULL;
//};
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
	// n?u c?y r?ng
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
		if (strcmp(MH.tenMH,root->monhoc.tenMH) >0)
		{
			ThemNode(root->pRight, MH);
		}
		else if (stricmp(MH.tenMH,root->monhoc.tenMH) <0)
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
//   			    cout<<current->monhoc.maMH;
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
				}
				pre->pRight = NULL;
				i++;
				current = current->pRight;     			
     		}
    	}
   	}
}
int LNR_D(Node *root,int trangso)
{
    Node *pre;
	Node *current=root;
	int dem=0;
	int i=1;
	while (current)
    {
		if (!current->pLeft)
    	{
    		if(i>14*(trangso-1)&&i<=14*trangso)
    		{
    		dem++;    
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
     				dem++;
      				pre->pRight = NULL;
				}
				i++;
				current = current->pRight;     			
     		}
    	}
   	}
   	return dem;
}
// C?CH 1: T?M NODE TR?I NH?T C?A C?Y CON PH?I
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
void XoaALLTree(Node* &root)
{
	if(root!=NULL)
	{
		XoaALLTree(root->pLeft);
		if(root->pRight==NULL)
		{
			delete root;
		}
		else
		XoaALLTree(root->pRight);
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
void WriteFileMH(char *FileName,MonHoc mh,Node *&root)  
{  
	FILE *f;      	
//	MonHoc mh;
//	NhapMH(mh,0);
	f=fopen(FileName,"ab");  
	ThemNode(root,mh);
	fwrite(&mh,sizeof(mh),1,f); 
	fclose(f);   
}  
void doc_tu_file_vao_cay(char *FileName,Node *&root)
{
		FILE *f;   
		MonHoc monhoc;   	
	f=fopen(FileName,"rb");
	while (fread(&monhoc,sizeof(monhoc),1,f))  
	{  
		 ThemNode(root,monhoc);
	}  	  
	fclose(f); 
}
void vietMHvaofile(Node *&root)
{
	if (root != NULL)
	{
		vietMHvaofile(root->pLeft);
		WriteFileMH("monhoc.dat",root->monhoc,root);
		vietMHvaofile(root->pRight);
	}		
}
void KiemTraMMH(Node *root,MonHoc MH,int &KT)
{
	Node *pre;
	Node *current=root;
	while (current)
    {
		if (!current->pLeft)
    	{
			if(strcmp(current->monhoc.maMH,MH.maMH)==0||strcmp(current->monhoc.tenMH,MH.tenMH)==0)
			{
					KT=1;
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
				if(strcmp(current->monhoc.maMH,MH.maMH)==0||strcmp(current->monhoc.tenMH,MH.tenMH)==0)
				{
					KT=1;
				}						
      			pre->pRight = NULL;
      			current = current->pRight;
     		}
    	}
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
void KT_MMH(Node *root,int&KT,char maMH[])
{
	if(root!=NULL)
	{
		KT_MMH(root->pLeft,KT,maMH);
		if(strcmp(root->monhoc.maMH,maMH)==0)
		{
			KT=1;
		}
		KT_MMH(root->pRight,KT,maMH);
	}
}
void Tim_MMH(int x,int y,Node *root,char maMH[])
{
	if(root!=NULL)
	{
		Tim_MMH(x,y,root->pLeft,maMH);
		if(strcmp(root->monhoc.maMH,maMH)==0)
		{
			outtextxy(x,y,root->monhoc.tenMH);
		}
		Tim_MMH(x,y,root->pRight,maMH);
	}
}
