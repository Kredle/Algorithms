#include "pch.h"
#include "C:\Users\gamel\source\repos\Dextra algo\Dextra algo\Paliukh_Dijkstra_algorithm.h"

TEST(FunctionTest, Djikstra_algo_test) {
	Graph<> a;
	a.add_edge(0, 1, 2);
	a.add_edge(1, 2, 2);
	a.add_edge(2, 3, 2);
	a.add_edge(3, 4, 2);
	Algorithm_output output = a.Dijkstra_algo(0, 4);
	EXPECT_EQ(8, output.distance);
	EXPECT_EQ("0-->1-->2-->3-->4   ", output.dist_str);

	Graph<6> a1;
	a1.add_edge(0, 1, 2);
	a1.add_edge(0, 2, 4);
	a1.add_edge(1, 2, 1);
	a1.add_edge(1, 3, 8);
	a1.add_edge(1, 4, 10);
	a1.add_edge(2, 3, 5);
	a1.add_edge(3, 4, 2);
	a1.add_edge(3, 5, 6);
	a1.add_edge(4, 5, 3);
	Algorithm_output output1 = a1.Dijkstra_algo(0, 5);
	EXPECT_EQ(13, output1.distance);
	EXPECT_EQ("0-->1-->2-->3-->4-->5   ", output1.dist_str);

	Graph<> a2;
	a2.add_edge(0, 2, 1);
	a2.add_edge(0, 1, 2);
	a2.add_edge(1, 2, 1);
	a2.add_edge(3, 4, 8);
	Algorithm_output output2 = a2.Dijkstra_algo(0, 2);
	EXPECT_EQ(1, output2.distance);
	EXPECT_EQ("0-->2   ", output2.dist_str);
	Algorithm_output output3 = a2.Dijkstra_algo(4, 3);
	EXPECT_EQ(8, output3.distance);
	EXPECT_EQ("4-->3   ", output3.dist_str);

}