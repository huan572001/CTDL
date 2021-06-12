/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/ 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include "dssv.h"
#include "monhoc.h"
#include "loptinchi.h"

char tk[7]="";
char mk[7]="";


void xuly();



void taobangmenu()
{
	setmapid();
	setbkcolor(MAU_TRANG);
	cleardevice();
   	
   	
	setcolor(MAU_DEN);
	rectangle(5,5,CUASO_NGANG,CUASO_DOC);
	rectangle(10,10,300,320);
	rectangle(310,10,1525,790);
	rectangle(10,325,300,790);
					    
	taobutton(16,16,"MON HOC",280,70,MAU_XAM,MAU_DEN,20,30,1);
	taobutton(16,91,"LOP TIN CHI",280,70,MAU_XAM,MAU_DEN,20,30,2);
	taobutton(16,166,"SINH VIEN",280,70,MAU_XAM,MAU_DEN,20,30,3);
	taobutton(16,241,"DANG XUAT",280,70,MAU_XAM,MAU_DEN,20,30,4);
											    
	taobutton_t(70,330,"CHUC NANG",20,10,MAU_XANHLA,MAU_XANHNON,0,0);
}

void dangnhap()
{	
	
	setmapid();
	setbkcolor(MAU_TRANG);
   	cleardevice();
   	
	setcolor(MAU_DEN);
	setlinestyle(0,0,3);
	tao_o(510,200,1020,525);
	setlinestyle(0,0,1);
	tao_o(520,276,1010,445);
	taobutton_t(610,220,"DANG NHAP HE THONG",0,0,MAU_TRANG,MAU_DEN,0,0);
	
	taobutton_t(530,310,"Tai khoan",190,30,MAU_XAM,MAU_DEN,30,5);
	tao_o(720,310,1000,340);
	
	taobutton_t(530,380,"Mat khau",190,30,MAU_XAM,MAU_DEN,30,5);	
	tao_o(720,380,1000,410);
	taobutton_k(550,460,"DANG NHAP",180,40,MAU_XANHDUONG,MAU_TRANG,1000);
	taobutton_k(850,460,"THOAT",120,40,MAU_DO,MAU_TRANG,1001);
	
	taotextinput(720,310,1000,340,"",1002);
	taotextinput(720,380,1000,410,"",1003);
	
	int x=-1, y=-1;
	while(true){
		int id=0;

		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		switch(id){
			case 1000:
				taobangmenu();
				xuly();
				break;
			case 1001:
				exit(0);
				break;
			case 1002:
				Nhap(725,315,tk);
				break;
			case 1003:
				Nhap(725,385,mk);
				break;
			
		}
	}
		
		delay(0.001);
}
}


void xuly()
{
	int luu_id=0;
	int x=-1, y=-1;
	while(true){
		
		
		int id=0;
		id=luu_id;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		
		switch(id){
			case 1:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
  			 	cleardevice();
				taobangmenu();
				xulymonhoc(luu_id);
				break;
			case 2:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
  			 	cleardevice();
				taobangmenu();
				xulyltc(luu_id);
				break;
			case 3:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
   				cleardevice();
  			 	taobangmenu();
				xulydssv(luu_id);
				break;
			case 4:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
   				cleardevice();
				dangnhap();
				
				break;

		}
		delay(0.001);
}
}



int main(int argc, char *argv[])
{
	setmapid();
	// now, you can run project
	initwindow(CUASO_NGANG,CUASO_DOC);			// init window graphics
	setbkcolor(MAU_TRANG);					// set background
   	cleardevice();
   	
	//tao o dang nhap
	
	dangnhap();
	
			
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}



