#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <String>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	//����Ƶ
	cap.open("D:\\CODE\\ComputerNetwork\\Lab1\\VideoToImg\\test.mp4");
	//�Ƿ�ɹ�����Ƶ
	if (!cap.isOpened())
		return 0;
	long totalFrame = cap.get(CAP_PROP_FRAME_COUNT);
	int fps = cap.get(CAP_PROP_FPS);
	cout << "��֡��Ϊ��" << totalFrame << "֡��Ϊ"<<fps<< endl;

	Mat	frame;
	for(int i=0;i<totalFrame;i++)
	{
		// ͨ��������������Ƶת��Ϊһ֡֡ͼƬ
		cap >> frame;
		if (frame.empty())
			break;
		
		//�洢֡
		String str = to_string(i) + ".png";
		imwrite(str.c_str(), frame);
			
		cout << "���ڴ����" << i << "֡" << endl;
		//// �½����ڣ�0��ʾ���������ı䴰�ڴ�С
		//namedWindow("video", 0);
		////resize���ڴ�С
		//resizeWindow("video", 500, 500);
		////չʾ֡
		//imshow("video", frame);
	}
	cout << "������"<<endl;

	//�رմ���
	destroyAllWindows();
	return 0;

}