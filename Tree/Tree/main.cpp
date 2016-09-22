#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>


typedef struct TREE
{
	int info;
	int repeats;
	TREE *left, *right;
} TREE;


typedef struct line
{
	int info;
	int repeats;
	line *prev, *next;
} line;



void add(TREE **root, int addinf)// ������� ���������� ��������� � ������ ����������
{
	if (!(*root))
	{
		if (!(*root = (TREE *)calloc(1, sizeof(TREE))))
		{
			puts("������");
			_getch();
			return ;
		}

		(*root)->info = addinf;// ���������� ����������
		(*root)->repeats = 1;
		return;
	}
	else
	{
		if ((*root)->info == addinf)
		{
			(*root)->repeats++;
			return;
		}
		if ((*root)->info < addinf)
		{
			add(&((*root)->right), addinf);// �������� ������� ��� ������� ���������
		}
		else
		{
			add(&((*root)->left), addinf);// ������� ������� ��� ������ ���������
		}
	}
}

void see_in_line(TREE *root)
{
	if (!root)	
	{
		puts("������ ������");
		return;
	}
	if (root->left)
		see_in_line(root->left);
	printf("%d(%d)\n", root->info, root->repeats);
	if (root->right)
		see_in_line(root->right);
	return;
}

void TreeToLine(TREE *root, line** head)// ���������� ��������� ������ � ������� 
{
	if (!(*head))		
	{
		if (!((*head) = (line*)calloc(1, sizeof(line))))	
		{
			puts("������");
			_getch();
			return;
		}
	}

	if (root->left)
	{
		TreeToLine(root->left, head);

		line *element;
		if (!(element = (line*)calloc(1, sizeof(line))))
		{
			puts("������");
			_getch();
			return;
		}

		(*head)->next = element;
		element->prev = (*head);
		(*head) = (*head)->next;
	}

	(*head)->info = root->info;
	(*head)->repeats = root->repeats;

	if (root->right)
	{
		line *element;
		if (!(element = (line*)calloc(1, sizeof(line))))
		{
			puts("������");
			_getch();
			return;
		}

		(*head)->next = element;
		element->prev = (*head);
		(*head) = (*head)->next;
		TreeToLine(root->right, head);
			return;
	}
	return;
}

void LineToTree(TREE **root, line *head, line *tail)
{
	if (!(*root))// ���� ��� ����� ������ ������
	{
		if (!((*root) = (TREE*)calloc(1, sizeof(TREE)))) // �������� ������ ��� ����
		{
			puts("������");
			_getch();
			return;
		}
	}

	int n = 0; // n ����� ���������� ���-�� ��������� � �������
	line *element; // ��������� ������� ����� ������ �� ������� ���� �� �������� ������
	element = head; // ������� ��������� � ������ �������
	while (element != tail)// ���� �� ����� �� ������ ������� ���������� �������
	{
		element = element->next;
		n++;			// � ����� ����� n ����� ����� ���-�� ��������� � ������� 
	}
	element = head;// ����� ������ ������� � ������ �������
	n = n / 2;			// n ����� �� 2, ������ ����� ������� ����� ������������ ��������
	while (n--)
		element = element->next;	// ���������� ������� �� ����������� ������� �������

	TREE *list; // ������ ����� ��������� ���� TREE ������� ����� ���������� � ����� ������
	if (element != head) // ���� ������� �� ����� � ������ �������
	{
		if (!((*root)->left))// ���� � ����� ������ ��� ������ ���������
		{
 			list = (TREE*)calloc(1, sizeof(TREE));//�������� ������ ��� ��������� ���� TREE 
			if (!list)
			{
				puts("������");
				_getch();
				return;
			}
			(*root)->left = list;// ��������� ������� � ������ ������
		}
		LineToTree(&((*root)->left), head, element->prev);// �������� ������� ��� ������ ��������� ������ ������� � ����������� �������� �� ������ � ������
	}
	if (element != tail)// ���� ����� ��� ������� ��������� �.� ��� ����� �� ������������ �������� +1 �� ������
	{
		if (!((*root)->left))
		{
			list = (TREE*)calloc(1, sizeof(TREE));
			if (!list)
			{
				puts("������");
				_getch();
				return;
			}
			(*root)->right = list;
		}
		LineToTree(&((*root)->right), element->next, tail);
	}

	(*root)->info = element->info;
	(*root)->repeats = element->repeats;
	return;
}

void FreeTree(TREE **root)
{
	if (!(*root))
		return;
	if ((*root)->left)	
	{
		FreeTree(&((*root)->left));
		(*root)->left = nullptr;
	}
	if ((*root)->right)	
	{
		FreeTree(&((*root)->right));
		(*root)->right = nullptr;
	}
	free(*root);			
	return;
}

