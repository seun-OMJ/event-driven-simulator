#pragma once

class ListItem {
public:
	virtual int compareTo(ListItem *other) = 0;
	virtual void setInt(int v);
	virtual int getInt();

    virtual int getTime();
}; // class ListItem
