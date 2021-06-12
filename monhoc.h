
#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "cautrucmonhoc.h"

void tao_item1()
{
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(350,40,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
        
    taobutton_t(880,40,"TEN MH",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(350,90,"STCLT",130,30,MAU_XAM,MAU_DEN,20,5);
    
    taobutton_t(880,90,"STCTH",130,30,MAU_XAM,MAU_DEN,20,5);
   
    
    taobutton(630,210,"SAVE",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton(770,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(1070,210,"NEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	
	int sldong=15;
	int slcot=5;
	int mangdodai_mh[]={0,80,225,430,225,225};
	int chieu_cao=30;
	char monhoc[][50]={"","STT","MA MON HOC","TEN MON HOC","STCLT","STCTH"};
	taobang(325,280,chieu_cao,mangdodai_mh,slcot,sldong,monhoc,10,5);
	
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
	
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	taotextinput(480,40,850,70,"",11);
	taotextinput(1010,40,1360,70,"",12);
	taotextinput(480,90,850,120,"",13);
	taotextinput(1010,90,1360,120,"",14);
}



void xulymonhoc(int &luu_id)
{

	tao_item1();
	char maMH[10];
	char tenMH[50];
	char STCLT[2];
	char STCTH[2];
	
	int x=-1, y=-1;
	while(true){
		
		//Bat chuot
		int id=0;
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
			case 11:
				Nhap(485,45,maMH);
				break;
			case 12:
				Nhap(1015,45,tenMH);
				break;
			case 13:
				Nhap(485,95,STCLT);
				break;
			case 14:
				Nhap(1015,95,STCTH);
				break;
		}
		delay(0.001);
		
}
}

