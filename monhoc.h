
#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "cautrucmonhoc.h"
////////////////////////////////////////////////////////////DO HOA///////////////////////////
int mangdodai_mh[]={0,80,225,430,225,225};
void tao_item1(Node *&root)
{
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(350,40,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
        
    taobutton_t(880,40,"TEN MH",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(350,90,"STCLT",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(880,90,"STCTH",130,30,MAU_XAM,MAU_DEN,20,5);
   
    
    taobutton(630,170,"THEM",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton(770,170,"LUU CHINH SUA",240,30,MAU_XANHDUONG,MAU_TRANG,15,5,314);
	taobutton(1010,170,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,315);
//	taobutton(1070,210,"NEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton_t(350,210,"TIM KIEM",160,30,MAU_XAM,MAU_DEN,20,5);
	int sldong=15;
	int slcot=5;
	
	int chieu_cao=30;
	char monhoc[][50]={"","STT","MA MON HOC","TEN MON HOC","STCLT","STCTH"};
	taobang(325,280,chieu_cao,mangdodai_mh,slcot,sldong,monhoc,10,5,100);
	LNR(405,280,root,mangdodai_mh);
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
//	LNR2(root);
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	taotextinput(480,40,850,70,"",11);
	taotextinput(1010,40,1360,70,"",12);
	taotextinput(480,90,850,120,"",13);
	taotextinput(1010,90,1360,120,"",14);
	taotextinput(510,210,750,240,"",15);
}



void xulymonhoc(int &luu_id,Node *&root)
{
	tao_item1(root);
	MonHoc MH;
	char STCTH[2]="";
	char STCLT[2]="";
	int x=-1, y=-1;
	int id=0;
	while(true){
		
		//Bat chuot
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1)//thoat ra vào chuc nang khac
		{
			luu_id=id;
			break;
		}
		outtextxy(485,45,MH.maMH);
		outtextxy(1015,45,MH.tenMH);
		outtextxy(485,95,STCLT);
		outtextxy(1015,95,STCTH);
		switch(id)
		{
			
			case 11:
				if(luu_id<100||luu_id>114)
				Nhap(485,45,id,MH.maMH);//nhap ma mon hoc
				break;
			case 12:
				Nhap(1015,45,id,MH.tenMH);//nhap ten mon hoc
				break;
			case 13:
				Nhapso(485,95,id,STCLT);//nhap so tc lt
				MH.STCLT=chuyen_chuoi_thanh_so(STCLT);//chuyen chuoi thanh so gan lai vao MH
				break;
			case 14:
				Nhapso(1015,95,id,STCTH);//nhap so tc th
				MH.STCTH=chuyen_chuoi_thanh_so(STCTH);//chuyen chuoi thanh so gan lai vao MH
				break; 
			case 313:
				int kt=0;
				KiemTraMMH(root,MH.maMH,kt);//kiem tra xem ma mon hoc co bi chung hay ko
				if(kt==1)
				{
					outtextxy(630,140,"khong duoc trung ma mon hoc!");
					id=11;//cho con tro nhay vao o ma mon hoc	
				}
				else
				{
					ThemNode(root,MH);//them vao cay
//					WriteFileMH("monhoc.Dat",MH);//them vao file
					id=1;//cap nhat lai bang					
//					outtextxy(630,140,"them mon hoc thanh cong");				
				}	
				break;			
		}
		if(id>100&&id<114)
		{
			tao_item1(root);//tao lai o nhap
			LNR1(root,id-99,MH);//tim kiem Mh de xuat
			chuyen_so_thanh_chuoi(MH.STCLT,STCLT);
			chuyen_so_thanh_chuoi(MH.STCTH,STCTH);
			luu_id=id;//cap nhat luu id de bat ko cho nhap ma mon hoc
			id=12;//cho con tro nhay vao o nhap ten mon hoc
		}
		if(id==314)
		{
			chinh_su_mon_hoc_co_ten(root,MH);//
//			tao_item1(root);
//			outtextxy(630,140,"chinh sua thanh cong");
			id=1;//de cap nhat lai bang
		}
		if(id==315&&luu_id>99&&luu_id<114)//phai co du lieu moi dc xoa
		{
			XoaNode(root,MH.maMH);//xoa mon hoc
//			LNR2(root);
//			tao_item1(root);
			id=1;//cap nhat lai bang
		}
		delay(0.001);		
	}
}

