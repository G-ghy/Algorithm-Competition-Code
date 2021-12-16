#include<iostream>
#include<queue>
using namespace std;
int a[1001];//定义初始数组 
queue<int> q;//定义队列q 

bool dfs(int l,int r,int flag)//广度优先遍历数组 
{
	if(l>r) return true;//终止条件 
	int root=a[l];//定义根节点 
	if(flag)//二叉搜索树，左小右大 
	{
		for(int i=l+1;i<=r;i++)//从第二个节点开始遍历 
		{
			if(a[i]>=root)//找到大于根节点的节点，即为右子树的根节点 
			{
				for(int j=i+1;j<=r;j++)
				if(a[j]<root) return false;//右子树中有比根节点小的，不符合题意 
				
				if(!dfs(l+1,i-1,flag)) return false;//判断左子树 
				if(!dfs(i,r,flag)) return false;//判断右子树 
				
				break;
 			}
 			if(i==r)//如果找不到比根节点大的，即只有左子树 
 			{
 				if(!dfs(l+1,r,flag)) return false;	//判断左子树 
			}
		}
	}
	else//镜像二叉搜索树，原理同上，修改符号即可 
	{
		for(int i=l+1;i<=r;i++)
		{
			if(a[i]<root)
			{
				for(int j=i+1;j<=r;j++)
				if(a[j]>=root) return false;
				
				if(!dfs(l+1,i-1,flag)) return false;
				if(!dfs(i,r,flag)) return false;
				
				break;
 			}
 			if(i==r)
 			{
 				if(!dfs(l+1,r,flag)) return false;	
			}
		}	
	}
	q.push(root);//将根节点放入队列，即按左右根的形式放入 
	return true;
}

void print()
{
	cout<<"YES"<<endl;
	int flag=1;
	while(!q.empty())//从头开始遍历队列 
	{
		if(flag) flag=0;
		else cout<<" ";
		cout<<q.front();
		q.pop();
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];//为数组赋值 
	if(dfs(1,n,1))//判断是否为二叉搜索树 
	{
		print();
		return 0;
	}
	else
	{
		while(!q.empty())//清空数组，为下一次判断做准备 
		q.pop();
	}
	if(dfs(1,n,0))//判断是否为镜像二叉搜索树 
	{
		print();
		return 0;
	}
	else cout<<"NO"<<endl;//还不是就输出NO 
}