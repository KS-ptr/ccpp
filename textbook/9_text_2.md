## 配列 続き
### 配列とポインタ
ポインタと配列には密接な関係がある。配列の各要素のアドレスを調べてみる。`&test[0]`のようにアドレス演算子を使って配列の要素のアドレスを取得する。また、配列では特別な書き方で配列要素のアドレスを表すことができる。`test`の様に、**「配列名」を記述するだけで配列の先頭要素のアドレスを表すことができるようになっている**。（testと&test[0]の出力結果が同じになる）*配列名とは、配列の先頭要素のアドレスを格納しているポインタと同じ働きを持つ*　ということに留意する必要がある。

### ポインタ演算
配列名によって、配列の先頭要素のポインタを使えるということが分かっている。また、C++ではポインタが配列に密接な関係を持つとき、ポインタに対して次の表のような演算を行うことができる。
|        |                |                                       | 
| ------ | -------------- | ------------------------------------- | 
| 演算子 | ポインタ演算例 | 演算内容                              | 
| +      | p + 1          | pが指している要素の次の要素のアドレス | 
| -      | p - 1          | pが指している要素の前の要素のアドレス | 
|        | p1 - p2        | p1とp2の間の要素数                    | 
| ++     | p++            | pが指している次の要素のアドレス       | 
| --     | p--            | pが指している前の要素のアドレス       | 

`*(test + 1)`は配列の2番目の要素(test[1])と同じ意味になることが分かる。

また、**配列名で表されるポインタには、他のアドレスを代入することはできない。**

### 引数と配列
配列を関数の引数として使うコードを確認する。
```C++
double avg(int t[]);

int main() {
    int num = 5;
    int test[num];
    ...
    double avg = double(test);
}

double avg(int t[]) {
    double sum = 0;

    for (int i = 0; i < num; i++) {
        sum += t[i];
    }
    return sum / num;
}
```
この平均を返す関数avgでは、配列を引数として扱っている。この時仮引数には`t[]`と記述し、実引数として`test`を渡している。この様に、引数として配列を扱うときには、実引数として配列名を渡す。配列名は先頭要素のアドレスを示すので、**関数には配列の各要素の値ではなく、配列の先頭要素のアドレスだけが渡されることになる**。配列を関数に渡す場合は、先頭要素のアドレスを渡す方法を使うので、注意が必要。

#### ポインタを引数として使う
配列と同じように、同じ関数をポインタの様に記述することができる。
```C++
double avg(int* pT);

double avg(int* pT) {
    double sum = 0;
    for (int i = 0; i < num; i++) {
        sum += *(pT + i);
    }
    return sum / num;
}
```
と宣言する。この関数の仮引数はポインタpTとしている。このとき、呼び出し元から配列の先頭要素のアドレスが渡されると、ポインタpTがそのアドレスで初期化される。関数内では、ポインタpTに対してポインタ演算を行うことで、配列要素を処理できる。

#### ポインタに[]演算子を使う
配列名を先頭要素へのポインタとして扱うことができることを確認したが、これとは逆に**ポインタに[]を使って配列の様に表記する**こともできる。前のavg関数の中で、`*(pT + i)`としたが、`pT[i]`と書くことも可能。この[]を添字演算子とも言う。ポインタに[]を使った表記は、**ポインタpTが指している要素から数えてi個先の要素を表す**、ということになる。ただし、[]を正しく使えるのはポインタと配列が密接な関係を持つときだけなので注意が必要。この関数では、実引数として配列の先頭要素のアドレスが渡されるので添字演算子を使うことができる。