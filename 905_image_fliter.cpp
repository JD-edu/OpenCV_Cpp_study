﻿#include <opencv2/opencv.hpp>
#include <iostream>

// 트랙바 콜백 함수
void onTrackbar(int, void*) {
    // 콜백 함수는 트랙바 이벤트에서 호출되지만, 실제 처리는 메인 루프에서 수행됩니다.
}

int main() {
    // 이미지 읽기
    cv::Mat img = cv::imread("./resource/lena.jpg");
    if (img.empty()) {
        std::cerr << "Error: Unable to load image!" << std::endl;
        return 1;
    }

    // 윈도우 생성
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);

    // 트랙바 생성 (초기값 1, 최대값 20)
    int k = 1;
    cv::createTrackbar("K", "image", &k, 20, onTrackbar);

    while (true) {
        // 종료 조건 (ESC 키)
        if (cv::waitKey(1) == 27) {
            break;
        }

        // 트랙바 값 가져오기
        k = cv::getTrackbarPos("K", "image");

        // 값이 0이면 1로 치환
        if (k == 0) {
            k = 1;
        }

        // (k, k) 크기의 커널 생성 및 필터 적용
        cv::Mat kernel = cv::Mat::ones(k, k, CV_32F) / (k * 2);
        cv::Mat dst;
        cv::filter2D(img, dst, -1, kernel);

        // 결과 이미지 표시
        cv::imshow("image", dst);
    }

    // 모든 창 닫기
    cv::destroyAllWindows();

    return 0;
}
