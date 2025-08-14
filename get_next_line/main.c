/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:00 by shkondo           #+#    #+#             */
/*   Updated: 2025/07/02 20:04:28 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd;
  char *line;
  int line_number;

  // 引数チェック
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    printf("例: %s test.txt\n", argv[0]);
    return (1);
  }

  // ファイルを開く
  fd = open(argv[1], O_RDONLY);
  // fd = 0;
  if (fd == -1) {
    printf("エラー: ファイル '%s' を開けません\n", argv[1]);
    return (1);
  }

  // ファイル情報を表示
  printf("get_next_line\n");
  printf("filename: %s\n", argv[1]);
  printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

  // ファイルを1行ずつ読み取り
  line_number = 1;
  while ((line = get_next_line(fd)) != NULL) {
    printf("行 %d: ", line_number);

    // 改行文字を視覚化して表示
    for (int i = 0; line[i]; i++) {
      if (line[i] == '\n')
        printf("\\n");
      else if (line[i] == '\t')
        printf("\\t");
      else
        printf("%c", line[i]);
    }
    printf("\n");

    free(line);
    line_number++;
  }

  // 結果を表示
  printf("総行数: %d\n", line_number - 1);

  // ファイルを閉じる
  close(fd);

  return (0);
}
