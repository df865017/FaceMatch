#ifndef Eye_H
#define Eye_H
#include"baseoperate.h"
class Eye:public BaseOperate
{
public:
	Eye()
	{
		Peye=this;
		//give the first price
	    //lefteye picture
	    pictureLeftEye=".//face_part//left_eye.png";
	    mat_lefteye=imread(pictureLeftEye, 1);

		//righteye picture
	    pictureRightEye=".//face_part//right_eye.png";
	    mat_righteye=imread(pictureRightEye, 1);

	}
	~Eye()
	{
	}
	//1.0
	void LMousePoint();
	void RMousePoint();
	static void on_mouse(int event,int x,int y,int flags,void *ustc);  //¾²Ì¬»Øµ÷º¯Êý
	//2.0
	void LInFileEye();
	void RInFileEye();
	//3.0

	void LMask();
	void RMask();
	//4.0

	void LAffain();
	void RAffain();

private:
	static Eye* Peye;
	char* pictureLeftEye;
	char* lefteye_window;
	char* pictureRightEye;
	char* righteye_window;

	 Mat mat_lefteye;
	 Mat mat_righteye;
	 //1.0
	 void MousePoint();
	 //3.0
	 void Mask();
	 //4.0
	 void Affain();
};

#endif
