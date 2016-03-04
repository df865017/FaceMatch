#ifndef Mouth_H
#define Mouth_H
#include"baseoperate.h"
class Mouth:public BaseOperate
{
public:
	Mouth()
	{
		Pmouth=this;
			//mouth picture
	    pictureMouth=".//face_part//mouth.png";
	    mat_mouth=imread(pictureMouth, 1);

		mouth_mask_window="mouthMask Image";
	    pictureMouth_mask=".//face_part//mask//mouth_mask.png";
		mat_mouth_mask=imread(pictureMouth_mask,1);
	}
	~Mouth()
	{
	}
	//1.0
	void MousePoint();
	static void on_mouse(int event,int x,int y,int flags,void *ustc);  //¾²Ì¬»Øµ÷º¯Êý
	//2.0
	void InFileMouth();
	//3.0
	void Mask();
	//4.0
	void Affain();



private:
	static Mouth* Pmouth;

	char* pictureMouth;
	char* mouth_window ;
	char* pictureMouth_mask;
	char* mouth_mask_window;
	Mat mat_mouth,mat_mouth_mask;
	Mat warp_mouth[22];
//4.0
	void PasteMouth();
	void GetAffain();
};

#endif
