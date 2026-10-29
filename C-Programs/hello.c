#include <stdio.h>

/*
 * 使用冒泡排序将整数数组按从小到大的顺序排列。
 *
 * 每一轮比较相邻的两个元素：如果左边的数比右边大，就交换它们。
 * 一轮结束后，当前未排序部分中最大的数会移动到末尾，就像气泡
 * 上浮一样，因此这种算法称为“冒泡排序”。
 */
void bubble_sort(int numbers[], size_t length)
{
    /* 少于两个元素的数组本来就已经有序，不需要排序。 */
    if (length < 2) {
        return;
    }

    /*
     * 每完成一轮，未排序部分的末尾就会多一个确定位置的最大值。
     * 因此第 i 轮只需要检查到 length - i - 1。
     */
    for (size_t i = 0; i < length - 1; ++i) {
        /* 若一整轮都没有交换，说明数组已经有序，可以提前结束。 */
        int swapped = 0;

        for (size_t j = 0; j < length - i - 1; ++j) {
            /* 相邻元素逆序时交换，使较大的元素向右移动。 */
            if (numbers[j] > numbers[j + 1]) {
                int temporary = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temporary;
                swapped = 1;
            }
        }

        /* 本轮没有发生交换，后续也无需再比较。 */
        if (!swapped) {
            break;
        }
    }
}

/* 逐个打印数组中的元素，方便查看排序前后的结果。 */
void print_array(const int numbers[], size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        printf("%d", numbers[i]);

        /* 元素之间打印空格，最后一个元素后不再打印空格。 */
        if (i + 1 < length) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void)
{
    /* 准备一组待排序数据。 */
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    /* 根据数组占用的总字节数计算元素个数，避免手动填写长度。 */
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("排序前：");
    print_array(numbers, length);

    /* 对数组本身进行原地排序，不会创建另一份数组。 */
    bubble_sort(numbers, length);

    printf("排序后：");
    print_array(numbers, length);

    return 0;
}
