## 関数
### オーバーロード
引数の型や数が異なっていれば、同じ名前を持つ関数を複数定義できる。例えば、最大値を求める関数をint型とdouble型で用意ができる。このように同じ名前の関数を異なる引数の型・数を使って複数定義することを関数のオーバーロードという。

**関数をオーバーロードする際は、引数の型や数が異なっている必要がある。**

### 関数テンプレート
**C++では関数のひな型を用意できる**、という便利な機能がある。このひな形を、関数テンプレートという。関数テンプレートを利用するには、
1. 関数テンプレートを宣言・定義する
2. 関数を呼び出す(関数が自動的に生成される)

という手順が必要。

#### 関数テンプレートを定義する
  
関数テンプレートは、通常の関数宣言または定義に**template<...>**という指定を付けたもの。<...>部分には、テンプレート引数というものを指定する。

テンプレート引数は、T等という仮の型名を指定したもの。関数テンプレートでは、仮引数の型名にテンプレート引数を使う。具体的な型名の代わりに、Tなどという仮の型名を使う。
```C++
template <class T>
T maxt(T x, T y) {
    if (x > y)
        return x;
    else
        return y;
}
```

#### 関数テンプレートを利用する
関数テンプレートを利用するときは、通常の関数の呼び出しと同じように関数を呼び出す。関数テンプレートの呼び出しを記述すると、コードをコンパイルするときに、**テンプレート引数Tを、指定した方に置き換えた関数が作成される**。

関数テンプレートは、**扱う型が異なるが、そのほかでは全く同じ処理を行う関数についてコードを1つにまとめることができる**という便利な機能を持っている。