/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:30:34 by kyuki             #+#    #+#             */
/*   Updated: 2020/10/05 19:57:17 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
    puts("-------ft_isascii----------");
    printf("library :%d\n", isascii(' '));
    printf("zisaku  :%d\n", ft_isascii('a'));
    printf("library :%d\n", isascii('A'));
    printf("zisaku  :%d\n", ft_isascii('A'));
    printf("library :%d\n", isascii('1'));
    printf("zisaku  :%d\n", ft_isascii('1'));
    
    puts("-------ft_isdigit----------");
    printf("library :%d\n", isdigit('2'));
    printf("zisaku  :%d\n", ft_isdigit('2'));
    printf("library :%d\n", isdigit('A'));
    printf("zisaku  :%d\n", ft_isdigit('A'));
    printf("library :%d\n", isdigit('1'));
    printf("zisaku  :%d\n", ft_isdigit('1'));
    
    puts("-------ft_alpha----------");
    printf("library :%d\n", isalpha('2'));
    printf("zisaku  :%d\n", ft_isalpha('2'));
    printf("library :%d\n", isalpha('A'));
    printf("zisaku  :%d\n", ft_isalpha('A'));
    printf("library :%d\n", isalpha('/'));
    printf("zisaku  :%d\n", ft_isalpha('/'));
    
    puts("-------ft_alpha----------");
    printf("library :%d\n", isalnum('2'));
    printf("zisaku  :%d\n", ft_isalnum('2'));
    printf("library :%d\n", isalnum('A'));
    printf("zisaku  :%d\n", ft_isalnum('A'));
    printf("library :%d\n", isalnum('/'));
    printf("zisaku  :%d\n", ft_isalnum('/'));
    
    puts("-------ft_isprint----------");
    printf("library :%d\n", isprint('2'));
    printf("zisaku  :%d\n", ft_isprint('2'));
    printf("library :%d\n", isprint('\t'));
    printf("zisaku  :%d\n", ft_isprint('\t'));
    printf("library :%d\n", isprint('\n'));
    printf("zisaku  :%d\n", ft_isprint('\n'));
    
    puts("-----------ft_memset-------------");
    char str01[] = "0123456789";
    char str02[] = "0123456789";
    ft_memset(str01 + 2, '*', 5);
    memset(str02 + 2, '*', 5);
    printf("zisaku  : %s\n", str01);
    printf("library : %s\n", str02);
    char *str03;
    char *str04;

    if (!(str03 = (char *)malloc(sizeof(char) * 10)))
        return (0);
    if (!(str04 = (char *)malloc(sizeof(char) * 10)))
        return (0);

    memset(str03, 'a', 10);
    ft_memset(str04, 'a', 10);
    for (int i = 0; i < 15; i++)
    {
        printf("library %d : %c\n", i, str03[i]);
        printf("zisaku  %d : %c\n", i,str04[i]);
    }
    
    puts("-----------ft_memcpy-------------");
    char str11[] = "0123456789";
    char str12[] = "0123456789";
    char dst[] = "ABCDEFGHIJ";
    ft_memcpy(str11, dst, 6);
    memcpy(str12, dst, 6);
    printf("zisaku  : %s\n", str11);
    printf("library : %s\n", str12);
    
    puts("-----------ft_memccpy-------------");
    char str21[] = "0123456789";
    char str22[] = "0123456789";
    ft_memccpy(str21, dst, 'B', 7);
    memccpy(str22, dst, 'B', 7);
    printf("zisaku  : %s\n", str21);
    printf("library : %s\n", str22);
    char    dst1[] = "test basic du memccpy !";
    char    str23[22];
    char    str24[22];
    char *r1;
    char *r2;
    ft_memccpy(str23, dst1, 'z', 22);
    memccpy(str24, dst1, 'z', 22);
    printf("zisaku  : %s\n", str23);
    printf("library : %s\n", str24);
    r1 = ft_memccpy("", dst1, ' ', 0);
    r2 = memccpy("", dst1, ' ', 0);
    printf("zisaku  : %s\n", r1);
    printf("library : %s\n", r2);
    
    puts("-----------ft_memmove-------------");
    char str31[] = "abcdefghijklmnopqrstu";
    char str32[] = "abcdefghijklmnopqrstu";
    ft_memmove(str31 + 5, str31, 10);
    memmove(str32 + 5, str32, 10);
    printf("zisaku  : %s\n", str31);
    printf("library : %s\n", str32);
    
    puts("-----------ft_strcat-------------");
    char str41[30] = "こんにちは";
    char str42[30] = "こんにちは";
    char str43[] = "konbanha";
    ft_strcat(str41, str43);
    strcat(str42, str43);
    printf("zisaku  : %s\n", str41);
    printf("library : %s\n", str42);
    char str44[30] ={'\0'};
    char str45[30] ={'\0'};
    char str46[] = "konbanhaaaa";
    ft_strcat(str44, str46);
    strcat(str45, str46);
    printf("zisaku  : %s\n", str44);
    printf("library : %s\n", str45);
//    puts("----あえてエラーを出す------");
//    char str47[30] ="aaaaaaa";
//    char str48[30] ="aaaaaaa";
//    char str49 = NULL;
//    ft_strcat(str47, str49);
//    strcat(str48, str49);
//    printf("zisaku  : %s\n", str47);
//    printf("library : %s\n", str48);
    
    puts("----ft_memchr------");
    char str51[] ="nesugosita!!!";
    char str52[] ="nesugosita!!!";
    printf("zisaku  : %s\n", ft_memchr(str51, 103, 15));
    printf("library : %s\n", memchr(str52, 103, 15));
    
    puts("----ft_memcmp------");
    puts("ここは正か負があってたら良い気がする。");
    char str61[] ="nesugosita!!!";
    char str62[] ="nesugosita!!!";
    char str63[] = "nesugosita!!!";
    printf("zisaku  : %d\n", ft_memcmp(str61, str63, 15));
    printf("library : %d\n", memcmp(str62, str63, 15));
    
    printf("zisaku  : %d\n", ft_memcmp("aiueo", "aiue1", 5));
    printf("library : %d\n", memcmp("aiueo", "aiue1", 5));
    printf("zisaku  : %d\n", ft_memcmp("aiueo", "aiueo", 5));
    printf("library : %d\n", memcmp("aiueo", "aiueo", 5));
    printf("zisaku  : %d\n", ft_memcmp("aiueo", "1iueo", 5));
    printf("library : %d\n", memcmp("aiueo", "1iueo", 5));
    printf("zisaku  : %d\n", ft_memcmp("aiueo", "1iueo", 0));
    printf("library : %d\n", memcmp("aiueo", "1iueo", 0));
    printf("zisaku  : %d\n", ft_memcmp("", "", 0));
    printf("library : %d\n", memcmp("", "", 0));
    
    puts("----ft_strchr------");
    char str71[] ="nesugosita!!!";
    char str72[] ="nesugosita!!!";
    printf("zisaku  : %s\n", ft_strchr(str71, 103));
    printf("library : %s\n", strchr(str72, 103));
    char str73[] = "aiueo";
    printf("zisaku  : %s\n", ft_strchr(str73, 'a'));
    printf("library : %s\n", strchr(str73, 'a'));
    printf("zisaku  : %s\n", ft_strchr(str73, 'i'));
    printf("library : %s\n", strchr(str73, 'i'));
    printf("zisaku  : %s\n", ft_strchr(str73, 'u'));
    printf("library : %s\n", strchr(str73, 'u'));
    printf("zisaku  : %s\n", ft_strchr(str73, 'e'));
    printf("library : %s\n", strchr(str73, 'e'));
    printf("zisaku  : %s\n", ft_strchr(str73, 'o'));
    printf("library : %s\n", strchr(str73, 'o'));
    printf("zisaku  : %s\n", ft_strchr(str73, 0));
    printf("library : %s\n", strchr(str73, 0));
    printf("zisaku  : %p\n", ft_strchr(str73, 0));
    printf("library : %p\n", strchr(str73, 0));
    printf("zisaku  : %s\n", ft_strchr(str73, 1));
    printf("library : %s\n", strchr(str73, 1));
    printf("zisaku  : %s\n", ft_strchr(str73, 'z'));
    printf("library : %s\n", strchr(str73, 'z'));
    
    puts("----ft_strrchr------");
    char a[] = "aiueo";
    printf("zisaku  : %s\n", ft_strrchr(a, 'a'));
    printf("library : %s\n", strrchr(a, 'a'));
    printf("zisaku  : %s\n", ft_strrchr(a, 'i'));
    printf("library : %s\n", strrchr(a, 'i'));
    printf("zisaku  : %s\n", ft_strrchr(a, 'u'));
    printf("library : %s\n", strrchr(a, 'u'));
    printf("zisaku  : %s\n", ft_strrchr(a, 'e'));
    printf("library : %s\n", strrchr(a, 'e'));
    printf("zisaku  : %s\n", ft_strrchr(a, 'o'));
    printf("library : %s\n", strrchr(a, 'o'));
    printf("zisaku  : %s\n", ft_strrchr(a, 0));
    printf("library : %s\n", strrchr(a, 0));
    printf("zisaku  : %p\n", ft_strrchr(a, 0));
    printf("library : %p\n", strrchr(a, 0));
    printf("zisaku  : %s\n", ft_strrchr(a, 1));
    printf("library : %s\n", strrchr(a, 1));
    printf("zisaku  : %s\n", ft_strrchr(a, 'z'));
    printf("library : %s\n", strrchr(a, 'z'));
    
    puts("----ft_strstr------");
    char str81[] ="nesugosita!!!";
    char str82[] ="gosita";
    printf("zisaku  : %s\n", ft_strstr(str81, str82));
    printf("library : %s\n", strstr(str81, str82));
    
    puts("----ft_strnstr------");
    char str81_0[] ="nesugosita!!!";
    char str81_1[] ="go";
    printf("zisaku  : %s\n", ft_strnstr(str81_0, str81_1, 5));
    printf("library : %s\n", strnstr(str81_0, str81_1, 5));
    printf("zisaku  : %s\n", ft_strnstr(str81_0, str81_1, 6));
    printf("library : %s\n", strnstr(str81_0, str81_1, 6));
    
    puts("----ft_atoi------");
    char    str91[] = "-a-5";
    printf("zisaku  : %d\n", ft_atoi(str91));
    printf("library : %d\n", atoi(str91));
    char    str92[] = "-100";
    printf("zisaku  : %d\n", ft_atoi(str92));
    printf("library : %d\n", atoi(str92));
    char    str93[] = "1000321";
    printf("zisaku  : %d\n", ft_atoi(str93));
    printf("library : %d\n", atoi(str93));
    char    str94[] = "2147483648";
    printf("zisaku  : %d\n", ft_atoi(str94));
    printf("library : %d\n", atoi(str94));
    char    str95[] = "-2147483649";
    printf("zisaku  : %d\n", ft_atoi(str95));
    printf("library : %d\n", atoi(str95));
    char    str96[] = "100ab100";
    printf("zisaku  : %d\n", ft_atoi(str96));
    printf("library : %d\n", atoi(str96));
    char    str97[] = "\0";
    printf("zisaku  : %d\n", ft_atoi(str97));
    printf("library : %d\n", atoi(str97));
    char    str98[] = "111.11";
    printf("zisaku  : %d\n", ft_atoi(str98));
    printf("library : %d\n", atoi(str98));
    char    str99[] = "-2147483648";
    printf("zisaku  : %d\n", ft_atoi(str99));
    printf("library : %d\n", atoi(str99));
    char    str99_1[] = "2147483647";
    printf("zisaku  : %d\n", ft_atoi(str99_1));
    printf("library : %d\n", atoi(str99_1));
    char str99_2[] ="999999999";
    printf("zisaku  : %d\n", ft_atoi(str99_2));
    printf("library : %d\n", atoi(str99_2));
    
    puts("----ft_strlcpy------");
    char str101[] ="1234567";
    char str102[] ="1234567";
    char str103[] = "ABCDEFG";
    printf("zisaku  : %zu, %s\n", ft_strlcpy(str101,str103, 0), str101);
    printf("library : %zu, %s\n", strlcpy(str102,str103, 0), str102);
    printf("zisaku  : %zu, %s\n", ft_strlcpy(str101,str103, 3), str101);
    printf("library : %zu, %s\n", strlcpy(str102,str103, 3), str102);
    
    puts("----ft_toupper------");
    int str111 = toupper('a');
    int str112 = ft_toupper('a');
    printf("library: %c\n", str111);
    printf("zisaku : %c\n", str112);
    
    puts("----ft_tolower------");
    int str113 = tolower('A');
    int str114 = ft_tolower('A');
    printf("library: %c\n", str113);
    printf("zisaku : %c\n", str114);
    
    puts("----ft_tolower------");
    int str121 = strlen("chidoridaisuki");
    int str122 = ft_strlen("chidoridaisuki");
    printf("library: %d\n", str121);
    printf("zisaku : %d\n", str122);
    
    puts("----ft_strcmp------");
    char str131[] = "chidoridaisuki";
    char str132[] = "chidoridaisuki";
    char str133[] = "chidori&nobu&daigo";
    printf("library: %d\n", strcmp(str131, str132));
    printf("zisaku : %d\n", ft_strcmp(str131, str132));
    printf("library: %d\n", strcmp(str131, str133));
    printf("zisaku : %d\n", ft_strcmp(str131, str133));
    
    puts("----ft_strncmp------");
    char str141[] = "chidoridaisuki";
    char str142[] = "chidoridaisuki";
    char str143[] = "chidori&nobu&daigo";
    printf("library: %d\n", strncmp(str141, str142, 14));
    printf("zisaku : %d\n", ft_strncmp(str141, str142, 14));
    printf("library: %d\n", strncmp(str141, str143, 7));
    printf("zisaku : %d\n", ft_strncmp(str141, str143, 7));
    printf("library: %d\n", strncmp(str141, str143, 8));
    printf("zisaku : %d\n", ft_strncmp(str141, str143, 8));
    
    puts("----ft_strlcat------");
    char str151[10] ="12";
    char str152[10] ="12";
    char str153[] = "ABCDEFG";
    printf("zisaku  : %zu, %s\n", ft_strlcat(str151,str153, 6), str151);
    printf("library : %zu, %s\n", strlcat(str152,str153, 6), str152);
    printf("zisaku  : %zu, %s\n", ft_strlcat(str151,str153, 1), str151);
    printf("library : %zu, %s\n", strlcat(str152,str153, 1), str152);
    puts("----ft_strdup------");
    char str161[] ="radwimps";
    printf("zisaku  : %s\n", ft_strdup(str161));
    printf("library  : %s\n", strdup(str161));
    puts("----bzero------");
    char str171[] ="radwimps";
    char str172[] ="radwimps";
    ft_bzero(str171, 3);
    bzero(str172, 3);
    printf("zisaku  : %s\n", str171 + 3);
    printf("library  : %s\n", str172 + 3);
    printf("zisaku  : %s\n", str171 + 2);
    printf("library  : %s\n", str172 + 2);
}


//strdup calloc
