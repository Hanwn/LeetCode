# 关于string，int，char的互相转化

> char ''  string ""


1. char - > int 

```cpp
char a = '1';
int b = a - '0';
```

2. char - > string

```cpp
char c = 'x';
string s = ""

s += c;
cout<<s;
```


3. int - > char

```cpp
int a = 1;
char c = a + 48;
```

4. int - > string

```cpp
int a = 123;
string b = to_string(a);
```

5. string - > int
```cpp

```

6. string - > const char*

```cpp
const char* p = s.c_str();
```


