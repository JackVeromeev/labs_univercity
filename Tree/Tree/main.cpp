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



void add(TREE **root, int addinf)// функция добавления элементов в дерево рекурсивно
{
	if (!(*root))
	{
		if (!(*root = (TREE *)calloc(1, sizeof(TREE))))
		{
			puts("Ошибка");
			_getch();
			return ;
		}

		(*root)->info = addinf;// записываем информацию
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
			add(&((*root)->right), addinf);// вызываем функцию для правого поддерева
		}
		else
		{
			add(&((*root)->left), addinf);// вызывае функцию для левого поддерева
		}
	}
}

void see_in_line(TREE *root)
{
	if (!root)	
	{
		puts("Дерево пустое");
		return;
	}
	if (root->left)
		see_in_line(root->left);
	printf("%d(%d)\n", root->info, root->repeats);
	if (root->right)
		see_in_line(root->right);
	return;
}

void TreeToLine(TREE *root, line** head)// перезапись элементов дерева в очередь 
{
	if (!(*head))		
	{
		if (!((*head) = (line*)calloc(1, sizeof(line))))	
		{
			puts("Ошибка");
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
			puts("Ошибка");
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
			puts("Ошибка");
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
	if (!(*root))// если нет корня нового дерева
	{
		if (!((*root) = (TREE*)calloc(1, sizeof(TREE)))) // выделяем память под него
		{
			puts("Ошибка");
			_getch();
			return;
		}
	}

	int n = 0; // n будет показывать кол-во элементов в очереди
	line *element; // указатель которым будем ходить по очереди дабы не потерять голову
	element = head; // элемент поставили в начало очереди
	while (element != tail)// пока не дошли до хвоста очереди перемещаем элемент
	{
		element = element->next;
		n++;			// в конце цикла n будет равно кол-ву элементов в очереди 
	}
	element = head;// снова ставим элемент в начало очереди
	n = n / 2;			// n делим на 2, находя таким образом номер центрального элемента
	while (n--)
		element = element->next;	// перемещаем элемент на центральный элемент очереди

	TREE *list; // создаём новый указатель типа TREE который будем записывать в новое дерево
	if (element != head) // если элемент не стоит в голове очереди
	{
		if (!((*root)->left))// если в новом дереве нет левого указателя
		{
 			list = (TREE*)calloc(1, sizeof(TREE));//выделяем память под указатель типа TREE 
			if (!list)
			{
				puts("Ошибка");
				_getch();
				return;
			}
			(*root)->left = list;// связываем элемент с корнем дерева
		}
		LineToTree(&((*root)->left), head, element->prev);// вызываем функцию для левого указателя головы очереди и предыдущего элемента то центра к голове
	}
	if (element != tail)// тоже самое для правого указателя т.е для части от центрального элемента +1 до хвоста
	{
		if (!((*root)->left))
		{
			list = (TREE*)calloc(1, sizeof(TREE));
			if (!list)
			{
				puts("Ошибка");
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
	if (!(*root)) // если пустой корень дерева
	{
		puts("Дерево пустое");
		return ;
	}
	line *head; // создаём голову очереди в которую будем записывать элементы дерева
	head = nullptr;
	TreeToLine(*root, &head);// вызываем функцию записи дерева в очередь
	line *tail;  // создаём хвост очереди 
	tail = head;// т.к. после записи голова стоит в конце очереди то приравниваем её к хвосту
	while (head->prev) //пока существует указатель на предыдущий элемент перед головой перемещаемся. В итоге стоим в начале очереди.Голова стоит на своём месте
		head = head->prev;
	FreeTree(root); // очищаем дерево из которого вычитывал элементы в очередь
	(*root) = nullptr; // зануляем корень
	LineToTree(root, head, tail); // вызываем функцию для перезаписи очереди в дерево
	puts("Сбалансировано");
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
			puts("Элемент не найден");
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

void see_in_tree(TREE* root,int level) // функция вывода дерева по уровням
{
	int i;
	if (!root)
	{
		printf("Ошибка");
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
		puts("1) Добавить\n2) Вывод в столбец\n3) Поиск и удаление\n4) Балансировка дерева\n5) Вывести по уровням\n6) Удаление рекурсией\n0) Выход\n");
		while ((c = _getch()) != '1' && c != '2' && c != '3' && c != '4' && c != '0' && c != '5' && c != '6')
		{
			printf("%c\n", c);
			puts("Неверная комманда");
			fflush(stdin);
		}
		switch (c)
		{
		case '1':
			int i;
			system("CLS");
			printf("Добавление элементов в дерево\nInfo: ");
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
			puts("До свиданья");
			_getch();
		}
	}
	return 0;
}