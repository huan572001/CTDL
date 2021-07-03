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
#include "cautrucmonhoc.h"
#include "cautrucloptinchi.h"
#include "cautrucsinhvien.h"
#include "dh_svdk.h"
const char AD[10]="ADMIN";
const char Pass[10]="GV";
const char passsv[10]="SV";
bool ktdn(NodeSinhVien *first,SinhVien &SV)//kiem tra dang nhap sinh vien 
{
	
	for (NodeSinhVien *k=first ; k!=NULL ; k=k->next)
	{
		if ((stricmp(SV.mSV,k->sv.mSV)==0) && ((stricmp(SV.sdt,passsv)==0)))
		{
			SV=k->sv;
			return true;
		}
	
		}
		return false;	
}
void xuly_svdk(Node *root,DSloptinchi &dsltc,NodeSinhVien *&first,SinhVien SV);// sinh vien dang ky
void xuly(Node *root,DSloptinchi &dsltc,NodeSinhVien *&first);// admin

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


///////////////////////////// gv ////////////////////////

void dangnhap(Node *root,DSloptinchi &dsltc,NodeSinhVien *&first)
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
	SinhVien SV;
	int luu_id=0;
	int x=-1, y=-1;
	int id=0;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
			}
		switch(id){
			
			case 1000: 
				if ((stricmp(SV.mSV,AD)==0) && ((stricmp(SV.sdt,Pass)==0)))//dang nhap giang vien
				{
				taobangmenu();
				xuly(root,dsltc,first);
				}
				else if (ktdn(first,SV)==true) 
				{
					xuly_svdk(root,dsltc,first,SV);
				}
				else//nhap lai
				{	
				outtextxy(700,420,"Thong tin sai! Moi nhap lai");
				}				
				break;
			case 1001:
				exit(0);
				break;
			case 1002:
				NhapInHoa(725,315,id,SV.mSV);
				break;
			case 1003:
				NhapInHoa(725,385,id,SV.sdt);
				break;			
		}	
		delay(0.001);
    }
}


void xuly(Node *root,DSloptinchi &dsltc,NodeSinhVien *&first)
{
	int luu_id=0;
	int x=-1, y=-1;
	int id=0;
	while(true){					
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
				xulymonhoc(luu_id,root);
				break;
			case 2:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
  			 	cleardevice();
				taobangmenu();
				xulyltc(luu_id,dsltc,first);
//				XuLythemLTC(dsltc,luu_id);
				break;
			case 3:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
   				cleardevice();
  			 	taobangmenu();
				xulydssv(first,luu_id);
				break;
			case 4:
				luu_id=0;
				setmapid();
				setbkcolor(MAU_TRANG);
   				cleardevice();
				dangnhap(root,dsltc,first);
				
				break;

		}
		delay(0.001);
}
}

/////////////////////  sv   /////////////
void xuly_svdk(Node *root,DSloptinchi &dsltc,NodeSinhVien *&first,SinhVien SV)
{
//	setbkcolor(MAU_TRANG);
	int x=-1, y=-1;
	int id=2;
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(id){
			case 2:
				taobangmenu();
				xuly_dohoa_svdk(id,dsltc,first,SV);
			case 4:
				setmapid();
				setbkcolor(MAU_TRANG);
   				cleardevice();
				dangnhap(root,dsltc,first);	
				break;
			
		}
		delay(0.001);
	}
	
}

int main(int argc, char *argv[])
{
	Node *root=NULL;
	DSloptinchi dsltc;
	NodeSinhVien *first=NULL;
	dsltc.soluong=0;
	doc_tu_file_vao_cay("monhoc.Dat",root);
	doc_tu_file_vao_LTC("Loptinchi.Dat",dsltc);
	doc_tu_file_vao_dslkd("Sinhvien.Dat",first);
	setmapid();
	// now, you can run project
	initwindow(CUASO_NGANG,CUASO_DOC);			// init window graphics
	setbkcolor(MAU_TRANG);					// set background
   	cleardevice();
   	
	//tao o dang nhap
	
	dangnhap(root,dsltc,first);
	
			
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}



