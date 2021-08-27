/*
파일 이름: (Bank) Account.cpp
작성자: 김소현
업데이트 정보: [2021, 08, 24] 파일 버전 0.1
*/

#ifndef __BANKING_COMMON_h__
#define __BANKING_COMMON_h__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

//프로그램 사용자의 선택 메뉴
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

//신용 등급
enum {LEVEL_A=7, LEVEL_B = 4, LEVEL_C = 2};

//계좌의 종류
enum {NORMAL=1, CREDIT=2};

# endif
