# Let's make your Esolang!
![update](https://img.shields.io/badge/update-2020.01.22-9cf.svg?style=flat) 
![cpp](https://img.shields.io/badge/C++-11-blue.svg?style=flat)  
Do you know Esoteric programming language (esolang)?
It is a very difficult language to understand that meaning.
For example, there are Brainf*ck, Malbolge and Piet.  
  
These codes I offer help you make an esolang based on Brainf*ck easily!

# NEW! You can make BF-based Encryption  
```console
$ cd PROJECT_ROOT
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./enc [original message] [output filename]
Original : 1234
Size     : 4
Done!

$ ./bf [output filename]
[original message]
```

For example, if you encode [original.txt](original.txt) (written "How are you?"), you will get the bf-based-code (with NOISE) like this.
  
```text
>��+�+*+�+�+�+�+C[->M�U+��+�G++�T+/+
+X�+k�+�+�<�]>+H+3.>bA+�+
+#+�+_+0+�+�+�+a+[->K5+9�+��+�+��+Zg+*�+�H+��+�+�<]>+�.>�+M+9+�+�+�+�++�+�+�+�[->���+�
+�l+�Q+� +�+�+�m+a�+4�+<]>+�+6+P+�+�+�+�+�+:.>+�+
+D[->Uz�+�P+ɲ+޲+��+�L+O�+��+g�+�+�<a]>+ +�.>x�+�++4+b++�+^+G+�[->X)�+
�+�b+F�+��+
6+*+s+d�+�+�<S]>+	+�++S+O+Q+�.>e�+�+�+�+�+�++�+�+�+�+[->�O�+|�+7�+��+��+3�+:�+�+!�+��+�<�]>+�+/++�.>��+m+H+�++H++
+O+�+q[->q�_+��+Ӟ+��+�+��+�+��+��+s~+<']>+�.>�9+W++d[->A�5+�+�
+��+��++d�+�h+��+Y2+<]>+	+9.>++�+�+q+h++�+6+
+�+�+�[->��j+��+%�+�+��+�&+C+ݯ+�:+��+<
]>+m.>�+8+�++�+`+�+{+�+r+�+�[->�`+ދ+�Y+�+2+b�+�A+�s+v�+��+�<�]>+�.>��+y++�+�+�++^+�+p+L+�[->�q+�+ k+�+�+��+�
+|G+�+�N+	<#]>+f+�++�+�+�+�.>��+�+2++
++8[->T+�+�+��+tW+��+��+�j+A�+X1+<]>+�+�+H.

```

# First: use pure Brainf*ck
```console
$ cd PROJECT_ROOT
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./bfi ../hello.bf
Hello, world!
```

You can use this project file as a Brainf*ck interpreter like this if you don't modify.

# Second: modify coded
In [orders.cpp](orders.h), you can find the orders of Brainf*ck.

```cpp
#define PTR_INCREMENT   '>'
#define PTR_DECREMENT   '<'
#define BYTE_INCREMENT  '+'
#define BYTE_DECREMENT  '-'
#define OUTPUT          '.'
#define INPUT           ','
#define LOOP_START      '['
#define LOOP_END        ']'
```

You can change these orders to yours, and YOUR esolang is done !.

## For Example ...
If you change the orders like
```cpp
#define PTR_INCREMENT   'a'
#define PTR_DECREMENT   'b'
#define BYTE_INCREMENT  'c'
#define BYTE_DECREMENT  'd'
#define OUTPUT          'e'
#define INPUT           'f'
#define LOOP_START      'g'
#define LOOP_END        'h'
```

Then, the "Hello, world" code is

```text
cccccccccgdaccccccccacccccccccccacccccbbbhaeacceccccccceeccceadeddddddddd
dddebcccccccceddddddddeccceddddddeddddddddeace
```

# References
[https://gist.github.com/7shi/527649](https://gist.github.com/7shi/527649)  
[南関東開発機構 : 多重ループに対応したBrainfuckインタプリタ](http://blog.livedoor.jp/south_kanto_dm/archives/51691594.html)  
  
上記ページは，勝手ながらかなり参考にさせていただきました．この場をお借りして感謝申し上げます．