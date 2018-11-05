#pragma   once
#include<stdio.h>
#include<stdbool.h>
// 2,7,11,15
int sum[2] = { 0 };
int* twoSum(int* nums, int numsSize, int target) {
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				sum[0] = i;
				sum[1] = j;
				return sum;	
			}
		}
	}
	return NULL;
}
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
bool isMirror(struct TreeNode *t1, struct TreeNode *t2)
{
	if (t1 == NULL && t2 == NULL)   return true;
	if (t1 == NULL || t2 == NULL)   return false;
	return ((*t1).val == (*t2).val) && (isMirror((*t1).right, (*t2).left)) && (isMirror((*t1).left, (*t2).right));
}
bool isSymmetric(struct TreeNode *root) {
	return isMirror(root, root);
}
//*
//* Definition for singly-linked list.
//struct ListNode {
//    int val;
//   struct ListNode *next;
//};
//struct ListNode* CreateNode(int data)
//{
//	struct ListNode* node = (struct ListNode *)malloc(sizeof(struct ListNode));
//	node->val = data;
//	node->next = NULL;
//	return node;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//
//	struct ListNode* p = l1;
//	struct ListNode* q = l2;
//	int carry = 0;//表示进位
//	int x = 0;
//	int y = 0;
//	int sum = 0;
//	struct ListNode* m = NULL;
//	struct ListNode* n = m;
//	while (p != NULL || q != NULL)
//	{
//		if (p != NULL)
//		{
//			x = p->val;
//		}
//		else {
//			x = 0;
//		}
//		if (q != NULL)
//		{
//			y = q->val;
//		}
//		else {
//			y = 0;
//		}
//
//		sum = x + y + carry;
//		carry = sum / 10;
//		if (sum >= 10)
//		{
//			sum = sum % 10;
//		}
//		struct ListNode* node = CreateNode(sum);
//		if (n == NULL)
//		{
//			n = node;
//			m = n;
//		}
//		else {
//			while (n->next != NULL)
//			{
//				n = n->next;
//			}
//			n->next = node;
//			n = n->next;
//		}
//		if (p != NULL)
//		{
//			p = p->next;
//		}
//		if (q != NULL)
//		{
//			q = q->next;
//		}
//	}
//	if (carry == 1)
//	{
//		n->next = CreateNode(1);
//	}
//	return m;
//}