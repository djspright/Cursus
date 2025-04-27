#include "libft.h" // ft_calloc, ft_memset などを含む想定
#include <stdio.h>  // printf のため
#include <string.h> // memcmp のため (ゼロチェックに使用)
#include <stdlib.h> // free, malloc のため (標準callocとの比較やゼロサイズケースのため)
#include <limits.h> // SIZE_MAX のため (オーバーフローテスト用)

// メモリの内容が全てゼロかチェックするヘルパー関数
int is_memory_zero(const void *mem, size_t bytes)
{
    const unsigned char *p = mem;
    size_t i = 0;
    while (i < bytes)
    {
        if (p[i] != 0)
            return (0); // ゼロでないバイトが見つかったら 0 (偽) を返す
        i++;
    }
    return (1); // 全てゼロなら 1 (真) を返す
}

int main(void)
{
    int *int_arr;
    char *char_arr;
    void *zero_ptr;
    void *overflow_ptr;
    size_t num_elements;
    size_t element_size;
    size_t i;

    printf("--- Testing ft_calloc ---\n");

    // --- Test 1: 基本的なint配列の確保とゼロ初期化 ---
    printf("\nTest 1: Basic allocation (int * 10)\n");
    num_elements = 10;
    element_size = sizeof(int);
    int_arr = (int *)ft_calloc(num_elements, element_size);
    if (int_arr == NULL)
    {
        printf("  [FAIL] ft_calloc returned NULL unexpectedly.\n");
    }
    else
    {
        printf("  ft_calloc returned non-NULL pointer: OK\n");
        // ゼロ初期化チェック
        if (is_memory_zero(int_arr, num_elements * element_size))
        {
            printf("  Memory zero-initialized: OK\n");
        }
        else
        {
            printf("  [FAIL] Memory not zero-initialized!\n");
            // 中身を少し表示してみる (デバッグ用)
            printf("  Content: ");
            for (i = 0; i < num_elements && i < 5; ++i) printf("%d ", int_arr[i]);
            printf("\n");
        }
        free(int_arr); // 解放
        printf("  Memory freed.\n");
    }

    // --- Test 2: char配列の確保とゼロ初期化 ---
    printf("\nTest 2: Basic allocation (char * 5)\n");
    num_elements = 5;
    element_size = sizeof(char);
    char_arr = (char *)ft_calloc(num_elements, element_size);
    if (char_arr == NULL)
    {
        printf("  [FAIL] ft_calloc returned NULL unexpectedly.\n");
    }
    else
    {
        printf("  ft_calloc returned non-NULL pointer: OK\n");
        // ゼロ初期化チェック (memcmp を使っても良い)
        // char check_zeros[5] = {0}; // 比較用のゼロ配列
        // if (memcmp(char_arr, check_zeros, num_elements * element_size) == 0)
        if (is_memory_zero(char_arr, num_elements * element_size))
        {
            printf("  Memory zero-initialized: OK\n");
        }
        else
        {
            printf("  [FAIL] Memory not zero-initialized!\n");
        }
        free(char_arr);
        printf("  Memory freed.\n");
    }

    // --- Test 3: nmemb が 0 のケース ---
    printf("\nTest 3: nmemb == 0\n");
    element_size = sizeof(int);
    zero_ptr = ft_calloc(0, element_size);
    if (zero_ptr == NULL)
    {
        printf("  ft_calloc(0, size) returned NULL (might be acceptable depending on system malloc(0)).\n");
        // NULLでもfreeできるはず
        free(zero_ptr); // free(NULL) は安全
        printf("  free(NULL) called.\n");
    }
    else
    {
        printf("  ft_calloc(0, size) returned non-NULL pointer: OK (PDF rule)\n");
        // freeできるか試す
        free(zero_ptr);
        printf("  Memory freed.\n");
        // Note: このポインタへの書き込みは未定義動作
    }

    // --- Test 4: size が 0 のケース ---
    printf("\nTest 4: size == 0\n");
    num_elements = 10;
    zero_ptr = ft_calloc(num_elements, 0);
     if (zero_ptr == NULL)
    {
        printf("  ft_calloc(nmemb, 0) returned NULL (might be acceptable depending on system malloc(0)).\n");
        free(zero_ptr);
        printf("  free(NULL) called.\n");
    }
    else
    {
        printf("  ft_calloc(nmemb, 0) returned non-NULL pointer: OK (PDF rule)\n");
        free(zero_ptr);
        printf("  Memory freed.\n");
    }

    // --- Test 5: オーバーフローを引き起こす可能性のあるサイズ (任意) ---
    // SIZE_MAX は <limits.h> で定義される size_t の最大値
    printf("\nTest 5: Potential overflow test (SIZE_MAX / 2 + 1, 2)\n");
    overflow_ptr = ft_calloc(SIZE_MAX / 2 + 1, 2);
    if (overflow_ptr == NULL)
    {
        printf("  ft_calloc returned NULL (expected on overflow): OK\n");
    }
    else
    {
        // もし確保できてしまったら、それはオーバーフローチェックが機能していない可能性
        printf("  [WARN/FAIL?] ft_calloc did not return NULL on potential overflow.\n");
        free(overflow_ptr);
         printf("  Memory freed.\n");
    }

    printf("\n--- ft_calloc testing finished ---\n");
    return (0);
}
