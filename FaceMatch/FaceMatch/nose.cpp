#include"nose.h"
Nose* Nose::Pnose=NULL;   //give the first the price to Pnose
//1.1
void Nose::MousePoint()
{
	nose_window="Nose Image";
	face_filename=".//face_part//txt//nose.txt";
			CopyImage(mat_nose,mat_public);
			public_window=nose_window;
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

//1.2
void Nose::on_mouse(int event,int x,int y,int flags,void *ustc)
{
	      if ( Pnose == NULL )
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
			putText(Pnose->mat_public,temp,pre_pt,FONT_HERSHEY_SIMPLEX,0.3,Scalar(0,0,255,255),1,8,false);//在窗口上显示坐标  
			circle(Pnose->mat_public,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);						//划点  
			//write the ordinate in the file
			Pnose->face_fout<<(double)x<<'\t'<<(double)y<<endl;

			imshow(Pnose->public_window,Pnose->mat_public);  
			cv::waitKey(0); 
		}  


}
//2.1
void Nose::InFileNose()
{
	//define the file
	face_filename=".//face_part//txt//nose.txt";
	face_fin.open(face_filename,ios::in|ios::out);
	if(!face_fin) 
	{
	cout<<"error in open the file!"<<endl;
	system("pause");
	face_fin.close();
	return ;
	}
	//1.nose
	double x=0,y=0;
	for(int i=0;i<face_data.GetNoseRows();i++)
	{
		face_fin>>x>>y;
		face_data.SetNose(x,i,0);
		face_data.SetNose(y,i,1);
		//cout<<face_data.GetNose(i,0)<<"\t"<<face_data.GetNose(i,1)<<endl;
	}
		face_fin.close();
}

//3.1
void Nose::Mask()
{
	GrayThreshold(mat_nose,220);
}

//4.1
void Nose::Affain()
{
	//1.1  get the srcImage
	CopyImage(file_dst,face_src);
	//1.2  get the dstImage
	CopyImage(mat_nose,face_dst);
	//1.3  
	GetAffain();
	//1.4 paste the picture
	PasteNose();
	//1.5
	CopyImage(face_src,file_dst);

}

//4.2
void Nose::GetAffain()
{
	int max_i=12;
	int Tpoint[12][3];
	//1.target the point
	for(int i=0;i<max_i;i++)
	{
		if(i==0)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=5;
		}
		else if(i==1)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=9;
		}

		else if(i==2)
		{
		  Tpoint[i][0]=5;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=6;
		}
		else if(i==3)
		{
		  Tpoint[i][0]=6;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=7;
		}
		else if(i==4)
		{
		  Tpoint[i][0]=7;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=8;
		}
		else if(i==5)
		{
		  Tpoint[i][0]=8;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=9;
		}

		else if(i==6)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=2;
		  Tpoint[i][2]=5;
		}
		else if(i==7)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=3;
		  Tpoint[i][2]=5;
		}
		else if(i==8)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=5;
		}

		else if(i==9)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=2;
		  Tpoint[i][2]=9;
		}

		else if(i==10)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=3;
		  Tpoint[i][2]=9;
		}
		else if(i==11)
		{
		  Tpoint[i][0]=1;
		  Tpoint[i][1]=4;
		  Tpoint[i][2]=9;
		}

	}//for
	//2.get the matrix
		   for(int i=0;i<max_i;i++)
		   {
			   	 Point2f srcTri[3];
				 Point2f dstTri[3];
				int pointcount=3;  //three point

				for(int j=0;j<pointcount;j++)
				{
					//1	
				double x1=face_data.GetNose(Tpoint[i][j]-1,0);
				double y1=face_data.GetNose(Tpoint[i][j]-1,1);
				srcTri[j]= Point2f(x1,y1);
				double x2=	file_data.GetNose(Tpoint[i][j]-1,0);
				double y2=	file_data.GetNose(Tpoint[i][j]-1,1);
				dstTri[j]=	Point2f(x2,y2);
				//cout<<x1<<'\t'<<y1<<endl;
				//cout<<x2<<'\t'<<y2<<endl;
				}
				        /// 求得仿射变换 (10 matrix)
				warp_nose[i] = getAffineTransform( srcTri, dstTri );
				//cout<<warp_nose[i]<<endl;
		   }//for
}

//4.3
void Nose::PasteNose()
{
	int max_value=120;
	 for (int y=0;y<face_dst.rows;y++)
	 for(int x=0;x<face_dst.cols;x++)
	 {
			if(mat_nose_mask.at<Vec3b>(y,x)[0]==0&&mat_nose_mask .at<Vec3b>(y,x)[1]==0&&mat_nose_mask .at<Vec3b>(y,x)[2]==0) //face_dst is a mask; mat_nose_mask  is also a mask
			{
			}
			//10*i 10*i 10*i
			else if(mat_nose_mask .at<Vec3b>(y,x)[0]<=max_value&&mat_nose_mask .at<Vec3b>(y,x)[1]<=max_value&&mat_nose_mask .at<Vec3b>(y,x)[2]<=max_value)
			{
				//
					int order=0;
					int price=(int)mat_nose_mask .at<Vec3b>(y,x)[0];
					order=( price/10 -1 );


					warp_nose[order].copyTo(warp_mat);

					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[0]=face_dst.at<Vec3b>(y,x)[0];
					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[1]=face_dst.at<Vec3b>(y,x)[1];
					face_src.at<Vec3b>( PointY(warp_mat,x,y),PointX(warp_mat,x,y))[2]=face_dst.at<Vec3b>(y,x)[2];


			}
	}

}