// Copyright (C) 2009 - 2014 NICTA
//
// Authors:
// - Vikas Reddy (vikas.reddy at ieee dot org, rvikas2333 at gmail dot com)
//
// This file is provided without any warranty of
// fitness for any purpose. You can redistribute
// this file and/or modify it under the terms of
// the GNU General Public License (GPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


#ifndef DISPLAY_IMAGE_H_ //DISPLAY_IMAGE_H_ 를 정의하지 않았다면 #endif 문장 이전의 내용들을 include영역에 포함시키라는 뜻
//모든 헤더파일에 매크로 #ifndef~#endif의 선언을 포함하는 것이 좋다.
//매크로: 프로그램 내에서 컴파일러가 매크로를 만났을때, 대체할 문자열을 정의
//헤더파일이 겹치는 것을 막기위한 매크로
#define DISPLAY_IMAGE_H_ 

#include "opencv2/opencv.hpp"


enum colour_fill { red, green, blue, white }; 
//열거목록의 위치에 따라 정수값이 자동으로 할당, 0,1,2,3 순서!(colour_fill이라고 하자)

class DisplayImage //class이름은 DisplayImage
{
private: // 내부에서만 사용할수 있음
	cv::Mat disp_image; // 행렬 : disp_image

public: //class내부나 외부 어디든 접근 가능
	DisplayImage(const cv::Size imsize); //변수
	void Overlay_Img(const cv::Mat& img, const cv::Size ofset); //함수
	void Overlay_Img(const cv::Mat& img, const cv::Mat& mask, cv::Size ofset, const int& colour_fill); //함수
	cv::Mat Render_img(void);

	virtual ~DisplayImage(); //가상함수:포인터나 참조를 통해 접근 가능
	//가상생성자는 가질 수 없음.
};

#endif /* DISPLAY_IMAGE_H_ */

