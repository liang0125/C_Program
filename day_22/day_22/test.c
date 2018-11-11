#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//char *my_strncat(char *dest,const char *src, size_t num)
//{
//	char *p = dest;
//	assert(dest&&src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (num--)
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return p;
//}
//char *my_strncpy(char *dest, char *src, size_t num)
//{
//	char *p = dest;
//	assert(dest&&src);
//	while (num--&&*src)
//	{
//		*dest++ = *src++;
//		
//	}
//	if (num > 0)
//	{
//		num = num + 1;
//		while (num--)
//		{
//			*dest++ = '\0';	
//		}
//	}
//	return p;
//}
int my_strncmp(const char *dest,const char *src, size_t num)
{
	assert(dest&&src);
	while ((num--) && (*dest == *src))
	{
		dest++;
		src++;
	}
	if ((*dest - *src) > 0)
		return 1;
	else if ((*dest - *src) < 0)
		return -1;
	else return 0;
}
int main()
{
	char arr1[20];
	char arr2[20];
	strcpy(arr1, "to be");
	strcpy(arr2, "to bw");
	printf("%d\n",my_strncmp(arr1, arr2, 6));
	return 0;
}