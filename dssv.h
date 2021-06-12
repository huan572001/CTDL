#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"

void taobarde(int x ,int y ,int x1 ,int y1)//de bang
{
	setfillstyle(1,MAU_TRANG);
	bar(x,y,x1,y1);
} 
void manhinhchinh3()
{	
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
    rectangle(5,5,CUASO_NGANG,CUASO_DOC);
    rectangle(10,10,300,320);
    rectangle(310,10,1525,790);
    rectangle(10,325,300,790);
    
    taobutton(16,370,"Sinh Vien",280,70,MAU_XAM,MAU_DEN,20,30,31);
    taobutton(16,445,"Bang diem",280,70,MAU_XAM,MAU_DEN,20,30,32);
    taobutton(16,520,"In DSSV",280,70,MAU_XAM,MAU_DEN,20,30,33);
    //taobutton(16,595,"In DSSV",14,MAU_XAM,280,70);
}


void itembentrai1()
{
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
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
	taotextinput(1100,140,1340,170,"",316);
	
	taobutton(1360,60,"NAM",130,30,MAU_XAM,MAU_DEN,20,5,317);
	taobutton(1360,100,"NU",130,30,MAU_XAM,MAU_DEN,20,5,318);

	//save//cancle//delete//new//
	taobutton(630,210,"SAVE",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,4545);
	taobutton(770,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,3192);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,3193);
	taobutton(1070,210,"NEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,3194);
}



void sinhvien_it3()
{   
	setbkcolor(MAU_TRANG);
	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
  	itembentrai1();
  	
	int sldong=15;
	int slcot=6;
	int mangdodai[]={0,65,225,225,355,225,90};
	int chieu_cao=30;
	char sinhvien[][50]={"","STT","MA LOP","MSSV","HO TEN","SDT","PHAI"};
	taobang(325,280,chieu_cao,mangdodai,slcot,sldong,sinhvien,10,5);
	
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
}


 void diem_it3()
 {
 	setbkcolor(MAU_TRANG);
	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
 	itembentrai1();
	int sldong=15;
	int slcot=5;
	int mangdodai_diem[]={0,80,350,245,245,225};
	int chieu_cao=30;
	char diem[][50]={"","STT","MSSV","HO","TEN","DIEM TB"};
	taobang(325,280,chieu_cao,mangdodai_diem,slcot,sldong,diem,10,5);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
 }


void lophoc_it3()
{
	setbkcolor(MAU_TRANG);
  	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,40,"MA LOP",130,30,MAU_XAM,MAU_DEN,20,5);
    setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
    taotextinput(460,40,830,70,"",3131);
    
	taobutton(770,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(920,210,"CHI TIET",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
    
    
	int sldong=15;
	int slcot=4;
	int mangdodai_lh[]={0,136,350,327,327};
	int chieu_cao=30;
	char lophoc[][50]={"","STT","MA LOP","SO LUONG SINH VIEN","NAM NHAP HOC"};
	taobang(325,280,chieu_cao,mangdodai_lh,slcot,sldong,lophoc,10,5);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
	
}
void xulydssv(int &luu_id)
{
	char maLop[15];
	manhinhchinh3();
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
			case 31://sinh vien
			//	manhinhchinh3();
				sinhvien_it3();
				break;
			case 32://lop hoc
			//	manhinhchinh3();
				diem_it3();
				break;
			case 33:
			//	manhinhchinh3();
				lophoc_it3();
				break;
			case 3131:
				Nhap(465,45,maLop);
				break;
			default : 
			manhinhchinh3();
			break;
		}
		delay(0.001);
		
}
}


