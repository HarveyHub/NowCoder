#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


struct OptInf
{
	OptInf(char ch, int p, int l);
	char opt;
	int pos;
	int level;//parenthesis levels
	
	char priority;//sort priority
	
};

OptInf::OptInf(char ch, int p, int l):opt(ch),pos(p), level(l)
{
	if(ch == '+' || ch == '-')
	{
		this->priority = 1;
	}
	else
		this->priority = 0;
}

ostream& print(ostream& os, OptInf& opt)
{
	os << "pos: " << opt.pos << "\tlevel: " << opt.level << "\topt: " << opt.opt << endl;
	return os;
}

int OptCompare(OptInf &l, OptInf &r)
{
	if(l.level == r.level)
	{
		return l.priority > r.priority;
	} 
	return l.level < r.level;
}


struct BTNode
{
	union
	{
		OptInf *opt;	
		double value;
	}data;
	BTNode *left;
	BTNode *right;

};

bool BSTInsertOpt(BTNode* &p, OptInf& opt)  
{  
    if(NULL == p) // 空树  
    {  
        p = new BTNode();  
        p->data.opt = &opt;  
        p->left = p->right = NULL;  
        return true;  
    }  
  
	if(p->data.opt->pos == opt.pos)
		return false;
  
    if(opt.pos < p->data.opt->pos)  // 递归  
        return BSTInsertOpt(p->left, opt);  
  
    return BSTInsertOpt(p->right, opt); // 递归  
} 

void preOrder(BTNode* p)
{
	stack<BTNode*> nodes;
	while(p != NULL || !nodes.empty())
	{
		while(p != NULL)
		{
			nodes.push(p);
			p = p->left;
		}
		p = nodes.top();
		nodes.pop();
		cout << p->data.opt->pos << " ";
		p = p->right;
	}
} 

BTNode* createNode(string &str, int start, int end)
{
	BTNode* p = new BTNode();
	p->data.value = start + end;
	return p;
}

void BSTInsertValue(BTNode* &p, string& str)
{
	int start = 0, end = str.size() - 1;
	stack<BTNode*> nodes;
	BTNode* q;
	while(p != NULL || !nodes.empty())
	{
		while(p != NULL)
		{
			nodes.push(p);
			p = p->left;
		}
		p = nodes.top();
		nodes.pop();
		q = nodes.top();
		if(p->left == NULL)
		{
			p->left = createNode(str, start, p->data.opt->pos-1);
			start = p->data.opt->pos+1;
		}
		if(p->right == NULL)
		{
			
			p->right = createNode(str, p->data.opt->pos+1, q->data.opt->pos-1);
		}
		p = p->right;
	}
	
}

// 先序遍历  
void preOrderTraverse(BTNode* T)  
{  	
    if(T != NULL)  
    {  
        cout << T->data.opt->pos << " "; 
        preOrderTraverse(T->left);  
        preOrderTraverse(T->right);  
    }  
}


void inOrderTraverse(BTNode* T)
{
	if(T != NULL)  
    {  
		inOrderTraverse(T->left);
        cout << T->data.opt->pos << " ";
		inOrderTraverse(T->right);
    }  
} 


// ((5+7)*4-4)+7*6
int main()
{
	set<char> opts = {'+', '-', '*', '/'};
	string exp;
	while(cin >> exp)
	{
		vector<OptInf> optinfs;
		int level = 0, len = exp.size(), i;
		for(i = 0; i < len; i++)
		{
			if(exp[i] == '(')
				level ++;
			if(exp[i] == ')')
				level --;
			if(opts.find(exp[i]) != opts.end())
			{
				optinfs.push_back(OptInf(exp[i], i, level));
			}
		}
		
		for(auto i : optinfs)
			print(cout, i);
		cout << endl;
		sort(optinfs.begin(), optinfs.end(), OptCompare);
		for(auto i : optinfs)
			print(cout, i);
		
		BTNode *root = NULL;
		// root.data.opt = optinfs[0].opt;
		
		// CreateBTNode(root.right, exp, optinfs_origin[0].pos+1,)
		for(size_t i = 0; i < optinfs.size(); i++)
		{
			BSTInsertOpt(root, optinfs[i]);
		}
		preOrderTraverse(root);
		cout << endl;
		inOrderTraverse(root);
		cout << endl;
		preOrder(root);
		cout << endl;
		preOrderTraverse(root);
	}
}