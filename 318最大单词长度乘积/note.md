###关于字母的表示方法总结

#### 1、数组表示法

- 由于字母都是通过ASCII码的形式存储的，所以和数字可以相互转化
- 只需要声明一个长度为26的数组即可将字符串中的所有字母表示
- 其实本质上是哈希表表示法

```cpp
string s = "sadasdsadasdas";
int ch[26] = {0};
for (int i = 0 ; i < s.size(); i++) {
    ch[s[i] - 'a']++
}
```



####2、数字表示法

- 由于只有26个字母且一个`int`型数字有32位，所以用一个int型数字即可表示所有的字母
- 此种方法仅使用于一个字符串种仅仅出现一次字母的情况

```cpp
string s = "asdfghjk";
int mark = 0;
for (int i = 0; i < s.size(); i++) {
    mark |= 1<<(s[i] - 'a');
}
```

