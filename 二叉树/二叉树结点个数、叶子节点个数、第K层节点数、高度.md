
>其实解决二叉树有关的问题少不了要用递归，我们在用递归的时候要想想树的五种形式是否都满足，以确定终止条件即可。
## 求二叉树的结点个数
>空树返回0，其他返回左子树节点数+右子树节点数+1

```
//求二叉树的结点个数
int GetSize(BNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return GetSize(root->left) + GetSize(root->right) + 1;
}
```
## 求二叉树叶子节点个数
>空树的话返回0，只有一个结点返回1，其他的就是左子树的叶子节点数+右子树的叶子节点数。

```
int GetLeafSize(BNode * root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return GetLeafSize(root->left) + GetLeafSize(root->right);
}
```
## 求第K层的结点个数
>我们依然是用子问题递推的方法，我们可以用第k层左子树的节点数+第K层右子树的节点数。<br>终止条件：空树返回0，如果查的是第一层的节点数，返回1.


```
int GetKLevelSize(BNode *root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return GetKLevelSize(root->left, k - 1)+ GetKLevelSize(root->right, k - 1);
}
```
## 求二叉树的高度
>在求二叉树的高度时，我们不能像之前一样左右相加了，这时候我们需要比较左子树的高度和右子树的高度，看哪个更高，高的+1便是二叉树的高度了。


```
#define MAX(a,b) ((a)>(b)?(a):(b))
int GetHeight(BNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int i = GetHeight(root->left);
	int j = GetHeight(root->right);
	return MAX(i, j) + 1;
}
```

