#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //�ļ����������ʽ��֡�ʣ��ֱ���
    VideoWriter video("test.mp4", VideoWriter::fourcc('D', 'I', 'V', 'X'),29.0, Size(1280,720));
	//ͼƬ��ַ
	String img_path = "D:\\CODE\\ComputerNetwork\\Lab1\\VideoToImg\\VideoToImg\\";
	vector<String> img;

	glob(img_path, img, false);
	//��ȡͼƬ������
	size_t count = img.size();
	for (size_t i = 0; i < count; i++)
	{
		stringstream str;
		str << i << ".png";
		Mat image = imread(img_path + str.str());
		//ͼƬ��Ϊ��
		if (!image.empty())
		{
			//��������ֱ���
			resize(image, image, Size(1280, 720));
			video << image;
			cout << "���ڴ����" << i << "֡" << endl;
		}
	}
	cout << "�������" << endl;
}
