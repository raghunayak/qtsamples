# Various ways to automatically destroy QObject based class
This sample program shows the multiple ways to destroy a class derived from
QObject.

## Solution 1

Set the parent object for the given QObject.

This way, Whenever the parent object is destroyed, Qt automatically deletes
all the child object as well.

## Solution 2

You can connect `QObject::destroyed()` signal of an object to ``QObject::deleteLater()`
slot of your object.

> **Warning:** This works only when the Qt event loop is running.

## Solution 3

Use automatic variables. This way there is no need to do any memory management.
I would still set the parent parent for objects declared this way. This is so
that child thread is automatically updated whenever parent is moved to another
thread. Check Sample_2.

## Solution 4

You can use smart pointers such as `std::unique_ptr` to management the life time
of your class object. This is least preferred way because it can interfere with
Qt memory management (eg: if you set the parent to such object by mistake).

> **Warning:** Care must be taken to not to set parent pointer in this case.
> Otherwise application may crash.

