#ifndef Header
#define Header
template <class T>
class MyList
{
   public:
      MyList(){}
      virtual ~MyList() {}
      virtual int size() = 0;
      virtual void push( T data) = 0;
      virtual void pushBack (T data) = 0;
      virtual T erase() = 0;
      virtual void setToBegin () = 0;
      virtual void setToEnd () = 0;
      virtual void prev() = 0;
      virtual void next() = 0;
      virtual int currPos () = 0;
      virtual void setToPos (int pos) = 0;
      virtual T getValue () = 0;
      virtual int find (T data) = 0;
      virtual void clear() = 0;

};
#endif // Header
