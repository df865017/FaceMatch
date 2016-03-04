#include"baseoperate.h"
#include<string.h>
//1.1 Input the filedata
void BaseOperate::InputFile() 
{
	ifstream fin;
	fin.open(file_filename, ios::in|ios::out);
	if(!fin) 
	{
	cout<<"error in open the file!"<<endl;
	return ;
	}
	
	int faceframenum=file_data.GetFaceFrameRows();
	int lefteyebrownum=file_data.GetLeftEyebrowRows();
	int righteyebrownum=file_data.GetRightEyebrowRows();
	int nosenum=file_data.GetNoseRows();
	int lefteyenum=file_data.GetLeftEyeRows();
	int righteyenum=file_data.GetRightEyeRows();
	int mouthnum=file_data.GetMouthRows();
     string s;  
     getline(fin,s);  //string.h
	 int count=0;
	 fin>>count;
	 //1.faceframe
	 double faceframe_point[12][2];
	for(int i=0;i<=faceframenum-1;i++)
	{
		
		fin>>faceframe_point[i][0]>>faceframe_point[i][1];

	}
	file_data.SetFaceFrame(faceframe_point);

	//2. lefteyebrow
	double lefteyebrow_point[5][2];
	for(int i=0;i<=lefteyebrownum-1;i++)
	{
		fin>>lefteyebrow_point[i][0]>>lefteyebrow_point[i][1];
	}
	file_data.SetLeftEyebrow(lefteyebrow_point);
	//3. righteyebrow
	double righteyebrow_point[5][2];
	for(int i=0;i<=righteyebrownum-1;i++)
	{
		fin>>righteyebrow_point[i][0]>>righteyebrow_point[i][1];
	}
	file_data.SetRightEyebrow(righteyebrow_point);
	//4. nose
	double nose_point[9][2];
	for(int i=0;i<=nosenum-1;i++)
	{
		fin>>nose_point[i][0]>>nose_point[i][1];
		//cout<<nose_point[i][0]<<" "<<nose_point[i][1]<<endl;
	}
	file_data.SetNose(nose_point);
	//5.lefteye
	double lefteye_point[6][2];
	for(int i=0;i<=lefteyenum-1;i++)
	{
		fin>>lefteye_point[i][0]>>lefteye_point[i][1];
	}
	file_data.SetLeftEye(lefteye_point);
	//6.righteye
	double righteye_point[6][2];
	for(int i=0;i<=righteyenum-1;i++)
	{
		fin>>righteye_point[i][0]>>righteye_point[i][1];
	}
	file_data.SetRightEye(righteye_point);
	//7.
	double mouth_point[18][2];
	for(int i=0;i<=mouthnum-1;i++)
	{
		fin>>mouth_point[i][0]>>mouth_point[i][1];
	}
	file_data.SetMouth(mouth_point);
	
	fin.close();

}
//2.1 on mouse point

//3.0 make a mask
//3.1 
void BaseOperate::GrayThreshold(Mat &image,int max_value)
{
	cvtColor( image, mat_gray,CV_RGB2GRAY );
	int max_BINARY_value=255;

	threshold(mat_gray,mat_gray,max_value,max_BINARY_value,CV_THRESH_BINARY);

	for (int y=0;y<mat_gray.rows;y++)
	{
		for(int x=0;x<mat_gray.cols;x++)
		{
			if((int)mat_gray.at<uchar>(y,x)==0)
			{
			image.at<Vec3b>(y,x)[0]=image.at<Vec3b>(y,x)[0];
			image.at<Vec3b>(y,x)[1]=image.at<Vec3b>(y,x)[1];
			image.at<Vec3b>(y,x)[2]=image.at<Vec3b>(y,x)[2];
			}
			else
			{
			image.at<Vec3b>(y,x)[0]=0;
			image.at<Vec3b>(y,x)[1]=0;
			image.at<Vec3b>(y,x)[2]=0;		
			}

		}		
	}


}

//4.1 copy the image
void BaseOperate::CopyImage(Mat &src, Mat &dst)
{
	dst= Mat::zeros( src.rows, src.cols, src.type() );
	src.copyTo(dst);
	return ;
}
//4.2 affain computer
int BaseOperate:: PointX(Mat warp_mat,int x,int y)
{

  return (int)( warp_mat.at<double>(0,0)*x+warp_mat.at<double>(0,1)*y+warp_mat.at<double>(0,2) );

}

int BaseOperate::PointY(Mat warp_mat,int x,int y)
{
	return (int)( warp_mat.at<double>(1,0)*x+warp_mat.at<double>(1,1)*y+warp_mat.at<double>(1,2) );
}

//5.1
void BaseOperate::ShowFace()
{
	char* source_window;
	source_window = "Source image";
	cv::namedWindow(source_window,CV_WINDOW_AUTOSIZE); 
	cvMoveWindow(source_window,0,0);
	imshow(source_window,file_dst);
    waitKey(0);
}
//5.2 
void BaseOperate::Display(Mat & image, char* name)
{
    cv::namedWindow(name,CV_WINDOW_AUTOSIZE); 
	imshow(name,image);
    waitKey(0);

}