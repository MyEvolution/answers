#ifndef TREENODE
#define TREENODE
#include<iostream>
#include<string>
using namespace std;
class TreeNode
{
	
	string value;
	int count=0;
	TreeNode *left=nullptr;
	TreeNode *right=nullptr;//左右儿子 
	public :
		TreeNode(const string &s):value(s){}
		TreeNode(const TreeNode &TN):value(TN.value),count(TN.count),left(TN.left?nullptr:new TreeNode(*TN.left)),
		right(TN.right?nullptr:new TreeNode(*TN.right)){}//类值类，对于一个很高的树，代价挺大
		TreeNode&operator = (TreeNode & tn)
		{
			auto i = tn.left?nullptr:new TreeNode (*tn.left);
			auto j = tn.right?nullptr:new TreeNode (*tn.right);
			delete_tree(*this);
			left = i;
			right = j;
			value = tn.value;
			count = tn.count;			
		}
		~TreeNode()
		{
			delete_tree(*this);
		}
	private:
		static void delete_tree(TreeNode &tn)//删除两个孩子 
		{
			if(tn.left)
			{
			delete_tree(*tn.left);//释放子树 
			delete tn.left; 
			}
			if(tn.right)
			{
			delete_tree(*tn.right);
			delete tn.right;
		    }
		    //其他的成员变量在离开作用域自动会释放掉 
		}
 };
 #endif
 /*
 二叉树的节点类
 当我们复制二叉树的节点类时候，想要建立一颗与其一样的子树，但是代价可能是很大的
 如果我们想要改变这棵树，用引用即可，因为共享资源的坏处就是资源可能被破坏
 所以我决定将它做成类值的类
 目前只定义了一些拷贝控制成员 
 注意既然是类值的，那么就要自己定义了，而不能用合成的
 我们需要把树都赋值过来  当我们new时，又用到了拷贝构造，所以这其实是一个递归，终点就是遇到了叶子节点
 所以说代价可能是很大的，对于一颗大树
 同时我们需要特殊的析构函数，因为要删除整棵树，释放很多的内存，这并不是那么容易
我们先删除子树，为了删除子树就要删除子树的子树，这也是递归
终究来说 删除一颗树，就是让他成了一个叶子节点。然后就剩下内置类型成员，可以通过编译器来释放了
*/ 
