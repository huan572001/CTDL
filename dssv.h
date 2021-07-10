#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "cautrucsinhvien.h"
#include "cautrucloptinchi.h"
void manhinhchinh3()
{	
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
    rectangle(5,5,CUASO_NGANG,CUASO_DOC);
    rectangle(10,10,300,320);
    rectangle(310,10,1525,790);
    rectangle(10,325,300,790);
    
    taobutton(16,370,"Sinh Vien",280,70,MAU_XAM,MAU_DEN,20,30,31);
    taobutton(16,445,"In DSSV",280,70,MAU_XAM,MAU_DEN,20,30,33);
    //taobutton(16,595,"In DSSV",14,MAU_XAM,280,70);
}
void itembentrai1()
{
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,40,"MA LOP",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(460,40,830,70,"",311);
    
    taobutton_t(860,40,"MSSV",110,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(970,40,1340,70,"",312);
    
    taobutton_t(330,90,"HO",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(460,90,830,120,"",313);
    
    taobutton_t(860,90,"TEN",110,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(970,90,1340,120,"",314);
    
   	taobutton_t(330,140,"SDT",130,30,MAU_XAM,MAU_DEN,20,5);
   	taotextinput(460,140,830,170,"",315);
   	
//   	taobutton_t(860,140,"NAM NHAP HOC",240,30,MAU_XAM,MAU_DEN,20,5);
//	tao_o(1100,140,1340,170);
//	taotextinput(1100,140,1340,170,"",316);
	
	taobutton(1360,60,"NAM",130,30,MAU_XAM,MAU_DEN,20,5,317);
	taobutton(1360,100,"NU",130,30,MAU_XAM,MAU_DEN,20,5,318);

	//save//cancle//delete//new//
	taobutton(630,210,"ADD",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,4545);
	taobutton(770,210,"SAVE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,3192);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,3193);
	taobutton(1210,210,"BACK",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,3194);
	taobutton(1070,210,"UPDATE",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,3195);
}
void sinhvien_it3(NodeSinhVien *first,int trangso,char malop[])
{   
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
  	itembentrai1();
  	char tam[3];
	int sldong=15;
	int slcot=6;
	int mangdodai[]={0,65,225,225,355,225,90};
	int chieu_cao=30;
	char sinhvien[][50]={"","STT","MA LOP","MSSV","HO TEN","SDT","PHAI"};
	taobang(325,280,chieu_cao,mangdodai,slcot,sldong,sinhvien,10,5,200,trangso);
	XuatDanhSach(405,315,first,mangdodai,trangso,malop);
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
	chuyen_so_thanh_chuoi(trangso,tam);
	outtextxy(800,740,tam);
	outtextxy(820,740,"/");
	chuyen_so_thanh_chuoi(SL_SV_Lop(first,malop)/14+1,tam);
	outtextxy(840,740,tam);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,71);
}
// void diem_it3()
// {
// 	setbkcolor(MAU_TRANG);
// 	setcolor(MAU_DEN);
//	taobarde(315,15,1520,260);
//	taobarde(315,270,1520,780);
// 	itembentrai1();
//	int sldong=15;
//	int slcot=5;
//	int mangdodai_diem[]={0,80,350,245,245,225};
//	int chieu_cao=30;
//	char diem[][50]={"","STT","MSSV","HO","TEN","DIEM TB"};
//	taobang(325,280,chieu_cao,mangdodai_diem,slcot,sldong,diem,10,5,100,trangso);/////
//			
//	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
//	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,71);
// }
void lophoc_it3(NodeSinhVien *first,int trangso,int id)
{
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
  	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,40,"MA LOP",130,30,MAU_XAM,MAU_DEN,20,5);
    setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
    taotextinput(460,40,830,70,"",3131);
    if(id==31)
	taobutton(850,210,"VIEW",140,30,MAU_XANHDUONG,MAU_TRANG,30,5,501);
	else
    taobutton(850,210,"PRINT",140,30,MAU_XANHDUONG,MAU_TRANG,30,5,501);
    
	int sldong=15;
	int slcot=3;
	int mangdodai_lh[]={0,136,500,500};
	int chieu_cao=30;
	char lophoc[][50]={"","STT","MA LOP","SO LUONG SINH VIEN"};
	taobang(325,280,chieu_cao,mangdodai_lh,slcot,sldong,lophoc,10,5,100,trangso);
	XuatDSlop(460,310,first,mangdodai_lh,trangso);	
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
	char tam[3];
    chuyen_so_thanh_chuoi(trangso,tam);
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	taobutton_t(850,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	outtextxy(870,740,"/");
	chuyen_so_thanh_chuoi((Dem_Lop(first,trangso)/14)+1,tam);
	taobutton_t(890,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,71);
	
}
void Frint_SV_Lop(NodeSinhVien *&first,int &luu_id,char maLop[])
{
	int trangso=1;
		int x=-1, y=-1;
	int id=0;
	sinhvien_it3(first,trangso,maLop);
	while(true)
	{
		outtextxy(465,45,maLop);
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id<=33&&id>=31||id==501)
		{
			luu_id=id;
			break;
		}
		if(id==70)
		{
			if(trangso>1)
			{
				trangso--;
				sinhvien_it3(first,trangso,maLop);
			}	
			id=0;
		}
		else if(id==71)
		{
			trangso++;
			sinhvien_it3(first,trangso,maLop);
			id=0;
		}			
		delay(0.001);
	}
}
void XuLyNhapSV(NodeSinhVien *&first,DSloptinchi dsltc,int &luu_id,char maLop[])
{
	SinhVien SV;
	int trangso=1;
	sinhvien_it3(first,trangso,maLop);
	char mSVtam[MaSV];
	int x=-1, y=-1;
	int id=0;
	while(true){	
		//Bat chuot	
		strcpy(SV.malop,maLop);
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id<=33&&id>=31||id==501)
		{
			luu_id=id;
			break;
		}
		outtextxy(465,45,maLop);
		switch(id)
		{
			case 312:
				if(luu_id<200||luu_id>214)
				NhapInHoa(975,45,id,SV.mSV);
				break;
			case 313:
				Nhap(465,95,id,SV.ho);
				break;
			case 314:
				Nhap(975,95,id,SV.ten);
				break;
			case 315:
				Nhapso(465,145,id,SV.sdt,11);
				break;
			case 317:
				SV.phai=true;
				taobutton(1360,60,"NAM",130,30,MAU_XAM1,MAU_DEN,20,5,317);
				taobutton(1360,100,"NU",130,30,MAU_XAM,MAU_DEN,20,5,318);
				break;
			case 318:
				SV.phai=false;
				taobutton(1360,60,"NAM",130,30,MAU_XAM,MAU_DEN,20,5,317);
				taobutton(1360,100,"NU",130,30,MAU_XAM1,MAU_DEN,20,5,318);
				break;
			case 3192:
				chinh_sua_Sv_coMS(first,SV,mSVtam);
				remove("Sinhvien.dat");
				vietSVvaofile(first);
				sinhvien_it3(first,trangso,maLop);
				strcpy(SV.mSV,"");
				strcpy(SV.sdt,"");
				strcpy(SV.ho,"");
				strcpy(SV.ten,"");
				id=0;
				break;
			case 3193:
				if(KT_SV_DK_LTC(dsltc,mSVtam)==false)
				{
					XoaSv(first,mSVtam);
					remove("Sinhvien.dat");
					vietSVvaofile(first);
					sinhvien_it3(first,trangso,maLop);
					strcpy(SV.mSV,"");
					strcpy(SV.sdt,"");
					strcpy(SV.ho,"");
					strcpy(SV.ten,"");
					id=0;				
				}
				else
				{
					outtextxy(770,180,"Khong Duoc Xoa!");
					id=0;
				}
				break;
			case 3194://back
				id=3;
				break;
			case 3195://update
				sinhvien_it3(first,trangso,maLop);
				id=0;
				break;
			case 4545://ADD
				if(Kiem_tra_nhapSV(SV)==true&&Kiem_tra_MaSV(first,SV.mSV)==true)
				{					
					ThemSVvaolop(first,SV);					
					WriteFileSV("Sinhvien.Dat",SV);
					sinhvien_it3(first,trangso,maLop);
					strcpy(SV.mSV,"");
					strcpy(SV.sdt,"");
					strcpy(SV.ho,"");
					strcpy(SV.ten,"");
					id=0;
				}
				else
				{			
					outtextxy(770,180,"dien thieu thong tin hoac ma SV bi trung");
					id=0;
				}												
				break;
			case 70:
				if(trangso>1)
				{
					trangso--;
					sinhvien_it3(first,trangso,maLop);//in lai trang
				}	
				id=0;
				break;
			case 71:
				if(SL_SV_Lop(first,maLop)/14+1>trangso)
				{
					trangso++;
					sinhvien_it3(first,trangso,maLop);//in lai trang
				}
				id=0;
				break;
		}
		if(id>200&&id<=214)
		{	
			sinhvien_it3(first,trangso,maLop);
			if(SL_SV_Lop(first,maLop)>=id-200+(trangso-1)*14)
			{
				timSV(first,id-200+(trangso-1)*14,SV,maLop);
				strcpy(mSVtam,SV.mSV);
				outtextxy(975,45,SV.mSV);
				outtextxy(465,95,SV.ho);
				outtextxy(975,95,SV.ten);
				outtextxy(465,145,SV.sdt);
				luu_id=id;//cap nhat luu id de bat ko cho nhap ma mon hoc
			}	
			else
			{
				strcpy(SV.mSV,"");
				strcpy(SV.sdt,"");
				strcpy(SV.ho,"");
				strcpy(SV.ten,"");
			}	
				
				
			id=0;//cho con tro nhay vao o nhap ten mon hoc
		}
		delay(0.001);		
	}
}
void XuLyNhapLOP(NodeSinhVien *&first,DSloptinchi dsltc,int &luu_id)
{
	
	char maLop[Malop]="";
	int x=-1, y=-1;
	int id=0;
	int trangso=1;
	lophoc_it3(first,trangso,luu_id);
	while(true){	
		//Bat chuot	
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id<=33&&id>=31)
		{
			luu_id=id;
			break;
		}
		switch(id)
		{
			case 3131:
				NhapInHoa(465,45,id,maLop);
				break;
			case 501:
				if(luu_id==31)
				{
					if(strlen(maLop)>0)
					XuLyNhapSV(first,dsltc,id,maLop);
					else
					outtextxy(500,100,"KHONG DUOC DE TRONG!");
				}
				else
				{
					for(NodeSinhVien *k=first;k!=NULL;k=k->next)
					{
						if(strcmp(k->sv.malop,maLop)==0)
						{
							Frint_SV_Lop(first,id,maLop);	
							break;
						}
						if(k->next==NULL)
						{
							outtextxy(500,100,"KHONG TON TAI LOP!");
							id=3131;	
						}
					}
					
				}
				
				break;
			case 70:
				if(trangso>1)
				{
					trangso--;
					lophoc_it3(first,trangso,luu_id);
				}	
				id=0;
				break;
			case 71:
				if (Dem_Lop(first,trangso)/14>trangso-1)
				{
				trangso++;
				lophoc_it3(first,trangso,luu_id);
				}
				id=0;
				break;
		}
		if(id>100&&id<114)
		{
			lophoc_it3(first,trangso,luu_id);//tao lai o nhap
			timLopSV(first,id-100,maLop);
			outtextxy(465,45,maLop);
			id=0;//cho con tro nhay vao o nhap ten mon hoc
		}
		delay(0.001);		
	}
}
void xulydssv(NodeSinhVien *&first,DSloptinchi dsltc,int &luu_id)
{
	char maLop[15];
	manhinhchinh3();
	int x=-1, y=-1;
	int id=31;
	while(true){
		
		//Bat chuot
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1)
		{
			luu_id=id;
			break;
		}
		switch(id)
		{
			case 31://sinh vien
				manhinhchinh3();
				taobutton(16,370,"Sinh Vien",280,70,MAU_XAM1,MAU_DEN,20,30,31);
				XuLyNhapLOP(first,dsltc,id);
				break;
			case 33://in lop
				manhinhchinh3();
  				taobutton(16,445,"In DSSV",280,70,MAU_XAM1,MAU_DEN,20,30,33);
  				XuLyNhapLOP(first,dsltc,id);
				break;
//			case 3131:
//				Nhap(465,45,id,maLop);
//				break;
		}
		delay(0.001);	
}
}
