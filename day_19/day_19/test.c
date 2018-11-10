#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char *s1, const char *s2) 
{
	assert(s1&&s2);
	while (*s1==*s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
int mian()
{
	char *arr1 = "abcdef";
	char *arr2 = "abcdef";
	int ret=my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}
//void *my_memmov(void *dest, const void *src, size_t count)
//{
//	void *ret = dest;
//		assert(dest&&src);
//		if (dest < src)
//		{
//			while (count--)
//			{
//				*(char *)dest = *(char *)src;
//				dest = (char *)dest + 1;
//				src = (char *)src + 1;
//			}
//		}
//		else
//		{
//			src = (char *)src + count - 1;
//			dest = (char *)dest + count - 1;
//			while (count--)
//			{
//				*(char *)dest = *(char *)src;
//				dest = (char *)dest - 1;
//				src = (char *)src - 1;
//			}
//		}
//		return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_memmov(arr+4 , arr+2,16);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//void* my_memcpy(void *dest, const void *src, size_t count)
//{
//	void *ret = dest;
//	assert(dest&&src);
//	while (count--)
//	{
//		*(char *)dest = *(char *)src;
//		dest = (char *)dest + 1;
//		src = (char *)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_memcpy(arr + 2, arr,8);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//char *my_strstr(const char *src, const char *subsrc)
//{
//	assert(src&&subsrc);
//	const char *cur = src;
//	const char *s1 = cur;
//	const char *s2 = subsrc;
//	if (*subsrc == '\0')
//		return (char *)src;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = subsrc;
//		while (*s1&&*s2&&*s1==*s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return (char *)cur;
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char *arr1 = "abcdef";
//	char *arr2 = "cdef";
//	char *p=my_strstr(arr1, arr2);
//	if (p != NULL)
//	{
//		printf("%s\n", p);
//	}
//	else printf("找不到\n");
//	return 0;
//}

//char *my_strcat(char *dest, const char*src)
//{
//	assert(dest&&src);
//	while(*dest)
//	{
//		dest++;
//	}
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//char *my_strcat(char *dest, const char *src)
//{
//	assert(dest&&src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//char *my_strcpy(char *dest, char *src)
//{
//	
//	while (*dest&&*src)
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	return dest;
//}
//int my_strlen(const char* arr)
//{
//	assert(arr);
//	char *p = arr;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return p-arr;
//}
//int my_strlen(const char* arr)
//{
//	assert(arr);
//	if (*arr == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(arr + 1);
//}

//1.实现strlen
//int my_strlen(const char* arr)
//{
//	assert(arr);
//	int count = 0;
//	while (*arr++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[20] = "abcde";
//	int ret=my_strlen(arr);
//	my_strcpy(arr, "hello");
//	my_strcat(arr,"hello");
//	printf("%s\n", arr);
//	return 0;
//}