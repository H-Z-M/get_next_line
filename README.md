# get_next_line

|Function         | get_next_line                 |
|:-----------------|:-------------------------------|
|**Prototype**        | **char * get_next_line(int fd);** |
|**Turn in files**    | **get_next_line.c, get_next_line_utils.c,<br>get_next_line.h** |
|**Parameters**       | **File descriptor to read from**  |
|**Return value**     | **Read line: correct behavior<br>NULL: nothing else to read or an error occurred** |
|**External functs**  | **read, malloc, free**            |
|**Description**      | **Write a function which returns a line read from a file descriptor** |

**関数 get_next_line をループで呼び出すと、ファイルディスクリプターにあるテキストを1行ずつ読むことができる。**
  
- プログラムは、-D BUFFER_SIZE=xx というフラグを付けてコンパイルする必要がある。これは、get_next_line の read 呼び出しのバッファサイズとして使用される。
- プログラムはこのようにしてコンパイルされる。: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
