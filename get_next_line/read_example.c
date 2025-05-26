#include <stdio.h>      // perror, printf のため
#include <unistd.h>     // read, open, close のため
#include <fcntl.h>      // O_RDONLY のため
#include <errno.h>      // errno のため
#include <string.h>     // strerror のため (エラー表示に使う場合)

#define BUFFER_SIZE 128 // 一度に読み込むバッファサイズ

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "使用方法: %s <ファイル名>\n", argv[0]);
        return 1;
    }

    const char *filepath = argv[1];
    int fd; // ファイルディスクリプタ

    // ファイルを読み込み専用で開く
    // O_RDONLY: 読み込み専用でファイルを開くフラグ
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("openに失敗しました"); // errno に基づいてエラーメッセージを表示
        // fprintf(stderr, "openに失敗しました: %s\n", strerror(errno)); // strerrorを使う場合
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    printf("ファイル '%s' の内容:\n", filepath);
    printf("----------------------------------------\n");

    // read はファイルの終端に達すると 0 を返す
    // エラーが発生すると -1 を返す
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // 読み込んだデータを標準出力 (ファイルディスクリプタ 1) に書き出す
        // write 関数も同様に、実際に書き込めたバイト数を返す
        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("writeに失敗しました");
            close(fd);
            return 1;
        }
        // 部分的な書き込みが発生した場合の処理 (この例では省略)
        if (bytes_written < bytes_read) {
            fprintf(stderr, "警告: 部分的な書き込みが発生しました。\n");
        }
    }

    printf("----------------------------------------\n");

    // read のループが終了した後、エラーが発生したか確認
    if (bytes_read == -1) {
        perror("readに失敗しました");
    } else {
        printf("ファイルの読み込みが完了しました。\n");
    }

    // ファイルを閉じる
    if (close(fd) == -1) {
        perror("closeに失敗しました");
        return 1;
    }

    return 0;
}
