#include <string>
using namespace std;

template<class K, class T> 
class T23
{
	Internal* root; //указатель на корень
	int size; //текущий размер дерева
	void _Clear(Internal*); //рекурсивная очистка дерева
	bool _Insert(Node*, Node* , Node*& ,K&); //рекурсивная функция вставки
	bool _Delete(Internal*,K,Leaf*&,bool &one_sone); //рекурсивная функция удаления
	T _Get(Internal*,K); //рекурсивная функция поиска
	void _Copy(Internal*);
	int cnt; //счетчик количества просомтренных операцией узлов дерева
public:
	T23();  //конструктор
	T23(T23<K, T>& t); //Конструктор копирования
	~T23(); //деструктор
	bool Insert(K,T); //включение нового элемента с заданным ключом
	bool Delete(K);   //удаление элемента с заданным ключом
	void Show();
	int getCountNodesView() 
	{
		int temp = cnt;
		cnt = 0;
		return temp;
	}
	class Iterator
	{
	public:
		Iterator(T23<K, T>* owner);
		void beg();
		void end();
		void next();
		void prev();
		bool IsOff();
		T& operator*();
	private:
		T23<K, T>* tree;
		Leaf* cur;
		Leaf* _FindMin(Internal* t);  //поиск мин. ключа
		Leaf* _FindMax(Internal *t);   //поиск макс. ключа
		void _Next(Internal *t); //рекурсивная функция перехода к следующему ключу
		void _Prev(Internal *t);	//К предыдущему
	};
};


template<class K, class T>
T23<K,T>::T23(T23<K,T>& t)
{
	root = NULL; //указатель на корень дерева
	cnt = size = 0; //сброс счетчика и размера дерева в 0
	_Copy(t.root);
}

template<class K, class T>
void T23<K, T>::_Copy(Internal *t)
{
  if (t == NULL) return;
  if (t->son1->type() == 0)
  {
    if (t->son1) Insert(t->son1->key, t->son1->value);
    if (t->son2) Insert(t->son2->key, t->son2->value);
    if (t->son3) Insert(t->son3->key, t->son3->value);
    return;
  }
  _Copy(((Internal*)t->son1, tree));
  Insert(t->son1->key, t->son1->value);
  _Copy(((Internal*)t->son2, tree));
  Insert(t->son2->key, t->son2->value);
  if (t->son3)
  {
    _Copy(((Internal*)t->son3, tree));
    Insert(t->son3->key, t->son3->value);
  }
}

template<class K, class T> int T23<K,T>::GetSize(){ return size; } //опрос размера дерева

template<class K, class T> 
void T23<K,T>::Clear() //функция очистки дерева
{
	_Clear(root);  //вызов функции рекурсивной очистки дерева
	delete root;    //удалили корень
	root=NULL;    //сбросили указатель на корень в NULL
	size=0;     //размер дерева 0
}

template<class K, class T> 
void T23<K,T>::_Clear(Internal *t)  //функция рекурсивной очистки дерева
{
	if(t==NULL) return; //если дерево и так пустое
	if(t->son1->type() == 0) 
	{
		if(t->son1) delete t->son1; //удаление 1-го листа
		if(t->son2) delete t->son2; //удаление 2-го листа
		if(t->son3) delete t->son3; //удаление 3-его листа
		return;
	}
	_Clear(((Internal*)t->son1)); //идем  удалять из 1-го поддерева 
	delete t->son1; //удаление 1-го поддерева
	_Clear(((Internal*)t->son2)); //идем удалять из 2-го поддерева
	delete t->son2; //удаление 2-го поддерева 
	if(t->son3) //идем удалять из 3-го поддерева
	{
		_Clear(((Internal*)t->son3));
		delete t->son3; //удаление 3-го поддерева
	}
}




template<class K, class T> 
void T23<K,T>::Show() //функция распечатки дерева
{
    if (IsEmpty())
		return;
	root->Show(0);
}

