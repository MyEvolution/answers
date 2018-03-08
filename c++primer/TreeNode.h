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
	TreeNode *right=nullptr;//���Ҷ��� 
	public :
		TreeNode(const string &s):value(s){}
		TreeNode(const TreeNode &TN):value(TN.value),count(TN.count),left(TN.left?nullptr:new TreeNode(*TN.left)),
		right(TN.right?nullptr:new TreeNode(*TN.right)){}//��ֵ�࣬����һ���ܸߵ���������ͦ��
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
		static void delete_tree(TreeNode &tn)//ɾ���������� 
		{
			if(tn.left)
			{
			delete_tree(*tn.left);//�ͷ����� 
			delete tn.left; 
			}
			if(tn.right)
			{
			delete_tree(*tn.right);
			delete tn.right;
		    }
		    //�����ĳ�Ա�������뿪�������Զ����ͷŵ� 
		}
 };
 #endif
 /*
 �������Ľڵ���
 �����Ǹ��ƶ������Ľڵ���ʱ����Ҫ����һ������һ�������������Ǵ��ۿ����Ǻܴ��
 ���������Ҫ�ı�������������ü��ɣ���Ϊ������Դ�Ļ���������Դ���ܱ��ƻ�
 �����Ҿ�������������ֵ����
 Ŀǰֻ������һЩ�������Ƴ�Ա 
 ע���Ȼ����ֵ�ģ���ô��Ҫ�Լ������ˣ��������úϳɵ�
 ������Ҫ��������ֵ����  ������newʱ�����õ��˿������죬��������ʵ��һ���ݹ飬�յ����������Ҷ�ӽڵ�
 ����˵���ۿ����Ǻܴ�ģ�����һ�Ŵ���
 ͬʱ������Ҫ�����������������ΪҪɾ�����������ͷźܶ���ڴ棬�Ⲣ������ô����
������ɾ��������Ϊ��ɾ��������Ҫɾ����������������Ҳ�ǵݹ�
�վ���˵ ɾ��һ������������������һ��Ҷ�ӽڵ㡣Ȼ���ʣ���������ͳ�Ա������ͨ�����������ͷ���
*/ 
