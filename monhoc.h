#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "cautrucmonhoc.h"
#include "cautrucloptinchi.h"
//////////////////////////DO HOA///////////////////////////
int mangdodai_mh[]={0,80,225,430,225,225};
void tao_item1(Node *root,int trangso)
{
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
	
    taobutton_t(350,40,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
        
    taobutton_t(880,40,"TEN MH",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(350,90,"STCLT",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(880,90,"STCTH",130,30,MAU_XAM,MAU_DEN,20,5);
   
    
    taobutton(630,170,"ADD",120,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton(760,170,"SAVE",140,30,MAU_XANHDUONG,MAU_TRANG,30,5,314);
	taobutton(910,170,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,315);
	taobutton(1060,170,"UPDATE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,316);
	taotextinput(480,40,850,70,"",11);
	taotextinput(1010,40,1360,70,"",12);
	taotextinput(480,90,850,120,"",13);
	taotextinput(1010,90,1360,120,"",14);
	int sldong=15;
	int slcot=5;
	
	int chieu_cao=30;
	char monhoc[][50]={"","STT","MA MON HOC","TEN MON HOC","STCLT","STCTH"};
	taobang(325,280,chieu_cao,mangdodai_mh,slcot,sldong,monhoc,10,5,100,trangso);
	char tam[3];
	chuyen_so_thanh_chuoi(trangso,tam);
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	taobutton_t(850,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	outtextxy(870,740,"/");
	char tam1[3];
	chuyen_so_thanh_chuoi(LNR_D(root,trangso)/14+1,tam1);
	taobutton_t(890,740,tam1,20,20,MAU_TRANG,MAU_DEN,0,0);
	LNR(405,280,root,mangdodai_mh,trangso);//xuat ds mon hoc
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,71);
}
void xulymonhoc(int &luu_id,Node *&root,DSloptinchi dsltc)
{	
	MonHoc MH;
	char STCTH[2]="";
	char STCLT[2]="";
	int x=-1, y=-1;
	int id=0;
	int KT=0;
	int trangso=1;
	tao_item1(root,trangso);
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
				NhapInHoa(485,45,id,MH.maMH);//nhap ma mon hoc
				break;
			case 12:
				if(luu_id<100||luu_id>114)
				Nhap(1015,45,id,MH.tenMH);//nhap ten mon hoc
				break;
			case 13:
				Nhapso(485,95,id,STCLT,3);//nhap so tc lt
				MH.STCLT=chuyen_chuoi_thanh_so(STCLT);//chuyen chuoi thanh so gan lai vao MH
				break;
			case 14:
				Nhapso(1015,95,id,STCTH,3);//nhap so tc th
				MH.STCTH=chuyen_chuoi_thanh_so(STCTH);//chuyen chuoi thanh so gan lai vao MH
				trangso=1;
				break; 
			case 313:
				KT=0;
				KiemTraMMH(root,MH,KT);
				if(KT==0&&KT_Nhap_MH(MH)==true)
				{
					ThemNode(root,MH);//them vao cay
					tao_item1(root,trangso);
					WriteFileMH("monhoc.Dat",MH,root);//them vao file
					id=0;
						strcpy(MH.maMH,"");	
						strcpy(MH.tenMH,"");
						strcpy(STCLT,"");
						strcpy(STCTH,"");			
					outtextxy(630,140,"them mon hoc thanh cong");			
				}
				else 
				{
					outtextxy(630,140,"khong duoc trung ma mon hoc va de trong!");
					id=11;//cho con tro nhay vao o ma mon hoc				
				}	
				break;	
			case 314:
				chinh_su_mon_hoc_co_ten(root,MH);//
				tao_item1(root,trangso);
				remove("monhoc.Dat");
				vietMHvaofile(root);
				outtextxy(630,140,"chinh sua thanh cong");
				id=0;//de cap nhat lai bang
				break;
			case 316:
				id=1;
				break;	
			case 70:
				if(trangso>1)
				{
					trangso--;
					tao_item1(root,trangso);
				}	
				id=0;
				break;
			case 71:
    			if (LNR_D(root,trangso)/14>(trangso-1))
				{
				trangso++;
				tao_item1(root,trangso);
				}
				id=0;
				break;	
                
		}
		if(id>100&&id<=114)
		{
			tao_item1(root,trangso);//tao lai o nhap
			LNR1(root,id-99+(trangso-1)*14,MH);//tim kiem Mh de xuat
			chuyen_so_thanh_chuoi(MH.STCLT,STCLT);
			chuyen_so_thanh_chuoi(MH.STCTH,STCTH);
			luu_id=id;//cap nhat luu id de bat ko cho nhap ma mon hoc
			id=0;
		}
		if(id==315&&luu_id>99&&luu_id<114)//phai co du lieu moi dc xoa
		{
			if(KT_MH_Da_Duoc_Tao_LTC(dsltc,MH.maMH)==false)
			{
				XoaNode(root,MH.tenMH);//xoa mon hoc
//				remove("monhoc.Dat");
//				vietMHvaofile(root);
				tao_item1(root,trangso);
				outtextxy(630,140,"Xoa thanh cong");
			}
			else
			{
				outtextxy(630,140,"khong duoc xoa!");
			}
			id=0;//cap nhat lai bang
		}
		delay(0.001);		
	}
}

