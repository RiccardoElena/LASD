#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Clear(unsigned int &, unsigned int &, const lasd::ClearableContainer &,
           bool);

void Resize(unsigned int &, unsigned int &, const lasd::ResizableContainer &,
            bool, unsigned long);

#endif // __CONTAINER_H__