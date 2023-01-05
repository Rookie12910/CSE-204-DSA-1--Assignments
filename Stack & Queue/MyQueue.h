#ifndef HeaderQ
#define HeaderQ
template <class T>
class MyQueue
{
   public:
      MyQueue(){}
      virtual ~MyQueue() {}
      virtual void clear() = 0;
      virtual void enqueue(T data) = 0;
      virtual T dequeue() = 0;
      virtual int length() = 0;
      virtual T frontValue() = 0;
      virtual T rearValue() = 0;
      virtual T leaveQueue() = 0;


};
#endif // HeaderQ

