#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"

void taobarde1(int x ,int y ,int x1 ,int y1)
{
	setfillstyle(1,MAU_TRANG);
	bar(x,y,x1,y1);
} 
void manhinhchinh2()
{
	setbkcolor(MAU_TRANG);
   	   	
	setcolor(MAU_DEN);
    rectangle(5,5,CUASO_NGANG,CUASO_DOC);
    rectangle(10,10,300,320);
    rectangle(310,10,1525,790);
    rectangle(10,325,300,790);
    
    taobutton(16,370,"Lop TC",280,70,MAU_XAM,MAU_DEN,20,30,21);
    taobutton(16,445,"SV DK TC",280,70,MAU_XAM,MAU_DEN,20,30,22);
    taobutton(16,520,"Diem LTC",280,70,MAU_XAM,MAU_DEN,20,30,23);
    taobutton(16,595,"Sinh Vien",280,70,MAU_XAM,MAU_DEN,20,30,24);
}


void sinhvien_it2()
{   
	setbkcolor(MAU_TRANG);
  	setcolor(MAU_DEN);
  	
  	taobarde1(315,15,1520,260);
	taobarde1(315,270,1520,780);
  	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,50,"MA LTC",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(460,50,830,80);
    
    taobutton_t(860,50,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,50,1340,80);
    
    taobutton_t(330,100,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(510,100,830,130);
    
    taobutton_t(860,100,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,100,1340,130);
    
    taobutton_t(330,150,"NHOM",130,30,MAU_XAM,MAU_DEN,20,5);
   	tao_o(460,150,830,180);
    
    
    taobutton(630,210,"SAVE",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton(770,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(1070,210,"NEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	
	int sldong=15;
	int slcot=5;
	int mangdodai_diem[]={0,80,350,245,245,225};
	int chieu_cao=30;
	char diem[][50]={"","STT","MSSV","HO","TEN","DIEM TB"};
	taobang(325,280,chieu_cao,mangdodai_diem,slcot,sldong,diem,10,5);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
}


void diemltc_it2()
{
	sinhvien_it2();
}

void loptc_it2()
{
	setbkcolor(MAU_TRANG);
	
	taobarde1(315,15,1520,260);
	taobarde1(315,270,1520,780);
	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,40,"MA LTC",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(460,40,830,70);
    
    taobutton_t(860,40,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,40,1340,70);
    
    taobutton_t(330,90,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(510,90,830,120);
    
    taobutton_t(860,90,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,90,1340,120);
    
   	taobutton_t(330,140,"SV MAX",130,30,MAU_XAM,MAU_DEN,20,5);
   	tao_o(460,140,830,170);
   	
   	taobutton_t(860,140,"SV MIN",130,30,MAU_XAM,MAU_DEN,20,5);
	tao_o(990,140,1340,170);
	
	taobutton_t(330,190,"NHOM",130,30,MAU_XAM,MAU_DEN,20,5);
	tao_o(460,190,600,220);

	//save//cancle//delete//new//
	taobutton(630,210,"SAVE",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	taobutton(770,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(1070,210,"NEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,313);
	
	int sldong=15;
	int slcot=7;
	int mangdodai_ltc[]={0,80,200,173,173,173,173,173};
	int chieu_cao=30;
	char ltc[][50]={"","STT","MLCC","MMH","NIEN KHOA","HOC KY","NHOM","SL SV"};
	taobang(325,280,chieu_cao,mangdodai_ltc,slcot,sldong,ltc,10,5);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
}

void svdk_tc()
{
	setbkcolor(MAU_TRANG);
	
	taobarde1(315,15,1520,260);
	taobarde1(315,270,1520,780);
	
	taobutton_t(330,50,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(510,50,830,80);
    
    taobutton_t(860,50,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,50,1340,80);
    
    taobutton_t(330,100,"MSSV",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(460,100,830,130);
    
    taobutton_t(860,100,"HO TEN",130,30,MAU_XAM,MAU_DEN,20,5);
    tao_o(990,100,1340,130);
    
    taobutton(770,210,"SAVE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
	taobutton(920,210,"CANCLE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,313);
    
    int sldong=15;
	int slcot=7;
	int mangdodai_dk[]={0,80,200,173,173,173,173,173};
	int chieu_cao=30;
	char svdk[][50]={"","STT","MLTC","MMH","NHOM","SL SV","CL","CHON"};
	taobang(325,280,chieu_cao,mangdodai_dk,slcot,sldong,svdk,10,5);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,00);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,00);
    
}
void xulyltc(int &luu_id)
{
	
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
			case 21://sinh vien
			manhinhchinh2();
				loptc_it2();
				break;
			case 22://lop hoc
			manhinhchinh2();
			svdk_tc();
				break;
			case 23:
				manhinhchinh2();
				diemltc_it2();
				outtextxy(1000,500,"a");
				break;
			case 24:
				manhinhchinh2();
				sinhvien_it2();
			default : 
			manhinhchinh2();
			break;
		}
		delay(0.001);
		
}
}

