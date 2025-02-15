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
    // 이미지 읽기
    cv::Mat img = cv::imread("./resource/rail.jpg");
    if (img.empty()) {
        std::cerr << "Error: Unable to load image!" << std::endl;
        return 1;
    }

    // Perspective 변환을 위한 좌표 설정 (4x2 행렬)
    std::vector<cv::Point2f> pts1 = { {475, 426}, {382, 649}, {594, 421}, {699, 638} };
    std::vector<cv::Point2f> pts2 = { {10, 10}, {10, 1000}, {1000, 10}, {1000, 1000} };

    // 좌표점 표시
    cv::circle(img, pts1[0], 20, cv::Scalar(255, 0, 0), -1); // 파란색
    cv::circle(img, pts1[1], 20, cv::Scalar(0, 255, 0), -1); // 초록색
    cv::circle(img, pts1[2], 20, cv::Scalar(0, 0, 255), -1); // 빨간색
    cv::circle(img, pts1[3], 20, cv::Scalar(0, 0, 0), -1);   // 검정색

    // Perspective 변환 행렬 계산
    cv::Mat M = cv::getPerspectiveTransform(pts1, pts2);

    // Perspective 변환 적용
    cv::Mat dst;
    cv::warpPerspective(img, dst, M, cv::Size(1100, 1100));

    // 결과 표시
    cv::imshow("Original Image", img);
    cv::imshow("Perspective Transformed Image", dst);

    // 키 입력 대기
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
