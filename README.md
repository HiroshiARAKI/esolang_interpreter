# Let's make your Esolang!
Do you know Esoteric programming language (esolang)?
It is a very difficult language to understand that meaning.
For example, there are Brainf*ck, Malbolge and Piet.  
  
These codes I offer help you make an esolang based on Brainf*ck easily!

# First: use pure Brainf*ck
```console
$ cd PROJECT_RROOT
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./bfi ../hello.bf
Hello, world!
```

You can use this project file as a Brainf*ck interpreter like this if you don't modify.

# Second: modify coded
At lines 18 - 25 in [main.cpp](main.cpp), you can find the orders of Brainf*ck.

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
#define PTR_INCREMENT   '>'
#define PTR_DECREMENT   '<'
#define BYTE_INCREMENT  '+'
#define BYTE_DECREMENT  '-'
#define OUTPUT          '.'
#define INPUT           ','
#define LOOP_START      '['
#define LOOP_END        ']'
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