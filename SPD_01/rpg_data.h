#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Data {
	int len;
	std::vector<int> R;
	std::vector<int> P;
	std::vector<int> Q;
	std::vector<int> order;

	// Extracting data from file to struct
	void Add(std::string filename, std::string data_number) {
		std::string line, l1, l2, l3;

		std::ifstream File(filename);

		while (line != data_number) File >> line;

		File >> len;
		
		for (int i = 0; i < len; i++) {
			File >> l1 >> l2 >> l3;
			R.push_back(std::stoi(l1));
			P.push_back(std::stoi(l2));
			Q.push_back(std::stoi(l3));
		}

		File.close();

		order_algorithm();
	}

	// Function to show data 
	void Show() {
		for (int i = 0; i < order.size(); i++) {
			std::cout << R[order[i]] << " " << P[order[i]] << " " << Q[order[i]] << "\n";
		}
	}
	
	// Function to show order
	void Show_order() {
		std::cout << "Kolejnosc: ";
		for (int i = 0; i < len; i++) {
			std::cout << order[i] + 1 << " ";
		}
		std::cout << '\n';
	}

	// Function to calculate cmax
	int cmax() {
		int m = 0, c = 0;

		for (int i = 0; i < len; i++) {
			m = std::max(m, R[order[i]]) + P[order[i]];
			c = std::max(c, m + Q[order[i]]);
		}

		return c;
	}

	// Function to calculate order using optimal algorithm
	void order_algorithm() {
		bool special = false;
		std::vector<int> r_min;
		std::vector<int> q_min;

		int counter = 0;
		for (int i = 0; i < len; i++) {
			if (R[i] == 0 and Q[i] == 0) counter++;
		}
		if ((float)counter > (float)len / 2) special = true;

		if (special) {
			int index = -1;

			for (int i = 0; i < len; i++) {
				if (R[i] != 0 and Q[i] != 0) index = i;
			}

			int sum = 0;
			for (int i = 0; i < len; i++) {
				if (R[i] != R[index] and sum < R[index]) {
					sum += P[i];
					r_min.push_back(i);
				}
				else if (R[i] != R[index]) q_min.push_back(i);
			}

			for (int i = 0; i < r_min.size(); i++) order.push_back(r_min[i]);
			order.push_back(index);
			for (int i = 0; i < q_min.size(); i++) order.push_back(q_min[i]);
		}

		else {
			for (int i = 0; i < len; i++) {
				if (R[i] < Q[i]) r_min.push_back(i);
				else q_min.push_back(i);
			}

			for (int i = 0; i < r_min.size() - 1; i++) {
				for (int j = 0; j < r_min.size() - i - 1; j++) {
					if (R[r_min[j]] > R[r_min[j + 1]]) std::swap(r_min[j], r_min[j + 1]);
				}
			}

			for (int i = 0; i < q_min.size() - 1; i++) {
				for (int j = 0; j < q_min.size() - i - 1; j++) {
					if (Q[q_min[j]] < Q[q_min[j + 1]]) std::swap(q_min[j], q_min[j + 1]);
				}
			}

			for (int i = 0; i < len; i++) {
				if (i < r_min.size()) order.push_back(r_min[i]);
				else order.push_back(q_min[i - r_min.size()]);
			}
		}
		r_min.clear();
		q_min.clear();
	}
};

