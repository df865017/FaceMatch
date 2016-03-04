#include"eye.h"
Eye* Eye::Peye=NULL;   //give the first the price to Peyebrow

//1.0
void Eye::LMousePoint()
{
			    //lefteye picture
		lefteye_window="LeftEye Image";
		face_filename=".//face_part//txt//lefteye.txt";
				CopyImage(mat_lefteye,mat_public);
				public_window=lefteye_window;
		MousePoint();
}
//1.1
void Eye::RMousePoint()
{
		    //righteye picture
		righteye_window="RightEye Image";
		face_filename=".//face_part//txt//righteye.txt";
			CopyImage(mat_righteye,mat_public);
			public_window=righteye_window;
		MousePoint();

}

//1.2
void Eye::MousePoint()
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
void Eye::on_mouse(int event,int x,int y,int flags,void *ustc)
{
	      if ( Peye == NULL )
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
			putText(Peye->mat_public,temp,pre_pt,FONT_HERSHEY_SIMPLEX,0.3,Scalar(0,0,255,255),1,8,false);//在窗口上显示坐标  
			circle(Peye->mat_public,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);						//划点  
			//write the ordinate in the file
			Peye->face_fout<<(double)x<<'\t'<<(double)y<<endl;

			imshow(Peye->public_window,Peye->mat_public);  
			cv::waitKey(0); 
		}  

}

//2.1
void Eye::LInFileEye()
{
	//define the file
	face_filename=".//face_part//txt//lefteye.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
		//1.lefteye
	double x=0,y=0;
	for(int i=0;i<face_data.GetLeftEyeRows();i++)
	{
		face_fin>>x>>y;
			face_data.SetLeftEye(x,i,0);
			face_data.SetLeftEye(y,i,1);
		
		//cout<<face_data.GetLeftEye(i,0)<<"\t"<<face_data.GetLeftEye(i,1)<<endl;
	}

		face_fin.close();
}

//2.2
void Eye::RInFileEye()
{
		//define the file
	face_filename=".//face_part//txt//righteye.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
		//1.righteye
    double x=0,y=0;
	for(int i=0;i<face_data.GetRightEyeRows();i++)
	{
		face_fin>>x>>y;
			face_data.SetRightEye(x,i,0);
			face_data.SetRightEye(y,i,1);

		//cout<<face_data.GetRightEye(i,0)<<"\t"<<face_data.GetRightEye(i,1)<<endl;
	}
	face_fin.close();

}

//3.0
void Eye::Mask()
{

}
//3.1
void Eye::LMask()
{
  GrayThreshold(mat_lefteye,150);
}
//3.2
void Eye::RMask()
{
	 GrayThreshold(mat_righteye,200);
}

//4.1
void Eye::Affain()
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
void Eye::LAffain()
{
	//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_lefteye,face_dst);
	//1.3  
			bool result=true;
			std::vector< Point2f > srcMatrix;
			std::vector< Point2f > dstMatrix;
			int pointnum=0;
				//give the first price
				srcMatrix.clear();dstMatrix.clear();
				pointnum=face_data.GetLeftEyeRows();
				
				for(int j=0;j<pointnum;j++)
			   srcMatrix.push_back( Point2f(face_data.GetLeftEye(j,0), face_data.GetLeftEye(j,1) ) );
				for(int j=0;j<pointnum;j++)
				dstMatrix.push_back( Point2f(file_data.GetLeftEye(j,0),file_data.GetLeftEye(j,1) ) );
				warp_mat=estimateRigidTransform(srcMatrix,dstMatrix,result);
	//1.4
				Affain();										
	//1.5 
	CopyImage(face_src,file_dst);

}
//4.3
void Eye::RAffain()
{

	//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_righteye,face_dst);
	//1.3  
			bool result=true;
			std::vector< Point2f > srcMatrix;
			std::vector< Point2f > dstMatrix;
			int pointnum=0;
				//give the first price
				srcMatrix.clear();dstMatrix.clear();
				pointnum=face_data.GetRightEyeRows();

				for(int j=0;j<pointnum;j++)
			   srcMatrix.push_back( Point2f(face_data.GetRightEye(j,0), face_data.GetRightEye(j,1) ) );
				for(int j=0;j<pointnum;j++)
				dstMatrix.push_back( Point2f(file_data.GetRightEye(j,0),file_data.GetRightEye(j,1) ) );
				warp_mat=estimateRigidTransform(srcMatrix,dstMatrix,result);

				Affain();										
	//1.4 
	CopyImage(face_src,file_dst);

}