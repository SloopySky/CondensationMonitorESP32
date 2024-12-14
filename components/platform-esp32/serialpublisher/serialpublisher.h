#ifndef SERIALPUBLISHER_H_
#define SERIALPUBLISHER_H_

#include <publisher.h>

struct SerialPublisher {
    struct Publisher base;
};

void serialpublisher_init(struct SerialPublisher * const self);

#endif /* SERIALPUBLISHER_H_ */