template<class K, class T> 
bool T23<K,T>::Insert(K k, T value) //функция вставки в дерево
{
	Node *lt = new Leaf(k,value);  //создали листок
	if(root == NULL)      //если дерево пустое
		{
		root = new Internal;   //создаем дерево
		root->son1=lt;  //создали листок
		root->son2 = root->son3 = NULL;
		size++; //увеличили счетчик размера дерева
		
		return true;
		}
	if (root->son2 == NULL)
		{
		 if (((Leaf*)root->son1)->key < k) 
			{
			root->son2=lt;
			root->key1 = k;
			size++; //увеличили счетчик размера дерева
			return true;
			}
		 else 
			{
			 if (((Leaf*)root->son1)->key > k)
				{
				 root->son2=root->son1;
				 root->key1=((Leaf*)root->son1)->key;
				 root->son1=lt;
				 size++; //увеличили счетчик размера дерева
				 
				 return true;
				}
			 else
				{
				 delete lt;
				 return false;
				}
			}

		}
	Node *tbk = new Internal;
	K lbk;
	bool inserted=_Insert(root,lt,tbk,lbk); //вызов функции рекурсивной вставки в дерево
	if (inserted == false) 
	{
		delete lt;
		return false;
	}
	if (tbk != NULL) //если появилось новое поддерево (произошло расщепление)
	{
		Node *temp;
		temp=root; //то формируем итоговое дерево,
		root=new Internal;   //создаем дерево
		root->son1=temp;	//1-ым сыном которого будет корень "старого" дерева,
		root->son2=tbk;    //а 2-ым сыном будет "новое" поддерево
		root->key1=lbk;
		root->son3=NULL;
		
	}
	return true;
}
													
template<class K, class T> 
bool T23<K,T>::_Insert(Node *t,Node *lt,Node *&tup,K &lup) //функция рекурсивной вставки в дерево
{
	cnt++;
	int child=0;
	tup=NULL;
	if(t->type()==0)
		{
		 if (((Leaf*)t)->key==((Leaf*)lt)->key)  
			 return false;
		 else
			{
			 tup=lt;
			 if ( (((Leaf*)t)->key) < ( ((Leaf*)lt)->key) ) lup=((Leaf*)lt)->key;
			 else
				{
				 lup=((Leaf*)t)->key;
				 K temp1;
				 T temp2;
				 temp1=((Leaf*)t)->key;
				 ((Leaf*)t)->key=((Leaf*)lt)->key;
				 ((Leaf*)lt)->key=temp1;
				 temp2=((Leaf*)t)->value;
				 ((Leaf*)t)->value=((Leaf*)lt)->value;
				 ((Leaf*)lt)->value=temp2;
				}			
			}
		 size++;
		 return true;
		}
	Node *w;
	if ( (((Leaf*)lt)->key) < (((Internal*)t)->key1))
		{
		 child=1;
         w=((Internal*)t)->son1;
		}
	else
		{
		 if( (((Internal*)t)->son3==NULL) || ( ((((Internal*)t)->son3)!=NULL) & (((Leaf*)lt)->key<((Internal*)t)->key2)))
			{
			 child=2;
			 w=((Internal*)t)->son2;
			}
		 else
			{
			 child=3;
			 w=((Internal*)t)->son3;
			}
		}
	K lbk;
	Node *tbk=new Internal;
	bool inserted=_Insert(w,lt,tbk,lbk);

	if (inserted==true)
		{
		 if (tbk!=NULL)
			{	
			 if (((Internal*)t)->son3==NULL)
				{
				 if (child==2)
					{
					((Internal*)t)->son3=tbk;
					((Internal*)t)->key2=lbk;
					}
				 else
					{
					 ((Internal*)t)->son3=((Internal*)t)->son2;
					 ((Internal*)t)->key2=((Internal*)t)->key1;
					 ((Internal*)t)->son2=tbk;
					 ((Internal*)t)->key1=lbk;
					}				
				}
			 else
				{				 
				 cnt++;
				 tup=new Internal;
				 if (child==3)
					{
					 ((Internal*)tup)->son1=((Internal*)t)->son3;
					 ((Internal*)tup)->son2=tbk;
					 ((Internal*)tup)->son3=NULL;
					 ((Internal*)tup)->key1=lbk;
					 ((Internal*)t)->son3=NULL;
					 lup=((Internal*)t)->key2;
					}
				 else
					{
					 ((Internal*)tup)->son2=((Internal*)t)->son3;
					 ((Internal*)tup)->key1=((Internal*)t)->key2;
					 ((Internal*)tup)->son3=NULL;
					 if (child==2)
						{
						 ((Internal*)tup)->son1=tbk;
						 lup=lbk;
						}
					 if (child==1)
						{
						 ((Internal*)tup)->son1=((Internal*)t)->son2;
						 ((Internal*)t)->son2=tbk;
						 lup=((Internal*)t)->key1;
						 ((Internal*)t)->key1=lbk;
						}
					}
				 ((Internal*)t)->son3=NULL;
				}			 
			}

		}
	return inserted;
}

template<class K, class T> 
bool T23<K,T>::Delete(K k) // функция удаления 
{
	Internal *t;
	Leaf *tmin;
	bool one;
	int fl=size;
	if(root==NULL) 
		return false;
	if(root->son2==NULL)
	{
		if(((Leaf*)root->son1)->key==k)
		{
		delete root->son1;
		root->son1=NULL;
		delete root;
		root=NULL; 
		size=0;
		return true;
		}

		else 
		{ 
			return false; 
		}
	}
	bool deleted;
	deleted=_Delete(root,k,tmin,one);
	if(deleted==true)
	{
		if(one==true)
		{
			if(root->son1->type()==1)
			{
			t=((Internal*)root->son1);
			delete root; 
			root=t;
			}
		}
	}
	return deleted;
}

