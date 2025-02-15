﻿/*
MIT License

Copyright (c) 2024 JD edu. http://jdedu.kr author: conner.jeong@gmail.com
     
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
     
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
     
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN TH
SOFTWARE.
*/
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 빈 이미지 생성 (320x240, 3채널, 8비트)
    cv::Mat img = cv::Mat::zeros(320, 240, CV_8UC3);

    // 텍스트 추가
    cv::putText(img, "This is test!", cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(102, 255, 255), 1);
    cv::putText(img, "Hello world!", cv::Point(50, 100), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(255, 204, 51), 1);

    // 이미지 표시
    cv::imshow("my win", img);

    // 키 입력 대기
    cv::waitKey(0);

    // 창 닫기
    cv::destroyAllWindows();

    return 0;
}
