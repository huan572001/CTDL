#pragma once 
#include <string.h>
#include <winbgim.h> 
#include "funtion.h"
#include "define.h"
#include"cautrucloptinchi.h"
void manhinhchinh2()
{
	setbkcolor(MAU_TRANG);   	
	setcolor(MAU_DEN);
	
    rectangle(5,5,CUASO_NGANG,CUASO_DOC);
    rectangle(10,10,300,320);
    rectangle(310,10,1525,790);
    rectangle(10,325,300,790);
    
    taobutton(16,370,"Lop TC",280,70,MAU_XAM,MAU_DEN,20,30,21);
    taobutton(16,445,"Diem LTC",280,70,MAU_XAM,MAU_DEN,20,30,23);
    taobutton(16,520,"Sinh Vien",280,70,MAU_XAM,MAU_DEN,20,30,24);
}

void Bang_sinhvien_it2(LopTinChi ltc,int trangso)
{
		taobarde(315,270,1520,780);
		int sldong=15;
	int slcot=5;
	int mangdodai_diem[]={0,80,350,245,245,225};
	int chieu_cao=30;
	char diem[][50]={"","STT","MSSV","HO","TEN","DIEM TB"};
	taobang(325,280,chieu_cao,mangdodai_diem,slcot,sldong,diem,10,5,100,trangso);
			
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
	char tam[3];
	chuyen_so_thanh_chuoi(trangso,tam);
	taobutton_t(850,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	outtextxy(870,740,"/");	
	chuyen_so_thanh_chuoi(soluongSVDK(ltc.dsSVDK.first)/14+1,tam);
	taobutton_t(890,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);	
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,71);
}
void sinhvien_it2(LopTinChi ltc,int trangso)
{   
	setbkcolor(MAU_TRANG);
  	setcolor(MAU_DEN);
  	
  	taobarde(315,15,1520,260);
  	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,50,"MA LTC",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(460,50,830,80,"",111);
    
    taobutton_t(860,50,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(990,50,1340,80,"",112);
    
    taobutton_t(330,100,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(510,100,830,130,"",113);
    
    taobutton_t(860,100,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(990,100,1340,130,"",114);
    
    taobutton_t(330,150,"NHOM",130,30,MAU_XAM,MAU_DEN,20,5);
   	taotextinput(460,150,830,180,"",115);
    
	taobutton(770,210,"SEARCH",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,260);
	
	Bang_sinhvien_it2(ltc,trangso);
}
void loptc_it2(DSloptinchi &ds,int trangso)
{
	
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	
	taobarde(315,15,1520,260);
	taobarde(315,270,1520,780);
	
	rectangle(315,15,1520,260);
    rectangle(315,270,1520,780);
    
    taobutton_t(330,40,"MA LTC",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(460,40,830,70,"",41);
    
    taobutton_t(860,40,"MA MH",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(990,40,1340,70,"",42);
    
    taobutton_t(330,90,"NIEN KHOA",180,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(510,90,830,120,"",43);
    
    taobutton_t(860,90,"HOC KY",130,30,MAU_XAM,MAU_DEN,20,5);
    taotextinput(990,90,1340,120,"",44);
    
   	taobutton_t(330,140,"SV MAX",130,30,MAU_XAM,MAU_DEN,20,5);
   	taotextinput(460,140,830,170,"",45);
   	
   	taobutton_t(860,140,"SV MIN",130,30,MAU_XAM,MAU_DEN,20,5);
	taotextinput(990,140,1340,170,"",46);
	
	taobutton_t(330,190,"NHOM",130,30,MAU_XAM,MAU_DEN,20,5);
	taotextinput(460,190,600,220,"",47);
	//save//cancle//delete//new//
	taobutton(630,210,"ADD",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,343);
	taobutton(770,210,"SAVE",140,30,MAU_XANHDUONG,MAU_TRANG,30,5,344);
	taobutton(920,210,"DELETE",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,345);
	taobutton(1070,210,"UPDATE",140,30,MAU_XANHDUONG,MAU_TRANG,30,5,347);
	taobutton(1220,210,"VIEW",130,30,MAU_XANHDUONG,MAU_TRANG,30,5,346);
	
	int sldong=15;
	int slcot=7;
	int mangdodai_ltc[]={0,80,200,173,173,173,173,173};
	int chieu_cao=30;
	char ltc[][50]={"","STT","MLCC","MMH","NIEN KHOA","HOC KY","NHOM","SL SV"};
	taobang(325,280,chieu_cao,mangdodai_ltc,slcot,sldong,ltc,10,5,200,trangso);	
//	Xuatds2(ds);
	Xuatds(405,280,ds,mangdodai_ltc);	
	taobutton(330,740,"PREV",130,30,MAU_XAM,MAU_DEN,30,5,70);
	char tam[3];
    chuyen_so_thanh_chuoi(trangso,tam);
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	taobutton_t(850,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	outtextxy(870,740,"/");
	chuyen_so_thanh_chuoi(ds.soluong/14+1,tam);
	taobutton_t(890,740,tam,20,20,MAU_TRANG,MAU_DEN,0,0);
	taobutton(1370,740,"NEXT",130,30,MAU_XAM,MAU_DEN,30,5,70);
}
void xuly_Ds_SVDK(DSloptinchi &ds,LopTinChi ltc,int &luu_id,NodeSinhVien *first)
{
	int x=-1, y=-1;
	int id=0;
	int trangso=1;
	manhinhchinh2();
	taobutton(16,520,"Sinh Vien",280,70,MAU_XAM1,MAU_DEN,20,30,24);
	sinhvien_it2(ltc,trangso);
	taobutton(920,210,"BACK",140,30,MAU_XANHDUONG,MAU_TRANG,15,5,261);
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	char maltc[6]="";
	char hocky[4]="";
	char nhom[4]="";
	XuatDanhSachSVDK(410,315,ltc.dsSVDK.first,first,trangso);
	chuyen_so_thanh_chuoi(ltc.maLTC,maltc);
	outtextxy(465,55,maltc);
	outtextxy(995,55,ltc.maMH);
	outtextxy(515,105,ltc.nienKhoa);
	chuyen_so_thanh_chuoi(ltc.hocKy,hocky);
	outtextxy(995,105,hocky);
	chuyen_so_thanh_chuoi(ltc.nhom,nhom);
	outtextxy(465,155,nhom);
	while(true){
		
		//Bat chuot
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id>=21&&id<=24)
		{
			luu_id=id;
			break;
		}
		switch(id)
		{
			case 111:
 		  	  	Nhapso(465,55,id,maltc,7);
 		  	  	ltc.maLTC=chuyen_chuoi_thanh_so(maltc);
 		    	break;
 		    case 112:
    			NhapInHoa(995,55,id,ltc.maMH);
    			break;
    		case 113:
    			Nhapso(515,105,id,ltc.nienKhoa,10);
    			break;
    		case 114:
    			Nhapso(995,105,id,hocky,4);
    			ltc.hocKy=chuyen_chuoi_thanh_so(hocky);
    			break;
    		case 115:
//    			chuyen_so_thanh_chuoi(ltc.nhom,nhom);
    			Nhapso(465,155,id,nhom,4);
//    			ltc.nhom=chuyen_chuoi_thanh_so(nhom);
    			break;
    		case 260://tim kiem
    			for(int i=0;i<ds.soluong;i++)
    			{
    				if(ds.DSltc[i].maLTC==ltc.maLTC)
    				{
    					Bang_sinhvien_it2(ds.DSltc[i],trangso);
    					XuatDanhSachSVDK(410,315,ds.DSltc[i].dsSVDK.first,first,trangso);
    					ltc=ds.DSltc[i];
					}
				}
    			id=0;
    			break;
    		case 261://back
    			id=id_LTC;
    			break;
    		case 70:
				if(trangso>1)
				{
					trangso--;
					Bang_sinhvien_it2(ltc,trangso);
					XuatDanhSachSVDK(410,315,ltc.dsSVDK.first,first,trangso);
				}	
				id=0;
				break;
			case 71:
				
    			if (soluongSVDK(ltc.dsSVDK.first)/14>(trangso-1))
				{
					trangso++;
					Bang_sinhvien_it2(ltc,trangso);
					XuatDanhSachSVDK(410,315,ltc.dsSVDK.first,first,trangso);
				}
				id=0;
				break;
		}
		delay(0.001);		
	}
}
void XuLythemLTC(DSloptinchi &ds,int &luu_id,NodeSinhVien *first,Node *root)
{
//	setmapid();
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int trangso=1;
	loptc_it2(ds,trangso);
	int x=-1, y=-1;
	int KT=0;
	LopTinChi ltc;
	
	char maLTC[6]="";
	char hocKy[2]="";
	char nhom[2]="";
	char SVmin[4]="";
	char SVmax[4]="";
	int id=0;
	if(ds.soluong==0)
	{
		ltc.maLTC=rand()%(9999+1-1000);
		chuyen_so_thanh_chuoi(ltc.maLTC,maLTC);
	}
	while(true){
		
		//Bat chuot
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id>=21&&id<=24)//thoat ra vào chuc nang khac
		{
			luu_id=id;
			break;
		}			
		outtextxy(465,45,maLTC);
		outtextxy(995,45,ltc.maMH);
		outtextxy(515,95,ltc.nienKhoa);
		outtextxy(995,95,hocKy);
		outtextxy(465,145,SVmax);
		outtextxy(995,145,SVmin);
		outtextxy(465,195,nhom);
		if(ds.soluong!=0&&luu_id<200||luu_id>214)
		{
			
			ltc.maLTC=ds.DSltc[ds.soluong-1].maLTC+1;
			chuyen_so_thanh_chuoi(ltc.maLTC,maLTC);
		}
		switch(id)
		{			
			case 42:
				if(luu_id<200||luu_id>214)
					NhapInHoa(995,45,id,ltc.maMH);//nhap ten ma mon hoc
				break;
			case 43:
				if(luu_id<200||luu_id>214)
				Nhapso(515,95,id,ltc.nienKhoa,10);//nhap so tc lt
				break;
			case 44:
				if(luu_id<200||luu_id>214)
				{
					Nhapso(995,95,id,hocKy,3);//nhap so tc th
					ltc.hocKy=chuyen_chuoi_thanh_so(hocKy);//chuyen chuoi thanh so gan lai vao MH
				}
				
				break; 
			case 45:
				Nhapso(465,145,id,SVmax,5);//nhap ma mon hoc
				ltc.maxsv=chuyen_chuoi_thanh_so(SVmax);
				break;
			case 46:
				Nhapso(995,145,id,SVmin,5);//nhap ma mon hoc
				ltc.minsv=chuyen_chuoi_thanh_so(SVmin);
				break;
			case 47:
				if(luu_id<200||luu_id>214)
				{
					Nhapso(465,195,id,nhom,2);//nhap ma mon hoc
					ltc.nhom=chuyen_chuoi_thanh_so(nhom);	
				}			
				break;
			case 343://add
				KT=0;
				KT_MMH(root,KT,ltc.maMH);
				if(KT==0)
				{
					outtextxy(680,180,"khong ton tai ma mon hoc!");	
					id=0;
				}	
				else if(ltc.minsv>ltc.maxsv)
				{
					outtextxy(680,180,"SVmax >= SVmin!");
					id=0;
				}
				else if(KT_nhap_LTC(ltc)==false)
				{
					outtextxy(680,180,"Khong duoc de trong!");
					id=0;
				}
				else if(KT_LTC_chung(ds,ltc.maLTC)==false)
				{
					outtextxy(680,180,"ma lop tin chi bi trung!");
					id=0;
				}
				else
				{
					NhapDSLopTinChi(ds,ltc);
					WriteFileLTC("Loptinchi.Dat",ltc,ds.Time[ds.soluong-1]);
					loptc_it2(ds,trangso);
					outtextxy(680,180,"them thanh cong.");
					id=2;
				}
				break;
			case 344://save
				KT=0;
				KT_MMH(root,KT,ltc.maMH);
				if(KT==0)
				{
					outtextxy(680,180,"khong ton tai ma mon hoc!");	
					id=0;
				}	
				else if(ltc.minsv>ltc.maxsv)
				{
					
					outtextxy(680,180,"SVmax >= SVmin!");
					id=0;
				}
				else if(KT_nhap_LTC(ltc)==false)
				{
					outtextxy(680,180,"Khong duoc de trong!");
					id=0;
				}
				else
				{
					chinh_Sua(ds,ltc);
					remove("Loptinchi.dat");
					vietLTCvaofile(ds);
					outtextxy(680,180,"chinh sua thanh cong.");
					id=2;
				}

				break;
			case 345://delete
				Xoa(ds,luu_id-201);
				remove("Loptinchi.dat");
				vietLTCvaofile(ds);
				id=2;
				break;
			case 346://view
				if(luu_id>200&&luu_id<214)
				xuly_Ds_SVDK(ds,ltc,id,first);
				break;
			case 347:
				id=2;
				break;
			case 70:
				if(trangso>1)
				{
					trangso--;
					loptc_it2(ds,trangso);
				}	
				id=0;
				break;
			case 71:
    			if (ds.soluong/14>(trangso-1))
				{
				trangso++;
				loptc_it2(ds,trangso);
				}
				id=0;
				break;
		}
		if(id>200&&id<214)
		{
			loptc_it2(ds,trangso);//tao lai o nhap
			ltc=ds.DSltc[id-201+14*(trangso-1)];//201 vi mang bat dau tu 0
			chuyen_so_thanh_chuoi(ltc.maLTC,maLTC);//gan gia gia tri cho maLTC de xuat ra man hinh
			chuyen_so_thanh_chuoi(ltc.hocKy,hocKy);//gan gia gia tri cho hocKy de xuat ra man hinh
			chuyen_so_thanh_chuoi(ltc.nhom,nhom);//gan gia gia tri cho nhom de xuat ra man hinh
			chuyen_so_thanh_chuoi(ltc.minsv,SVmin);//gan gia gia tri cho SVmin de xuat ra man hinh
			chuyen_so_thanh_chuoi(ltc.maxsv,SVmax);//gan gia gia tri cho SVmax de xuat ra man hinh
			luu_id=id;//cap nhat luu id de bat ko cho nhap ma mon hoc
			id=0;
		}
		delay(0.001);
	}
}
void Nhap_diem_SV_ltc(int &luu_id,DSloptinchi &dsltc,NodeSinhVien *first)
{
	int x=-1, y=-1;
	int id=0;
	int trangso=1;
		LopTinChi ltc;
	sinhvien_it2(ltc,trangso);
		char maltc[6]="";
	char hocky[4]="";
	char nhom[4]="";
	char diem[4]="";
	int i;
	while(true){
		
		//Bat chuot
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = MapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (id<=4 && id>=1||id>=21&&id<=24)
		{
			luu_id=id;
			break;
		}
		switch(id)
		{
			case 111:
 		  	  	Nhapso(465,55,id,maltc,7);
 		  	  	ltc.maLTC=chuyen_chuoi_thanh_so(maltc);
 		    	break;
 		    case 112:
    			NhapInHoa(995,55,id,ltc.maMH);
    			break;
    		case 113:
    			Nhapso(515,105,id,ltc.nienKhoa,10);
    			break;
    		case 114:
    			Nhapso(995,105,id,hocky,4);
    			ltc.hocKy=chuyen_chuoi_thanh_so(hocky);
    			break;
    		case 115:
    			Nhapso(465,155,id,nhom,4);
    			ltc.nhom=chuyen_chuoi_thanh_so(nhom);
    			break;
    		case 260://tim kiem
    			
    			for(i=0;i<dsltc.soluong;i++)
    			{
    				if(dsltc.DSltc[i].hocKy==ltc.hocKy&&strcmp(dsltc.DSltc[i].maMH,ltc.maMH)==0&&dsltc.DSltc[i].nhom==ltc.nhom)
    				{
    					Bang_sinhvien_it2(dsltc.DSltc[i],trangso);
    					XuatDanhSachSVDK(410,315,dsltc.DSltc[i].dsSVDK.first,first,trangso);
    					ltc=dsltc.DSltc[i];
    					break;
					}
					if(i==dsltc.soluong-1)
					{
						outtextxy(680,180,"Khong ton Tai LTC!");
					}
				}
    			id=0;
    			break;
    		case 70:
				if(trangso>1)
				{
					trangso--;
					Bang_sinhvien_it2(ltc,trangso);
					XuatDanhSachSVDK(410,315,ltc.dsSVDK.first,first,trangso);
				}	
				id=0;
				break;
			case 71:
    			if (soluongSVDK(ltc.dsSVDK.first)/14>(trangso-1))
				{
					trangso++;
					Bang_sinhvien_it2(ltc,trangso);
					XuatDanhSachSVDK(410,315,ltc.dsSVDK.first,first,trangso);
				}
				id=0;
				break;
		}
		if(id>100&&id<114)
		{
			int j=0;
			for(NodeSVDK *k=dsltc.DSltc[i].dsSVDK.first;k!=NULL;k=k->next)
			{
				if(j==id-101+14*(trangso-1))
				{
					if(k->svdk.diem==0)
						strcpy(diem,"0");
					else
						chuyen_so_thanh_chuoi(k->svdk.diem,diem);
						Nhapso(1350,315+30*(id-101),id,diem,4);
						k->svdk.diem=chuyen_chuoi_thanh_so(diem);
						remove("Loptinchi.dat");
						vietLTCvaofile(dsltc);
				}
				j++;
			}
		}
		delay(0.001);		
	}
}
void xulyltc(int &luu_id,DSloptinchi &dsltc,NodeSinhVien *first,Node *root)
{
	
	int x=-1, y=-1;
	int id=21;
	manhinhchinh2();
	while(true){
		
		//Bat chuot
//		id=21;
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
//				loptc_it2(dsltc);
    			taobutton(16,370,"Lop TC",280,70,MAU_XAM1,MAU_DEN,20,30,21);
   
				XuLythemLTC(dsltc,id,first,root);
				break;
			case 23:
				manhinhchinh2();
				taobutton(16,445,"Diem LTC",280,70,MAU_XAM1,MAU_DEN,20,30,23);
   
				Nhap_diem_SV_ltc(id,dsltc,first);
				break;
			case 24:	
				LopTinChi ltc;
				xuly_Ds_SVDK(dsltc,ltc,id,first);
				break;
		}
//		XuLythemLTC(dsltc,id);
		delay(0.001);		
	}
}

