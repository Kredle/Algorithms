#include "pch.h"
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
#define INF DBL_MAX
#define MAX_V 1000

struct Algorithm_output {
	double distance;
	string dist_str;

	Algorithm_output() : distance(0.), dist_str("") {}
	Algorithm_output(double dist, string d_s) : distance(dist), dist_str(d_s) {}
};

struct Edge {
	size_t from;
	size_t to;
	double weight;

	Edge() : from(-1), to(-1), weight(INF){}
	Edge(size_t fr, size_t t, double w){
		if (fr < 0 || t < 0) {
			cout << "ERROR: Wrong vertix\n";
			from = -1;
			to = -1;
		}
		else if (fr == t && fr!=-1 && t!= -1) {
			cout << "ERROR: Loop edge\n";
			fr = -1;
			t = -1;
		}
		else {
			if (w < 0) {
				cout << "ERROR: Negative weight\n";
				weight = INF;
			}
			else {
				from = fr;
				to = t;
				weight = w;
			}
		}
	}
};


template <size_t S = 5>
class Graph {
private:
	Edge* pair_mas;
	bool* marked;
	size_t size = S;
public:
	Graph() {
		pair_mas = new Edge[size];
		marked = new bool[size];
		for (int i = 0; i < size; ++i) {
			marked[i] = false;
			pair_mas[i] = Edge();
		}
	}

	void add_edge(size_t fr, size_t t, double w) {
		if (fr < 0 || t < 0) { cout << "ERROR: Wrong vertex\n"; return; }
		else if (fr == t) { cout << "ERROR: Loop edge\n"; return; }
		else {
			if (w < 0) { cout << "Negative weight\n"; return; }
			else {
				for (int i = 0; i < size; ++i) {
					if((pair_mas[i].from == fr && pair_mas[i].to == t) || (pair_mas[i].from == t && pair_mas[i].to == fr)) 
					{
						//cout << "This edge alredy exists\n";
						return;
					}
				}
				Edge* pair_helper = new Edge[size + 1];
				for (size_t i = 0; i < size; ++i) {
					pair_helper[i] = pair_mas[i];
				}
				pair_helper[size] = Edge(fr, t, w);
				delete[] pair_mas;
				pair_mas = pair_helper;
				++size;
			}
		}
	}

	void remove_edge(size_t fr, size_t t) {
		if (fr < 0 || t < 0) {cout << "ERROR: Wrong vertex\n";	return;}
		for (size_t i = 0; i < size; ++i) {
			if (pair_mas[i].from == fr && pair_mas[i].to == t) {
				for (size_t j = i; j < size - 1; ++j) {
					pair_mas[j] = pair_mas[j + 1];
				}
				pair_mas[size - 1] = Edge(-1, -1, INF); 
				return;
			}
		}
	}

	bool empty() { return S == 0; }

	friend ostream& operator<<(ostream& os, Graph& a) {
		if (a.empty()) { os << "Graph is empty\n"; return os; }
		os << "Edge_List: \n";
		bool is_any_printed = false;
		for (int i = 0; i < a.size; ++i) {
			if (a.pair_mas[i].from == -1 || a.pair_mas[i].to == -1 || a.pair_mas[i].from>MAX_V || a.pair_mas[i].to>MAX_V) continue;
			cout << '(' << a.pair_mas[i].from << "<->" << a.pair_mas[i].to << ")\n";
			is_any_printed = true;
		}
		if (!is_any_printed) cout << "(empty)\n";
		return os;
	}

	Algorithm_output Dijkstra_algo(size_t start, size_t end) {
		Algorithm_output output;
		if (start == end) { cout << "The same parametrs. \n"; return Algorithm_output(); }
		if (start < 0 || end < 0) { cout << "Negative parametrs\n"; return Algorithm_output(); }
		size_t* prev = new size_t[size];
		for (size_t i = 0; i < size; ++i) {
			prev[i] = -1;
		}
		double* dist = new double[size];
		for (size_t i = 0; i < size; ++i) {
			dist[i] = INF;
		}
		dist[start] = 0;
		size_t u = start;
		marked[u] = true;
		while (true) {
			for (size_t i = 0; i < size; ++i) {
				if (pair_mas[i].from == u) {
					size_t v = pair_mas[i].to;
					if (!marked[v]) {
						double weight = pair_mas[i].weight;
						if (dist[u] + weight < dist[v]) {
							dist[v] = dist[u] + weight;
							prev[v] = u;
						}
					}
				}
			}
			for (size_t i = 0; i < size; ++i) {
				if (pair_mas[i].to == u) {
					size_t v = pair_mas[i].from;
					if (!marked[v]) {
						double weight = pair_mas[i].weight;
						if (dist[u] + weight < dist[v]) {
							dist[v] = dist[u] + weight;
							prev[v] = u;
						}
					}
				}
			}
			u = -1;
			double min_dist = INF;
			for (size_t i = 0; i < size; ++i) {
				if (!marked[i] && dist[i] < min_dist) {
					min_dist = dist[i];
					u = i;
				}
			}
			if (u == -1) break;
			marked[u] = true;
		}
		if (prev[end] == INF) {
			cout << "No path from " << start << " to " << end << "\n";
			return Algorithm_output();
		}
		string path_str = "";
		size_t curr = end;
		while (curr != -1) {
			path_str = to_string(curr) + "-->" + path_str;
			curr = prev[curr];
		}
		path_str[path_str.length() - 1] = ' ';
		path_str[path_str.length() - 2] = ' ';
		path_str[path_str.length() - 3] = ' ';
		double distance = dist[end];
		output.distance = distance;
		output.dist_str = path_str;
		return output;
	}
};
