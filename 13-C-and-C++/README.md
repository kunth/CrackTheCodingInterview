##### `This file merges all the .md files above`

### 13.2 Compare and contrast a hash table and an STL map. Hos is a hash table implemented? If the number of inputs is small, which data structure options can be used instesd of a hash table?

In a hash table, a value is stored by calling a hash function on a key. Values are not stored in sorted order. Additionally, since hash tables use the key to find the index that will store the value, an insert or lookup can be done in amortized 0(1) time (assuming few collisions in the hash table). In a hash table, one must also handle potential collisions. This is often done by chaining, which means to create a linked list of all the values whose keys map to a particular index.

An STL map inserts the key/value pairs into a binary search tree based on the keys.There is no need to handle collisions, and, since the tree is balanced, the insert and lookup time is guaranteed to be O(log N).

**hash table : array + hash funciton(key)**

**STL: red-black tree**

- hash table 要处理好冲突，使key分布比较均匀

- 无论哈希函数有多好，仍然有可能有冲突

- 不要轻易改变hash table大小

- 当数据比较少时，可以用STL map。

### 13.3 How do virtual funcitons work in C++?

虚函数取决于“vtable”或“Virtual Table”

如果一个类的函数被声明为virtual，一个vtable就会被构建，用来存储这个类的虚函数的地址。这种情况下编译器也会添加一个隐藏的vptr变量来指向这个类的vtable。

如果一个虚函数没有在派生类中被覆盖，那么派生类的vtable存储的就是父类(虚)函数的地址。vtable用来解决当虚函数被调用时该函数的实际地址。C++中的动态绑定就是通过vtable机制实现的。

因为，当我们把派生类对象赋给基类指针时，(基类)vptr变量指向的派生类的vtable。
### 13.4 What is the difference between deep copy and shallow copy? Explain how you would use each.

浅拷贝把一个对象的所有成员变量拷贝给另一个对象。深拷贝不仅拷贝了成员变量，还深拷贝了指针(成员变量)所指向的对象

``` c++
struct Test {
  char *ptr;
};

void shallow_copy(Test & src, Test & dest){
  dest.ptr = src.ptr;
}

void deep_copy(Test & src, Test & dest){
  dest.ptr = (char*)malloc(strlen(src.ptr)+1);
  strcpy(dest.ptr, src.ptr);
}
```

浅拷贝会引起许多运行时错误，特别是当创建和销毁对象时。实际中，浅拷贝用的很少。

### 13.5 What is the significance of the keyword "volatile" in C?

volatile告知编译器，变量在代码不改变的情况下也可以由外部而改变。这可能是由操作系统、硬件、或者另外一个线程。因为volatile变量可能会意外改变，所以每次编译器都从内存中重取其值。
### 13.6 Why does a destructor in base class need to be declared virtual?

``` c++
class A{
public:
  virtual void foo(){
      printf("A foo\n");
  }
  ~A(){
      printf("A destructor\n");
  }
};

class B: public A{
  void foo(){
      printf("B foo\n");
  }
  ~B(){
      printf("B destructor\n");
  }
};

int main()
{
    A*a = new B();
    a->foo();
    delete a;
    return 1;
}
```
运行结果：

``` C++
B foo
A destructor
```
而如果在析构函数前加上virtual

``` c++
class A{
public:
  virtual void foo(){
      printf("A foo\n");
  }
  virtual ~A(){
      printf("A destructor\n");
  }
};

class B: public A{
  void foo(){
      printf("B foo\n");
  }
  ~B(){
      printf("B destructor\n");
  }
};

int main()
{
    A*a = new B();
    a->foo();
    delete a;
    return 1;
}
```
运行结果：

``` C++
B foo
B destructor
A destructor
```

如果A的析构函数不是virtual， 那么仅有A的析构函数被调用，即便p实际上是类型B. 将基类的析构函数声明为virtual，是用于确保派生类的析构函数能被调用。
