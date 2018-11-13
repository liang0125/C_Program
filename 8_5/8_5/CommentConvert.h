#ifndef __CommentConvert_H__
#define  __CommentConvert_H__ 

#include<stdio.h>
#include<stdlib.h>


typedef  enum State
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}State;
void DoNulState(FILE *pfread, FILE *pfwrite, State *ps);
void DoCState(FILE *pfread, FILE *pfwrite, State *ps);
void DoCppState(FILE *pfread, FILE *pfwrite, State *ps);
void CommentCovert(FILE *pfread, FILE *pfwrite);
#endif // __CommentConvert_H__
