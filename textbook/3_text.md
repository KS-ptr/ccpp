## 変数
### 型
* 変数には値を記憶させることができるが、その値には種類がある。C++の基本的な型は以下の通り。
  * 論理型
    *  bool 
  * 文字型
    * char
    * unsigned char
  * 整数型
    * short int
    * unsigned short int
    * int
    * unsigned int  
    * long int
    * unsigned long int
  * 浮動小数点型
    * float
    * double
    * long double
### 入力の受け取り
* キーボードからの入力を受け取るには`cin >>`を使う。空白などの入力は読み飛ばされる。
  * 2つ以上の値を入力させたい場合は`cin >> x >> y`とする。
  * cin は標準入力を表している。「>>」は標準入力を指定した変数に送り込むという機能を持っている。cinを使うときは、cout同様に`#include<iostream>`する。

### 定数
* `const`を指定してから変数を宣言すると、その変数の値を変更することができなくなる。
* constで指定すると、あとから値を変更できなくなる（変更しようとしてもコンパイルできない）。