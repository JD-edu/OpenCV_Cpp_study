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
    // 웹캠 초기화 (기본 카메라: 0번)
    cv::VideoCapture cap(0);

    // 웹캠 열기 확인
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the webcam!" << std::endl;
        return 1;
    }

    // 프레임 크기 설정
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);

    // 비디오 저장을 위한 설정
    int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X'); // 압축 코덱 설정
    cv::VideoWriter writer("./resource/203_video.avi", fourcc, 25.0, cv::Size(320, 240));

    // 저장 파일 열기 확인
    if (!writer.isOpened()) {
        std::cerr << "Error: Unable to open video file for writing!" << std::endl;
        return 1;
    }

    // 캡처 루프
    while (true) {
        cv::Mat frame;
        bool ret = cap.read(frame); // 프레임 읽기

        // 프레임 읽기 확인
        if (!ret) {
            std::cerr << "Error: Unable to read frame from webcam!" << std::endl;
            break;
        }

        // 프레임 표시
        cv::imshow("my win", frame);

        // 프레임 저장
        writer.write(frame);

        // 종료 키 체크 ('q' 키로 종료)
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // 리소스 해제
    cap.release();
    writer.release();
    cv::destroyAllWindows();

    return 0;
}
