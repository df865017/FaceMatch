#ifndef EyeBrow_H
#define EyeBrow_H
#include"baseoperate.h"
class EyeBrow:public BaseOperate
{

public:
	EyeBrow()
	{
		Peyebrow=this;
		//give the first price
		pictureLeftEyebrow=".//face_part//left_eyebrow.png";
	    mat_lefteyebrow=imread(pictureLeftEyebrow, 1);

		pictureRightEyebrow=".//face_part//right_eyebrow.png";
	    mat_righteyebrow=imread(pictureRightEyebrow, 1);	


	}
	~EyeBrow()
	{
	}
	//1.0
	void LMousePoint();
	void RMousePoint();

	static void on_mouse(int event,int x,int y,int flags,void *ustc);  //¾²Ì¬»Øµ÷º¯Êý
	//2.0
	void LInFileEyebrow();
	void RInFileEyebrow();
	//3.0

	void LMask();
	void RMask();
	//4.0

	void LAffain();
	void RAffain();
private:
	static EyeBrow * Peyebrow;
	 char* lefteyebrow_window;
	 char* pictureLeftEyebrow;
	 char* pictureRightEyebrow;
	 char* righteyebrow_window ;
	 Mat mat_lefteyebrow;
	 Mat mat_righteyebrow;
	 //1.0
	void MousePoint();
	//3.0
	void Mask();
	//4.0
	void Affain();
};

#endif
