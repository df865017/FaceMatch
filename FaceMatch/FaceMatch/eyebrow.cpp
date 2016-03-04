#include"eyebrow.h"
EyeBrow * EyeBrow::Peyebrow=NULL;   //give the first the price to Peyebrow
//1.0

void EyeBrow::LMousePoint()
{
			    //lefteyebrow picture
		face_filename=".//face_part//txt//lefteyebrow.txt";
		lefteyebrow_window="LeftEyeBrow Image";
				CopyImage(mat_lefteyebrow,mat_public);
				public_window=lefteyebrow_window;
		MousePoint();
}
//1.1
void EyeBrow::RMousePoint()
{
		    //righteyebrow picture
		face_filename=".//face_part//txt//righteyebrow.txt";
		righteyebrow_window="RightEyeBrow Image";
			CopyImage(mat_righteyebrow,mat_public);
			public_window=righteyebrow_window;
		MousePoint();

}
//1.2
void EyeBrow::MousePoint()
{
	
	//define the file
	face_fout.open(face_filename,ios::out|ios::app);
	if(!face_fout) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fout.close();
	return ;
	}
	//show the point
		cv::namedWindow(public_window,CV_WINDOW_AUTOSIZE); 
		cvMoveWindow(public_window,0,0);
	    cv::setMouseCallback(public_window,on_mouse,0);//
		cv::imshow(public_window,mat_public);
		cv::waitKey(0); 
	face_fout.close();
}
//1.3
void EyeBrow::on_mouse(int event,int x,int y,int flags,void *ustc)
{
	      if ( Peyebrow == NULL )
            return;
		            // 回调函数中调用非静态变量
		static Point pre_pt = (-1,-1);//初始坐标  
		static Point cur_pt = (-1,-1);//实时坐标  
		char temp[16];  


		if (event == CV_EVENT_LBUTTONDOWN)//左键按下，读取初始坐标，并在图像上该点处划圆  
		{  
			sprintf(temp,"(%d,%d)",y,x);  
			//sprintf(temp,"(%d,%d,%d)",image.at<Vec3b>(x,y)[0],image.at<Vec3b>(x,y)[1],image.at<Vec3b>(x,y)[2]); 
			pre_pt = Point(x,y);  
			putText(Peyebrow->mat_public,temp,pre_pt,FONT_HERSHEY_SIMPLEX,0.3,Scalar(0,0,255,255),1,8,false);//在窗口上显示坐标  
			circle(Peyebrow->mat_public,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);						//划点  
			//write the ordinate in the file
			Peyebrow->face_fout<<(double)x<<'\t'<<(double)y<<endl;

			imshow(Peyebrow->public_window,Peyebrow->mat_public);  
			cv::waitKey(0); 
		}  

}
//2.1
void EyeBrow::LInFileEyebrow()
{
	//define the file
	face_filename=".//face_part//txt//lefteyebrow.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
		//1.lefteyebrow
	double x=0,y=0;
	for(int i=0;i<face_data.GetLeftEyebrowRows();i++)
	{
		face_fin>>x>>y;
		face_data.SetLeftEyebrow(x,i,0);
		face_data.SetLeftEyebrow(y,i,1);
		//cout<<face_data.GetLeftEyebrow(i,0)<<"\t"<<face_data.GetLeftEyebrow(i,1)<<endl;
	}

		face_fin.close();
}
//2.2
void EyeBrow::RInFileEyebrow()
{
		//define the file
	face_filename=".//face_part//txt//righteyebrow.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
		//1.lefteyebrow
		double x=0,y=0;
	for(int i=0;i<face_data.GetRightEyebrowRows();i++)
	{
		face_fin>>x>>y;
		face_data.SetRightEyebrow(x,i,0);
		face_data.SetRightEyebrow(y,i,1);
		//cout<<face_data.GetRightEyebrow(i,0)<<"\t"<<face_data.GetRightEyebrow(i,1)<<endl;

	}

		face_fin.close();

}

//3.1
void EyeBrow::Mask()
{

}
//3.1
void EyeBrow::LMask()
{
	GrayThreshold(mat_lefteyebrow,150);
}
//3.2
void EyeBrow::RMask()
{
	 GrayThreshold(mat_righteyebrow,150);
}
//4.1
void EyeBrow::Affain()
{
	//1.4 paste the picture
	for (int y=0;y<face_dst.rows;y++)
	 for(int x=0;x<face_dst.cols;x++)
			if(face_dst.at<Vec3b>(y,x)[0]==0&&face_dst.at<Vec3b>(y,x)[1]==0&&face_dst.at<Vec3b>(y,x)[2]==0) //face_dst is a mask 
			{				   }
			else
			{
			face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[0]=face_dst.at<Vec3b>(y,x)[0];
			face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[1]=face_dst.at<Vec3b>(y,x)[1];
			face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[2]=face_dst.at<Vec3b>(y,x)[2];
		   }	 

}

//4.2
// five points
void EyeBrow::LAffain()
{

	//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_lefteyebrow,face_dst);
	//1.3  
			bool result=true;
			std::vector< Point2f > srcMatrix;
			std::vector< Point2f > dstMatrix;
			int pointnum=0;
				//give the first price
				srcMatrix.clear();dstMatrix.clear();
				pointnum=face_data.GetLeftEyebrowRows();

				for(int j=0;j<pointnum;j++)
			   srcMatrix.push_back( Point2f(face_data.GetLeftEyebrow(j,0), face_data.GetLeftEyebrow(j,1) ) );
				for(int j=0;j<pointnum;j++)
				dstMatrix.push_back( Point2f(file_data.GetLeftEyebrow(j,0),file_data.GetLeftEyebrow(j,1) ) );
				warp_mat=estimateRigidTransform(srcMatrix,dstMatrix,result);
	//1.4
				Affain();										
	//1.5 
	CopyImage(face_src,file_dst);
}

//4.3
//five points
void EyeBrow::RAffain()
{
		//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_righteyebrow,face_dst);
	//1.3  
			bool result=true;
			std::vector< Point2f > srcMatrix;
			std::vector< Point2f > dstMatrix;
			int pointnum=0;
				//give the first price
				srcMatrix.clear();dstMatrix.clear();
				pointnum=face_data.GetRightEyebrowRows();

				for(int j=0;j<pointnum;j++)
			   srcMatrix.push_back( Point2f(face_data.GetRightEyebrow(j,0),face_data.GetRightEyebrow(j,1) ) );
				for(int j=0;j<pointnum;j++)
				dstMatrix.push_back( Point2f(file_data.GetRightEyebrow(j,0),file_data.GetRightEyebrow(j,1) ) );
				warp_mat=estimateRigidTransform(srcMatrix,dstMatrix,result);

				Affain();										
	//1.4 
	CopyImage(face_src,file_dst);
}

