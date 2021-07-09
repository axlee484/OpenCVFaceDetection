#include<iostream>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>


using namespace std;
using namespace cv;



int main()
{

	string pathToXml;
	CascadeClassifier Detect;
	cout << "Enter path for Detection Library's XML(Make sure the path doesn't have any whitespaces)\n";
	cin >> pathToXml;
	auto it=Detect.load(pathToXml);
	if (!it)
	{
		cout << "Error loading the XML file\nABORTING";
		exit(-1);
	}


	string pathToImage;
	cout << "Enter the path of the photo(Make sure the path doesn't have any whitespaces)"<<endl;
	cin >> pathToImage;
	Mat image = imread(pathToImage, 100);

	if (image.empty())
	{
		cout << "ËRROR LOADING IMAGE\nABORTING";
		exit(-1);
	}

	cout << "Processing Image to search for faces";
	vector<Rect> faces;
	Detect.detectMultiScale(image, faces);


	system("cls");
	if (faces.size() == 0)
	{
		cout << "No faces detected. Try using higher resolution or different format\nABORTING" << endl; exit(2);
	}

	for (int i = 0;i < faces.size();i++)
	{
		Point point1(faces[i].x, faces[i].y);
		Point point2(faces[i].x + faces[i].width, faces[i].y + faces[i].height);

		rectangle(image, point1, point2, Scalar(255,255,255), 2, 2, 0);

	}

	string savepath;
	cout << "Enter path to save the file(Make sure the path doesn't have any whitespaces)\n";
	cin >> savepath;
	imwrite(savepath, image);




	return 0;
}
