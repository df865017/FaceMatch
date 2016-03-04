#ifndef Nose_H
#define Nose_H
#include"baseoperate.h"
class Nose:public BaseOperate
{
public:
	Nose()
	{
		Pnose=this;
		//give the first price
		//nose picture
	    pictureNose=".//face_part//nose.png";
	    mat_nose=imread(pictureNose, 1);

		nose_mask_window="NoseMask Image";
	    pictureNose_mask=".//face_part//mask//nose_mask.png";
		mat_nose_mask=imread(pictureNose_mask,1);

	}
	~Nose()
	{
	}
	//1.0
	void MousePoint();
	static void on_mouse(int event,int x,int y,int flags,void *ustc);  //¾²Ì¬»Øµ÷º¯Êý
	//2.0
	void InFileNose();

	//3.0
	void Mask();
	//4.0
	void Affain();
private:
	static Nose* Pnose;

	char* pictureNose;
	char* nose_window ;
	char* pictureNose_mask;
	char* nose_mask_window;
	Mat mat_nose,mat_nose_mask;
	Mat warp_nose[12];
//4.0
	void PasteNose();
	void GetAffain();
};

#endif
