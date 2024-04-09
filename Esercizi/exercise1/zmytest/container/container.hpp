#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(unsigned int &, unsigned int &, const lasd::Container &, bool);

void Size(unsigned int &, unsigned int &, const lasd::Container &, bool);

void Clear(unsigned int &, unsigned int &, const lasd::Container &, bool);

void Resize(unsigned int &, unsigned int &, const lasd::Container &, bool);

#endif // __CONTAINER_H__