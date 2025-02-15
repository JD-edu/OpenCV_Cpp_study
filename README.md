# OpenCV C++ tutorial 
This tutorial provide example code to build OpenCV based C++ application.
OpenCV is computer vision library written in C++. For detail information for OpenCV refer here  [OpenCV official page](https://opencv.org).
It is easier way to learn OpenCV using python. For python OpenCV tutorial, refer here  [https://opencv.org](https://github.com/JD-edu/aiot-pi/tree/master/OpenCV_code).

# How to start 
1. Open OpenCV_C++_study folder
2. run Visual Studio 2022 with double clicking "OpenCV_C++_study.sln" file.
3. You can see "OpenCV_C++_study.cpp" on your Visual Studio 2022 editor window.
4. Build it and run it.
```
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 읽기
    cv::Mat img = cv::imread("./resource/lane.jpg");
    if (img.empty()) {
        std::cerr << "Error: Unable to load image!" << std::endl;
        return 1;
    }

    // Canny Edge Detection
    cv::Mat edges;
    cv::Canny(img, edges, 50, 200, 3);

    // 확장된 허프 변환으로 직선 검출
    std::vector<cv::Vec4i> lines;
    int minLineLength = 100; // 최소 직선 길이
    int maxLineGap = 0;      // 최대 허용 간격
    cv::HoughLinesP(edges, lines, 1, CV_PI / 360, 100, minLineLength, maxLineGap);

    // 검출된 직선 그리기
    for (size_t i = 0; i < lines.size(); i++) {
        cv::Vec4i l = lines[i];
        cv::line(img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 3);
    }

    // 결과 표시
    cv::imshow("Detected Lines", img);

    // 키 입력 대기
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```

If you want chamge code, select one of example code files. And copy text of the file, and paste text to "OpenCV_C++_study.sln".
An build it and run it. 

# Create OpenCV based Visual Studio 2022 project 
TBD
