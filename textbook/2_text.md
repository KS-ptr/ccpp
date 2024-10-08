## コードの内容

### main関数
* `int main()`等で宣言される**main関数**を原則としてC++では最初に実行する
  
* `return 0`等、関数を**return**すると関数内の処理を終了する

### ファイルを読み込んでおく
* `#includ<iostream>`等「*」から始まる行は、コンパイルする前に読み込んでおくプログラムを指定する行　ファイルの読み込み作業を**インクルード**という 
  * cin, coutを使うときは必ず`<iostream>`をインクルードすること

* iostreamのように、前もって読み込まれるファイルを**ヘッダファイル**という
  * #がついた行はコンパイラに含まれる**プリプロセッサ**によってコードより先に読み込まれる。「;」はつけない。

## 文字と数値
### リテラルとは
* 特定の文字や数値の表記をC++では**リテラル**という　リテラルとは**一定の値を表すために用いられるC++の単語のようなもの**
  
* リテラルの種類には以下のようなものがある
1. 文字リテラル
2. 文字列リテラル
3. 数値リテラル
4. 論理リテラル
  
### 文字リテラル
* C++では以下の2種類のリテラルを区別して扱っている。
  * 1つの文字
  * 文字列

* **文字リテラル**は、`'H', 'e'`など''(シングルクォーテーション)でくくってコード中に記述する。
  * キーから入力できない特殊な文字は「\」をつけた2つの文字の組み合わせで1文字として表すが、これを**エスケープシーケンス**という。
    * `\\` ￥マーク
    * `\'` シングルクォーテーション
    * `\"` ダブルクォーテーション

* **文字列リテラル**は、複数の文字の並びを""（ダブルクォーテーション）で囲って記述する。

* **数値リテラル**には
  * 整数リテラル
  * 浮動小数点リテラル
  
  があり、'や"ではくくらない。8進数（先頭に0をつける）や16真数（先頭に0xをつける）での表記も可能。