/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myString.h"
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/************************************************************************************
 * Static function
 *************************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

char *MS_StrAllocAndAppend(const char *str1, const char *str2) // chèn tại cuối chuỗi
{

    /*
    Chèn chuỗi trong C

    Tham số
        str1:      Chuỗi ban đầu (không chấp nhận Null)
        pos:       Vị trí chèn (tính từ đầu chuỗi str1)
        str2:      Chuỗi chèn vào (không chấp nhận Null pointer)
    Giá trị trả về
        Con trỏ mảng chứa kết quả. Nếu thực thi thất bại thì trả về Null
*/
    size_t pos;
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    pos = len1;
    // Kiểm tra vị trí chèn có nằm trong chuỗi str1 không

    size_t result_size = len1 + len2 + 1;
    char *result = (char *)malloc(sizeof(char) * result_size);
    if (result == NULL)
    {
        return NULL;
    }

    // Copy phạm vi từ đầu chuỗi ban đầu tới trước vị trí cần chèn vào chuỗi kết quả
    memcpy(result, str1, pos);

    // Copy chuỗi cần chèn vào cuối kết quả
    memcpy(&result[pos], str2, len2);

    // Copy phạm vi từ vị trí cần chèn tới cuối chuỗi ban đầu vào chuỗi kết quả
    // Thêm ký tự kết thúc chuỗi `\0` vào kết quả
    strcpy(&result[pos + len2], &str1[pos]);

    return result;
}
char *MS_StrAllocAndInsert(const char *str1, size_t pos, const char *str2) // Chèn tại vị trí bất kỳ
{

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    size_t result_size = len1 + len2 + 1;
    char *result = (char *)malloc(sizeof(char) * result_size);
    if (result == NULL)
    {
        return NULL;
    }

    // Copy phạm vi từ đầu chuỗi ban đầu tới trước vị trí cần chèn vào chuỗi kết quả
    memcpy(result, str1, pos);

    // Copy chuỗi cần chèn vào cuối kết quả
    memcpy(&result[pos], str2, len2);

    // Copy phạm vi từ vị trí cần chèn tới cuối chuỗi ban đầu vào chuỗi kết quả
    // Thêm ký tự kết thúc chuỗi `\0` vào kết quả
    strcpy(&result[pos + len2], &str1[pos]);

    return result;
}
char *MS_AddParenthesesIfMissing(char *arr)
{

    char *insert_str_pre = "(";
    char *insert_str_next = ")";
    int size_arr = strlen(arr);
    int left = 0;
    int right = 0;
    for (int i = 0; i < size_arr; i++)
    {
        if (arr[i] == '(')
        {
            left++;
        }
        if (arr[i] == ')')
        {
            right++;
        }
    }
    while (left != right)
    {
        if (left > right)
        {
            arr = MS_StrAllocAndAppend(arr, insert_str_next);
            right++;
        }
        else if (left < right)
        {
            arr = MS_StrAllocAndAppend(insert_str_pre, arr);
            left++;
        }
    }
    return arr;
}