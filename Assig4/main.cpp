
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Job.h"
#include "PriorityQueue.h"

std::vector<Job> readInput(const std::string& filename)
{
	std::vector<Job> jobs;
	Job job;
	int number = -1;
	char c;
	int i = 0;

	std::ifstream ifs;
	ifs.open(filename.c_str());

	while (ifs.get(c))          //loop getting single characters
	{
		if (c >= '0' && c <= '9')
		{
			if (number == -1)
			{
				number = 0;
			}

			number *= 10;
			number += c - '0';
		}
		else if (number != -1)
		{
			int field = i % 3;

			if (field == 0)
			{
				job.id = number;
			}
			else if (field == 1)
			{
				job.priority = number;
			}
			if (field == 2)
			{
				job.duration = number;
				jobs.push_back(job);
			}

			number = -1;
			i++;
		}
	}

	if (number != -1)
	{
		int field = i % 3;

		if (field == 0)
		{
			job.id = number;
		}
		else if (field == 1)
		{
			job.priority = number;
		}
		if (field == 2)
		{
			job.duration = number;
			jobs.push_back(job);
		}
	}

	ifs.close();

	return jobs;
}

int main(int argc, char* argv[])
{
	std::vector<Job> jobs;

	if (argc == 2)
	{
		jobs = readInput(argv[1]);
	}
	else
	{
		jobs = readInput("data.txt");
	}

	PriorityQueue pq;
	pq.buildHeap(jobs.data(), jobs.size());

	Job processors[4];
	std::cout << "Processor: 1 2 3 4\n";
	std::cout << processors[1].id << ":" << processors[1].duration << " \n";
	while (pq.getSize() != 0 || processors[0].duration != 0 || processors[1].duration != 0 || processors[2].duration != 0 || processors[3].duration != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (processors[i].duration == 0)
			{
				if (pq.getSize() != 0)
				{
					processors[i] = pq.extractMax();
				}
			}
			else
			{
				processors[i].duration--;
				if (processors[i].duration == 0)
				{
					if (pq.getSize() != 0)
					{
						processors[i] = pq.extractMax();
					}
				}
			}
			if (processors[i].duration != 0)
			{
				std::cout << processors[i].id << ":" << processors[i].duration << " ";
			}
		}
	}

	return 0;
}