void BalanceTree(TREE **root)
{
	if (!(*root)) // ���� ������ ������ ������
	{
		puts("������ ������");
		return ;
	}
	line *head; // ������ ������ ������� � ������� ����� ���������� �������� ������
	head = nullptr;
	TreeToLine(*root, &head);// �������� ������� ������ ������ � �������
	line *tail;  // ������ ����� ������� 
	tail = head;// �.�. ����� ������ ������ ����� � ����� ������� �� ������������ � � ������
	while (head->prev) //���� ���������� ��������� �� ���������� ������� ����� ������� ������������. � ����� ����� � ������ �������.������ ����� �� ���� �����
		head = head->prev;
	FreeTree(root); // ������� ������ �� �������� ��������� �������� � �������
	(*root) = nullptr; // �������� ������
	LineToTree(root, head, tail); // �������� ������� ��� ���������� ������� � ������
	puts("��������������");
	_getch();
	return;
}

void delete_el(TREE ** root)
{
	int searchinf;
	printf("info: ");
	scanf("%d", &searchinf);
	TREE *parent, *current, *temp;
	parent = current = *root;
	int flag = false;
	while (!flag)
	{
		if (current->info == searchinf)
			flag = true;
		else
		{
			if (current->info < searchinf && current->right)
			{
				parent = current;
				current = current->right;
				continue;
			}
			if (current->info > searchinf && current->left)
			{
				parent = current;
				current = current->left;
				continue;
			}
			puts("������� �� ������");
			return;
		}
	}

	if (current->left == nullptr && current->right == nullptr)
	{
		if (parent->left == current)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		free(current);
		current = nullptr;
		return;
	}

	if (current->right)
	{
		if (!current->left)
			current->left = current->right;
		else
		{
			temp = current->left;
			while (temp->right)
				temp = temp->right;
			temp->right = current->right;
		}
	}
	if(parent == current)
		if(current->left)
			parent = current->left;
	else
		if (parent->left == current)
			parent->left = current->left;
		else
			parent->right = current->left;
	free(current);
	current = nullptr;
	return;
}

void see_in_tree(TREE* root,int level) // ������� ������ ������ �� �������
{
	int i;
	if (!root)
	{
		printf("������");
		return;
	}
	if (root->right)
		see_in_tree(root->right, level + 1);
	for (i = 0; i < level; i++)
		printf(".");
	printf("%d(%d)\n", root->info, root->repeats);

		if (root->left)
		see_in_tree(root->left, level + 1);
}

void recur_del(TREE ** root,int searchinf)
{
	static TREE *parent, *current, *temp;
	static int flag;
	if (!flag)
	{
		parent = current = *root;
		flag = 1;
	}
	if (flag==1)			// flag == 1 -- search
	{
		if (current->info == searchinf)
			flag = 2;
		else 
			if (current->info < searchinf && current->right)
			{
				parent = current;
				current = current->right;
				recur_del(root,searchinf);
			}
			else
				if (current->info > searchinf && current->left)
				{
					parent = current;
					current = current->left;
					recur_del(root,searchinf);
				}					
				else
				{
					puts("Element's not found");
					flag = 0;
					return;
				}
	}

	if (flag == 2)							// flag == 2 -- we found element and check location of current
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent->left == current)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			free(current);
			puts("Element's deleted");
			_getch();
			current = nullptr;
			flag = 0;
			return;
		}
		if (current->right)
		{
			if (!current->left)
				current->left = current->right;
			else
			{
				temp = current->left;
				flag = 3;					// flag == 3 -- we need to find rightest son of the left son of the current
				recur_del(root, searchinf);
				temp->right = current->right;
			}
		}
		if(parent == current)

			parent = current->left;
		else
			if (parent->left == current)
				parent->left = current->left;
			else
				parent->right = current->left;
		free(current);
		puts("Element's deleted");
		_getch();
		flag = 0;
	}
	if(flag == 3)
	{
		if(temp->right)
		{
			temp = temp->right;
			recur_del(root, searchinf);
		}
		return;
	}
	if(flag)
		flag = 0;
	return;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	TREE *root;
	root = nullptr;
	char c = 0;
	int level = 0;
	while (c != '0')
	{
		system("CLS");
		puts("1) ��������\n2) ����� � �������\n3) ����� � ��������\n4) ������������ ������\n5) ������� �� �������\n6) �������� ���������\n0) �����\n");
		while ((c = _getch()) != '1' && c != '2' && c != '3' && c != '4' && c != '0' && c != '5' && c != '6')
		{
			printf("%c\n", c);
			puts("�������� ��������");
			fflush(stdin);
		}
		switch (c)
		{
		case '1':
			int i;
			system("CLS");
			printf("���������� ��������� � ������\nInfo: ");
			while (!scanf("%d", &i))
			{
				puts("Incorrect input");
				fflush(stdin);
			}
			add(&root, i);
			break;
		case '2':
			see_in_line(root);
			_getch();
			break;
		case '3':
			delete_el(&root);
			_getch();
			break;
		case '4':
			BalanceTree(&root);
			_getch();
			break;
		case '5':
			see_in_tree(root, level);
			_getch();
			break;
		case '6':
			system("CLS");
			int searchinf;
			while (!scanf("%d", &searchinf))
			{
				puts("Incorrect input");
				fflush(stdin);
			}
			recur_del(&root, searchinf);
		case '0':
			FreeTree(&root);
			puts("�� ��������");
			_getch();
		}
	}
	return 0;
}