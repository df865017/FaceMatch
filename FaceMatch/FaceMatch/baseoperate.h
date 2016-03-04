#ifndef BaseOperate_H
#define BaseOperate_H
#include"filedata.h"
class Filedata;
class BaseOperate:public FileData
{
public:
	BaseOperate()
	{
			public_window="Public Image";
			warp_mat.create(2,3,CV_32F);
	}
	~BaseOperate()
	{}
	//1.0
	void InputFile();

	//2.0
	virtual void MousePoint()=0;
	//3.0
	void GrayThreshold(Mat &image,int max_value);
	virtual void Mask()=0;
	//4.0
	void CopyImage(Mat &src, Mat &dst);
	virtual void Affain()=0;
	int PointX(Mat warp_mat,int x,int y);
	int PointY(Mat warp_mat,int x,int y);
	////5.0
    void ShowFace();
	void Display(Mat & image, char* name);

	char* public_window;  //Public variables in child class  
	char* face_filename;  //Public variables in child class
	 Mat face_src;		 //Public variables in child class	  
	 Mat face_dst;       //Public variables in child class
	 Mat mat_public;      //Public variables in child class
	 Mat warp_mat;        //Public variables in child class
	 ofstream face_fout;  //Public variables in child class
	 ifstream face_fin;   //Public variables in child class
	 FileData face_data;
	 FileData file_data;	

private:
	Mat mat_gray;  
	//	



};

#endif
