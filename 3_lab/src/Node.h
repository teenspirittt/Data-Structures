#pragma once

using namespace std;
typedef unsigned int uint;

template<typename K, typename V>
class Node {
	public:
		virtual bool inner() = 0;
		virtual void Show(int level) = 0;
};

template<typename K, typename V>
class Internal: public Node {
	public:
		Node *son1, *son2, *son3; 
		K key1, low3; 
		bool inner(){ return 1; }
		Internal() {
			son1 = son2 = son3 = NULL; 
			key1 = low3 = INT_MAX;
		}
		void Show (int level) {
			if(son3 != NULL)
				son3->Show(level+1);
			if(son2 != NULL) 
				son2->Show(level+1);
			for(int i=0;i<6*level;i++) cout<<" ";
			if(son2 == NULL) 
				cout<<"-";
			else
				cout << key1;
			if(son3==NULL)
				cout<<"," << "-";
			else 
				cout<< "," <<low3;
			cout<<endl;
			son1->Show(level+1);			
		}
};



template<typename K, typename V>
class Leaf: public Node {
	public:
		K key;
		V data;
		bool inner() { return 0; }
		void Show(int level) {
			for (int i = 0; i < 6 * level; i++) cout << " ";
			cout << key << endl;
		}
		Leaf(K key_, T data_) { key = key_; data = data_; }
};