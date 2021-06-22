#pragma once
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "dssv.h"
#include "monhoc.h"
#include "loptinchi.h"
#include "cautrucmonhoc.h"
#include "cautrucloptinchi.h"
#include "cautrucsinhvien.h"

void taobangmenu_svdk()
{
	setmapid();
	setbkcolor(MAU_TRANG);
	cleardevice();
   	
   	
	setcolor(MAU_DEN);
	rectangle(5,5,CUASO_NGANG,CUASO_DOC);
	rectangle(10,10,300,320);
	rectangle(310,10,1525,790);
	rectangle(10,325,300,790);
					    
//	taobutton(16,16,"MON HOC",280,70,MAU_XAM,MAU_DEN,20,30,1);
	taobutton(16,91,"LOP TIN CHI",280,70,MAU_XAM,MAU_DEN,20,30,2);
//	taobutton(16,166,"SINH VIEN",280,70,MAU_XAM,MAU_DEN,20,30,3);
	taobutton(16,241,"DANG XUAT",280,70,MAU_XAM,MAU_DEN,20,30,4);
											    
	taobutton_t(70,330,"CHUC NANG",20,10,MAU_XANHLA,MAU_XANHNON,0,0);
}

void svdk_thongtinsv()
{
	setmapid();
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	rectangle(315,15,1520,260);
	taobarde1(315,15,1520,260);
	taobarde1(315,270,1520,780);
    
    
    taobutton_t(330,40,"MA LOP",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(460,40,830,70);
    taotextinput(460,40,830,70,"",311);
    
    taobutton_t(860,40,"MSSV",110,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(970,40,1340,70);
    taotextinput(970,40,1340,70,"",312);
    
    taobutton_t(330,90,"HO",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(460,90,830,120);
    taotextinput(460,90,830,120,"",313);
    
    taobutton_t(860,90,"TEN",110,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(970,90,1340,120);
    taotextinput(970,90,1340,120,"",314);
    
   	taobutton_t(330,140,"SDT",130,30,MAU_XAM,MAU_DEN,20,5);
   	tao_o(460,140,830,170);
   	taotextinput(460,140,830,170,"",315);
   	
   	taobutton_t(860,140,"NAM NHAP HOC",240,30,MAU_XAM,MAU_DEN,20,5);
	tao_o(1100,140,1340,170);
	taotextinput(1100,140,1340,170,"",310);
	
	taobutton_t(330,190,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
	tao_o(510,190,830,220);
    taotextinput(510,190,830,220,"",999);
    
    taobutton_t(860,190,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,190,1340,220);
    taotextinput(990,190,1340,220,"",998);
	
	taobutton(1360,60,"NAM",130,30,MAU_XAM,MAU_DEN,20,5,317);
	taobutton(1360,100,"NU",130,30,MAU_XAM,MAU_DEN,20,5,318);
	
	taobutton(1355,170,"TIM KIEM",155,30,MAU_XANHDUONG,MAU_TRANG,10,5,343);
}
void bangchon_svdk()
{
	setmapid();
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	rectangle(315,270,1520,780);
	
	
	int sldong=15;
	int slcot=7;
	int mangdodai_svdk[]={0,80,173,273,173,173,173,100};
	int chieu_cao=30;
	char svdk[][50]={"","STT","MMH","TEN MH","NHOM","SVDDK","CL","CHON"};
	taobang(325,280,chieu_cao,mangdodai_svdk,slcot,sldong,svdk,10,5,200);		
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
	
}
void xuly_dohoa_svdk()
{
	svdk_thongtinsv();
	int luu_id=0;
	int x=-1, y=-1;
	int id=0;
	while(true){	
		//Bat chuot	
		id=luu_id;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id==4)
		{
			luu_id=id;
			break;
		}
		switch(id){
			case 343:
				taobangmenu_svdk();
				svdk_thongtinsv();
				bangchon_svdk();
				break;
			case 998:
				Nhap(995,195,id,"");
				break;
			case 999:
				Nhap(515,195,id,"");
				break;
				
			
		}
		delay(0.001);
}
}
