#include <string.h>
#include <assert.h>
#include "hashtable.h"

stringHashTable g_Save_IO[H_PRIMER_NUMBER];

void H_InitSaveDataIO(void)
{
    for (int i = 0; i < H_PRIMER_NUMBER; i++)
    {
        strcpy(g_Save_IO[i], "vacant");
    }
}

int H_HashFunction(stringHashTable node)
{
    int sumChar, sizeOfNode;
    sizeOfNode = strlen(node);
    sumChar = 0;
    for (int i = 0; i < sizeOfNode; i++)
        sumChar += (int)node[i];
    return (sumChar % H_PRIMER_NUMBER);
}
void H_ProbeFunction(stringHashTable node, int *StopPosition, int *FirstInsert)
{
    int tempStopPosition, tempFirstInsert;
    int check = H_HashFunction(node);
    tempFirstInsert = check;
    if ((strcmp(g_Save_IO[check], node) == 0) || strcmp(g_Save_IO[check], "vacant") == 0)
        tempStopPosition = check;
    else
    {
        tempStopPosition = (check + 1) % H_PRIMER_NUMBER;

        while ((tempStopPosition != check) && (strcmp(g_Save_IO[tempStopPosition], node) != 0) && strcmp(g_Save_IO[tempStopPosition], "vacant") != 0)
        {
            if ((strcmp(g_Save_IO[tempStopPosition], "delete") == 0) && (strcmp(g_Save_IO[tempFirstInsert], "delete") != 0))
                tempFirstInsert = tempStopPosition;
            tempStopPosition = (tempStopPosition + 1) % H_PRIMER_NUMBER;
        }
        if (strcmp(g_Save_IO[tempStopPosition], "vacant") == 0 && (strcmp(g_Save_IO[tempFirstInsert], "delete") != 0))
            tempFirstInsert = tempStopPosition;
    }
    *StopPosition = tempStopPosition;
    *FirstInsert = tempFirstInsert;
}

void H_InsertFunction(stringHashTable node)
{
    int StopPosition, FirstInsert;
    H_ProbeFunction(node, &StopPosition, &FirstInsert);
    if (strcmp(g_Save_IO[StopPosition], node) != 0)
    {
        if (strcmp(g_Save_IO[FirstInsert], "vacant") == 0 || (strcmp(g_Save_IO[FirstInsert], "delete") == 0))
        {
            strcpy(g_Save_IO[FirstInsert], node);
        }
        else
        {
            assert(1); // Bảng bị đầy
        }
    }
}
int H_FindFunction(stringHashTable node)
{
    int StopPosition, FirstInsert;
    H_ProbeFunction(node, &StopPosition, &FirstInsert);
    if (strcmp(g_Save_IO[StopPosition], node) == 0)
    {
        return StopPosition;
    }
    return -1;
}