template<class K, class T> 
bool T23<K,T>::_Delete(Internal *t,K k, Leaf *&tlow1, bool &one_son) //функция рекурсивного удаления из дерева
{
	Internal *w, *y, *z;
	int child;
	cnt++;
	tlow1=NULL;
	one_son = false;
	if(t->son1->type()==0)
	{
		if(((Leaf*)t->son1)->key==k)
		{
			delete t->son1;  
			t->son1=t->son2;
			t->son2=t->son3;
			t->son3=NULL;
			t->key1=t->key2;
			t->key2=INT_MAX; 
			size--;
		}

		else
		{
			if(((Leaf*)t->son2)->key==k)
			{
				delete t->son2;   
				t->son2=t->son3;
				t->son3=NULL;
				t->key1=t->key2;
				t->key2=INT_MAX; 
				size--;
			}
			else
			{
				if((t->son3!=NULL)&&(((Leaf*)t->son3)->key==k))
				{
				delete t->son3;  ;
				t->son3=NULL;
				size--;
				}
				else
				{
				return false;
				}
			}
		}
		tlow1=((Leaf*)t->son1);
		if(t->son2==NULL)
		{
			one_son=true;
		}
		return true;
	}
	if (k < t->key1)
	{
		child = 1;
		w = ((Internal*)t->son1);
	}
	else
	{
		if((t->son3==NULL)||(k<t->key2))
		{
			child=2;
			w=((Internal*)t->son2);
		}
		else
		{
			child=3;
			w=((Internal*)t->son3);
		}
	}
	bool one_son_bk;
	Leaf *tlow1_bk;
	if((_Delete(w,k,tlow1_bk,one_son_bk))==false)
	{
		return false;
	}
	
	tlow1=tlow1_bk;
	//one_son=false;
	if(tlow1_bk!=NULL)
	{
		if(child==2)
		{
			t->key1=((Leaf*)tlow1_bk)->key;
			tlow1=NULL;
		}
		if(child==3)
		{
			t->key2=((Leaf*)tlow1_bk)->key;
			tlow1=NULL;
		}
	}
	if (one_son_bk == false)
		return true;
	if(child==1)
	{
	y=((Internal*)t->son2);
		if(y->son3!=NULL)
		{
		w->son2=y->son1;
		w->key1=t->key1;     
		t->key1=y->key1;
		y->son1=y->son2;
		y->son2=y->son3;
		y->key1=y->key2;
		y->son3=NULL;
		y->key2=INT_MAX; 
		}
		else
		{
		y->son3 = y->son2;
		y->key2 = y->key1;
		y->son2 = y->son1;
		y->key1 = t->key1;
		y->son1 = w->son1;
		delete w;
		t->son1 = t->son2;
		t->son2 = t->son3;
		t->key1 = t->key2;
		t->son3 = NULL;
		t->key2 = INT_MAX;
		//one_son=true; 
		if (t->son2 == NULL)
			{
				one_son = true;
			}
		}
		return true;
	}
	if(child==2)
	{
	y=((Internal*)t->son1);
		if(y->son3!=NULL)
		{
		w->son2=w->son1;
		w->key1=t->key1;
		w->son1=y->son3;
		y->son3=NULL;
		t->key1=y->key2;
		y->key2=INT_MAX;  
		//one_son=false;
		return true;
		}
		else
		{
			z = ((Internal*)t->son3);
			if ((z != NULL) && (z->son3 != NULL))
			{
				w->son2 = z->son1;
				w->key1 = t->key2;
				t->key2 = z->key1;
				z->son1 = z->son2;
				z->son2 = z->son3;
				z->key1 = z->key2;
				z->son3 = NULL;
				z->key2 = INT_MAX;
				//one_son=false;
				return true;
			}
		}
		y->son3=w->son1;
		y->key2=t->key1;
		delete w;        
		t->son2=t->son3;
		t->key1=t->key2;
		t->son3=NULL;
		t->key2=INT_MAX; 
		if(t->son2==NULL)
		{ 
			one_son=true; 
		}
		return true;
	}
	y=((Internal*)t->son2);
	if(y->son3!=NULL)
	{
	w->son2=w->son1;
	w->key1=t->key2;
	w->son1=y->son3;
	t->key2=y->key2; 
	y->son3=NULL;
	y->key2=INT_MAX; 
	}
	else
	{
	y->son3=w->son1;
	y->key2=t->key2;
	t->son3=NULL;
	t->key2=INT_MAX; 
	delete w; 
	}
	return true;
}

