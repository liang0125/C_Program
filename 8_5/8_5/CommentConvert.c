#define _CRT_SECURE_NO_WARNINGS 1
#include"CommentConvert.h"


void DoNulState(FILE *pfread, FILE *pfwrite, State *ps)
{
	char first = fgetc(pfread);
	switch (first)
	{
	case'/':
	{
		char second = fgetc(pfread);
		switch (second)
		{
		case'*':
		{
			fputc('/', pfwrite);
			fputc('/', pfwrite);
			*ps = C_STATE;
		}
			break;
		case'/':
		{
			fputc(first, pfwrite);
			fputc(second, pfwrite);
			*ps = CPP_STATE;
		}
			break;
		case EOF:
		{
			fputc(first, pfwrite);
			*ps = END_STATE;
		}
		default:
			fputc(first, pfwrite);
			fputc(second, pfwrite);
			break;
		}
	}
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default: 
		fputc(first, pfwrite);
		*ps = NUL_STATE;
		break;

	}
}


void DoCState(FILE *pfread, FILE *pfwrite, State *ps)
{
	char first = fgetc(pfread);
	switch (first)
	{
	case'*': 
	{
		char second = fgetc(pfread);
		switch (second)
		{
		case'/':
		{
			char third = fgetc(pfread);

				if (third != '\n')
				{
					fputc('\n', pfwrite);
					ungetc(third, pfread);
				}
			
				else
				{
					fputc(third, pfwrite);
				}
				
					
			*ps = NUL_STATE;
		}
			break;
		case'*':
		{
			fputc(first, pfwrite);
			ungetc(second, pfread);
			*ps = C_STATE;
		}
			break;
		default:
		{
			fputc(first, pfwrite);
			fputc(second, pfwrite);
		}
			break;
		}
	}
		break;
	case'\n':
	{
		fputc('\n', pfwrite);
		fputc('/', pfwrite);
		fputc('/', pfwrite);
		*ps = C_STATE;
	}
		break;
	default:
		fputc(first, pfwrite);
		break;
	}
}

void DoCppState(FILE *pfread, FILE *pfwrite, State *ps)
{
	char first = fgetc(pfread);
	switch (first)
	{
	case'\n':
		fputc(first, pfwrite);
		*ps = NUL_STATE;
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfwrite);
		break;
	}
}


void CommentCovert(FILE *pfread, FILE *pfwrite)
{
	State state = NUL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
		{
			DoNulState(pfread,pfwrite, &state);

		}
		break;
		case C_STATE:
		{
			 DoCState(pfread, pfwrite, &state);

		}
		break;
		case CPP_STATE:
		{
			 DoCppState(pfread, pfwrite, &state);

		}
		break;
		case END_STATE:
			break;
		}
	}
}