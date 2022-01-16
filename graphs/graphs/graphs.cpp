
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//DIRECTIONAL GRAPH REPRESENTATION
template<class T>
class Graph {
public:
	struct Node {
		T val;
		bool Isvisited = false;

	};
	vector<vector<Node>>* adj_marix;
	int current_v_number = 0;
	void add_edge(T u, T v);
	void add_vertex(T v);
	void breadth_firstsearch(T node);
	void depth_first_search(T node);
	void display_adj_matix();

	Graph(int node_count,T root_val) {
		adj_marix = new vector<vector<Node>>(node_count);

		Node root_n;
		root_n.val = root_val;
		current_v_number++;
		
		adj_marix->begin()->push_back(root_n);
	}
	~Graph() {
		adj_marix->clear();
		adj_marix->shrink_to_fit();
		delete adj_marix;
	}
};

template<class T>
void Graph<T>::add_edge(T u,T v) {
	
	typename vector<vector<Node>>::iterator it;
	Node vertices[2];
	for (it=adj_marix->begin();it !=adj_marix->begin()+current_v_number;it++)
	{
		
		if ((it->begin()->val) == u) {
			vertices[0].val = v;
			it->push_back(vertices[0]);
			break;
		}
			
	}

}
template<class T>
void Graph<T>::add_vertex(T v) {

	Node node;
	node.val = v;

	if (adj_marix->begin() + current_v_number != adj_marix->end()) {
		typename vector<vector<Node>>::iterator it= adj_marix->begin()+current_v_number;	
		it->push_back(node);
		current_v_number++;
	}
	else
		cout << "Graph is Full!"<<endl;

	
}
template<class T>
void Graph<T>::breadth_firstsearch(T node ) {

	queue<T> node_q;
	node_q.push(node);
	bool Isfirst = true;
	typename vector<vector<Node>>::iterator it;
	typename vector<Node>::iterator it2;
	while (!node_q.empty()) {
		node = node_q.front();
		cout << node_q.front() << " ";
		for (it = adj_marix->begin(); it != adj_marix->begin() + current_v_number; it++)
		{
			if (it->begin()->val == node) {
				it->begin()->Isvisited = true;
				for (it2 = it->begin(); it2 != it->end(); it2++) {
					if (!it2->Isvisited) {
						it2->Isvisited = true;
						node_q.push(it2->val);
					}
				}
				break;
			}

		}	
		node_q.pop();
	}	
}
template<class T>
void Graph<T>::depth_first_search(T node) {


	stack<T> node_s;
	node_s.push(node);
	typename vector<vector<Node>>::iterator it;
	typename vector<Node>::iterator it2;

	while (!node_s.empty()) {
		node = node_s.top();
		cout << node_s.top() << " ";
		node_s.pop();
		for (it = adj_marix->begin(); it != adj_marix->begin() + current_v_number; it++)
		{
			if (it->begin()->val == node) {
				it->begin()->Isvisited = true;
				for (it2 = it->begin(); it2 != it->end(); it2++) {
					if (!it2->Isvisited) {
						it2->Isvisited = true;
						node_s.push(it2->val);
					}
				}
				break;
			}
		}
	}
}

template<class T>
void Graph<T>::display_adj_matix() {

	typename vector<vector<Node>>::iterator it;
	typename vector<Node>::iterator it2;
	for (it = adj_marix->begin(); it!= adj_marix->begin()+current_v_number; it++)
	{
		for ( it2=it->begin(); it2!=it->end(); it2++)
		{
			cout << it2->val<<it2->Isvisited << " ";
		}
		cout << endl;
	}
}

int main()
{

	{	
		Graph<int> my_g(10, 5);
	/*	my_g.add_vertex(1);
		my_g.add_vertex(2);*/
		my_g.add_vertex(3);
	/*	my_g.add_vertex(4);*/
	/*	my_g.add_vertex(6);*/
		my_g.add_vertex(7);
		my_g.add_vertex(10);
		my_g.add_vertex(6);
		/*my_g.add_vertex(8);*/
		//my_g.add_vertex(9);
		//my_g.add_vertex(10);
	/*	my_g.add_edge(5, 8)*/;
		my_g.add_edge(5, 3);
		my_g.add_edge(3, 7);
		my_g.add_edge(5, 4);
		my_g.add_edge(4, 7);
		my_g.add_edge(5, 6);
		my_g.add_edge(6, 10);
		my_g.depth_first_search(5);
		/*my_g.breadth_firstsearch(5);*/
		cout << endl;
	/*	my_g.depth_first_search(5);*/
		cout << endl;
		cout << endl;
		/*my_g.display_adj_matix();*/
	}
	
	_CrtDumpMemoryLeaks();
}

