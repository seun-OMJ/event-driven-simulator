
#include "burstHolder.h"
burstHolder::burstHolder(int item):value(item){}
int burstHolder::getInt() {
    return value;
}
void burstHolder::setInt(int item) {
    value = item;
}
int burstHolder::compareTo(ListItem *other) {return -1;}