template <class K, class T>
T23<K,T>::Iterator::Iterator(T23<K, T>* t)  //конструктор 
{
	tree = t;
	if (tree)
	{
		if (tree->root)
		{
			cur = _FindMin(tree->root);
		}
		else { cur = NULL; }
	}
	else { cur = NULL; }
}
template <class K, class T>
void T23<K, T>::Iterator::beg() //установка на первый узел в дереве (с мин. ключом)
{
	if (tree->root != 0)
	{
		cur = _FindMin(tree->root);
	}
}
template <class K, class T>
void T23<K, T>::Iterator::end() //установка на последний узел в дереве (с макс. ключом)
{
	if (tree->root != 0)
	{
		cur = _FindMax(tree->root);
	}
}

template <class K, class T>
void T23<K, T>::Iterator::next()   //переход к следующему ключу 
{
	if (tree->root)
	{
		_Next(tree->root);
	}
}

template <class K, class T>
void T23<K, T>::Iterator::prev()  //переход к предыдущему ключу
{
	if (tree->root)
	{
		_Prev(tree->root);
	}
}

template <class K, class T>
bool T23<K, T>::Iterator::IsOff()  //проверка состояния итератора
{
	return (cur == 0);
}

template <class K, class T>
T& T23<K, T>::Iterator::operator*()  //доступ по чтению и записи к текущему узлу
{
	if (!cur) throw TreeException();
	return cur->value;
}

template <class K, class T>
typename T23<K, T>::Leaf* T23<K, T>::Iterator::_FindMin(Internal* t)  //поиск мин. ключа
{
	if (t == NULL) return NULL;
	if ((t->son1->type() == 0))
	{
		return ((Leaf*)t->son1);
	}
	return _FindMin(((Internal*)t->son1));
}
template <class K, class T>
typename T23<K, T>::Leaf* T23<K, T>::Iterator::_FindMax(Internal* t)   //поиск макс. ключа
{
	if (t == NULL)return 0;
	if ((t->son1->type() == 0))
	{
		if (t->son3)return ((Leaf*)t->son3);
		if (t->son2)return ((Leaf*)t->son2);
		return ((Leaf*)t->son1);
	}
	if (t->son3)return _FindMax(((Internal*)t->son3));
	if (t->son2)return _FindMax(((Internal*)t->son2));
	return _FindMax(((Internal*)t->son1));
}

template <class K, class T>
void T23<K, T>::Iterator::_Next(Internal* t) //рекурсивная функция перехода к следующему ключу
{
	if (t == NULL) return;
	if ((t->son1->type() == 0))
	{
		if (t->son1 == cur)
		{
			if (t->son2) cur = ((Leaf*)t->son2);
			return;
		}

		if (t->son2)
		{
			if (t->son2 == cur)
			{
				if (t->son3)cur = ((Leaf*)t->son3);
				else cur = NULL;
				return;
			}
		}

		if (t->son3)
		{
			if (t->son3 == cur)
			{
				cur = NULL;
				return;
			}
		}
		return;
	}

	if (cur == NULL)
		return;
	if (t->key1 > cur->key)
	{
		_Next(((Internal*)t->son1));
		if (cur == NULL)
		{
			cur = _FindMin(((Internal*)t->son2));
		}
		return;
	}

	if (t->key2 > cur->key)
	{
		_Next(((Internal*)t->son2));
		if (cur == NULL)
		{
			if (t->son3)cur = _FindMin(((Internal*)t->son3));
		}
		return;
	}

	_Next(((Internal*)t->son3));
	if (cur == NULL)
	{
		cur = _FindMax(((Internal*)t->son3));
	}
	return;
}

template <class K, class T>
void T23<K, T>::Iterator::_Prev(Internal* t)
{
	if (t == NULL)return;
	if ((t->son1->type() == 0))
	{
		if (t->son1 == cur)
		{
			cur = NULL;
			return;
		}

		if (t->son2)
		{
			if (t->son2 == cur)
			{
				cur = ((Leaf*)t->son1);
				return;
			}
		}

		if (t->son3)
		{
			if (t->son3 == cur)
			{
				cur = ((Leaf*)t->son2);
				return;
			}
		}
		return;
	}

	if (cur == NULL)
		return;            //итератор вне дерева
	if (t->key1 > cur->key)
	{
		_Prev(((Internal*)t->son1));
		if (cur == NULL) { ; }
		return;
	}

	if (t->key2 > cur->key)
	{
		_Prev(((Internal*)t->son2));
		if (cur == NULL)
		{
			cur = _FindMax(((Internal*)t->son1));
		}
		return;
	}

	_Prev(((Internal*)t->son3));
	if (cur == NULL)
	{
		cur = _FindMax(((Internal*)t->son2));
	}
	return;
}
