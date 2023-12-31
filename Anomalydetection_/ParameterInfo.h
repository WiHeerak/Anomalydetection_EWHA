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

#ifndef SYSTEM_CONFIGURATION_H_
#define SYSTEM_CONFIGURATION_H_

#include "main.h"
#include "inc.h"
#include "CascadedBgsParams.h"
#include "SequentialBgeParams.h"
//#include "opencv2/highgui.hpp"
//#include "opencv2/opencv.hpp"


class ParameterInfo
{
public:
	//define constant 상수 정의
	double n_secs, acc_secs; 
	bgscascade_thresholds T_vals;
	bg_est_param_values T_bge_vals;
	string curr_filename;

	s16 N; // 2byte
	s16 fvno;
	s16 ovlstep;
	u32 n_gaus; // 4byte
	u32 n_gaus_final;
	u32 n_iter;
	u16 total_seqs;
	ifstream param_file; //읽기 작업을 위한 파일 클래스
	char filename[200];
	string ref_frno, frno;
	string path, path1, outfile, seqname;
	int lcnt;
	int ltemp;
	s16 ind;
	string outfileptr;
	cv::Mat first_img; //n차원 dense array
	cv::Mat img_sc, input_img_mtx, mask_mtx_us;
	cv::Mat padded_input_img, roi_image;

	cv::Size tsize; //이미지 또는 사각형의 크기를 지정하기 위한 클래스
	float ratio;

	u32 true_height, true_width;
	u32 prow, pcol;

	u32 height, width, channels;
	u32 sequence_len;
	cv::VideoCapture vidfile; //비디오 파일, 이미지 시퀀스 또는 카메라에서 비디오캡처를 위한 클래스

	input_type in_data_format;
	string bg_train_path, tr_mask_path, tst_mask_path;


	//std::vector<std::string> result, result1;

	ParameterInfo(const rowvec& cur_param_vec, double ratio,
		bool training_reqd_flag = true);
	ParameterInfo(const rowvec& cur_param_vec);

	void initialise_algorithm_parameters(const rowvec& cur_param_vec,
		const bool& training_reqd_flag);
	void downscale_frame_and_pad_if_necessary();
	void fill_padded_region();
	void upscale_mask(cv::Mat& mask);
	void draw_bounding_boxes();
	void is_grey_scale_img(const rowvec& cur_param_vec);
	void load_files_from_folder(std::vector<std::string>& out_result);
	void load_files_from_filelist(std::vector<std::string>& out_result, string filedata);

	void get_input_frame(const std::vector<std::string> result, u32 frm_idx);
	void get_first_frame(const std::vector<std::string> result);
	void numtostr(int num, char* str);
	void output_statistics();

	virtual ~ParameterInfo();
};

#endif SYSTEM_CONFIGURATION_H_ //원래 이건 주석처리였음!
