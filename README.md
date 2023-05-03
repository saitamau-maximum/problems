# Maximum Problems

<https://judge.maximum.vc/> 上の問題を管理するためのリポジトリ

## ディレクトリ構成

```
│
├── README.md (このファイル)
├── .gitignore
├── LICENSE
│
├── .clang-format (フォーマット用)
│
├── package.json (npm の設定)
├── yarn.lock (yarn の依存関係のバージョン固定)
│
├── requirements.txt (Python の依存関係)
├── requirements.lock (Python の依存関係のバージョン固定)
│
├── PROJECT (プロジェクトの設定)
│
├── common
│   ├── testlib.h (https://github.com/MikeMirzayanov/testlib を参照)
│   │
│   ├── common_loader.js (問題文 HTML の共通部分呼び出し用)
│   ├── common.html (問題文 HTML の共通部分)
│   └── style.css (問題文 HTML の共通スタイル)
│
├── templates
│   └── problem.html (問題文 HTML)
│
└── (各問題のディレクトリ)

```

## Quickstart

[Rime+のススメ](https://qiita.com/hiroshi-cl/items/fbd0d0963d8207d33bc6) を読みましょう

### インストール

入力生成器として [Rime](https://github.com/icpc-jag/rime) を用いるため、インストールする。venv などを使うと良い。

```bash
pip install rime
```

requirements.txt に書いてあるので、以下のコマンドでもインストールできる

```bash
pip install -r requirements.txt
```

なお、Windows 上で動かす場合不安定らしいので注意

### 問題作り

ルートディレクトリで実行

```bash
rime add problems problem <problem-name>
```

`PROBLEM` ファイルの内容 (一部)

```py
pid='<problem-name>' # 問題のID、ディレクトリ名と同一 (上記コマンドの <problem-name>)
problem(
  time_limit=1.0, # 実行時間制限 (秒)
  id=pid,
  title="問題名", # 問題名 (英語がいい)
)
```

また、 `/templates/problem.html` をコピーして、問題文を書く。
ローカルサーバーが立ち上がるので、`http://localhost:5000/<problem-name>/problem.html` にアクセスする。
Ctrl + C でサーバーを終了できる。
問題文が完成したら Ctrl + P で A4 サイズの PDF に変換し、 problem.pdf として保存する。

```bash
yarn start
```

### 想定解や嘘解法など追加

`/problems` 内で実行

```bash
rime add <problem-name> solution <sol-name>
```

`<sol-name>` は、次の形式にしてください

```bnf
<sol-name> ::= sol-<lang>-<expected-judge>
<lang> ::= 'cpp' | 'py' | 'java' | 'c' | (その他言語の拡張子)
<expected-judge> ::= <verdict> | <verdict>-<reason>
<verdict> ::= 'ac' | 'wa' | 'tle'
<reason> ::= (WA / TLE になる理由を簡潔に)
```

`SOLUTION` ファイルの内容

- cpp 使うなら `cxx_solution` をコメントアウトし、`main.cc` ファイルを作成する
- もし AC 以外の想定なら引数として `challenge_cases=[]` を追加する
- スコアは `expected_score` で設定。まあ一律で 1 でいいと思う

### テストケース追加

`/problems` 内で実行

```bash
rime add <parent_problem_dir_name> testset tests
```

サンプルは `00_sampleX.in` という名前で `tests` ディレクトリに入れる。
なお、 `X` は 0, 1, 2, ... というように連番にすること。(0-indexed)

ランダムケース (`generator.cc` で作ったもの) は `10_randomX.in` という名前にする。
`generator.cc` には違う Seed 値をコマンドライン引数として与えて、異なるケースを生成するようにする。

コーナーケースは `20_cornerX_<何のコーナーか>.in` という名前にする。
どっちも最大 10 個まであれば十分だと思う。

`TESTSET` ファイルの内容

- Input generators: 入力を生成するプログラム
- Input validators: 入力がフォーマット・制約を満たしているかをチェックするプログラム
- Output judges: 出力が正しいかをチェックするプログラム
- Reactives: いわゆるインタラクティブ問題のためのプログラム
- Extra Testsets: その他の設定

### ビルドとテスト

`/problems` 内で実行

```bash
rime build <problem-name>
```

```bash
rime test <problem-name>
```

### zip ファイル生成

`/problems` 内で実行

```bash
rime pack <problem-name>
```

`/problems/<problem-name>/rime-out/domjudge/<problem-name>.zip` が生成されるはず

これを DOMJudge の「Import Problems」の「Import Archive」からアップロードする。

ミスったら問題詳細の一番下「Problem Archive」からアップする。このとき「Delete old data」にチェックしたほうがいいと思う。

ジャッジはアップされないので注意。
ただ比較するだけのジャッジなら問題ないが、インタラクティブなど特殊な場合は、ジャッジをアップする必要がある。
Admin の「Executables」から「Add new executable」で「Type: Compare」で、`build`, `compare.cc` の 2 ファイルからなる zip を入れる。
デフォルトの各ファイルは `/templates/compare` にある。
`testlib.h` を入れたいなら [cn-xcpc-tools/testlib-for-domjudge](https://github.com/cn-xcpc-tools/testlib-for-domjudge/blob/master/testlib.h) を使うといいかも。
`/templates/compare/testlib.h` に置いとくので、もし必要だったらこっちの `testlib.h` を zip に含める。 (`/common/testlib.h` は含めないようにする)

問題文もアップされないので注意。
問題詳細ページから PDF をアップする。

## testlib.h の使い方

Codeforces の開発者 Mike Mirzayanov さんが作った、テストケースとかにかかわるライブラリ。
<https://github.com/MikeMirzayanov/testlib>

なんか「使い方が最も簡単にわかる方法は、ソースコードを見ろ」らしいので、見てください。
(`/checkers`, `/validators`, `/generators`, `/interactors` のファイルたちは使い方の例っぽい)
