#pragma once
#include<iostream>
#include<string.h>
using namespace std;
struct MonHoc{
	char maMH[10];
	char tenMH[50];
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
void XuatMH(MonHoc MH)
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
void LNR(Node *root)
{
	// cây còn ph?n t?
	
	if (root != NULL)
	{
		LNR(root->pLeft);
		XuatMH(root->monhoc);
		LNR(root->pRight);
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
		if(strcmp(key,root->monhoc.tenMH)>0)
		{
			XoaNode(root->pRight,key);
		}
		else if(strcmp(key,root->monhoc.tenMH)<0)
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
void chinh_su_mon_hoc_co_ten(Node* root,char* key)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		if(strcmp(key,root->monhoc.tenMH)>0)
		{
			chinh_su_mon_hoc_co_ten(root->pRight,key);
		}
		else if(strcmp(key,root->monhoc.tenMH)<0)
		{
			chinh_su_mon_hoc_co_ten(root->pLeft,key);
		}
		else
		{
			NhapMH(root->monhoc,1);
		}
	}
}
