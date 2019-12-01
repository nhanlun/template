struct Node
{
	Node * pLeft;
	Node * pRight;
	int val, height;
	Node()
	{
		val = 0;
		height = 1;
		pLeft = pRight = nullptr;
	}
	Node(int x)
	{
		val = x;
		height = 1;
		pLeft = pRight = nullptr;
	}
	~Node()
	{
		delete pLeft;
		delete pRight;
	}
};

int GetHeight(Node * root)
{
	if (root == nullptr) return 0;
	return root -> height;
}

int CalcHeight(Node * root)
{
	int LeftHeight = GetHeight(root -> pLeft);
	int RightHeight = GetHeight(root -> pRight);
	return (1 + max(LeftHeight, RightHeight));
}

int CalcBalance(Node * root)
{
	int LeftHeight = GetHeight(root -> pLeft);
	int RightHeight = GetHeight(root -> pRight);
	return LeftHeight - RightHeight;
}

void RightRotate(Node* &root)
{
	Node* tmp1 = root->pLeft;
	Node* tmp2 = tmp1->pRight;

	root->pLeft = tmp2;
	tmp1->pRight = root;

	root->height = CalcHeight(root);
	tmp1->height = CalcHeight(tmp1);

	root = tmp1;
}

void LeftRotate(Node* &root)
{
	Node* tmp1 = root->pRight;
	Node* tmp2 = tmp1->pLeft;

	root->pRight = tmp2;
	tmp1->pLeft = root;

	root->height = CalcHeight(root);
	tmp1->height = CalcHeight(tmp1);

	root = tmp1;
}

void Insert(Node* &root, int x)
{
	if (root == nullptr)
	{
		root = new Node(x);
		return;
	}
	if (root->val > x) Insert(root->pLeft, x);
	else if (root->val < x) Insert(root->pRight, x);
	else return;
	root->height = CalcHeight(root);
	int balanceFactor = CalcBalance(root);

	// Left Left case
	if (balanceFactor > 1 && x < root->pLeft->val) RightRotate(root);
	// Left Right case
	if (balanceFactor > 1 && x > root->pLeft->val)
	{
		LeftRotate(root->pLeft);
		RightRotate(root);
	}
	// Right Right case
	if (balanceFactor < -1 && x > root->pRight->val) LeftRotate(root);
	// Right Left case
	if (balanceFactor < -1 && x < root->pRight->val) 
	{
		RightRotate(root->pRight);
		LeftRotate(root);
	}
}