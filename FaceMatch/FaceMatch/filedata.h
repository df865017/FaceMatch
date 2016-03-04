#ifndef FileData_H
#define FileData_H
//define the head file
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include <fstream>
using namespace cv;
using namespace std;

class FileData
{
public:
	FileData()
	{
		//give the price
	faceframe.rows=12;faceframe.cols=2;
	lefteyebrow.rows=5;lefteyebrow.cols=2;
	righteyebrow.rows=5;righteyebrow.cols=2;
	nose.rows=9;nose.cols=2;
	lefteye.rows=6;lefteye.cols=2;
	righteye.rows=6;righteye.cols=2;
	mouth.rows=18;mouth.cols=2;

	}
	~FileData()
	{}
	//use the fuction give the price
	//1.faceframe 12
	void SetFaceFrame(double point[12][2])
	{
		for(int i=0;i<faceframe.rows;i++)
		{
			faceframe.point[i][0] =point[i][0];
			faceframe.point[i][1] =point[i][1];
		
		}
	}
	void SetFaceFrame(double &price,int i,int j)
	{

			faceframe.point[i][j] =price;
	}
	double GetFaceFrame(int i,int j)
	{
	 return faceframe.point[i][j];
	}
	int GetFaceFrameRows()
	{
	 return faceframe.rows;
	}
   //2.lefteyebrow 5
	void SetLeftEyebrow(double point[5][2])
	{
		for(int i=0;i<lefteyebrow.rows;i++)
		{
			lefteyebrow.point[i][0] =point[i][0];
			lefteyebrow.point[i][1] =point[i][1];
		
		}
	}
	void SetLeftEyebrow(double &price,int i,int j)
	{
			lefteyebrow.point[i][j] =price;
	}
	double GetLeftEyebrow(int i,int j)
	{
	 return lefteyebrow.point[i][j];
	}
	int GetLeftEyebrowRows()
	{
	 return lefteyebrow.rows;
	}
   //3.righteyebrow  5
	void SetRightEyebrow(double point[5][2])
	{
		for(int i=0;i<righteyebrow.rows;i++)
		{
			righteyebrow.point[i][0] =point[i][0];
			righteyebrow.point[i][1] =point[i][1];
		
		}
	}
	void SetRightEyebrow(double &price,int i,int j)
	{
			righteyebrow.point[i][j] =price;
	}
	double GetRightEyebrow(int i,int j)
	{
	 return righteyebrow.point[i][j];
	}
	int GetRightEyebrowRows()
	{
	 return righteyebrow.rows;
	}   
	//4.nose 9
	void SetNose(double point[9][2])
	{
		for(int i=0;i<nose.rows;i++)
		{
			nose.point[i][0] =point[i][0];
			nose.point[i][1] =point[i][1];
		
		}
	}
	void SetNose(double &price,int i,int j)
	{
			nose.point[i][j] =price;
	}
	double GetNose(int i,int j)
	{
	 return nose.point[i][j];
	}
	int GetNoseRows( )
	{
	 return nose.rows;
	}
   //5.lefteye 6
	void SetLeftEye(double point[6][2])
	{
		for(int i=0;i<lefteye.rows;i++)
		{
			lefteye.point[i][0] =point[i][0];
			lefteye.point[i][1] =point[i][1];
		
		}
	}
	void SetLeftEye(double &price,int i,int j)
	{
			lefteye.point[i][j] =price;
	}
	double GetLeftEye(int i,int j)
	{
	 return lefteye.point[i][j];
	}
	int GetLeftEyeRows( )
	{
	 return lefteye.rows;
	}
   //6.righteye 6
	void SetRightEye(double point[6][2])
	{
		for(int i=0;i<righteye.rows;i++)
		{
			righteye.point[i][0] =point[i][0];
			righteye.point[i][1] =point[i][1];
		
		}
	}
	void SetRightEye(double &price,int i,int j)
	{
			righteye.point[i][j] =price;
	}
	double GetRightEye(int i,int j)
	{
	 return righteye.point[i][j];
	}
	int GetRightEyeRows( )
	{
	 return righteye.rows;
	}

	//7.mouth  18
	void SetMouth(double point[18][2])
	{
		for(int i=0;i<mouth.rows;i++)
		{
			mouth.point[i][0] =point[i][0];
			mouth.point[i][1] =point[i][1];
		
		}
	}
	void SetMouth(double &price,int i,int j)
	{
			mouth.point[i][j] =price;
	}
	double GetMouth(int i,int j)
	{
	 return mouth.point[i][j];
	}
	int GetMouthRows( )
	{
	 return mouth.rows;
	}
	void OutMouth()
	{
		for(int i=0;i<mouth.rows;i++)
	 cout<<mouth.point[i][0]<<" "<<mouth.point[i][1]<<endl;
	}
	//
	//virtual void InputFile()=0;
	//virtual void ChangePicture(char* range, int order)=0;
	//virtual void ReadPicture()=0;

typedef struct faceframe
{
	double point[12][2];
	//add 0 at every point
	int rows;int cols;
}FaceFrame;

typedef struct lefteyebrow
{
	double point[5][2];
//add 12 at every point
	int rows;int cols;

}LeftEyeBrow;

typedef struct righteyebrow
{
	double point[5][2];
//add 17 at every point
	int rows;int cols;

}RightEyeBrow;


typedef struct nose
{
	double point[9][2];
	//add 22 at every point
	int rows;int cols;

}Nose;

typedef struct lefteye
{
	double point[6][2];
	//add 31 at every point
	int rows;int cols;
}LeftEye;

typedef struct righteye
{
	double point[6][2];
	//add 37 at every point 
	int rows;int cols;
}RightEye;


typedef struct mouth
{
	double point[18][2];
	//add 43 at every point
	int rows;int cols;

}Mouth;
	static Mat file_src; //Public variables in child class
	static Mat file_dst; //Public variables in child class
	static char* file_filename;
	static char* file_picturename;
		


private:



	 //it is easy to access the object
	FaceFrame faceframe;
	LeftEyeBrow lefteyebrow;
	RightEyeBrow righteyebrow;
	Nose nose;
	LeftEye lefteye;
	RightEye righteye;
	Mouth mouth;
};


#endif