# Get Next Line

## Goals
This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.
> このプロジェクトでは、非常に便利な関数をコレクションに加えることができるだけでなく、C言語のプログラミングにおいて非常に興味深い新しい概念である「静的変数」を学ぶことができます。

## Common Instructions
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
> あなたのプロジェクトは規範に沿って書かれていなければなりません。ボーナスファイル/関数がある場合は、それらも規範チェックに含まれ、内部に規範エラーがある場合は0が返されます。

- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
> 関数は、未定義の動作とは別に、予期せぬ終了（セグメンテーション・フォールト、バス・エラー、ダブル・フリーなど）をしてはいけません。このような事態が発生した場合、プロジェクトは非機能的であるとみなされ、評価の際に0点が与えられます。

- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
> ヒープに割り当てられたすべてのメモリ空間は、必要に応じて適切に解放されなければなりません。リークは許されません。

- If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink.
> 課題で要求された場合、-Wall、-Wextra、-Werror のフラグでソースファイルを要求された出力にコンパイルする Makefile を提出しなければなりません。また、Makefile は再リンクしてはいけません。

- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
> また、Makefile には少なくとも $(NAME), all, clean, fclean, re というルールが含まれていなければなりません。

- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file_bonus.{c/h}. Mandatory and bonus part evaluation is done separately.
> プロジェクトにボーナスを入れるには、Makefileにルールbonusを含めなければなりません。bonusは、プロジェクトのメイン部分で禁止されているすべての様々なヘッダー、ライブラリ、関数を追加します。ボーナスは別のfile_bonus.{c/h} に記述する必要があります。必須部分とボーナス部分の評価は別々に行われます。

- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
> あなたのプロジェクトであなたのlibftの使用が許可されている場合、そのソースと関連するMakefileを、関連するMakefileのあるlibftフォルダにコピーする必要があります。お客様のプロジェクトのMakefileは，そのMakefileを使ってライブラリをコンパイルした後，プロジェクトをコンパイルする必要があります。

- We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
> プロジェクトのテストプログラムは、提出や評価の必要はありませんが、作成することをお勧めします。自分の作品や仲間の作品を簡単にテストする機会を得ることができます。これらのテストは、特にディフェンス時に役立つでしょう。実際、弁論大会では、あなたのテストやあなたが評価している相手のテストを自由に使用することができます。

- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.
> あなたの作品を、指定されたgitリポジトリに提出してください。git repositoryにある作品のみが採点されます。Deepthoughtがあなたの作品の採点を担当する場合は、あなたの相互評価の後に行われます。Deepthoughtによる採点中に作品のいずれかのセクションでエラーが発生した場合、評価は中止されます。


## Mandatory part - Get_next_line
|Function         | get_next_line                 |
|:-----------------|:-------------------------------|
|**Prototype**        | **char * get_next_line(int fd);** |
|**Turn in files**    | **get_next_line.c, get_next_line_utils.c,<br>get_next_line.h** |
|**Parameters**       | **File descriptor to read from**  |
|**Return value**     | **Read line: correct behavior<br>NULL: nothing else to read or an error occurred** |
|**External functs**  | **read, malloc, free**            |
|**Description**      | **Write a function which returns a line read from a file descriptor** |


- Calling your function get_next_line in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it.
> 関数 get_next_line をループで呼び出すと、ファイル記述子にあるテキストを1行ずつ、最後まで読むことができます。

- Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL.
> 関数は、読み込んだばかりの行を返します。他に読むべきものがない場合や、エラーが発生した場合は、NULLを返します。

- Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
> ファイルから読み込んだときと、標準入力から読み込んだときに、関数がうまく動作するようにしてください。

- libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.
> このプロジェクトでは libft は使用できません。get_next_lineが動作するために必要な関数を含むget_next_line_utils.cファイルを追加する必要があります。

- Your program must compile with the flag -D BUFFER_SIZE=xx which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by the moulinette.
> プログラムは、-D BUFFER_SIZE=xx というフラグを付けてコンパイルする必要があります。これは、get_next_line の read 呼び出しのバッファサイズとして使用されます。この値は、あなたの評価者やmoulinetteによって変更されます。

