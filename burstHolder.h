#include "ListItem.h"

class burstHolder: public ListItem {
private:
    int value;

public:
    burstHolder(int item);
    int getInt();
    void setInt(int item);
    int compareTo(ListItem *other);
};

