#pragma once

struct Job
{
	int id;
	int priority;
	int duration = 0;

	bool operator==(const Job& rhs) const;

	bool operator!=(const Job& rhs) const;

	bool operator<(const Job& rhs) const;

	bool operator>(const Job& rhs) const;

	bool operator<=(const Job& rhs) const;

	bool operator>=(const Job& rhs) const;
};

