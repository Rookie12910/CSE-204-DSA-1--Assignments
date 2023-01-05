#ifndef HeaderS
#define HeaderS
template <class T>
class MyStack
{
   public:
      MyStack(){}
      virtual ~MyStack() {}
      virtual void clear() = 0;
      virtual void push(T data) = 0;
      virtual T pop() = 0;
      virtual int length() = 0;
      virtual T topValue() = 0;

};
#endif // Header
