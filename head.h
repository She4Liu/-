#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 定义全局变量ROW和COL从而方便在头文件里修改整个游戏的棋盘大小
#define ROW 3
#define COL 3

// 菜单函数
void menu();

// 游戏主函数
void game();

// 初始化棋盘函数
void int_board(char board[ROW][COL], int row, int col);

// 打印棋盘函数
void board_print(char board[ROW][COL], int row, int col);

// 玩家下棋函数
void player_movie(char board[ROW][COL], int row, int col);

// 电脑下棋函数
void computer_movie(char board[ROW][COL], int row, int col);

// 判断输赢
void who_win(char c);

// 何人胜利
char who(char board[ROW][COL], int row, int col);
