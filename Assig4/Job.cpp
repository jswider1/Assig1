#include "Job.h"

bool Job::operator==(const Job& rhs) const
{
	return priority == rhs.priority && duration == rhs.duration;
}

bool Job::operator!=(const Job& rhs) const
{
	return !(*this == rhs);
}

bool Job::operator<(const Job& rhs) const
{
	return priority > rhs.priority || (priority == rhs.priority && duration > rhs.duration);
}

bool Job::operator>(const Job& rhs) const
{
	return !(*this == rhs) && !(*this < rhs);
}

bool Job::operator<=(const Job& rhs) const
{
	return (*this == rhs) || (*this < rhs);
}

bool Job::operator>=(const Job& rhs) const
{
	return (*this == rhs) || (*this > rhs);
}

