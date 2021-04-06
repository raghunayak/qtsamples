# Qt Timer and QThread!
This sample program shows the two possible ways to move QTimer object to another QThread

Comment/Uncomment `USE_QTIMER_MOVE_TO_THREAD` macro to check the two possible
solutions.

## Solution 1 (Preferred solution)

Here we set the parent object for the QTimer.

Whenever a parent object is moved to new thread, Qt automatically moves all the
child objects to the same thread as well.

## Solution 2

In this solution, we don't set the parent for the timer. Instead, we manually
invoke `QObject::moveToThread()` on the timer object.

> **Warning:** You cannot call `QObject::moveToThread()` on any object which has a parent.

## Solution 3

Not shown in the the example. However, you can dynamically create the timer
object once you are already on new thread.

## Additional comments

Care must be taken when you call `stop()` method on the timer, once it is moved to
a new thread. You can call `stop()` on the QTimer only from the thread it belongs to.