- The program will be compiled in this way: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
> プログラムはこのようにしてコンパイルされます。: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.

- Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes.
> ファイルまたは標準入力から読み取るためには、コンパイル時に定義されたBUFFER_SIZEを使用する必要があります。この値は、テスト目的で評価中に変更されます。

- In the header file get_next_line.h you must have at least the prototype of the function get_next_line.
> ヘッダーファイルget_next_line.hには、少なくとも関数get_next_lineのプロトタイプがなければなりません。

----
		Does your function still work if the BUFFER_SIZE value is 9999? And 
		if the BUFFER_SIZE value is 1?  And 10000000?  Do you know why?
		BUFFER_SIZEの値が9999であっても、この関数は動作しますか？ 
		またBUFFER_SIZEの値が1の場合は？ そして、10000000。 なぜだかわかりますか？
----
		You should try to read as little as possible each time get_next_line is called.
		If you encounter a newline, you have to return the current line.
		Don’t read the whole file and then process each line.
		get_next_lineが呼ばれるたびに、できる限り読み込まないようにする必要があります。
		もし、改行があった場合は、現在の行を戻さなければなりません。
		ファイル全体を読んでから各行を処理するのはやめましょう。
----
		Don’t turn in your project without testing.  There are many tests to run, cover your bases.
		Try to read from a file, from a redirection, from standard input.
		How does your program behave when you send a newline to the standard output?  And CTRL-D?
		テストをしないでプロジェクトを提出してはいけません。 たくさんのテストを実施して ベースをカバーしましょう。
		ファイルからの読み込み、リダイレクトからの読み込み、標準入力からの読み込みを試してみてください。
		標準入力から読み込んでみてください。 標準出力に改行を送ると、プログラムはどのように動作しますか？
		標準出力に改行を送ったときのプログラムの動作は？ また、CTRL-Dは？
----

- lseek is not an allowed function. File reading must be done only once.
> lseekは許可された関数ではありません。ファイルの読み込みは一度だけ行わなければならない。

- We consider that get_next_line has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd.
> 2回の呼び出しの間に、同じファイル記述子が最初のfdからすべてを読み込む前に別のファイルに切り替わる場合、get_next_lineは未定義の動作をすると考える。

- Finally we consider that get_next_line has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.
> 最後に、get_next_lineがバイナリファイルから読み込んだときの動作は未定義であると考える。しかし、望むならば、この動作を首尾一貫したものにすることができます。

- Global variables are forbidden.
> グローバル変数の使用は禁止されています。

- Important: You should always return the line that has been read followed by a ’\n’. unless you have reach end of file and the is no ’\n’.
> 重要：読み取られた行の後に「\n」が続く行を常に返す必要があります。 ファイルの終わりに到達していて、それが「\n」でない場合を除きます。

## Bonus part
The project get_next_line is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses will be taken into consideration if the mandatory part isn’t perfect.
Turn-in all 3 mandatory files ending by file_bonus.[c\h] for this part.
> get_next_lineというプロジェクトは単純で、ボーナスの余地はほとんどありませんが、あなたには想像力があることでしょう。必須パートをクリアした方は、ぜひこのボーナスパートをクリアして先に進んでください。ただし、必須パートが完璧でない場合、ボーナスは考慮されませんのでご注意ください。
このパートでは、file_bonus.[c\h]で終わる3つの必須ファイルをすべて提出してください。

- To succeed get_next_line with a single static variable.
> get_next_lineを1つの静的変数で成功させること。

- To be able to manage multiple file descriptors with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.
> get_next_lineで複数のファイル記述子を管理できるようにすること。例えば、ファイルディスクリプター3、4、5が読み取り可能な場合、それぞれのディスクリプターの読み取りスレッドを失うことなく、3に1回、4に1回、3に1回、5に1回などの頻度でget_next_lineを呼び出すことができます。
