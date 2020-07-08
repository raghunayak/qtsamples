# Qt Metatype!
This sample program shows usage of Qt meta type

There are two classes declared in this sample.
The `BaseClass` is not derived from `QObject`, whereas the `DerivedClass` is derived from `QObject`, and the `BaseClass`.

As you can see, registration of meta-type is not necessary for classes derived from QObject.
When you try to use Qt::QueuedConnection type without first registering the meta type with Qt, Qt would throw a runtime error.
You can observe this error by commenting `Q_DECLARE_METATYPE` inside `myclass.h` file.
